// Originally from QKekos

#pragma once
#include "../__init__.h"

#define PREV_KEYS_QUEUE_SIZE 10
#define MAGIC_KEY_TIMEOUT 1500

bool sturdy_pr(uint16_t keycode, keyrecord_t *record, bool *return_value);
bool remember_last_key_user(uint16_t keycode, keyrecord_t* record, uint8_t* mods);
bool process_double_tap(uint16_t keycode, keyrecord_t *record);
void record_send_string(const char *str);
void enqueue(int keycode);
void dequeue(void);
void print_queue(void);

uint32_t enqueue_space(uint32_t trigger_time, void *cb_arg);
void refresh_token(void);

extern int prev_keys_queue[];
extern int mag1_key_count;
extern int mag2_key_count;
extern int mag3_key_count;
extern int mag4_key_count;
extern int last_key_pressed_time;

#define queue(i) prev_keys_queue[PREV_KEYS_QUEUE_SIZE + i]

#define record_case(symbol, keycode) \
    case symbol: \
        enqueue(keycode); \
        continue