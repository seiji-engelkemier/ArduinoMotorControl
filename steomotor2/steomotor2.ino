/*     Simple Stepper Motor Control Exaple Code
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
// defines pins numbers
const int stepPin = 3; 
const int dirPin = 4; 
const int greenBut = 5;
const int redBut=6;
int Stepping = false;
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
  
  if (digitalRead(greenBut) == LOW && Stepping == false)
  {
    digitalWrite(dirPin, HIGH);
    Stepping = true;
  }
  
  if (digitalRead(greenBut) == LOW && Stepping == true)
  {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(pauseDur); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(pauseDur);
    numStep=numStep+1;
  }
  
  if (digitalRead(redBut) == LOW && Stepping == false)
  {
    digitalWrite(dirPin, LOW);
    Stepping = true;
  }
  
  if (digitalRead(redBut) == LOW && Stepping == true)
  {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(pauseDur); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(pauseDur);
    numStep=numStep-1;
  }

  if (digitalRead(redBut) == HIGH && digitalRead(redBut) == HIGH)
  {
    Stepping=false;
  }
  
  wirelength=numStep*coeff;
  
  i=i+1;
  if (i==100)
  {
    Serial.println(String(numStep)+"  "+String(wirelength));
    i=0;
  }
 
}
