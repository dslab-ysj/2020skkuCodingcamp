#define pinRed 3
#define pinGre 5
#define pinSWL 7
#define pinSWR 8
#define MAX_PWM 255

bool cState_swl = false;
bool lState_swl = false;
bool cState_swr = false;
bool lState_swr = false;
int valDuty = 0;
int valStep = 20;

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
    valDuty = valDuty + valStep;
    if(valDuty > MAX_PWM) valDuty = MAX_PWM;
    analogWrite(pinRed, valDuty);
    analogWrite(pinGre, valDuty);
  }
  
  if(cState_swr && (cState_swr != lState_swr))
  {
    valDuty = valDuty - valStep;
    if(valDuty < 0) valDuty = 0;    
    analogWrite(pinRed, valDuty);
    analogWrite(pinGre, valDuty);  
  }

  lState_swl = cState_swl;
  lState_swr = cState_swr;
}
