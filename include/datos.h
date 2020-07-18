#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED


struct dedos //estructura para guardar los valores de los 5 sensores flexibles
{
        float dedo1; //pulgar
        float dedo2; //indice
        //float dedo3; //corazon
        //float dedo4; //anular
        //float dedo5; //meñique
} ;


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
} ;

#endif // DATOS_H_INCLUDED
