int debugLED = 12;
int buttonPin = 22;

bool buttonPushed = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(debugLED, OUTPUT);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  
   // Using pushbutton as momentary switch
  while (digitalRead(buttonPin)==HIGH)
  {
    digitalWrite(debugLED,HIGH);
  }
 digitalWrite(debugLED,LOW);
 

  // On/Off action with pushbutton
// if (digitalRead(buttonPin) and (buttonPushed == 0))
// {
//  digitalWrite(debugLED,HIGH);
//  buttonPushed = 1;
////  delay(500);
// }
// else if (digitalRead(buttonPin) and (buttonPushed == 1))
// {
//  digitalWrite(debugLED,LOW);
//  buttonPushed = 0;
// }

 
}
