#include "ESP32Ping.h"
#include "MPU9250.h"

#include "wifi.h"
#include "MPU.h"
#include "flex.h"
#include "datos.h"


//WiFi
bool statusWifi;
IPAddress subnet(172,16,0,0);
IPAddress esp(172,16,0,200);
IPAddress rpi(172,16,0,100);

// Acelerometro probar con los 2
MPU9250 IMU(Wire,0x68);
bool statusMPU;


guante_t guante1;
acelerometro_t acel;
flexibles_t sflex;

void setup()
{
    Serial.begin(115200);

    // wifi
    statusWifi = wifiConnect(esp, rpi, subnet);
    if (!statusWifi) {
        Serial.println("Connection error");
        exit(1);
    }

    // acelerometro
    statusMPU = initMPU(&IMU);
    if (!statusMPU) {
        Serial.println("IMU initialization unsuccessful");
        exit(1);
    }
    //flex sensor
    pinMode(FLEX_PIN1, INPUT);
    pinMode(FLEX_PIN2, INPUT);

}

void loop()
{
    //acelerometro
    //dataMPU(&IMU);
    getDataMPU(&acel,&IMU);
    showDataStructMPU(&acel);

    //flex sensor
    //showDataFlexes();
    getDataFlex(&sflex);
    showDataStructFlex(&sflex);
}
