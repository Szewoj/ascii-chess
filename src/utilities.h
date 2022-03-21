#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include "ChessPiece.h"
#include <iostream>

#define BOARD_SIZE 8
#define PIECES_AMOUNT 32

class ChessPiece;
struct Board;

bool IsOnBoard( int x, int y );
void AddMove( int* moveList, int coord );
void PrintList( int* moveList );
void Zeros( int* table, const int SIZE );
bool ProperMove( int vect, int* moveList );
bool IsSpecialPiece( char piece );
short int CanPromote( Board& chess );




struct Board{

    ChessPiece* board[BOARD_SIZE][BOARD_SIZE];
    ChessPiece* pieces[PIECES_AMOUNT];

    Board(){
        for( int i = 0; i < 8; ++i )
            for( int j = 0; j < 8; ++j )
                this->board[i][j] = NULL;
        for( int i = 0; i <= PIECES_AMOUNT; ++i )
            this->pieces[i] = NULL;
    }

    void AddPieces();
    void DelPieces();

    friend std::ostream& operator << ( std::ostream& out, const Board& board );

};



#endif // UTILITIES_H_INCLUDED
