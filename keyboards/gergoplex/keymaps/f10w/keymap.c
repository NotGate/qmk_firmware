// sudo util/docker_build.sh gergoplex:f10w:flash
// make gergoplex:f10w:flash
#include QMK_KEYBOARD_H

#define XXXX KC_NO
#define DASH KC_MINS
#define SLSH KC_SLASH
#define SQT KC_QUOT
#define DQT S(KC_QUOT)
#define BS KC_BSPC
#define CBS LCTL(KC_BSPC)
#define DS LCTL(KC_DEL)
#define TB KC_TAB
#define NL KC_ENT
#define SPC KC_SPC
#define DOT KC_DOT
#define COM KC_COMMA
#define SEMI KC_COLN
#define EXCL S(KC_1)
#define QUES S(KC_SLASH)
#define LP S(KC_9)
#define RP S(KC_0)

#define FNS OSL(1)

#define SFT OSM(MOD_LSFT)

enum custom_keycodes {
    TOP = SAFE_RANGE,
    MID,
    BOT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_gergoplex(
    DOT ,KC_L,KC_N,KC_G,KC_K,KC_Q,KC_D,KC_C,KC_U,KC_B,
    KC_T,KC_S,KC_A,KC_H,KC_V,KC_X,KC_R,KC_E,KC_I,KC_O,
    COM ,KC_Y,SQT ,KC_P,KC_J,KC_Z,KC_M,SEMI,KC_W,KC_F,
              FNS ,MID ,SFT ,BOT ,SPC ,TOP ),
[1] = LAYOUT_gergoplex(
    KC_0,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,
    XXXX,XXXX,XXXX,CBS ,XXXX,XXXX,EXCL,QUES,LP  ,RP  ,
    XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
              XXXX,XXXX,XXXX,XXXX,XXXX,XXXX),
};

/*
Adjusted 251033 fc,dr.lnphswxvzjkqmtguebia'yo;
0    1    2    3    4    5    6    7    8    9
f    d    l    h    x    q    m    u    i    y     29.6
c    r    n    s    v    k    t    e    a    o     58.8
,    .    p    w    z    j    g    b    '    ;     11.1
05.7 10.4 12.0 13.1 01.3 01.3 13.8 16.1 15.7 10.1
42.5 57.0
08.8

Adjusted 252590 fc;dr.lnphswxvzjkqmtguebia'yo,
0    1    2    3    4    5    6    7    8    9
f    d    l    h    x    q    m    u    i    y     29.6
c    r    n    s    v    k    t    e    a    o     58.9
SFT  .    p    w    z    j    g    b    '    ,     11.0
04.4 10.4 12.0 13.1 01.3 01.3 13.8 16.2 15.7 11.3
41.3 58.2
9.0
*/

size_t row = 0, col = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(record->event.pressed) {
        switch (keycode) {
            case TOP:
                tap_code(pgm_read_word(&keymaps[0][row][col]));
                return false;
                break;
            case MID:
                tap_code(pgm_read_word(&keymaps[0][row][col]));
                return false;
                break;
            case BOT:
                tap_code(pgm_read_word(&keymaps[0][row][col]));
                return false;
                break;
        }
        if(record->event.key.col < 3) {
            col = record->event.key.col;
            row = record->event.key.row;
        } else {

        }
    }
    return true;
};
