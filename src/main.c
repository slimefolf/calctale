//CalcTale, an Undertale port to the TI-84 calculator by Gavyn Rodimon, or slimefolf on Cemetech


//libraries n stuff
#include <ti/getcsc.h>
#include <compression.h>
#include <graphx.h>
#include <keypadc.h>
#include <time.h>
#include "func.c"
#include "vars.h"
#include "gfx/sprites.h"

//framerate stuffz
#define TARGET_FRAMERATE 30
#define TARGET_FRAME_TIME (CLOCKS_PER_SEC / TARGET_FRAMERATE)

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