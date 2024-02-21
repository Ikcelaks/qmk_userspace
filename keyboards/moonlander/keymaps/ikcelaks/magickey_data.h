// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

/*******************************************************************************
  88888888888 888      d8b                .d888 d8b 888               d8b
      888     888      Y8P               d88P"  Y8P 888               Y8P
      888     888                        888        888
      888     88888b.  888 .d8888b       888888 888 888  .d88b.       888 .d8888b
      888     888 "88b 888 88K           888    888 888 d8P  Y8b      888 88K
      888     888  888 888 "Y8888b.      888    888 888 88888888      888 "Y8888b.
      888     888  888 888      X88      888    888 888 Y8b.          888      X88
      888     888  888 888  88888P'      888    888 888  "Y8888       888  88888P'
                                                        888                 888
                                                        888                 888
                                                        888                 888
     .d88b.   .d88b.  88888b.   .d88b.  888d888 8888b.  888888 .d88b.   .d88888
    d88P"88b d8P  Y8b 888 "88b d8P  Y8b 888P"      "88b 888   d8P  Y8b d88" 888
    888  888 88888888 888  888 88888888 888    .d888888 888   88888888 888  888
    Y88b 888 Y8b.     888  888 Y8b.     888    888  888 Y88b. Y8b.     Y88b 888
     "Y88888  "Y8888  888  888  "Y8888  888    "Y888888  "Y888 "Y8888   "Y88888
         888
    Y8b d88P
     "Y88P"
*******************************************************************************/

#pragma once

// Autocorrection dictionary with longest match semantics:
// Autocorrection dictionary (6 entries):
//   j☆    -> just
//   j☆☆   -> justment
//   ☆☆    -> ☆n
//   j✵    -> join
//   jud☆  -> judge
//   jud☆☆ -> judgment

#define AUTOCORRECT_MIN_LENGTH 2 // "j☆"
#define AUTOCORRECT_MAX_LENGTH 5 // "jud☆☆"
#define DICTIONARY_SIZE 37
#define COMPLETIONS_SIZE 18
#define MAGICKEY_COUNT 4

static const uint16_t magickey_data[DICTIONARY_SIZE] PROGMEM = {
    0x4100, 0x0005, 0x0101, 0x0021, 0x0000, 0x4007, 0x000C, 0x000D, 0x0011, 0x0100, 0x0013, 0x0000, 0x0018, 0x000D, 0x0000, 0x8000,
    0x0000, 0x8000, 0x0003, 0xC000, 0x0007, 0x4007, 0x001A, 0x000D, 0x001F, 0x0000, 0x0018, 0x000D, 0x0000, 0x8001, 0x0009, 0x8000,
    0x0009, 0x000D, 0x0000, 0x8000, 0x000E
};

static const uint8_t magickey_completions_data[COMPLETIONS_SIZE] PROGMEM = {
    0x67, 0x65, 0x00, 0x75, 0x73, 0x74, 0x00, 0x6E, 0x00, 0x6D, 0x65, 0x6E, 0x74, 0x00, 0x6F, 0x69,
    0x6E, 0x00
};
