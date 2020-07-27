#include "MPU9250.h"

#include "MPU.h"
#include "datos.h"

bool initMPU (MPU9250 *IMU)
{
    int status = IMU->begin();

    for(int i = 0; (i<5) && (status < 0); i++) {
        delay(500);
        status = IMU->begin();
    }
    if (status < 0) {
        return false;
    }
    Serial.println("IMU initialization successful");
    return true;

}

void dataMPU (MPU9250 *IMU)
{
    IMU->readSensor();

    Serial.println("Valores accel: ");
    Serial.println(IMU->getAccelX_mss(),6);
    Serial.println(IMU->getAccelY_mss(),6);
    Serial.println(IMU->getAccelZ_mss(),6);
    Serial.println("");

    Serial.println("Valores gyro: ");
    Serial.println(IMU->getGyroX_rads(),6);
    Serial.println(IMU->getGyroY_rads(),6);
    Serial.println(IMU->getGyroZ_rads(),6);
    Serial.println("");

    Serial.println("Valores magn: ");
    Serial.println(IMU->getMagX_uT(),6);
    Serial.println(IMU->getMagY_uT(),6);
    Serial.println(IMU->getMagZ_uT(),6);
    Serial.println("");
    //Serial.println(IMU->getTemperature_C(),6);
    delay(5000);
}

void getDataMPU (acelerometro_t *acel, MPU9250 *IMU)
{
    IMU->readSensor();
    //acel
    acel->accX = IMU->getAccelX_mss();
    acel->accY = IMU->getAccelY_mss();
    acel->accZ = IMU->getAccelZ_mss();

    //giro
    acel->gyroX = IMU->getGyroX_rads();
    acel->gyroY = IMU->getGyroY_rads();
    acel->gyroZ = IMU->getGyroZ_rads();

    //magn
    acel->magX = IMU->getMagX_uT();
    acel->magY = IMU->getMagY_uT();
    acel->magZ = IMU->getMagZ_uT();

}

void showDataStructMPU(acelerometro_t *acel)
{
    Serial.println(acel->accX,6);
    delay(1000);
}
