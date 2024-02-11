
#include "magic_sturdy/general.h"
#include "../__init__.h"

int mag1_key_count = 0;
int mag2_key_count = 0;
int mag3_key_count = 0;
int mag4_key_count = 0;
int last_key_pressed_time = 0;
int prev_key_time;

int prev_keys_queue[PREV_KEYS_QUEUE_SIZE] = {KC_NO};
deferred_token magic_timeout_token = INVALID_DEFERRED_TOKEN;

uint32_t enqueue_space(uint32_t trigger_time, void *cb_arg) {
    enqueue(KC_SPC);
    return 0;
}

void refresh_token(void) {
    if (magic_timeout_token != INVALID_DEFERRED_TOKEN)
        cancel_deferred_exec(magic_timeout_token);

    magic_timeout_token = defer_exec(MAGIC_KEY_TIMEOUT, enqueue_space, NULL);
}

void record_send_string(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 11) dequeue();
        else if (65 <= str[i] && str[i] <= 90) enqueue(str[i] - 61);
        else if (97 <= str[i] && str[i] <= 122) enqueue(str[i] - 93);
    }

    SEND_STRING(str);
}

void enqueue(int keycode) {
    for (int i = 0; i < PREV_KEYS_QUEUE_SIZE - 1; i += 1)
        prev_keys_queue[i] = prev_keys_queue[i + 1];

    prev_keys_queue[PREV_KEYS_QUEUE_SIZE - 1] = keycode;
}

void dequeue(void) {
    set_last_keycode(prev_keys_queue[PREV_KEYS_QUEUE_SIZE - 1]);

     for (int i = PREV_KEYS_QUEUE_SIZE - 1; i > 0; i -= 1)
        prev_keys_queue[i] = prev_keys_queue[i - 1];

    prev_keys_queue[0] = KC_NO;
}

void print_queue(void) {
    uprintf("queue: ");

    for (int i = 0; i < PREV_KEYS_QUEUE_SIZE - 1; i += 1)
        uprintf("%d, ", prev_keys_queue[i]);

    uprintf("\n");
}

uint16_t normalize_keycode(uint16_t keycode) {
    if (IS_QK_MOD_TAP(keycode))   return QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
    if (IS_QK_LAYER_TAP(keycode)) return QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);

    return keycode;
}

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record, uint8_t* mods) {
    keycode = normalize_keycode(keycode);

    switch (keycode) {
        case KC_BSPC:
        case KC_LEFT:
            dequeue();
            return false;
    }

    if (
        (*mods & MOD_MASK_CTRL) &&
        ((keycode == KC_BSPC && record->tap.count) || (keycode == KC_BSPC))
    ) keycode = KC_SPC;

    switch (keycode) {
        case KC_ENT:
        case KC_TAB:
        case KC_BSPC:
        case LCTL(KC_BSPC):
        case KC_LEFT:
        case KC_DQUO:
        case KC_LPRN:
        case KC_SPC:
            keycode = KC_SPC;
            break;

        case KC_A ... KC_Z:
            if ((*mods & ~(MOD_MASK_SHIFT)) == 0) {
                *mods &= ~MOD_MASK_SHIFT;
            }
            break;

        case US_MAG1:
        case US_MAG2:
        case US_MAG3:
        case US_MAG4:
            return false;
    }

    enqueue(keycode);
    print_queue();
    return true;
}

bool sturdy_pr(uint16_t keycode, keyrecord_t *record, bool *return_value) {
    *return_value = false;
    prev_key_time = last_key_pressed_time;

    if (record->event.pressed) {
        last_key_pressed_time = timer_read();
        refresh_token();

        if (keycode != US_MAG1) mag1_key_count = 0;
        else mag1_key_count += 1;

        if (keycode != US_MAG2) mag2_key_count = 0;
        else mag2_key_count += 1;

        if (keycode != US_MAG4) mag3_key_count = 0;
        else mag3_key_count += 1;

        if (keycode != US_MAG4) mag4_key_count = 0;
        else mag4_key_count += 1;
    }

    switch (keycode) {
        case US_MAG1:
            if (record->event.pressed)
                process_magic_key_1();

            return true;

        case US_MAG2:
            if (record->event.pressed)
                process_magic_key_2();

            return true;

        case US_MAG3:
            if (record->event.pressed)
                process_magic_key_3();

            return true;

        case US_MAG4:
            if (record->event.pressed)
                process_magic_key_4();

            return true;

        // case KC_B:
        // case KC_Z:
        // case KC_F:
        //     return process_double_tap(keycode, record);
    }

    return false;
}

// bool process_double_tap(uint16_t keycode, keyrecord_t *record) {
//     if (
//         !record->event.pressed ||
//         highest_layer != STURDY ||
//         queue(-2) != keycode ||
//         timer_elapsed(prev_key_time) > (get_tapping_term(keycode, NULL) + 50)
//     ) return false;

//     dequeue();
//     process_magic_key();

//     return true;
// }
