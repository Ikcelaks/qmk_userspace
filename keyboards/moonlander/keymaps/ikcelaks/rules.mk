# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
SPACE_CADET_ENABLE = no
COMBO_ENABLE = yes
REPEAT_KEY_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes

SRC += magic_sturdy/general.c
SRC += magic_sturdy/magic_keys.c
