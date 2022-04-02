/*
   IR read codes
   by Hanie kiani
   https://electropeak.com/learn/
*/
#include <IRremote.h>  //including infrared remote header file     
#define IrPin 4
#define controlPin 3
#define targetCode "x"

IRrecv irrecv(IrPin);
decode_results results;

bool lightState = false;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); //初始化
}

void loop()
{
  if (irrecv.decode(&results))// Returns 0 if no data ready, 1 if data ready.
  {
    int IRvalue = results.value;// Results of decoding are stored in result.value
    
    if(IRvalue == targetCode){
      Serial.println("Code match");
      lightState = ~lightState;
      digitalWrite(controlPin, lightState);
    }else{
      Serial.println("Code not match: " + IRvalue);
    }

    irrecv.resume(); // Restart the ISR state machine and Receive the next value
  }
}
