#include QMK_KEYBOARD_H

static uint16_t state;
uint16_t start = 0;
enum SIDE{NONE,RIGHT,LEFT};
enum SIDE side = NONE;
#define XX KC_NO
#define X 2^0
#define Z 2^1
#define K 2^2
#define J 2^3
#define V 2^4
#define Q 2^5
#define PINKIE 2^6
#define THUMB1 2^7
#define THUMB2 2^8

#define T(KC):tap_code16(KC);break;
#define O(KC):set_oneshot_mods(KC);break;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_gergoplex(
            XX, 5, 3, 1,XX,XX,11,13,15,XX,
             6, 4, 2, 0,XX,XX,10,12,14,16,
            XX,XX,XX,XX,XX,XX,XX,XX,XX,XX,
                  XX, 7, 8,18,17,XX)
};

static void process(uint16_t val) {
    switch (val) {
        // Alphabet
        X    :T(KC_X)
        Z    :T(KC_Z)
        K    :T(KC_K)
        J    :T(KC_J)
        V    :T(KC_V)
        Q    :T(KC_Q)
        X|K  :T(KC_A)
        X|J  :T(KC_L)
        X|V  :T(KC_E)
        X|Q  :T(KC_C)
        Z|K  :T(KC_R)
        Z|J  :T(KC_N)
        Z|V  :T(KC_D)
        Z|Q  :T(KC_I)
        K|V  :T(KC_T)
        K|Q  :T(KC_S)
        J|V  :T(KC_H)
        J|Q  :T(KC_O)
        X|K|V:T(KC_B)
        X|K|Q:T(KC_Y)
        X|J|V:T(KC_M)
        X|J|Q:T(KC_F)
        Z|K|V:T(KC_G)
        Z|K|Q:T(KC_U)
        Z|J|V:T(KC_P)
        Z|J|Q:T(KC_W)

        // Capital Alphabet
        THUMB1|PINKIE      :T(KC_TAB)
        THUMB1|PINKIE|X    :T(S(KC_X))
        THUMB1|PINKIE|Z    :T(S(KC_Z))
        THUMB1|PINKIE|K    :T(S(KC_K))
        THUMB1|PINKIE|J    :T(S(KC_J))
        THUMB1|PINKIE|V    :T(S(KC_V))
        THUMB1|PINKIE|Q    :T(S(KC_Q))
        THUMB1|PINKIE|X|K  :T(S(KC_A))
        THUMB1|PINKIE|X|J  :T(S(KC_L))
        THUMB1|PINKIE|X|V  :T(S(KC_E))
        THUMB1|PINKIE|X|Q  :T(S(KC_C))
        THUMB1|PINKIE|Z|K  :T(S(KC_R))
        THUMB1|PINKIE|Z|J  :T(S(KC_N))
        THUMB1|PINKIE|Z|V  :T(S(KC_D))
        THUMB1|PINKIE|Z|Q  :T(S(KC_I))
        THUMB1|PINKIE|K|V  :T(S(KC_T))
        THUMB1|PINKIE|K|Q  :T(S(KC_S))
        THUMB1|PINKIE|J|V  :T(S(KC_H))
        THUMB1|PINKIE|J|Q  :T(S(KC_O))
        THUMB1|PINKIE|X|K|V:T(S(KC_B))
        THUMB1|PINKIE|X|K|Q:T(S(KC_Y))
        THUMB1|PINKIE|X|J|V:T(S(KC_M))
        THUMB1|PINKIE|X|J|Q:T(S(KC_F))
        THUMB1|PINKIE|Z|K|V:T(S(KC_G))
        THUMB1|PINKIE|Z|K|Q:T(S(KC_U))
        THUMB1|PINKIE|Z|J|V:T(S(KC_P))
        THUMB1|PINKIE|Z|J|Q:T(S(KC_W))

        // Pinkie Chords
        PINKIE      :T(KC_ENT)
        PINKIE|X    :T(KC_UNDS)
        PINKIE|Z    :T(KC_BSLASH)
        PINKIE|K    :T(KC_1)
        PINKIE|J    :T(KC_CIRC)
        PINKIE|V    :T(KC_0)
        PINKIE|Q    :T(KC_SLASh)
        PINKIE|X|K  :T(KC_RBRC)
        PINKIE|X|J  :T(KC_GT)
        PINKIE|X|V  :T(KC_EQL)
        PINKIE|X|Q  :T(KC_MINUS)
        PINKIE|Z|K  :T(KC_RCBR)
        PINKIE|Z|J  :T(KC_RPRN)
        PINKIE|Z|V  :T(KC_ASTR)
        PINKIE|Z|Q  :T(KC_PLUS)
        PINKIE|K|V  :T(KC_LBRC)
        PINKIE|K|Q  :T(KC_LCBR)
        PINKIE|J|V  :T(KC_LT)
        PINKIE|J|Q  :T(KC_LPRN)
        PINKIE|X|K|V:T(KC_8)
        PINKIE|X|K|Q:T(KC_7)
        PINKIE|X|J|V:T(KC_3)
        PINKIE|X|J|Q:T(KC_4)
        PINKIE|Z|K|V:T(KC_6)
        PINKIE|Z|K|Q:T(KC_2)
        PINKIE|Z|J|V:T(KC_5)
        PINKIE|Z|J|Q:T(KC_9)

        // Thumb1 Chords
        THUMB1      :T(KC_SPC)
        THUMB1|X    :T(KC_DLR)
        THUMB1|Z    :T(KC_TILD)
        THUMB1|K    :T(KC_F1)
        THUMB1|J    :T(KC_GRV)
        THUMB1|V    :T(KC_ESC)
        THUMB1|Q    :T(KC_PERC)
        THUMB1|X|K  :T(KC_DOT)
        THUMB1|X|J  :T(KC_AMPR)
        THUMB1|X|V  :T(KC_DQT)
        THUMB1|X|Q  :T(KC_AT)
        THUMB1|Z|K  :T(KC_EXLM)
        THUMB1|Z|J  :T(KC_COLN)
        THUMB1|Z|V  :T(KC_HASH)
        THUMB1|Z|Q  :T(KC_QUOT)
        THUMB1|K|V  :T(KC_COMM)
        THUMB1|K|Q  :T(KC_QUES)
        THUMB1|J|V  :T(KC_PIPE)
        THUMB1|J|Q  :T(KC_SCLN)
        THUMB1|X|K|V:T(KC_F8)
        THUMB1|X|K|Q:T(KC_F7)
        THUMB1|X|J|V:T(KC_F3)
        THUMB1|X|J|Q:T(KC_F4)
        THUMB1|Z|K|V:T(KC_F6)
        THUMB1|Z|K|Q:T(KC_F2)
        THUMB1|Z|J|V:T(KC_F5)
        THUMB1|Z|J|Q:T(KC_F9)

        // Thumb1 Chords
        THUMB2      :T(KC_BSPC)
        THUMB2|X    :O(KC_LCTL)
        THUMB2|Z    :T(XX)
        THUMB2|K    :O(KC_LGUI)
        THUMB2|J    :T(XX)
        THUMB2|V    :O(KC_LALT)
        THUMB2|Q    :T(XX)
        THUMB2|X|K  :O(KC_LCTL|KC_LGUI)
        THUMB2|X|J  :T(XX)
        THUMB2|X|V  :O(KC_LCTL|KC_LALT)
        THUMB2|X|Q  :T(XX)
        THUMB2|Z|K  :T(XX)
        THUMB2|Z|J  :T(XX)
        THUMB2|Z|V  :T(XX)
        THUMB2|Z|Q  :T(XX)
        THUMB2|K|V  :O(KC_LGUI|KC_LALT)
        THUMB2|K|Q  :T(XX)
        THUMB2|J|V  :T(XX)
        THUMB2|J|Q  :T(XX)
        THUMB2|X|K|V:O(KC_LCTL|KC_LGUI|KC_LALT)
        THUMB2|X|K|Q:T(XX)
        THUMB2|X|J|V:T(XX)
        THUMB2|X|J|Q:T(XX)
        THUMB2|Z|K|V:T(XX)
        THUMB2|Z|K|Q:T(XX)
        THUMB2|Z|J|V:T(XX)
        THUMB2|Z|J|Q:T(XX)
    }
    // KC_LOCK?
    // printscreen
    // audio controls (up,down,mute)
    // brightness controls (up,down)
    // media controls (pause,play,next,prev)
    // arrows (lrud)
    // Home, End, PageUp, PageDown
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
