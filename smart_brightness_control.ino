#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED size
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// OLED I2C address
#define OLED_ADDR 0x3C

// OLED object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pin definitions
#define LED_PIN 5          // LED pin
#define POT_PIN 4          // Potentiometer (ADC)

// PWM settings
#define PWM_CHANNEL 0
#define PWM_FREQ 5000
#define PWM_RESOLUTION 8   // 0-255

void setup() {
  Serial.begin(115200);

  // LED PWM setup
  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(LED_PIN, PWM_CHANNEL);

  // I2C pins (ESP32-C3)
  Wire.begin(3, 2); // SDA = GPIO3, SCL = GPIO2

  // OLED init
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("OLED not found");
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10, 20);
  display.println("Smart Brightness");
  display.println("Control System");
  display.display();
  delay(2000);
}

void loop() {
  int potValue = analogRead(POT_PIN);      // 0–4095
  int brightness = map(potValue, 0, 4095, 0, 255);

  // Set LED brightness
  ledcWrite(PWM_CHANNEL, brightness);

  // Display on OLED
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 10);
  display.println("Brightness Level");

  display.setTextSize(2);
  display.setCursor(20, 30);
  display.print(map(brightness, 0, 255, 0, 100));
  display.print(" %");

  display.display();

  delay(200);
}
