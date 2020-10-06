// sudo util/docker_build.sh gergoplex:f10w:flash
#include QMK_KEYBOARD_H
#define XXXX KC_NO
#define SFT OSM(MOD_LSFT)
#define FNS OSL(1)
#define DOT KC_DOT
#define COM KC_COMM

enum custom_keycodes {
    TOP = SAFE_RANGE,
    MID,
    BOT,
    SPC,

    AND,
    THE,
    ING,
    YOU,
    SCN,
    CLN,
    DQT,
    SQT,
    MNS,
    PLS
};

bool spc = false;
size_t row = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_gergoplex(
    KC_U,KC_F,KC_C,KC_R,XXXX,    XXXX,KC_D,KC_M,KC_W,KC_L,
    KC_I,KC_A,KC_O,KC_N,XXXX,    XXXX,KC_T,KC_H,KC_E,KC_S,
    DOT ,KC_Y,KC_V,KC_G,XXXX,    XXXX,KC_B,KC_P,KC_K,COM ,
              TOP ,MID ,BOT ,    SFT ,SPC ,FNS ),
[1] = LAYOUT_gergoplex(
    XXXX,SCN ,DQT ,AND ,XXXX,    XXXX,THE ,SQT ,CLN ,XXXX,
    XXXX,KC_Z,KC_J,YOU ,XXXX,    XXXX,ING ,KC_X,KC_Q,XXXX,
    XXXX,XXXX,XXXX,PLS ,XXXX,    XXXX,MNS ,XXXX,XXXX,XXXX,
   	          XXXX,XXXX,XXXX,    XXXX,XXXX,XXXX)
};

void f(uint16_t keycode, bool tap) {
    switch (keycode) {
        case SPC:
            spc = true;
            break;
        case THE:
            tap_code(KC_T);
            tap_code(KC_H);
            tap_code(KC_E);
            break;
        case YOU:
            tap_code(KC_Y);
            tap_code(KC_U);
            tap_code(KC_U);
            break;
        case TOP:
            f(pgm_read_word(&keymaps[0][row][0]),true);
            break;
        case MID:
            f(pgm_read_word(&keymaps[0][row][1]),true);
            break;
        case BOT:
            f(pgm_read_word(&keymaps[0][row][2]),true);
            break;
        default:
            if(tap) tap_code(keycode);
    }
}

// TODO: find a good way to activate LSFT or FNS before other keys - opposite of space
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        f(keycode,false);
        if(record->event.key.col < 3) {
            row = record->event.key.row;
        }
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
