int workingLED = 12;
int blueLED = 6;
int redLED = 7;

int buttonA = 22;
int buttonB = 23;

bool buttonPushed = 0;

int count = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(workingLED, OUTPUT);
  
  pinMode(buttonA, INPUT);
  pinMode(buttonB, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  ++count;
  
   // Using pushbutton as momentary switch
  while (digitalRead(buttonA)==HIGH)
  {
    digitalWrite(blueLED,HIGH);
    digitalWrite(workingLED,HIGH);
  }
  digitalWrite(blueLED,LOW);
  digitalWrite(workingLED,LOW); 

  // On/Off action with pushbutton
 if (digitalRead(buttonB) and (buttonPushed == 0))
 {
  digitalWrite(redLED,HIGH);
  buttonPushed = 1;
//  delay(500);
 }
 else if (digitalRead(buttonB) and (buttonPushed == 1))
 {
  digitalWrite(redLED,LOW);
  buttonPushed = 0;
 }

 
}
