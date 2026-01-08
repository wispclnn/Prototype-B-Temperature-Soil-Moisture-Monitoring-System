
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHTPIN 4
#define DHTTYPE DHT11
#define HOTLED 16
#define COLDLED 17
#define TEMP_THRESHOLD 25

#define SOIL_PIN 34
#define DRY_THRESHOLD 2000

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(HOTLED, OUTPUT);
  pinMode(COLDLED, OUTPUT);

  digitalWrite(HOTLED, LOW);
  digitalWrite(COLDLED, LOW);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("LCD init failed"));
    for(;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  // Read temperature
  float temp = dht.readTemperature();
  if(isnan(temp)) {
    Serial.println("Check DHT11 Sense Pin!");
    return;
  }

  // Read soil moisture
  int soilValue = analogRead(SOIL_PIN);

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" °C");

  Serial.print("Soil Moisture: ");
  Serial.println(soilValue);

  // LED logic
  String tempStatus;
  if (temp > TEMP_THRESHOLD) {
    digitalWrite(HOTLED, HIGH);
    digitalWrite(COLDLED, LOW);
    tempStatus = "HOT → RED LED";
  } else {
    digitalWrite(HOTLED, LOW);
    digitalWrite(COLDLED, HIGH);
    tempStatus = "COOL → GREEN LED";
  }

  // Soil status
  String soilStatus;
  if (soilValue > DRY_THRESHOLD) {
    soilStatus = "Soil Dry!";
    // Future: trigger relay pump here
  } else {
    soilStatus = "Soil Moist";
  }

  // OLED output
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Temp: ");
  display.print(temp);
  display.println(" C");
  display.println(tempStatus);

  display.print("Soil: ");
  display.println(soilValue);
  display.println(soilStatus);
  display.display();

  delay(2000);
}