#include "gfx/legato/generated/screen/le_gen_screen_FPSCounter.h"

// screen member widget declarations
static leWidget* root0;

leWidget* FPSCounter_FPSBackground;
leLabelWidget* FPSCounter_FPSCounterValue;
leWidget* FPSCounter_FPSSideContainer;
leButtonWidget* FPSCounter_FPSUpdateValue;
leLabelWidget* FPSCounter_FPSSizeLabel;
leLabelWidget* FPSCounter_FPSStringSize;
leButtonWidget* FPSCounter_FPSNextButton;
leLabelWidget* FPSCounter_FPSContainerTitle;
leButtonWidget* FPSCounter_FPSCounterSizeUp;
leButtonWidget* FPSCounter_FPSCounterSizeDown;
leLabelWidget* FPSCounter_FPSRefreshValue;
leLabelWidget* FPSCounter_FPSRefreshLabel;
leLabelWidget* FPSCounter_FPSUpdateLabel;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_FPSCounter(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_FPSCounter(void)
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

    FPSCounter_FPSBackground = leWidget_New();
    FPSCounter_FPSBackground->fn->setPosition(FPSCounter_FPSBackground, 0, 0);
    FPSCounter_FPSBackground->fn->setSize(FPSCounter_FPSBackground, 480, 272);
    FPSCounter_FPSBackground->fn->setScheme(FPSCounter_FPSBackground, &LightRedBackgroundScheme);
    root0->fn->addChild(root0, (leWidget*)FPSCounter_FPSBackground);

    FPSCounter_FPSCounterValue = leLabelWidget_New();
    FPSCounter_FPSCounterValue->fn->setPosition(FPSCounter_FPSCounterValue, 0, 70);
    FPSCounter_FPSCounterValue->fn->setSize(FPSCounter_FPSCounterValue, 353, 134);
    FPSCounter_FPSCounterValue->fn->setBackgroundType(FPSCounter_FPSCounterValue, LE_WIDGET_BACKGROUND_NONE);
    FPSCounter_FPSCounterValue->fn->setHAlignment(FPSCounter_FPSCounterValue, LE_HALIGN_CENTER);
    FPSCounter_FPSCounterValue->fn->setString(FPSCounter_FPSCounterValue, (leString*)&string_NumsLarge);
    root0->fn->addChild(root0, (leWidget*)FPSCounter_FPSCounterValue);

    FPSCounter_FPSSideContainer = leWidget_New();
    FPSCounter_FPSSideContainer->fn->setPosition(FPSCounter_FPSSideContainer, 359, 8);
    FPSCounter_FPSSideContainer->fn->setSize(FPSCounter_FPSSideContainer, 113, 260);
    FPSCounter_FPSSideContainer->fn->setScheme(FPSCounter_FPSSideContainer, &WhiteBackgroundScheme);
    FPSCounter_FPSSideContainer->fn->setBackgroundType(FPSCounter_FPSSideContainer, LE_WIDGET_BACKGROUND_NONE);
    FPSCounter_FPSSideContainer->fn->setBorderType(FPSCounter_FPSSideContainer, LE_WIDGET_BORDER_LINE);
    root0->fn->addChild(root0, (leWidget*)FPSCounter_FPSSideContainer);

    FPSCounter_FPSSizeLabel = leLabelWidget_New();
    FPSCounter_FPSSizeLabel->fn->setPosition(FPSCounter_FPSSizeLabel, 2, 121);
    FPSCounter_FPSSizeLabel->fn->setSize(FPSCounter_FPSSizeLabel, 64, 25);
    FPSCounter_FPSSizeLabel->fn->setBackgroundType(FPSCounter_FPSSizeLabel, LE_WIDGET_BACKGROUND_NONE);
    FPSCounter_FPSSizeLabel->fn->setString(FPSCounter_FPSSizeLabel, (leString*)&string_Size);
    FPSCounter_FPSSideContainer->fn->addChild(FPSCounter_FPSSideContainer, (leWidget*)FPSCounter_FPSSizeLabel);

    FPSCounter_FPSStringSize = leLabelWidget_New();
    FPSCounter_FPSStringSize->fn->setPosition(FPSCounter_FPSStringSize, 68, 123);
    FPSCounter_FPSStringSize->fn->setSize(FPSCounter_FPSStringSize, 24, 25);
    FPSCounter_FPSStringSize->fn->setBackgroundType(FPSCounter_FPSStringSize, LE_WIDGET_BACKGROUND_NONE);
    FPSCounter_FPSStringSize->fn->setHAlignment(FPSCounter_FPSStringSize, LE_HALIGN_CENTER);
    FPSCounter_FPSStringSize->fn->setString(FPSCounter_FPSStringSize, (leString*)&string_NumsLittle);
    FPSCounter_FPSSideContainer->fn->addChild(FPSCounter_FPSSideContainer, (leWidget*)FPSCounter_FPSStringSize);

    FPSCounter_FPSNextButton = leButtonWidget_New();
    FPSCounter_FPSNextButton->fn->setPosition(FPSCounter_FPSNextButton, 57, 229);
    FPSCounter_FPSNextButton->fn->setSize(FPSCounter_FPSNextButton, 55, 30);
    FPSCounter_FPSNextButton->fn->setBackgroundType(FPSCounter_FPSNextButton, LE_WIDGET_BACKGROUND_NONE);
    FPSCounter_FPSNextButton->fn->setString(FPSCounter_FPSNextButton, (leString*)&string_Next);
    FPSCounter_FPSNextButton->fn->setPressedEventCallback(FPSCounter_FPSNextButton, event_FPSCounter_FPSNextButton_OnPressed);
    FPSCounter_FPSSideContainer->fn->addChild(FPSCounter_FPSSideContainer, (leWidget*)FPSCounter_FPSNextButton);

    FPSCounter_FPSContainerTitle = leLabelWidget_New();
    FPSCounter_FPSContainerTitle->fn->setPosition(FPSCounter_FPSContainerTitle, 2, 2);
    FPSCounter_FPSContainerTitle->fn->setSize(FPSCounter_FPSContainerTitle, 109, 25);
    FPSCounter_FPSContainerTitle->fn->setBackgroundType(FPSCounter_FPSContainerTitle, LE_WIDGET_BACKGROUND_NONE);
    FPSCounter_FPSContainerTitle->fn->setHAlignment(FPSCounter_FPSContainerTitle, LE_HALIGN_CENTER);
    FPSCounter_FPSContainerTitle->fn->setString(FPSCounter_FPSContainerTitle, (leString*)&string_DynamicString);
    FPSCounter_FPSSideContainer->fn->addChild(FPSCounter_FPSSideContainer, (leWidget*)FPSCounter_FPSContainerTitle);

    FPSCounter_FPSCounterSizeUp = leButtonWidget_New();
    FPSCounter_FPSCounterSizeUp->fn->setPosition(FPSCounter_FPSCounterSizeUp, 57, 148);
    FPSCounter_FPSCounterSizeUp->fn->setSize(FPSCounter_FPSCounterSizeUp, 55, 30);
    FPSCounter_FPSCounterSizeUp->fn->setBackgroundType(FPSCounter_FPSCounterSizeUp, LE_WIDGET_BACKGROUND_NONE);
    FPSCounter_FPSCounterSizeUp->fn->setString(FPSCounter_FPSCounterSizeUp, (leString*)&string_Plus);
    FPSCounter_FPSCounterSizeUp->fn->setPressedEventCallback(FPSCounter_FPSCounterSizeUp, event_FPSCounter_FPSCounterSizeUp_OnPressed);
    FPSCounter_FPSSideContainer->fn->addChild(FPSCounter_FPSSideContainer, (leWidget*)FPSCounter_FPSCounterSizeUp);

    FPSCounter_FPSCounterSizeDown = leButtonWidget_New();
    FPSCounter_FPSCounterSizeDown->fn->setPosition(FPSCounter_FPSCounterSizeDown, 1, 148);
    FPSCounter_FPSCounterSizeDown->fn->setSize(FPSCounter_FPSCounterSizeDown, 55, 30);
    FPSCounter_FPSCounterSizeDown->fn->setBackgroundType(FPSCounter_FPSCounterSizeDown, LE_WIDGET_BACKGROUND_NONE);
    FPSCounter_FPSCounterSizeDown->fn->setString(FPSCounter_FPSCounterSizeDown, (leString*)&string_Minus);
    FPSCounter_FPSCounterSizeDown->fn->setPressedEventCallback(FPSCounter_FPSCounterSizeDown, event_FPSCounter_FPSCounterSizeDown_OnPressed);
    FPSCounter_FPSSideContainer->fn->addChild(FPSCounter_FPSSideContainer, (leWidget*)FPSCounter_FPSCounterSizeDown);

    FPSCounter_FPSRefreshValue = leLabelWidget_New();
    FPSCounter_FPSRefreshValue->fn->setPosition(FPSCounter_FPSRefreshValue, 4, 94);
    FPSCounter_FPSRefreshValue->fn->setSize(FPSCounter_FPSRefreshValue, 101, 28);
    FPSCounter_FPSRefreshValue->fn->setBackgroundType(FPSCounter_FPSRefreshValue, LE_WIDGET_BACKGROUND_NONE);
    FPSCounter_FPSRefreshValue->fn->setHAlignment(FPSCounter_FPSRefreshValue, LE_HALIGN_CENTER);
    FPSCounter_FPSRefreshValue->fn->setString(FPSCounter_FPSRefreshValue, (leString*)&string_NumsLittle);
    FPSCounter_FPSSideContainer->fn->addChild(FPSCounter_FPSSideContainer, (leWidget*)FPSCounter_FPSRefreshValue);

    FPSCounter_FPSRefreshLabel = leLabelWidget_New();
    FPSCounter_FPSRefreshLabel->fn->setPosition(FPSCounter_FPSRefreshLabel, 1, 72);
    FPSCounter_FPSRefreshLabel->fn->setSize(FPSCounter_FPSRefreshLabel, 109, 23);
    FPSCounter_FPSRefreshLabel->fn->setBackgroundType(FPSCounter_FPSRefreshLabel, LE_WIDGET_BACKGROUND_NONE);
    FPSCounter_FPSRefreshLabel->fn->setString(FPSCounter_FPSRefreshLabel, (leString*)&string_RefreshRate);
    FPSCounter_FPSSideContainer->fn->addChild(FPSCounter_FPSSideContainer, (leWidget*)FPSCounter_FPSRefreshLabel);

    FPSCounter_FPSUpdateLabel = leLabelWidget_New();
    FPSCounter_FPSUpdateLabel->fn->setPosition(FPSCounter_FPSUpdateLabel, 1, 22);
    FPSCounter_FPSUpdateLabel->fn->setSize(FPSCounter_FPSUpdateLabel, 106, 25);
    FPSCounter_FPSUpdateLabel->fn->setBackgroundType(FPSCounter_FPSUpdateLabel, LE_WIDGET_BACKGROUND_NONE);
    FPSCounter_FPSUpdateLabel->fn->setString(FPSCounter_FPSUpdateLabel, (leString*)&string_FPS);
    FPSCounter_FPSSideContainer->fn->addChild(FPSCounter_FPSSideContainer, (leWidget*)FPSCounter_FPSUpdateLabel);

    FPSCounter_FPSUpdateValue = leButtonWidget_New();
    FPSCounter_FPSUpdateValue->fn->setPosition(FPSCounter_FPSUpdateValue, 362, 50);
    FPSCounter_FPSUpdateValue->fn->setSize(FPSCounter_FPSUpdateValue, 107, 30);
    FPSCounter_FPSUpdateValue->fn->setBackgroundType(FPSCounter_FPSUpdateValue, LE_WIDGET_BACKGROUND_NONE);
    FPSCounter_FPSUpdateValue->fn->setToggleable(FPSCounter_FPSUpdateValue, LE_TRUE);
    FPSCounter_FPSUpdateValue->fn->setString(FPSCounter_FPSUpdateValue, (leString*)&string_NumsLittle);
    root0->fn->addChild(root0, (leWidget*)FPSCounter_FPSUpdateValue);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    FPSCounter_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_FPSCounter(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);

    FPSCounter_OnUpdate(); // raise event
}

void screenHide_FPSCounter(void)
{
    FPSCounter_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    FPSCounter_FPSBackground = NULL;
    FPSCounter_FPSCounterValue = NULL;
    FPSCounter_FPSSideContainer = NULL;
    FPSCounter_FPSUpdateValue = NULL;
    FPSCounter_FPSSizeLabel = NULL;
    FPSCounter_FPSStringSize = NULL;
    FPSCounter_FPSNextButton = NULL;
    FPSCounter_FPSContainerTitle = NULL;
    FPSCounter_FPSCounterSizeUp = NULL;
    FPSCounter_FPSCounterSizeDown = NULL;
    FPSCounter_FPSRefreshValue = NULL;
    FPSCounter_FPSRefreshLabel = NULL;
    FPSCounter_FPSUpdateLabel = NULL;


    showing = LE_FALSE;
}

void screenDestroy_FPSCounter(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_FPSCounter(uint32_t lyrIdx)
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

