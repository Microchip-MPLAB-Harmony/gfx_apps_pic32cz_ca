#include "gfx/legato/generated/screen/le_gen_screen_FPSCounters.h"

// screen member widget declarations
static leWidget* root0;

leWidget* FPSCounters_FPSBackground;
leLabelWidget* FPSCounters_FPSCounterValue;
leWidget* FPSCounters_FPSSideContainer;
leButtonWidget* FPSCounters_FPSUpdateValue;
leLabelWidget* FPSCounters_FPSSizeLabel;
leLabelWidget* FPSCounters_FPSStringSize;
leButtonWidget* FPSCounters_FPSNextButton;
leLabelWidget* FPSCounters_FPSContainerTitle;
leButtonWidget* FPSCounters_FPSCounterSizeUp;
leButtonWidget* FPSCounters_FPSCounterSizeDown;
leLabelWidget* FPSCounters_FPSRefreshValue;
leLabelWidget* FPSCounters_FPSRefreshLabel;
leLabelWidget* FPSCounters_FPSUpdateLabel;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_FPSCounters(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_FPSCounters(void)
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

    FPSCounters_FPSBackground = leWidget_New();
    FPSCounters_FPSBackground->fn->setPosition(FPSCounters_FPSBackground, 0, 0);
    FPSCounters_FPSBackground->fn->setSize(FPSCounters_FPSBackground, 480, 272);
    FPSCounters_FPSBackground->fn->setScheme(FPSCounters_FPSBackground, &LightRedBackgroundScheme);
    root0->fn->addChild(root0, (leWidget*)FPSCounters_FPSBackground);

    FPSCounters_FPSCounterValue = leLabelWidget_New();
    FPSCounters_FPSCounterValue->fn->setPosition(FPSCounters_FPSCounterValue, 0, 70);
    FPSCounters_FPSCounterValue->fn->setSize(FPSCounters_FPSCounterValue, 353, 134);
    FPSCounters_FPSCounterValue->fn->setBackgroundType(FPSCounters_FPSCounterValue, LE_WIDGET_BACKGROUND_NONE);
    FPSCounters_FPSCounterValue->fn->setHAlignment(FPSCounters_FPSCounterValue, LE_HALIGN_CENTER);
    FPSCounters_FPSCounterValue->fn->setString(FPSCounters_FPSCounterValue, (leString*)&string_NumsLarge);
    root0->fn->addChild(root0, (leWidget*)FPSCounters_FPSCounterValue);

    FPSCounters_FPSSideContainer = leWidget_New();
    FPSCounters_FPSSideContainer->fn->setPosition(FPSCounters_FPSSideContainer, 359, 8);
    FPSCounters_FPSSideContainer->fn->setSize(FPSCounters_FPSSideContainer, 113, 260);
    FPSCounters_FPSSideContainer->fn->setScheme(FPSCounters_FPSSideContainer, &WhiteBackgroundScheme);
    FPSCounters_FPSSideContainer->fn->setBackgroundType(FPSCounters_FPSSideContainer, LE_WIDGET_BACKGROUND_NONE);
    FPSCounters_FPSSideContainer->fn->setBorderType(FPSCounters_FPSSideContainer, LE_WIDGET_BORDER_LINE);
    root0->fn->addChild(root0, (leWidget*)FPSCounters_FPSSideContainer);

    FPSCounters_FPSSizeLabel = leLabelWidget_New();
    FPSCounters_FPSSizeLabel->fn->setPosition(FPSCounters_FPSSizeLabel, 2, 121);
    FPSCounters_FPSSizeLabel->fn->setSize(FPSCounters_FPSSizeLabel, 64, 25);
    FPSCounters_FPSSizeLabel->fn->setBackgroundType(FPSCounters_FPSSizeLabel, LE_WIDGET_BACKGROUND_NONE);
    FPSCounters_FPSSizeLabel->fn->setString(FPSCounters_FPSSizeLabel, (leString*)&string_Size);
    FPSCounters_FPSSideContainer->fn->addChild(FPSCounters_FPSSideContainer, (leWidget*)FPSCounters_FPSSizeLabel);

    FPSCounters_FPSStringSize = leLabelWidget_New();
    FPSCounters_FPSStringSize->fn->setPosition(FPSCounters_FPSStringSize, 68, 123);
    FPSCounters_FPSStringSize->fn->setSize(FPSCounters_FPSStringSize, 24, 25);
    FPSCounters_FPSStringSize->fn->setBackgroundType(FPSCounters_FPSStringSize, LE_WIDGET_BACKGROUND_NONE);
    FPSCounters_FPSStringSize->fn->setHAlignment(FPSCounters_FPSStringSize, LE_HALIGN_CENTER);
    FPSCounters_FPSStringSize->fn->setString(FPSCounters_FPSStringSize, (leString*)&string_NumsLittle);
    FPSCounters_FPSSideContainer->fn->addChild(FPSCounters_FPSSideContainer, (leWidget*)FPSCounters_FPSStringSize);

    FPSCounters_FPSNextButton = leButtonWidget_New();
    FPSCounters_FPSNextButton->fn->setPosition(FPSCounters_FPSNextButton, 57, 229);
    FPSCounters_FPSNextButton->fn->setSize(FPSCounters_FPSNextButton, 55, 30);
    FPSCounters_FPSNextButton->fn->setBackgroundType(FPSCounters_FPSNextButton, LE_WIDGET_BACKGROUND_NONE);
    FPSCounters_FPSNextButton->fn->setString(FPSCounters_FPSNextButton, (leString*)&string_Next);
    FPSCounters_FPSNextButton->fn->setPressedEventCallback(FPSCounters_FPSNextButton, event_FPSCounters_FPSNextButton_OnPressed);
    FPSCounters_FPSSideContainer->fn->addChild(FPSCounters_FPSSideContainer, (leWidget*)FPSCounters_FPSNextButton);

    FPSCounters_FPSContainerTitle = leLabelWidget_New();
    FPSCounters_FPSContainerTitle->fn->setPosition(FPSCounters_FPSContainerTitle, 2, 2);
    FPSCounters_FPSContainerTitle->fn->setSize(FPSCounters_FPSContainerTitle, 109, 25);
    FPSCounters_FPSContainerTitle->fn->setBackgroundType(FPSCounters_FPSContainerTitle, LE_WIDGET_BACKGROUND_NONE);
    FPSCounters_FPSContainerTitle->fn->setHAlignment(FPSCounters_FPSContainerTitle, LE_HALIGN_CENTER);
    FPSCounters_FPSContainerTitle->fn->setString(FPSCounters_FPSContainerTitle, (leString*)&string_DynamicString);
    FPSCounters_FPSSideContainer->fn->addChild(FPSCounters_FPSSideContainer, (leWidget*)FPSCounters_FPSContainerTitle);

    FPSCounters_FPSCounterSizeUp = leButtonWidget_New();
    FPSCounters_FPSCounterSizeUp->fn->setPosition(FPSCounters_FPSCounterSizeUp, 57, 148);
    FPSCounters_FPSCounterSizeUp->fn->setSize(FPSCounters_FPSCounterSizeUp, 55, 30);
    FPSCounters_FPSCounterSizeUp->fn->setBackgroundType(FPSCounters_FPSCounterSizeUp, LE_WIDGET_BACKGROUND_NONE);
    FPSCounters_FPSCounterSizeUp->fn->setString(FPSCounters_FPSCounterSizeUp, (leString*)&string_Plus);
    FPSCounters_FPSCounterSizeUp->fn->setPressedEventCallback(FPSCounters_FPSCounterSizeUp, event_FPSCounters_FPSCounterSizeUp_OnPressed);
    FPSCounters_FPSSideContainer->fn->addChild(FPSCounters_FPSSideContainer, (leWidget*)FPSCounters_FPSCounterSizeUp);

    FPSCounters_FPSCounterSizeDown = leButtonWidget_New();
    FPSCounters_FPSCounterSizeDown->fn->setPosition(FPSCounters_FPSCounterSizeDown, 1, 148);
    FPSCounters_FPSCounterSizeDown->fn->setSize(FPSCounters_FPSCounterSizeDown, 55, 30);
    FPSCounters_FPSCounterSizeDown->fn->setBackgroundType(FPSCounters_FPSCounterSizeDown, LE_WIDGET_BACKGROUND_NONE);
    FPSCounters_FPSCounterSizeDown->fn->setString(FPSCounters_FPSCounterSizeDown, (leString*)&string_Minus);
    FPSCounters_FPSCounterSizeDown->fn->setPressedEventCallback(FPSCounters_FPSCounterSizeDown, event_FPSCounters_FPSCounterSizeDown_OnPressed);
    FPSCounters_FPSSideContainer->fn->addChild(FPSCounters_FPSSideContainer, (leWidget*)FPSCounters_FPSCounterSizeDown);

    FPSCounters_FPSRefreshValue = leLabelWidget_New();
    FPSCounters_FPSRefreshValue->fn->setPosition(FPSCounters_FPSRefreshValue, 4, 94);
    FPSCounters_FPSRefreshValue->fn->setSize(FPSCounters_FPSRefreshValue, 101, 28);
    FPSCounters_FPSRefreshValue->fn->setBackgroundType(FPSCounters_FPSRefreshValue, LE_WIDGET_BACKGROUND_NONE);
    FPSCounters_FPSRefreshValue->fn->setHAlignment(FPSCounters_FPSRefreshValue, LE_HALIGN_CENTER);
    FPSCounters_FPSRefreshValue->fn->setString(FPSCounters_FPSRefreshValue, (leString*)&string_NumsLittle);
    FPSCounters_FPSSideContainer->fn->addChild(FPSCounters_FPSSideContainer, (leWidget*)FPSCounters_FPSRefreshValue);

    FPSCounters_FPSRefreshLabel = leLabelWidget_New();
    FPSCounters_FPSRefreshLabel->fn->setPosition(FPSCounters_FPSRefreshLabel, 1, 72);
    FPSCounters_FPSRefreshLabel->fn->setSize(FPSCounters_FPSRefreshLabel, 109, 23);
    FPSCounters_FPSRefreshLabel->fn->setBackgroundType(FPSCounters_FPSRefreshLabel, LE_WIDGET_BACKGROUND_NONE);
    FPSCounters_FPSRefreshLabel->fn->setString(FPSCounters_FPSRefreshLabel, (leString*)&string_RefreshRate);
    FPSCounters_FPSSideContainer->fn->addChild(FPSCounters_FPSSideContainer, (leWidget*)FPSCounters_FPSRefreshLabel);

    FPSCounters_FPSUpdateLabel = leLabelWidget_New();
    FPSCounters_FPSUpdateLabel->fn->setPosition(FPSCounters_FPSUpdateLabel, 1, 22);
    FPSCounters_FPSUpdateLabel->fn->setSize(FPSCounters_FPSUpdateLabel, 106, 25);
    FPSCounters_FPSUpdateLabel->fn->setBackgroundType(FPSCounters_FPSUpdateLabel, LE_WIDGET_BACKGROUND_NONE);
    FPSCounters_FPSUpdateLabel->fn->setString(FPSCounters_FPSUpdateLabel, (leString*)&string_FPS);
    FPSCounters_FPSSideContainer->fn->addChild(FPSCounters_FPSSideContainer, (leWidget*)FPSCounters_FPSUpdateLabel);

    FPSCounters_FPSUpdateValue = leButtonWidget_New();
    FPSCounters_FPSUpdateValue->fn->setPosition(FPSCounters_FPSUpdateValue, 362, 50);
    FPSCounters_FPSUpdateValue->fn->setSize(FPSCounters_FPSUpdateValue, 107, 30);
    FPSCounters_FPSUpdateValue->fn->setBackgroundType(FPSCounters_FPSUpdateValue, LE_WIDGET_BACKGROUND_NONE);
    FPSCounters_FPSUpdateValue->fn->setToggleable(FPSCounters_FPSUpdateValue, LE_TRUE);
    FPSCounters_FPSUpdateValue->fn->setString(FPSCounters_FPSUpdateValue, (leString*)&string_NumsLittle);
    root0->fn->addChild(root0, (leWidget*)FPSCounters_FPSUpdateValue);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    FPSCounters_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_FPSCounters(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);

    FPSCounters_OnUpdate(); // raise event
}

void screenHide_FPSCounters(void)
{
    FPSCounters_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    FPSCounters_FPSBackground = NULL;
    FPSCounters_FPSCounterValue = NULL;
    FPSCounters_FPSSideContainer = NULL;
    FPSCounters_FPSUpdateValue = NULL;
    FPSCounters_FPSSizeLabel = NULL;
    FPSCounters_FPSStringSize = NULL;
    FPSCounters_FPSNextButton = NULL;
    FPSCounters_FPSContainerTitle = NULL;
    FPSCounters_FPSCounterSizeUp = NULL;
    FPSCounters_FPSCounterSizeDown = NULL;
    FPSCounters_FPSRefreshValue = NULL;
    FPSCounters_FPSRefreshLabel = NULL;
    FPSCounters_FPSUpdateLabel = NULL;


    showing = LE_FALSE;
}

void screenDestroy_FPSCounters(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_FPSCounters(uint32_t lyrIdx)
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

