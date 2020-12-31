/*  -------------------------
 * |  ADC1 |  ADC0 |  PWM1 |
 * | A3,A2 | A1,A0 | D6,D9 |
 * -------------------------
 * |*GPIO0 |*GPIO1 |  PWM0 |
 * | D2,D4 | D7,D8 | D3,D5 |
 * -------------------------
 * |  UART |  SPI  |  I2C  |
 * ------------------------- */

// LED : GPIO 0
#define PIN_RED 2   // 7 at GPIO 1   
#define PIN_GRE 4   // 8 at GPIO 1
 
void setup()
{
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GRE, OUTPUT);
}

void loop()
{
  digitalWrite(PIN_RED, HIGH);
  digitalWrite(PIN_GRE, LOW);
  delay(1000);
  
  digitalWrite(PIN_RED, LOW);
  digitalWrite(PIN_GRE, HIGH);  
  delay(1000);
}
