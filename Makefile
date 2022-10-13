# Complier
CC         :=  gcc
STD_FLAGS  := -std=gnu11
DBG_FLAGS  := -g
OPT_FLAGS  := -O3
WARN_FLAGS := -Wall -Wextra -Werror
            #    -ferror-limit=5
ARCH_FLAGS :=
CC_FLAGS    := $(STD_FLAGS) $(DBG_FLAGS) $(OPT_FLAGS) $(WARN_FLAGS) $(ARCH_FLAGS)

# Linker
LD := ld
LD_FLAGS :=

# Archiver
AR = ar
AR_FLAGS := -crv

# Platform
PLAT := WIN
PLAT := LINUX

ifeq ($(PLAT), WIN)
RM := erase /Q
endif

ifeq ($(PLAT), LINUX)
RM := rm /Q
endif

# Path
WORKSPACE := $(shell pwd)
ROOT:= $(WORKSPACE)

OUT_PATH := $(ROOT)/build
BIN_PATH := $(OUT_PATH)/bin
OBJ_PATH := $(OUT_PATH)/obj
PRE_PATH := $(OUT_PATH)/pre

CLEAN_PATH := $(OUT_PATH)

# Target
TAR_NAME := main.exe

TAR_TYPE := BINARY
# TAR_TYPE := STATIC_LIB
# TAR_TYPE := DYNAMIC_LIB

TAR_VER := DEBUG
# TAR_VER := RELEASE

ifneq ($(TAR_TYPE), BINARY)
	CC_FLAGS += -c
endif

TAR := $(BIN_PATH)/$(TAR_NAME)

# Define
DEF :=
# RELEASE and DEBUG
ifeq ($(TAR_VER), DEBUG)
    DEF +=
else
    DEF +=
endif

CC_FLAGS += $(DEF)

# Include
INC_PATH := inc
INC_DIRS := $(foreach path, $(INC_PATH) ,$(shell find $(path) -maxdepth 10 -type d))
INC :=  $(addprefix -I, $(INC_DIRS))

CC_FLAGS += $(INC)

# Library
LIB :=

# Source Code
SRC_PATH := src
SRC_DIRS := $(foreach path, $(SRC_PATH) ,$(shell find $(path) -maxdepth 10 -type d))
SRC := $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))

# Object
OBJ := $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(basename $(SRC))))

.PHONY: fast
fast:
	@echo "[INFO] MAKE..."
	@mkdir -p $(BIN_PATH)
	$(CC) $(CC_FLAGS) $(LIB) $(SRC) -o $(TAR)
	@echo "[INFO] Done"


.PHONY: all
all: $(TAR)

$(TAR): $(OBJ)

	@echo "[INFO] MAKE $(notdir $@) ..."
	@mkdir -p $(dir $@)

	ifeq ($(TAR_TYPE), BINARY)
		@echo "[INFO] LD $(notdir $@) ..."
		$(LD) $(LD_FLAGS) $@ $(OBJ)
	endif

	ifeq ($(TAR_TYPE), STATIC_LIB)
		@echo "[INFO] AR $(notdir $@) ..."
		$(AR) $(AR_FLAGS) $@ $(OBJ)
	endif

	@echo "[INFO] Done $(notdir $@)"

$(OBJ_PATH)/%.o: %.c
	@echo "[INFO] CC $(notdir $<) ..."
	@mkdir -p $(dir $@)
	$(CC) $(CC_FLAGS) $< -o $@
	@echo "[INFO] Done $(notdir $@)"

.PHONY: clean
clean:
	@echo "[INFO] Cleaning Files ..."
	$(RM) $(CLEAN_PATH)
	@echo "[INFO] Done"

.PHONY: rebuild
rebuild: clean all
	@echo "[INFO] Rebuilding ..."
	@echo "[INFO] Done"

.PHONY: debug
debug:
	@echo "-----------------------"
	@echo $(SRC_DIRS)
