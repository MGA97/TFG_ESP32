#include "MPU9250.h"
#include "datos.h"

#ifndef MPU_H_INCLUDED
#define MPU_H_INCLUDED


bool initMPU(MPU9250 *IMU);

void dataMPU (MPU9250 *IMU);
void getDataMPU (acelerometro_t *acel);
void showDataStructMPU(acelerometro_t *acel);

#endif // MPU_H_INCLUDED
