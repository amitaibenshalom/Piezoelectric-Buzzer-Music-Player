#include "piezo_basic.h"
#define PIN_TONE_P 8 // one side of the piezo buzzer
#define PIN_TONE_N 12 // other side of the piezo buzzer

void play_note(uint16_t half_cycle_time, uint16_t tone_time){
  uint16_t Current_Time = millis() ;
  while ((millis()- Current_Time)<= tone_time) {
    digitalWrite(PIN_TONE_P, HIGH) ; 
    digitalWrite(PIN_TONE_N, LOW) ; 
    delayMicroseconds(half_cycle_time);
    digitalWrite(PIN_TONE_P, LOW) ; //invert polarity for piezo DC balance
    digitalWrite(PIN_TONE_N, HIGH) ; //invert polarity for piezo DC balance
    delayMicroseconds(half_cycle_time);
  }
  digitalWrite(PIN_TONE_N, LOW) ; 
 }

void play_song(float song[]) {
   int i = 0;
   while(song[i] != END) {
      if (song[i] == P)
        delay(p_time);
      else {
        play_note(calculate_half_cycle_time(song[i]),note_time);
      }
      delay(p_between_notes_time);
      i++;
   }
}


void setup() {
  pinMode(PIN_TONE_P, OUTPUT);
  digitalWrite(PIN_TONE_P, LOW) ;
  pinMode(PIN_TONE_N, OUTPUT);
  digitalWrite(PIN_TONE_N, LOW) ;
  Serial.begin(115200);
  delay (3000);// wait to make sure serial begin 
  Serial.println(F(__FILE__ " " __DATE__ " " __TIME__));
  Serial.println("START");
}

void loop() {
  Serial.println("now play");
  play_song(song1);
  delay(silent_song_time);
}
