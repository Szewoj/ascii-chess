#ifndef CHESSPIECE_INCLUDED
#define CHESSPIECE_INCLUDED

#include "utilities.h"

struct Board;

void SeekMove( Board* chess, int* moveList, bool isWhite, int currX, int currY, int dirX, int dirY ); // Queen, Tower, Bishop, King and Knight
void SeekMovePawn( Board* chess, int* moveList, bool isWhite, int currX, int currY ); // Pawn


class ChessPiece{
    private:

    int row, col;
    char sign;
    bool firstMove;

    public:

    void InitPiece( Board* chess );

    ChessPiece(){}
    ChessPiece( int i, int j, char c, Board* chess ): row( i -1 ), col( j -1 ), sign( c ) { this->InitPiece( chess ); this->firstMove = true; }

    int GetRow() const { return this->row; }
    int GetCol() const { return this->col; }
    char GetSign() const { return this->sign; }
    bool IsWhite() const { bool isWhite = this->sign < 'a'; return isWhite;}
    bool FirstMove() const { return this->firstMove; }
    void Move( Board* chess, short int vect );
    void ShowMoves( Board* chess, int* moveList );
    void PromotePawn ( char newSign );

};


#endif // CHESSPIECE_INCLUDED
