#include "gfx/legato/generated/screen/le_gen_screen_FPSImages.h"

// screen member widget declarations
static leWidget* root0;

leWidget* FPSImages_ImageBackground;
leImageWidget* FPSImages_ImageRenderArea;
leWidget* FPSImages_ImageSideContainer;
leButtonWidget* FPSImages_ImageUpdateValue;
leButtonWidget* FPSImages_ImageTypeNextButton;
leButtonWidget* FPSImages_ImageTypePrevButton;
leLabelWidget* FPSImages_ImageTypeValue;
leLabelWidget* FPSImages_ImageTypeLabel;
leLabelWidget* FPSImages_ImageSizeValue;
leLabelWidget* FPSImages_ImageSizeLabel;
leButtonWidget* FPSImages_ImageSizeUpButton;
leButtonWidget* FPSImages_ImageSizeDownButton;
leButtonWidget* FPSImages_ImageNextButton;
leLabelWidget* FPSImages_ImageContainerTitle;
leLabelWidget* FPSImages_ImageRefreshValue;
leLabelWidget* FPSImages_ImageRefreshLabel;
leLabelWidget* FPSImages_ImageUpdateLabel;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_FPSImages(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_FPSImages(void)
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

    FPSImages_ImageBackground = leWidget_New();
    FPSImages_ImageBackground->fn->setPosition(FPSImages_ImageBackground, 0, 0);
    FPSImages_ImageBackground->fn->setSize(FPSImages_ImageBackground, 480, 272);
    FPSImages_ImageBackground->fn->setScheme(FPSImages_ImageBackground, &WhiteFillScheme);
    root0->fn->addChild(root0, (leWidget*)FPSImages_ImageBackground);

    FPSImages_ImageRenderArea = leImageWidget_New();
    FPSImages_ImageRenderArea->fn->setPosition(FPSImages_ImageRenderArea, 0, 0);
    FPSImages_ImageRenderArea->fn->setSize(FPSImages_ImageRenderArea, 480, 272);
    FPSImages_ImageRenderArea->fn->setBackgroundType(FPSImages_ImageRenderArea, LE_WIDGET_BACKGROUND_NONE);
    FPSImages_ImageRenderArea->fn->setBorderType(FPSImages_ImageRenderArea, LE_WIDGET_BORDER_NONE);
    FPSImages_ImageRenderArea->fn->setHAlignment(FPSImages_ImageRenderArea, LE_HALIGN_LEFT);
    FPSImages_ImageRenderArea->fn->setVAlignment(FPSImages_ImageRenderArea, LE_VALIGN_TOP);
    root0->fn->addChild(root0, (leWidget*)FPSImages_ImageRenderArea);

    FPSImages_ImageSideContainer = leWidget_New();
    FPSImages_ImageSideContainer->fn->setPosition(FPSImages_ImageSideContainer, 359, 8);
    FPSImages_ImageSideContainer->fn->setSize(FPSImages_ImageSideContainer, 113, 260);
    FPSImages_ImageSideContainer->fn->setScheme(FPSImages_ImageSideContainer, &WhiteBackgroundScheme);
    FPSImages_ImageSideContainer->fn->setBackgroundType(FPSImages_ImageSideContainer, LE_WIDGET_BACKGROUND_NONE);
    FPSImages_ImageSideContainer->fn->setBorderType(FPSImages_ImageSideContainer, LE_WIDGET_BORDER_LINE);
    root0->fn->addChild(root0, (leWidget*)FPSImages_ImageSideContainer);

    FPSImages_ImageUpdateValue = leButtonWidget_New();
    FPSImages_ImageUpdateValue->fn->setPosition(FPSImages_ImageUpdateValue, 5, 39);
    FPSImages_ImageUpdateValue->fn->setSize(FPSImages_ImageUpdateValue, 107, 31);
    FPSImages_ImageUpdateValue->fn->setBackgroundType(FPSImages_ImageUpdateValue, LE_WIDGET_BACKGROUND_NONE);
    FPSImages_ImageUpdateValue->fn->setToggleable(FPSImages_ImageUpdateValue, LE_TRUE);
    FPSImages_ImageUpdateValue->fn->setString(FPSImages_ImageUpdateValue, (leString*)&string_NumsLittle);
    FPSImages_ImageSideContainer->fn->addChild(FPSImages_ImageSideContainer, (leWidget*)FPSImages_ImageUpdateValue);

    FPSImages_ImageTypeNextButton = leButtonWidget_New();
    FPSImages_ImageTypeNextButton->fn->setPosition(FPSImages_ImageTypeNextButton, 57, 192);
    FPSImages_ImageTypeNextButton->fn->setSize(FPSImages_ImageTypeNextButton, 55, 30);
    FPSImages_ImageTypeNextButton->fn->setBackgroundType(FPSImages_ImageTypeNextButton, LE_WIDGET_BACKGROUND_NONE);
    FPSImages_ImageTypeNextButton->fn->setString(FPSImages_ImageTypeNextButton, (leString*)&string_NextSymbol);
    FPSImages_ImageTypeNextButton->fn->setPressedEventCallback(FPSImages_ImageTypeNextButton, event_FPSImages_ImageTypeNextButton_OnPressed);
    FPSImages_ImageSideContainer->fn->addChild(FPSImages_ImageSideContainer, (leWidget*)FPSImages_ImageTypeNextButton);

    FPSImages_ImageTypePrevButton = leButtonWidget_New();
    FPSImages_ImageTypePrevButton->fn->setPosition(FPSImages_ImageTypePrevButton, 1, 192);
    FPSImages_ImageTypePrevButton->fn->setSize(FPSImages_ImageTypePrevButton, 55, 30);
    FPSImages_ImageTypePrevButton->fn->setBackgroundType(FPSImages_ImageTypePrevButton, LE_WIDGET_BACKGROUND_NONE);
    FPSImages_ImageTypePrevButton->fn->setString(FPSImages_ImageTypePrevButton, (leString*)&string_Previous);
    FPSImages_ImageTypePrevButton->fn->setPressedEventCallback(FPSImages_ImageTypePrevButton, event_FPSImages_ImageTypePrevButton_OnPressed);
    FPSImages_ImageSideContainer->fn->addChild(FPSImages_ImageSideContainer, (leWidget*)FPSImages_ImageTypePrevButton);

    FPSImages_ImageTypeValue = leLabelWidget_New();
    FPSImages_ImageTypeValue->fn->setPosition(FPSImages_ImageTypeValue, 38, 168);
    FPSImages_ImageTypeValue->fn->setSize(FPSImages_ImageTypeValue, 74, 23);
    FPSImages_ImageTypeValue->fn->setBackgroundType(FPSImages_ImageTypeValue, LE_WIDGET_BACKGROUND_NONE);
    FPSImages_ImageTypeValue->fn->setString(FPSImages_ImageTypeValue, (leString*)&string_NumsTiny);
    FPSImages_ImageSideContainer->fn->addChild(FPSImages_ImageSideContainer, (leWidget*)FPSImages_ImageTypeValue);

    FPSImages_ImageTypeLabel = leLabelWidget_New();
    FPSImages_ImageTypeLabel->fn->setPosition(FPSImages_ImageTypeLabel, 4, 168);
    FPSImages_ImageTypeLabel->fn->setSize(FPSImages_ImageTypeLabel, 39, 19);
    FPSImages_ImageTypeLabel->fn->setBackgroundType(FPSImages_ImageTypeLabel, LE_WIDGET_BACKGROUND_NONE);
    FPSImages_ImageTypeLabel->fn->setString(FPSImages_ImageTypeLabel, (leString*)&string_ImageType);
    FPSImages_ImageSideContainer->fn->addChild(FPSImages_ImageSideContainer, (leWidget*)FPSImages_ImageTypeLabel);

    FPSImages_ImageSizeValue = leLabelWidget_New();
    FPSImages_ImageSizeValue->fn->setPosition(FPSImages_ImageSizeValue, 35, 112);
    FPSImages_ImageSizeValue->fn->setSize(FPSImages_ImageSizeValue, 75, 23);
    FPSImages_ImageSizeValue->fn->setBackgroundType(FPSImages_ImageSizeValue, LE_WIDGET_BACKGROUND_NONE);
    FPSImages_ImageSizeValue->fn->setString(FPSImages_ImageSizeValue, (leString*)&string_NumsTiny);
    FPSImages_ImageSideContainer->fn->addChild(FPSImages_ImageSideContainer, (leWidget*)FPSImages_ImageSizeValue);

    FPSImages_ImageSizeLabel = leLabelWidget_New();
    FPSImages_ImageSizeLabel->fn->setPosition(FPSImages_ImageSizeLabel, 4, 113);
    FPSImages_ImageSizeLabel->fn->setSize(FPSImages_ImageSizeLabel, 33, 19);
    FPSImages_ImageSizeLabel->fn->setBackgroundType(FPSImages_ImageSizeLabel, LE_WIDGET_BACKGROUND_NONE);
    FPSImages_ImageSizeLabel->fn->setString(FPSImages_ImageSizeLabel, (leString*)&string_Size);
    FPSImages_ImageSideContainer->fn->addChild(FPSImages_ImageSideContainer, (leWidget*)FPSImages_ImageSizeLabel);

    FPSImages_ImageSizeUpButton = leButtonWidget_New();
    FPSImages_ImageSizeUpButton->fn->setPosition(FPSImages_ImageSizeUpButton, 57, 136);
    FPSImages_ImageSizeUpButton->fn->setSize(FPSImages_ImageSizeUpButton, 55, 30);
    FPSImages_ImageSizeUpButton->fn->setBackgroundType(FPSImages_ImageSizeUpButton, LE_WIDGET_BACKGROUND_NONE);
    FPSImages_ImageSizeUpButton->fn->setString(FPSImages_ImageSizeUpButton, (leString*)&string_Plus);
    FPSImages_ImageSizeUpButton->fn->setPressedEventCallback(FPSImages_ImageSizeUpButton, event_FPSImages_ImageSizeUpButton_OnPressed);
    FPSImages_ImageSideContainer->fn->addChild(FPSImages_ImageSideContainer, (leWidget*)FPSImages_ImageSizeUpButton);

    FPSImages_ImageSizeDownButton = leButtonWidget_New();
    FPSImages_ImageSizeDownButton->fn->setPosition(FPSImages_ImageSizeDownButton, 1, 136);
    FPSImages_ImageSizeDownButton->fn->setSize(FPSImages_ImageSizeDownButton, 55, 30);
    FPSImages_ImageSizeDownButton->fn->setBackgroundType(FPSImages_ImageSizeDownButton, LE_WIDGET_BACKGROUND_NONE);
    FPSImages_ImageSizeDownButton->fn->setString(FPSImages_ImageSizeDownButton, (leString*)&string_Minus);
    FPSImages_ImageSizeDownButton->fn->setPressedEventCallback(FPSImages_ImageSizeDownButton, event_FPSImages_ImageSizeDownButton_OnPressed);
    FPSImages_ImageSideContainer->fn->addChild(FPSImages_ImageSideContainer, (leWidget*)FPSImages_ImageSizeDownButton);

    FPSImages_ImageNextButton = leButtonWidget_New();
    FPSImages_ImageNextButton->fn->setPosition(FPSImages_ImageNextButton, 57, 226);
    FPSImages_ImageNextButton->fn->setSize(FPSImages_ImageNextButton, 55, 30);
    FPSImages_ImageNextButton->fn->setBackgroundType(FPSImages_ImageNextButton, LE_WIDGET_BACKGROUND_NONE);
    FPSImages_ImageNextButton->fn->setString(FPSImages_ImageNextButton, (leString*)&string_Next);
    FPSImages_ImageNextButton->fn->setPressedEventCallback(FPSImages_ImageNextButton, event_FPSImages_ImageNextButton_OnPressed);
    FPSImages_ImageSideContainer->fn->addChild(FPSImages_ImageSideContainer, (leWidget*)FPSImages_ImageNextButton);

    FPSImages_ImageContainerTitle = leLabelWidget_New();
    FPSImages_ImageContainerTitle->fn->setPosition(FPSImages_ImageContainerTitle, 0, 2);
    FPSImages_ImageContainerTitle->fn->setSize(FPSImages_ImageContainerTitle, 111, 25);
    FPSImages_ImageContainerTitle->fn->setBackgroundType(FPSImages_ImageContainerTitle, LE_WIDGET_BACKGROUND_NONE);
    FPSImages_ImageContainerTitle->fn->setHAlignment(FPSImages_ImageContainerTitle, LE_HALIGN_CENTER);
    FPSImages_ImageContainerTitle->fn->setString(FPSImages_ImageContainerTitle, (leString*)&string_ImageRendering);
    FPSImages_ImageSideContainer->fn->addChild(FPSImages_ImageSideContainer, (leWidget*)FPSImages_ImageContainerTitle);

    FPSImages_ImageRefreshValue = leLabelWidget_New();
    FPSImages_ImageRefreshValue->fn->setPosition(FPSImages_ImageRefreshValue, 7, 89);
    FPSImages_ImageRefreshValue->fn->setSize(FPSImages_ImageRefreshValue, 101, 24);
    FPSImages_ImageRefreshValue->fn->setBackgroundType(FPSImages_ImageRefreshValue, LE_WIDGET_BACKGROUND_NONE);
    FPSImages_ImageRefreshValue->fn->setHAlignment(FPSImages_ImageRefreshValue, LE_HALIGN_CENTER);
    FPSImages_ImageRefreshValue->fn->setString(FPSImages_ImageRefreshValue, (leString*)&string_NumsLittle);
    FPSImages_ImageSideContainer->fn->addChild(FPSImages_ImageSideContainer, (leWidget*)FPSImages_ImageRefreshValue);

    FPSImages_ImageRefreshLabel = leLabelWidget_New();
    FPSImages_ImageRefreshLabel->fn->setPosition(FPSImages_ImageRefreshLabel, 1, 68);
    FPSImages_ImageRefreshLabel->fn->setSize(FPSImages_ImageRefreshLabel, 109, 18);
    FPSImages_ImageRefreshLabel->fn->setBackgroundType(FPSImages_ImageRefreshLabel, LE_WIDGET_BACKGROUND_NONE);
    FPSImages_ImageRefreshLabel->fn->setString(FPSImages_ImageRefreshLabel, (leString*)&string_RefreshRate);
    FPSImages_ImageSideContainer->fn->addChild(FPSImages_ImageSideContainer, (leWidget*)FPSImages_ImageRefreshLabel);

    FPSImages_ImageUpdateLabel = leLabelWidget_New();
    FPSImages_ImageUpdateLabel->fn->setPosition(FPSImages_ImageUpdateLabel, 1, 22);
    FPSImages_ImageUpdateLabel->fn->setSize(FPSImages_ImageUpdateLabel, 110, 19);
    FPSImages_ImageUpdateLabel->fn->setBackgroundType(FPSImages_ImageUpdateLabel, LE_WIDGET_BACKGROUND_NONE);
    FPSImages_ImageUpdateLabel->fn->setString(FPSImages_ImageUpdateLabel, (leString*)&string_FPS);
    FPSImages_ImageSideContainer->fn->addChild(FPSImages_ImageSideContainer, (leWidget*)FPSImages_ImageUpdateLabel);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    FPSImages_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_FPSImages(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);

    FPSImages_OnUpdate(); // raise event
}

void screenHide_FPSImages(void)
{
    FPSImages_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    FPSImages_ImageBackground = NULL;
    FPSImages_ImageRenderArea = NULL;
    FPSImages_ImageSideContainer = NULL;
    FPSImages_ImageUpdateValue = NULL;
    FPSImages_ImageTypeNextButton = NULL;
    FPSImages_ImageTypePrevButton = NULL;
    FPSImages_ImageTypeValue = NULL;
    FPSImages_ImageTypeLabel = NULL;
    FPSImages_ImageSizeValue = NULL;
    FPSImages_ImageSizeLabel = NULL;
    FPSImages_ImageSizeUpButton = NULL;
    FPSImages_ImageSizeDownButton = NULL;
    FPSImages_ImageNextButton = NULL;
    FPSImages_ImageContainerTitle = NULL;
    FPSImages_ImageRefreshValue = NULL;
    FPSImages_ImageRefreshLabel = NULL;
    FPSImages_ImageUpdateLabel = NULL;


    showing = LE_FALSE;
}

void screenDestroy_FPSImages(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_FPSImages(uint32_t lyrIdx)
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

