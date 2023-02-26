#ifndef ShapeSelectorFunction_h
#define ShapeSelectorFunction_h

#include "NeoPixelMatrix.h"
#include "CraftLightFunction.h"
#include "NormalFunction.h"
#include "DPadController.h"
#include "Logging.h"

/// <summary>
/// This class defines the functionality for selecting the shape of the light.
/// </summary>
class ShapeSelectorFunction : public CraftLightFunction
{
  public:
    /// <summary>
    /// Initializes a new instance of the <see cref="ShapeSelectorFunction" /> class.
    /// </summary>
    /// <param name="pixels">The controller for the LEDs that make up the light.</param>
    ShapeSelectorFunction(NeoPixelMatrix& pixels);

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

    /// <summary>
    /// This method is invoked by the main sketch when it bring this function to the forefront (when it makes it THE active function).
    /// </summary>
    void activate();

  private:
    NeoPixelMatrix& pixels;
};
#endif