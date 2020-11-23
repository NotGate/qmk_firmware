// sudo util/docker_build.sh gergoplex:f10w:flash
// make gergoplex:f10w:flash
#include QMK_KEYBOARD_H

#define XXXX KC_NO
#define DOT KC_DOT
#define COM KC_COMM
#define DQT S(KC_QUOT)
#define SQT KC_QUOT
#define DASH KC_MINS

#define BS LCTL(KC_BSPC)
#define DS LCTL(KC_DEL)
#define TB KC_TAB
#define NL KC_ENT
#define SPC KC_SPC

#define FNS OSL(1)

#define SFT OSM(MOD_LSFT)

enum custom_keycodes {
    TOP = SAFE_RANGE,
    MID,
    BOT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_gergoplex(
    KC_Y,KC_D,KC_H,KC_L,TB  ,KC_V,KC_B,KC_O,KC_K,KC_U,
    KC_S,KC_N,KC_T,KC_R,NL  ,KC_F,KC_M,KC_I,KC_E,KC_A,
    FNS ,KC_G,KC_C,KC_J,XXXX,KC_Q,KC_P,KC_Z,KC_X,KC_W,
              TOP ,MID ,BOT ,BS  ,SPC ,SFT ),
[1] = LAYOUT_gergoplex(
    XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,DASH,XXXX,XXXX,XXXX,
    XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,DOT ,COM ,SQT ,DQT ,
    XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
              TOP ,MID ,BOT ,XXXX,XXXX,XXXX),
};

size_t row = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(record->event.pressed) {
        switch (keycode) {
            case TOP:
                tap_code(pgm_read_word(&keymaps[0][row][0]));
                return false;
                break;
            case MID:
                tap_code(pgm_read_word(&keymaps[0][row][1]));
                return false;
                break;
            case BOT:
                tap_code(pgm_read_word(&keymaps[0][row][2]));
                return false;
                break;
        }
        if(record->event.key.col < 3) {
            row = record->event.key.row;
        }
    }
    return true;
};
