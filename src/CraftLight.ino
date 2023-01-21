/// <summary>
/// This is the program, designed to run on an Arduino like controller to give the Craft Light the
/// functionality:
/// It has three modes of functionality:
/// Normal --------------------------------------------------------------------------------------------
/// SetColor ------------------------------------------------------------------------------------------
/// SetShape ------------------------------------------------------------------------------------------
/// </summary>
#include <Adafruit_NeoPixel.h>
#include <RotaryEncoder.h>
#include "DPadController.h"
#include "Logging.h"
#include "HardwareSerial.h"

// Instantiate the Neopixel library. It is used to control the RGB lights that make up the Craft Light.
// The original version uses RGB lights (not RGBW), because that is what I had available.
Adafruit_NeoPixel pixels(
  96, // The number of pixels available
      // There are two rows of LEDs, each containing X LEDs, counting starts from left most,
      // front row one.
  9,  // The digital pin used to send the commands to the LED strip
  NEO_GRB + NEO_KHZ800 // The type of LED strip being used in the Craft Light
  );

// CONTROLS --------------------------------------------------------------------------------------------
INSTANTIATE_DPADCONTROLLER(controller,
   2, // The digital pin connected to the "ENC A" pin on the encoder
   3, // The digital pin connected to the "ENC B" pin on the encoder
   4, // The digital pin connected to the UP button on the DPAD
   5, // The digital pin connected to the DOWN button on the DPAD
   6, // The digital pin connected to the LEFT button on the DPAD
   7, // The digital pin connected to the RIGHT button on the DPAD
   8  // The digital pin connected to the CENTER button on the DPAD
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