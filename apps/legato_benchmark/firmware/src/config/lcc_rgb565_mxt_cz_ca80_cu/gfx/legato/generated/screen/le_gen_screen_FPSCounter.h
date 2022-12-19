#ifndef LE_GEN_SCREEN_FPSCOUNTER_H
#define LE_GEN_SCREEN_FPSCOUNTER_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* FPSCounter_FPSBackground;
extern leLabelWidget* FPSCounter_FPSCounterValue;
extern leWidget* FPSCounter_FPSSideContainer;
extern leButtonWidget* FPSCounter_FPSUpdateValue;
extern leLabelWidget* FPSCounter_FPSSizeLabel;
extern leLabelWidget* FPSCounter_FPSStringSize;
extern leButtonWidget* FPSCounter_FPSNextButton;
extern leLabelWidget* FPSCounter_FPSContainerTitle;
extern leButtonWidget* FPSCounter_FPSCounterSizeUp;
extern leButtonWidget* FPSCounter_FPSCounterSizeDown;
extern leLabelWidget* FPSCounter_FPSRefreshValue;
extern leLabelWidget* FPSCounter_FPSRefreshLabel;
extern leLabelWidget* FPSCounter_FPSUpdateLabel;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_FPSCounter_FPSNextButton_OnPressed(leButtonWidget* btn);
void event_FPSCounter_FPSCounterSizeUp_OnPressed(leButtonWidget* btn);
void event_FPSCounter_FPSCounterSizeDown_OnPressed(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_FPSCounter(void); // called when Legato is initialized
leResult screenShow_FPSCounter(void); // called when screen is shown
void screenHide_FPSCounter(void); // called when screen is hidden
void screenDestroy_FPSCounter(void); // called when Legato is destroyed
void screenUpdate_FPSCounter(void); // called when Legato is updating

leWidget* screenGetRoot_FPSCounter(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void FPSCounter_OnShow(void); // called when this screen is shown
void FPSCounter_OnHide(void); // called when this screen is hidden
void FPSCounter_OnUpdate(void); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_FPSCOUNTER_H
