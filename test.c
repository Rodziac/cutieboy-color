#include <gb/gb.h>
#include <time.h>
#include <stdlib.h>

unsigned char spritetiles[] = {
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255
};

// -1 = none
//  0 = cube
//  1 = L
//  2 = reverse L
//  3 = Z
//  4 = S
//  5 = I
//  6 = T

int currentPieceId = -1;
int numberOfSprites = -1;
int startX = 50;
int startY = 20;
void renderPiece() {
	set_sprite_data(numberOfSprites + 1, numberOfSprites + 4, spritetiles);
	switch (currentPieceId)
	{
		case 0:
			move_sprite(numberOfSprites + 1, startX, startY);
			move_sprite(numberOfSprites + 2, startX + 8, startY + 8);
			move_sprite(numberOfSprites + 3, startX + 8, startY);
			move_sprite(numberOfSprites + 4, startX, startY + 8);
			break;
		case 1:
			move_sprite(numberOfSprites + 1, startX, startY);
			move_sprite(numberOfSprites + 2, startX, startY + 8);
			move_sprite(numberOfSprites + 3, startX, startY + 16);
			move_sprite(numberOfSprites + 4, startX + 8, startY + 16);
			break;
		case 2:
			move_sprite(numberOfSprites + 1, startX, startY);
			move_sprite(numberOfSprites + 2, startX, startY + 8);
			move_sprite(numberOfSprites + 3, startX, startY + 16);
			move_sprite(numberOfSprites + 4, startX - 8, startY + 16);
			break;
		case 3:
			move_sprite(numberOfSprites + 1, startX, startY);
			move_sprite(numberOfSprites + 2, startX + 8, startY);
			move_sprite(numberOfSprites + 3, startX + 8, startY + 8);
			move_sprite(numberOfSprites + 4, startX + 16, startY + 8);
			break;
		case 4:
			move_sprite(numberOfSprites + 1, startX + 8, startY);
			move_sprite(numberOfSprites + 2, startX + 16, startY);
			move_sprite(numberOfSprites + 3, startX + 8, startY + 8);
			move_sprite(numberOfSprites + 4, startX, startY + 8);
			break;
		case 5:
			move_sprite(numberOfSprites + 1, startX, startY - 8);
			move_sprite(numberOfSprites + 2, startX, startY);
			move_sprite(numberOfSprites + 3, startX, startY + 8);
			move_sprite(numberOfSprites + 4, startX, startY + 16);
			break;
		case 6:
			move_sprite(numberOfSprites + 1, startX, startY);
			move_sprite(numberOfSprites + 2, startX, startY + 8);
			move_sprite(numberOfSprites + 3, startX - 8, startY + 8);
			move_sprite(numberOfSprites + 4, startX + 8, startY + 8);
			break;
		default:
			break;
	}
	numberOfSprites += 4;
}

int randNum(int max) {
	srand(time(NULL));
	return rand() % (max + 1);
}

void main()
{
	UBYTE counter,x,y;
	x=40;
	y=17;

	disable_interrupts();
	DISPLAY_OFF;

	// load sprite
	SPRITES_8x8;
	currentPieceId = randNum(6);
	renderPiece();

	SHOW_SPRITES; 
	DISPLAY_ON;
	enable_interrupts();
}
