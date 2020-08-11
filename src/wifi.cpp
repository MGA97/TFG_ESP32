#include "WiFi.h"

#include "wifi.h"

bool wifiConnect(IPAddress esp, IPAddress rpi, IPAddress subnet)
{
    WiFi.config(esp, rpi, subnet); //esp: ip; rpi: gateway;

    for(int i = 0; (i < 5) && (WiFi.status() != WL_CONNECTED); i++) {
        delay(500);
        Serial.println("Connecting to WiFi...");
        WiFi.begin(SSID);
    }
    if (WiFi.status() != WL_CONNECTED) {
        return false;
    }
    Serial.println("Connected to the WiFi network");
    return true;
}

bool wifiClientConnect (WiFiClient client, IPAddress rpi, int port)
{
	for (int i = 0; (i < 5) && client.connect(rpi, port) != 1; i++) {
		delay(500);
		Serial.println("Client connecting...");
	}
	if (!client.connect(rpi,port)){
		return false;
	}
	Serial.println("Client connected");
	return true;
}
