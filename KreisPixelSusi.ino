// farben-demo für susi
// benötigt bibliothek: "Adafruit NeoPixel by Adafruit", getestet mit version 1.1.7
// jan 2019
// basiert auf: NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            13

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      16

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// physiologisch korrekte Helligkeits-Tabelle
const int LOGMAX = 35;  // anzahl einträge in die helligkeits-tabelle
int log35[]  = {0, 0, 1, 1, 2, 2, 3, 3, 4, 5, 6, 8, 9, 11, 13, 15, 18, 21, 24, 28, 33, 38, 44, 51, 60, 69, 80, 93, 107, 124, 143, 165, 191, 221, 255};
// index:       0  1  2  3  4  5  6  7  8  9  10 11 12 13  14  15  16  17  18  19  20  21  22  23  24  25  26  27   28   29   30   31   32   33   34

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
}

// ein die farbe wechselndes würmchen im kreis sausen lassen:
void loop() {
  const int LAENGE = 6;               // wie viele LEDs soll das würmchen lang sein.
  for (float farbe = 0.0; farbe < 2*PI; farbe += 0.3) {   // farbe durchwechseln
    for (int start = 0; start < NUMPIXELS; start++) {     // an welcher LED startet das würmchen. bewirkt, dass das würmchen im kreis saust
      for (int lednr = 0; lednr < LAENGE; lednr++){       // das würmchen besteht aus LAENGE LEDs
        // farbe der aktuellen LED: über die phasenverschiebung innerhalb der sin-funktion werden rot, grün und blau gemischt:
        unsigned int R = (float)lednr * (sin(farbe + 0.0/3.0*2.0*PI)+1.0)/2.0 * LOGMAX / LAENGE;
        unsigned int G = (float)lednr * (sin(farbe + 1.0/3.0*2.0*PI)+1.0)/2.0 * LOGMAX / LAENGE;
        unsigned int B = (float)lednr * (sin(farbe + 2.0/3.0*2.0*PI)+1.0)/2.0 * LOGMAX / LAENGE;
 
        int lednr_ring = (start + lednr) % NUMPIXELS; // der ring ist ringförmig... positionen größer der letzten LED werden wieder auf den anfang umgebrochen (% = modulo)
        
        pixels.setPixelColor(lednr_ring, pixels.Color(log35[R], log35[G], log35[B])); // die LED mit der physiologisch richtigen farbe setzen
      }
      pixels.show(); // die in der obigen schleife definierten LED-farben auf einen schlag an den ring rausschicken
      delay(60);    // kurz warten
    }
  }
}
