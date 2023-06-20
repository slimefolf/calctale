//CalcTale, an Undertale port to the TI-84 calculator by Gavyn Rodimon, or slimefolf on Cemetech


//libraries n stuff
#include <ti/getcsc.h>
#include <compression.h>
#include <graphx.h>
#include <keypadc.h>
#include <time.h>
#include "func.c"
#include "gfx/sprites.h"

//frame limit
#define TARGET_FRAMERATE 30
#define TARGET_FRAME_TIME (CLOCKS_PER_SEC / TARGET_FRAMERATE)

//main stuffz
int main(void) {
	
	//setup / initialization
	if (sprites_init() == 0) {return 1;}
    gfx_Begin();
	gfx_SetDrawBuffer();
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);
	
	//the endless loop of pain and suffering (for the developer, anyways)
	do {
		getInput();
		renderScr();
		
		//frame delay
		clock_t frame_start = clock();
		clock_t frame_time = clock() - frame_start;
		do {frame_time = clock() - frame_start;} while (frame_time < TARGET_FRAME_TIME);
	} while(inGame == true);
	
    gfx_End();
    return 0;
}