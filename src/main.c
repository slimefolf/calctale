//CalcTale, an Undertale port to the TI-84 calculator by Gavyn Rodimon, or slimefolf on Cemetech


//libraries n stuff
#include <ti/getcsc.h>
#include <compression.h>
#include <graphx.h>
#include <keypadc.h>
#include <time.h>
#include "func.c"
#include "gfx/sprites.h"

//main stuffz
int main(void) {
	gameSetup();
	
	//the endless loop of pain and suffering (for the developer, anyways)
	do {
		getInput();
		renderScr();
		frameDelay();
	} while(inGame == true);
	
    gfx_End();
    return 0;
}