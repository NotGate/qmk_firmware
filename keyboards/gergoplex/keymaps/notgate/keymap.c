#include QMK_KEYBOARD_H
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Basic layer
     *
     * ,-----------------------------.       ,--------------------------------.
     * |    Q |  W  |  E  |  R  |  T  |      |  Y  |  U  |  I  |  O  |    P   |
     * |-----+-----+-----+-----+------|      |--------------------------------|
     * |CTRL/A|  S  |  D  |  F  |  G  |      |  H  |  J  |  K  |  L  | CTRL/; |
     * |-----+-----+-----+-----+------|      |--------------------------------|
     * |SHFT/Z|  X  |  C  |  V  |  B  |      |  N  |  M  |  <  |  >  | SHFT/? |
     * `------+-----+-----+------+----'      `--------------------------------'
     *  .-------------------------.           .-----------------.
     *  |ESC/META|ENT/ALT|SPC(SYM)|           |SPC(NUM)|BSPC|TAB|
     *  '-------------------------'           '-----------------'
     */
    [BASE] = LAYOUT_gergoplex(
        KC_A   ,KC_B   ,KC_C   ,KC_D   ,XXXXXXX,/*   */XXXXXXX,KC_E   ,KC_F   ,KC_G   ,KC_H   ,
        KC_I   ,KC_J   ,KC_K   ,KC_L   ,XXXXXXX,/*   */XXXXXXX,KC_M   ,KC_N   ,KC_O   ,KC_P   ,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,/*   */XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                        XXXXXXX,KC_Q   ,KC_R   ,/*   */KC_S   ,KC_T   ,XXXXXXX)
};
