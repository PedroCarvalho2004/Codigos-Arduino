#include <Adafruit_NeoPixel.h>

#define PIN 6       // Pino digital onde está conectado o DATA IN
#define NUM_LEDS 12 // Total de LEDs no anel

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();    // Inicializa os LEDs
  strip.show();     // Apaga todos os LEDs no início
}

void loop() {
  // Define cores para os LEDs individualmente
  for(int i= 0; i < 4; i+=2)  {
    strip.setPixelColor(i, strip.Color(255,0,0));
  }
  for(int i= 4; i < 8; i+=2)  {
    strip.setPixelColor(i,strip.Color(0,255,0));
  }
    for(int i= 8; i < 12; i+=2)  {
    strip.setPixelColor(i,strip.Color(0,0,230));
  }
  
  for(int i= 1; i < 5; i+=2)  {
    strip.setPixelColor(i, strip.Color(0,0,230));
  }
  for(int i= 5; i < 9; i+=2)  {
    strip.setPixelColor(i,strip.Color(255,0,0));
  }
    for(int i= 9; i < 13; i+=2)  {
    strip.setPixelColor(i,strip.Color(0,255,0));
  }


  strip.show(); // Atualiza todos os LEDs de uma vez


}