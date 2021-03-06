#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED

#include "MPU9250.h"


struct flexibles
{
    float dedos[5];
};
typedef flexibles flexibles_t;

struct acelerometro
{
    float accX;
    float accY;
    float accZ;

    float gyroX;
    float gyroY;
    float gyroZ;

    float magX;
    float magY;
    float magZ;

    MPU9250 *IMU;
};
typedef acelerometro acelerometro_t;

struct guante
{
    flexibles_t sflex;
    acelerometro_t acel;
};
typedef guante guante_t;

#endif // DATOS_H_INCLUDED
