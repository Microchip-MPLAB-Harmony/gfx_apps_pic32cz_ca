#ifndef LE_GEN_SCREEN_FPSIMAGES_H
#define LE_GEN_SCREEN_FPSIMAGES_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* FPSImages_ImageBackground;
extern leImageWidget* FPSImages_ImageRenderArea;
extern leWidget* FPSImages_ImageSideContainer;
extern leButtonWidget* FPSImages_ImageUpdateValue;
extern leButtonWidget* FPSImages_ImageTypeNextButton;
extern leButtonWidget* FPSImages_ImageTypePrevButton;
extern leLabelWidget* FPSImages_ImageTypeValue;
extern leLabelWidget* FPSImages_ImageTypeLabel;
extern leLabelWidget* FPSImages_ImageSizeValue;
extern leLabelWidget* FPSImages_ImageSizeLabel;
extern leButtonWidget* FPSImages_ImageSizeUpButton;
extern leButtonWidget* FPSImages_ImageSizeDownButton;
extern leButtonWidget* FPSImages_ImageNextButton;
extern leLabelWidget* FPSImages_ImageContainerTitle;
extern leLabelWidget* FPSImages_ImageRefreshValue;
extern leLabelWidget* FPSImages_ImageRefreshLabel;
extern leLabelWidget* FPSImages_ImageUpdateLabel;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_FPSImages_ImageTypeNextButton_OnPressed(leButtonWidget* btn);
void event_FPSImages_ImageTypePrevButton_OnPressed(leButtonWidget* btn);
void event_FPSImages_ImageSizeUpButton_OnPressed(leButtonWidget* btn);
void event_FPSImages_ImageSizeDownButton_OnPressed(leButtonWidget* btn);
void event_FPSImages_ImageNextButton_OnPressed(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_FPSImages(void); // called when Legato is initialized
leResult screenShow_FPSImages(void); // called when screen is shown
void screenHide_FPSImages(void); // called when screen is hidden
void screenDestroy_FPSImages(void); // called when Legato is destroyed
void screenUpdate_FPSImages(void); // called when Legato is updating

leWidget* screenGetRoot_FPSImages(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void FPSImages_OnShow(void); // called when this screen is shown
void FPSImages_OnHide(void); // called when this screen is hidden
void FPSImages_OnUpdate(void); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_FPSIMAGES_H
