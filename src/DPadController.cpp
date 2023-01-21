#include "DPadController.h"
 
DPadController::DPadController(RotaryEncoder& encoder, DPadButton* buttons[5]) : encoder(encoder)
{
  this->buttons = buttons;
}

void DPadController::updateState()
{
  // First check the rotary encoder state:
  long previousLastPosition = this->lastEncoderPosition;
  this->lastEncoderPosition = this->encoder.getPosition();
  long delta = this->lastEncoderPosition - previousLastPosition;
  if (delta != 0)
  {
    LOG("Rotary ENC: ");
    LOG(previousLastPosition);
    LOG(" -> ");
    LOG(this->lastEncoderPosition);
    LOG(": Delta = ");
    LOGLN(delta);
  }

  // The check all buttons for all types of action on them.
  // We need to do this because Arduino UNO (which is what I'm using only has two
  // interrupt pins, and they are used for the rotary encoder).
  for (unsigned int i=0; i < 5; i++)
  {
    this->buttons[i]->updateState();
    if (this->buttons[i]->wasClicked())
    {
      LOG("Button "); LOG(this->buttons[i]->Name); LOGLN(" was clicked");
    }
    else if (this->buttons[i]->wasDoubleClicked())
    {
      LOG("Button "); LOG(this->buttons[i]->Name); LOGLN(" was double-clicked");      
    }
    else if (this->buttons[i]->wasLongPressed())
    {
      LOG("Button "); LOG(this->buttons[i]->Name); LOGLN(" was long pressed");
    }
  }
}