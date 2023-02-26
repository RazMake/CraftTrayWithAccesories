#include "LightSettings.h"

void LightSettings::Setup()
{
  this->settingsSlotIndex = 0;
  this->Red = 100;
  this->Green = 100;
  this->Blue = 100;
  this->leftBarLength = 0; // 0 = left bar disabled.
  this->leftBarStart = 0;
  this->rightBarLength = 1; // minimum size possible, to make sure the bar fits on the available pixels.
  this->rightBarStart = 0; // start from the right most position.
}

void LightSettings::LoadSettings()
{
}

void LightSettings::SaveSettings()
{
}

void LightSettings::SetSettingsSlot(uint8_t slotIndex)
{
  if (slotIndex > 2)
  {
    this->settingsSlotIndex = 2;
  }
  else
  {
    this->settingsSlotIndex = slotIndex;
  }
}

uint8_t LightSettings::GetCurrentSlotIndex()
{
  return this->settingsSlotIndex;
}