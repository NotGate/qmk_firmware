# sudo util/docker_build.sh gergoplex:f10w:flash
DEBUG_MATRIX = yes
ifeq ($(strip $(DEBUG_MATRIX)), yes)
    OPT_DEFS += -DDEBUG_MATRIX
endif
