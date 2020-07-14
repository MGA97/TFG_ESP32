#include "MPU9250.h"

#include "MPU.h"


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
