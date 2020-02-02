# Build
# sudo util/docker_build.sh gergoplex:notgate:flash

# Stuff
MOUSEKEY_ENABLE = yes

#Debug options
VERBOSE = yes
DEBUG_MATRIX_SCAN_RATE = no
DEBUG_MATRIX = yes

# Germ says no touchie
ifeq ($(strip $(DEBUG_MATRIX)), yes)
    OPT_DEFS += -DDEBUG_MATRIX
endif
