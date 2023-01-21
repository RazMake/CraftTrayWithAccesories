#include "Arduino.h"
#include "DPadButton.h"

#define DEBOUNCE_TIMEOUT 15 // milliseconds

DPadButton::DPadButton(int pin, const char* buttonName)
{
  this->pin = pin;
  this->Name = buttonName;
  this->lastPinStateChangeMs = 0; // There was no previous state change.
  this->isButtonCurrentlyPressed = this->currentPinStateIsLow;
  this->lastButtonStateChangeMs = 0; // There was no previous state change.
  this->previousClickTime = 0; // There was no previous click.
  this->previousClickDetected = false; // There was no button click yet.
  this->wasButtonClicked = false;
  this->wasButtonDoubleClicked = false;
  this->wasButtonLongPressed = false;
}

void DPadButton::updateState()
{
  bool isPinCurrentlyLow = digitalRead(this->pin) == LOW;
  if (isPinCurrentlyLow != this->currentPinStateIsLow)
  {
    this->currentPinStateIsLow = isPinCurrentlyLow;
    this->lastPinStateChangeMs = millis();
  }

  if (this->previousClickDetected && millis() - this->previousClickTime >= DOUBLECLICK_TIMEOUT)
  {
    // If more than double click timeout has passed since the last click, I know know this is a simple click.
    this->previousClickDetected = false;
    this->wasButtonClicked = true;
    this->wasButtonDoubleClicked = false;
    this->wasButtonLongPressed = false;
  }

  if (this->currentPinStateIsLow != this->isButtonCurrentlyPressed && millis() - this->lastPinStateChangeMs > DEBOUNCE_TIMEOUT)
  {
    this->isButtonCurrentlyPressed = this->currentPinStateIsLow;
    if (!this->isButtonCurrentlyPressed)
    {
      if (millis() - this->lastButtonStateChangeMs >= LONGPRESS_TIMEOUT)
      {
        this->previousClickDetected = false;
        this->previousClickTime = 0;
        this->wasButtonClicked = false;
        this->wasButtonDoubleClicked = false;
        this->wasButtonLongPressed = true;
      }
      else
      {
        if (this->previousClickDetected && millis() - this->previousClickTime <= DOUBLECLICK_TIMEOUT)
        {
          this->previousClickDetected = false;
          this->previousClickTime = 0;
          this->wasButtonClicked = false;
          this->wasButtonDoubleClicked = true;
          this->wasButtonLongPressed = false;
        }
        else
        {
          this->previousClickDetected = true;
          this->previousClickTime = millis();
        }
      }
    }

    this->lastButtonStateChangeMs = this->lastPinStateChangeMs; // Remember when we changed state, for next time.
  }
}

void DPadButton::init()
{
  // Because I'm ativating the internal pull up resistor,
  // the button pressed state is when the pin is LOW (the button connects it to the ground),
  // and the button released state is HIGH (the pull up resistor pulls it to VSS, when
  // the button is not pressed = contact is broken).
  pinMode(this->pin, INPUT_PULLUP);
  this->currentPinStateIsLow = digitalRead(this->pin) == LOW;
  this->lastButtonStateChangeMs = millis();
}

bool DPadButton::wasClicked()
{
  if (this->wasButtonClicked)
  {
    this->wasButtonClicked = false;
    return true;
  }

  return false;
}

bool DPadButton::wasDoubleClicked()
{
  if (this->wasButtonDoubleClicked)
  {
    this->wasButtonDoubleClicked = false;
    return true;
  }

  return false;
}

bool DPadButton::wasLongPressed()
{
  if (this->wasButtonLongPressed)
  {
    this->wasButtonLongPressed = false;
    return true;
  }

  return false;
}