// Feel Free to copy.
// __author__ : Ronil Patil

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED Display
#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

#define I2Cdisplay_SDA 21
#define I2Cdisplay_SCL 22
TwoWire I2Cdisplay = TwoWire(1);

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &I2Cdisplay, -1);

// LDR (Light Dependent Resistor)
#define ldr  33
 
void setup()
{
  Serial.begin(115200); // starts the serial port at 9600
  
  I2Cdisplay.begin(I2Cdisplay_SDA, I2Cdisplay_SCL, 100000);

  // Initialize OLED Display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  display.setTextColor(WHITE);
}
 
void loop()
{
  displayLDR();
  delay(1000);
}

// SCREEN NUMBER 4: LUMINOSITY
void displayLDR() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(53, 17);
  int ldrReading = map(analogRead(ldr), 0, 4095, 100, 0);
  display.print(ldrReading);
  display.print(" %");
  display.display();
  //  int ldrReadingPer = map(ldrReading, 0, 100, 0, LED_COUNT-1);
}

//Connection's : 
                /*one end of LDR to ground, another end to GPIO 33 (D33) and one more thing add 10k resistor at same end and 3.3v*/
