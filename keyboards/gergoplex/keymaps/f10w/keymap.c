// sudo util/docker_build.sh gergoplex:f10w:flash
#include QMK_KEYBOARD_H
#define XXX KC_NO

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
size_t row = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_gergoplex(
    W  ,TH ,L  ,D  ,XXX,XXX,I  ,R  ,H  ,M  ,
    SFT,N  ,T  ,A  ,XXX,XXX,E  ,O  ,S  ,FNS,
    Y  ,P  ,IN ,F  ,XXX,XXX,C  ,G  ,U  ,ER ,
   	    TOP,MID,BOT,        OU ,SPC,B  ),
[1] = LAYOUT_gergoplex(
    XXX,SCN,DQT,DOT,XXX,XXX,COM,SQT,CLN,XXX,
    XXX,Z  ,J  ,K  ,XXX,XXX,V  ,X  ,Q  ,XXX,
    XXX,XXX,XXX,PLS,XXX,XXX,MNS,XXX,XXX,XXX,
   	    XXX,XXX,XXX,        XXX,XXX,XXX)
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
