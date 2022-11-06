#include QMK_KEYBOARD_H
// qmk flash -kb ym68 -km rev2 -e AVR_CFLAGS="-Wno-array-bounds"

enum custom_keycodes {
    STARDEW_ANIM_CANCEL = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case STARDEW_ANIM_CANCEL:
        if (record->event.pressed) {
            for (int i = 0; i < 6; i++) {
                tap_code_delay(KC_BTN1, 17);
                SEND_STRING(SS_DELAY(125) SS_DOWN(X_R) SS_DOWN(X_DEL) SS_DOWN(X_RSFT));
                SEND_STRING(SS_DELAY(17) SS_UP(X_R) SS_UP(X_DEL) SS_UP(X_RSFT));
                SEND_STRING(SS_DELAY(17));
            }
        }
        else {

        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_GRV,  KC_BSPC, KC_GRV,
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,        KC_PGUP,
        TG(1) ,     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                KC_DEL,
        // STARDEW_ANIM_CANCEL ,     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                KC_DEL,
        KC_LSPO, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,           KC_UP,     KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,            KC_SPC,                                     TO(0),   TO(1),   TO(2),        KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT(
        _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_PSCR,
        _______,     _______, KC_VOLU,  KC_MPLY, _______, _______, _______, _______, KC_UP, _______, _______, _______, _______, _______,      KC_1,
        _______,       KC_MPRV, KC_VOLD, KC_MNXT, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______,             KC_SCRL,
        KC_LSFT,   _______, _______, _______,  _______, _______,  _______, _______, _______, _______, _______, _______, KC_RSFT,        _______, KC_2,
        _______,   _______,   _______,                      _______,                              _______, _______, _______, _______, _______, _______
    ),
    [2] = LAYOUT(
        RESET,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_PSCR,
        _______,     _______, KC_UP,   _______, _______, _______, _______, KC_MSTP, KC_VOLU, KC_MPLY, _______, _______, _______, _______,      KC_HOME,
        _______,       KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, _______, _______, _______,             KC_END,
        _______,   _______, _______, _______,  _______, _______,  _______, _______, _______, _______, _______, _______, _______,        _______, _______,
        _______,   _______,   _______,                      _______,                              _______, _______, _______, _______, _______, _______
    ),
};

