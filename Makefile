ENCRYPTEDDIR=ENCRYPTED
BUILDDIR=BUILD
SRCDIR=src

SRC_FILES=$(shell find $(SRCDIR) -name "*.c")
ENC_FILES=$(SRC_FILES:$(SRCDIR)/%=$(ENCRYPTEDDIR)/%)
OBJ_FILES=$(ENC_FILES:$(ENCRYPTEDDIR)/%.c=$(BUILDDIR)/%.o)



server: $(OBJ_FILES)
	gcc -o $@ $^

$(BUILDDIR)/%.o: $(ENCRYPTEDDIR)/%.c
	mkdir -p $(dir $@)
	gcc -c -o $@ $^

$(ENCRYPTEDDIR)/%.c: $(SRCDIR)/%.c
	mkdir -p $(dir $@)
	./string_encryptor.py $^ > $@

clean:
	rm -rf $(BUILDDIR) $(ENCRYPTEDDIR) server

.PHONY: clean
.SECONDARY: $(ENC_FILES)

