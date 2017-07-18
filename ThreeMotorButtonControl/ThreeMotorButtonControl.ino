int delayms=100;

// 6 pin numbers for each motor
int p_clkp[]={22,32,42};
int p_clkm[]={23,33,43};
int p_cwp[]={24,34,44};
int p_cwm[]={25,35,45};
int p_enp[]={26,36,46};
int p_enm[]={27,37,47};

// create array of booleans for on/off signals
bool cwp[3];
bool cwm[3];
bool clkp[3];
bool clkm[3];
bool enp[3];
bool enm[3];
bool s_en[3];
bool s_dir[3];

// Button control 
const int greenBut=48;
const int redBut=49;



void setup()
{
  // Set data transfer rate
  Serial.begin(9600);

  // Set the pins for buttons to Inputs
  pinMode(greenBut, INPUT);
  pinMode(redBut, INPUT);

  // Set each motor pin to OUTPUT mode
  for (int i=0;i<3;i++)
  {
    pinMode(p_cwp[i], OUTPUT);
    pinMode(p_cwm[i], OUTPUT);
    pinMode(p_clkp[i], OUTPUT);
    pinMode(p_clkm[i], OUTPUT);
    pinMode(p_enp[i], OUTPUT);
    pinMode(p_enm[i], OUTPUT);

    s_en[i]=1;
    s_dir[i]=1;

    cwp[i]=LOW;
    cwm[i]=LOW;
    clkp[i]=LOW;
    clkm[i]=LOW;
    enp[i]=LOW;
    enm[i]=LOW;
   
    digitalWrite(p_cwp[i],cwp[i]);
    digitalWrite(p_cwm[i],cwm[i]);
    digitalWrite(p_clkp[i],clkp[i]);
    digitalWrite(p_clkm[i],clkm[i]);
    digitalWrite(p_enp[i],enp[i]);
    digitalWrite(p_enm[i],enm[i]);
  
  }

  
  Serial.println("Press and hold - green for CCW, red for CW.");
  
}


void loop() 
{
  if (digitalRead(greenBut) == HIGH) // temp change condition from LOW to HIGH
  {
    // Set all motors to CCW
    for (int i=0;i<3;i++)
    {
      cwp[i]=HIGH;
      cwm[i]=LOW;
      WriteSignal();
    }
    
    // The while loop allows the motor to spin normally by 
    // preventing the pause caused by the Arduino program looping
    while (digitalRead(greenBut) == HIGH)
    {
      MotorOnSignal();
      MotorOffSignal();
    }
  }

  if (digitalRead(redBut) == HIGH) // temp change condition from LOW to HIGH
  {
    // Set all motors to CW
    for (int i=0;i<3;i++)
    {
      cwp[i]=LOW;
      cwm[i]=HIGH;
      WriteSignal();
    }
    while (digitalRead(redBut) == HIGH)
    {
      MotorOnSignal();
      MotorOffSignal();
    }
  }
  
  
  
 

  
} // end of main loop

void WriteSignal()
{
  for (int i=0;i<3;i++)
  {
    digitalWrite(p_clkp[i],clkp[i]);
    digitalWrite(p_clkm[i],clkm[i]); 
    digitalWrite(p_cwp[i],cwp[i]);
    digitalWrite(p_cwm[i],cwm[i]);
  }
}

void MotorOnSignal()
{
  for (int i=0;i<3;i++)
  {
    clkp[i]=HIGH;
    clkm[i]=LOW;
    digitalWrite(p_clkp[i],clkp[i]);
    digitalWrite(p_clkm[i],clkm[i]); 
  }      
  delayMicroseconds(delayms);
}

void MotorOffSignal()
{
  for (int i=0;i<3;i++)
  {
    clkp[i]=LOW;
    clkm[i]=LOW;
    digitalWrite(p_clkp[i],clkp[i]);
    digitalWrite(p_clkm[i],clkm[i]); 
  }      
  delayMicroseconds(delayms);
}


