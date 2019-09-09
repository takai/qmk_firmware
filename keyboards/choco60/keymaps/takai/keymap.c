/* Copyright 2019 Naoto Takai
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

#include "choco60.h"
#include QMK_KEYBOARD_H

#define _BASE 0
#define _FN1 1
#define _FN2 2
#define _FN3 3

#define KC_ KC_TRNS
#define KC_FN1 LT(_FN1, KC_SPACE)
#define KC_FN2 LT(_FN2, KC_SPACE)
#define KC_FN3 MO(_FN3)
#define KC_RST RESET
#define KC_GUIL RGUI(KC_LEFT)
#define KC_GUIR RGUI(KC_RGHT)
#define KC_OPTD RALT(KC_DOWN)
#define KC_OPTU RALT(KC_UP)
#define KC_GSLB LGUI(LSFT(KC_LBRC))
#define KC_GSRB LGUI(LSFT(KC_RBRC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_kc(
    //|----+----+----+----+----+----|----+----+----+----+----+----+----+----+----|
       GESC,1   ,2   ,3   ,4   ,5   ,6   ,7   ,8   ,9   ,0   ,MINS,EQL ,BSLS,GRV , \
    //|----+----+----+----+----+----|----+----+----+----+----+----+----+----+----|
       TAB    ,Q   ,W   ,E   ,R   ,T   ,Y   ,U   ,I   ,O   ,P   ,LBRC,RBRC,BSPC  , \
    //|-------+----+----+----+----+----|----+----+----+----+----+----+----+------|
       LCTRL   ,A   ,S   ,D   ,F   ,G   ,H   ,J   ,K   ,L   ,SCLN,QUOT,ENT       , \
    //|--------+----+----+----+----+----|----+----+----+----+----+----+----------|
       LSFT     ,Z   ,X   ,C   ,V   ,B   ,N   ,M   ,COMM,DOT ,SLSH,RSFT     ,FN3 , \
    //|---------+----+----+----+----+----|----+----+----+----+----+---------+----|
              LALT,   LGUI,      SPC, FN1,          FN2,  RGUI,RALT
    //      |-----+-------+---------|----+-------------+------+----|
  ),
  [_FN1] = LAYOUT_kc(
    //|----+----+----+----+----+----|----+----+----+----+----+----+----+----+----|
           ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    , \
    //|----+----+----+----+----+----|----+----+----+----+----+----+----+----+----|
              ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,      , \
    //|-------+----+----+----+----+----|----+----+----+----+----+----+----+------|
               ,    ,    ,    ,    ,    ,LEFT,DOWN,  UP,RGHT,    ,    ,          , \
    //|--------+----+----+----+----+----|----+----+----+----+----+----+----------|
                ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,         ,    , \
    //|---------+----+----+----+----+----|----+----+----+----+----+---------+----|
                  ,       ,         ,    ,             ,      ,
    //      |-----+-------+---------|----+-------------+------+----|
  ),
  [_FN2] = LAYOUT_kc(
    //|----+----+----+----+----+----|----+----+----+----+----+----+----+----+----|
           ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    , \
    //|----+----+----+----+----+----|----+----+----+----+----+----+----+----+----|
              ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,GSLB,GSRB,      , \
    //|-------+----+----+----+----+----|----+----+----+----+----+----+----+------|
               ,    ,    ,    ,    ,    ,GUIL,OPTD,OPTU,GUIR,    ,    ,          , \
    //|--------+----+----+----+----+----|----+----+----+----+----+----+----------|
                ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,         ,    , \
    //|---------+----+----+----+----+----|----+----+----+----+----+---------+----|
                  ,       ,         ,    ,             ,      ,
    //      |-----+-------+---------|----+-------------+------+----|
  ),
  [_FN3] = LAYOUT_kc(
    //|----+----+----+----+----+----|----+----+----+----+----+----+----+----+----|
           ,  F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10, F11, F12, INS, DEL, \
    //|----+----+----+----+----+----|----+----+----+----+----+----+----+----+----|
              ,    ,    ,    ,    ,    ,    ,    ,PSCR,BRMD,BRMU,  UP,    ,      , \
    //|-------+----+----+----+----+----|----+----+----+----+----+----+----+------|
               ,    ,    ,    ,    ,    ,    ,    ,HOME,PGUP,LEFT,RGHT,          , \
    //|--------+----+----+----+----+----|----+----+----+----+----+----+----------|
       RST      ,    ,    ,    ,    ,    ,    ,    , END,PGDN,DOWN,         ,    , \
    //|---------+----+----+----+----+----|----+----+----+----+----+---------+----|
                  ,       ,         ,    ,             ,      ,
    //      |-----+-------+---------|----+-------------+------+----|
  ),
};
