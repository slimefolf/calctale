//CalcTale, an Undertale port to the TI-84 calculator by Gavyn Rodimon, or slimefolf on Cemetech


//libraries n stuff
#include <ti/getcsc.h>
#include <compression.h>
#include <graphx.h>
#include <keypadc.h>
#include <time.h>
#include "gfx/sprites.h"

//miscellaneous variables 
int inGame = true;
int playerX = 0;
int playerY = 0;
int playerDir = 1;
int animTimer = 0;
int animPhase = 1;

//framerate stuffz
#define TARGET_FRAMERATE 30
#define TARGET_FRAME_TIME (CLOCKS_PER_SEC / TARGET_FRAMERATE)

//function initialization
void renderScr();
void getInput();
void playerAnim();
void frameDelay();



//main stuffz
int main(void)
{
	if (sprites_init() == 0) {return 1;}
    gfx_Begin();
	gfx_SetDrawBuffer();
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);

	//the endless loop of pain and suffering (for the developer, anyways)
	do {
		getInput();
		renderScr();
		frameDelay();
	} while(inGame == true);
	
    gfx_End();
    return 0;
}



//Gets the input from the keypad
void getInput() {
	kb_Scan();
	if (kb_Data[6] & kb_Clear) {inGame = false;}
	if (kb_Data[7]) {
		if (kb_Down == true) {playerDir = 1;}
		if (kb_Left == true) {playerDir = 2;}
		if (kb_Up == true) {playerDir = 3;}
		if (kb_Right == true) {playerDir = 4;}
		playerAnim();
	}
	else {
		animPhase = 1;
		animTimer = 0;
	}
}

//Renders graphics to the screen
void renderScr() {
	gfx_FillScreen(1);
	if (playerDir == 1) {
		if (animPhase == 1) {gfx_TransparentSprite(friskIdleDn, 150, 105);}
		else if (animPhase == 2) {gfx_TransparentSprite(friskWalkDn1, 150, 105);}
		else if (animPhase == 3) {gfx_TransparentSprite(friskWalkDn2, 150, 105);}
	}
	gfx_SwapDraw();
}

//animation when walkin'
void playerAnim() {
	if (animTimer >= 30) {animTimer = 0;}
	if ((animTimer >= 1) && (animTimer <= 7)) {animPhase = 2;}
	else if ((animPhase >= 16) && (animPhase <= 22)) {animPhase = 3;}
	else {animPhase = 1;}
	animTimer = animTimer + 1;
}

//The delay used to cap the framerate (about 30fps)
void frameDelay() {
	//frame cap stuff
	clock_t frame_start = clock();
	clock_t frame_time = clock() - frame_start;
	do {frame_time = clock() - frame_start;} while (frame_time < TARGET_FRAME_TIME);
}