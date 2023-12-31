#include <ti/getcsc.h>
#include <compression.h>
#include <graphx.h>
#include <keypadc.h>
#include <time.h>
#include "gfx/sprites.h"
#include "vars.c"

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