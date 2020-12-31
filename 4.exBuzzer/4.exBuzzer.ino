/*  -------------------------
 * |  ADC1 |  ADC0 | *PWM1 |
 * | A3,A2 | A1,A0 | D6,D9 |
 * -------------------------
 * | GPIO0 | GPIO1 | *PWM0 |
 * | D2,D4 | D7,D8 | D3,D5 |
 * -------------------------
 * |  UART |  SPI  |  I2C  |
 * ------------------------- */
#include "buzzer.h"
 
// Buzzer : PWM 0 
#define PIN_BZ 3

//int ArraySize = sizeof(NationalAnthemM)/sizeof(int); // 애국가
//int ArraySize = sizeof(SchoolBellM)/sizeof(int); // 학교종
int ArraySize = sizeof(RabbitM)/sizeof(int); // 산토끼 

void setup()
{
  pinMode(PIN_BZ, OUTPUT);
}

void loop()
{
  for (int i=0 ; i<ArraySize ; i++)
  {
    //Play(NationalAnthemM[i], NationalAnthemR[i]); // 애국가 
    //Play(SchoolBellM[i], SchoolBellR[i]);  // 학교종
    Play(RabbitM[i], RabbitR[i]); // 산토끼
  }
  delay(5000);
}

void Play(int FREQ, float LEN)
{
  int DUTY = 30; // 듀티값[us]
  long loopCnt = 300000; // 1박에 적절한 길이, 조절시 1박의 길이 바뀜
  if(FREQ)
  {
    for(int i=0 ; i<loopCnt*LEN/FREQ ; i++)
    {
      digitalWrite(PIN_BZ,HIGH);
      delayMicroseconds(DUTY);
      digitalWrite(PIN_BZ,LOW);
      delayMicroseconds(FREQ-DUTY);//디지털 신호로 PWM생성 
    }
  }
  else // 쉼표를 위한 부분 
  {
    for(int i=0 ; i<loopCnt*LEN/200 ; i++)
    {
      digitalWrite(PIN_BZ,LOW);
      delayMicroseconds(200);
    }
  }
}
