
// -*- mode: C++ -*-

#include "AccelStepper/AccelStepper.h"
// The X Stepper pins
#define STEPPER1_DIR_PIN 24
#define STEPPER1_STEP_PIN 22
// The Y stepper pins
#define STEPPER2_DIR_PIN 7
#define STEPPER2_STEP_PIN 6
// Define some steppers and the pins the will use


AccelStepper astep[3];

int p_clkp[]={22,32,42};
int p_clkm[]={23,33,43};
int p_cwp[]={24,34,44};
int p_cwm[]={25,35,45};
int p_enp[]={26,36,46};
int p_enm[]={27,37,47};


bool cwp[3];
bool cwm[3];
bool clkp[3];
bool clkm[3];
bool enp[3];
bool enm[3];





int cyc=0;
int stepen[]={1,1,1};
AccelStepper stepper1(AccelStepper::DRIVER, 22, 24);
AccelStepper stepper2(AccelStepper::DRIVER, 32, 34);
AccelStepper stepper3(AccelStepper::DRIVER, 42, 44);

void setup()
{  
    astep[0]=stepper1;
    astep[1]=stepper2;
    astep[2]=stepper3;
    
    Serial.begin(115200);
    //pinMode(23, OUTPUT);
    //pinMode(25, OUTPUT);
    //pinMode(26, OUTPUT);
    //pinMode(27, OUTPUT);
    //digitalWrite(23,LOW); 
    //digitalWrite(25,LOW);
    //digitalWrite(26,LOW);
    //digitalWrite(27,LOW);
    
    for (int i=0;i<3;i++)
    {
      //pinMode(p_cwp[i], OUTPUT);
      pinMode(p_cwm[i], OUTPUT);
      //pinMode(p_clkp[i], OUTPUT);
      pinMode(p_clkm[i], OUTPUT);
      pinMode(p_enp[i], OUTPUT);
      pinMode(p_enm[i], OUTPUT);
      
    }
    
    for (int i=0;i<3;i++)
    {
      //cwp[i]=HIGH;
      cwm[i]=LOW;
      //clkp[i]=LOW;
      clkm[i]=LOW;
      enp[i]=LOW;
      enm[i]=LOW;
     
      //digitalWrite(p_cwp[i],cwp[i]);
      digitalWrite(p_cwm[i],cwm[i]);
      //digitalWrite(p_clkp[i],clkp[i]);
      digitalWrite(p_clkm[i],clkm[i]);
      digitalWrite(p_enp[i],enp[i]);
      digitalWrite(p_enm[i],enm[i]);
    }

    
    for (int i=0; i<3; i++)    
    {
      astep[i].setMaxSpeed(5000.0);
      astep[i].setAcceleration(200000.0);
      astep[i].setSpeed(2000);
    }
       
    
    
}
void loop()
{
    // Change direction at the limits
    //if (stepper1.distanceToGo() == 0)
    //    stepper1.moveTo(-stepper1.currentPosition());
    //if (stepper2.distanceToGo() == 0)
    //    stepper2.moveTo(-stepper2.currentPosition());
    //Serial.print(String(stepper1.currentPosition())+"\n");
    
    //delay(2);
    //stepper2.run();
    //Serial.print(1);
   
    cyc=(cyc+1) % 1000;
    
    if (cyc==0)
      {
        String rec=readserial();
        if (rec!="")
        {
          int nmot = (getValue(rec, ':', 0)).toInt();
          int enable = (getValue(rec, ':', 1)).toInt();
          //Serial.print("\nEnable"+String(enable)+"f\n");
          int dir = (getValue(rec, ':', 2)).toInt();
          int sp = (getValue(rec, ':', 3)).toInt();
          int pos = (getValue(rec, ':', 4)).toInt();
          if ((nmot==0)||(nmot==1)||(nmot==2))
          {
            if (dir==0)
              {
                astep[nmot].moveTo(1000000);
                astep[nmot].setSpeed(sp);
              }
            else
              {
                astep[nmot].moveTo(-1000000);
                astep[nmot].setSpeed(-sp);
              }
  
            if (enable==0)
            {
              astep[nmot].stop();
              stepen[nmot]=0;
              Serial.write("Stopped");
              String ss=String(nmot)+" "+String(enable)+" "+String(dir)+" "+String(sp)+" "+String(pos);
              //Serial.print(ss);
            }
            else
            {
              stepen[nmot]=1;
              Serial.write("Started");
              String ss=String(nmot)+" "+String(enable)+" "+String(dir)+" "+String(sp)+" "+String(pos);
              //Serial.print(ss);
            }
          }
        }
      }

for (int i=0;i<3;i++)
{
  if (stepen[i]==1)
    {
      astep[i].runSpeed();
    }
}

}

String readserial()
{
   String instr;
   if (Serial.available() > 0) {
                instr=Serial.readString();
                Serial.print("I received: ");
                Serial.print(instr);
                Serial.print("\n");
                
        }
   return instr;
}


String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
