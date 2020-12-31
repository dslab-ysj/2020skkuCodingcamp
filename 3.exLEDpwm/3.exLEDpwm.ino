/*  -------------------------
 * |  ADC1 |  ADC0 | *PWM1 |
 * | A3,A2 | A1,A0 | D6,D9 |
 * -------------------------
 * | GPIO0 | GPIO1 | *PWM0 |
 * | D2,D4 | D7,D8 | D3,D5 |
 * -------------------------
 * |  UART |  SPI  |  I2C  |
 * ------------------------- */
// Maximum value of PWM
#define MAX_PWM 255

// LED : PWM 0 
#define PIN_RED 3
#define PIN_GRE 5

void setup(){
  //Don't need to set pinMode() at pwm
}

void loop()
{
  int i=0;
  
  for(i = 0; i <= MAX_PWM; i++)
  { 
    analogWrite(PIN_RED,i);
    analogWrite(PIN_GRE,i);
    delay(10);   // 255번 * 10ms -> 약 2.5s
  }
  for(i = MAX_PWM; i >= 0; i--)
  {
    analogWrite(PIN_RED,i);
    analogWrite(PIN_GRE,i);
    delay(10);   
  }
}
