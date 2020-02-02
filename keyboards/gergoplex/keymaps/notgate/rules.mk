# Build
# sudo util/docker_build.sh gergoplex:notgate:flash

# Stuff
MOUSEKEY_ENABLE = no

#Debug options
CONSOLE_ENABLE = no
VERBOSE = no
DEBUG_MATRIX_SCAN_RATE = no
DEBUG_MATRIX = no

# Germ says no touchie
ifeq ($(strip $(DEBUG_MATRIX)), yes)
    OPT_DEFS += -DDEBUG_MATRIX
endif
