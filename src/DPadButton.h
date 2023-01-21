#ifndef DPadButton_h
#define DPadButton_h

#include "Arduino.h"
#include "Logging.h"

// The minimum number of milliseconds a button has to be pressed before it is considered a "long-press".
#ifndef LONGPRESS_TIMEOUT
  #define LONGPRESS_TIMEOUT 700
#endif

// The max number of milliseconds between two short clicks of a button to be considered a "double-click".
// if the clicks are separated by mode than this number of milliseconds are considered simply two separate clicks.
#ifndef DOUBLECLICK_TIMEOUT
  #define DOUBLECLICK_TIMEOUT 250
#endif

/// <summary>
/// This class represents a single button on the controller and provides the functionality for detecting clicks, double-clicks and long presses.
/// </summary>
class DPadButton
{
  public:
    DPadButton(int pin, const char* buttonName);

    /// <summary>
    // Gets the name of the button.
    /// </summary>
    const char* Name;

    /// <summary>
    /// Initializes the hardware for this button (aka. sets up the pin mode).
    /// </summary>
    void init();

    /// <summary>
    /// This must be called in the Arduino loop function to check the state of the button.
    /// It is necessary to do so because the class is designed to work with normal pins (which do not cause interrupts).
    /// </summary>
    void updateState();

    /// <summary>
    /// Gets a value indicating whether during the last call of updateState() it was detected that the button was clicked.
    /// The value is cleared once the method returns true, so consumers can check again for the next time the button is clicked.
    /// </summary>
    bool wasClicked();

    /// <summary>
    /// Gets a value indicating whether during the last call of updateState() it was detected that the button was double-clicked.
    /// The value is cleared once the method returns true, so consumers can check again for the next time the button is double-clicked.
    /// </summary>
    bool wasDoubleClicked();

    /// <summary>
    /// Gets a value indicating whether during the last call of updateState() it was detected that the button was long-pressed.
    /// The value is cleared once the method returns true, so consumers can check again for the next time the button is long-pressed.
    /// </summary>
    bool wasLongPressed();

  private:
    // The pin to which the button is connected.
    int pin;

    // State used to indicate to consumers what event happened:
    bool wasButtonClicked;
    bool wasButtonLongPressed;
    bool wasButtonDoubleClicked;

    // We need to disconnect the pin state changes from the button state changes so we can debounce.
    // That essentially means the pin will go HIGH/LOW sometimes, in rapid succession, but the button
    // state does not change (untill the rapid changes have settled)
    // ----------------------------------------------------------------------------------------------
    // The time (milliseconds) when the pin changed its state last.
    unsigned long lastPinStateChangeMs;
    // The current state of the pin.
    bool currentPinStateIsLow;

    // Then we need to keep previous state for the button too, in order to detect long-press and double-click.
    // ----------------------------------------------------------------------------------------------
    // A flag indicating whther the last known state of the button is pressed or released.
    bool isButtonCurrentlyPressed;
    // The last time the button changed its state (between pressed and released).t
    unsigned long lastButtonStateChangeMs;
    // The last time a button press then release within a short time (click) was detected.
    unsigned long previousClickTime;
    // A flag indicating whether we have detected a button click that was not yet
    // signaled to the consumer. Used to allow distinguishing double-clicks from clicks.
    bool previousClickDetected;
};
#endif