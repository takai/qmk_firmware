/* Copyright 2019 'Naoto Takai'
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

#include "cocoa40.h"
#include QMK_KEYBOARD_H

#define _BASE 0
#define _NUMS 2
#define _SYMS 3
#define _FN   4

#define KC_ KC_NO
#define KC_NUMS LT(_NUMS, KC_SPACE)
#define KC_SYMS LT(_SYMS, KC_SPACE)
#define KC_FN MO(_FN)
#define KC_RST RESET
#define KC_DBUG DEBUG
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD
#define KC_GUIL RGUI(KC_LEFT)
#define KC_GUIR RGUI(KC_RGHT)
#define KC_OPTD RALT(KC_DOWN)
#define KC_OPTU RALT(KC_UP)
#define KC_BRMI TD(TD_LBRC_MINUS)

enum {
  TD_LBRC_MINUS = 0
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LBRC_MINUS] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_MINUS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_kc(
    //|----+----+----+----+----+----|----+----+----+----+----+----+----+----|
       GESC,Q   ,W   ,E   ,R   ,T   ,Y   ,U   ,I   ,O   ,P   ,BRMI,RBRC,BSPC,\
    //|----+----+----+----+----+----|----+----+----+----+----+----+----+----|
       LCTL ,A   ,S   ,D   ,F   ,G   ,H   ,J   ,K   ,L   ,SCLN,QUOT,ENTER   ,\
    //|-----+----+----+----+----+----|----+----+----+----+----+----+--------|
       LSFT   ,Z   ,X   ,C   ,V   ,N   , M  , B  ,COMM,DOT ,SLSH,RSFT ,FN   ,\
    //|-------+----+----+----+----+----|----+----+----+----+----+-----+-----|
             LALT ,LGUI   ,NUMS     ,SYMS         ,RGUI  ,RALT
    //      |-----+-------+---------|-------------+------+----|
  ),
  [_NUMS] = LAYOUT_kc(
    //|----+----+----+----+----+----|----+----+----+----+----+----+----+----|
       TAB ,1   ,2   ,3   ,4   ,5   ,6   ,7   ,8   ,9   ,0   ,MINS,EQL ,BSLS,\
    //|----+----+----+----+----+----|----+----+----+----+----+----+----+----|
            ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,        ,\
    //|-----+----+----+----+----+----|----+----+----+----+----+----+--------|
              ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,     ,     ,\
    //|-------+----+----+----+----+----|----+----+----+----+----+-----+-----|
                  ,       ,         ,             ,      ,
    //      |-----+-------+---------|-------------+------+----|
  ),
  [_SYMS] = LAYOUT_kc(
    //|----+----+----+----+----+----|----+----+----+----+----+----+----+----|
       TILD,EXLM,AT  ,HASH,DLR ,PERC,CIRC,AMPR,ASTR,LPRN,RPRN,UNDS,PLUS,PIPE,\
    //|----+----+----+----+----+----|----+----+----+----+----+----+----+----|
            ,    ,    ,    ,    ,    ,LEFT,DOWN,UP  ,RGHT,    ,    ,        ,\
    //|-----+----+----+----+----+----|----+----+----+----+----+----+--------|
              ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,     ,     ,\
    //|-------+----+----+----+----+----|----+----+----+----+----+-----+-----|
                  ,       ,         ,             ,      ,
    //      |-----+-------+---------|-------------+------+----|
  ),
  [_FN] = LAYOUT_kc(
    //|----+----+----+----+----+----|----+----+----+----+----+----+----+----|
      POWER,F1  ,F2  ,F3  ,F4  ,F5  ,    ,P7  ,P8  ,P9  ,MUTE,VOLD,VOLU,DEL ,\
    //|----+----+----+----+----+----|----+----+----+----+----+----+----+----|
            ,F6  ,F7  ,F8  ,F9  ,F10 ,    ,P4  ,P5  ,P6  ,    ,    ,        ,\
    //|-----+----+----+----+----+----|----+----+----+----+----+----+--------|
       RST    ,F11 ,F12 ,PSCR,SLCK,PAUS,    ,P1  ,P2  ,P3  ,    ,     ,     ,\
    //|-------+----+----+----+----+----|----+----+----+----+----+-----+-----|
                  ,       ,         ,P0           ,PDOT  ,
    //      |-----+-------+---------|-------------+------+----|
  ),
};
