//variable initialization


//libraries
#include <ti/getcsc.h>
#include <compression.h>
#include <graphx.h>
#include <keypadc.h>
#include <time.h>

//Misc. variables
int inGame = true;
int playerX = 0;
int playerY = 0;
int playerDir = 1;
int animTimer = 0;
int animPhase = 1;

//Functions
void renderScr();
void getInput();
void playerAnim();