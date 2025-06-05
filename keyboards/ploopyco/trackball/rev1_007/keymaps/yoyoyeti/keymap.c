#include QMK_KEYBOARD_H

static bool btn3_held = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_BTN3:
            btn3_held = record->event.pressed;
            return true;

        case KC_BTN1:
            if (record->event.pressed) {
                if (btn3_held) {
                    // BTN3 + BTN4 = CMD+CTRL+N
                    register_code(KC_LGUI);
                    register_code(KC_LCTL);
                    register_code(KC_N);
                    wait_ms(10);
                    unregister_code(KC_N);
                    unregister_code(KC_LCTL);
                    unregister_code(KC_LGUI);
                    return false;
                }
            }
            return true;

        case KC_BTN2:
            if (record->event.pressed) {
                if (btn3_held) {
                    // BTN3 + BTN5 = CMD+CTRL+O
                    register_code(KC_LGUI);
                    register_code(KC_LCTL);
                    register_code(KC_O);
                    wait_ms(10);
                    unregister_code(KC_O);
                    unregister_code(KC_LCTL);
                    unregister_code(KC_LGUI);
                    return false;
                }
            }
            return true;
    }
    return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_BTN4,
        KC_BTN3,
        KC_BTN5,
        KC_BTN1,
        KC_BTN2
    ),
};

