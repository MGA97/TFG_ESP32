#include "flex.h"
#include "MPU.h"
#include "datos.h"


void showDataGlove (guante_t *guante1)
{
	showDataStructFlex (&guante1->sflex);
	showDataStructMPU (&guante1->acel);
}




