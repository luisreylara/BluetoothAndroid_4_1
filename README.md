##  This app Android Works Bluetooth with api 16 Jelly Bean 4.1 BluetoothAndroid_4_1

![ima1](https://github.com/luisreylara/BluetoothAndroid_4_1/blob/main/doc/bt01.png)
![ima1](https://github.com/luisreylara/BluetoothAndroid_4_1/blob/main/doc/bt02.png)

## This app require ESP32 code , whichone sends data to the app over BT
[CodeEsp32](https://github.com/luisreylara/BluetoothAndroid_4_1/blob/main/doc/BT_Entrada.ino)

## Code.ino
```

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
//STRINGS FOR BLUETOOTH COMMUNICATIONS
String rfid="luis,paco,111111,22222";
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
```


### Bib & Source
* https://www.electroniclinic.com/how-to-create-android-app-for-arduino-sensor-monitoring-over-bluetooth/#google_vignette



