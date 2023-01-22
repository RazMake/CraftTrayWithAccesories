#ifndef CraftLightFunction_h
#define CraftLightFunction_h

class CraftLightFunction
{
  public:
    /// <summary>
    /// This method is called (on the currently active "light function") so it can peform the specific work, when UP
    /// button is clicked, double-clicked or long pressed.
    /// </summary>
    /// <param name="eventType">The kind of event (click, double-click, long press) that happened for this button.</param>
    virtual void UpButtonEvent(const char eventType) = 0;

    /// <summary>
    /// This method is called (on the currently active "light function") so it can peform the specific work, when DOWN
    /// button is clicked, double-clicked or long pressed.
    /// </summary>
    /// <param name="eventType">The kind of event (click, double-click, long press) that happened for this button.</param>
    virtual void DownButtonEvent(const char eventType) = 0;

    /// <summary>
    /// This method is called (on the currently active "light function") so it can peform the specific work, when LEFT
    /// button is clicked, double-clicked or long pressed.
    /// </summary>
    /// <param name="eventType">The kind of event (click, double-click, long press) that happened for this button.</param>
    virtual void LeftButtonEvent(const char eventType) = 0;

    /// <summary>
    /// This method is called (on the currently active "light function") so it can peform the specific work, when RIGHT
    /// button is clicked, double-clicked or long pressed.
    /// </summary>
    /// <param name="eventType">The kind of event (click, double-click, long press) that happened for this button.</param>
    virtual void RightButtonEvent(const char eventType) = 0;

    /// <summary>
    /// This method is called (on the currently active "light function") so it can peform the specific work, when CENTER
    /// button is clicked, double-clicked or long pressed.
    /// </summary>
    /// <param name="eventType">The kind of event (click, double-click, long press) that happened for this button.</param>
    virtual void CenterButtonEvent(const char eventType) = 0;

    /// <summary>
    /// This method is called (on the currently active "light function") so it can peform the specific work, when the rotary
    /// encoder is moved.
    /// </summary>
    /// <param name="delta">The number of ticks the rotary wheel was moved (positive = the wheel was moved left, negative it was moved right).</param>
    virtual void RotaryEncoderEvent(const int delta) = 0;
};
#endif