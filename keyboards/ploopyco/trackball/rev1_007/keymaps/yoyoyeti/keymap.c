#include QMK_KEYBOARD_H

static bool btn4_held = false;
static bool btn4_used_for_shortcut = false;
static uint16_t btn4_press_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_BTN4:
            if (record->event.pressed) {
                btn4_held = true;
                btn4_used_for_shortcut = false;
                btn4_press_timer = timer_read();
            } else {
                btn4_held = false;
                // If button was released quickly and wasn't used for shortcuts, toggle drag scroll
                if (!btn4_used_for_shortcut && timer_elapsed(btn4_press_timer) < 200) {
                    tap_code(KC_BTN4);
                }
            }
            return false;

        case KC_BTN1:
            if (record->event.pressed) {
                if (btn4_held) {
                    btn4_used_for_shortcut = true;  // Mark that BTN4
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
                if (btn4_held) {
                    btn4_used_for_shortcut = true;  // Mark that BTN4
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
        KC_BTN4,
        DRAG_SCROLL,
        KC_BTN5,
        KC_BTN1,
        KC_BTN2
    ),
};
