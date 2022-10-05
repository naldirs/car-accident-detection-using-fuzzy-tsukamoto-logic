#include <TinyGPS++.h>
#define gpsTX 14
#define gpsRX 12
SoftwareSerial gpsSerial(gpsTX, gpsRX);

TinyGPSPlus gps;

void gpsinit() {
  gpsSerial.begin(9600);
}

void getgps() {  
  while(gpsSerial.available() > 0)
  if(gps.encode(gpsSerial.read())) {
    lastlatt = (gps.location.lat());
    lastlong = (gps.location.lng());
  } 
  /*If 5000 milliseconds pass and there are no characters coming in
  over the software serial port, show a "No GPS detected" error*/
  if (millis() > 500 && gps.charsProcessed() < 10) {
    nogps();
    Serial.println(" GPS tidak terpasang!");
  }
}
