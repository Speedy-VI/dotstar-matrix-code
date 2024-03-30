#include <SPI.h>
#include <Adafruit_DotStar.h>
#define NUMPIXELS 72
#define DATA_PIN 11
#define CLOCKPIN 13
#define BRIGHTNESS 10
#define Volts 5
#define Max_Amps 250

Adafruit_DotStar strip(NUMPIXELS, DATA_PIN, CLOCKPIN, DOTSTAR_BRG);
const int delayTime = 200;

void setup() {
strip.setBrightness(BRIGHTNESS);
strip.begin(); // Initialize pins for output
strip.show();  // Turn all LEDs off ASAP
}

void loop() {

    // Define the colors
    uint32_t blueColor = strip.Color(0, 0, 255);
    uint32_t redColor = strip.Color(0, 255, 0);
    uint32_t offColor = strip.Color(0, 0, 0);

    // Randomly select a subset of LEDs to light up
    for (int i = 0; i < NUMPIXELS; i++) {
        // Randomly select whether to light up the LED
        bool isLit = random(2) == 0; // Increase the divisor for more sparse lighting
         Serial.print("isLit: ");
        Serial.println(isLit); // Print the value of isLit to Serial monitor
        uint32_t color = isLit ? (random(2) ? redColor : blueColor) : offColor; // Randomly select color between red and blue
        strip.setPixelColor(i, color);
    }

    strip.show(); // Show the updated strip
    delay(delayTime); // Delay before next iteration
}
