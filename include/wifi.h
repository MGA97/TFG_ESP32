
#ifndef SETUP_H_INCLUDED
#define SETUP_H_INCLUDED

//WIFI
#define SSID (char*)"PiNetMal"

bool wifiConnect(IPAddress esp, IPAddress rpi, IPAddress subnet);

#endif // SETUP_H_INCLUDED
