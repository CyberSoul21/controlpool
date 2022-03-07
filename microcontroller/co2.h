#ifndef ControlPool9_h
#define ControlPool9_h

co2Struct valuCo2;
String variaCo2Str;


void valorInicialCo2(co2Struct valores){
  
  String valoresStr;
  valoresStr=String(valores);
  //Datos Inicio operacion
  String mni = "";
  String act = "";


  mni = valoresStr.substring(0,3);//Enviar a la memoria
  act = valoresStr.substring(4,5);
   
  Serial.print("mni: ");
  Serial.println(mni);
  Serial.print("act: ");
  Serial.println(act);


  Serial1.print("page14.t0.txt=\""+act+"\"");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);     
  delay(50);
  Serial1.print("page14.t1.txt=\""+mni+"\"");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);     
  delay(50);  
    
}


void inicioFinCo2(){//Ajustar inicio y fin, recibir dato de estado activo o desactivado
  
  String data = "";
  bool flag = true;
  int actiIon = 0;
  //Datos inicio operacion

  String mni = "00";
  String act = "0";
  
  String valuCo2Str;
  
  
  while (flag)//Espera instrucciones desde la LCD
  {
    while (Serial1.available())//Espera instrucciones desde la LCD
    {
      data = Serial1.readStringUntil('\n');
      if(data.length()>3){
        Serial.print("Llego del DATA CO2: ");
        Serial.println(data);         

        mni = data.substring(0,3);//Enviar a la memoria
        act = data.substring(4,5);
                
        valuCo2Str = mni+":"+act;
        conversorCharCo2(valuCo2Str,valuCo2);   
        variaCo2Str = valuCo2Str;
        Serial.print("Guardar- valuCO2: ");
        Serial.println(variaCo2Str); 
          
        Serial.println(mni);//Solo para vigilar con el serial del PC*Borrar esta linea cuando termine pruebas
        Serial.println(act);        
        

        Serial1.print("page 2");
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff);      
        delay(50);


  
        //guardar(valuIon,0);
        eeprom.write(400, (byte*) valuCo2, sizeof(valuCo2));
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

