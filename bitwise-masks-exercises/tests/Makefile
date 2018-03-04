SRC_DIR := ../src
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
C_UNIT_TEST_FILE := tests.check.c
OBJ_FILES := $(SRC_FILES:%.c=%.o)
LCFLAGS := `pkg-config --libs --cflags check`
CFLAGS := -Wall -pedantic -std=c11
RED := '\033[0;32m' # bash color red
NO_COLOR := '\033[0m' # bash no color

tests: tests.o $(OBJ_FILES)
	@gcc $(CFLAGS) -o $@ $^ $(LCFLAGS)
	@printf "$@		MADE\n"
	@$(MAKE) clean_shit
	@echo "\n\n$(RED)"
	@./$@
	@echo "$(NO_COLOR)\n\n"
	@$(MAKE) clean

see: 
	@echo SRC_DIR=$(SRC_DIR)
	@echo SRC_FILES=$(SRC_FILES)
	@echo OBJ_FILES=$(OBJ_FILES)

tests.c: 
	@touch $@
	@checkmk $(C_UNIT_TEST_FILE) > $@
	@printf "$@ 		MADE\n"

tests.o: tests.c
	@gcc $(CFLAGS) -c $< -o $@

%.o: $(SRC_DIR)/%.c
	@gcc $(CFLAGS) -c $< -o $@
	@printf "$@ 		MADE\n"

clean_shit:
	@rm *.o $(SRC_DIR)/*.o

clean:
	@$(MAKE) clean_shit
	@rm tests

.PHONY: tests tests.c tests.o 
