
#define PIN_TONE_P 8 // one side of the piezo buzzer
#define PIN_TONE_N 12 // other side of the piezo buzzer
uint16_t note_time = 200; // mS 
uint16_t p_time = 200;
uint16_t p_between_notes_time = 20;
uint16_t silent_song_time = 2000; // mS 

// freq in hertz
float DO = 261.63;
float DOD = 277.18;
float RE = 293.66;
float RED = 311.13;
float MI = 329.63;
float FA = 349.23;
float FD = 369.99;
float SOL = 392.00;
float SOLD = 415.30;
float LA = 440.00;
float LAD = 466.16;
float CI = 493.88;

float P = -1; //pause note
float END = -2; //end of song

float song1[] = {SOL,MI,MI,P,FA,RE,RE,P,DO,RE,MI,FA,SOL,SOL,SOL,P,SOL,MI,MI,P,FA,RE,RE,P,DO,MI,SOL,SOL,DO,P,P,P,RE,RE,RE,RE,RE,MI,FA,P,MI,MI,MI,MI,MI,FA,SOL,P,SOL,MI,MI,P,FA,RE,RE,P,DO,MI,SOL,SOL,DO,P,END};
float song2[] = {DO,RE,MI,FA,SOL,LA,CI,DO,END};

uint16_t calculate_half_cycle_time(float note) {
  return static_cast<unsigned int>(1/(2*note) * 1000000);
}

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
  delay (3500);// wait to make sure serial begin 
  Serial.println(F(__FILE__ " " __DATE__ " " __TIME__));
  Serial.println("START");

}

void loop() {
  Serial.println("now play");
  play_song(song1);
  delay(silent_song_time);
}
