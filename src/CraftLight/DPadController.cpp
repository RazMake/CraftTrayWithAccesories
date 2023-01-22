#include "DPadController.h"
 
DPadController::DPadController(RotaryEncoder& encoder, DPadButton* buttons[5], void(* dpadEventCallback)(const char, const long)) : encoder(encoder)
{
  this->buttons = buttons;
  this->dpadEventCallback = dpadEventCallback;
}

void DPadController::updateState()
{
  // First check the rotary encoder state:
  long previousLastPosition = this->lastEncoderPosition;
  this->lastEncoderPosition = this->encoder.getPosition();
  long delta = this->lastEncoderPosition - previousLastPosition;
  if (delta != 0)
  {
    this->dpadEventCallback(DPadController::RotaryEncoderMoved, delta);
  }

  // The check all buttons for all types of action on them.
  // We need to do this because Arduino UNO (which is what I'm using only has two
  // interrupt pins, and they are used for the rotary encoder).
  for (unsigned char i=0; i < 5; i++)
  {
    this->buttons[i]->updateState();
    if (this->buttons[i]->wasClicked())
    {
      this->dpadEventCallback(DPadController::ButtonClicked, i);
    }
    else if (this->buttons[i]->wasDoubleClicked())
    {
      this->dpadEventCallback(DPadController::ButtonDoubleClicked, i);
    }
    else if (this->buttons[i]->wasLongPressed())
    {
      this->dpadEventCallback(DPadController::ButtonLongPressed, i);
    }
  }
}