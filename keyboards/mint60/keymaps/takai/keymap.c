/* Copyright 2018 Eucalyn
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
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

#define LAYOUT_kc( \
  L00,L01,L02,L03,L04,L05,    R00,R01,R02,R03,R04,R05,R06,  R07, \
  L10,  L11,L12,L13,L14,L15,    R10,R11,R12,R13,R14,R15,R16,R17, \
  L20,   L21,L22,L23,L24,L25,    R20,R21,R22,R23,R24,R25,   R27, \
  L30,    L31,L32,L33,L34,L35,    R30,R31,R32,R33,R34,R35,R36,R37, \
  L40,L41, L42, L43,    L44,      R40, R41, R43,      R45,R46,R47 \
) \
{ \
  { KC_##L00, KC_##L01, KC_##L02, KC_##L03, KC_##L04, KC_##L05, KC_NO,    KC_NO }, \
  { KC_##L10, KC_##L11, KC_##L12, KC_##L13, KC_##L14, KC_##L15, KC_NO,    KC_NO }, \
  { KC_##L20, KC_##L21, KC_##L22, KC_##L23, KC_##L24, KC_##L25, KC_NO,    KC_NO }, \
  { KC_##L30, KC_##L31, KC_##L32, KC_##L33, KC_##L34, KC_##L35, KC_NO,    KC_NO }, \
  { KC_##L40, KC_##L41, KC_##L42, KC_##L43, KC_##L44, KC_NO,    KC_NO,    KC_NO }, \
  { KC_##R00, KC_##R01, KC_##R02, KC_##R03, KC_##R04, KC_##R05, KC_##R06, KC_##R07 }, \
  { KC_##R10, KC_##R11, KC_##R12, KC_##R13, KC_##R14, KC_##R15, KC_##R16, KC_##R17 }, \
  { KC_##R20, KC_##R21, KC_##R22, KC_##R23, KC_##R24, KC_##R25, KC_NO,    KC_##R27 }, \
  { KC_##R30, KC_##R31, KC_##R32, KC_##R33, KC_##R34, KC_##R35, KC_##R36, KC_##R37 }, \
  { KC_##R40, KC_##R41, KC_NO,    KC_##R43, KC_NO,    KC_##R45, KC_##R46, KC_##R47 }, \
}

#define _BASE 0
#define _FN1 1

#define KC_ KC_TRNS
#define KC_FN1 MO(_FN1)
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD
#define KC_RST RESET
#define KC_IME LALT(KC_GRV)

enum custom_keycodes {
  RGBRST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_kc(
    // |----+----+----+----+----+----|----+----+----+----+----+----+----+----+----|
        GESC, 1  , 2  , 3  , 4  , 5  , 6  , 7  , 8  , 9  , 0  ,MINS,EQL , BSPC    ,\
    // |----+----+----+----+----+----|----+----+----+----+----+----+----+---------|
        TAB   , Q  , W  , E  , R  , T  , Y  , U  , I  , O  , P  ,LBRC,RBRC, BSLS  ,\
    // |------+----+----+----+----+----|----+----+----+----+----+----+----+-------|
        LCTL   , A  , S  , D  , F  , G  , H  , J  , K  , L  ,SCLN,QUOT, ENT       ,\
    // |-------+----+----+----+----+----|----+----+----+----+----+----+-----------|
        LSFT     , Z  , X  , C  , V  , B  , N  , M  ,COMM,DOT ,SLSH,RSFT, UP ,FN1 ,\
    // |---------+----+----+----+----+----|----+----+----+----+---------+----+----|
        FN1 ,LCTL ,LALT ,LGUI , SPC      , SPC         ,RGUI ,RALT ,LEFT,DOWN,RGHT
    // |----+-----+-----+-----+----------|-------------+-----+-----+----+----+----|
  ),
  [_FN1] = LAYOUT_kc(
    // |----+----+----+----+----+----|----+----+----+----+----+----+----+----+----|
        GRV ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,VOLD,VOLU, DEL     ,\
    // |----+----+----+----+----+----|----+----+----+----+----+----+----+---------|
              ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,       ,\
    // |------+----+----+----+----+----|----+----+----+----+----+----+----+-------|
               ,RTOG,RMOD,RHUI,RSAI,RVAI,    ,    ,    ,    ,    ,    ,           ,\
    // |-------+----+----+----+----+----|----+----+----+----+----+----+-----------|
                 ,    ,    ,RHUD,RSAD,RVAD,    ,    ,    ,    ,    ,    ,    ,    ,\
    // |---------+----+----+----+----+----|----+----+----+----+---------+----+----|
            ,IME  ,     ,     ,          ,             ,     ,     ,    ,    ,RST
    // |----+-----+-----+-----+----------|-------------+-----+-----+----+----+----|
  ),
};

const uint16_t PROGMEM fn_actions[] = {

};

// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
