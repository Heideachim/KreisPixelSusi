# KreisPixelSusi
Ein Würmchen saust auf einem Ring von NeoPixeln (WS2812)

Ein farbiger Punkt läuft immer im Kreis herum, wobei er einen immer dunkler werdenden Lichtschweif hinter sich herzieht. Im Laufe der Zeit ändert dieses Würmchen langsam seine Farbe, sodass er den ganze Regenbogen durchmacht.

Dazu hängt eine kreisförmige Platine mit einigen RGB-LEDs an einem Arduino, der für jede einzelne LED die Farbe berechnet und diese Information dann über eine Leitung zu den LEDs schickt. Die LEDs hängen alle nacheinander an dieser Leitung. Jede LED schneidet aus dem Datenstrom, der vom Arduino kommt, die für ihne geltenden Farb-Werte heraus und leitet die restlichen Werte an die nächste LED weiter.

Das wird dazu benötigt:

- Ein Arduino, z. B. ein Arduino Nano. Bei Exp-Tech für 23€, bei Aliexpress mit einem nervigen CH340-USB-Chip für 2€.
- Ein Ring mit ein paar WS2812 LEDs. Die Firma Adafruit nennt sie 'NeoPixel'. Bei Exp-Tech für 7 €, bei Aliexpress für 2€.
- Lötzinn und Kabel, um die beiden miteinander zu verbinden.

Eine ausführlichere Beschreibung gibt es hier: https://www.instructables.com/id/Colorful-Worms-for-Susi/
