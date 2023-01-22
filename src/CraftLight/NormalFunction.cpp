#include "NormalFunction.h"

#ifdef LoggingEnabled
    #define LOGBUTTONEVENT(buttonName, eventType) \
    LOG(buttonName); \
    LOG(" button"); \
    switch(eventType) \
    { \
      case DPadController::ButtonClicked: LOGLN(" was clicked");break; \
      case DPadController::ButtonDoubleClicked: LOGLN(" was double clicked");break; \
      case DPadController::ButtonLongPressed: LOGLN(" was long pressed");break; \
      default: LOGLN("??"); \
    }
#else
    #define LOGBUTTONEVENT(buttonName, eventType)
#endif

NormalFunction::NormalFunction(Adafruit_NeoPixel& pixels) : pixels(pixels)
{
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