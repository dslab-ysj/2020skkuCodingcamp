/*  -------------------------
 * |  ADC1 |  ADC0 |  PWM1 |
 * | A3,A2 | A1,A0 | D6,D9 |
 * -------------------------
 * |*GPIO0 |*GPIO1 |  PWM0 |
 * | D2,D4 | D7,D8 | D3,D5 |
 * -------------------------
 * |  UART |  SPI  |  I2C  |
 * ------------------------- */

// Switch : GPIO 1
#define PIN_SWL 7
#define PIN_SWR 8

void setup()
{
  Serial.begin(9600); // 스위치 값 모니터링을 위한 부분 
  pinMode(PIN_SWL, INPUT);
  pinMode(PIN_SWR, INPUT);
}

void loop()
{
  bool valSWL = digitalRead(PIN_SWL); // read signal from left switch
  bool valSWR = digitalRead(PIN_SWR); // read signal from right switch

  Serial.print("Left Switch : ");
  Serial.print(valSWL);
  Serial.print(", Right Switch : ");
  Serial.println(valSWR);

  delay(200);
}
