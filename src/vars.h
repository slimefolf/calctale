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
void frameDelay();
void gameSetup();

//framerate stuffz
#define TARGET_FRAMERATE 30
#define TARGET_FRAME_TIME (CLOCKS_PER_SEC / TARGET_FRAMERATE)