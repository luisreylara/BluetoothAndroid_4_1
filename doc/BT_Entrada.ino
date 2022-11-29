
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
//STRINGS FOR BLUETOOTH COMMUNICATIONS
String rfid="pedro,diego,111111,22222";
char michar;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32Entrada"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}
void loop() {
  if (Serial.available()) {
    michar=Serial.read();
    if (michar=='a'){
      rfid="pedro,luis,111111,22222";
      SerialBT.println(rfid);
      Serial.println(rfid);
    }
    if (michar=='b') {
      rfid="diego,diego,3333,44444";
      SerialBT.println(rfid);
      Serial.println(rfid);
    }
  }
  delay(20);
}
