#include "NormalFunction.h"

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
    LOGLN(" in NormalFunction app");
#else
    #define LOGBUTTONEVENT(buttonName, eventType)
#endif

NormalFunction::NormalFunction(Adafruit_NeoPixel& pixels) : pixels(pixels)
{
}

void NormalFunction::activate()
{
LOGLN("NormalFunction is active");
}

void NormalFunction::UpButtonEvent(const char eventType)
{
  LOGBUTTONEVENT("Up", eventType);
}

void NormalFunction::DownButtonEvent(const char eventType)
{
  LOGBUTTONEVENT("Down", eventType);
}

void NormalFunction::LeftButtonEvent(const char eventType)
{
  LOGBUTTONEVENT("Left", eventType);
}

void NormalFunction::RightButtonEvent(const char eventType)
{
  LOGBUTTONEVENT("Right", eventType);
}

void NormalFunction::CenterButtonEvent(const char eventType)
{
  LOGBUTTONEVENT("Center", eventType);
}

void NormalFunction::RotaryEncoderEvent(const int delta)
{
    LOG("Rotary ENC: Delta = ");
    LOGLN(delta);
}