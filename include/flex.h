#ifndef FLEX_H_INCLUDED
#define FLEX_H_INCLUDED

#include "datos.h"


#define FLEX_PIN1 39
#define FLEX_PIN2 34
#define FLEX_PIN3 35
#define FLEX_PIN4 32
#define FLEX_PIN5 33

#define VCC 3.33
#define R 39000 //37k input ADC

#define SFLEX_LOW 30000
#define SFLEX_HIGH 80000

void showDataFlexes();
void showSingleDataFlex(int FLEX_PIN);
float readSingleDataFlex(int FLEX_PIN);
void getDataFlex (flexibles_t *sflex);
void showDataStructFlex (flexibles_t *sflex);
void calibrationFlex(float *sflexCal);
float readSingleDataFlexCalibrated(int FLEX_PIN, float sflexCalL, float sflexCalH);

#endif // FLEX_H_INCLUDED
