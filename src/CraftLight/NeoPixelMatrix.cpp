#include "NeoPixelMatrix.h"

NeoPixelMatrix::NeoPixelMatrix(uint32_t rowsCount, uint32_t columnsCount, uint32_t dataPin)
    : pixels(columnsCount * rowsCount, dataPin, NEO_GRB + NEO_KHZ800 /*The type of LED strip being used in the Craft Light*/)
{
  this->rowsCount = rowsCount;
  this->columnsCount = columnsCount;
  this->barLength = 1;
}

void NeoPixelMatrix::Setup()
{
  this->pixels.begin();
  this->pixels.show(); // Ensure the pixels are OFF by default.
}

void NeoPixelMatrix::TurnOff()
{
  this->pixels.clear();
  this->pixels.show();
}

void NeoPixelMatrix::TurnOn()
{
  uint32_t color = this->pixels.Color(255, 255, 255);
  for (int i=0; i<this->barLength; i++)
  {
    this->pixels.setPixelColor(i,color);
    this->pixels.setPixelColor(2*this->columnsCount - 1 - i, color);
    this->pixels.setPixelColor(i + 2*this->columnsCount, color);
  }

  this->pixels.show();
}

void NeoPixelMatrix::IncBarLength()
{
  if (this->barLength < this->columnsCount)
  {
    this->barLength = this->barLength + 1;
    this->TurnOn();
  }
}

void NeoPixelMatrix::DecBarLength()
{
  if (this->barLength > 1)
  {
    this->barLength = this->barLength - 1;
    this->TurnOff();
    this->TurnOn();
  }
}
