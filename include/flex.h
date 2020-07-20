#ifndef FLEX_H_INCLUDED
#define FLEX_H_INCLUDED

#include "datos.h"

extern const int FLEX_PIN1;
extern const int FLEX_PIN2;
extern const int FLEX_PIN3;
extern const int FLEX_PIN4;
extern const int FLEX_PIN5;

extern const float VCC;
extern const float R_DIV;
extern const float STRAIGHT_RES;
extern const float BEND_RES;

void showDataFlexes();
void showSingleDataFlex(int FLEX_PIN);
float readSingleDataFlex(int FLEX_PIN);
void getDataFlex (flexibles_t *sflex);


#endif // FLEX_H_INCLUDED
