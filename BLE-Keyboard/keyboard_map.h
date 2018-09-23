#include <stdint.h>

#include "hwconfig.h"
#include "keycode.h"
#define KEYBOARD_NUM_OF_COLUMNS 16 // !< Number of columns in the keyboard matrix
#define KEYBOARD_NUM_OF_ROWS    8  // !< Number of rows in the keyboard matrix

static const uint8_t row_pin_array[KEYBOARD_NUM_OF_ROWS] = {
    KSI0,
    KSI1,
    KSI2,
    KSI3,
    KSI4,
    KSI5,
    KSI6,
    KSI7
};

static const uint8_t column_pin_array[KEYBOARD_NUM_OF_COLUMNS] = {
    KSO0,
    KSO1,
    KSO2,
    KSO3,
    KSO4,
    KSO5,
    KSO6,
    KSO7,
    KSO8,
    KSO9,
    KSO10,
    KSO11,
    KSO12,
    KSO13,
    KSO14,
    KSO15
};

static const uint8_t wakeup_button_row_index = 2;			//select row_pin_array[2] = 21
static const uint8_t wakeup_button_column_index = 1;	//select column_pin_array[1] = 2
//wakeup button is default_matrix_lookup[2][1] = 0x29 and it's ESC key

/** Table containing the mapping between the key matrix and the HID Usage codes for each key. */
static const uint8_t default_matrix_lookup[KEYBOARD_NUM_OF_COLUMNS * KEYBOARD_NUM_OF_ROWS] =
{
  /*  0          1          2          3          4             5          6                 7         8          9          10         11         12         13         14         15  */
    0x3E,      0x35,      0x3B,      0x22,      KC_C, /*Fn*/  0x23,      0x00,             KC_N,      KC_SPACE,  KC_R,      KC_ENTER,  0x42,      KC_COMM,   0x00,      KC_UP,     0x00,
    0x41,      0x39,      0x3A,      KC_LGUI,   KC_X,         0x11,      KC_APPLICATION,   KC_J,      KC_G,      KC_E,      KC_M,      0x45,      0x2E,      0x4C,      KC_DOWN,   0x00,
    0x40,      0x29,      KC_RALT,   0x0A,      0x00,         0x0B,      0x00,             KC_H,      KC_PGDOWN, KC_5,      KC_K,      0x44,      0x34,      0x46,      0x00,      KC_LEFT,
    0x1A,      0x14,      KC_LALT,   0x15,      KC_Y,         0x18,      0x0C,             KC_1,      KC_3,      0x00,      KC_7,      0x12,      0x13,      KC_MINS,   0xE5,      KC_RIGHT,
    0x1F,      KC_RCTRL,  0x20,      0x21,      KC_CAPSLOCK,  0x24,      0x25,             0x00,      KC_2,      0xE2,      0x51,      0x26,      0x27,      0x4F,      0x00,      KC_END,
    0x16,      0x04,      0x07,      0x09,      0x00,         0x0D,      0x0E,             0x00,      0x00,      0x00,      0x28,      0x0F,      0x33,      0x00,      0x00,      0xE4,
    0x1B,      0x1D,      0x06,      0x19,      KC_S,         0x10,      0x36,             KC_F1,     KC_F3,     KC_F6,     KC_F8,     0x37,      KC_F12,    0x00,      KC_DELETE, KC_INSERT,
    0x3F,      0x2B,      0x3C,      0x17,      0x00,         0x1C,      0x30,             KC_ESCAPE, KC_F2,     KC_F5,     KC_F7,     0x43,      KC_F11,    0,/*FNL*/  KC_PSCREEN,0xE0
};
