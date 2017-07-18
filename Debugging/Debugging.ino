bool buttonState1 = 0;
bool buttonState2 = 0;
bool A;
bool B;
int i = 0;

int pinA = 52;
int pinB = 53;
int pin1 = 28;
int pin2 = 29;
int pin3 = 38;
int pin4 = 39;
int pin5 = 48;
int pin6 = 49;


int ledA = 13;
//int ledB = 23;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);
  pinMode(pin5, INPUT);
  pinMode(pin6, INPUT); 
  pinMode(3, INPUT);
  
//  pinMode(ledA, OUTPUT);
//  pinMode(ledB, OUTPUT);
//  digitalWrite(ledA, LOW);
//  digitalWrite(ledB, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  A = digitalRead(pinA);
  B = digitalRead(pinB);
  
  Serial.print("iteration: "); Serial.println(i++);

  /*
  if (buttonState1 != A)
  {
    Serial.print("left changed to: "); Serial.println(A);
    buttonState1 = A;
  }
  if (buttonState2 != digitalRead(49))
  {
    Serial.print("right changed to: "); Serial.println(B);
    buttonState2 = B;
  }
  */
  Serial.print("left A: "); Serial.print(A);
  Serial.print(" | right B: "); Serial.println(B);
  Serial.print("Left 1: "); Serial.print(digitalRead(pin1));
  Serial.print(" | right 1: "); Serial.println(digitalRead(pin2));
  Serial.print("left 2: "); Serial.print(digitalRead(pin3));
  Serial.print(" | right 2: "); Serial.println(digitalRead(pin4));
  Serial.print("left 3: "); Serial.print(digitalRead(pin5));
  Serial.print(" | right 3: "); Serial.println(digitalRead(pin6));

  Serial.print("dig-read: ");Serial.println(digitalRead(3));
//  digitalWrite(13,HIGH);
//  delay(250);
//  digitalWrite(13,LOW);
  delay(2000);
}
