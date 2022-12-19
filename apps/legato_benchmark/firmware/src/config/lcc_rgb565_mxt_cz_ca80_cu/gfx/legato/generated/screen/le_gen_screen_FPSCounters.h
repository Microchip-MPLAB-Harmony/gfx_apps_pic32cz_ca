#ifndef LE_GEN_SCREEN_FPSCOUNTERS_H
#define LE_GEN_SCREEN_FPSCOUNTERS_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* FPSCounters_FPSBackground;
extern leLabelWidget* FPSCounters_FPSCounterValue;
extern leWidget* FPSCounters_FPSSideContainer;
extern leButtonWidget* FPSCounters_FPSUpdateValue;
extern leLabelWidget* FPSCounters_FPSSizeLabel;
extern leLabelWidget* FPSCounters_FPSStringSize;
extern leButtonWidget* FPSCounters_FPSNextButton;
extern leLabelWidget* FPSCounters_FPSContainerTitle;
extern leButtonWidget* FPSCounters_FPSCounterSizeUp;
extern leButtonWidget* FPSCounters_FPSCounterSizeDown;
extern leLabelWidget* FPSCounters_FPSRefreshValue;
extern leLabelWidget* FPSCounters_FPSRefreshLabel;
extern leLabelWidget* FPSCounters_FPSUpdateLabel;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_FPSCounters_FPSNextButton_OnPressed(leButtonWidget* btn);
void event_FPSCounters_FPSCounterSizeUp_OnPressed(leButtonWidget* btn);
void event_FPSCounters_FPSCounterSizeDown_OnPressed(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_FPSCounters(void); // called when Legato is initialized
leResult screenShow_FPSCounters(void); // called when screen is shown
void screenHide_FPSCounters(void); // called when screen is hidden
void screenDestroy_FPSCounters(void); // called when Legato is destroyed
void screenUpdate_FPSCounters(void); // called when Legato is updating

leWidget* screenGetRoot_FPSCounters(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void FPSCounters_OnShow(void); // called when this screen is shown
void FPSCounters_OnHide(void); // called when this screen is hidden
void FPSCounters_OnUpdate(void); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_FPSCOUNTERS_H
