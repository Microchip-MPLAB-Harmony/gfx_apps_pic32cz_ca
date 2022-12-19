#include "gfx/legato/generated/screen/le_gen_screen_Splash.h"

// screen member widget declarations
static leWidget* root0;

leWidget* Splash_SplashBackground;
leImageWidget* Splash_SplashPIC32Logo;
leImageWidget* Splash_SplashHarmonyLogo;
leImageWidget* Splash_SplashBar;
leImageWidget* Splash_SplashMicrochipLogo;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Splash(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Splash(void)
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 480, 272);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Splash_SplashBackground = leWidget_New();
    Splash_SplashBackground->fn->setPosition(Splash_SplashBackground, 0, 0);
    Splash_SplashBackground->fn->setSize(Splash_SplashBackground, 480, 272);
    Splash_SplashBackground->fn->setScheme(Splash_SplashBackground, &WhiteFillScheme);
    root0->fn->addChild(root0, (leWidget*)Splash_SplashBackground);

    Splash_SplashPIC32Logo = leImageWidget_New();
    Splash_SplashPIC32Logo->fn->setPosition(Splash_SplashPIC32Logo, 120, 40);
    Splash_SplashPIC32Logo->fn->setSize(Splash_SplashPIC32Logo, 240, 139);
    Splash_SplashPIC32Logo->fn->setBackgroundType(Splash_SplashPIC32Logo, LE_WIDGET_BACKGROUND_NONE);
    Splash_SplashPIC32Logo->fn->setBorderType(Splash_SplashPIC32Logo, LE_WIDGET_BORDER_NONE);
    Splash_SplashPIC32Logo->fn->setImage(Splash_SplashPIC32Logo, (leImage*)&PIC32Logo);
    root0->fn->addChild(root0, (leWidget*)Splash_SplashPIC32Logo);

    Splash_SplashHarmonyLogo = leImageWidget_New();
    Splash_SplashHarmonyLogo->fn->setPosition(Splash_SplashHarmonyLogo, 120, 40);
    Splash_SplashHarmonyLogo->fn->setSize(Splash_SplashHarmonyLogo, 240, 139);
    Splash_SplashHarmonyLogo->fn->setVisible(Splash_SplashHarmonyLogo, LE_FALSE);
    Splash_SplashHarmonyLogo->fn->setScheme(Splash_SplashHarmonyLogo, &WhiteBackgroundScheme);
    Splash_SplashHarmonyLogo->fn->setBorderType(Splash_SplashHarmonyLogo, LE_WIDGET_BORDER_NONE);
    Splash_SplashHarmonyLogo->fn->setImage(Splash_SplashHarmonyLogo, (leImage*)&HarmonyLogo);
    root0->fn->addChild(root0, (leWidget*)Splash_SplashHarmonyLogo);

    Splash_SplashBar = leImageWidget_New();
    Splash_SplashBar->fn->setPosition(Splash_SplashBar, 480, 207);
    Splash_SplashBar->fn->setSize(Splash_SplashBar, 480, 65);
    Splash_SplashBar->fn->setBackgroundType(Splash_SplashBar, LE_WIDGET_BACKGROUND_NONE);
    Splash_SplashBar->fn->setBorderType(Splash_SplashBar, LE_WIDGET_BORDER_NONE);
    Splash_SplashBar->fn->setImage(Splash_SplashBar, (leImage*)&Bar);
    root0->fn->addChild(root0, (leWidget*)Splash_SplashBar);

    Splash_SplashMicrochipLogo = leImageWidget_New();
    Splash_SplashMicrochipLogo->fn->setPosition(Splash_SplashMicrochipLogo, 17, 223);
    Splash_SplashMicrochipLogo->fn->setSize(Splash_SplashMicrochipLogo, 144, 39);
    Splash_SplashMicrochipLogo->fn->setVisible(Splash_SplashMicrochipLogo, LE_FALSE);
    Splash_SplashMicrochipLogo->fn->setBackgroundType(Splash_SplashMicrochipLogo, LE_WIDGET_BACKGROUND_NONE);
    Splash_SplashMicrochipLogo->fn->setBorderType(Splash_SplashMicrochipLogo, LE_WIDGET_BORDER_NONE);
    Splash_SplashMicrochipLogo->fn->setImage(Splash_SplashMicrochipLogo, (leImage*)&MicrochipLogo);
    root0->fn->addChild(root0, (leWidget*)Splash_SplashMicrochipLogo);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    Splash_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Splash(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);

    Splash_OnUpdate(); // raise event
}

void screenHide_Splash(void)
{
    Splash_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Splash_SplashBackground = NULL;
    Splash_SplashPIC32Logo = NULL;
    Splash_SplashHarmonyLogo = NULL;
    Splash_SplashBar = NULL;
    Splash_SplashMicrochipLogo = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Splash(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Splash(uint32_t lyrIdx)
{
    if(lyrIdx >= LE_LAYER_COUNT)
        return NULL;

    switch(lyrIdx)
    {
        case 0:
        {
            return root0;
        }
        default:
        {
            return NULL;
        }
    }
}

