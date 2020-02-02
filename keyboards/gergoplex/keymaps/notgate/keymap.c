#include QMK_KEYBOARD_H

static uint32_t state;
#define ROW record->event.key.row
#define COL record->event.key.col
#define CASE(H,M,L,KC) case H|M<<4|L<<8:tap_code16(KC);break;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_gergoplex(
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX , XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX , XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX , XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                        XXXXXXX,XXXXXXX,XXXXXXX , XXXXXXX,XXXXXXX,XXXXXXX)
};

// All 9 buttons are assigned their own bit within `state`
// This looks verbose but I want the positioning of everything to be clear
// The following is right-handed
// OSM(MOD_LSFT)
static void process(uint32_t val) {
    switch(val) {
        // Sorted by ascii
        CASE(0b0000,
             0b0000,
             0b10,KC_BSPC)
        CASE(0b0001,
             0b0000,
             0b00,KC_TAB)
        CASE(0b0000,
             0b0001,
             0b00,KC_ENT)
        CASE(0b0000,
             0b0100,
             0b01,KC_ESC)
        CASE(0b0000,
             0b0000,
             0b01,KC_SPC)
        CASE(0b1000,
             0b0100,
             0b01,KC_EXLM)
        CASE(0b0000,
             0b1010,
             0b01,KC_DQT)
        CASE(0b1000,
             0b0010,
             0b01,KC_HASH)
        CASE(0b0000,
             0b1000,
             0b01,KC_DLR)
        CASE(0b0010,
             0b0000,
             0b01,KC_PERC)
        CASE(0b0100,
             0b1000,
             0b01,KC_AMPR)
        CASE(0b1010,
             0b0000,
             0b01,KC_QUOT)
        CASE(0b0110,
             0b0001,
             0b00,KC_LPRN)
        CASE(0b1100,
             0b0001,
             0b00,KC_RPRN)
        CASE(0b1000,
             0b0011,
             0b00,KC_ASTR)
        CASE(0b1010,
             0b0001,
             0b00,KC_PLUS)
        CASE(0b0100,
             0b0000,
             0b01,KC_GRV)
        CASE(0b0010,
             0b1001,
             0b00,KC_MINUS)
        CASE(0b0000,
             0b1100,
             0b01,KC_DOT)
        CASE(0b0010,
             0b0001,
             0b00,KC_SLASH)
        CASE(0b0000,
             0b0011,
             0b00,KC_0)
        CASE(0b0000,
             0b0101,
             0b00,KC_1)
        CASE(0b1010,
             0b0101,
             0b00,KC_2)
        CASE(0b0100,
             0b1011,
             0b00,KC_3)
        CASE(0b0110,
             0b1001,
             0b00,KC_4)
        CASE(0b1100,
             0b0011,
             0b00,KC_5)
        CASE(0b1000,
             0b0111,
             0b00,KC_6)
        CASE(0b0010,
             0b1101,
             0b00,KC_7)
        CASE(0b0000,
             0b1111,
             0b00,KC_8)
        CASE(0b1110,
             0b0001,
             0b00,KC_9)
        CASE(0b1100,
             0b0000,
             0b01,KC_COLON) // S(KC_SCOLON)
        CASE(0b0110,
             0b0000,
             0b01,KC_SCOLON)
        CASE(0b0100,
             0b0011,
             0b00,KC_LT)
        CASE(0b0000,
             0b1011,
             0b00,KC_EQL)
        CASE(0b0100,
             0b1001,
             0b00,KC_GT)
        CASE(0b0010,
             0b0100,
             0b01,KC_QUES)
        CASE(0b0010,
             0b1000,
             0b01,KC_AT)

        CASE(0b0000,
             0b1101,
             0b01,S(KC_A))
        CASE(0b0000,
             0b1111,
             0b01,S(KC_B))
        CASE(0b0010,
             0b1001,
             0b01,S(KC_C))
        CASE(0b1000,
             0b0011,
             0b01,S(KC_D))
        CASE(0b0000,
             0b1011,
             0b01,S(KC_E))
        CASE(0b0110,
             0b1001,
             0b01,S(KC_F))
        CASE(0b1000,
             0b0111,
             0b01,S(KC_G))
        CASE(0b0100,
             0b0011,
             0b01,S(KC_H))
        CASE(0b1010,
             0b0001,
             0b01,S(KC_I))
        CASE(0b0100,
             0b0001,
             0b01,S(KC_J))
        CASE(0b0000,
             0b0101,
             0b01,S(KC_K))
        CASE(0b0100,
             0b1001,
             0b01,S(KC_L))
        CASE(0b0100,
             0b1011,
             0b01,S(KC_M))
        CASE(0b1100,
             0b0001,
             0b01,S(KC_N))
        CASE(0b0110,
             0b0001,
             0b01,S(KC_O))
        CASE(0b1100,
             0b0011,
             0b01,S(KC_P))
        CASE(0b0010,
             0b0001,
             0b01,S(KC_Q))
        CASE(0b1000,
             0b0101,
             0b01,S(KC_R))
        CASE(0b0010,
             0b0101,
             0b01,S(KC_S))
        CASE(0b0000,
             0b0111,
             0b01,S(KC_T))
        CASE(0b1010,
             0b0101,
             0b01,S(KC_U))
        CASE(0b0000,
             0b0011,
             0b01,S(KC_V))
        CASE(0b1110,
             0b0001,
             0b01,S(KC_W))
        CASE(0b0000,
             0b1001,
             0b01,S(KC_X))
        CASE(0b0010,
             0b1101,
             0b01,S(KC_Y))
        CASE(0b1000,
             0b0001,
             0b01,S(KC_Z))

        CASE(0b0000,
             0b0111,
             0b00,KC_LBRC)
        CASE(0b1000,
             0b0001,
             0b00,KC_BSLASH)
        CASE(0b0000,
             0b1101,
             0b00,KC_RBRC)
        CASE(0b0100,
             0b0001,
             0b00,KC_CIRC)
        CASE(0b0000,
             0b1001,
             0b00,KC_UNDS)

        CASE(0b0000,
             0b1100,
             0b00,KC_A)
        CASE(0b0000,
             0b1110,
             0b00,KC_B)
        CASE(0b0010,
             0b1000,
             0b00,KC_C)
        CASE(0b1000,
             0b0010,
             0b00,KC_D)
        CASE(0b0000,
             0b1010,
             0b00,KC_E)
        CASE(0b0110,
             0b1000,
             0b00,KC_F)
        CASE(0b1000,
             0b0110,
             0b00,KC_G)
        CASE(0b0100,
             0b0010,
             0b00,KC_H)
        CASE(0b1010,
             0b0000,
             0b00,KC_I)
        CASE(0b0100,
             0b0000,
             0b00,KC_J)
        CASE(0b0000,
             0b0100,
             0b00,KC_K)
        CASE(0b0100,
             0b1000,
             0b00,KC_L)
        CASE(0b0100,
             0b1010,
             0b00,KC_M)
        CASE(0b1100,
             0b0000,
             0b00,KC_N)
        CASE(0b0110,
             0b0000,
             0b00,KC_O)
        CASE(0b1100,
             0b0010,
             0b00,KC_P)
        CASE(0b0010,
             0b0000,
             0b00,KC_Q)
        CASE(0b1000,
             0b0100,
             0b00,KC_R)
        CASE(0b0010,
             0b0100,
             0b00,KC_S)
        CASE(0b0000,
             0b0110,
             0b00,KC_T)
        CASE(0b1010,
             0b0100,
             0b00,KC_U)
        CASE(0b0000,
             0b0010,
             0b00,KC_V)
        CASE(0b1110,
             0b0000,
             0b00,KC_W)
        CASE(0b0000,
             0b1000,
             0b00,KC_X)
        CASE(0b0010,
             0b1100,
             0b00,KC_Y)
        CASE(0b1000,
             0b0000,
             0b00,KC_Z)

        CASE(0b0010,
             0b0101,
             0b00,KC_LCBR)
        CASE(0b0100,
             0b0010,
             0b01,KC_PIPE)
        CASE(0b1000,
             0b0101,
             0b00,KC_RCBR)
        CASE(0b1000,
             0b0000,
             0b01,KC_TILD)
        CASE(0b0000,
             0b0010,
             0b01,KC_DEL)

        /* CASE(0b0000, */
        /*      0b0000, */
        /*      0b00,S(KC_)) */
        /* CASE(0b0000, */
        /*      0b0000, */
        /*      0b00,KC_) */

    }
}

#include <print.h>
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(record->event.pressed){
        //uprintf("Pressed: %d, %d, %d", keycode, ROW,COL);
        if (keycode != XXXXXXX) {
            return true;
        }
        state |= 1<<(COL<3?((COL*MATRIX_COLS)+4-ROW%5):8+(2-ROW%5));
        return false;
    }
    //uprintf("Released: %d, %d, %d", keycode, ROW,COL);
    if(state > 0){
        //uprintf("State: %d",state);
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
