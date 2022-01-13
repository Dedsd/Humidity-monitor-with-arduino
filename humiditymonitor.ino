#include <DHT.h>
#define DHTPIN 5 // dht pin
#define DHTTYPE DHT11

const int red = 2; // led rgb red pin
const int green = 3; // led rgb green pin
const int blue = 4; // led rgb blue pin

DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  dht.begin(); // initialize DHT
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  delay(1000);
  float hum = dht.readHumidity();
  if (isnan(hum)) {
    return; // if is not a number do the read again
  }
  
  Serial.print(hum);
  Serial.println("%");
  
  if (hum <= 50 && hum >= 30) {
    analogWrite(red, 32);
    analogWrite(green, 178);
    analogWrite(blue, 170);
  }
  
  else if (hum < 30) {
    analogWrite(red, 255);
    analogWrite(green, 255);
    analogWrite(blue, 0);
  }
  
  else if (hum > 50) {
    analogWrite(red, 255);
    analogWrite(green, 0);
    analogWrite(blue, 0);
  }
}
