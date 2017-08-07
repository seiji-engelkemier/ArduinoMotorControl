/*     Simple Stepper Motor Control Exaple Code
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
// defines pins numbers
const int stepPin = 2; 
const int dirPin = 3; 
const int greenBut = 5;
const int redBut=4;
int pauseDur = 10000;
float wirelength=0;
int numStep=0;
float coeff=1.0;
int i=0;

 
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  // Set the pins for buttons to Inputs
  pinMode(greenBut, INPUT);
  pinMode(redBut, INPUT);
  // Set the data rate
  Serial.begin(9600);
  
}
void loop() {
  
  if (digitalRead(greenBut) == LOW)
  {
    digitalWrite(dirPin, HIGH); // CW direction
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(pauseDur); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(pauseDur);
    numStep=numStep+1;
  }
  
  if (digitalRead(redBut) == LOW)
  {
    digitalWrite(dirPin, LOW); // CCW direction
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(pauseDur); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(pauseDur);
    numStep=numStep-1;
  }


  
//  wirelength=numStep*coeff;
  
  i=i+1;
  if (i==100)
  {
//    Serial.println(String(numStep)+"  "+String(wirelength));
    Serial.println(String(numStep));
    i=0;
  }

  
}
