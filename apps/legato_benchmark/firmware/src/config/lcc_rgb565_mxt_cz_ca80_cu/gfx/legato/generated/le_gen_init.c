#include "gfx/legato/generated/le_gen_init.h"

static int32_t currentScreen;
static int32_t changingToScreen;

void legato_initializeScreenState(void)
{
    leSetStringTable(&stringTable);

    initializeStrings();

    screenInit_Splash();
    screenInit_FPSCounters();
    screenInit_FPSMotion();
    screenInit_FPSImages();

    currentScreen = -1;
    changingToScreen = -1;

    legato_showScreen(screenID_Splash);
}

uint32_t legato_getCurrentScreen(void)
{
    return currentScreen;
}

static void legato_hideCurrentScreen(void)
{
    switch(currentScreen)
    {
        case screenID_Splash:
        {
            screenHide_Splash();
            currentScreen = 0;
            break;
        }
        case screenID_FPSCounters:
        {
            screenHide_FPSCounters();
            currentScreen = 0;
            break;
        }
        case screenID_FPSMotion:
        {
            screenHide_FPSMotion();
            currentScreen = 0;
            break;
        }
        case screenID_FPSImages:
        {
            screenHide_FPSImages();
            currentScreen = 0;
            break;
        }
    }
}

void legato_showScreen(uint32_t id)
{
    if(changingToScreen >= 0)
        return;

    changingToScreen = id;
}

void legato_updateScreenState(void)
{
    if(changingToScreen >= 0)
    {
        legato_hideCurrentScreen();

        switch(changingToScreen)
        {
            case screenID_Splash:
            {
                screenShow_Splash();
                break;
            }
            case screenID_FPSCounters:
            {
                screenShow_FPSCounters();
                break;
            }
            case screenID_FPSMotion:
            {
                screenShow_FPSMotion();
                break;
            }
            case screenID_FPSImages:
            {
                screenShow_FPSImages();
                break;
            }
        }

        currentScreen = changingToScreen;
        changingToScreen = -1;
    }

    switch(currentScreen)
    {
        case screenID_Splash:
        {
            screenUpdate_Splash();
            break;
        }
        case screenID_FPSCounters:
        {
            screenUpdate_FPSCounters();
            break;
        }
        case screenID_FPSMotion:
        {
            screenUpdate_FPSMotion();
            break;
        }
        case screenID_FPSImages:
        {
            screenUpdate_FPSImages();
            break;
        }
    }
}

leBool legato_isChangingScreens(void)
{
    return changingToScreen != -1;
}

