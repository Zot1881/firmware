#ifndef __LEDMAP_H__
#define __LEDMAP_H__

// Includes:

    #include "key_action.h"

// Typedefs:
    typedef enum {
        BacklightStrategy_Functional,
        BacklightStrategy_ConstantRGB,
        BacklightStrategy_PerKeyRGB,
    } backlight_strategy_t;

    typedef enum {
        KeyActionColor_None,
        KeyActionColor_Scancode,
        KeyActionColor_Modifier,
        KeyActionColor_Shortcut,
        KeyActionColor_SwitchLayer,
        KeyActionColor_SwitchKeymap,
        KeyActionColor_Mouse,
        KeyActionColor_Macro,
    } key_action_color_t;

    typedef enum {
        LedMapIndex_LeftSlot_LeftShift = 21,
        LedMapIndex_LeftSlot_IsoKey = 22,
    } led_map_index_t;

    typedef struct {
        uint8_t red;
        uint8_t green;
        uint8_t blue;
    } rgb_t;

// Variables:
    extern rgb_t LedMap_ConstantRGB;

#if DEVICE_ID == DEVICE_ID_UHK60V2
    extern bool PerKeyColorByDefaultUseFunctionalColor;
    extern rgb_t ColorsTable[256];
    extern uint8_t ColorsMap[LayerId_Count][SLOT_COUNT][MAX_KEY_COUNT_PER_MODULE];
#endif

// Functions:

    void UpdateLayerLeds(void);
    void InitLedLayout(void);
    void SetLedBacklightStrategy(backlight_strategy_t newStrategy);

#endif
