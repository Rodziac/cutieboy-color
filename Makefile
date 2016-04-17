OBJ=./obj
GAMENAME=test

build:
	mkdir -p $(OBJ)
	gbdk-n-compile.sh $(GAMENAME).c -o $(OBJ)/$(GAMENAME).rel
	gbdk-n-link.sh $(OBJ)/$(GAMENAME).rel -o $(OBJ)/$(GAMENAME).ihx
	gbdk-n-make-rom.sh $(OBJ)/$(GAMENAME).ihx $(GAMENAME).gb

clean:
	rm -rf $(OBJ)
	rm -f $(GAMENAME).gb

test:
	make clean
	make build
	make run

run:
	gvbam $(GAMENAME).gb
