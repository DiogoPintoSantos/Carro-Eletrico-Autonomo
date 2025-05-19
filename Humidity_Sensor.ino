

//Libraries
String dht22();
#include <DHT.h>
String dht22(){
  delay(2000);
  //Read data and store it to variables hum and temp
  hum = String(dht.readHumidity());
  //Print temp and humidity values to serial monitor

  return hum;
  delay(1000);  //Delay 2 sec.
}
