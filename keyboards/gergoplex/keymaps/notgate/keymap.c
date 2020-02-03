#include QMK_KEYBOARD_H

static uint32_t state;
#define ROW record->event.key.row
#define COL record->event.key.col
#define TAP(H,M,L,KC) case H|M<<4|L<<8:tap_code16(KC);break;
#define OS(H,M,L,KC) case H|M<<4|L<<8:set_oneshot_mods(KC);break;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_gergoplex(
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX , XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX , XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX , XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                        XXXXXXX,XXXXXXX,XXXXXXX , XXXXXXX,XXXXXXX,XXXXXXX)
};

// All 10 buttons are assigned their own bit within `state`
// This looks verbose but I want the positioning of everything to be clear
// It'll eventually be refactored to prevent needing a big switch like this (highest number is 2^11-1 = 2047)
// The following is right-handed
static void process(uint32_t val) {
    switch(val) {
        // Sorted by ascii
        TAP(0b0000,
            0b0000,
            0b10,KC_BSPC)
        TAP(0b0000,
            0b0001,
            0b00,KC_ENT)
        TAP(0b0001,
            0b0000,
            0b00,KC_TAB)
        TAP(0b0000,
            0b0100,
            0b01,KC_ESC)
        TAP(0b0000,
            0b0000,
            0b01,KC_SPC)
        TAP(0b1000,
            0b0100,
            0b01,KC_EXLM)
        TAP(0b0000,
            0b1010,
            0b01,KC_DQT)
        TAP(0b1000,
            0b0010,
            0b01,KC_HASH)
        TAP(0b0000,
            0b1000,
            0b01,KC_DLR)
        TAP(0b0010,
            0b0000,
            0b01,KC_PERC)
        TAP(0b0100,
            0b1000,
            0b01,KC_AMPR)
        TAP(0b1010,
            0b0000,
            0b01,KC_QUOT)
        TAP(0b0111,
            0b0000,
            0b00,KC_LPRN)
        TAP(0b1101,
            0b0000,
            0b00,KC_RPRN)
        TAP(0b1001,
            0b0010,
            0b00,KC_ASTR)
        TAP(0b1011,
            0b0000,
            0b00,KC_PLUS)
        TAP(0b0000,
            0b0110,
            0b01,KC_COMMA)
        TAP(0b0011,
            0b1000,
            0b00,KC_MINUS)
        TAP(0b0000,
            0b1100,
            0b01,KC_DOT)
        TAP(0b0011,
            0b0000,
            0b00,KC_SLASH)
        TAP(0b0001,
            0b0010,
            0b00,KC_0)
        TAP(0b0001,
            0b0100,
            0b00,KC_1)
        TAP(0b1011,
            0b0100,
            0b00,KC_2)
        TAP(0b0101,
            0b1010,
            0b00,KC_3)
        TAP(0b0111,
            0b1000,
            0b00,KC_4)
        TAP(0b1101,
            0b0010,
            0b00,KC_5)
        TAP(0b1001,
            0b0110,
            0b00,KC_6)
        TAP(0b0011,
            0b1100,
            0b00,KC_7)
        TAP(0b0001,
            0b1110,
            0b00,KC_8)
        TAP(0b1111,
            0b0000,
            0b00,KC_9)
        TAP(0b1100,
            0b0000,
            0b01,KC_COLON)
        TAP(0b0110,
            0b0000,
            0b01,KC_SCOLON)
        TAP(0b0101,
            0b0010,
            0b00,KC_LT)
        TAP(0b0001,
            0b1010,
            0b00,KC_EQL)
        TAP(0b0101,
            0b1000,
            0b00,KC_GT)
        TAP(0b0010,
            0b0100,
            0b01,KC_QUES)
        TAP(0b0010,
            0b1000,
            0b01,KC_AT)

        TAP(0b0001,
            0b1100,
            0b01,S(KC_A))
        TAP(0b0001,
            0b1110,
            0b01,S(KC_B))
        TAP(0b0011,
            0b1000,
            0b01,S(KC_C))
        TAP(0b1001,
            0b0010,
            0b01,S(KC_D))
        TAP(0b0001,
            0b1010,
            0b01,S(KC_E))
        TAP(0b0111,
            0b1000,
            0b01,S(KC_F))
        TAP(0b1001,
            0b0110,
            0b01,S(KC_G))
        TAP(0b0101,
            0b0010,
            0b01,S(KC_H))
        TAP(0b1011,
            0b0000,
            0b01,S(KC_I))
        TAP(0b0101,
            0b0000,
            0b01,S(KC_J))
        TAP(0b0001,
            0b0100,
            0b01,S(KC_K))
        TAP(0b0101,
            0b1000,
            0b01,S(KC_L))
        TAP(0b0101,
            0b1010,
            0b01,S(KC_M))
        TAP(0b1101,
            0b0000,
            0b01,S(KC_N))
        TAP(0b0111,
            0b0000,
            0b01,S(KC_O))
        TAP(0b1101,
            0b0010,
            0b01,S(KC_P))
        TAP(0b0011,
            0b0000,
            0b01,S(KC_Q))
        TAP(0b1001,
            0b0100,
            0b01,S(KC_R))
        TAP(0b0011,
            0b0100,
            0b01,S(KC_S))
        TAP(0b0001,
            0b0110,
            0b01,S(KC_T))
        TAP(0b1011,
            0b0100,
            0b01,S(KC_U))
        TAP(0b0001,
            0b0010,
            0b01,S(KC_V))
        TAP(0b1111,
            0b0000,
            0b01,S(KC_W))
        TAP(0b0001,
            0b1000,
            0b01,S(KC_X))
        TAP(0b0011,
            0b1100,
            0b01,S(KC_Y))
        TAP(0b1001,
            0b0000,
            0b01,S(KC_Z))

        TAP(0b0001,
            0b0110,
            0b00,KC_LBRC)
        TAP(0b1001,
            0b0000,
            0b00,KC_BSLASH)
        TAP(0b0001,
            0b1100,
            0b00,KC_RBRC)
        TAP(0b0101,
            0b0000,
            0b00,KC_CIRC)
        TAP(0b0001,
            0b1000,
            0b00,KC_UNDS)
        TAP(0b0100,
            0b0000,
            0b01,KC_GRV)

        TAP(0b0000,
            0b1100,
            0b00,KC_A)
        TAP(0b0000,
            0b1110,
            0b00,KC_B)
        TAP(0b0010,
            0b1000,
            0b00,KC_C)
        TAP(0b1000,
            0b0010,
            0b00,KC_D)
        TAP(0b0000,
            0b1010,
            0b00,KC_E)
        TAP(0b0110,
            0b1000,
            0b00,KC_F)
        TAP(0b1000,
            0b0110,
            0b00,KC_G)
        TAP(0b0100,
            0b0010,
            0b00,KC_H)
        TAP(0b1010,
            0b0000,
            0b00,KC_I)
        TAP(0b0100,
            0b0000,
            0b00,KC_J)
        TAP(0b0000,
            0b0100,
            0b00,KC_K)
        TAP(0b0100,
            0b1000,
            0b00,KC_L)
        TAP(0b0100,
            0b1010,
            0b00,KC_M)
        TAP(0b1100,
            0b0000,
            0b00,KC_N)
        TAP(0b0110,
            0b0000,
            0b00,KC_O)
        TAP(0b1100,
            0b0010,
            0b00,KC_P)
        TAP(0b0010,
            0b0000,
            0b00,KC_Q)
        TAP(0b1000,
            0b0100,
            0b00,KC_R)
        TAP(0b0010,
            0b0100,
            0b00,KC_S)
        TAP(0b0000,
            0b0110,
            0b00,KC_T)
        TAP(0b1010,
            0b0100,
            0b00,KC_U)
        TAP(0b0000,
            0b0010,
            0b00,KC_V)
        TAP(0b1110,
            0b0000,
            0b00,KC_W)
        TAP(0b0000,
            0b1000,
            0b00,KC_X)
        TAP(0b0010,
            0b1100,
            0b00,KC_Y)
        TAP(0b1000,
            0b0000,
            0b00,KC_Z)

        TAP(0b0011,
            0b0100,
            0b00,KC_LCBR)
        TAP(0b0100,
            0b0010,
            0b01,KC_PIPE)
        TAP(0b1001,
            0b0100,
            0b00,KC_RCBR)
        TAP(0b1000,
            0b0000,
            0b01,KC_TILD)
        TAP(0b0000,
            0b0010,
            0b01,KC_DEL)

        // Control characters (this especially needs refactoring - naive solution)
        OS(0b0000,
           0b1000,
           0b10,MOD_LCTL)
        OS(0b0000,
           0b0100,
           0b10,MOD_LGUI)
        OS(0b0000,
           0b0010,
           0b10,MOD_LALT)
        OS(0b0000,
           0b0001,
           0b10,MOD_LSFT)

        OS(0b0000,
           0b1100,
           0b10,MOD_LCTL|MOD_LGUI)
        OS(0b0000,
           0b0110,
           0b10,MOD_LGUI|MOD_LALT)
        OS(0b0000,
           0b1010,
           0b10,MOD_LCTL|MOD_LALT)
        OS(0b0000,
           0b1110,
           0b10,MOD_LCTL|MOD_LGUI|MOD_LALT)

        // TBD
        // F1-12
        // printscreen
        // audio controls (up,down,mute)
        // brightness controls (up,down)
        // media controls (pause,play,next,prev)
        // arrows (lrud)
        // Home, End, PageUp, PageDown
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(record->event.pressed){
        if (keycode != XXXXXXX) {
            return true;
        }
        state |= 1<<(COL<3?((COL*MATRIX_COLS)+4-ROW%5):8+(2-ROW%5));
        return false;
    }
    if(state > 0){
        process(state);
        state = 0;
        return false;
    }else{
        return true;
    }
}
/*
#define LAYOUT_gergoplex(                            \
    L00,L01,L02,L03,L04,   R00,R01,R02,R03,R04,  \
    L10,L11,L12,L13,L14,   R10,R11,R12,R13,R14,  \
    L20,L21,L22,L23,L24,   R20,R21,R22,R23,R24,  \
            L30,L31,L32,   R30,R31,R32)          \
    {                               \
    { L04,   L14,   L24,  KC_NO},   \
    { L03,   L13,   L23,  L32},     \
    { L02,   L12,   L22,  L31},     \
    { L01,   L11,   L21,  L30},     \
    { L00,   L10,   L20,  KC_NO},   \
                                    \
    { R00,   R10,   R20, KC_NO},      \
    { R01,   R11,   R21, R30},      \
    { R02,   R12,   R22, R31},      \
    { R03,   R13,   R23, R32},      \
    { R04,   R14,   R24, KC_NO},    \
}
 */
