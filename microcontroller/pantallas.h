#ifndef ControlPool8_h
#define ControlPool8_h


void pantallaInicio(){  
  delay(2000);
  Serial1.print("page 1");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);      
  //Serial.println("Holi");  
}

void pantallaPrincipal(){  
  delay(50);
  Serial1.print("page 2");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);      
   
}

void pantallaPool(){  
  delay(100);
  Serial1.print("page 5");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);      
    
}
void pantallaOxy(){  
  delay(100);
  Serial1.print("page 6");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);      
    
}
void pantallaIon0(){
  String data = "";  
  int opc=0;
  bool flag=true; 
  delay(50);
  Serial1.print("page 15");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);      
  
}
void pantallaIon1(){ ///////////////////////////////Eliminar 
  delay(100);
  Serial1.print("page 9");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);      
  //Serial.println("Holi");  
}
void pantallaIon2(){////////////////////////////Eliminar  
  delay(100);
  Serial1.print("page 10");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);      
    
}

void pantallaIonM(){  
  delay(100);
  Serial1.print("page 11");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);      
    
}

void pantallaCO2(){  
  delay(100);
  Serial1.print("page 14");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);      
   
}
void pantallaMenu(){  
  delay(100);
  Serial1.print("page 3");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);      
   
}


void pantallaFecha(){  
  delay(100);
  Serial1.print("page 8");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);      
    
}
void pantallaBloqueo(){  
  delay(100);
  Serial1.print("page 1");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);      
    
}
void pantaCambiarContrasena(){  
  delay(100);
  Serial1.print("page 13");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);      
   
}
int contrasenaPregunta(){
  String data = "";  
  int opc=0;
  bool flag=true; 
  delay(50);
  Serial1.print("page 12");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);      
  
  while (flag)//Espera instrucciones desde la LCD
  {
    //Serial.println("Entre");
    while (Serial1.available())//Espera instrucciones desde la LCD
    {      
      data = Serial1.readStringUntil('\n');
      if(data=="si"){
        opc=1;
        flag = false;
      }
      else if(data=="no"){
        opc=2;
        flag = false;
      }
      else if(data="volver"){
        opc=3;
        flag = false;
      }
    }
  }
  return opc;
}

#endif

