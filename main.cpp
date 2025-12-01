#define BLYNK_TEMPLATE_ID "TMPL2rzVvh0n2"
#define BLYNK_TEMPLATE_NAME "iot based water monitoring system"
#define BLYNK_AUTH_TOKEN "H5XQZAf5nw-vZsF_LwE9Cxkb7ZM6R713"

#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

char ssid[] = "XY";
char pass[] = "AmIro1234";

#define ONE_WIRE_BUS D4
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

LiquidCrystal_I2C lcd(0x27, 16, 2);

float neutralPH = 7.0;
float neutralVoltage = 2.50;
float slope = 0.18;

BlynkTimer timer;

const int AVG_COUNT = 10;
float avgBuffer[AVG_COUNT] = {0};
int bufIdx = 0;

float readProbeVoltage() {
  int raw = analogRead(A0);
  float voltage = (raw / 1023.0) * 5.0;
  return voltage;
}

float runningAverageVoltage(float newV) {
  avgBuffer[bufIdx] = newV;
  bufIdx = (bufIdx + 1) % AVG_COUNT;

  float sum = 0;
  for (int i = 0; i < AVG_COUNT; i++) sum += avgBuffer[i];

  return sum / AVG_COUNT;
}

float readPH() {
  float voltage = readProbeVoltage();
  float vAvg = runningAverageVoltage(voltage);
  float pH = neutralPH - ((vAvg - neutralVoltage) / slope);
  return pH;
}

void sendSensor() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);

  int turbRaw = analogRead(A0);
  float turbVolt = turbRaw * (5.0 / 1023.0);
  float turbidity = map(turbVolt * 100, 0, 300, 1000, 0);

  float pHValue = readPH();

  Blynk.virtualWrite(V0, tempC);
  Blynk.virtualWrite(V1, turbidity);
  Blynk.virtualWrite(V2, pHValue);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(tempC);
  lcd.print("C Turb:");
  lcd.print(turbidity);

  lcd.setCursor(0, 1);
  lcd.print("pH:");
  lcd.print(pHValue, 2);
}

void setup() {
  Serial.begin(115200);
  lcd.begin();
  lcd.backlight();
  sensors.begin();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(2000, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}
