#include "sprites.h"
#include <fileioc.h>

#define sprites_HEADER_SIZE 0

unsigned char *sprites_appvar[4] =
{
    (unsigned char*)0,
    (unsigned char*)12,
    (unsigned char*)565,
    (unsigned char*)1118,
};

unsigned char sprites_init(void)
{
    unsigned int data, i;
    uint8_t appvar;

    appvar = ti_Open("sprites", "r");
    if (appvar == 0)
    {
        return 0;
    }

    data = (unsigned int)ti_GetDataPtr(appvar) - (unsigned int)sprites_appvar[0] + sprites_HEADER_SIZE;
    for (i = 0; i < 4; i++)
    {
        sprites_appvar[i] += data;
    }

    ti_Close(appvar);

    return 1;
}

