#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

//////////////////////////////////////////////////////////
////////////////////////COMBOS////////////////////////////
//////////////////////////////////////////////////////////
// Maybe overlapping combos will be implemented. One day ...
// const uint16_t PROGMEM t[] = {KC_V, KC_K, COMBO_END};
// const uint16_t PROGMEM a[] = {KC_K, KC_X, COMBO_END};
// const uint16_t PROGMEM e[] = {KC_V, KC_X, COMBO_END};
// const uint16_t PROGMEM b[] = {KC_V, KC_K, KC_X, COMBO_END};

// combo_t key_combos[COMBO_COUNT] = {
//   COMBO(t, KC_T),
//   COMBO(a, KC_A),
//   COMBO(e, KC_E),
//   COMBO(b, KC_B)
// };

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     LAYOUT_planck_grid(
//     XXXXXXX ,KC_Q   ,KC_J   ,KC_Z   ,XXXXXXX,RESET  ,RESET  ,XXXXXXX,KC_Z   ,KC_J   ,KC_Q   ,XXXXXXX,
//     KC_TAB  ,KC_V   ,KC_K   ,KC_X   ,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_X   ,KC_K   ,KC_V   ,KC_TAB ,
//     KC_ENT  ,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_ENT ,
//     XXXXXXX ,XXXXXXX,XXXXXXX,KC_SPC ,KC_BSPC,XXXXXXX,XXXXXXX,KC_BSPC,KC_SPC ,XXXXXXX,XXXXXXX,XXXXXXX)
// };
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_planck_grid(
    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,RESET   , RESET  ,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX , XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    XXXXXXX,XXXXXXX,KC_0   ,KC_1   ,KC_2   ,KC_3    , KC_6   ,KC_7   ,KC_8   ,KC_9   ,XXXXXXX,XXXXXXX,
    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_4    , KC_5   ,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX)
};

static uint32_t state;

#define ROW record->event.key.row
#define COL record->event.key.col

#define CASE(val,KC) case val:tap_code(KC);break;
#define CAP(val,KC) case val:register_code(KC_LSFT);tap_code(KC);unregister_code(KC_LSFT);break;

#define OS(val,mod) case val:set_oneshot_mods(mod);break;

static void process(uint32_t val){
    switch(val){
        CASE(640,KC_E)
        CASE(384,KC_T)
        CASE(768,KC_A)
        CASE(10,KC_I)
        CASE(6,KC_O)
        CASE(12,KC_N)
        CASE(258,KC_S)
        CASE(264,KC_R)
        CASE(132,KC_H)
        CASE(516,KC_L)
        CASE(514,KC_C)
        CASE(136,KC_D)
        CASE(266,KC_U)
        CASE(644,KC_M)
        CASE(518,KC_F)
        CASE(140,KC_P)
        CASE(392,KC_G)
        CASE(770,KC_Y)
        CASE(896,KC_B)
        CASE(14,KC_W)
        CASE(128,KC_V)
        CASE(256,KC_K)
        CASE(512,KC_X)
        CASE(2,KC_Q)
        CASE(4,KC_J)
        CASE(8,KC_Z)

        CAP(2097856,KC_E)
        CAP(2097600,KC_T)
        CAP(2097984,KC_A)
        CAP(2097226,KC_I)
        CAP(2097222,KC_O)
        CAP(2097228,KC_N)
        CAP(2097474,KC_S)
        CAP(2097480,KC_R)
        CAP(2097348,KC_H)
        CAP(2097732,KC_L)
        CAP(2097730,KC_C)
        CAP(2097352,KC_D)
        CAP(2097482,KC_U)
        CAP(2097860,KC_M)
        CAP(2097734,KC_F)
        CAP(2097356,KC_P)
        CAP(2097608,KC_G)
        CAP(2097986,KC_Y)
        CAP(2098112,KC_B)
        CAP(2097230,KC_W)
        CAP(2097344,KC_V)
        CAP(2097472,KC_K)
        CAP(2097728,KC_X)
        CAP(2097218,KC_Q)
        CAP(2097220,KC_J)
        CAP(2097224,KC_Z)

        CASE(704,KC_EQUAL)
        CASE(448,KC_LBRC)
        CASE(832,KC_RBRC)
        CAP(74,KC_EQUAL)
        CAP(70,KC_9)
        CAP(76,KC_0)
        CASE(578,KC_MINUS)
        CAP(322,KC_LBRC)
        CAP(328,KC_RBRC)
        CAP(200,KC_8)
        CAP(196,KC_COMM)
        CAP(580,KC_DOT)
        CASE(330,KC_2)
        CASE(708,KC_3)
        CASE(582,KC_4)
        CASE(204,KC_5)
        CASE(456,KC_6)
        CASE(834,KC_7)
        CASE(960,KC_8)
        CASE(78,KC_9)
        CASE(192,KC_0)
        CASE(320,KC_1)
        CAP(576,KC_MINUS)
        CASE(66,KC_SLASH)
        CAP(68,KC_6)
        CASE(72,KC_BSLS)

        CAP(2097792,KC_QUOT)
        CASE(2097920,KC_DOT)
        CASE(2097536,KC_COMM)
        CASE(2097162,KC_QUOT)
        CASE(2097158,KC_SCLN)
        CAP(2097164,KC_SCLN)
        CAP(2097666,KC_2)
        CAP(2097410,KC_SLASH)
        CAP(2097416,KC_1)
        CAP(2097288,KC_3)
        CAP(2097284,KC_BSLS)
        CAP(2097668,KC_7)
        CASE(2097418,KC_DOWN)
        CASE(2097796,KC_UP)
        CASE(2097670,KC_LEFT)
        CASE(2097292,KC_RIGHT)
        CASE(2097544,KC_PGUP)
        CASE(2097922,KC_PGDN)
        CASE(2098048,KC_END)
        CASE(2097166,KC_HOME)
        CASE(2097280,KC_DEL)
        CASE(2097408,KC_ESC)
        CAP(2097664,KC_4)
        CAP(2097154,KC_5)
        CASE(2097156,KC_GRAVE)
        CAP(2097160,KC_GRAVE)

        OS(4992,MOD_LCTL)
        OS(4736,MOD_LSFT)
        OS(4480,MOD_LALT)
        OS(4864,MOD_LGUI)
        OS(4106,(MOD_LCTL | MOD_LSFT))
        OS(4102,(MOD_LCTL | MOD_LALT))
        OS(4108,(MOD_LCTL | MOD_LGUI))

        CASE(4096      ,KC_ENTER)
        CASE(64        ,KC_TAB)
        CASE(2097152   ,KC_SPACE)
        CASE(4194304   ,KC_BSPACE)
    };
}

// Keep track of left and right so you can send if it switches?
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(record->event.pressed){
        if(keycode != XXXXXXX){
            return true;
        }
        if(ROW<3){
            state |= (1<<(ROW*MATRIX_COLS+COL));
        }else if(3<ROW && ROW<7){
            state |= (1<<((ROW-4)*MATRIX_COLS+(MATRIX_COLS-COL-1)));
        }else if(ROW == 7 && COL>2){
            state |= (1<<((ROW-4)*MATRIX_COLS+COL));
        }else if(ROW == 7 && COL<3){
            state |= (1<<((ROW-4)*MATRIX_COLS+(MATRIX_COLS-COL-1)));
        }
        return false;
    }else{
        if(state > 0){
            process(state);
            state = 0;
            return false;
        }else{
            return true;
        }
    }
}
