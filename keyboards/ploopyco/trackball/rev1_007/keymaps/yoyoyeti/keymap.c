#include QMK_KEYBOARD_H

static bool drag_held = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DRAG_SCROLL:
            if (record->event.pressed) {
                drag_held = true;
            } else {
                drag_held = false;
            }
            return true;

        case KC_BTN1:
            if (record->event.pressed) {
                if (drag_held) {
                    // BTN4 + BTN1 = CMD+CTRL+N
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
                if (drag_held) {
                    // BTN4 + BTN2 = CMD+CTRL+O
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
        DRAG_SCROLL,
        KC_BTN5,
        KC_BTN4,
        KC_BTN1,
        KC_BTN2
    ),
};
