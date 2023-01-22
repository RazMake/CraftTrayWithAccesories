#ifndef NormaltFunction_h
#define NormalFunction_h

#include <Adafruit_NeoPixel.h>
#include "CraftLightFunction.h"
#include "DPadController.h"
#include "Logging.h"

/// <summary>
/// This class is the normal functionality of the craft light.
/// </summary>
class NormalFunction : public CraftLightFunction
{
  public:
    /// <summary>
    /// Initializes a new instance of the <see cref="NormalFunction" /> class.
    /// </summary>
    /// <param name="pixels">The controller for the LEDs that make up the light.</param>
    NormalFunction(Adafruit_NeoPixel& pixels);

    /// <summary>
    /// This method is called (on the currently active "light function") so it can peform the specific work, when UP
    /// button is clicked, double-clicked or long pressed.
    /// </summary>
    /// <param name="eventType">The kind of event (click, double-click, long press) that happened for this button.</param>
    void UpButtonEvent(const char eventType);

    /// <summary>
    /// This method is called (on the currently active "light function") so it can peform the specific work, when DOWN
    /// button is clicked, double-clicked or long pressed.
    /// </summary>
    /// <param name="eventType">The kind of event (click, double-click, long press) that happened for this button.</param>
    void DownButtonEvent(const char eventType);

    /// <summary>
    /// This method is called (on the currently active "light function") so it can peform the specific work, when LEFT
    /// button is clicked, double-clicked or long pressed.
    /// </summary>
    /// <param name="eventType">The kind of event (click, double-click, long press) that happened for this button.</param>
    void LeftButtonEvent(const char eventType);

    /// <summary>
    /// This method is called (on the currently active "light function") so it can peform the specific work, when RIGHT
    /// button is clicked, double-clicked or long pressed.
    /// </summary>
    /// <param name="eventType">The kind of event (click, double-click, long press) that happened for this button.</param>
    void RightButtonEvent(const char eventType);

    /// <summary>
    /// This method is called (on the currently active "light function") so it can peform the specific work, when CENTER
    /// button is clicked, double-clicked or long pressed.
    /// </summary>
    /// <param name="eventType">The kind of event (click, double-click, long press) that happened for this button.</param>
    void CenterButtonEvent(const char eventType);

    /// <summary>
    /// This method is called (on the currently active "light function") so it can peform the specific work, when the rotary
    /// encoder is moved.
    /// </summary>
    /// <param name="delta">The number of ticks the rotary wheel was moved (positive = the wheel was moved left, negative it was moved right).</param>
    void RotaryEncoderEvent(const int delta);

  private:
    Adafruit_NeoPixel& pixels;
};
#endif