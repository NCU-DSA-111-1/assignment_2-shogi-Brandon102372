#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#define SIZE 9
#include "coord.h"
#include "step.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef enum {BLUE,RED,BLACK}COLOR;
typedef enum {KING,ROOK,DRAGON,BISHOP,HORSE,GOLD,SILVER,PRO_SILVER,KNIGHT,PRO_KNIGHT,LANCE,PRO_LANCE,PAWN,PRO_PAWN,EMPTY}CHESS_TYPE;
static const char *chess_name[]={"王","飛","龍","角","馬","金","銀","全","桂","圭","香","杏","步","と","  "}; 

typedef struct chess_pice{
	CHESS_TYPE type;
	COLOR color;
}chess;

/*Set a grid of the chess board to a certain type of chess pice and color*/
void set_chess(chess*target,CHESS_TYPE type,COLOR color);
/*Show the whole chess board*/
void show(chess board[][SIZE]);
/*Initialize the chess board*/
void initialize(chess board[][SIZE]);
/*Check if the chess pice can move from it's starting points to destination*/
bool clear_path(chess board[][SIZE],coord st,coord ed);
/*Check if the chess pice can move to the destination*/
bool valid_move(chess board[][SIZE],coord start,coord end,COLOR player);
/*move the chess picce*/
void move_chess(chess board[][SIZE],coord start,coord end,short promote);
/*Check if the chess pice can be promoted*/
bool can_promote(CHESS_TYPE type,coord start,coord end,COLOR player);
/*Take a move back*/
void regret(chess board[][SIZE],step back,COLOR player);
#endif

