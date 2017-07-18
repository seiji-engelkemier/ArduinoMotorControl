class Flasher
{
  // Class Member Variables
  // These are intialized at startup
  int ledPin;         // the number of the LED pin
  long OnTime;        // milliseconds of on-time
  long OffTime;       // milliseconds of off-time

  // These maintain the current state
  int ledState;                   // ledState used to set the LED
  unsigned long previousMillis;   // will store last time LED was updated

  // Constructor - creates a Flasher
  // and initialized the member variables and state
  public:
  Flasher(int pin, long on, long off)
  {
    ledPin = pin;
    pinMode(ledPin, OUTPUT);

    OnTime = on;
    OffTime = off;

    ledState = LOW;
    previousMillis = 0;
  }

  void Update()
  {
    // check to see if it's time to change the state of the LED
    unsigned long currentMillis = millis();

    if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
    {
      ledState = LOW; // Turn it off
      previousMillis = currentMillis; // Remember the time
      digitalWrite(ledPin, ledState); // Update the LED
    }
    else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
    {
      ledState = HIGH; // Turn it on
      previousMillis = currentMillis; // Remember the time
      digitalWrite(ledPin, ledState); // Update the LED
    }
  }
};

Flasher blueLED(6, 100, 400);
Flasher redLED(7, 200, 300);
Flasher yellowLED(12, 400, 800);

void setup() 
{ 
}

void loop() 
{
  blueLED.Update();
  redLED.Update();
  yellowLED.Update();
}
