#include QMK_KEYBOARD_H


enum layers{
  _BASE,
  _FN
};

// HOME ROW MODS
#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LCTL_T(KC_S)
#define HOME_T LSFT_T(KC_T)
#define HOME_N RSFT_T(KC_N)
#define HOME_E RCTL_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RGUI_T(KC_O)

// Alias
#define LT_SPC LT(_FN, KC_SPC)


// combo
// l + u = bspc
// w + f = tab
const uint16_t PROGMEM lu_bspc[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM wf_tab[] = {KC_W, KC_F, COMBO_END};

combo_t key_combos[] = {
    COMBO(lu_bspc, KC_BSPC),
    COMBO(wf_tab, KC_TAB),
};


// Key Overrides aka ZMK's Mod-Morph
// Shift + .                  = :
// Ctrl  + Shift   + .        = >
// Shift + ,                  = ;
// Ctrl  + Shift   + ,        = <
// Shift + spc                = `
// Shift + esc                = ~
const key_override_t s_dot    = ko_make_basic(MOD_MASK_SHIFT, KC_DOT,  KC_COLON);
const key_override_t cs_dot   = ko_make_basic(MOD_MASK_CS,    KC_DOT,  KC_GT);
const key_override_t s_comma  = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
const key_override_t cs_comma = ko_make_basic(MOD_MASK_CS,    KC_COMM, KC_LT);
const key_override_t s_spc    = ko_make_basic(MOD_MASK_SHIFT, LT_SPC,  KC_GRV);
const key_override_t s_esc    = ko_make_basic(MOD_MASK_SHIFT, KC_ESC,  S(KC_GRV));
const key_override_t s_bspc   = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

const key_override_t *key_overrides[] = {
    &s_dot,
    &cs_dot,
    &s_comma,
    &cs_comma,
    &s_spc,
    &s_esc,
    &s_bspc
};


// Kinesis advantage2 keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base layer: Colemak
    [_BASE] = LAYOUT_kinesis_adv2(
      KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_SCRL,  KC_PAUS,  TG(_FN),    MO(_FN),
      KC_EQL,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,
      KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,                                   KC_J,     KC_L,     KC_U,     KC_Y,     KC_QUOT,  KC_BSLS,
      KC_CAPS,  HOME_A,   HOME_R,   HOME_S,   HOME_T,   KC_G,                                   KC_M,     HOME_N,   HOME_E,   HOME_I,   HOME_O,   KC_QUOT,
      KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,                                   KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                KC_GRV,   KC_INS,   KC_LEFT,  KC_RGHT,                                                    KC_UP,    KC_DOWN,  KC_LBRC,  KC_RBRC,
                                              KC_LCTL,  KC_LALT,                                KC_RGUI,  KC_RCTL,
                                                        KC_HOME,                                KC_PGUP,
                                    KC_ESC,   LT_SPC,   KC_END,                                 KC_PGDN,  KC_ENTER, KC_BSPC),
    [_FN] = LAYOUT_kinesis_adv2(
      QK_BOOT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,                                _______,  KC_NUM,   KC_PEQL,  KC_PSLS,  KC_PAST,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,                                _______,  KC_P7,    KC_P8,    KC_P9,    KC_PMNS,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,                                _______,  KC_P4,    KC_P5,    KC_P6,    KC_PPLS,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,                                _______,  KC_P1,    KC_P2,    KC_P3,    KC_PENT,  _______,
                _______,  _______,  _______,  _______,                                                    _______,  _______,  KC_PDOT,  KC_PENT,
                                              _______,  _______,                                _______,  _______,
                                                        _______,                                _______,
                                    _______,  _______,  _______,                                _______,  _______,  KC_P0)
};
