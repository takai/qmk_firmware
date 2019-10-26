/* Copyright 2019 Erovia
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
#include QMK_KEYBOARD_H

enum custom_layers {
    _BASE,
    _NUMS,
    _SYMS,
    _FN,
};


#define KC_NUMS LT(_NUMS, KC_SPACE)
#define KC_SYMS LT(_SYMS, KC_SPACE)
#define KC_FN MO(_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
    KC_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPACE,
    KC_LCTRL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_ENTER,
    KC_LSHIFT,KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH,
    KC_FN, KC_LALT, KC_LGUI, KC_NUMS, KC_SYMS, KC_RGUI, KC_RALT, KC_FN
  ),

  [_NUMS] = LAYOUT(
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLASH,
    KC_TAB, _______, _______, _______, _______, _______, KC_MINS, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_EQL, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_SYMS] = LAYOUT(
    KC_TILDE, KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_MINUS,
    KC_TAB,  _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_FN] = LAYOUT(
    RESET, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_DELETE,
    _______, RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______, _______, _______,
    _______, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, _______, _______, _______, _______, KC_UP,   _______,
    _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT
  ),
};

void led_set_user(uint8_t usb_led) {
if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
	dimple_led_on();
	} else {
	dimple_led_off();
	}
}
