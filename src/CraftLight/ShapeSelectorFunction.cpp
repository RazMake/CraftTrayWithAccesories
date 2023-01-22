#include "ShapeSelectorFunction.h"

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
    LOGLN(" in ShapeSelector app");
#else
    #define LOGBUTTONEVENT(buttonName, eventType)
#endif

ShapeSelectorFunction::ShapeSelectorFunction(Adafruit_NeoPixel& pixels) : pixels(pixels)
{
}

void ShapeSelectorFunction::activate()
{
  LOGLN("ShapeSelectorFunction is active");
}

void ShapeSelectorFunction::UpButtonEvent(const char eventType)
{
  LOGBUTTONEVENT("Up", eventType);
}

void ShapeSelectorFunction::DownButtonEvent(const char eventType)
{
  LOGBUTTONEVENT("Down", eventType);
}

void ShapeSelectorFunction::LeftButtonEvent(const char eventType)
{
  LOGBUTTONEVENT("Left", eventType);
}

void ShapeSelectorFunction::RightButtonEvent(const char eventType)
{
  LOGBUTTONEVENT("Right", eventType);
}

void ShapeSelectorFunction::CenterButtonEvent(const char eventType)
{
  LOGBUTTONEVENT("Center", eventType);
}

void ShapeSelectorFunction::RotaryEncoderEvent(const int delta)
{
    LOG("Rotary ENC: Delta = ");
    LOGLN(delta);
}