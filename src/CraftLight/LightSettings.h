#ifndef LightSettings_h
#define LightSettings_h

#include <Adafruit_NeoPixel.h>
#include "Logging.h"

/// <summary>
/// This class contains the settings of the Craft Light, so they can be stored in EEPROM. That way next time you start the light it will have the same settings as you last used.
/// </summary>
class LightSettings
{
  public:
    /// <summary>
    /// Light color definition: RED value (0-255).
    /// </summary>
    uint8_t Red;

    /// <summary>
    /// Light color definition: GREEN value (0-255).
    /// </summary>
    uint8_t Green;

    /// <summary>
    /// Light color definition: BLUE value (0-255).
    /// </summary>
    uint8_t Blue;

    /// <summary>
    /// The size of the left light bar.
    /// </summary>
    uint8_t leftBarLength;

    /// <summary>
    /// The left edge of the left light bar.
    /// </summary>
    uint8_t leftBarStart;

    /// <summary>
    /// The size of the right light bar.
    /// </summary>
    int8_t rightBarLength;

    /// <summary>
    /// The right edge of the right light bar.
    /// </summary>
    uint8_t rightBarStart;

    /// <summary>
    /// Gets the default slot index from EEPROM, and then loads the settings in that slot.
    /// </summary>
    void Setup();

    /// <summary>
    /// Persists current settings to the current settings slot (in EEPROM, so they survive a power off).
    /// </summary>
    void SaveSettings();

    /// <summary>
    /// Loads the settings from the current settings slot.
    /// </summary>
    void LoadSettings();

    /// <summary>
    /// Sets the current settings slot.
    /// This call does not change the settings or the slot contents. The users of the class can call
    /// LoadSettings() after this call to load the settings in the newly selected slot.
    /// ot SaveSettings() to override the contents of the current slot with the settings currently in the class fields.
    /// </summary>
    /// <param name="slotIndex">The index of the settings slot to become current. It must be between 0 and 2, inclusive.</param>
    void SetSettingsSlot(uint8_t slotIndex);

    /// <summary>
    /// Gets the current settings slot index.
    /// </summary>
    uint8_t GetCurrentSlotIndex();
   
  private:
    uint8_t settingsSlotIndex;
};
#endif