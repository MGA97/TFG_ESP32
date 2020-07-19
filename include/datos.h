#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED


struct flexibles //estructura para guardar los valores de los 5 sensores flexibles
{
    float dedos[5];
};
typedef flexibles flexibles_t;

struct acelerometro
{
    float accX;
    float accY;
    float accX;

    float gyroX;
    float gyroY;
    float gyroZ;

    float magX;
    float magY;
    float magZ;
};
typedef acelerometro acelerometro_t;

struct guante
{
    flexibles_t sflex;
    acelerometro_t acel;
};
typedef guante guante_t;

#endif // DATOS_H_INCLUDED
