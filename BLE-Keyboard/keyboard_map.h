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
    0x00,      0x00,      0x00,      0x00,      0x00, /*Fn*/  KC_V,      0x00,             KC_N,      KC_SPACE,  KC_R,      KC_ENTER,  0x00,      KC_COMM,   0x00,      KC_UP,     0x00,
    0x00,      0x00,      0x00,      KC_LGUI,   KC_C,         KC_B,      KC_APPLICATION,   KC_J,      KC_G,      KC_E,      KC_M,      KC_DOT,    KC_SCOLON, 0x00,      KC_DOWN,   0x00,
    0x00,      0x00,      KC_RALT,   0x00,      KC_X,         KC_F,      0x00,             KC_H,      KC_PGDOWN, KC_Z,      KC_K,      KC_L,      KC_P,      KC_SLASH,  0x00,      KC_LEFT,
    0x00,      0x00,      KC_LALT,   0x00,      KC_Y,         KC_D,      0x00,             KC_T,      KC_3,      KC_U,      KC_I,      0x00,      KC_LBRC,   0x00,      0x00,      KC_RIGHT,
    0x00,      KC_RCTRL,  0x00,      0x00,      KC_CAPSLOCK,  KC_TAB,    0x00,             KC_1,      KC_2,      KC_5,      KC_7,      KC_9,      KC_MINUS,  KC_QUOTE,  0x00,      KC_END,
    0x00,      0x00,      0x00,      0x00,      0x00,         KC_Q,      0x00,             KC_GRAVE,  KC_F4,     KC_4,      KC_6,      KC_8,      KC_0,      KC_RBRC,   KC_HOME,   KC_PGUP,
    KC_RSHIFT, 0x00,      0x00,      0x00,      KC_S,         KC_W,      0x00,             KC_F1,     KC_F3,     KC_F6,     KC_F8,     KC_F10,    KC_F12,    KC_EQUAL,  KC_DELETE, KC_INSERT,
    KC_LSHIFT, 0x00,      0x00,      0x00,      KC_NONUS_HASH,0x00,      0x00,             KC_ESCAPE, KC_F2,     KC_F5,     KC_F7,     KC_F9,     KC_F11,    0,/*FNL*/  KC_PSCREEN,KC_BSPACE
};
