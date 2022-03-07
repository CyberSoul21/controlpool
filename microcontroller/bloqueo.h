#ifndef ControlPool2_h
#define ControlPool2_h

contraStruct valuContr;
String variaContrStr;

int ingresoContrasena(String password, int pantalla, String ano){//AquÃ­ debe recibir contraseÃ±a almacenada en la memoria
  bool flag = true;
  String data = "";
  String realPass = "";
  int digitos = 0; 
  int okCtr=0;
  Serial.println("Estoy en contrasena");
  while(flag){
    while (Serial1.available())//Espera instrucciones desde la LCD
    {
      data = Serial1.readStringUntil('\n');
      Serial.print("data: ");
      Serial.println(data);
      if(password.substring(10,11).toInt()==0){
        digitos = 10;
      }else{
        digitos = password.substring(10,11).toInt();
        realPass = password.substring(0,digitos);        
      }
      Serial.println(realPass);      
      
      if(data==ano)//ContraseÃ±a
      {
        if(pantalla==2){
          Serial1.print("page 2");
          Serial1.write(0xff);
          Serial1.write(0xff);
          Serial1.write(0xff);
          flag = false;        
        }
        if(pantalla==13){
          Serial1.print("page 13");
          Serial1.write(0xff);
          Serial1.write(0xff);
          Serial1.write(0xff);
          flag = false;        
        }        
        okCtr=1;
      }
      else if(data==realPass)//ContraseÃ±a
      {
        if(pantalla==2){
          Serial1.print("page 2");
          Serial1.write(0xff);
          Serial1.write(0xff);
          Serial1.write(0xff);
          flag = false;        
        }
        if(pantalla==13){
          Serial1.print("page 13");
          Serial1.write(0xff);
          Serial1.write(0xff);
          Serial1.write(0xff);
          flag = false;        
        }
        okCtr=1; 
      }      
      else if(data=="volverContr")
      {
        Serial1.print("page 4");
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff);
        delay(100);
        Serial1.print("page1.t3.txt=\"\"");
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff);
        flag = false;
        okCtr=0; 
      }else{
        Serial1.print("page1.t3.txt=\"*Inorrecto\"");
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff);
        okCtr=0;        
      }
    }    
  }  
  return okCtr;
}

void cambiarContrasena(){//Cambiar Contraseña
  
  String data = "";
  bool flag = true;
  String valuContrStr="";
  
  while (flag)//Espera instrucciones desde la LCD
  {
    while (Serial1.available())//Espera instrucciones desde la LCD
    {
      data = Serial1.readStringUntil('\n');
      //while(Serial1.available()){
      //Serial1.read();}
      if(data.length()==11){
        
        Serial.print("Llego del contraseña: ");
        Serial.println(data);  
        valuContrStr = data;    
        conversorChar11(valuContrStr,valuContr); 
        
        Serial1.print("page 2");
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff);      
        delay(50);
        Serial.println(valuContr);

        eeprom.write(500, (byte*) valuContr, sizeof(valuContr));
        delay(500);        
        flag = false;
        
      }else if(data=="00"){

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

