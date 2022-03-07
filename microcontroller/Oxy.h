#ifndef ControlPool4_h
#define ControlPool4_h

tiempoStruct valuOxy;
String variaOxyStr;

void valorInicialOxy(tiempoStruct valores){
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
  String dia = "";
  
  hri = valoresStr.substring(0,2);//Enviar a la memoria
  mni = valoresStr.substring(3,5);
  sgi = valoresStr.substring(6,8);
    
  hrf = valoresStr.substring(9,11);
  mnf = valoresStr.substring(12,14);
  sgf = valoresStr.substring(15,17);
  dia = valoresStr.substring(18,19);
  act = valoresStr.substring(20,21);
  /*
  Serial.print("hri: ");
  Serial.println(hri);
  Serial.print("mni: ");
  Serial.println(mni);
  Serial.print("sgi: ");
  Serial.println(sgi);
  Serial.print("hrf: ");
  Serial.println(hrf);
  Serial.print("mnf: ");
  Serial.println(mnf);
  Serial.print("sgf: ");
  Serial.println(sgf); 
  Serial.print("dia: ");
  Serial.println(dia);
  Serial.print("act: ");
  Serial.println(act);        
  
  */
  Serial1.print("page2.t7.txt=\""+hri+":"+mni+":"+sgi+"\"");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);  
  delay(50);
  Serial1.print("page2.t8.txt=\""+hrf+":"+mnf+":"+sgf+"\"");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff); 
  delay(50);
  Serial1.print("page2.t14.txt=\""+act+"\"");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);     
  delay(50);
}


void inicioFinOxy(){//Ajustar inicio y fin, recibir dato de estado activo o desactivado
  
  String data = "";
  bool flag = true;
  int actiOxy = 0;
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
  
  String valuOxyStr;
  
  
  while (flag)//Espera instrucciones desde la LCD
  {
    while (Serial1.available())//Espera instrucciones desde la LCD
    {
      data = Serial1.readStringUntil('\n');
      //while(Serial1.available()){
      //Serial1.read();}
      if(data.length()>6){
        
        Serial.print("Llego del DATA Oxy: ");
        Serial.println(data); 
          
        hri = data.substring(0,2);//Enviar a la memoria
        mni = data.substring(3,5);
        sgi = data.substring(6,8);
        
        hrf = data.substring(9,11);
        mnf = data.substring(12,14);
        sgf = data.substring(15,17);
        dia = data.substring(18,19);
        act = data.substring(19,20);
        Serial.println("Descomponiendo el DATA Oxy: ");      
        Serial.print("hri: ");
        Serial.println(hri);
        Serial.print("mni: ");
        Serial.println(mni);
        Serial.print("sgi: ");
        Serial.println(sgi);
        Serial.print("hrf: ");
        Serial.println(hrf);
        Serial.print("mnf: ");
        Serial.println(mnf);
        Serial.print("sgf: ");
        Serial.println(sgf); 
        Serial.print("dia: ");
        Serial.println(dia);
        Serial.print("act: ");
        Serial.println(act);         



                
        
        valuOxyStr = hri+":"+mni+":"+sgi+":"+hrf+":"+mnf+":"+sgf+":"+dia+":"+act;
        conversorChar(valuOxyStr,valuOxy);   
        variaOxyStr=valuOxyStr;
        Serial.print("Guardar- valuOxy: ");
        Serial.println(valuOxyStr); 
          
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


  
        //guardar(valuOxy,0);
        eeprom.write(0, (byte*) valuOxy, sizeof(valuOxy));
        delay(500);        
        flag = false;
        
      }else if(data=="volver"){

        delay(50);
        Serial1.print("page 3");
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff); 
        delay(50);        
        

        flag = false;
        }
        else{
          flag = true;
         }
       }
  }
}


#endif

