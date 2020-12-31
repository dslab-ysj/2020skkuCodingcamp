/*  -------------------------
 * | *ADC1 | *ADC0 |  PWM1 |
 * | A3,A2 | A1,A0 | D6,D9 |
 * -------------------------
 * | GPIO0 | GPIO1 |  PWM0 |
 * | D2,D4 | D7,D8 | D3,D5 |
 * -------------------------
 * |  UART |  SPI  |  I2C  |
 * ------------------------- */
//Light Sensor : ADC 0
#define PIN_LIGHT A0

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int valLIGHT = analogRead(PIN_LIGHT);
  Serial.print("ADC Value of Light Sensor : ");
  Serial.println(valLIGHT);
  delay(500);
}
