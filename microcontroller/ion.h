#ifndef ControlPool5_h
#define ControlPool5_h

ionStruct valuIon;
String variaIonStr;

String valoresStr1;
String valoresStr2;
String valoresStr3;
String valoresStr4;
String valoresStr5;
String valoresStr6;
String valoresStr7;

void valorInicialIon(ionStruct valores1,ionStruct valores2,ionStruct valores3,ionStruct valores4,ionStruct valores5,ionStruct valores6,ionStruct valores7,long int dia){

  String trama; //Va para la LCD
    
  valoresStr1=String(valores1);
  valoresStr1 = valoresStr1.substring(0,20);
  //Serial.println("valoresStr1: ");
  //Serial.println(valoresStr1);
    
  valoresStr2=String(valores2);
  valoresStr2 = valoresStr2.substring(0,20);
  //Serial.println("valoresStr2: ");
  //Serial.println(valoresStr2);  
  
  valoresStr3=String(valores3);
  valoresStr3 = valoresStr3.substring(0,20);  
  //Serial.println("valoresStr3: ");
  //Serial.println(valoresStr3);
    
  valoresStr4=String(valores4);
  valoresStr4 = valoresStr4.substring(0,20);  
  //Serial.println("valoresStr4: ");
  //Serial.println(valoresStr4);
    
  valoresStr5=String(valores5);
  valoresStr5 = valoresStr5.substring(0,20);  
  //Serial.println("valoresStr5: ");
  //Serial.println(valoresStr5);
    
  valoresStr6=String(valores6);
  valoresStr6 = valoresStr6.substring(0,20);  
  //Serial.println("valoresStr6: ");  
  //Serial.println(valoresStr6);
    
  valoresStr7=String(valores7);
  valoresStr7 = valoresStr7.substring(0,20);  
  //Serial.println("valoresStr7: ");
  //Serial.println(valoresStr7);
    
  trama = valoresStr1+valoresStr2+valoresStr3+valoresStr4+valoresStr5+valoresStr6+valoresStr7;


  switch(dia){
    case 1:
      Serial1.print("page2.t16.txt=\"Lunes\"");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);
      break;
    case 2:
      Serial1.print("page2.t16.txt=\"Martes\"");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);      
      break;
    case 3:
      Serial1.print("page2.t16.txt=\"Miercoles\"");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);      
      break;
    case 4:
      Serial1.print("page2.t16.txt=\"Jueves\"");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);      
      break;
    case 5:
      Serial1.print("page2.t16.txt=\"Viernes\"");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);      
      break;
    case 6:
      Serial1.print("page2.t16.txt=\"Sabado\"");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);      
      break;
    case 7:
      Serial1.print("page2.t16.txt=\"Domingo\"");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);      
      break;   
    }
  
  Serial.print("********valorInicialIon*********");
  Serial.println("Trama: ");
  Serial.println(trama);
  
  
  Serial1.print("page15.trama.txt=\""+trama+"\"");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);     
  delay(50);  
}


void inicioFinIon(){//Ajustar inicio y fin, recibir dato de estado activo o desactivado
  
  String data = "";
  bool flag = true;
  int actiIon = 0;
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
  
  String valuIonStr;
  bool flag2=true;


  String lunesIon = "";
  String martesIon = "";
  String miercolesIon = "";
  String juevesIon = "";
  String viernesIon = "";        
  String sabadoIon = "";
  String domingoIon = "";
  String trama = "";
      
while (flag)//Espera instrucciones desde la LCD
  {
    while (Serial1.available())//Espera instrucciones desde la LCD
    {
      data = Serial1.readStringUntil('\n');
      if(data.length()>120){
        Serial.print("Llego del DATA ION: ");
        Serial.println(data);
 
        lunesIon = data.substring(0,20);
        Serial.print("lunes: ");
        Serial.println(lunesIon);
        martesIon = data.substring(20,40);
        Serial.print("martes: ");
        Serial.println(martesIon);
        miercolesIon = data.substring(40,60);
        Serial.print("miercoles: ");
        Serial.println(miercolesIon);
        juevesIon = data.substring(60,80);
        Serial.print("jueves: ");
        Serial.println(juevesIon);
        viernesIon = data.substring(80,100);
        Serial.print("viernes: ");
        Serial.println(viernesIon);
        sabadoIon = data.substring(100,120);
        Serial.print("sabado: ");
        Serial.println(sabadoIon);
        domingoIon = data.substring(120,141);
        Serial.print("domingo: ");
        Serial.println(domingoIon);          
        
        valuIonStr=lunesIon;
        conversorCharIon(valuIonStr,valuIon);   
        eeprom.write(600, (byte*) valuIon, sizeof(valuIon));
        delay(50); 

        valuIonStr=martesIon;
        conversorCharIon(valuIonStr,valuIon);   
        eeprom.write(620, (byte*) valuIon, sizeof(valuIon));
        delay(50); 

        valuIonStr=miercolesIon;
        conversorCharIon(valuIonStr,valuIon);   
        eeprom.write(640, (byte*) valuIon, sizeof(valuIon));
        delay(50); 

        valuIonStr=juevesIon;
        conversorCharIon(valuIonStr,valuIon);   
        eeprom.write(660, (byte*) valuIon, sizeof(valuIon));
        delay(50); 

        valuIonStr=viernesIon;
        conversorCharIon(valuIonStr,valuIon);   
        eeprom.write(680, (byte*) valuIon, sizeof(valuIon));
        delay(50); 

        valuIonStr=sabadoIon;
        conversorCharIon(valuIonStr,valuIon);   
        eeprom.write(720, (byte*) valuIon, sizeof(valuIon));
        delay(50); 

        valuIonStr=domingoIon;
        conversorCharIon(valuIonStr,valuIon);   
        eeprom.write(740, (byte*) valuIon, sizeof(valuIon));
        delay(50);
        
        valoresStr1 =lunesIon;
        valoresStr2 =martesIon;
        valoresStr3 =miercolesIon;
        valoresStr4 =juevesIon;
        valoresStr5 =viernesIon;
        valoresStr6 =sabadoIon;
        valoresStr7 =domingoIon;                                                         

        trama = valoresStr1+valoresStr2+valoresStr3+valoresStr4+valoresStr5+valoresStr6+valoresStr7;
        Serial.println("VALOR A GUARDAR DE LA TRAMA: ");
        Serial.println(trama);
        
        Serial1.print("page15.trama.txt=\""+trama+"\"");
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff);     
        delay(50);         


        
        //Serial.print("valuIon: ");
        //Serial.println(valuIon); 

        Serial1.print("page 2");
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff);      
        delay(50);

        
       
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

