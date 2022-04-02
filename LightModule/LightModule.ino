#define lightPin A0
#define controlPin 3
#define threshold 400

#define delaymSec 1000

void setup(){
  pinMode(lightPin, INPUT);
  pinMode(controlPin, OUTPUT);

  Serial.begin(9600);
}

void loop(){
  //讀取光亮度
  uint16_t lightValue = analogRead(lightPin);

  Serial.println("Current analog value is " + lightValue);
  
  if(lightValue < threshold){
    Serial.println("Light On");
    digitalWrite(controlPin, HIGH);
  }
  else if(lightValue > threshold){
    Serial.println("Light Off");
    digitalWrite(controlPin, LOW);
  }

  //delay
  delay(delaymSec);
}
