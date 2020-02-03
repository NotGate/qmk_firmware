# sudo util/docker_build.sh gergoplex:notgate:flash
KEY_LOCK_ENABLE = yes

MOUSEKEY_ENABLE = no
CONSOLE_ENABLE = no
VERBOSE = no
DEBUG_MATRIX_SCAN_RATE = no
DEBUG_MATRIX = no

# Germ says no touchie
ifeq ($(strip $(DEBUG_MATRIX)), yes)
    OPT_DEFS += -DDEBUG_MATRIX
endif
