#include <Ultrasonic.h>
void motorDC(float distance, float distanceb);
int p = 30;  //distância limite

void motorDC(float distance, float distanceb) {

  if (distance > p && distanceb > p) {
    moveForward();
  } else  {
    moveBackBrake();

    if (distance < distanceb) {
      moveLeft();
    } else if (distance > distanceb) {
      moveRight();
    }
  }
}
// Robo anda para a direita
void moveRight() {
 // Serial.println("Direita");
  digitalWrite(brakePin, LOW);
  digitalWrite(brakePinb, LOW);
  digitalWrite(directionPin, HIGH);
  digitalWrite(directionPinb, LOW);
  analogWrite(pwmPin, 200);
  analogWrite(pwmPinb, 160);
  delay(1000);
  analogWrite(pwmPin, 0);
  analogWrite(pwmPinb, 0);
  delay(500);
 // Serial.println("Acaba de virar para a direita:");
}
//Robo anda para a esquerda
void moveLeft() {
//  Serial.println("Esquerda");
  digitalWrite(brakePin, LOW);
  digitalWrite(brakePinb, LOW);
  digitalWrite(directionPin, LOW);
  digitalWrite(directionPinb, HIGH);
  analogWrite(pwmPin, 180);
  analogWrite(pwmPinb, 200);
  delay(1000); 
  analogWrite(pwmPin, 0);
  analogWrite(pwmPinb, 0);
  delay(500);
  //Serial.println("Acaba de virar para a esquerda:");
}
//robo anda para a frente
void moveForward() {
//  Serial.println("Anda para a frente");
  digitalWrite(brakePin, LOW);
  digitalWrite(brakePinb, LOW);
  digitalWrite(directionPin, HIGH);
  digitalWrite(directionPinb, HIGH);
  analogWrite(pwmPin, 200);
  analogWrite(pwmPinb, 200);
  delay(1000);
}
//Robo anda para trás e pára
void moveBackBrake() {
  //Serial.println("Too close");
  digitalWrite(brakePin, LOW);
  digitalWrite(brakePinb, LOW);
  digitalWrite(directionPin, LOW);
  digitalWrite(directionPinb, LOW);
  analogWrite(pwmPin, 200);
  analogWrite(pwmPinb, 200);
  delay(500);
  digitalWrite(brakePin, HIGH);
  digitalWrite(brakePinb, HIGH);
  delay(200);
  //Serial.println("Acaba de andar para tras:");
}
