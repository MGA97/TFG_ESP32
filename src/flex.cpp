#include "Arduino.h"

#include "flex.h"

#define FLEX_PIN1 39
#define FLEX_PIN2 34
#define FLEX_PIN2 35
#define FLEX_PIN2 32
#define FLEX_PIN2 33

const float VCC = 3.33;
const float R_DIV = 40000; //37k input ADC
const float STRAIGHT_RES = 29000.0;
const float BEND_RES = 80000.0;

void showDataFlexes ()
{
    showSingleDataFlex(FLEX_PIN1);
    showSingleDataFlex(FLEX_PIN2);

    delay(1000);
}

void showSingleDataFlex (int FLEX_PIN)
{
    float flexR = readDataFlex(FLEX_PIN);
    Serial.println("Resistencia: " + String(flexR) + " ohms");
    Serial.println("");
}

float readSingleDataFlex(int FLEX_PIN)
{
    int flexADC = analogRead(FLEX_PIN);
    float flexV = flexADC * (VCC/4095); //12 bits ADC
    float flexR = R_DIV * (VCC/flexV - 1.0);
    return flexR;
}

void getDataFlex (flexibles_t *sflex)
{
    float fpin[5] = {FLEX_PIN1,FLEX_PIN2,FLEX_PIN3,FLEX_PIN4,FLEX_PIN5};

    for (int i = 0; i < sizeof(fpin); i++)
    sflex.dedos[i] = readSingleDataFlex(fpin[i]);
}

