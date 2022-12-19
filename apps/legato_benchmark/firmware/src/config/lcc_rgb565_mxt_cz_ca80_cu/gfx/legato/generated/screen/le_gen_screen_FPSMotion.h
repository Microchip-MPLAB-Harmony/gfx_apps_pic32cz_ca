#ifndef LE_GEN_SCREEN_FPSMOTION_H
#define LE_GEN_SCREEN_FPSMOTION_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* FPSMotion_MotionBackground;
extern leRectangleWidget* FPSMotion_RectMotionWidget10;
extern leRectangleWidget* FPSMotion_RectMotionWidget9;
extern leRectangleWidget* FPSMotion_RectMotionWidget8;
extern leRectangleWidget* FPSMotion_RectMotionWidget7;
extern leRectangleWidget* FPSMotion_RectMotionWidget6;
extern leRectangleWidget* FPSMotion_RectMotionWidget5;
extern leRectangleWidget* FPSMotion_RectMotionWidget4;
extern leRectangleWidget* FPSMotion_RectMotionWidget3;
extern leRectangleWidget* FPSMotion_RectMotionWidget2;
extern leRectangleWidget* FPSMotion_RectMotionWidget1;
extern leWidget* FPSMotion_MotionSideContainer;
extern leButtonWidget* FPSMotion_MotionUpdateValue;
extern leButtonWidget* FPSMotion_MotionSizeUpButton;
extern leButtonWidget* FPSMotion_MotionSizeDownButton;
extern leLabelWidget* FPSMotion_MotionRectSizeValue;
extern leLabelWidget* FPSMotion_MotionRectSizeLabel;
extern leLabelWidget* FPSMotion_MotionRectCount;
extern leLabelWidget* FPSMotion_MotionNumLabel;
extern leButtonWidget* FPSMotion_MotionPlusButton;
extern leButtonWidget* FPSMotion_MotionMinusButton;
extern leButtonWidget* FPSMotion_MotionNextButton;
extern leLabelWidget* FPSMotion_MotionContainerTitle;
extern leLabelWidget* FPSMotion_MotionRefreshValue;
extern leLabelWidget* FPSMotion_MotionRefreshLabel;
extern leLabelWidget* FPSMotion_MotionUpdateLabel;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_FPSMotion_MotionSizeUpButton_OnPressed(leButtonWidget* btn);
void event_FPSMotion_MotionSizeDownButton_OnPressed(leButtonWidget* btn);
void event_FPSMotion_MotionPlusButton_OnPressed(leButtonWidget* btn);
void event_FPSMotion_MotionMinusButton_OnPressed(leButtonWidget* btn);
void event_FPSMotion_MotionNextButton_OnPressed(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_FPSMotion(void); // called when Legato is initialized
leResult screenShow_FPSMotion(void); // called when screen is shown
void screenHide_FPSMotion(void); // called when screen is hidden
void screenDestroy_FPSMotion(void); // called when Legato is destroyed
void screenUpdate_FPSMotion(void); // called when Legato is updating

leWidget* screenGetRoot_FPSMotion(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void FPSMotion_OnShow(void); // called when this screen is shown
void FPSMotion_OnHide(void); // called when this screen is hidden
void FPSMotion_OnUpdate(void); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_FPSMOTION_H
