#include QMK_KEYBOARD_H
#include "keymap_swedish.h"
#include "moonlander.h"
#include "version.h"


enum layers {
    BASE,  // default layer
    LSYMB,  // symbols
    RSYMB,  // symbols
    RSYMBEXT,  // symbols
    MDIA,  // media keys
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT(
//    ┌──────┬─────────────┬─────────┬─────────┬────────────────┬─────────────┬───────────┐   ┌──────────┬─────────────┬─────────────────┬─────────┬────────┬────────┬──────┐
//    │  =   │      1      │    2    │    3    │       4        │      5      │   left    │   │   rght   │      6      │        7        │    8    │   9    │   0    │  -   │
//    ├──────┼─────────────┼─────────┼─────────┼────────────────┼─────────────┼───────────┤   ├──────────┼─────────────┼─────────────────┼─────────┼────────┼────────┼──────┤
//    │ del  │      Q      │    W    │    E    │       R        │      T      │    no     │   │    no    │      Y      │        U        │    I    │   O    │   P    │  \   │
//    ├──────┼─────────────┼─────────┼─────────┼────────────────┼─────────────┼───────────┤   ├──────────┼─────────────┼─────────────────┼─────────┼────────┼────────┼──────┤
//    │ bspc │   CMD<A>    │ ALT<S>  │ CTRL<D> │      ↑<F>      │      G      │ csag-none │   │ csa-none │      H      │      ↑<J>       │ CTRL<K> │ ALT<L> │ CMD<*> │  '   │
//    ├──────┼─────────────┼─────────┼─────────┼────────────────┼─────────────┼───────────┘   └──────────┼─────────────┼─────────────────┼─────────┼────────┼────────┼──────┤
//    │ lsft │      Z      │    X    │    C    │       V        │      B      │                          │      N      │ MT(alt|ctrl, M) │    ,    │   .    │   _    │ rsft │
//    ├──────┼─────────────┼─────────┼─────────┼────────────────┼─────────────┤                          ├─────────────┼─────────────────┼─────────┼────────┼────────┼──────┤
//    │  no  │ WEBUSB_PAIR │ A(lsft) │  left   │      rght      │ LALT_T(app) │                          │ RCTL_T(esc) │       up        │  down   │   [    │   ]    │  no  │
//    └──────┴─────────────┴─────────┴─────────┼────────────────┼─────────────┼───────────┐   ┌──────────┼─────────────┼─────────────────┼─────────┴────────┴────────┴──────┘
//                                             │ LT(RSYMB, spc) │    bspc     │    no     │   │   esc    │     tab     │ LT(LSYMB, ent)  │
//                                             └────────────────┴─────────────┴───────────┘   └──────────┴─────────────┴─────────────────┘
  SE_EQL  , SE_1        , SE_2       , SE_3    , SE_4              , SE_5           , KC_LEFT ,     KC_RGHT , SE_6           , SE_7                        , SE_8    , SE_9    , SE_0     , SE_MINS,
  KC_DEL  , SE_Q        , SE_W       , SE_E    , SE_R              , SE_T           , KC_NO   ,     KC_NO   , SE_Y           , SE_U                        , SE_I    , SE_O    , SE_P     , SE_BSLS,
  KC_BSPC , A_LCMD      , S_LALT     , D_LCTL  , F_LSFT            , SE_G           , KC_HYPR ,     KC_MEH  , SE_H           , J_RSFT                      , K_RCTL  , L_RALT  , STR_RCMD , SE_QUOT,
  KC_LSFT , SE_Z        , SE_X       , SE_C    , SE_V              , SE_B           ,                         SE_N           , MT(MOD_LALT|MOD_LCTL, SE_M) , SE_COMM , SE_DOT  , SE_UNDS  , KC_RSFT,
  KC_NO   , WEBUSB_PAIR , A(KC_LSFT) , KC_LEFT , KC_RGHT           , LALT_T(KC_APP) ,                         RCTL_T(KC_ESC) , KC_UP                       , KC_DOWN , KC_LBRC , KC_RBRC  , KC_NO  ,
                                                 LT(RSYMB, KC_SPC) , KC_BSPC        , KC_NO   ,     KC_ESC  , KC_TAB         , LT(LSYMB, KC_ENT)
),

[LSYMB] = LAYOUT(
//    ┌──────┬─────┬─────┬─────┬─────┬─────┬───────────┐   ┌──────────┬─────┬─────┬─────┬─────┬─────┬──────────┐
//    │  =   │  1  │  2  │  3  │  4  │  5  │   left    │   │   rght   │  6  │  7  │  8  │  9  │  0  │    -     │
//    ├──────┼─────┼─────┼─────┼─────┼─────┼───────────┤   ├──────────┼─────┼─────┼─────┼─────┼─────┼──────────┤
//    │ del  │  \  │  /  │  (  │  )  │  _  │    no     │   │    no    │ no  │ no  │ no  │ no  │ no  │ ` (dead) │
//    ├──────┼─────┼─────┼─────┼─────┼─────┼───────────┤   ├──────────┼─────┼─────┼─────┼─────┼─────┼──────────┤
//    │ bspc │  :  │  -  │  [  │  ]  │  .  │ csag-none │   │ csa-none │ no  │ no  │ no  │ no  │ no  │ ` (dead) │
//    ├──────┼─────┼─────┼─────┼─────┼─────┼───────────┘   └──────────┼─────┼─────┼─────┼─────┼─────┼──────────┤
//    │ lsft │  ?  │  +  │  {  │  }  │  ,  │                          │ no  │ no  │ no  │ no  │ no  │ ` (dead) │
//    ├──────┼─────┼─────┼─────┼─────┼─────┤                          ├─────┼─────┼─────┼─────┼─────┼──────────┤
//    │      │     │     │     │     │     │                          │     │     │     │     │     │    no    │
//    └──────┴─────┴─────┴─────┼─────┼─────┼───────────┐   ┌──────────┼─────┼─────┼─────┴─────┴─────┴──────────┘
//                             │     │     │           │   │          │     │     │
//                             └─────┴─────┴───────────┘   └──────────┴─────┴─────┘
  SE_EQL  , SE_1    , SE_2    , SE_3    , SE_4    , SE_5    , KC_LEFT ,     KC_RGHT , SE_6    , SE_7    , SE_8    , SE_9    , SE_0    , SE_MINS,
  KC_DEL  , SE_BSLS , SE_SLSH , SE_LPRN , SE_RPRN , SE_UNDS , KC_NO   ,     KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , SE_GRV ,
  KC_BSPC , SE_COLN , SE_MINS , SE_LBRC , SE_RBRC , SE_DOT  , KC_HYPR ,     KC_MEH  , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , SE_GRV ,
  KC_LSFT , SE_QUES , SE_PLUS , SE_LCBR , SE_RCBR , SE_COMM ,                         KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , SE_GRV ,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                         KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_NO  ,
                                          KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS
),

[RSYMB] = LAYOUT(
//    ┌──────────┬─────┬─────┬─────┬─────┬─────┬───────────┐   ┌──────────┬─────┬─────┬─────┬─────┬─────┬──────────┐
//    │    =     │  1  │  2  │  3  │  4  │  5  │   left    │   │   rght   │  6  │  7  │  8  │  9  │  0  │    -     │
//    ├──────────┼─────┼─────┼─────┼─────┼─────┼───────────┤   ├──────────┼─────┼─────┼─────┼─────┼─────┼──────────┤
//    │   del    │ no  │ no  │ no  │ no  │ no  │    no     │   │    no    │  +  │  (  │  -  │  /  │  |  │ ` (dead) │
//    ├──────────┼─────┼─────┼─────┼─────┼─────┼───────────┤   ├──────────┼─────┼─────┼─────┼─────┼─────┼──────────┤
//    │   bspc   │ no  │ no  │ no  │ no  │ no  │ csag-none │   │ csa-none │  "  │  [  │  .  │  '  │  !  │ ` (dead) │
//    ├──────────┼─────┼─────┼─────┼─────┼─────┼───────────┘   └──────────┼─────┼─────┼─────┼─────┼─────┼──────────┤
//    │   lsft   │ no  │ no  │ no  │ no  │ no  │                          │  #  │  {  │  ,  │  <  │  &  │ ` (dead) │
//    ├──────────┼─────┼─────┼─────┼─────┼─────┤                          ├─────┼─────┼─────┼─────┼─────┼──────────┤
//    │ ` (dead) │     │     │     │     │     │                          │     │     │     │     │     │    no    │
//    └──────────┴─────┴─────┴─────┼─────┼─────┼───────────┐   ┌──────────┼─────┼─────┼─────┴─────┴─────┴──────────┘
//                                 │     │     │           │   │          │     │     │
//                                 └─────┴─────┴───────────┘   └──────────┴─────┴─────┘
  SE_EQL  , SE_1    , SE_2    , SE_3    , SE_4    , SE_5    , KC_LEFT ,     KC_RGHT , SE_6    , SE_7    , SE_8    , SE_9    , SE_0    , SE_MINS,
  KC_DEL  , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,     KC_NO   , SE_PLUS , SE_LPRN , SE_MINS , SE_SLSH , SE_PIPE , SE_GRV ,
  KC_BSPC , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_HYPR ,     KC_MEH  , SE_DQUO , SE_LBRC , SE_DOT  , SE_QUOT , SE_EXLM , SE_GRV ,
  KC_LSFT , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,                         SE_HASH , SE_LCBR , SE_COMM , SE_LABK , SE_AMPR , SE_GRV ,
  SE_GRV  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                         KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_NO  ,
                                          KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS
),

[RSYMBEXT] = LAYOUT(
//    ┌──────────┬─────┬─────┬─────┬─────┬─────┬───────────┐   ┌──────────┬─────┬─────┬─────┬─────┬──────┬─────┐
//    │    =     │  1  │  2  │  3  │  4  │  5  │   left    │   │   rght   │  6  │  7  │  8  │  9  │  0   │  -  │
//    ├──────────┼─────┼─────┼─────┼─────┼─────┼───────────┤   ├──────────┼─────┼─────┼─────┼─────┼──────┼─────┤
//    │   del    │ no  │ no  │ no  │ no  │ no  │    no     │   │    no    │  ?  │  )  │  _  │  \  │  `   │     │
//    ├──────────┼─────┼─────┼─────┼─────┼─────┼───────────┤   ├──────────┼─────┼─────┼─────┼─────┼──────┼─────┤
//    │   bspc   │ no  │ no  │ no  │ no  │ no  │ csag-none │   │ csa-none │  $  │  ]  │  :  │  *  │  @   │     │
//    ├──────────┼─────┼─────┼─────┼─────┼─────┼───────────┘   └──────────┼─────┼─────┼─────┼─────┼──────┼─────┤
//    │   lsft   │ no  │ no  │ no  │ no  │ no  │                          │ no  │  }  │  ;  │  >  │ perc │     │
//    ├──────────┼─────┼─────┼─────┼─────┼─────┤                          ├─────┼─────┼─────┼─────┼──────┼─────┤
//    │ ` (dead) │     │     │     │     │     │                          │     │     │     │     │      │ no  │
//    └──────────┴─────┴─────┴─────┼─────┼─────┼───────────┐   ┌──────────┼─────┼─────┼─────┴─────┴──────┴─────┘
//                                 │     │     │           │   │          │     │     │
//                                 └─────┴─────┴───────────┘   └──────────┴─────┴─────┘
  SE_EQL  , SE_1    , SE_2    , SE_3    , SE_4    , SE_5    , KC_LEFT ,     KC_RGHT , SE_6    , SE_7    , SE_8    , SE_9    , SE_0    , SE_MINS,
  KC_DEL  , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,     KC_NO   , SE_QUES , SE_RPRN , SE_UNDS , SE_BSLS , KC_GRV  , KC_TRNS,
  KC_BSPC , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_HYPR ,     KC_MEH  , SE_DLR  , SE_RBRC , SE_COLN , SE_ASTR , SE_AT   , KC_TRNS,
  KC_LSFT , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,                         KC_NO   , SE_RCBR , SE_SCLN , SE_RABK , SE_PERC , KC_TRNS,
  SE_GRV  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                         KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_NO  ,
                                          KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}

