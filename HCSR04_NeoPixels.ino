#include <Adafruit_NeoPixel.h>

#define trigPin 16
#define echoPin 17
#define PIN 13
//#define led2 10
#define NUMPIXELS 40 // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin (9600);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 // pinMode(led, OUTPUT);
 // pinMode(led2, OUTPUT);
}

void loop() {
    pixels.clear(); // Set all pixel colors to 'off'
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 20) {  // This is where the LED On/Off happens

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));

    pixels.show();   // Send the updated pixel colors to the hardware.

   // delay(30); // Pause before next pass through loop
  }
}
  else {
      for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(distance/3, distance/3, distance/3));

    pixels.show();   // Send the updated pixel colors to the hardware.

    //delay(30); // Pause before next pass through loop
  }
   // digitalWrite(led,LOW);
    //digitalWrite(led2,HIGH);
    pixels.clear(); // Set all pixel colors to 'off'
  }
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
    
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(200);
} 
