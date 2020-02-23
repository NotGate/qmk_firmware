#include QMK_KEYBOARD_H

static uint16_t state;
enum SIDE{NONE,RIGHT,LEFT};
enum SIDE side = NONE;
uint16_t start = 0;
#define X  KC_NO
#define XX KC_NO
#define ROW record->event.key.row
#define COL record->event.key.col
#define TAP(H, M, L, KC) case H | M << 4 | L << 8: tap_code16(KC);break;
#define OS(H, M, L, KC)  case H | M << 4 | L << 8: set_oneshot_mods(KC);break;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_gergoplex(
             0, 1, 2, 3,XX,XX,13,12,11,10,
             4, 5, 6, 7,XX,XX,17,16,15,14,
            XX,XX,XX,XX,XX,XX,XX,XX,XX,XX,
                  XX, 8, 9,19,18,XX)
};

static void process(uint16_t val) {
    switch (val) {
        TAP(0b0000, 0b0000, 0b10, KC_BSPC)
        TAP(0b0000, 0b0001, 0b00, KC_ENT)
        TAP(0b0000, 0b0001, 0b01, KC_TAB)
        TAP(0b0000, 0b0100, 0b01, KC_ESC)
        TAP(0b0000, 0b0000, 0b01, KC_SPC)
        TAP(0b1000, 0b0100, 0b01, KC_EXLM)
        TAP(0b0000, 0b1010, 0b01, KC_DQT)
        TAP(0b1000, 0b0010, 0b01, KC_HASH)
        TAP(0b0000, 0b1000, 0b01, KC_DLR)
        TAP(0b0010, 0b0000, 0b01, KC_PERC)
        TAP(0b0100, 0b1000, 0b01, KC_AMPR)
        TAP(0b1010, 0b0000, 0b01, KC_QUOT)
        TAP(0b0110, 0b0001, 0b00, KC_LPRN)
        TAP(0b1100, 0b0001, 0b00, KC_RPRN)
        TAP(0b1000, 0b0011, 0b00, KC_ASTR)
        TAP(0b1010, 0b0001, 0b00, KC_PLUS)
        TAP(0b0000, 0b0110, 0b01, KC_COMMA)
        TAP(0b0010, 0b1001, 0b00, KC_MINUS)
        TAP(0b0000, 0b1100, 0b01, KC_DOT)
        TAP(0b0010, 0b0001, 0b00, KC_SLASH)
        TAP(0b0000, 0b0011, 0b00, KC_0)
        TAP(0b0000, 0b0101, 0b00, KC_1)
        TAP(0b1010, 0b0101, 0b00, KC_2)
        TAP(0b0100, 0b1011, 0b00, KC_3)
        TAP(0b0110, 0b1001, 0b00, KC_4)
        TAP(0b1100, 0b0011, 0b00, KC_5)
        TAP(0b1000, 0b0111, 0b00, KC_6)
        TAP(0b0010, 0b1101, 0b00, KC_7)
        TAP(0b0000, 0b1111, 0b00, KC_8)
        TAP(0b1110, 0b0001, 0b00, KC_9)
        TAP(0b1100, 0b0000, 0b01, KC_COLON)
        TAP(0b0110, 0b0000, 0b01, KC_SCOLON)
        TAP(0b0100, 0b0011, 0b00, KC_LT)
        TAP(0b0000, 0b1011, 0b00, KC_EQL)
        TAP(0b0100, 0b1001, 0b00, KC_GT)
        TAP(0b0010, 0b0100, 0b01, KC_QUES)
        TAP(0b0010, 0b1000, 0b01, KC_AT)
        TAP(0b0000, 0b1101, 0b01, S(KC_A))
        TAP(0b0000, 0b1111, 0b01, S(KC_B))
        TAP(0b0010, 0b1001, 0b01, S(KC_C))
        TAP(0b1000, 0b0011, 0b01, S(KC_D))
        TAP(0b0000, 0b1011, 0b01, S(KC_E))
        TAP(0b0110, 0b1001, 0b01, S(KC_F))
        TAP(0b1000, 0b0111, 0b01, S(KC_G))
        TAP(0b0100, 0b0011, 0b01, S(KC_H))
        TAP(0b1010, 0b0001, 0b01, S(KC_I))
        TAP(0b0100, 0b0001, 0b01, S(KC_J))
        TAP(0b0000, 0b0101, 0b01, S(KC_K))
        TAP(0b0100, 0b1001, 0b01, S(KC_L))
        TAP(0b0100, 0b1011, 0b01, S(KC_M))
        TAP(0b1100, 0b0001, 0b01, S(KC_N))
        TAP(0b0110, 0b0001, 0b01, S(KC_O))
        TAP(0b1100, 0b0011, 0b01, S(KC_P))
        TAP(0b0010, 0b0001, 0b01, S(KC_Q))
        TAP(0b1000, 0b0101, 0b01, S(KC_R))
        TAP(0b0010, 0b0101, 0b01, S(KC_S))
        TAP(0b0000, 0b0111, 0b01, S(KC_T))
        TAP(0b1010, 0b0101, 0b01, S(KC_U))
        TAP(0b0000, 0b0011, 0b01, S(KC_V))
        TAP(0b1110, 0b0001, 0b01, S(KC_W))
        TAP(0b0000, 0b1001, 0b01, S(KC_X))
        TAP(0b0010, 0b1101, 0b01, S(KC_Y))
        TAP(0b1000, 0b0001, 0b01, S(KC_Z))
        TAP(0b0000, 0b0111, 0b00, KC_LBRC)
        TAP(0b1000, 0b0001, 0b00, KC_BSLASH)
        TAP(0b0000, 0b1101, 0b00, KC_RBRC)
        TAP(0b0100, 0b0001, 0b00, KC_CIRC)
        TAP(0b0000, 0b1001, 0b00, KC_UNDS)
        TAP(0b0100, 0b0000, 0b01, KC_GRV)
        TAP(0b0000, 0b1100, 0b00, KC_A)
        TAP(0b0000, 0b1110, 0b00, KC_B)
        TAP(0b0010, 0b1000, 0b00, KC_C)
        TAP(0b1000, 0b0010, 0b00, KC_D)
        TAP(0b0000, 0b1010, 0b00, KC_E)
        TAP(0b0110, 0b1000, 0b00, KC_F)
        TAP(0b1000, 0b0110, 0b00, KC_G)
        TAP(0b0100, 0b0010, 0b00, KC_H)
        TAP(0b1010, 0b0000, 0b00, KC_I)
        TAP(0b0100, 0b0000, 0b00, KC_J)
        TAP(0b0000, 0b0100, 0b00, KC_K)
        TAP(0b0100, 0b1000, 0b00, KC_L)
        TAP(0b0100, 0b1010, 0b00, KC_M)
        TAP(0b1100, 0b0000, 0b00, KC_N)
        TAP(0b0110, 0b0000, 0b00, KC_O)
        TAP(0b1100, 0b0010, 0b00, KC_P)
        TAP(0b0010, 0b0000, 0b00, KC_Q)
        TAP(0b1000, 0b0100, 0b00, KC_R)
        TAP(0b0010, 0b0100, 0b00, KC_S)
        TAP(0b0000, 0b0110, 0b00, KC_T)
        TAP(0b1010, 0b0100, 0b00, KC_U)
        TAP(0b0000, 0b0010, 0b00, KC_V)
        TAP(0b1110, 0b0000, 0b00, KC_W)
        TAP(0b0000, 0b1000, 0b00, KC_X)
        TAP(0b0010, 0b1100, 0b00, KC_Y)
        TAP(0b1000, 0b0000, 0b00, KC_Z)
        TAP(0b0010, 0b0101, 0b00, KC_LCBR)
        TAP(0b0100, 0b0010, 0b01, KC_PIPE)
        TAP(0b1000, 0b0101, 0b00, KC_RCBR)
        TAP(0b1000, 0b0000, 0b01, KC_TILD)
        TAP(0b0000, 0b0010, 0b01, KC_DEL)

        // TODO: Refactor
        OS(0b0000, 0b1000, 0b10, MOD_LCTL)
        OS(0b0000, 0b0100, 0b10, MOD_LGUI)
        OS(0b0000, 0b0010, 0b10, MOD_LALT)
        OS(0b0000, 0b0001, 0b10, MOD_LSFT)
        OS(0b0000, 0b1100, 0b10, MOD_LCTL | MOD_LGUI)
        OS(0b0000, 0b0110, 0b10, MOD_LGUI | MOD_LALT)
        OS(0b0000, 0b1010, 0b10, MOD_LCTL | MOD_LALT)
        OS(0b0000, 0b1110, 0b10, MOD_LCTL | MOD_LGUI | MOD_LALT)

        // TODO: Decisions
        TAP(0b1000, 0b0000, 0b10, KC_LOCK)
        // F1-12
        // printscreen
        // audio controls (up,down,mute)
        // brightness controls (up,down)
        // media controls (pause,play,next,prev)
        // arrows (lrud)
        // Home, End, PageUp, PageDown
    }
}

void matrix_scan_user() {
    if(side!=NONE && timer_elapsed(start)>500){
        process(state);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(record->event.pressed && keycode != X) {
        if(side != keycode/10+1 && side != NONE) {
            process(state);
            state = 0;
        }
        side = keycode/10+1;
        if(state==0) start = timer_read();
        state |= 1 << (keycode%10);
    }else if(state > 0){
        process(state);
        state = 0;
        side = NONE;
    }
    return false;
}
