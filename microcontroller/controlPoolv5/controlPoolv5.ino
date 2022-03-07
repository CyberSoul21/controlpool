/**************************************************************************//**
 * @file controlPoolv2.ino
 *
 * 
 * @author Ing. Wilson Javier Almario Rodriguez.
 * @date 16/08/2019
 *
 *
 *
 *****************************************************************************/
/******************************************************************************
 * Copyright (C) 2019 by Wilson Almario 
 *
 *****************************************************************************/
#include "memoria.h"
#include "fecha.h"
#include "bloqueo.h"
#include "pantallas.h"
#include "pool.h"
#include "Oxy.h"
#include "ion.h"
#include "ionManual.h"
#include "co2.h"
/*
-------------------------------------------------------------
***************Variables auxiliares******************
-------------------------------------------------------------*/
String data = "0"; //Lectura desde el serial
int opcIon=0;      //Eleccion de opcion en ION
int refMinuto;
int contador = 0;
int cambio = 1;
int desacOxy = 0;
int actIonPro = 0;
int opcCtr=0;      //Eleccion de opcion en contraseña
int okCtr=0;

float minPool  = 0 ;
float divMinP  = 0,divMinC;
float decimasP = 0,decimasC = 0;
long int divMinPInt = 0, divMinCInt = 0;

float tiemposCO2[7];

int primer = 0;
float minrefCo2 = 0;
//long int minrefCo2 = 0; ORIGINAL
long int contadorCo2  = 0;
 float difMin = 0;
int pos=0;
 
 



/*
-------------------------------------------------------------
-------------------------------------------------------------*/
/*
-------------------------------------------------------------
***************SALIDAS DIGITALES******************
-------------------------------------------------------------*/
const int outPool = 4;      // Salida relÃ© pool.
const int outOxy1 = 5;      // Salida relÃ© Oxy.
const int outOxy2 = 6;      // Salida relÃ© Oxy.
const int outIon1 = 7;      // Salida relÃ© Ion.
const int outIon2 = 8;      // Salida relÃ© Ion.
const int outCO2 = 9;      // Salida relÃ© CO2.
/*
-------------------------------------------------------------
-------------------------------------------------------------*/

/*
-------------------------------------------------------------
*Variables para almacenar la infomacion
*char[21] tipo char 21 posiciones
*Definida en memoria.h
-------------------------------------------------------------*/
//char variaPool[21];
tiempoStruct variaPool;
tiempoStruct variaOxy;
ionStruct variaIonLunes;//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ionStruct variaIonMartes;
ionStruct variaIonMiercoles;
ionStruct variaIonJueves;
ionStruct variaIonViernes;
ionStruct variaIonSabado;
ionStruct variaIonDomingo;
tiempoStruct variaIonM;

contraStruct variaContr;

co2Struct variaCo2;


long int poolInicio;
long int poolFin;
long int hora;
float minReloj;
//long int minReloj; //Original

long int oxyInicio;
long int oxyFin;

long int ionInicio;//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
long int ionFin;

long int ionMInicio;
long int ionMFin;


long int hriP = 0;
long int mniP = 0;
long int sgiP = 0;
long int hrfP = 0;
long int mnfP = 0;
long int sgfP = 0;
long int diaP = 0;
long int actP = 0;

long int hriO = 0;
long int mniO = 0;
long int sgiO = 0;
long int hrfO = 0;
long int mnfO = 0;
long int sgfO = 0;
long int diaO = 0;
long int actO = 0;


String hriOSt = "";
String mniOSt = "";
String sgiOSt = "";
String hrfOSt = "";
String mnfOSt = "";
String sgfOSt = "";
String diaOSt = "";
String actOSt = "";

String hriISt = "";
String mniISt = "";
String sgiISt = "";
String hrfISt = "";
String mnfISt = "";
String sgfISt = "";
String diaISt = "";
String actISt = "";

long int hriI = 0;
long int mniI = 0;
long int sgiI = 0;
long int hrfI = 0;
long int mnfI = 0;
long int sgfI = 0;
long int diaI = 0;
long int actI = 0;

long int hriIM = 0;
long int mniIM = 0;
long int sgiIM = 0;
long int hrfIM = 0;
long int mnfIM = 0;
long int sgfIM = 0;
long int diaIM = 0;
long int actIM = 0;

long int mniC = 0;
long int actC = 0;

String hriIMSt = "";
String mniIMSt = "";
String sgiIMSt = "";
String hrfIMSt = "";
String mnfIMSt = "";
String sgfIMSt = "";
String diaIMSt = "";
String actIMSt = "";



/*
-------------------------------------------------------------
-------------------------------------------------------------*/


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//PC
  Serial1.begin(9600);// ComunicaciÃ³n LCD
  rtc.begin();        //Trasmision RTC iniciar
  pinMode(outPool, OUTPUT);
  pinMode(outOxy1, OUTPUT);
  pinMode(outOxy2, OUTPUT);
  pinMode(outIon1, OUTPUT);
  pinMode(outIon2, OUTPUT); 
  pinMode(outCO2, OUTPUT);  

  digitalWrite(outPool, HIGH);
  digitalWrite(outIon1, HIGH);
  digitalWrite(outIon2, HIGH); 
  digitalWrite(outOxy1, HIGH);
  digitalWrite(outOxy2, HIGH);
  digitalWrite(outCO2, HIGH);     
  
/*
-------------------------------------------------------------
***************Lectura de horas almacenadas******************
-------------------------------------------------------------*/
  variaContr;
  eeprom.read(500, (byte*) variaContr, sizeof(variaContr));
  Serial.print("Leyo contraseña: ");
  Serial.println(variaContr);

  variaPool;
  eeprom.read(100, (byte*) variaPool, sizeof(variaPool));
  valorInicialPool(variaPool);//Cololar en la pantalla valores

  variaOxy;
  eeprom.read(0, (byte*) variaOxy, sizeof(variaOxy));
  //Serial.print("Leyo antesde vslor inicial Oxy: ");
  //Serial.println(variaOxy); 
  valorInicialOxy(variaOxy);//Cololar en la pantalla valores

  ////////////////////////////////////////////////////////LECTURA VARIABLES ION /////////////////////////////////////
  eeprom.read(600, (byte*) variaIonLunes, sizeof(variaIonLunes));
  //Serial.print("Leyo antesde vslor inicial ION: ");
  //Serial.println(variaIon);
  eeprom.read(620, (byte*) variaIonMartes, sizeof(variaIonMartes));
  //Serial.print("Leyo antesde vslor inicial ION: ");
  //Serial.println(variaIon); 
  eeprom.read(640, (byte*) variaIonMiercoles, sizeof(variaIonMiercoles));
  //Serial.print("Leyo antesde vslor inicial ION: ");
  //Serial.println(variaIon); 
  eeprom.read(660, (byte*) variaIonJueves, sizeof(variaIonJueves));
  //Serial.print("Leyo antesde vslor inicial ION: ");
  //Serial.println(variaIon); 
  eeprom.read(680, (byte*) variaIonViernes, sizeof(variaIonViernes));
  //Serial.print("Leyo antesde vslor inicial ION: ");
  //Serial.println(variaIon); 
  eeprom.read(720, (byte*) variaIonSabado, sizeof(variaIonSabado));
  //Serial.print("Leyo antesde vslor inicial ION: ");
  //Serial.println(variaIon); 
  eeprom.read(740, (byte*) variaIonDomingo, sizeof(variaIonDomingo));
  //Serial.print("Leyo antesde vslor inicial ION: ");
  //Serial.println(variaIon); 

  obtenerFecha();
  valorInicialIon(variaIonLunes,variaIonMartes,variaIonMiercoles,variaIonJueves,variaIonViernes,variaIonSabado,variaIonDomingo,horaRTC.di);//Cololar en la pantalla valores  
  //Serial.print("Leyo antesde vslor inicial: ");
  //Serial.println(variaIon); 
  //Serial.println(variaIon[22]);

  variaIonM;
  eeprom.read(300, (byte*) variaIonM, sizeof(variaIonM));
  //Serial.print("Leyo antesde vslor inicial ION: ");
  //Serial.println(variaIonM); 
  valorInicialIonM(variaIonM);//Cololar en la pantalla valores  
  //Serial.print("Leyo antesde vslor inicial: ");
  //Serial.println(variaIonM); 

  variaCo2;
  eeprom.read(400, (byte*) variaCo2, sizeof(variaCo2));
  //Serial.print("Leyo antesde vslor inicial ION: ");
  //Serial.println(variaCo2); 
  valorInicialCo2(variaCo2);//Cololar en la pantalla valores  
  //Serial.print("Leyo antesde vslor inicial: ");
  //Serial.println(variaCo2); 
  //Serial.println(variaCo2[22]);

 
  //valorInicialIonM(variaIonM);//Cololar en la pantalla valores  
  //Serial.print("Leyo antesde vslor inicial: ");
  //Serial.println(variaIonM); 
  //Serial.println(variaIonM[22]);
      
  variaContrStr = String(variaContr);
  variaPoolStr = String(variaPool);
  variaOxyStr  = String(variaOxy);
  variaIonStr  = String(variaIonMiercoles);
  variaIonMStr  = String(variaIonM); 
  variaCo2Str  = String(variaCo2);
  //Serial.print("variaIonMiercoles: ");   
  //Serial.println(variaIonMiercoles); 

  refMinuto = horaRTC.sg;
/*
-------------------------------------------------------------
-------------------------------------------------------------*/  
}




void loop() {
 
  String ano = rtc.getDateStr();
  ano = ano.substring(6,10);
  Serial.print("ano: ");
  Serial.println(ano);
  
  while (Serial1.available())//Espera instrucciones desde la LCD
  {
    data = Serial1.readStringUntil('\n');//dependiendo el dato de la LCD, llamara las diferentes funciones, definidas en cada libreria
    if(data=="fecha"){
      pantallaFecha(); //En fecha.h
      Serial.println("Fecha");
      recibirFecha();  //En fecha.h, para el ajuste de la fecha    
    }
    else if(data=="bloqueo"){
      Serial.println("Bloqueo");
      ingresoContrasena(variaContrStr,2,ano); //en bloqueo.h, espera a que se ingrese contraseÃ±a
    }     
    else if(data=="pool"){ //AquÃ­ mepiezan las diferentes programaciones: Pool, Ion, Ox y CO2
      Serial.println("Pool");//En pool.h
      pantallaPool();
      inicioFinPool(); //Ajusta hora de inicio y fin de Pool
    }
    else if(data=="oxy"){
      Serial.println("Oxy");
      pantallaOxy();
      inicioFinOxy(); //Ajusta hora de inicio y fin de Oxy
    }
    else if(data=="ion"){
      Serial.println("Ion");//En Ion.h
      pantallaIon0();
      inicioFinIon(); //Ajusta hora de inicio y fin de ION  sin el dia     
    }
    else if(data=="ionM"){
      pantallaIonM();
      inicioFinIonM();
      Serial.println("ionM");//En fecha.h
    }      
    else if(data=="co2"){
      Serial.println("CO2");//En fecha.h
      pantallaCO2();
      inicioFinCo2();      
    }
    else if(data=="cambContr"){
      Serial.println("Cambiar contrasena");//En fecha.h
      opcCtr=contrasenaPregunta();
      //Serial.println(opcIon);
     // pantallaBloqueo();
     // okCtr=ingresoContrasena(variaContrStr,13);
      delay(50);
      if(opcCtr==1){// && okCtr == 1){

        //pantallaBloqueo();
        //okCtr=ingresoContrasena(variaContrStr,13);

        
        pantaCambiarContrasena();
        cambiarContrasena();
        
        
        variaContrStr=valuContr;     
      }   
      else if(opcCtr==2){// && okCtr == 1){
        pantallaMenu();
      }      
      else if(opcCtr==3){// && okCtr == 1){
        pantallaPrincipal();
      }       
    }
    else if(data=="volver"){
      pantallaPrincipal();
    }    
    else{
      Serial.println("Default");
 
    }     
  }
  obtenerFecha();//Pregunta fecha al RTC para colocar en lapantalla //En fecha.h 
  
  if(refMinuto == horaRTC.sg){
    contador = contador + 1;
    delay(1000);
  }
  if(contador%2 == 0){
    cambio = 1;
  }else{
    cambio = 0;
    if(contador == 100){
        contador = 0;
      }     
  }
  //-----------------------------------------------------------------------------
  //--------------------------------POOL-----------------------------------------
  hriP = variaPoolStr.substring(0,2).toInt();
  mniP = variaPoolStr.substring(3,5).toInt();
  sgiP = variaPoolStr.substring(6,8).toInt();    
  hrfP = variaPoolStr.substring(9,11).toInt();
  mnfP = variaPoolStr.substring(12,14).toInt();
  sgfP = variaPoolStr.substring(15,17).toInt();
  diaP = variaPoolStr.substring(18,19).toInt();
  actP = variaPoolStr.substring(20,21).toInt();    

  poolInicio = hriP*3600 + mniP*60 + sgiP;
  poolFin = hrfP*3600 + mnfP*60 + sgfP;
  hora = horaRTC.hr*3600 + horaRTC.mn*60 + horaRTC.sg;
  
  /*
  Serial.print("Hora inicio: ");
  Serial.println(poolInicio);
  Serial.print("Hora Fin: ");
  Serial.println(poolFin);
  Serial.print("Hora Real: ");
  Serial.println(hora);
  /*
  Serial.print("hrfP: ");
  Serial.println(hrfP*3600);
  Serial.print("mnfP: ");
  Serial.println(mnfP*60);
  Serial.print("sgfP: ");
  Serial.println(sgfP);  
  */
  
  if((poolInicio<hora) && (poolFin>hora) && (actP == 1)){
    digitalWrite(outPool, LOW);
    //Serial.println("Entro");
  }else{
    digitalWrite(outPool, HIGH);
  }    
 //--------------------------------------------------------------------------------


 //--------------------------------------------------------------------------------
 //---------------------------------ION MANUAL ------------------------------------

  hriIMSt = variaPoolStr.substring(0,2);
  mniIMSt = variaPoolStr.substring(3,5);
  sgiIMSt = variaPoolStr.substring(6,8);    
  hrfIMSt = variaPoolStr.substring(9,11);
  mnfIMSt = variaPoolStr.substring(12,14);
  sgfIMSt = variaPoolStr.substring(15,17);
  actIMSt = variaIonMStr.substring(18,19); 
  //diaIMSt = variaIonMStr.substring(18,19);  
  
  hriIM = variaPoolStr.substring(0,2).toInt();
  mniIM = variaPoolStr.substring(3,5).toInt();
  sgiIM = variaPoolStr.substring(6,8).toInt();    
  hrfIM = variaPoolStr.substring(9,11).toInt();
  mnfIM = variaPoolStr.substring(12,14).toInt();
  sgfIM = variaPoolStr.substring(15,17).toInt();
  //diaIM = variaIonStr.substring(18,19).toInt();
  actIM = variaIonMStr.substring(18,19).toInt();

  ionMInicio = hriIM*3600 + mniIM*60 + sgiIM;
  ionMFin = hrfIM*3600 + mnfIM*60 + sgfIM;


  
  if((actP == 1) && (actIM == 1)){
  //if((poolInicio<hora) && (poolFin>hora)){
    desacOxy = 1;
    if((poolInicio<hora) && (poolFin>hora)){
      if(cambio == 0){
        digitalWrite(outIon2, HIGH);
        digitalWrite(outIon1, LOW);
        //Serial.print("Entro Ion1: ");
        //Serial.println(contador);
      }
      if(cambio == 1){
        digitalWrite(outIon1, HIGH);
        digitalWrite(outIon2, LOW);
        //Serial.print("Entro Ion2: ");
        //Serial.println(contador);
      }
    }else{
      digitalWrite(outIon1, HIGH);
      digitalWrite(outIon2, HIGH);      
    }
    Serial1.print("page2.t14.txt=\"No\"");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);     
    delay(50);
    Serial1.print("page2.t7.txt=\"None\"");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);     
    delay(50);
    Serial1.print("page2.t8.txt=\"\"");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);     
    delay(50);
    Serial1.print("page2.t9.txt=\""+hriIMSt+":"+mniIMSt+":"+sgiIMSt+"\"");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);     
    delay(50);
    Serial1.print("page2.t10.txt=\""+hrfIMSt+":"+mnfIMSt+":"+sgfIMSt+"\"");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);     
    delay(50);
    Serial1.print("page2.t15.txt=\"Si\"");////////////////////////////////////////////////////////////VERIFICAR ESTO
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);     
    delay(50);
        
  }else{
    if((actO == 1) && (actIonPro != 1)){
      Serial1.print("page2.t14.txt=\"Si\"");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);     
      delay(50);
    }
    desacOxy = 0;
    if(actIonPro == 0){
      Serial1.print("page2.t7.txt=\""+hriOSt+":"+mniOSt+":"+sgiOSt+"\"");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);     
      delay(50);
      Serial1.print("page2.t8.txt=\""+hrfOSt+":"+mnfOSt+":"+sgfOSt+"\"");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);     
      delay(50);
    }
    Serial1.print("page2.t9.txt=\""+hriISt+":"+mniISt+":"+sgiISt+"\"");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);     
    delay(50);
    Serial1.print("page2.t10.txt=\""+hrfISt+":"+mnfISt+":"+sgfISt+"\"");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);     
    delay(50);
/*    
    if(actISt==1){
      Serial1.print("page2.t15.txt=\"Si\"");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);       
    }else{
      Serial1.print("page2.t15.txt=\"No\"");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);      
    }
*/    
    delay(50);
    //digitalWrite(outIon1, HIGH);
    //digitalWrite(outIon2, HIGH);
  }  
  

 //--------------------------------------------------------------------------------- 


 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////MODIFICAR
 
 //--------------------------------------------------------------------------------
 //---------------------------------ION PROGRAMADO---------------------------------

  diaI = horaRTC.di;
  switch(diaI){
    case 1:
      hriISt = valoresStr1.substring(0,2);
      mniISt = valoresStr1.substring(3,5);
      sgiISt = valoresStr1.substring(6,8);
      hrfISt = valoresStr1.substring(9,11);
      mnfISt = valoresStr1.substring(12,14);
      sgfISt = valoresStr1.substring(15,17);
      actISt = valoresStr1.substring(18,19);
      Serial1.print("page2.t16.txt=\"LUNES\"");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);      
      break;
    case 2:
      hriISt = valoresStr2.substring(0,2);
      mniISt = valoresStr2.substring(3,5);
      sgiISt = valoresStr2.substring(6,8);
      hrfISt = valoresStr2.substring(9,11);
      mnfISt = valoresStr2.substring(12,14);
      sgfISt = valoresStr2.substring(15,17);
      actISt = valoresStr2.substring(18,19);    
      Serial1.print("page2.t16.txt=\"MARTES\"");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);      
      break;
    case 3:
      hriISt = valoresStr3.substring(0,2);
      mniISt = valoresStr3.substring(3,5);
      sgiISt = valoresStr3.substring(6,8);
      hrfISt = valoresStr3.substring(9,11);
      mnfISt = valoresStr3.substring(12,14);
      sgfISt = valoresStr3.substring(15,17);
      actISt = valoresStr3.substring(18,19);      
      Serial1.print("page2.t16.txt=\"MIERCOLES\"");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);      
      break;
    case 4:
      hriISt = valoresStr4.substring(0,2);
      mniISt = valoresStr4.substring(3,5);
      sgiISt = valoresStr4.substring(6,8);
      hrfISt = valoresStr4.substring(9,11);
      mnfISt = valoresStr4.substring(12,14);
      sgfISt = valoresStr4.substring(15,17);
      actISt = valoresStr4.substring(18,19);    
      Serial1.print("page2.t16.txt=\"JUEVES\"");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);      
      break;
    case 5:
      hriISt = valoresStr5.substring(0,2);
      mniISt = valoresStr5.substring(3,5);
      sgiISt = valoresStr5.substring(6,8);
      hrfISt = valoresStr5.substring(9,11);
      mnfISt = valoresStr5.substring(12,14);
      sgfISt = valoresStr5.substring(15,17);
      actISt = valoresStr5.substring(18,19);      
      Serial1.print("page2.t16.txt=\"VIERNES\"");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);      
      break;
    case 6:
      hriISt = valoresStr6.substring(0,2);
      mniISt = valoresStr6.substring(3,5);
      sgiISt = valoresStr6.substring(6,8);
      hrfISt = valoresStr6.substring(9,11);
      mnfISt = valoresStr6.substring(12,14);
      sgfISt = valoresStr6.substring(15,17);
      actISt = valoresStr6.substring(18,19);    
      Serial1.print("page2.t16.txt=\"SABADO\"");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);      
      break;
    case 7:
      hriISt = valoresStr7.substring(0,2);
      mniISt = valoresStr7.substring(3,5);
      sgiISt = valoresStr7.substring(6,8);
      hrfISt = valoresStr7.substring(9,11);
      mnfISt = valoresStr7.substring(12,14);
      sgfISt = valoresStr7.substring(15,17);
      actISt = valoresStr7.substring(18,19);    
      Serial1.print("page2.t16.txt=\"DOMINGO\"");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);      
      break;   
    }


  hriI = hriISt.toInt();
  mniI = mniISt.toInt();
  sgiI = sgiISt.toInt();    
  hrfI = hrfISt.toInt();
  mnfI = mnfISt.toInt();
  sgfI = sgfISt.toInt();
  actI = actISt.toInt();

  ionInicio = hriI*3600 + mniI*60 + sgiI;
  ionFin = hrfI*3600 + mnfI*60 + sgfI;

  if(actI==1){
    Serial1.print("page2.t15.txt=\"Si\"");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);     
    delay(50);     
  }else{
    Serial1.print("page2.t15.txt=\"No\"");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);     
    delay(50);     
  }

  
  if((ionInicio>poolInicio) && (ionFin<poolFin) && (ionInicio<hora) && (ionFin>hora) && (actP == 1) && (actI == 1) && (actIM == 0)){
    desacOxy = 1;
    actIonPro = 1;
    if(cambio == 0){
      digitalWrite(outIon2, HIGH);
      digitalWrite(outIon1, LOW);
      //Serial.print("Entro Ion1: ");
      //Serial.println(contador);
    }
    if(cambio == 1){
      digitalWrite(outIon1, HIGH);
      digitalWrite(outIon2, LOW);
      //Serial.print("Entro Ion2: ");
      //Serial.println(contador);
    }
    Serial1.print("page2.t14.txt=\"No\"");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);     
    delay(50);
    Serial1.print("page2.t7.txt=\"None\"");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);     
    delay(50);
    Serial1.print("page2.t8.txt=\"\"");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);     
    delay(50);    
        
  }else if((actIM == 0)){
    actIonPro = 0;
    if((actO == 1) && (actIonPro != 1)){
      Serial1.print("page2.t14.txt=\"Si\"");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);     
      delay(50);
    }
    desacOxy = 0;
    Serial1.print("page2.t7.txt=\""+hriOSt+":"+mniOSt+":"+sgiOSt+"\"");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);     
    delay(50);
    Serial1.print("page2.t8.txt=\""+hrfOSt+":"+mnfOSt+":"+sgfOSt+"\"");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);     
    delay(50);
    digitalWrite(outIon1, HIGH);
    digitalWrite(outIon2, HIGH);      
              
  }  
  

 //--------------------------------------------------------------------------------- 



 //--------------------------------------------------------------------------------
 //---------------------------------OXY--------------------------------------------

  hriOSt = variaOxyStr.substring(0,2);
  mniOSt = variaOxyStr.substring(3,5);
  sgiOSt = variaOxyStr.substring(6,8);
  hrfOSt = variaOxyStr.substring(9,11);
  mnfOSt = variaOxyStr.substring(12,14);
  sgfOSt = variaOxyStr.substring(15,17);
  diaOSt = variaOxyStr.substring(18,19);
  actOSt = variaOxyStr.substring(20,21);
 
  hriO = hriOSt.toInt();
  mniO = mniOSt.toInt();
  sgiO = sgiOSt.toInt();    
  hrfO = hrfOSt.toInt();
  mnfO = mnfOSt.toInt();
  sgfO = sgfOSt.toInt();
  diaO = diaOSt.toInt();
  actO = actOSt.toInt();

  oxyInicio = hriO*3600 + mniO*60 + sgiO;
  oxyFin = hrfO*3600 + mnfO*60 + sgfO;
  
  if((oxyInicio>poolInicio) && (oxyFin<poolFin) && (oxyInicio<hora) && (oxyFin>hora) && (actP == 1) && (actO == 1) && (desacOxy == 0)){
    if(cambio == 0){
      digitalWrite(outOxy2, HIGH);
      digitalWrite(outOxy1, LOW);
      //Serial.print("Entro Oxy1: ");
      //Serial.println(contador);
    }
    if(cambio == 1){
      digitalWrite(outOxy1, HIGH);
      digitalWrite(outOxy2, LOW);
      //Serial.print("Entro Oxy2: ");
      //Serial.println(contador);
    }    
  }else{
    digitalWrite(outOxy1, HIGH);
    digitalWrite(outOxy2, HIGH);
  }
  if((actO == 0)){
    Serial1.print("page2.t14.txt=\"No\"");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);     
    delay(50);
   }  

      

  //---------------------------------------------------------------------------------
  
  //-----------------------------------------------------------------------------
  //--------------------------------CO2-----------------------------------------
  
  Serial.print("variaCo2Str: ");
  Serial.println(variaCo2Str);  
  mniC = variaCo2Str.substring(0,4).toInt();
  actC = variaCo2Str.substring(4,5).toInt();  
  minPool = (hrfP*60 + mnfP + sgfP/60) - (hriP*60 + mniP + sgiP/60);
  
  divMinP =  (minPool-mniC)/4; //Intervalo en cero
  
  divMinPInt = divMinP;
  decimasP = divMinP - divMinPInt;
  decimasP = decimasP*4;

  divMinC = (float) (mniC)/4; //intervalo en 1
  Serial.print("mniC: ");
  Serial.println(mniC);
  divMinCInt = divMinC;
  
  decimasC = divMinC - divMinCInt;
  decimasC = decimasC*4;

  tiemposCO2[0] = divMinC; //Actual 12/07/2017 3:02 am
  tiemposCO2[1] = divMinP;
  tiemposCO2[2] = divMinC;
  tiemposCO2[3] = divMinP;
  tiemposCO2[4] = divMinC;
  tiemposCO2[5] = divMinP;
  tiemposCO2[6] = divMinC;
  tiemposCO2[7] = divMinP;  
  
/*
  tiemposCO2[0] = divMinCInt; ///Antes
  tiemposCO2[1] = divMinPInt;
  tiemposCO2[2] = divMinCInt;
  tiemposCO2[3] = divMinPInt;
  tiemposCO2[4] = divMinCInt;
  tiemposCO2[5] = divMinPInt;
  tiemposCO2[6] = divMinCInt + decimasC;
  tiemposCO2[7] = divMinPInt + decimasP;
 */ 

 
  Serial.print("tiemposCO2[0]: ");
  Serial.println(tiemposCO2[0]);
  Serial.print("tiemposCO2[1]: ");
  Serial.println(tiemposCO2[1]); 
  Serial.print("tiemposCO2[2]: ");
  Serial.println(tiemposCO2[2]);
  Serial.print("tiemposCO2[3]: ");
  Serial.println(tiemposCO2[3]); 
  Serial.print("tiemposCO2[4]: ");
  Serial.println(tiemposCO2[4]);
  Serial.print("tiemposCO2[5]: ");
  Serial.println(tiemposCO2[5]); 
  Serial.print("tiemposCO2[6]: ");
  Serial.println(tiemposCO2[6]);
  Serial.print("tiemposCO2[7]: ");
  Serial.println(tiemposCO2[7]);   

  
  
  minReloj = horaRTC.hr*60 + horaRTC.mn + (float) horaRTC.sg/60;
  difMin = minReloj - (hriP*60 + mniP + sgiP/60); 

  //float testSeg = (float) horaRTC.sg/60;
  //Serial.print("horaRTC.sg/60: "); 
  //Serial.println(testSeg);
  
  if((poolInicio<hora) && (poolFin>hora) && (actP == 1) && (actC == 1)){
    if(primer==0){
      minrefCo2 = tiemposCO2[pos];
      primer++;     
    }
    if(!(difMin<minrefCo2) && primer > 0 && pos<=7){
      pos++;
      minrefCo2 = minrefCo2 + tiemposCO2[pos];
    }
    Serial.print("pos: ");
    Serial.println(pos);  
    Serial.print("difMin: ");
    Serial.println(difMin); 
    Serial.print("minrefCo2: ");
    Serial.println(minrefCo2);
    if(pos%2==0){
      digitalWrite(outCO2, LOW);
    }else{
      digitalWrite(outCO2, HIGH);
    }   
  }else{
    minrefCo2 = 0;
    primer = 0; 
    pos=0;
    digitalWrite(outCO2, HIGH);   
  }   
  
  


  

}


