#ifndef FLEX_H_INCLUDED
#define FLEX_H_INCLUDED

#include "datos.h"


#define FLEX_PIN1 39
#define FLEX_PIN2 34
#define FLEX_PIN3 35
#define FLEX_PIN4 32
#define FLEX_PIN5 33

void showDataFlexes();
void showSingleDataFlex(int FLEX_PIN);
float readSingleDataFlex(int FLEX_PIN);
void getDataFlex (flexibles_t *sflex);
void showDataStructFlex (flexibles_t *sflex);

#endif // FLEX_H_INCLUDED
