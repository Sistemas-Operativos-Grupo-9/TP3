ENCRYPTEDDIR=ENCRYPTED
BUILDDIR=BUILD
SRCDIR=src

LIB_FILES=$(shell find $(SRCDIR)/lib -name "*.c")
SERVER_FILES=$(shell find $(SRCDIR)/server -name "*.c")
RUNME_FILES=$(shell find $(SRCDIR)/runme -name "*.c")
INTERACTOR_FILES=$(shell find $(SRCDIR)/interactor -name "*.c")
ENC_LIB_FILES=$(LIB_FILES:$(SRCDIR)/%=$(ENCRYPTEDDIR)/%)
OBJ_LIB_FILES=$(ENC_LIB_FILES:$(ENCRYPTEDDIR)/%.c=$(BUILDDIR)/%.o)
ENC_RUNME_FILES=$(RUNME_FILES:$(SRCDIR)/%=$(ENCRYPTEDDIR)/%)
OBJ_RUNME_FILES=$(ENC_RUNME_FILES:$(ENCRYPTEDDIR)/%.c=$(BUILDDIR)/%.o)
ENC_SERVER_FILES=$(SERVER_FILES:$(SRCDIR)/%=$(ENCRYPTEDDIR)/%)
OBJ_SERVER_FILES=$(ENC_SERVER_FILES:$(ENCRYPTEDDIR)/%.c=$(BUILDDIR)/%.o)
ENC_INTERACTOR_FILES=$(INTERACTOR_FILES:$(SRCDIR)/%=$(ENCRYPTEDDIR)/%)
OBJ_INTERACTOR_FILES=$(ENC_INTERACTOR_FILES:$(ENCRYPTEDDIR)/%.c=$(BUILDDIR)/%.o)

CFLAGS=-D_POSIX_C_SOURCE=200809L -I./include -std=c99 -g -lm

all: server interactor

server: $(BUILDDIR)/server_without_runme $(BUILDDIR)/runme_bin
	objcopy --add-section .RUN_ME=$(BUILDDIR)/runme_bin --set-section-flags .RUN_ME=noload,readonly $< $@

interactor: $(OBJ_INTERACTOR_FILES)
	gcc $(CFLAGS) -o $@ $^

$(BUILDDIR)/server_without_runme: $(BUILDDIR)/server_unstripped
	./strip.sh $< $@

$(BUILDDIR)/runme_bin: $(OBJ_RUNME_FILES) $(OBJ_LIB_FILES)
	gcc $(CFLAGS) -o $@ $^
	strip $@

$(BUILDDIR)/server_unstripped: $(OBJ_SERVER_FILES) $(OBJ_LIB_FILES)
	gcc $(CFLAGS) -o $@ $^

$(BUILDDIR)/%.o: $(ENCRYPTEDDIR)/%.c
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c -o $@ $^

$(ENCRYPTEDDIR)/%.c: $(SRCDIR)/%.c
	mkdir -p $(dir $@)
	./string_encryptor.py $^ > $@

clean:
	rm -rf $(BUILDDIR) $(ENCRYPTEDDIR) server

rebuild: clean all

.PHONY: rebuild all clean
.SECONDARY: $(ENC_FILES)

