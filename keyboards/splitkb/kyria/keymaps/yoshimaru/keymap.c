/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// NOTE
// qmk compile -kb splitkb/kyria/rev2 -km yoshimaru

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _SYM,
    _FUNCTION,
};

// Aliases for readability
#define QWERTY DF(_QWERTY)
#define SYM MO(_SYM)
#define FKEYS MO(_FUNCTION)

#define CTL_ESC CTL_T(KC_ESC)
#define CTL_SPC CTL_T(KC_SPC)
#define CTL_TAB MT(MOD_LCTL, KC_TAB)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT MT(MOD_LALT, KC_ENT)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// TODO
// - [ ] Remove CTL_T(KC_SPC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                                      ,-------------------------------------------.
 * |  Esc   |   Q  |   W  |   E  |   R  |   T  |                                      |   Y  |   U  |   I  |   O  |   P  |  DEL   |
 * |--------+------+------+------+------+------|                                      |------+------+------+------+------+--------|
 * |  Tab   |   A  |   S  |   D  |   F  |   G  |                                      |   H  |   J  |   K  |   L  | ; : |  Bksp  |
 * |--------+------+------+------+------+------+-------------.          ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |      |          |      | ] } |   N  |   M  | ,  < | . >  | /  ? | ' "    |
 * `----------------------+------+------+------+------+------|          |------+------+------+------+------+----------------------'
 *                        | MUTE | LALT | LGUI | Sym  |Ctrl/ |          |Shift/| FKEYS| RGUI |      |      |
 *                        |      |      |      |      |SPC   |          |Enter |      |      |      |      |
 *                        `----------------------------------'          `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
     KC_ESC  , KC_Q , KC_W, KC_E , KC_R ,   KC_T   ,                                                 KC_Y   , KC_U   , KC_I   , KC_O  , KC_P      , KC_DEL ,
     KC_TAB  , KC_A , KC_S, KC_D , KC_F ,   KC_G   ,                                                 KC_H   , KC_J   , KC_K   , KC_L  , KC_SCLN   , KC_BSPC,
     KC_LSFT , KC_Z , KC_X, KC_C , KC_V ,   KC_B   , KC_LBRC , _______       , _______   , KC_RBRC , KC_N   , KC_M   , KC_COMM, KC_DOT, KC_SLSH   , KC_QUOT,
                         KC_MUTE , KC_LALT, KC_LGUI, SYM     , CTL_SPC       , KC_SFTENT , FKEYS   , KC_RGUI, _______, _______
    ),

// NOTE
// ` , ~ , \ , |
// ガーブ、チルダ、バクスラ、パイプ
// - , _ , = , +
// ハイフン、アンスコ、イコール、プラス

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                                      ,-------------------------------------------.
 * |        |  !   |  @   |  #   |  $   |  %   |                                      |   ^  |  &   |  *   |  {   |  }   |        |
 * |--------+------+------+------+------+------|                                      |------+------+------+------+------+--------|
 * |        |      |      |  \   |  `   |      |                                      |      |  -   |  =   |  (   |  )   |        |
 * |--------+------+------+------+------+------+-------------.          ,-------------+------+------+------+------+------+--------|
 * |        |      |      |  |   |  ~   |      |      |      |          |      |      |      |  _   |  +   |  <   |  >   |        |
 * `----------------------+------+------+------+------+------|          |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |          |      |      |      |      |      |
 *                        `----------------------------------'          `----------------------------------'
 */
    [_SYM] = LAYOUT(
     _______ , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, _______,
     _______ , _______, _______, KC_BSLS , KC_GRV, _______,                                     _______, KC_MINS, KC_EQL , KC_LPRN, KC_RPRN, _______,
     _______ , _______, _______, KC_PIPE, KC_TILD, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LABK, KC_RABK, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),



/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                                      ,-------------------------------------------.
 * |        |  1   |  2   |  3   |  4   |  5   |                                      |   6  |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|                                      |------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |                                      |      | Left | Down |  UP  | Right|        |
 * |--------+------+------+------+------+------+-------------.          ,-------------+------+------+------+------+------+--------|
 * |        |  F6  |  F7  |  F8  |  F9  |  F10 | F11  | F12  |          |      |      |      |      | VOLD | VOLU |      |        |
 * `----------------------+------+------+------+------+------|          |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |          |      |      |      |      |      |
 *                        `----------------------------------'          `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      _______,  KC_1   ,  KC_2   ,  KC_3  ,  KC_4  , KC_5   ,                                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
      _______,  KC_F1  ,  KC_F2  ,  KC_F3 ,  KC_F4 , KC_F5  ,                                     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
      _______,  KC_F6  ,  KC_F7  ,  KC_F8 ,  KC_F9 , KC_F10 , KC_F11 , KC_F12 , _______, _______, _______, KC_VOLD, KC_VOLU, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};
// clang-format on

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

static void render_status(void) {
    // QMK Logo and version information
    // clang-format off
    static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };
    // clang-format on

    oled_write_P(qmk_logo, false);
    oled_write_P(PSTR("Yoshimaru rev2.1\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWERTY\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("SYMBOL\n"), false);
            break;
        case _FUNCTION:
            oled_write_P(PSTR("FUNCTION\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // Master
        render_status();
    } else {
        // Slave
        // Do nothing
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Next Tab/Previous Tab
        if (clockwise) {
            tap_code16(G(S(KC_RBRC)));
        } else {
            tap_code16(G(S(KC_LBRC)));
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
#endif
