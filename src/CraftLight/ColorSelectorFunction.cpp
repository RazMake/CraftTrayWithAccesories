#include "ColorSelectorFunction.h"

#ifdef LoggingEnabled
    #define LOGBUTTONEVENT(buttonName, eventType) \
    LOG(buttonName); \
    LOG(" button"); \
    switch(eventType) \
    { \
      case DPadController::ButtonClicked: LOG(" was clicked");break; \
      case DPadController::ButtonDoubleClicked: LOG(" was double clicked");break; \
      case DPadController::ButtonLongPressed: LOG(" was long pressed");break; \
      default: LOG(" ??"); \
    } \
    LOGLN(" in ColorSelectorFunction app");
#else
    #define LOGBUTTONEVENT(buttonName, eventType)
#endif

ColorSelectorFunction::ColorSelectorFunction(Adafruit_NeoPixel& pixels) : pixels(pixels)
{
}

void ColorSelectorFunction::activate()
{
  LOGLN("ColorSelectorFunction is active");
}

void ColorSelectorFunction::UpButtonEvent(const char eventType)
{
  LOGBUTTONEVENT("Up", eventType);
}

void ColorSelectorFunction::DownButtonEvent(const char eventType)
{
  LOGBUTTONEVENT("Down", eventType);
}

void ColorSelectorFunction::LeftButtonEvent(const char eventType)
{
  LOGBUTTONEVENT("Left", eventType);
}

void ColorSelectorFunction::RightButtonEvent(const char eventType)
{
  LOGBUTTONEVENT("Right", eventType);
}

void ColorSelectorFunction::CenterButtonEvent(const char eventType)
{
  LOGBUTTONEVENT("Center", eventType);
}

void ColorSelectorFunction::RotaryEncoderEvent(const int delta)
{
    LOG("Rotary ENC: Delta = ");
    LOGLN(delta);
}