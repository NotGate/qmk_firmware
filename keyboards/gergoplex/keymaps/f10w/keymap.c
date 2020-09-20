// sudo util/docker_build.sh gergoplex:f10w:flash
#include QMK_KEYBOARD_H
#define BASE 0
#define FNS 1

enum custom_keycodes {
    TOP = SAFE_RANGE,
    MID,
    BOT,
    SPC,
    SFT,
    TH,
    OU,
};

bool spc = false;
size_t col = 0;
size_t row = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_gergoplex(
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,
    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   OU,     KC_L,   KC_SCOLON,
    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   TH,     KC_DOT, KC_SLASH,
   	                TOP,    MID,    BOT,    OSM(MOD_LSFT),  SPC,     OSL(FNS)),
[FNS] = LAYOUT_gergoplex(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_X, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
   	              KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO)
};

void f(uint16_t keycode, bool tap) {
    switch (keycode) {
        case SPC:
            spc = true;
            break;
        case TH:
            tap_code(KC_T);
            tap_code(KC_H);
            break;
        case OU:
            tap_code(KC_O);
            tap_code(KC_U);
            break;
        case TOP:
            f(pgm_read_word(&keymaps[BASE][row][0]),true);
            break;
        case MID:
            f(pgm_read_word(&keymaps[BASE][row][1]),true);
            break;
        case BOT:
            f(pgm_read_word(&keymaps[BASE][row][2]),true);
            break;
        default:
            if(tap) tap_code(keycode);
    }
}

// TODO: find a good way to activate LSFT or FNS before other keys - opposite of space
// TODO: get capital letters working with TMB keys
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        f(keycode,false);
        col = record->event.key.col;
        row = record->event.key.row;
    } else {
        if(spc) {
            tap_code(KC_SPC);
            spc = false;
        }
    }
    return true;
};


/*
adding delay before or after certain keys:
https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/feature_macros

SS_TAP() presses and releases a key.
SS_DOWN() presses (but does not release) a key.
SS_UP() releases a key.

SEND_STRING("VE" SS_DELAY(1000) SS_TAP(X_HOME) "LO");


bool sft = false;
uint16_t key = 0;
uint16_t key_timer;
case KC_A ... KC_Z:
    key_timer = timer_read();
    key = keycode;
    return false;
    break;
}
void matrix_scan_user(void) {
    if (key && timer_elapsed(key_timer) > 1000) {
        tap_code(key);
        key = 0;
    }
}
*/
