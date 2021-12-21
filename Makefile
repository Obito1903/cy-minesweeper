SRC_FOLDER = src
BUILD_FOLDER = build
BACKUP_FOLDER = .backup
BIN_FOLDER = bin
ZIP_TMP_FOLDER = .zip
EXTRA 	= Doxyfile Makefile README.md
DOCS    = $(filter-out Docs/Doxygen Docs, $(shell find Docs -maxdepth 1))
ZIP_NAME = ${USER}-$(shell basename $$PWD)

# Commandes
CP   = cp -u
CC	 = gcc
FLAGS	 = -g -c -Wall -Iinclude
LFLAGS	 = -lncurses

FEATURES =
FEATURES_CC = #$(shell echo $(FEATURES) | sed 's/[^ ]* */-D&/g')

# Variable specifique a la compilation
SOURCES	= $(wildcard $(SRC_FOLDER)/*.c)
OBJS 	= $(subst $(SRC_FOLDER)/,$(BUILD_FOLDER)/,$(SOURCES:.c=.o))
HEADERS	= $(wildcard $(SRC_FOLDER)/*.h)
OUT	= $(BIN_FOLDER)/$(shell basename $$PWD)


all: $(BUILD_FOLDER) $(BIN_FOLDER) $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

$(BUILD_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	$(CC) $(FLAGS) $(FEATURES_CC) $^ -o $@

$(BUILD_FOLDER):
	mkdir -p $(BUILD_FOLDER)

$(BIN_FOLDER):
	mkdir -p $(BIN_FOLDER)

docs:
	( cat Doxyfile ; echo "PREDEFINED=$(FEATURES)" ) | doxygen -

clean:
	rm -f $(ZIP_NAME).zip $(OBJS) $(OUT)

run: all
	./$(OUT)

save: $(SOURCES)
	mkdir -p $(BACKUP_FOLDER)
	$(CP) $(SOURCES) $(HEADERS) $(BACKUP_FOLDER)/

restore:
	$(CP) $(BACKUP_FOLDER)/* $(SRC_FOLDER)

give: all $(EXTRA) $(DOCS)
	mkdir -p $(ZIP_TMP_FOLDER)/$(ZIP_NAME)
	$(CP) -r --parents $(SRC_FOLDER) $(DOCS) $(EXTRA) $(ZIP_TMP_FOLDER)/$(ZIP_NAME)
	cd $(ZIP_TMP_FOLDER) && zip -r $(PWD)/$(ZIP_NAME) $(ZIP_NAME)
	rm -rf $(ZIP_TMP_FOLDER)
