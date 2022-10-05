#define vbr 13

void getarinit(){
  pinMode(vbr, INPUT);
}

void getgetr(){
  getr = vibpulse();
}

long vibpulse(){
  delay(10);
  long measurement=pulseIn(vbr, HIGH);
  return measurement;
}
