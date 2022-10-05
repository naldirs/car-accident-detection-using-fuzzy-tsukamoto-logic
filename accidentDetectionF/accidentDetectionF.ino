#include <SoftwareSerial.h>

/*GPS variable*/
float lastlatt, lastlong;
/*Accelero variable*/
float accx, accy;
/*Vibr variable*/
long getr;
/*Fuzzy variable*/
float fuzzyf;
String fuzzyh;
/*Message to send*/
char carStatus;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  buzzinit();
  gpsinit();
  gsminit();
  acceleroinit();
  getarinit();
  //wirelessinit();
  buzok();
  lastlatt = -0.468874;
  lastlong = 117.156525;
}
 
void loop() {
  // put your main code here, to run repeatedly:
  getgps();
  getaccelero();
  getgetr();
  fuzzyf = fuzzy(accx,accy,getr);
  fuzzyh = himpunan(accx,accy,getr);
  createmessage();  
  //senddata();
  serialPrint(); 
}


void serialPrint(){
  Serial.print(String(accx)+ "\t" +String(accy)+ "\t" +String(getr)+ "\t" +String(fuzzyf)+ " (" +fuzzyh+ ")");
  Serial.println("\t\tkoordinat: " +String(lastlatt,6)+ "," +String(lastlong,6));
  /*test kirim pesan*/
  if(Serial.available()>0){
    sendCommands(Serial.read());
  }
}
