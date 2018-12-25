#include <Time.h>
#include <TimeLib.h> 

#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

const char* ssid= "ESP_9B6090";
const char* password = "ESP8266Test";

#define FIREBASE_HOST  "deneme-eb804.firebaseio.com"
#define FIREBASE_AUTH "41MqeGfErOCACpyb290ZMr0ekRDvdKjusCHqrxMn"

#define WIFI_SSID "Aysinur" 
#define WIFI_PASSWORD "aysinurrr"

void setup() {
  // put your setup code here, to run once:
  delay(900);
  Serial.begin(115200); //seri port ekranının baund numarasi.
  Serial.println("WiFi yapılandırılıyor.......");
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD); //esp8266'nın yumuşak erişimdeki şifresi ve id sinin yapılandırılması.
  Serial.print("Baglaniyorrrr");
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("baglandi.");

  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  
  boolean result = WiFi.softAP(ssid,password);

  if(result = true)
  {
    Serial.println("Ready");
  }
  else 
  {
    Serial.println("Failed!");
  }
}

void loop() {
 /* int number = WiFi.softAPgetStationNum();
  Serial.printf("Alandaki Kişi Sayısı = %d\n", number);
  Serial.printf("Dakika : %d\n", minute());
  
  Firebase.setFloat("number", number);

  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  Firebase.pushInt("Adet", number);
  delay(1000);*/

  int number = WiFi.softAPgetStationNum();
  int dakika =  minute();
  Serial.printf("Dakika : %d\n", dakika);
  Serial.printf("Alandaki Kişi Sayısı = %d\n", number);
 
  Firebase.setFloat("number", number);

  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  
}

  
