
#include "../__init__.h"
#include "magic_sturdy/__init__.h"
#include "magic_sturdy/general.h"
#include "modifiers.h"
#include "repeat_key.h"

void process_magic_key_1(void) {
    if (mag1_key_count >= 2) {
        switch (queue(-4)) {
            quadruple_magic_case(KC_SPC, KC_A, KC_L, KC_R, "eady");
            quadruple_magic_case(KC_J,   KC_U, KC_D, KC_G, "ment");
        }

        switch (queue(-3)) {
            default: record_send_string("n"); return;
        }
    }

    switch (queue(-5)) {
        quintuple_magic_case(KC_B, KC_A, KC_L, KC_L, KC_I, "st");
    }

    switch (queue(-4)) {
        quadruple_magic_case(KC_A, KC_B, KC_E, KC_T, "ment");
        quadruple_magic_case(KC_V, KC_I, KC_L, KC_I, "on");
    }

    switch (queue(-3)) {
        triple_magic_switch(KC_SPC,
            double_magic_switch(KC_A,
                magic_case(KC_L, "r");
                magic_case(KC_N, "other");
            );

            double_magic_switch(KC_E,
                magic_case(KC_D, "ge");
                magic_case(KC_X, "ample");
            );

            double_magic_case(KC_U, KC_S, "e");
            double_magic_case(KC_T, KC_I, "me");
            double_magic_case(KC_I, KC_N, "form");
        );

        triple_magic_switch(KC_B,
            double_magic_switch(KC_E,
                magic_case(KC_T, "ween");
                magic_case(KC_L, "ieve");
            );

            double_magic_case(KC_U, KC_D, "ge");
        );

        triple_magic_switch(KC_V,
            double_magic_switch(KC_A,
                magic_case(KC_R, "ious");
            );

            double_magic_case(KC_I, KC_D, "eo");
        );

        triple_magic_switch(KC_R,
            double_magic_case(KC_I, KC_D, "ge");
            double_magic_case(KC_E, KC_D, "ge");
        );

        triple_magic_switch(KC_S,
            double_magic_case(KC_Y, KC_S, "tem");
        );

        triple_magic_switch(KC_G,
            double_magic_case(KC_E, KC_N, "ious");
        );

        triple_magic_switch(KC_D,
            double_magic_case(KC_I, KC_F, "feren");
            double_magic_case(KC_E, KC_F, "inite");
        );

        triple_magic_switch(KC_L,
            double_magic_case(KC_E, KC_D, "ge");
            double_magic_case(KC_L, KC_I, "on");
        );

        triple_magic_case(KC_J, KC_U, KC_D, "g");
        triple_magic_case(KC_O, KC_B, KC_V, "ious");
        triple_magic_case(KC_H, KC_I, KC_L, "arious");
    }

    switch (queue(-2)) {
        double_magic_switch(KC_SPC,
            magic_case(KC_T, "han");
            magic_case(KC_L, "ittle");
        );

        double_magic_switch(KC_P,
            magic_case(KC_L, "y");
            magic_case(KC_A, "ge");
            magic_case(KC_E, "ople");
            magic_case(KC_R, "evious");
        );

        double_magic_case(KC_I, KC_C, "k");
        double_magic_case(KC_C, KC_Y, "c");
        double_magic_case(KC_A, KC_C, "k");
        double_magic_case(KC_E, KC_C, "k");
        double_magic_case(KC_D, KC_A, "y");
        double_magic_case(KC_B, KC_E, "en");
        double_magic_case(KC_S, KC_O, "me");
        double_magic_case(KC_L, KC_I, "st");
    }

    switch (queue(-1)) {
        magic_case(KC_SPC,  "the");

        magic_case(KC_V,   "er");
        magic_case(KC_S,   "k");
        magic_case(KC_X,   "es");

        magic_case(KC_M,   "ent");
        magic_case(KC_T,   "ment");
        magic_case(KC_K,   "s");

        magic_case(KC_L,   "k");
        magic_case(KC_R,   "l");
        magic_case(KC_J,   "ust");

        magic_case(KC_C,   "y");
        magic_case(KC_D,   "y");
        magic_case(KC_G,   "y");
        magic_case(KC_P,   "y");
        magic_case(KC_Y,   "p");
        magic_case(KC_W,   "hich");
        magic_case(KC_Q,   "uestion");

        magic_case(KC_B,   "efore");
        magic_case(KC_F,   "irst");
        magic_case(KC_Z,   "one");
        // US_MAG1
        magic_case(KC_N,   "ion");
        magic_case(KC_H,   "owever");

        magic_case(KC_U,   "e");
        magic_case(KC_E,   "u");
        // KC_QUOT

        magic_case(KC_O,   "a");
        magic_case(KC_A,   "b");
        // KC_QUES

        magic_case(KC_COMM, get_last_mods() & MOD_MASK_SHIFT ? "=" : " but");
        magic_case(KC_I,   "on");
        magic_case(KC_DOT, get_last_mods() & MOD_MASK_SHIFT ? "=" : "\\");
    }
}

void process_magic_key_2(void) {
    switch (queue(-3)) {
        triple_magic_switch(KC_SPC,
            double_magic_case(KC_A, KC_B, "out");
            double_magic_case(KC_O, KC_X, "ygen");
        );

        triple_magic_case(KC_A,   KC_N, KC_Y, "way");
        // triple_magic_case(KC_C,   KC_A, KC_P, "able");
        // triple_magic_case(KC_U,   KC_N, KC_I, "versity");
    }

    switch (queue(-2)) {
        double_magic_switch(KC_SPC,
            magic_case(KC_I, "ncrease");
            magic_case(KC_B, "ecause");
        );

        double_magic_case(KC_F, KC_R, "om");
    }

    switch (queue(-1)) {
        magic_case(KC_SPC, "for");
        magic_case(KC_A,   "nd");
        magic_case(KC_X,   "er");
        magic_case(KC_I,   "ng");
        magic_case(KC_Y,   "ou");
        magic_case(KC_Q,   "ui");
        magic_case(KC_J,   "oin");
        magic_case(KC_W,   "ould");
        magic_case(KC_C,   "k");
        magic_case(KC_N,   "f");
        case KC_COMMA:
            record_send_string(" and");
            return;
        case KC_DOT:
        case KC_QUES:
        case KC_EXLM:
        case KC_COLN:
        case KC_SCLN:
            unregister_weak_mods(MOD_MASK_CSAG);
            send_char(' ');
            add_oneshot_mods(MOD_MASK_SHIFT);
            enqueue(KC_SPC);
            return;
        default: tap_code16(queue(-1)); enqueue(queue(-1));
    }
}

void process_magic_key_3(void) {
    switch (queue(-1)) {
        magic_case(KC_B, "ecome");
        magic_case(KC_F, "ollow");
        magic_case(KC_N, "eighbor");
        magic_case(KC_H, "owever");
        magic_case(KC_U, "pgrade");
        magic_case(KC_O, "ther");
        magic_case(KC_A, "lready");
        magic_case(KC_P, "sych");
        magic_case(KC_I, "'ll");
        magic_case(KC_K, "now");
        magic_case(KC_T, "hough");
        magic_case(KC_L, "ight");
        magic_case(KC_M, "ight");
        magic_case(KC_R, "ight");
        magic_case(KC_J, "udge");
        magic_case(KC_C, "ould");
        magic_case(KC_D, "evelop");
        magic_case(KC_G, "eneral");
        magic_case(KC_W, "here");
        magic_case(KC_S, "hould");
        magic_case(KC_DOT, "org");
        magic_case(KC_COMM, " however");
        default: return;
    }
}

void process_magic_key_4(void) {
    switch (queue(-1)) {
        magic_case(KC_B, "etween");
        magic_case(KC_N, "umber");
        magic_case(KC_U, "pdate");
        magic_case(KC_O, "ught");
        magic_case(KC_A, "bout");
        magic_case(KC_P, "rogram");
        magic_case(KC_I, "'m");
        magic_case(KC_T, "hrough");
        magic_case(KC_M, "anage");
        magic_case(KC_C, "rowd");
        magic_case(KC_G, "overn");
        magic_case(KC_W, "orld");
        magic_case(KC_S, "chool");
        magic_case(KC_E, "'re");
        magic_case(KC_DOT, "com");
        magic_case(KC_COMM, " since");
        default: return;
    }
}
