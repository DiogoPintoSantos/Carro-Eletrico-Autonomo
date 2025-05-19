
#include <Adafruit_Sensor.h>  //INCLUSÃO DE BIBLIOTECA
#include <Adafruit_BMP280.h>  //INCLUSÃO DE BIBLIOTECA
extern String dht22();
void PMB_208();


void PMB_208() {
  temperatura = String(bmp.readTemperature());
  pressao = String(bmp.readPressure());
  altitude = String(bmp.readAltitude(1026), 0);
  Serial.println(""+ temperatura +" "+ pressao +" "+ altitude +" "+ dht22());
  
}
