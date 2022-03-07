#ifndef ControlPool6_h
#define ControlPool6_h

#include <Eeprom_at24c256.h>

Eeprom_at24c256 eeprom(0x50);


//Direccion en memoria
//0x00 0-----> Pool  100
//0x0E 16----> Oxy   0
//0x1C 32----> Ion   200 //por cambio en el oin ya no se usara este espacio
//0x2A 48----> IonM  300
//0x2A 48----> CO2   400
//0x2A 48----> Bloq   500
//0x1C 32----> Ion LUNES     600 //nuevo ION hora para cada dia
//0x1C 32----> Ion MARTES    620 //nuevo ION hora para cada dia
//0x1C 32----> Ion MIERCOLES 640 //nuevo ION hora para cada dia
//0x1C 32----> Ion JUEVES    660 //nuevo ION hora para cada dia
//0x1C 32----> Ion VIERNES   680 //nuevo ION hora para cada dia
//0x1C 32----> Ion SABADO    720 //nuevo ION hora para cada dia
//0x1C 32----> Ion DOMINGO   7400 //nuevo ION hora para cada dia


typedef char tiempoStruct[21];
typedef char contraStruct[11];
typedef char co2Struct[5];

typedef char ionStruct[20];

 //.....................|dia|activo|       
//"hri:mni:sgi:hrf:mnf:sgf:4:1";
//"00:00:00:00:00:00:0:0"


void guardar(tiempoStruct valores,int dir){
  Serial.print("Llego a guardar: " );
  Serial.println(valores);
  eeprom.write(dir, (byte*) valores, sizeof(valores));
  delay(500);
}

void leer(int dir, tiempoStruct &valores1){
  eeprom.read(dir, (byte*) valores1, sizeof(valores1));
  delay(500);
}



void guardarContr(contraStruct valores,int dir){
  Serial.print("Llego a guardar: " );
  Serial.println(valores);
  eeprom.write(dir, (byte*) valores, sizeof(valores));
  delay(500);
}

void leerContr(int dir, contraStruct &valores1){
  eeprom.read(dir, (byte*) valores1, sizeof(valores1));
  delay(500);
}


void conversorChar(String valorStr,tiempoStruct &valorChar){
  for(int i=0; i<21;i++){    
    valorChar[i]=valorStr[i];
    //Serial.println(valorChar[i]);
    //delay(100);
  }
  //Serial.println(valorChar);
}

void conversorCharIon(String valorStr,ionStruct &valorChar){
  for(int i=0; i<20;i++){    
    valorChar[i]=valorStr[i];
    //Serial.println(valorChar[i]);
    //delay(100);
  }
  //Serial.println(valorChar);
}



void conversorCharCo2(String valorStr,co2Struct &valorChar){ //Para la contraseña
  for(int i=0; i<5;i++){    
    valorChar[i]=valorStr[i];
    //Serial.println(valorChar[i]);
    //delay(100);
  }
  //Serial.println(valorChar);
}


void conversorChar11(String valorStr,contraStruct &valorChar){ //Para la contraseña
  for(int i=0; i<11;i++){    
    valorChar[i]=valorStr[i];
    //Serial.println(valorChar[i]);
    //delay(100);
  }
  //Serial.println(valorChar);
}

String conversorStr(String valorStr,tiempoStruct valorChar){
  for(int i=0; i<21;i++){    
    valorStr[i]=valorChar[i];
    //Serial.println(pool[i]);
    //delay(100);
  }
  return valorStr;   
}



#endif

