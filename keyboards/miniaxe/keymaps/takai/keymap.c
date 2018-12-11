/* Copyright 2018 ENDO Katsuhiro <ka2hiro@curlybracket.co.jp>
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

#define TAPPING_TERM 200
#define PERMISSIVE_HOLD

#define LAYOUT_kc(L01, L02, L03, L04, L05, R01, R02, R03, R04, R05,     \
                  L06, L07, L08, L09, L10, R06, R07, R08, R09, R10,     \
                  L11, L12, L13, L14, L15, R11, R12, R13, R14, R15,     \
                  L16, L17, L18, R16, R17, R18)                         \
  LAYOUT(KC_##L01, KC_##L02, KC_##L03, KC_##L04, KC_##L05,              \
         KC_##R01, KC_##R02, KC_##R03, KC_##R04, KC_##R05,              \
         KC_##L06, KC_##L07, KC_##L08, KC_##L09, KC_##L10,              \
         KC_##R06, KC_##R07, KC_##R08, KC_##R09, KC_##R10,              \
         KC_##L11, KC_##L12, KC_##L13, KC_##L14, KC_##L15,              \
         KC_##R11, KC_##R12, KC_##R13, KC_##R14, KC_##R15,              \
         KC_##L16, KC_##L17, KC_##L18,                                  \
         KC_##R16, KC_##R17, KC_##R18)

#define KC_ KC_TRNS

#define _BASE 0
#define _FN1 1
#define _FN2 2

#define KC_SPC1 LT(_FN1, KC_SPACE)
#define KC_SPC2 LT(_FN2, KC_SPACE)

#define KC_ZSFT SFT_T(KC_Z)
#define KC_ACTL CTL_T(KC_A)
#define KC_GTAB LGUI(KC_TAB)
#define KC_GENT LGUI(KC_ENT)
#define KC_CENT LCTL(KC_ENT)

#define KC_RSET RESET

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_kc(
    // |----+----+----+----+----|----+----+----+----+----|
         Q  , W  , E  , R  , T  , Y  , U  , I  , O  , P  ,
    // |----+----+----+----+----|----+----+----+----+----|
        ACTL, S  , D  , F  , G  , H  , J  , K  , L  ,SCLN,
    // |----+----+----+----+----|----+----+----+----+----|
        ZSFT, X  , C  , V  , B  , N  , M  ,COMM,DOT ,SLSH,
    // |----+----+----+----+----|----+----+----+----+----|
                  LALT,LGUI,SPC1,SPC2,RCTL,RSFT
    //           |----+----+----|----+----+----|
  ),

  [_FN1] = LAYOUT_kc(
    // |----+----+----+----+----|----+----+----+----+----|
         1  , 2  , 3  , 4  , 5  , 6  , 7  , 8  , 9  , 0  ,
    // |----+----+----+----+----|----+----+----+----+----|
        GTAB,GENT,CENT,    ,    ,PIPE,LPRN,RPRN,QUOT,DQUO,
    // |----+----+----+----+----|----+----+----+----+----|
        ESC ,    ,    ,    ,    ,BSLS,LBRC,RBRC,LCBR,RCBR,
    // |----+----+----+----+----|----+----+----+----+----|
                      ,    ,    ,    ,    ,
    //           |----+----+----|----+----+----|
  ),

  [_FN2] = LAYOUT_kc(
    // |----+----+----+----+----|----+----+----+----+----|
        EXLM, AT ,HASH,DLR ,PERC,CIRC,AMPR,ASTR,TAB ,BSPC,
    // |----+----+----+----+----|----+----+----+----+----|
            ,    ,    ,    ,    ,LEFT,DOWN, UP ,RGHT,ENT ,
    // |----+----+----+----+----|----+----+----+----+----|
        ESC ,    ,    ,    ,    ,    ,MINS,EQL ,UNDS,PLUS,
    // |----+----+----+----+----|----+----+----+----+----|
                      ,    ,    ,    ,    ,RSET
    //           |----+----+----|----+----+----|
  )

};
