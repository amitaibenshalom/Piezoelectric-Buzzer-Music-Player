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

uint16_t calculate_half_cycle_time(float note) {
  return static_cast<unsigned int>(1/(2*note) * 1000000);
}

int power(int a, int b) {
  int i = 0;
  int res = 1;
  while (b > 0){
    res *= a;
    b--;
  }
  return res;
}

// moves the note by n octaves FROM OCTAVE 4, n is signed
float move_octave(float note ,int n) {
  return note*power(2, n);
}


float song1[] = {SOL,MI,MI,P,FA,RE,RE,P,DO,RE,MI,FA,SOL,SOL,SOL,P,SOL,MI,MI,P,FA,RE,RE,P,DO,MI,SOL,SOL,DO,P,P,P,RE,RE,RE,RE,RE,MI,FA,P,MI,MI,MI,MI,MI,FA,SOL,P,SOL,MI,MI,P,FA,RE,RE,P,DO,MI,SOL,SOL,DO,P,END};
float song2[] = {DO,RE,MI,FA,SOL,LA,CI,move_octave(DO,1),END};
