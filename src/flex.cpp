#include "Arduino.h"

#include "flex.h"
#include "datos.h"

float fpin[5] = {FLEX_PIN1,FLEX_PIN2,FLEX_PIN3,FLEX_PIN4,FLEX_PIN5};
float sflexCalLow[5];
float sflexCalHigh[5];

void showDataFlexes ()
{
	for (int i = 0; i < (sizeof(fpin)/sizeof(fpin[0])); i++){
    showSingleDataFlex(fpin[i]);
	}
}

void showSingleDataFlex (int FLEX_PIN)
{
    float flexR = readSingleDataFlex(FLEX_PIN);
    Serial.println("Resistencia: " + String(flexR) + " ohms");
    Serial.println("");
}

float readSingleDataFlex(int FLEX_PIN)
{
	analogReadResolution(12); //cambiar resolucion de analogRead a 12 bits
    int flexADC = analogRead(FLEX_PIN); //analogRead tiene 10 bits por defecto de resolucion
    float flexV = flexADC * (VCC/4095); //12 bits ADC
    float flexR = R * (VCC/flexV - 1.0);
    return flexR;
}

float readSingleDataFlexCalibrated(int FLEX_PIN, float sflexCalL, float sflexCalH)
{
	float flexR = readSingleDataFlex(FLEX_PIN);
	int flexRCal = map(flexR, sflexCalL, sflexCalH, SFLEX_LOW, SFLEX_HIGH);
	return flexRCal;
}

void getDataFlex (flexibles_t *sflex)
{
    for (int i = 0; i < (sizeof(fpin)/sizeof(fpin[0])); i++)
    sflex->dedos[i] = readSingleDataFlexCalibrated(fpin[i], sflexCalLow[i], sflexCalHigh[i]);

}

void showDataStructFlex (flexibles_t *sflex)
{
	for (int i = 0; i < (sizeof(sflex->dedos)/sizeof(sflex->dedos[0])); i++){
    Serial.println(sflex->dedos[i]);
	}
}

void calibrationFlex (float *sflexCal)
{
	for (int i = 0; i < (sizeof(fpin)/sizeof(fpin[0])); i++){
		sflexCal[i] += readSingleDataFlex(fpin[i]);
	}
}
