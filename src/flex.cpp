#include "Arduino.h"

#include "flex.h"

const int FLEX_PIN1 = 34;
const int FLEX_PIN2 = 35;

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

float readDataFlex(int FLEX_PIN)
{
    int flexADC = analogRead(FLEX_PIN);
    float flexV = flexADC * (VCC/4095); //12 bits ADC
    float flexR = R_DIV * (VCC/flexV - 1.0);
    return flexR;
}
