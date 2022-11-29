#include <WiFi.h>
#include <Wiegand.h>
#include <HTTPClient.h>
#include "BluetoothSerial.h"


// WiFi details

//const char *ssid     = "ADM/PTC";
//const char *password = "";

//const char *ssid     = "Steve Wozniak";
//const char *password = "5eNTbbQe";

//const char *ssid     = "Estoicos";
//const char *password = "*Andromeda_$23";

//const char *ssid     = "IRT 2.4";
//const char *password = "Irt*2022";

const char *ssid     = "8Ainternet_F6A4";
const char *password = "MPXbT5ghyR";

//const char *ssid     = "Alumnos";
//const char *password = "";

String RFID = "8900703";

#define DEBUG(a) Serial.println(a);
#define LED1 14
#define LED2 27
#define LED3 26

BluetoothSerial BT;


WIEGAND wg;

void WiFi_Setup() {

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  int contador = 0;
  while (WiFi.status() != WL_CONNECTED && contador < 20 ) {
    delay(500);
    Serial.print(".");
    contador += 1;
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("WiFi connected!");
  }else {
    ESP.restart();
  }
  wg.begin();
}

void setup() {
  Serial.begin(115200);
  WiFi_Setup();
  BT.begin("Puerta01");

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {

  if (wg.available() )
  {
    HTTPClient http;
    String RFID = String (wg.getCode());
    String datos_a_enviar = "rfid=" + RFID;
    Serial.println(datos_a_enviar);


       http.begin("http:// /registro/pluma.php");       
    
    http.addHeader("Content-Type", "application/x-www-form-urlencoded"); //Preparamos el header text/plain si solo vamos a enviar texto plano sin un paradigma llave:valor.

    int codigo_respuesta = http.POST(datos_a_enviar);   
    
    if (codigo_respuesta > 0) {
    
      if (codigo_respuesta == 404) {
        String cuerpo_respuesta = http.getString();
        
        Serial.println(cuerpo_respuesta);
        Serial.println(cuerpo_respuesta);
        long value;
        value = cuerpo_respuesta.toInt();
        DEBUG(value);
        if (value==9991){
          digitalWrite(LED1, HIGH);   // turn the LED on (HIGH is the voltage level)
          delay(1000);                       // wait for a second
          digitalWrite(LED1, LOW);    // turn the LED off by making the voltage LOW
         delay(1000);  
        }
        if (value==9990){
          digitalWrite(LED2, HIGH);   // turn the LED on (HIGH is the voltage level)
          delay(1000);                       // wait for a second
          digitalWrite(LED2, LOW);    // turn the LED off by making the voltage LOW
         delay(1000);  
        }
        if (value==777){
          digitalWrite(LED3, HIGH);   // turn the LED on (HIGH is the voltage level)
          delay(1000);                       // wait for a second
          digitalWrite(LED3, LOW);    // turn the LED off by making the voltage LOW
          delay(1000);
          }
        
        //BT.println(cuerpo_respuesta);
      }
    } 
    else {
      Serial.println(codigo_respuesta);
    }
    http.end();  
  }
}
