/* Ping))) Sensor

This sketch reads a PING))) ultrasonic rangefinder and returns the
distance to the closest object in range. To do this, it sends a pulse
to the sensor to initiate a reading, then listens for a pulse
to return. The length of the returning pulse is proportional to
the distance of the object from the sensor.

The circuit:
* +V connection of the PING))) attached to +5V
* GND connection of the PING))) attached to ground

[...]

created 3 Nov 2008
by David A. Mellis
modified 30 Aug 2011
by Tom Igoe

This example code is in the public domain.

*/

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif


// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            3

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      6
Adafruit_NeoPixel pixels =
Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define SAMPLES 50

// Pin number constants
const int triggerPin = 5;
const int echoPin = 6;
long history[SAMPLES];

void setup()
{
    Serial.begin(9600);
    pixels.begin();
}

void loop()
{
    long duration, cm;

// The echo pin is used to read the signal from the PING))): a HIGH
// pulse whose duration is the time (in microseconds) from the sending
// of the ping to the reception of its echo off of an object.

    pinMode(echoPin, INPUT);
// The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
// Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    pinMode(triggerPin, OUTPUT);
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(triggerPin, LOW);

    duration = pulseIn(echoPin, HIGH);

    //Serial.print(microsecondsToCentimeters(duration));
    //Serial.print(' ');

    if (microsecondsToCentimeters(duration) <= 500) {
        for (int i = SAMPLES - 2; i >= 0; i--) {
            history[i + 1] = history[i];
        }
        history[0] = duration;
    }

    long total = 0;
    for (int i = 0; i < SAMPLES; i++) {
        total += history[i];
    }

    int corrected = total / SAMPLES;

    cm = microsecondsToCentimeters(corrected);

    unsigned char brightness = corrected / 256;
    //unsigned char brightness = 255 - ( 255 * cm/400);

    for (int i = 0; i < NUMPIXELS; i++) {

// pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(brightness, 0, 0));   // Moderately bright green color.


    }
    pixels.show();              // This sends the updated pixel color to the hardware.
    Serial.print(cm);
    Serial.print(' ');
    Serial.print(brightness);
    Serial.println();

    delay(10);
}

/*
long microsecondsToInches(long microseconds)
{
// According to Parallax's datasheet for the PING))), there are
// 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
// second). This gives the distance travelled by the ping, outbound
// and return, so we divide by 2 to get the distance of the obstacle.
// See:[...]
}

long microsecondsToFeet(long microseconds)
{
// According to Parallax's datasheet for the PING))), there are
// 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
// second). This gives the distance travelled by the ping, outbound
// and return, so we multiply by 12 to convert to feet and then by 2 to get the distance of the obstacle.
// See: [...]
}
*/

long microsecondsToCentimeters(long microseconds)
{
// The speed of sound is 340 m/s or 29 microseconds per centimeter.
// The ping travels out and back, so to find the distance of the
// object we take half of the distance travelled.
    return microseconds / 29 / 2;
}
