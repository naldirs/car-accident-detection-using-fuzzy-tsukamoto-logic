#include <ESP8266WiFi.h>
byte ledPin = 2;
char ssid[] = "MyPoint";          // SSID dari akses point
char pass[] = "12345677";         // password dari akses point

IPAddress server(192,168,4,1);    // IP address dari akses point
WiFiClient client;

void wirelessinit(){
  Serial.begin(9600);
  // Konek ke akses point
  WiFi.begin(ssid, pass);
  WiFi.mode(WIFI_STA);
  // perulangan jika tidak konek ke akses point
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  // menampilkan info wifi di serial monitor
  Serial.println();
  Serial.println("Connected");
  Serial.print("LocalIP:"); Serial.println(WiFi.localIP());
  Serial.println("MAC:" + WiFi.macAddress());
  Serial.print("Gateway:"); Serial.println(WiFi.gatewayIP());
  Serial.print("AP MAC:"); Serial.println(WiFi.BSSIDstr());
  //pinMode(ledPin, OUTPUT);
}

// fungsi untuk mengirimkan data
void senddata(){
  client.connect(server, 80);
  //digitalWrite(ledPin, LOW);
  client.print(String(accx)+ "\t" +String(accy)+ "\t" +String(getr)+ "\t" +String(fuzzyf)+ " (" +fuzzyh+ ")" );
  client.print("\t\tkoordinat: "+String(lastlatt,6)+","+String(lastlong,6)+"\r");

  client.flush();
 // digitalWrite(ledPin, HIGH);
  client.stop();
}
