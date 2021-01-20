#define pinRed 2
#define pinGre 4
#define pinSWL 7
#define pinSWR 8

bool cState_swl = false;
bool lState_swl = false;
bool cState_swr = false;
bool lState_swr = false;
bool valRed = false;
bool valGre = false;

void setup()
{
  pinMode(pinRed, OUTPUT);
  pinMode(pinGre, OUTPUT);
  pinMode(pinSWL, INPUT);
  pinMode(pinSWR, INPUT); 
}

void loop()
{
  cState_swl = digitalRead(pinSWL);
  cState_swr = digitalRead(pinSWR);
  delay(30);

  if(cState_swl && (cState_swl != lState_swl))
  {
    valRed = !valRed;
    digitalWrite(pinRed, valRed);
  }
  
  if(cState_swr && (cState_swr != lState_swr))
  {
    valGre = !valGre;
    digitalWrite(pinGre, valGre);
  }

  lState_swl = cState_swl;
  lState_swr = cState_swr;
}
