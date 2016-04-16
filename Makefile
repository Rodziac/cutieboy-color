BIN=~/gbdk-n/bin
OBJ=./obj
GAMENAME=test

build:
	mkdir -p $(OBJ)
	$(BIN)/gbdk-n-compile.sh $(GAMENAME).c -o $(OBJ)/$(GAMENAME).rel
	$(BIN)/gbdk-n-link.sh $(OBJ)/$(GAMENAME).rel -o $(OBJ)/$(GAMENAME).ihx
	$(BIN)/gbdk-n-make-rom.sh $(OBJ)/$(GAMENAME).ihx $(GAMENAME).gb

clean:
	rm -rf $(OBJ)
	rm -f $(GAMENAME).gb

test:
	gvbam $(GAMENAME).gb
