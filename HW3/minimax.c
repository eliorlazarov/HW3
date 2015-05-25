#include "Draughts.h"
#include "minimax.h"


int scoreOfBoard(char board[BOARD_SIZE][BOARD_SIZE],int turn){//White turn = 1, black = -1
	int whiteMan = 0, whiteKing = 0;
	int blackMan = 0, blackKing = 0;
	int whiteScore;
	//if no possible moves, return 100 or -100

	for (int i = 0; i < BOARD_SIZE; i++){
		for (int j = 0; j < BOARD_SIZE; j++){
			if (board[i][j] == WHITE_K)
				whiteKing++;
			if (board[i][j] == WHITE_M)
				whiteMan++;
			if (board[i][j] == BLACK_K)
				blackKing++;
			if (board[i][j] == BLACK_M)
				blackMan++;
		}
	}
	whiteScore = KING_SCORE*(whiteKing - blackKing) + MAN_SCORE*(whiteMan - blackMan);
	return (turn*whiteScore);
}