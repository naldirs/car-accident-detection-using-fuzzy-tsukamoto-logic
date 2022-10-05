#define buz 15

void buzzinit(){
  pinMode(buz, OUTPUT);
}

void buzok(){
  tone(buz,2000,300); delay(600);
}

void noakselero(){
  tone(buz,2000,500); delay(600);
  tone(buz,2000,500); delay(600);
}

void nogps(){
  tone(buz,2000,500); delay(600);
  tone(buz,2000,500); delay(600);
  tone(buz,2000,500); delay(600);
  tone(buz,2000,500); delay(600);
}

void smsterkirim(){
  tone(buz,2000,200); delay(250);
  tone(buz,2000,200);
}

void tabrakan(){
  tone(buz,2000,200); delay(300);
  tone(buz,2000,200); delay(300);
  tone(buz,2000,200); delay(300);
  tone(buz,2000,200); delay(300);
  tone(buz,2000,200); delay(300);
  tone(buz,2000,200); delay(300);
  tone(buz,2000,200); delay(300);
  tone(buz,2000,200); delay(300);
  tone(buz,2000,200); delay(300);
  tone(buz,2000,200); delay(300);
  tone(buz,2000,200); delay(300);
  tone(buz,2000,200); delay(300);
  tone(buz,2000,200); delay(300);
  tone(buz,2000,200); delay(300);
  tone(buz,2000,200); delay(300);
  tone(buz,2000,200); delay(300);
  tone(buz,2000,200); delay(300);
  tone(buz,2000,200); delay(300);
  tone(buz,2000,200); delay(300);
  tone(buz,2000,200); delay(300);
}

void terguling(){
  tone(buz,2000,900); delay(1000);
  tone(buz,2000,900); delay(1000);
  tone(buz,2000,900); delay(1000);
  tone(buz,2000,900); delay(1000);
  tone(buz,2000,900); delay(1000);
  tone(buz,2000,900); delay(1000);
}
