# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
SPACE_CADET_ENABLE = no
COMBO_ENABLE = yes
REPEAT_KEY_ENABLE = no
DEFERRED_EXEC_ENABLE = no
CAPS_WORD_ENABLE = yes
LTO_ENABLE = yes

TOP_SYMBOLS=10

# sequence_transform setup
mkfile_dir := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
include $(mkfile_dir)/sequence_transform/rules.mk
# end sequence_transform setup
