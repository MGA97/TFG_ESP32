
#ifndef SETUP_H_INCLUDED
#define SETUP_H_INCLUDED

//WIFI
#define SSID "PiNetMal"

bool wifiConnect(IPAddress esp, IPAddress rpi, IPAddress subnet);
bool wifiClientConnect(WiFiClient client, IPAddress rpi, int port);

#endif // SETUP_H_INCLUDED
