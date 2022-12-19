#include "gfx/legato/generated/screen/le_gen_screen_FPSMotion.h"

// screen member widget declarations
static leWidget* root0;

leWidget* FPSMotion_MotionBackground;
leRectangleWidget* FPSMotion_RectMotionWidget10;
leRectangleWidget* FPSMotion_RectMotionWidget9;
leRectangleWidget* FPSMotion_RectMotionWidget8;
leRectangleWidget* FPSMotion_RectMotionWidget7;
leRectangleWidget* FPSMotion_RectMotionWidget6;
leRectangleWidget* FPSMotion_RectMotionWidget5;
leRectangleWidget* FPSMotion_RectMotionWidget4;
leRectangleWidget* FPSMotion_RectMotionWidget3;
leRectangleWidget* FPSMotion_RectMotionWidget2;
leRectangleWidget* FPSMotion_RectMotionWidget1;
leWidget* FPSMotion_MotionSideContainer;
leButtonWidget* FPSMotion_MotionUpdateValue;
leButtonWidget* FPSMotion_MotionSizeUpButton;
leButtonWidget* FPSMotion_MotionSizeDownButton;
leLabelWidget* FPSMotion_MotionRectSizeValue;
leLabelWidget* FPSMotion_MotionRectSizeLabel;
leLabelWidget* FPSMotion_MotionRectCount;
leLabelWidget* FPSMotion_MotionNumLabel;
leButtonWidget* FPSMotion_MotionPlusButton;
leButtonWidget* FPSMotion_MotionMinusButton;
leButtonWidget* FPSMotion_MotionNextButton;
leLabelWidget* FPSMotion_MotionContainerTitle;
leLabelWidget* FPSMotion_MotionRefreshValue;
leLabelWidget* FPSMotion_MotionRefreshLabel;
leLabelWidget* FPSMotion_MotionUpdateLabel;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_FPSMotion(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_FPSMotion(void)
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

    FPSMotion_MotionBackground = leWidget_New();
    FPSMotion_MotionBackground->fn->setPosition(FPSMotion_MotionBackground, 0, 0);
    FPSMotion_MotionBackground->fn->setSize(FPSMotion_MotionBackground, 480, 272);
    FPSMotion_MotionBackground->fn->setScheme(FPSMotion_MotionBackground, &LightGreenBackgroundScheme);
    root0->fn->addChild(root0, (leWidget*)FPSMotion_MotionBackground);

    FPSMotion_RectMotionWidget10 = leRectangleWidget_New();
    FPSMotion_RectMotionWidget10->fn->setPosition(FPSMotion_RectMotionWidget10, 314, 131);
    FPSMotion_RectMotionWidget10->fn->setSize(FPSMotion_RectMotionWidget10, 40, 40);
    FPSMotion_RectMotionWidget10->fn->setScheme(FPSMotion_RectMotionWidget10, &BrownFillScheme);
    FPSMotion_RectMotionWidget10->fn->setBorderType(FPSMotion_RectMotionWidget10, LE_WIDGET_BORDER_NONE);
    FPSMotion_RectMotionWidget10->fn->setThickness(FPSMotion_RectMotionWidget10, 0);
    root0->fn->addChild(root0, (leWidget*)FPSMotion_RectMotionWidget10);

    FPSMotion_RectMotionWidget9 = leRectangleWidget_New();
    FPSMotion_RectMotionWidget9->fn->setPosition(FPSMotion_RectMotionWidget9, 178, 169);
    FPSMotion_RectMotionWidget9->fn->setSize(FPSMotion_RectMotionWidget9, 40, 40);
    FPSMotion_RectMotionWidget9->fn->setScheme(FPSMotion_RectMotionWidget9, &LightBlueFillScheme);
    FPSMotion_RectMotionWidget9->fn->setBorderType(FPSMotion_RectMotionWidget9, LE_WIDGET_BORDER_NONE);
    FPSMotion_RectMotionWidget9->fn->setThickness(FPSMotion_RectMotionWidget9, 0);
    root0->fn->addChild(root0, (leWidget*)FPSMotion_RectMotionWidget9);

    FPSMotion_RectMotionWidget8 = leRectangleWidget_New();
    FPSMotion_RectMotionWidget8->fn->setPosition(FPSMotion_RectMotionWidget8, 193, 3);
    FPSMotion_RectMotionWidget8->fn->setSize(FPSMotion_RectMotionWidget8, 40, 40);
    FPSMotion_RectMotionWidget8->fn->setScheme(FPSMotion_RectMotionWidget8, &PurpleFillScheme);
    FPSMotion_RectMotionWidget8->fn->setBorderType(FPSMotion_RectMotionWidget8, LE_WIDGET_BORDER_NONE);
    FPSMotion_RectMotionWidget8->fn->setThickness(FPSMotion_RectMotionWidget8, 0);
    root0->fn->addChild(root0, (leWidget*)FPSMotion_RectMotionWidget8);

    FPSMotion_RectMotionWidget7 = leRectangleWidget_New();
    FPSMotion_RectMotionWidget7->fn->setPosition(FPSMotion_RectMotionWidget7, 155, 70);
    FPSMotion_RectMotionWidget7->fn->setSize(FPSMotion_RectMotionWidget7, 40, 40);
    FPSMotion_RectMotionWidget7->fn->setScheme(FPSMotion_RectMotionWidget7, &PinkFillScheme);
    FPSMotion_RectMotionWidget7->fn->setBorderType(FPSMotion_RectMotionWidget7, LE_WIDGET_BORDER_NONE);
    FPSMotion_RectMotionWidget7->fn->setThickness(FPSMotion_RectMotionWidget7, 0);
    root0->fn->addChild(root0, (leWidget*)FPSMotion_RectMotionWidget7);

    FPSMotion_RectMotionWidget6 = leRectangleWidget_New();
    FPSMotion_RectMotionWidget6->fn->setPosition(FPSMotion_RectMotionWidget6, 98, 24);
    FPSMotion_RectMotionWidget6->fn->setSize(FPSMotion_RectMotionWidget6, 40, 40);
    FPSMotion_RectMotionWidget6->fn->setScheme(FPSMotion_RectMotionWidget6, &OrangeFillScheme);
    FPSMotion_RectMotionWidget6->fn->setBorderType(FPSMotion_RectMotionWidget6, LE_WIDGET_BORDER_NONE);
    FPSMotion_RectMotionWidget6->fn->setThickness(FPSMotion_RectMotionWidget6, 0);
    root0->fn->addChild(root0, (leWidget*)FPSMotion_RectMotionWidget6);

    FPSMotion_RectMotionWidget5 = leRectangleWidget_New();
    FPSMotion_RectMotionWidget5->fn->setPosition(FPSMotion_RectMotionWidget5, 197, 101);
    FPSMotion_RectMotionWidget5->fn->setSize(FPSMotion_RectMotionWidget5, 40, 40);
    FPSMotion_RectMotionWidget5->fn->setScheme(FPSMotion_RectMotionWidget5, &BlueFillScheme);
    FPSMotion_RectMotionWidget5->fn->setBorderType(FPSMotion_RectMotionWidget5, LE_WIDGET_BORDER_NONE);
    FPSMotion_RectMotionWidget5->fn->setThickness(FPSMotion_RectMotionWidget5, 0);
    root0->fn->addChild(root0, (leWidget*)FPSMotion_RectMotionWidget5);

    FPSMotion_RectMotionWidget4 = leRectangleWidget_New();
    FPSMotion_RectMotionWidget4->fn->setPosition(FPSMotion_RectMotionWidget4, 264, 79);
    FPSMotion_RectMotionWidget4->fn->setSize(FPSMotion_RectMotionWidget4, 40, 40);
    FPSMotion_RectMotionWidget4->fn->setScheme(FPSMotion_RectMotionWidget4, &YellowFillScheme);
    FPSMotion_RectMotionWidget4->fn->setBorderType(FPSMotion_RectMotionWidget4, LE_WIDGET_BORDER_NONE);
    FPSMotion_RectMotionWidget4->fn->setThickness(FPSMotion_RectMotionWidget4, 0);
    root0->fn->addChild(root0, (leWidget*)FPSMotion_RectMotionWidget4);

    FPSMotion_RectMotionWidget3 = leRectangleWidget_New();
    FPSMotion_RectMotionWidget3->fn->setPosition(FPSMotion_RectMotionWidget3, 84, 185);
    FPSMotion_RectMotionWidget3->fn->setSize(FPSMotion_RectMotionWidget3, 40, 40);
    FPSMotion_RectMotionWidget3->fn->setScheme(FPSMotion_RectMotionWidget3, &WhiteFillScheme);
    FPSMotion_RectMotionWidget3->fn->setBorderType(FPSMotion_RectMotionWidget3, LE_WIDGET_BORDER_NONE);
    FPSMotion_RectMotionWidget3->fn->setThickness(FPSMotion_RectMotionWidget3, 0);
    root0->fn->addChild(root0, (leWidget*)FPSMotion_RectMotionWidget3);

    FPSMotion_RectMotionWidget2 = leRectangleWidget_New();
    FPSMotion_RectMotionWidget2->fn->setPosition(FPSMotion_RectMotionWidget2, 286, 206);
    FPSMotion_RectMotionWidget2->fn->setSize(FPSMotion_RectMotionWidget2, 40, 40);
    FPSMotion_RectMotionWidget2->fn->setScheme(FPSMotion_RectMotionWidget2, &RedFillScheme);
    FPSMotion_RectMotionWidget2->fn->setBorderType(FPSMotion_RectMotionWidget2, LE_WIDGET_BORDER_NONE);
    FPSMotion_RectMotionWidget2->fn->setThickness(FPSMotion_RectMotionWidget2, 0);
    root0->fn->addChild(root0, (leWidget*)FPSMotion_RectMotionWidget2);

    FPSMotion_RectMotionWidget1 = leRectangleWidget_New();
    FPSMotion_RectMotionWidget1->fn->setPosition(FPSMotion_RectMotionWidget1, 9, 118);
    FPSMotion_RectMotionWidget1->fn->setSize(FPSMotion_RectMotionWidget1, 40, 40);
    FPSMotion_RectMotionWidget1->fn->setScheme(FPSMotion_RectMotionWidget1, &LightPinkFillScheme);
    FPSMotion_RectMotionWidget1->fn->setBorderType(FPSMotion_RectMotionWidget1, LE_WIDGET_BORDER_NONE);
    FPSMotion_RectMotionWidget1->fn->setThickness(FPSMotion_RectMotionWidget1, 0);
    root0->fn->addChild(root0, (leWidget*)FPSMotion_RectMotionWidget1);

    FPSMotion_MotionSideContainer = leWidget_New();
    FPSMotion_MotionSideContainer->fn->setPosition(FPSMotion_MotionSideContainer, 359, 8);
    FPSMotion_MotionSideContainer->fn->setSize(FPSMotion_MotionSideContainer, 113, 260);
    FPSMotion_MotionSideContainer->fn->setScheme(FPSMotion_MotionSideContainer, &WhiteBackgroundScheme);
    FPSMotion_MotionSideContainer->fn->setBackgroundType(FPSMotion_MotionSideContainer, LE_WIDGET_BACKGROUND_NONE);
    FPSMotion_MotionSideContainer->fn->setBorderType(FPSMotion_MotionSideContainer, LE_WIDGET_BORDER_LINE);
    root0->fn->addChild(root0, (leWidget*)FPSMotion_MotionSideContainer);

    FPSMotion_MotionUpdateValue = leButtonWidget_New();
    FPSMotion_MotionUpdateValue->fn->setPosition(FPSMotion_MotionUpdateValue, 4, 39);
    FPSMotion_MotionUpdateValue->fn->setSize(FPSMotion_MotionUpdateValue, 105, 30);
    FPSMotion_MotionUpdateValue->fn->setBackgroundType(FPSMotion_MotionUpdateValue, LE_WIDGET_BACKGROUND_NONE);
    FPSMotion_MotionUpdateValue->fn->setToggleable(FPSMotion_MotionUpdateValue, LE_TRUE);
    FPSMotion_MotionUpdateValue->fn->setString(FPSMotion_MotionUpdateValue, (leString*)&string_NumsLittle);
    FPSMotion_MotionSideContainer->fn->addChild(FPSMotion_MotionSideContainer, (leWidget*)FPSMotion_MotionUpdateValue);

    FPSMotion_MotionSizeUpButton = leButtonWidget_New();
    FPSMotion_MotionSizeUpButton->fn->setPosition(FPSMotion_MotionSizeUpButton, 57, 184);
    FPSMotion_MotionSizeUpButton->fn->setSize(FPSMotion_MotionSizeUpButton, 55, 30);
    FPSMotion_MotionSizeUpButton->fn->setBackgroundType(FPSMotion_MotionSizeUpButton, LE_WIDGET_BACKGROUND_NONE);
    FPSMotion_MotionSizeUpButton->fn->setString(FPSMotion_MotionSizeUpButton, (leString*)&string_Plus);
    FPSMotion_MotionSizeUpButton->fn->setPressedEventCallback(FPSMotion_MotionSizeUpButton, event_FPSMotion_MotionSizeUpButton_OnPressed);
    FPSMotion_MotionSideContainer->fn->addChild(FPSMotion_MotionSideContainer, (leWidget*)FPSMotion_MotionSizeUpButton);

    FPSMotion_MotionSizeDownButton = leButtonWidget_New();
    FPSMotion_MotionSizeDownButton->fn->setPosition(FPSMotion_MotionSizeDownButton, 1, 184);
    FPSMotion_MotionSizeDownButton->fn->setSize(FPSMotion_MotionSizeDownButton, 55, 30);
    FPSMotion_MotionSizeDownButton->fn->setBackgroundType(FPSMotion_MotionSizeDownButton, LE_WIDGET_BACKGROUND_NONE);
    FPSMotion_MotionSizeDownButton->fn->setString(FPSMotion_MotionSizeDownButton, (leString*)&string_Minus);
    FPSMotion_MotionSizeDownButton->fn->setPressedEventCallback(FPSMotion_MotionSizeDownButton, event_FPSMotion_MotionSizeDownButton_OnPressed);
    FPSMotion_MotionSideContainer->fn->addChild(FPSMotion_MotionSideContainer, (leWidget*)FPSMotion_MotionSizeDownButton);

    FPSMotion_MotionRectSizeValue = leLabelWidget_New();
    FPSMotion_MotionRectSizeValue->fn->setPosition(FPSMotion_MotionRectSizeValue, 44, 167);
    FPSMotion_MotionRectSizeValue->fn->setSize(FPSMotion_MotionRectSizeValue, 62, 16);
    FPSMotion_MotionRectSizeValue->fn->setBackgroundType(FPSMotion_MotionRectSizeValue, LE_WIDGET_BACKGROUND_NONE);
    FPSMotion_MotionRectSizeValue->fn->setString(FPSMotion_MotionRectSizeValue, (leString*)&string_NumsTiny);
    FPSMotion_MotionSideContainer->fn->addChild(FPSMotion_MotionSideContainer, (leWidget*)FPSMotion_MotionRectSizeValue);

    FPSMotion_MotionRectSizeLabel = leLabelWidget_New();
    FPSMotion_MotionRectSizeLabel->fn->setPosition(FPSMotion_MotionRectSizeLabel, 2, 162);
    FPSMotion_MotionRectSizeLabel->fn->setSize(FPSMotion_MotionRectSizeLabel, 38, 22);
    FPSMotion_MotionRectSizeLabel->fn->setBackgroundType(FPSMotion_MotionRectSizeLabel, LE_WIDGET_BACKGROUND_NONE);
    FPSMotion_MotionRectSizeLabel->fn->setString(FPSMotion_MotionRectSizeLabel, (leString*)&string_Size);
    FPSMotion_MotionSideContainer->fn->addChild(FPSMotion_MotionSideContainer, (leWidget*)FPSMotion_MotionRectSizeLabel);

    FPSMotion_MotionRectCount = leLabelWidget_New();
    FPSMotion_MotionRectCount->fn->setPosition(FPSMotion_MotionRectCount, 44, 114);
    FPSMotion_MotionRectCount->fn->setSize(FPSMotion_MotionRectCount, 24, 16);
    FPSMotion_MotionRectCount->fn->setBackgroundType(FPSMotion_MotionRectCount, LE_WIDGET_BACKGROUND_NONE);
    FPSMotion_MotionRectCount->fn->setString(FPSMotion_MotionRectCount, (leString*)&string_NumsTiny);
    FPSMotion_MotionSideContainer->fn->addChild(FPSMotion_MotionSideContainer, (leWidget*)FPSMotion_MotionRectCount);

    FPSMotion_MotionNumLabel = leLabelWidget_New();
    FPSMotion_MotionNumLabel->fn->setPosition(FPSMotion_MotionNumLabel, 2, 112);
    FPSMotion_MotionNumLabel->fn->setSize(FPSMotion_MotionNumLabel, 38, 19);
    FPSMotion_MotionNumLabel->fn->setBackgroundType(FPSMotion_MotionNumLabel, LE_WIDGET_BACKGROUND_NONE);
    FPSMotion_MotionNumLabel->fn->setString(FPSMotion_MotionNumLabel, (leString*)&string_RectanglesNum);
    FPSMotion_MotionSideContainer->fn->addChild(FPSMotion_MotionSideContainer, (leWidget*)FPSMotion_MotionNumLabel);

    FPSMotion_MotionPlusButton = leButtonWidget_New();
    FPSMotion_MotionPlusButton->fn->setPosition(FPSMotion_MotionPlusButton, 57, 133);
    FPSMotion_MotionPlusButton->fn->setSize(FPSMotion_MotionPlusButton, 55, 30);
    FPSMotion_MotionPlusButton->fn->setBackgroundType(FPSMotion_MotionPlusButton, LE_WIDGET_BACKGROUND_NONE);
    FPSMotion_MotionPlusButton->fn->setString(FPSMotion_MotionPlusButton, (leString*)&string_Plus);
    FPSMotion_MotionPlusButton->fn->setPressedEventCallback(FPSMotion_MotionPlusButton, event_FPSMotion_MotionPlusButton_OnPressed);
    FPSMotion_MotionSideContainer->fn->addChild(FPSMotion_MotionSideContainer, (leWidget*)FPSMotion_MotionPlusButton);

    FPSMotion_MotionMinusButton = leButtonWidget_New();
    FPSMotion_MotionMinusButton->fn->setPosition(FPSMotion_MotionMinusButton, 1, 133);
    FPSMotion_MotionMinusButton->fn->setSize(FPSMotion_MotionMinusButton, 55, 30);
    FPSMotion_MotionMinusButton->fn->setBackgroundType(FPSMotion_MotionMinusButton, LE_WIDGET_BACKGROUND_NONE);
    FPSMotion_MotionMinusButton->fn->setString(FPSMotion_MotionMinusButton, (leString*)&string_Minus);
    FPSMotion_MotionMinusButton->fn->setPressedEventCallback(FPSMotion_MotionMinusButton, event_FPSMotion_MotionMinusButton_OnPressed);
    FPSMotion_MotionSideContainer->fn->addChild(FPSMotion_MotionSideContainer, (leWidget*)FPSMotion_MotionMinusButton);

    FPSMotion_MotionNextButton = leButtonWidget_New();
    FPSMotion_MotionNextButton->fn->setPosition(FPSMotion_MotionNextButton, 57, 229);
    FPSMotion_MotionNextButton->fn->setSize(FPSMotion_MotionNextButton, 55, 30);
    FPSMotion_MotionNextButton->fn->setBackgroundType(FPSMotion_MotionNextButton, LE_WIDGET_BACKGROUND_NONE);
    FPSMotion_MotionNextButton->fn->setString(FPSMotion_MotionNextButton, (leString*)&string_Next);
    FPSMotion_MotionNextButton->fn->setPressedEventCallback(FPSMotion_MotionNextButton, event_FPSMotion_MotionNextButton_OnPressed);
    FPSMotion_MotionSideContainer->fn->addChild(FPSMotion_MotionSideContainer, (leWidget*)FPSMotion_MotionNextButton);

    FPSMotion_MotionContainerTitle = leLabelWidget_New();
    FPSMotion_MotionContainerTitle->fn->setPosition(FPSMotion_MotionContainerTitle, 5, 1);
    FPSMotion_MotionContainerTitle->fn->setSize(FPSMotion_MotionContainerTitle, 103, 25);
    FPSMotion_MotionContainerTitle->fn->setBackgroundType(FPSMotion_MotionContainerTitle, LE_WIDGET_BACKGROUND_NONE);
    FPSMotion_MotionContainerTitle->fn->setHAlignment(FPSMotion_MotionContainerTitle, LE_HALIGN_CENTER);
    FPSMotion_MotionContainerTitle->fn->setString(FPSMotion_MotionContainerTitle, (leString*)&string_MotionUpdates);
    FPSMotion_MotionSideContainer->fn->addChild(FPSMotion_MotionSideContainer, (leWidget*)FPSMotion_MotionContainerTitle);

    FPSMotion_MotionRefreshValue = leLabelWidget_New();
    FPSMotion_MotionRefreshValue->fn->setPosition(FPSMotion_MotionRefreshValue, 6, 88);
    FPSMotion_MotionRefreshValue->fn->setSize(FPSMotion_MotionRefreshValue, 101, 27);
    FPSMotion_MotionRefreshValue->fn->setBackgroundType(FPSMotion_MotionRefreshValue, LE_WIDGET_BACKGROUND_NONE);
    FPSMotion_MotionRefreshValue->fn->setHAlignment(FPSMotion_MotionRefreshValue, LE_HALIGN_CENTER);
    FPSMotion_MotionRefreshValue->fn->setString(FPSMotion_MotionRefreshValue, (leString*)&string_NumsLittle);
    FPSMotion_MotionSideContainer->fn->addChild(FPSMotion_MotionSideContainer, (leWidget*)FPSMotion_MotionRefreshValue);

    FPSMotion_MotionRefreshLabel = leLabelWidget_New();
    FPSMotion_MotionRefreshLabel->fn->setPosition(FPSMotion_MotionRefreshLabel, 1, 69);
    FPSMotion_MotionRefreshLabel->fn->setSize(FPSMotion_MotionRefreshLabel, 108, 18);
    FPSMotion_MotionRefreshLabel->fn->setBackgroundType(FPSMotion_MotionRefreshLabel, LE_WIDGET_BACKGROUND_NONE);
    FPSMotion_MotionRefreshLabel->fn->setString(FPSMotion_MotionRefreshLabel, (leString*)&string_RefreshRate);
    FPSMotion_MotionSideContainer->fn->addChild(FPSMotion_MotionSideContainer, (leWidget*)FPSMotion_MotionRefreshLabel);

    FPSMotion_MotionUpdateLabel = leLabelWidget_New();
    FPSMotion_MotionUpdateLabel->fn->setPosition(FPSMotion_MotionUpdateLabel, 1, 22);
    FPSMotion_MotionUpdateLabel->fn->setSize(FPSMotion_MotionUpdateLabel, 108, 18);
    FPSMotion_MotionUpdateLabel->fn->setBackgroundType(FPSMotion_MotionUpdateLabel, LE_WIDGET_BACKGROUND_NONE);
    FPSMotion_MotionUpdateLabel->fn->setString(FPSMotion_MotionUpdateLabel, (leString*)&string_FPS);
    FPSMotion_MotionSideContainer->fn->addChild(FPSMotion_MotionSideContainer, (leWidget*)FPSMotion_MotionUpdateLabel);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    FPSMotion_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_FPSMotion(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);

    FPSMotion_OnUpdate(); // raise event
}

void screenHide_FPSMotion(void)
{
    FPSMotion_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    FPSMotion_MotionBackground = NULL;
    FPSMotion_RectMotionWidget10 = NULL;
    FPSMotion_RectMotionWidget9 = NULL;
    FPSMotion_RectMotionWidget8 = NULL;
    FPSMotion_RectMotionWidget7 = NULL;
    FPSMotion_RectMotionWidget6 = NULL;
    FPSMotion_RectMotionWidget5 = NULL;
    FPSMotion_RectMotionWidget4 = NULL;
    FPSMotion_RectMotionWidget3 = NULL;
    FPSMotion_RectMotionWidget2 = NULL;
    FPSMotion_RectMotionWidget1 = NULL;
    FPSMotion_MotionSideContainer = NULL;
    FPSMotion_MotionUpdateValue = NULL;
    FPSMotion_MotionSizeUpButton = NULL;
    FPSMotion_MotionSizeDownButton = NULL;
    FPSMotion_MotionRectSizeValue = NULL;
    FPSMotion_MotionRectSizeLabel = NULL;
    FPSMotion_MotionRectCount = NULL;
    FPSMotion_MotionNumLabel = NULL;
    FPSMotion_MotionPlusButton = NULL;
    FPSMotion_MotionMinusButton = NULL;
    FPSMotion_MotionNextButton = NULL;
    FPSMotion_MotionContainerTitle = NULL;
    FPSMotion_MotionRefreshValue = NULL;
    FPSMotion_MotionRefreshLabel = NULL;
    FPSMotion_MotionUpdateLabel = NULL;


    showing = LE_FALSE;
}

void screenDestroy_FPSMotion(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_FPSMotion(uint32_t lyrIdx)
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

