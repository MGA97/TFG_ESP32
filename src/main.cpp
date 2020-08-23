#include "ESP32Ping.h"
#include "MPU9250.h"
#include "WiFi.h"

#include "wifi.h"
#include "MPU.h"
#include "flex.h"
#include "datos.h"
#include "glove.h"


//WiFi
bool statusWifi;
IPAddress subnet(172,16,0,0);
IPAddress esp(172,16,0,200);
IPAddress rpi(172,16,0,100);


//cliente
bool statusWifiClient;
//uint16_t port = 2023;

// Acelerometro
MPU9250 IMU(Wire,0x68);
bool statusMPU;


guante_t guante1;
acelerometro_t *acel = &guante1.acel;
flexibles_t *sflex = &guante1.sflex;

char txbuffer[sizeof(guante_t)];

const char * host = "172.16.0.100";
const uint16_t port = 2320;

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
    acel->IMU = &IMU;

    //flex sensor
    pinMode(FLEX_PIN1, INPUT);
    pinMode(FLEX_PIN2, INPUT);

}

void loop()
{
    //acelerometro
    //dataMPU(&IMU);
    getDataMPU(acel);
    showDataStructMPU(acel);

    //flex sensor
    //showDataFlexes();
    getDataFlex(sflex);
    showDataStructFlex(sflex);

    //showDataGlove(&guante1);
    memcpy(&txbuffer, &guante1, sizeof(guante1));

    WiFiClient client;

    if(!client.connect(host, port)) {
    	Serial.println("Connection to server failed");
    	delay(1000);
    	return;
    }
    Serial.println("Connected to server");
    //client.println("hola");
    client.write(txbuffer,sizeof(txbuffer));
    //client.write((byte*)&guante1, sizeof(guante1));
    Serial.println("Disconnecting...");

    client.stop();

    delay(2000);

}
