// sudo util/docker_build.sh planck/rev6:notgate:dfu
// make planck/rev6:notgate:dfu
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

#define FN OSL(1)

#define SFT OSM(MOD_LSFT)

enum custom_keycodes {
    TOP = SAFE_RANGE,
    MID,
    BOT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |   F  |   D  |   L  |   H  |   X  |   Q  |   M  |   I  |   Y  |   U  |  ;   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TAB  |   C  |   R  |   N  |   S  |   V  |   K  |   T  |   A  |   E  |   O  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CTL  | SFT  |   .  |   P  |   W  |   Z  |   J  |   G  |   B  |   '  |   ,  | ENT  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | ALT  | TOP  | MID  | BOT  | BACK | SPC  | FN   | GUI  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[0] = LAYOUT_planck_grid(
    KC_ESC,  KC_F,    KC_D,    KC_L,    KC_H,    KC_X,      KC_J,    KC_M,    KC_I,    KC_Y,    KC_U,     KC_COLN,
    KC_TAB,  KC_C,    KC_R,    KC_N,    KC_S,    KC_V,      KC_K,    KC_T,    KC_A,    KC_E,    KC_O,     KC_SLASH,
    KC_LCTL, KC_LSFT, KC_DOT,  KC_P,    KC_W,    KC_Z,      KC_Q,    KC_G,    KC_B,    KC_QUOT, KC_COMM,  KC_ENT,
    XXXX,    XXXX,    KC_LALT, TOP,     MID,     BOT,       KC_BSPC, KC_SPC,  FN,      KC_LGUI, XXXX,     XXXX
)};


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


/*
Adjusted 252078 fc;dr.lnphswxvzjkqmtgiabye'uo,
0    1    2    3    4    5    6    7    8    9
f    d    l    h    x    j    m    i    y    u     28.1
c    r    n    s    v    k    t    a    e    o     60.4
;    .    p    w    z    q    g    b    '    ,     11.1
04.4 10.4 12.0 13.1 01.3 01.3 13.8 16.1 15.5 11.4
41.3 58.2
09.1
*/
