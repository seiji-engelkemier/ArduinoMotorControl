class Motor
{
  // Class Member Variables
  int CLKP_pin;   // pin number for CLKP signal
  int CLKM_pin;
  int CWP_pin;
  int CWM_pin;
  int ENP_pin;
  int ENM_pin;
  int CW_buttonpin;
  int CCW_buttonpin;
  int MotorInterval = 100; // milliseconds between HIGH/LOW CLK signal for motor
  int motor_pins[6];
  int button_pins[2];

  // These maintain the current state
  unsigned long previousMillis;   // will store motor cycling
  bool buttonState;               // stores whether button is pressed
  bool cwp;                       // keeps track of DIR signal
  bool cwm;
  bool clkp;                      // stores CLK signal
  bool clkm;
  bool enp;                       // stores EN signal
  bool enm;
  


  // Constructor - creates a Motor object
  public:
    Motor(int clkp_pin, int clkm_pin, int cwp_pin, int cwm_pin, int enp_pin, int enm_pin, int CWbutton, int CCWbutton)
    {
      CLKP_pin = clkp_pin;
      CLKM_pin = clkm_pin;
      CWP_pin = cwp_pin;
      CWM_pin = cwm_pin;
      ENP_pin = enp_pin;
      ENM_pin = enm_pin;
      CW_buttonpin = CWbutton;
      CCW_buttonpin = CCWbutton;

      motor_pins[0] = CLKP_pin;
      motor_pins[1] = CLKM_pin;
      motor_pins[2] = CWP_pin;
      motor_pins[3] = CWM_pin;
      motor_pins[4] = ENP_pin;
      motor_pins[5] = ENM_pin;

      button_pins[0] = CW_buttonpin;
      button_pins[1] = CCW_buttonpin;
      
//      motor_pins = {CLKP_pin,CLKM_pin,CWP_pin,CWM_pin,ENP_pin,ENM_pin};   // issue with creating variable here - variable couldn't be accessed by functions in the class
//      button_pins = {CW_buttonpin, CCW_buttonpin};                        // same issue as line above.
      for (int i=0;i<(sizeof(motor_pins)/sizeof(int));i++)
      {
        pinMode(motor_pins[i], OUTPUT);
        digitalWrite(motor_pins[i], LOW);
      }
      for (int i=0;i<(sizeof(button_pins)/sizeof(int));i++)
      {
        pinMode(button_pins[i], INPUT);
      }
      
    }
  
    void Update()
    {
      /* note to self: there may be an issue with using same timing
       *  variable/function for CW and CCW button press. Also may be such small issue
       *  that it can be neglected.
       */
      if ((digitalRead(CCW_buttonpin) == HIGH) && (digitalRead(CW_buttonpin) == HIGH))
      {
//        // if both CW and CCW buttons are pressed, have motor do nothing
//        // this condition may be redundant. Being explicit for first run throughs.
//        MotorOff();
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
      }
      else if (digitalRead(CW_buttonpin) == HIGH)
      {
//        // run motor CW
//        cwp = LOW;
//        cwm = HIGH;
//        digitalWrite(motor_pins[2],cwp);
//        digitalWrite(motor_pins[3],cwm);
//        MotorRun();
          digitalWrite(6,HIGH);
      }
      else if (digitalRead(CCW_buttonpin) == HIGH)
      {
//        // run motor CCW
//        cwp = HIGH;
//        cwm = LOW;
//        digitalWrite(motor_pins[2],cwp);
//        digitalWrite(motor_pins[3],cwm);
//        MotorRun();
          digitalWrite(7,HIGH);
      }

      else
      {
        // neither button is pressed
//        MotorOff();
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
      }
    }

  private:
    void MotorRun()
    {
      // check to see if it's time to change signal of motor
      unsigned long currentMillis = millis();

      if((clkp == HIGH) && (currentMillis - previousMillis >= MotorInterval))
      {
        previousMillis = currentMillis;
        clkp = LOW;
        digitalWrite(motor_pins[0],clkp);
      }
      if((clkp == LOW) && (currentMillis - previousMillis >= MotorInterval))
      {
        previousMillis = currentMillis;
        clkp = HIGH;
        digitalWrite(motor_pins[0],clkp);
      }
    }
    void MotorOff()
    {
      // motor does not move
      clkp = LOW;
      clkm = LOW;
      digitalWrite(motor_pins[0],clkp);
      digitalWrite(motor_pins[1],clkm);
    }
};


/* ----------------------------------- */
/*            Main Code                */
/* ----------------------------------- */

/* copied and pasted these from threemotors.ino
 *  
int p_clkp[]={22,32,42};
int p_clkm[]={23,33,43};
int p_cwp[]={24,34,44};
int p_cwm[]={25,35,45};
int p_enp[]={26,36,46};
int p_enm[]={27,37,47};
int b_cw[]={28,38,48};
int b_ccw[]={29,39,49};
*/

/* Motor(clkp_pin,clkm_pin,cwp_pin,cwm_pin,enp_pin,enm_pin,CWbutton,CCWbutton) */
Motor motor1(6, 2, 6, 7, 52, 53, 22, 23);
//Motor motor2(32, 33, 34, 35, 36, 37, 38, 39);
//Motor motor3(42, 43, 44, 45, 46, 47, 48, 49);

void setup()
{
  
}

void loop()
{
  motor1.Update();
//  motor2.Update();
//  motor3.Update();
}

