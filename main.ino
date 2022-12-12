// Set Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID           "YOUR_TEMPLATE_ID"
#define BLYNK_DEVICE_NAME           "YOUR_DIVICE_NAME"
#define BLYNK_AUTH_TOKEN            "YOUR_AUTH_TOKEN"

//set I/O Pin 
#define CH1 D2 
#define CH2 D3
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YOUR_SSID_WIFI";
char pass[] = "YOUR_PASSWORD_WIFI";

//function recive data V1 pin from Blynk app project
BLYNK_WRITE(V1) {
  int valueButton1 = param.asInt();
  if(valueButton1 == 1)  {    digitalWrite(CH1,HIGH);  }
  else  {    digitalWrite(CH1,LOW);   }
}

//function recive data V2 pin from Blynk app project
BLYNK_WRITE(V2) {
  int valueButton2 = param.asInt();
  if(valueButton2 == 1)  {  digitalWrite(CH2,HIGH);  }
  else  {   digitalWrite(CH2,LOW);  }
}

void setup() {
  pinMode(CH1, OUTPUT);
  pinMode(CH2, OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
}
