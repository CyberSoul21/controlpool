#ifndef ControlPool_h
#define ControlPool_h

#include <DS3231.h>
DS3231  rtc(SDA, SCL);

struct horaStruct{
  long int hr;
  long int mn;
  long int sg;
  long int di;
};


horaStruct horaRTC;

void recibirFecha(){
  String data = "";
  bool flag = true;
  //String hr = "";
  //String mn = "";
  //String sg = "";
  long int hr = 12;
  long int mn = 45;
  long int sg = 32;

  long int di = 1;
  long int ms = 1;
  long int an = 2000;
  long int dil = 1;
  
  
  while (flag)//Espera instrucciones desde la LCD
  {
    while (Serial1.available())//Espera instrucciones desde la LCD
    {
      data = Serial1.readStringUntil('\n');
      if(data.length() > 7){
        //Serial.println(data);
        hr = data.substring(0,2).toInt();
        mn = data.substring(3,5).toInt();
        sg = data.substring(6,8).toInt();
        di = data.substring(9,11).toInt();
        ms = data.substring(12,14).toInt();
        an = data.substring(15,19).toInt();
        dil = data.substring(20,21).toInt();         
        delay(100);
        rtc.setTime(hr, mn, sg);
        delay(200);
        rtc.setDate(di, ms, an);
        delay(200);
        rtc.setDOW(dil);                               
        //Serial.println(dil);
        flag = false;
      }else{
        Serial.println("Volver");
        flag = false;
      }        
    }
  }
}

void obtenerFecha(){
   String reloj = rtc.getTimeStr();
   delay(50);
   String fecha = rtc.getDateStr();
   String dia = rtc.getDOWStr();
   String enviar1 = "";
   String enviar2 = ""; 
   String enviar3 = "";
   String enviar4 = ""; 
   String enviar5 = "";    
   
   horaRTC.hr = reloj.substring(0,2).toInt();
   horaRTC.mn = reloj.substring(3,5).toInt();
   horaRTC.sg = reloj.substring(6,8).toInt();
   

  if(dia=="Monday"){
    dia = "Lunes";
    horaRTC.di = 1;
  }else if(dia=="Tuesday"){
    dia = "Martes";
    horaRTC.di = 2;
  }else if(dia=="Wednesday"){
    dia = "Miercoles";
    horaRTC.di = 3;
  }else if(dia=="Thursday"){
    dia = "Jueves";
    horaRTC.di = 4;
  }else if(dia=="Friday"){
    dia = "Viernes";
    horaRTC.di = 5;
  }else if(dia=="Saturday"){
    dia = "Sabado";
    horaRTC.di = 6;
  }else if(dia=="Sunday"){
    dia = "Domingo";
    horaRTC.di = 7;
  }  
   
   enviar1 = "page2.t0.txt=\""+reloj+"\"";
   enviar2 = "page4.t0.txt=\""+reloj+"\"";
   enviar3 = "page2.t1.txt=\""+fecha+"\"";
   enviar4 = "page4.t1.txt=\""+fecha+"\"";
   enviar5 = "page4.t2.txt=\""+dia+"\""; 
   delay(50);
   //Serial.println(enviar); 
   Serial1.print(enviar1);
   Serial1.write(0xff);
   Serial1.write(0xff);
   Serial1.write(0xff);
   delay(50);
   Serial1.print(enviar2);
   Serial1.write(0xff);
   Serial1.write(0xff);
   Serial1.write(0xff);
   delay(50);
   Serial1.print(enviar3);
   Serial1.write(0xff);
   Serial1.write(0xff);
   Serial1.write(0xff);
   delay(50);
   Serial1.print(enviar4);
   Serial1.write(0xff);
   Serial1.write(0xff);
   Serial1.write(0xff);
   delay(50);
   Serial1.print(enviar5);
   Serial1.write(0xff);
   Serial1.write(0xff);
   Serial1.write(0xff);   
}

String formato(int valor){
  if(valor<=9){
    return "0"+String(valor); 
  }else{
    return String(valor);  
  }
  
}


#endif

