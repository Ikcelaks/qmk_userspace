/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRV
#define ES_GRTR_MAC LSFT(KC_GRV)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRV
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)
#define MOON_LED_LEVEL LED_LEVEL

#define C_GUI_ESC LGUI_T(KC_ESC)
#define C_RSFT_ENT RSFT_T(KC_ENT)
#define C_LALT_ENT LALT_T(KC_ENT)
#define C_RCTL_QUOT RCTL_T(KC_QUOT)
#define C_LCTL_BSPC LCTL(KC_BSPC)

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
    NAVI,  // navigation
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT_moonlander(
        KC_DOT,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_EQL,                                         KC_ASTR,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPC,
        KC_TAB,         KC_B,           KC_M,           KC_L,           KC_C,           KC_P,           KC_DQUO,                                        KC_PIPE,        KC_J,           ST_MAG1,        KC_U,           KC_O,           KC_COMM,        KC_BSLS,
        LCTL(KC_BSPC),  KC_S,           KC_T,           KC_R,           KC_D,           KC_Y,           KC_Q,                                           KC_DLR,         KC_F,           KC_N,           KC_E,           KC_A,           KC_I,           C_RCTL_QUOT,
        OSM(MOD_LSFT),  KC_V,           KC_K,           KC_X,           KC_G,           KC_W,                                                                                   KC_Z,           KC_H,           KC_MINS,        KC_QUES,        KC_DOT,         C_RSFT_ENT,
        KC_GRV,         KC_LCTL,        KC_LGUI,        KC_ESC,         TT(NAVI),                       C_LALT_ENT,                                     C_GUI_ESC,                     C_S_T(KC_SLSH),  KC_LALT,        KC_LBRC,        TT(MDIA),       TT(SYMB),
                                                                        KC_SPC,         KC_BSPC,        KC_DEL,                                         OSL(SYMB),      OSM(MOD_LSFT),      ST_MAG2
    ),
	[SYMB] = LAYOUT_moonlander(
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______, _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        _______, KC_HASH, KC_AMPR, KC_LCBR, KC_RCBR, KC_PIPE, _______, _______, KC_INS, KC_7, KC_8, KC_9, KC_PMNS, KC_F12,
        _______, KC_AT, KC_EXLM, KC_LPRN, KC_RPRN, KC_TILD, _______, ST_MAG5, KC_PPLS, KC_4, KC_5, KC_6, KC_PAST, _______,
        _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_GRV, KC_PSLS, KC_1, KC_2, KC_3, KC_PEQL, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_0, KC_PCMM, KC_PDOT, KC_PENT, _______,
        _______, _______, _______, _______, _______, _______
    ),
	[MDIA] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, _______, MS_UP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, MS_LEFT, MS_DOWN, MS_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT, _______, _______,
        XXXXXXX, _______, _______, MS_BTN1, MS_BTN2, _______, _______, KC_VOLU, KC_VOLD, KC_MUTE, _______, XXXXXXX,
        _______, _______, _______, _______, _______, _______
    ),
	[NAVI] = LAYOUT_moonlander(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, MS_WHLL, MS_WHLR, LCTL(KC_F), LCTL(KC_R), MS_WHLU, XXXXXXX, XXXXXXX, KC_PGUP, KC_HOME, KC_UP, KC_END, KC_CAPS, XXXXXXX,
        XXXXXXX, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, MS_WHLD, XXXXXXX, XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, LCTL(KC_DEL), XXXXXXX,
        XXXXXXX, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_A), KC_INS, KC_BSPC, XXXXXXX, KC_DEL, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______, _______, KC_ENT, KC_TAB, KC_SPC
    )
};

const uint16_t PROGMEM combo_RT_12[] = { ST_MAG2, OSM(MOD_LSFT), COMBO_END};
// const uint16_t PROGMEM combo_LB_IM[] = { KC_X, KC_G, COMBO_END};
// const uint16_t PROGMEM combo_LB_MR[] = { KC_K, KC_X, COMBO_END};
// const uint16_t PROGMEM combo_LB_RP[] = { KC_V, KC_K, COMBO_END};
const uint16_t PROGMEM combo_LB_IR[] = { KC_K, KC_G, COMBO_END};
const uint16_t PROGMEM combo_RB_IM[] = { KC_H, KC_MINS, COMBO_END};
const uint16_t PROGMEM combo_RB_MR[] = { KC_MINS, KC_QUES, COMBO_END};
const uint16_t PROGMEM combo_RB_RP[] = { KC_QUES, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_RB_IR[] = { KC_H, KC_QUES, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_RT_12, OSL(SYMB)),
    // COMBO(combo_LB_IM, KC_COLN),
    // COMBO(combo_LB_MR, ST_MAG3),
    // COMBO(combo_LB_RP, ST_MAG4),
    COMBO(combo_LB_IR, ST_MAG4),
    COMBO(combo_RB_IM, KC_SCLN),
    COMBO(combo_RB_MR, KC_COLN),
    COMBO(combo_RB_RP, ST_MAG3),
    COMBO(combo_RB_IR, ST_MAG4),
};

// extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void)
{
    rgb_matrix_enable();
    debug_enable=true;
}
