int debugmode=1;
int delayms=50;

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
bool s_en[3];
bool s_dir[3];



void setup()
{
Serial.begin(115200);
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

}

pinMode(13, OUTPUT);

for (int i=0;i<3;i++)
{
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


digitalWrite(13, LOW);

}

void loop() {

for (int i=0;i<3;i++)
{
  if (s_en[i]==1)
  {
    if (s_dir[i]==1)
    {
      cwp[i]=HIGH;
      cwm[i]=LOW;
      clkp[i]=HIGH;
      clkm[i]=LOW;
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




digitalWrite(13, HIGH);
delayMicroseconds(delayms);

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

//digitalWrite(22,LOW); 

digitalWrite(13, LOW);

//delay(1000);
delayMicroseconds(delayms);


//Communication part
String rec=readserial();

if (rec!="")
{
  for (int i=0;i<3;i++)
  {
    s_en[i]=(getValue(rec, ':', i)).toInt();
  }
  for (int i=3;i<6;i++)
  {
    s_dir[i]=(getValue(rec, ':', i)).toInt();
  }
  delayms=(getValue(rec, ':', 6)).toInt();
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
