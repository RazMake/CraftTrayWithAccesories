#ifndef DPadController_h
#define DPadController_h

#include "RotaryEncoder.h"
#include "Logging.h"
#include "DPadButton.h"

/// <summary>
/// This macro is instantiating a DPadController, connected to the specified pins.
/// This must be called outside of any function (before setup() or loop() definition).
/// </summary>
/// <param name="controllerVarName">The name of the variable holding the controller instance.</parm>
/// <param name="pinEncA">The digital pin connected to the "ENC A" pin on the encoder.</parm>
/// <param name="pinEncB">The digital pin connected to the "ENC B" pin on the encoder.</parm>
/// <param name="pinUpButton">The digital pin connected to the UP button on the DPAD.</parm>
/// <param name="pinDownButton">The digital pin connected to the DOWN button on the DPAD.</parm>
/// <param name="pinLeftButton">The digital pin connected to the LEFT button on the DPAD.</parm>
/// <param name="pinRightButton">The digital pin connected to the RIGHT button on the DPAD.</parm>
/// <param name="pinCenterButton">The digital pin connected to the CENTER button on the DPAD.</parm>
/// <param name="eventHandlerCallback">The callback method to be invoked  when the controls on the DPad are manipulated.</param>
#define INSTANTIATE_DPADCONTROLLER(controllerVarName, pinEncA, pinEncB, pinUpButton, pinDownButton, pinLeftButton, pinRightButton, pinCenterButton, eventHandlerCallback) \
int controllerVarName##Encoder_pinEncA = pinEncA; \
int controllerVarName##Encoder_pinEncB = pinEncB; \
RotaryEncoder controllerVarName##Encoder( \
  controllerVarName##Encoder_pinEncA, \
  controllerVarName##Encoder_pinEncB, \
  RotaryEncoder::LatchMode::TWO03); \
void updateEncoderPosition_##controllerVarName() { controllerVarName##Encoder.tick(); } \
DPadButton* controllerVarName##Buttons[] = { \
  new DPadButton(pinUpButton, "Up"), \
  new DPadButton(pinDownButton, "Down"), \
  new DPadButton(pinLeftButton, "Left"), \
  new DPadButton(pinRightButton, "Right"), \
  new DPadButton(pinCenterButton, "Center") \
}; \
DPadController controllerVarName(controllerVarName##Encoder, controllerVarName##Buttons, eventHandlerCallback);

/// <summary>
/// This macro is initializing a DPadController, connected to the specified pins.
/// This must be called inside the setup() function.
/// </summary>
/// <param name="controllerVarName">The name of the variable holding the controller instance to be setup.</parm>
#define SETUP_DPADCONTROLLER(controllerVarName) \
attachInterrupt(digitalPinToInterrupt(controllerVarName##Encoder_pinEncA), updateEncoderPosition_##controllerVarName, CHANGE); \
attachInterrupt(digitalPinToInterrupt(controllerVarName##Encoder_pinEncB), updateEncoderPosition_##controllerVarName, CHANGE); \
controllerVarName##Buttons[0]->init(); \
controllerVarName##Buttons[1]->init(); \
controllerVarName##Buttons[2]->init(); \
controllerVarName##Buttons[3]->init(); \
controllerVarName##Buttons[4]->init();

/// <summary>
/// This class represents a controller that encompases all the functionality provided by the Adafruit's ANO Directional Navigation and Scroll Wheel Rotary Encoder.
/// </summary>
class DPadController
{
  public:
    /// <summary>
    /// Initializes a new instance of the DPadController class.
    /// </summary>
    /// <param name="encoder">The rotary encoder on the DPAD.</parm>
    /// <param name="buttons">An array containing the buttons in the following order (up, down, left, right, center).</parm>
    /// <param name="dpadEventCallback">The callback </param>
    DPadController(RotaryEncoder& encoder, DPadButton* buttons[5], void(*dpadEventCallback)(const char, const long));

    /// <summary>
    /// This method must be called from the main loop to refresh the internal state of the controller
    /// and call the appropriate callbacks.
    /// </summary>
    void updateState();

    /// <summary>
    /// Constant: [Event Type] One of the buttons on the DPad was clicked.
    /// </summary>
    static const char ButtonClicked = 10;

    /// <summary>
    /// Constant: [Event Type] One of the buttons on the DPad was double clicked.
    /// </summary>
    static const char ButtonDoubleClicked = 20;

    /// <summary>
    /// Constant: [Event Type] One of the buttons on the DPad was long pressed.
    /// </summary>
    static const char ButtonLongPressed = 30;

    /// <summary>
    /// Constant: [Event Type] The wheel on the DPad (the rotary encoder) was moved.
    /// </summary>
    static const char RotaryEncoderMoved = 40;

    /// <summary>
    /// Constant: [Button] UP
    /// </summary>
    static const int UpButton = 0;

    /// <summary>
    /// Constant: [Button] DOWN
    /// </summary>
    static const int DownButton = 1;

    /// <summary>
    /// Constant: [Button] LEFT
    /// </summary>
    static const int LeftButton = 2;

    /// <summary>
    /// Constant: [Button] RIGHT
    /// </summary>
    static const int RightButton = 3;

    /// <summary>
    /// Constant: [Button] CENTER (Enter/Ok)
    /// </summary>
    static const int CenterButton = 4;

  private:
    // The object that manages the state of the rotary encoder.
    RotaryEncoder& encoder;
    // The array ob objects that manage the sate of the DPAD buttons.
    DPadButton** buttons;
    // This is used to determine how much did the rotary encoder moved.
    // It has a negative value for rotation to the left and a positive value for rotation to the right.
    long lastEncoderPosition = 0;
    // The callback to be invoked when DPad controller is manipulated.
    void(*dpadEventCallback)(const char, const long);
};
#endif