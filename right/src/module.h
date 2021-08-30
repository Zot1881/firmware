#ifndef __MODULE_H__
#define __MODULE_H__

// Includes:

    #include "layer.h"
    #include "slot.h"
    #include "slave_protocol.h"

// Macros:

    #define MAX_KEY_COUNT_PER_MODULE     64

// Typedefs:

    typedef enum {
        NavigationMode_Cursor,
        NavigationMode_Scroll,
        NavigationMode_Caret,
        NavigationMode_Media,
        NavigationMode_Zoom,
        NavigationMode_None,
    } navigation_mode_t;

    typedef struct {
        // working 'cache'
        float currentSpeed; // px/ms

        // acceleration configurations
        float baseSpeed;
        float speed;
        float acceleration;

        // navigation mode configurations
        float scrollSpeedDivisor;
        float caretSpeedDivisor;
        float zoomSpeedDivisor;

        float axisLockSkew;
        float axisLockSkewFirstTick;

        navigation_mode_t navigationModes[LayerId_Count];

        bool scrollAxisLock;
        bool cursorAxisLock;
        bool swapAxes;
        bool invertScrollDirection;
    } module_configuration_t;

// Variables:

    extern module_configuration_t ModuleConfigurations[ModuleId_ModuleCount];

// Functions:

    module_configuration_t* GetModuleConfiguration(int8_t moduleId);
    bool IsModuleAttached(module_id_t moduleId);
    slot_t ModuleIdToSlotId(module_id_t moduleId);

#endif
