#ifndef FLEX_H_INCLUDED
#define FLEX_H_INCLUDED

extern const int FLEX_PIN1;
extern const int FLEX_PIN2;

extern const float VCC;
extern const float R_DIV;
extern const float STRAIGHT_RES;
extern const float BEND_RES;

void showDataFlexes();
void showSingleDataFlex(int FLEX_PIN);
float readDataFlex(int FLEX_PIN);

#endif // FLEX_H_INCLUDED
