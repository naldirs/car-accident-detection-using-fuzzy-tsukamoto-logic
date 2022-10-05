/*Nomor tujian*/
String number = "+6285156575574";
/*Pin modul gsm*/
#define gsmTX 0
#define gsmRX 2
SoftwareSerial gsmSerial(gsmTX, gsmRX);

void gsminit() {
  gsmSerial.begin(9600);
}

void sendmessage(String stats){
  gsmSerial.println("AT+CMGF=1");
  delay(1000);
  gsmSerial.println("AT+CMGS=\""+number+"\"\r"); 
  delay(1000);
  gsmSerial.print("Sistem mendeteksi "+stats+" pada titik koordinat\nLatitude: "+String(lastlatt,6)+"\nLongitude: "+String(lastlong,6)+"\nhttps://www.google.com/maps/place/"+String(lastlatt,6)+","+String(lastlong,6)); // The SMS text you want to send
  delay(100);
  gsmSerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
  delay(1000);
  smsterkirim();
  //Serial.print("mengirimkan pesan!\n");
}

void sendCommands(char command){
  switch(command){
    case 't':
      sendmessage("kendaraan terguling");
    break;
    case 'k':
      sendmessage("telah mengalami tabrakan");
    break;
  }
}
