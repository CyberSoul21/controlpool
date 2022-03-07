#ifndef ControlPool3_h
#define ControlPool3_h

#include "memoria.h"


tiempoStruct valuPool;
String variaPoolStr;

void valorInicialPool(tiempoStruct valores){
  String valoresStr;
  valoresStr=String(valores);
  //Datos Inicio operacion
  String hri = "";
  String mni = "";
  String sgi = "";
  //Datos fin de operacion
  String hrf = "";
  String mnf = "";
  String sgf = "";
  String act = "";
  String dia= "";
  
  hri = valoresStr.substring(0,2);//Enviar a la memoria
  mni = valoresStr.substring(3,5);
  sgi = valoresStr.substring(6,8);
    
  hrf = valoresStr.substring(9,11);
  mnf = valoresStr.substring(12,14);
  sgf = valoresStr.substring(15,17);
  dia = valoresStr.substring(18,19);
  act = valoresStr.substring(20,21);    



  Serial1.print("page2.t5.txt=\""+hri+":"+mni+":"+sgi+"\"");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);  
  delay(50);
  Serial1.print("page2.t6.txt=\""+hrf+":"+mnf+":"+sgf+"\"");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff); 
  delay(50);
  if(act=="1"){
    Serial1.print("page2.t13.txt=\"Si\"");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);     
    delay(50);    
  }
  if(act=="0"){
    Serial1.print("page2.t13.txt=\"No\"");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);     
    delay(50);    
  }  

}


void inicioFinPool(){//Ajustar inicio y fin, recibir dato de estado activo o desactivado
  
  String data = "";
  bool flag = true;
  int actiPool = 0;
  //Datos inicio operacion
  String hri = "00";
  //int hri = 12;
  String mni = "00";
  //int mni = 45;
  String sgi = "00";
  //int sgi = 32;
  //Datos fin de operacion
  String hrf = "00";
  //int hrf = 12;
  String mnf = "00";
  //int mnf = 45;
  String sgf = "00";  
  //int sgf = 32;
  String dia = "0";
  String act = "0";
  
  String valuPoolStr;
  
  
  while (flag)//Espera instrucciones desde la LCD
  {
    while (Serial1.available())//Espera instrucciones desde la LCD
    {
      data = Serial1.readStringUntil('\n');
      //while(Serial1.available()){
      //Serial1.read();}
      //Serial1.flush(); 
      if(data.length()>6){
        

        hri = data.substring(0,2);//Enviar a la memoria
        mni = data.substring(3,5);
        sgi = data.substring(6,8);
        
        hrf = data.substring(9,11);
        mnf = data.substring(12,14);
        sgf = data.substring(15,17);
        dia = data.substring(18,19);
        act = data.substring(19,20);        
        //Serial.print("dia: ");
        //Serial.println(dia);
        //Serial.print("act: ");
        //Serial.println(act);        
        valuPoolStr = hri+":"+mni+":"+sgi+":"+hrf+":"+mnf+":"+sgf+":"+dia+":"+act;
        conversorChar(valuPoolStr,valuPool);  
        variaPoolStr=valuPoolStr;      
        //Serial.print("valuPool: ");
        //Serial.println(valuPool);           
    /*  Serial.println(hri);//Solo para vigilar con el serial del PC*Borrar esta linea cuando termine pruebas
        Serial.println(mni);
        Serial.println(sgi);
        Serial.println(hrf);
        Serial.println(mnf);
        Serial.println(sgf);
        Serial.println(dia);
        Serial.println(act);        
     */   

        Serial1.print("page 2");
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff);      
        delay(50);


  
        //guardar(valuPool,0);
        eeprom.write(100, (byte*) valuPool, sizeof(valuPool));
        delay(500);        
        flag = false;
        
      }else if(data=="volver"){

        delay(50);
        Serial1.print("page 3");
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff); 
        delay(50);        
        //Serial.println("Volver");

        flag = false;
        }
        else{
          flag = true;
         }
       }
  }
}

#endif

























