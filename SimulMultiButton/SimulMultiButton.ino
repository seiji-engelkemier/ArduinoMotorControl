class Motor
{
  // Class Member Variables
  int CLKPpin;
  int CLKMpin;
  int CWPpin;
  int CWMpin;
  int ENPpin;
  int ENMpin;

  // These maintain the current state
  bool buttonState;   // stores whether button is pressed

  // Constructor - creates a Motor object
  public:
  Motor(int clkp; int clkm, int cwp; int cwm; int enp; int enm)
  {
    CLKPpin = clkp;
    CLKMpin = clkm;
    CWPpin = cwp;
    CWMpin = cwm;
    ENPpin = enp;
    ENMpin = enm;
  }
};

