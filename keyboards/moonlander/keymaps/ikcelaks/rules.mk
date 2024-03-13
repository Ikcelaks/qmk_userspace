# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
SPACE_CADET_ENABLE = no
COMBO_ENABLE = yes
REPEAT_KEY_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes
CAPS_WORD_ENABLE = yes

include /home/qmk/qmk_userspace/keyboards/moonlander/keymaps/ikcelaks/sequence_transform/rules.mk

# Automatically rebuild my sequence_transform rules from the latest config
$(shell python3 /home/qmk/qmk_userspace/keyboards/moonlander/keymaps/ikcelaks/sequence_transform/generator/sequence_transform_data.py -q)

TOP_SYMBOLS=10
