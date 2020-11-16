#ifndef FLEX_H_INCLUDED
#define FLEX_H_INCLUDED

#include "datos.h"


#define FLEX_PIN1 39
#define FLEX_PIN2 34
#define FLEX_PIN3 35
#define FLEX_PIN4 32
#define FLEX_PIN5 33

#define VCC 3.33
#define R 19000 // 37k input ADC//39k

#define SFLEX_LOW 30000
#define SFLEX_HIGH 80000

void showDataFlexes();
void showSingleDataFlex(int FLEX_PIN);
float readSingleDataFlex(int FLEX_PIN);
void getDataFlex (flexibles_t *sflex);
void showDataStructFlex (flexibles_t *sflex);
float readSingleDataFlexCalibrated(int FLEX_PIN, float sflexCalL, float sflexCalH);
void setCalibrationFlex(float *sflexCal);
void calibrationFlex(float *sflexCal);

#endif // FLEX_H_INCLUDED
