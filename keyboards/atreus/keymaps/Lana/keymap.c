// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _RS 1
#define _LW 2
#define FUNK 3
#define SFTTAB SFT_T(KC_TAB)
#define SFTSPC SFT_T(KC_SPC)
#define ALTSPC MT(MOD_LALT, KC_SPC)
#define SFTENT SFT_T(KC_ENT)
#define FUNKENT MT(FUNK, KC_ENT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_Q  ,    KC_W   ,    KC_E   ,    KC_R   ,    KC_T  ,                  KC_Y   ,  KC_U   ,    KC_I   , KC_O   , KC_P   ,
    KC_A  ,    KC_S   ,    KC_D   ,    KC_F   ,    KC_G  ,                  KC_H   ,  KC_J   ,    KC_K   , KC_L   , KC_SCLN,
    KC_Z  ,    KC_X   ,    KC_C   ,    KC_V   ,    KC_B  ,                  KC_N   ,  KC_M   ,    KC_COMM, KC_DOT , KC_SLSH,
    KC_ESC,    KC_LCTL,    KC_LGUI,    TT(_RS),    ALTSPC,  SFTTAB, SFTSPC, FUNKENT,  TT(_LW),    KC_BSPC, KC_QUOT, KC_ENT
  ),
  /*
   *  1       2      3     4    5            ||        6       7     8     9    0
   *  #     left   down  right  $            ||        -       4     5     6    *
   *  [       ]      (     )    &            ||        +       1     2     3    /
   * esc     ctl    gui  raise altspc sfttab || space sftent   0     .     ENT  =
   */
  [_RS] = LAYOUT( /* [> RAISE <] */
    KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                 KC_6   , KC_7, KC_8   , KC_9  , KC_0     ,
    KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR ,                 KC_PMNS, KC_4, KC_5   , KC_6  , KC_ASTR ,
    KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                 KC_PPLS, KC_1, KC_2   , KC_3  , KC_PSLS  ,
    KC_ESC , KC_LCTL, KC_LGUI, TT(_RS), ALTSPC , SFTTAB, SFTSPC ,FUNKENT, KC_0, KC_PDOT, KC_ENT, KC_EQL
  ),


  /*
     *  1       2      3     4    5        ||     pgup    7     8     9    *
     *  F1     F2     F3    F4    F5       ||     pgdn    4     5     6    +
     *  F6     F7     F8    F9    F10      ||       `     1     2     3    \
     * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
     */
    [FUNK] = LAYOUT( /* [> RAISE <] */
      KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR,                 KC_PGUP, KC_7,    KC_8,    KC_9,    KC_ASTR ,
      KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,                  KC_PGDN, KC_4,    KC_5,    KC_6,    KC_PLUS ,
      KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                 KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS ,
      KC_ESC , KC_LCTL, KC_LGUI, TT(_RS), ALTSPC,  SFTTAB, SFTSPC, FUNKENT, TT(_LW), KC_BSPC, KC_QUOT, KC_ENT
      ),
  /*
   * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
   *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
   *       volup             reset      ||             F1    F2    F3   F12
   *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
   */
  [_LW] = LAYOUT( /* [> LOWER <] */
    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
    KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
    KC_NO,   KC_VOLU, KC_NO,   KC_NO,   RESET,                     KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    KC_ESC,  KC_LCTL, KC_LGUI, TT(_RS), ALTSPC,  SFTTAB, SFTSPC, FUNKENT,  TT(_LW),  KC_BSPC, KC_QUOT, KC_ENT
  )
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
    break;
  }
  return MACRO_NONE;
};
