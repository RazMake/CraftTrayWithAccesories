/// <summary>
/// This is the program, designed to run on an Arduino like controller to give the Craft Light the functionality.
/// For details, look at the description of each of the *Function.h files.
/// </summary>
#include <Adafruit_NeoPixel.h>
#include "DPadController.h"
#include "Logging.h"
#include "CraftLightFunction.h"
#include "NormalFunction.h"

// Instantiate the Neopixel library. It is used to control the RGB lights that make up the Craft Light.
// The original version uses RGB lights (not RGBW), because that is what I had available.
Adafruit_NeoPixel pixels(
  96, // The number of pixels available
      // There are two rows of LEDs, each containing X LEDs, counting starts from left most,
      // front row one.
  9,  // The digital pin used to send the commands to the LED strip
  NEO_GRB + NEO_KHZ800 // The type of LED strip being used in the Craft Light
  );

// The possible functions of the Craft Light:
NormalFunction normalFunction(pixels);

// The currently selected function:
CraftLightFunction* currentFunction = &normalFunction;

// This callback is invoked for any of the DPad controls being manipulated (all buttons and rotary encoder).
// It wires the event to the right method on the current function of the Craft Light.
// This method is passed in the constructor on the DPad controller.
void DPadEvent(const char eventType, const long eventData)
{
  switch(eventType)
  {
    case DPadController::ButtonClicked:
      switch(eventData)
      {
        case DPadController::UpButton: currentFunction->UpButtonEvent(DPadController::ButtonClicked);break;
        case DPadController::DownButton: currentFunction->DownButtonEvent(DPadController::ButtonClicked);break;
        case DPadController::LeftButton: currentFunction->LeftButtonEvent(DPadController::ButtonClicked);break;
        case DPadController::RightButton: currentFunction->RightButtonEvent(DPadController::ButtonClicked);break;
        case DPadController::CenterButton: currentFunction->CenterButtonEvent(DPadController::ButtonClicked);break;
      }
      break;

    case DPadController::ButtonDoubleClicked:
      switch(eventData)
      {
        case DPadController::UpButton: currentFunction->UpButtonEvent(DPadController::ButtonDoubleClicked);break;
        case DPadController::DownButton: currentFunction->DownButtonEvent(DPadController::ButtonDoubleClicked);break;
        case DPadController::LeftButton: currentFunction->LeftButtonEvent(DPadController::ButtonDoubleClicked);break;
        case DPadController::RightButton: currentFunction->RightButtonEvent(DPadController::ButtonDoubleClicked);break;
        case DPadController::CenterButton: currentFunction->CenterButtonEvent(DPadController::ButtonDoubleClicked);break;
      }
      break;

    case DPadController::ButtonLongPressed:
      switch(eventData)
      {
        case DPadController::UpButton: currentFunction->UpButtonEvent(DPadController::ButtonLongPressed);break;
        case DPadController::DownButton: currentFunction->DownButtonEvent(DPadController::ButtonLongPressed);break;
        case DPadController::LeftButton: currentFunction->LeftButtonEvent(DPadController::ButtonLongPressed);break;
        case DPadController::RightButton: currentFunction->RightButtonEvent(DPadController::ButtonLongPressed);break;
        case DPadController::CenterButton: currentFunction->CenterButtonEvent(DPadController::ButtonLongPressed);break;
      }
      break;

    case DPadController::RotaryEncoderMoved:
      currentFunction->RotaryEncoderEvent(eventData);
      break;
  }
}

INSTANTIATE_DPADCONTROLLER(controller,
   2, // The digital pin connected to the "ENC A" pin on the encoder
   3, // The digital pin connected to the "ENC B" pin on the encoder
   4, // The digital pin connected to the UP button on the DPAD
   5, // The digital pin connected to the DOWN button on the DPAD
   6, // The digital pin connected to the LEFT button on the DPAD
   7, // The digital pin connected to the RIGHT button on the DPAD
   8, // The digital pin connected to the CENTER button on the DPAD
   DPadEvent // Event handler for all the events from the DPad controller
  );

/// <summary>
/// This method is executed once when the Craft Light is powered on.
/// </summary>
void setup(void)
{
  LOGGING_INIT;
  pinMode(LED_BUILTIN, OUTPUT); // The built in led is used as a watchdog so I can tell the code is running on the controller.
  SETUP_DPADCONTROLLER(controller);
}

bool turnLedOn = true;
unsigned long ledTimerMs;

void loop(void) {
  controller.updateState();

  // Just blink the LED light, so I can tell the program is running.
  ledTimerMs = millis();
  if (ledTimerMs % 1000 == 0)
  {
    digitalWrite(LED_BUILTIN, turnLedOn ? HIGH : LOW);
    turnLedOn = !turnLedOn;
    delay(1);
  }
}