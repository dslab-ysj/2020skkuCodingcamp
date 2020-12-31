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
#define PIN_TEMP A0

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  float valTemp = analogRead(PIN_TEMP);
  valTemp = valTemp * 500/1023-50;
  Serial.print("Temperature : ");
  Serial.print(valTemp,1);
  Serial.println(" C");
  delay(500);
}
