/* Good on you for modifying your layout! if you don't have 
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H

#define IGNORE_MOD_TAP_INTERRUPT
#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion
#define FUNK 3


// Blank template at the bottom

enum customKeycodes {
	URL  = 1,
  FLSH = SAFE_RANGE,
};

  
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Basic layer
   *
   * ,-------------------------------------------.                         ,-------------------------------------------.
   * | L1/ESC |   Q  |   W  |   F  |   R  |   G  |                         |   Y  |   U  |   I  |   O  |   P  |  | \   |
   * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
   * |Ctrl/BS |   A  |   S  |  D   |   T  |   J  | RMB  |           | FUNC |   H  |   N  |   E  |   L  | ;  : |  ' "   |
   * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
   * | LShift |   Z  |   X  |   C  |   V  |   B  | LMB  |           |      |   K  |   M  | ,  < | . >  | /  ? |  - _   |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *                    .----------.   .-------.                                 .------.   .-----.
   *                    | Super/Del|   |SPC/ALT|                                 |SPC/FNC|  |BKSP |
   *                    '----------'   '-------'                                 `------.   '-----'
   *                                        ,-------.                      ,-------.
   *                                        | MMB   |                      | PgDn  |
   *                                 ,------|-------|                      |-------|------.
   *                                 | TAB  | NUMB  |                      | SYMB  | SHFT |
   *                                 | SHFT |       |                      |       |  ENT |
   *                                 |      |       |                      |       |      |
   *                                 `--------------'                      `--------------'
   */
  [BASE] = LAYOUT_GERGO(
  LT(NUMB, KC_ESC),       KC_Q,  KC_W,   KC_F,   KC_R, KC_G,                       KC_Y,    KC_U, KC_I, KC_O,   KC_P,    KC_PIPE,
  MT(MOD_LCTL, KC_BSPC),  KC_A,  KC_S,   KC_D,   KC_T, KC_J, KC_BTN2,       TT(FUNK),  KC_H,    KC_N, KC_E, KC_L,   KC_SCLN, KC_QUOT,
  KC_RSFT,                KC_Z,  KC_X,   KC_C,   KC_V, KC_B, KC_BTN1,       KC_BSPC,  KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS,

                      MT(MOD_LGUI, KC_DEL), MT(MOD_LALT, KC_SPC),       LT(FUNK, KC_SPC), KC_BSPC,

                                                  KC_BTN3,       KC_PGDN,
                                  SFT_T(KC_TAB), TT(NUMB),       TT(SYMB), SFT_T(KC_ENT)),
  /* Keymap 1: Symbols layer
   *
   * ,-------------------------------------------.                         ,-------------------------------------------.
   * |        |  !   |  @   |  {   |  }   |  |   |                         |      |      |      |      |      |  \ |   |
   * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
   * |        |  #   |  $   |  (   |  )   |  `   |      |           |      |   +  |  -   |  /   |  *   |  %   |  ' "   |
   * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
   * |        |  %   |  ^   |  [   |  ]   |  ~   |      |           |      |   &  |  =   |  ,   |  .   |  / ? | - _    |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *                        .------.   .------.                                 .------.   .-----.
   *                        |      |   |      |                                 |      |   | DEL |
   *                        '------'   '------'                                 `------.   '-----'
   *                                        ,-------.                     ,-------.
   *                                        |       |                     | PgUp  |
   *                                 ,------|-------|                     |-------|------.
   *                                 |      |       |                     |       |      |
   *                                 |      |       |                     |       |      |
   *                                 |      |       |                     |       |      |
   *                                 `--------------'                     `--------------'
   */
  [SYMB] = LAYOUT_GERGO(
  KC_TRNS, KC_EXLM, KC_AT,  KC_LCBR,KC_RCBR, KC_PIPE,                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS,
  KC_TRNS, KC_HASH, KC_DLR, KC_LPRN,KC_RPRN, KC_GRV,  KC_TRNS,       KC_TRNS,  KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_PERC, KC_QUOT,
  KC_TRNS, KC_PERC, KC_CIRC,KC_LBRC,KC_RBRC, KC_TILD, KC_TRNS,       KC_TRNS,  KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,

                                                    KC_TRNS, KC_TRNS,       KC_TRNS, KC_DEL,
                                                             KC_TRNS,       KC_PGUP,
                                                  KC_SCLN, KC_TRNS,        KC_TRNS, KC_TRNS),
/* Keymap 2: Pad/Function layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                         |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |  F1    |  F2  | F3   | F4   | F5   | F6   | BTN1 |           |      | LEFT | DOWN |  UP  | RIGHT|VolDn | VolUp  |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |  F7    |  F8  | F9   | F10  | F11  | F12  | BTN2 |           |      | MLFT | MDWN | MUP  | MRGHT|Ply/Pa|  Skip  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     | PgUp  |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[FUNK] = LAYOUT_GERGO(  
KC_TRNS, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS, 
KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,         KC_TRNS,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLD, KC_VOLU, 
KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,        KC_TRNS,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_MPLY, KC_MNXT, 

                                                  KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS,
                                                           KC_TRNS,       KC_TRNS,
                                             	  KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS),


/* Keymap template 
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |   1  |  2   |   3  |  4   |  5   |                         |  6   |  7   |  8   | 9    |  0   | BKSP   |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      |  w   |  e   |  r   |  T   |      |           |flsh  |   -  |  4   |  5   |  6   |  *   |   =    |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |  a   |  s   |  d   |   f  |      |      |           |      |   +  |  1   |  2   |  3   |  /   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |   s  |   |  spc |                                 |   0  |   |  .  |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
 */

[NUMB] = LAYOUT_GERGO(  
KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5   ,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, 
KC_TRNS, KC_TRNS, KC_W, KC_E, KC_R   , KC_T , KC_TRNS,       FLSH,  KC_PMNS, KC_4,    KC_5,    KC_6,    KC_PAST, KC_EQL, 
KC_TRNS, KC_A   , KC_S, KC_D, KC_F   , KC_TRNS, KC_TRNS,       KC_TRNS,  KC_PPLS, KC_1,    KC_2,    KC_3,    KC_PSLS, KC_TRNS, 

                                                  KC_C   , KC_SPC,       KC_0,    KC_PDOT,
                                                           KC_TRNS,       KC_TRNS,
                                             	  KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS)

};


 /* Keymap template
  *
  * ,-------------------------------------------.                         ,-------------------------------------------.
  * |        |      |      |      |      |      |                         |      |      |      |      |      |        |
  * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
  * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *                        .------.   .------.                                 .------.   .-----.
  *                        |      |   |      |                                 |      |   |     |
  *                        '------'   '------'                                 `------.   '-----'
  *                                        ,-------.       ,-------.
  *                                        |       |       |       |
  *                                 ,------|-------|       |-------|------.
  *                                 |      |       |       |       |      |
  *                                 |      |       |       |       |      |
  *                                 |      |       |       |       |      |
  *                                 `--------------'       `--------------'
 [SYMB] = LAYOUT_GERGO(
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,

                                                   KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS,
                                                            KC_TRNS,       KC_TRNS,
                                                 KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS),
  */
// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    //uint8_t layer = biton32(layer_state);
    biton32(layer_state);
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case FLSH:
    if (record->event.pressed) {
      // when keycode QMKBEST is pressed
      SEND_STRING("QMK is the best thing ever!");
    }
    else {
      // when keycode QMKBEST is released
    }
    break;

  }
  return true;
};  
