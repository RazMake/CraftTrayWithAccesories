#ifndef NeopixelMatrix_h
#define NeopixelMatrix_h

#include <Adafruit_NeoPixel.h>
#include "Logging.h"

/// <summary>
/// This class contains the functionality to treat a long strip of NeoPixels as a matrix.
/// </summary>
class NeoPixelMatrix
{
  public:
    /// <summary>
    /// Initializes a new instance of the <see cref="NeopixelMatrix" /> class.
    /// </summary>
    /// <param name="rowsCount"> The number of rows in the matrix.</param>
    /// <param name="columnsCount"> The number of columns in the matrix.</param>
    /// <param name="dataPin">The pin that is used to control the NeoPixels</param>
    NeoPixelMatrix(uint32_t rowsCount, uint32_t columnsCount, uint32_t dataPin);

    /// <summary>
    /// This method initializes the NeoPixels strip, making sure all pixels are off.
    /// It is supposed to be called in the setup() of the sketch.
    /// </summary>
    void Setup();

    /// <summary>
    /// Turns ON the pixels in the matrix (according to the last pattern).
    /// </summary>
    void TurnOn();

    /// <summary>
    /// Turns OFF all pixels in the matrix.
    /// </summary>
    void TurnOff();

    void IncBarLength();
    void DecBarLength();

  private:
    uint32_t rowsCount;
    uint32_t columnsCount;
    int barLength;
    Adafruit_NeoPixel pixels;
};
#endif