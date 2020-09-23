#include "MPU9250.h"
#include "WiFi.h"

#include "wifi.h"
#include "MPU.h"
#include "flex.h"
#include "datos.h"
#include "glove.h"


//WiFi
bool statusWifi; //comprobacion wifiConnect
IPAddress subnet(172,16,0,0);
IPAddress esp(172,16,0,200);
IPAddress rpi(172,16,0,100);
const int port = 2320; //puerto servidor

// Acelerometro
MPU9250 IMU(Wire,0x68);
bool statusMPU; //comprobacion initMPU

//estructuras
guante_t guante1;
acelerometro_t *acel = &guante1.acel;
flexibles_t *sflex = &guante1.sflex;

char txbuffer[sizeof(guante_t)]; //buffer para almacenar estructura guante1



void setup()
{
    Serial.begin(115200);

    // WIFI
    statusWifi = wifiConnect(esp, rpi, subnet);
    if (!statusWifi) {
        Serial.println("Connection error");
        exit(1);
    }

    memset(&guante1, 0, sizeof(guante1)); //preparar espacio de memoria para estructura guante

    // ACELEROMETRO
    statusMPU = initMPU(&IMU);
    if (!statusMPU) {
        Serial.println("IMU initialization unsuccessful");
        exit(1);
    }
    acel->IMU = &IMU; //meter objeto IMU en la estructura

    // SENSOR FLEXIBLE
    pinMode(FLEX_PIN1, INPUT);
    pinMode(FLEX_PIN2, INPUT);
    pinMode(FLEX_PIN3, INPUT);
    pinMode(FLEX_PIN4, INPUT);
    pinMode(FLEX_PIN5, INPUT);
}

void loop()
{
    //ACELEROMETRO
    getDataMPU(acel);
    showDataStructMPU(acel);

    //SENSOR FLEXIBLE
    getDataFlex(sflex);
    showDataStructFlex(sflex);

    memcpy(txbuffer, &guante1, sizeof(txbuffer)); //copiar estructura guante1 a buffer memoria

    WiFiClient client;
    if(!client.connect(rpi, port)) {
    	Serial.println("Connection to server failed");
    	delay(1000);
    	return;
    }
    Serial.println("Connected to server");
    client.write(txbuffer, sizeof(txbuffer));
    //client.write((byte*)&guante1, sizeof(guante1));
    Serial.println("Disconnecting...");

    client.stop();

    delay(2000);
}
