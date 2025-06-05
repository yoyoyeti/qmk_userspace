#include QMK_KEYBOARD_H

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_BTN4:
            if (record->event.pressed) {
                // Check if CMD is currently held (from any keyboard)
                if (get_mods() & MOD_MASK_GUI) {
                    // CMD is held - send CMD + CTRL + N
                    register_code(KC_LGUI);
                    register_code(KC_LCTL);
                    register_code(KC_N);
                    wait_ms(10);
                    unregister_code(KC_N);
                    unregister_code(KC_LCTL);
                    unregister_code(KC_LGUI);
                    return false; // Don't send normal BTN4
                }
            }
            return true; // Send normal BTN4 if CMD not held

        case KC_BTN5:
            if (record->event.pressed) {
                // Check if CMD is currently held (from any keyboard)
                if (get_mods() & MOD_MASK_GUI) {
                    // CMD is held - send CMD + CTRL + O
                    register_code(KC_LGUI);
                    register_code(KC_LCTL);
                    register_code(KC_O);
                    wait_ms(10);
                    unregister_code(KC_O);
                    unregister_code(KC_LCTL);
                    unregister_code(KC_LGUI);
                    return false; // Don't send normal BTN5
                }
            }
            return true; // Send normal BTN5 if CMD not held
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_BTN1,     // Left click
        KC_BTN2,     // Right click
        KC_BTN3,     // Middle click
        KC_BTN4,     // Mouse button 4
        KC_BTN5      // Mouse button 5
    ),
};
