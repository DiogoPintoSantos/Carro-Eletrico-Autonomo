#include <DHT.h>
#include <Ultrasonic.h>
#include <Adafruit_Sensor.h>//INCLUSÃO DE BIBLIOTECA
#include <Adafruit_BMP280.h>
#include <SoftwareSerial.h>
Adafruit_BMP280 bmp;
SoftwareSerial mySerial(0, 1);
String temperatura, pressao, altitude,hum;
#define echoPin 2
#define echoPinb 4  // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 5   //attach pin D3 Arduino to pin Trig of HC-SR04
#define trigPinb 6
#define DHTPIN 10  // what pin we're connected to
#define DHTTYPE DHT22  // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE);  //// Initialize DHT sensor for normal 16mhz Arduino
Ultrasonic ultrasonic1(trigPin, echoPin);
Ultrasonic ultrasonic2(trigPinb, echoPinb);
extern void motorDC(float distance, float distanceb);
extern void PMB_208();
extern String dht22();

// defines variables
// variable for the duration of sound wave travel
int directionPin = 12;
int pwmPin = 3;
int brakePin = 9;
//uncomment if using channel B, and remove above definitions
int directionPinb = 13;
int pwmPinb = 11;
int brakePinb = 8;
bool directionState;
int chk;

 //Stores humidity value

float temp;  //Stores temperature value


void setup() {
  // Sets the echoPin as an INPUT
  pinMode(directionPin, OUTPUT);
  pinMode(pwmPin, OUTPUT);
  pinMode(brakePin, OUTPUT);
  pinMode(directionPinb, OUTPUT);
  pinMode(pwmPinb, OUTPUT);
  pinMode(brakePinb, OUTPUT);
  Serial.begin(9600);  // // Serial Communication is starting with 9600 of baudrate speed
  dht.begin();
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }

  mySerial.begin(9600);
  if(!bmp.begin(0x76)){ //SE O SENSOR NÃO FOR INICIALIZADO NO ENDEREÇO I2C 0x76, FAZ
    Serial.println(F("Sensor BMP280 não foi identificado! Verifique as conexões.")); //IMPRIME O TEXTO NO MONITOR SERIAL
    while(1); //SEMPRE ENTRE NO LOOP
}

}
void loop() {
  float distance = ultrasonic1.Ranging(CM);
  float distanceb = ultrasonic2.Ranging(CM);
  // Serial.println(distance);
  // Serial.println(distanceb);
  motorDC(distance, distanceb);

  PMB_208();
  
}
