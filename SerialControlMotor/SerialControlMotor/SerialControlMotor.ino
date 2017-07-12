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



void setup()
{
  // Set data transfer rate
  Serial.begin(115200);

  // Set each pin to OUTPUT mode
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
    // dir = 1 is CCW. 

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

  
//  Serial.println("Enter a to rotate motor CW, press z for CCW, q to stop");
  
}


void loop() 
{
//  if (Serial.available())
//  {
//    char ch = Serial.read();
//    if (ch == "z")
//    {
//      cwp[1]=HIGH;
//      cwm[1]=LOW;
//      clkp[1]=HIGH;
//      clkm[1]=LOW;
//    }
//    if (ch == "a")
//    {
//      cwp[1]=LOW;
//      cwm[1]=HIGH;
//      clkp[1]=LOW;
//      clkm[1]=HIGH;
//    } 
//    if (ch == "q")
//    {
//      cwp[1]=LOW;
//      cwm[1]=HIGH;
//      clkp[1]=HIGH;
//      clkm[1]=HIGH;
//    }
//
//    int i = 1;
//    digitalWrite(p_clkp[i],clkp[i]);
//    digitalWrite(p_clkm[i],clkm[i]); 
//    digitalWrite(p_cwp[i],cwp[i]);
//    digitalWrite(p_cwm[i],cwm[i]);
//
//    delay(1000);
//  }

//  DirValue = Serial.read();
//  for (int i=0;i<3;i++)
//  {
//    s_dir[i]=DirValue;
//  }
  
  for (int i=0;i<3;i++)
  {
    if (s_en[i]==1)
    {
      if (s_dir[i]==1)
      {
        // Spin CW
        cwp[i]=LOW;
        cwm[i]=HIGH;
        clkp[i]=HIGH;
        clkm[i]=LOW;

        if (i == 2) 
        {
          // Spin CCW
          cwp[i]=HIGH;
          cwm[i]=LOW;
          clkp[i]=HIGH;
          clkm[i]=LOW;
        }
      }
      if (s_dir[i]==0)
      {
        cwp[i]=LOW;
        cwm[i]=HIGH;
        clkp[i]=LOW;
        clkm[i]=HIGH;
      }  
    
    digitalWrite(p_clkp[i],clkp[i]);
    digitalWrite(p_clkm[i],clkm[i]); 
    digitalWrite(p_cwp[i],cwp[i]);
    digitalWrite(p_cwm[i],cwm[i]);
    
    } 
    
  }
  
  
  delayMicroseconds(delayms);

  // Need this portion to turn clock signal off or else motor doesn't spin.
  for (int i=0;i<3;i++)
  {
    if (s_en[i]==1)
    {
      if (s_dir[i]==1)
      {
        cwp[i]=HIGH;
        cwm[i]=LOW;
        clkp[i]=LOW;
        clkm[i]=LOW;
      }
      if (s_dir[i]==0)
      {
        cwp[i]=LOW;
        cwm[i]=HIGH;
        clkp[i]=LOW;
        clkm[i]=LOW;
      }  
    
    digitalWrite(p_clkp[i],clkp[i]);
    digitalWrite(p_clkm[i],clkm[i]); 
    digitalWrite(p_cwp[i],cwp[i]);
    digitalWrite(p_cwm[i],cwm[i]);
  
    
    }
  
    
  }
  
  delayMicroseconds(delayms);
  
} // end of main loop
