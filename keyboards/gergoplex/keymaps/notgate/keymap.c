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
    [BASE] = LAYOUT_gergoplex(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, MT(MOD_LCTL, KC_A), KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, MT(MOD_LCTL, KC_SCLN), MT(MOD_RSFT, KC_Z), KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, MT(MOD_RSFT, KC_SLSH), MT(MOD_LGUI, KC_ESC), MT(MOD_LALT, KC_ENT), LT(SYMB, KC_SPC),  // Left
                              LT(NUMB, KC_SPC), KC_LSFT, MT(MOD_RSFT, KC_TAB)                                                                                                                                                                                                                                                                       // Right
                              ),
};
