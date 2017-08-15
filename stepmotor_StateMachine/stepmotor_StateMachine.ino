class Motor
{
  // Class Member Variables
  int step_signal_pin;
  int dir_signal_pin;
  int CW_buttonpin;
  int CCW_buttonpin;
  int MotorInterval = 5000; // microseconds between HIGH/LOW CLK signal for motor
  int motor_pins[2];
  int button_pins[2];

  // These maintain the current state
  unsigned long previousMicros;   // will store motor cycling
  bool buttonState;               // stores whether button is pressed
  bool dir_signal;                // keeps track of DIR signal
  bool step_signal;

  // Constructor
  public:
    Motor(int step_pin, int dir_pin, int cw_pin, int ccw_pin)
    {
      step_signal_pin = step_pin;
      dir_signal_pin = dir_pin;
      CW_buttonpin = cw_pin;
      CCW_buttonpin = ccw_pin;

      motor_pins[0] = step_signal_pin;
      motor_pins[1] = dir_signal_pin;

      button_pins[0] = CW_buttonpin;
      button_pins[1] = CCW_buttonpin;

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
        // if both CW and CCW buttons are pressed, have motor do nothing
        // this condition may be redundant. Being explicit for first run throughs.
        MotorOff();
      }      
      else if (digitalRead(CW_buttonpin) == HIGH)
      {
        // run motor CW
        dir_signal = HIGH;
        digitalWrite(motor_pins[1],dir_signal);
        MotorRun();
      }
      else if (digitalRead(CCW_buttonpin) == HIGH)
      {
        // run motor CCW
        dir_signal = LOW;
        digitalWrite(motor_pins[1],dir_signal);
        MotorRun();
      }
      else
      {
        // neither button is pressed
        MotorOff();
      }
    }

     private:
    void MotorRun()
    {
      // check to see if it's time to change signal of motor
      unsigned long currentMicros = micros();

      if((step_signal == HIGH) && (currentMicros - previousMicros >= MotorInterval))
      {
        previousMicros = currentMicros;
        step_signal = LOW;
        digitalWrite(motor_pins[0],step_signal);
      }
      if((step_signal == LOW) && (currentMicros - previousMicros >= MotorInterval))
      {
        previousMicros = currentMicros;
        step_signal = HIGH;
        digitalWrite(motor_pins[0],step_signal);
      }
    }
    void MotorOff()
    {
      // motor does not move
      step_signal = LOW;
//      dir_signal = LOW;
      digitalWrite(motor_pins[0],step_signal);
//      digitalWrite(motor_pins[1],dir_signal);
    }
};


Motor Nema23(2,3,4,5);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  Nema23.Update();
}
