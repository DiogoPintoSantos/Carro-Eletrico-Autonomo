
#include <Adafruit_Sensor.h>//INCLUSÃO DE BIBLIOTECA
#include <Adafruit_BMP280.h> //INCLUSÃO DE BIBLIOTECA
void PMB_208();
 //OBJETO DO TIPO Adafruit_BMP280 (I2C)


void PMB_208(){
  temperatura = String(bmp.readTemperature());
 pressao = String(bmp.readPressure());
 altitude = String(bmp.readAltitude(1026),0);
                                           //INTERVALO DE 2 SEGUNDOS
  if (Serial.available()) {
    char a = Serial.read();
    if (a == 't') {
      Serial.println("Temperatura:" + temperatura + " ºC Pressao: "+ pressao + " Pa, Altitude: " + altitude + "m");
      
      
      
      }

}}
