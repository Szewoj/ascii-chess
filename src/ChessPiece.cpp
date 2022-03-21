#include "ChessPiece.h"

void SeekMove( Board* chess, int* moveList, bool isWhite, int currX, int currY, int dirX, int dirY  ){

    if( !IsOnBoard( currX, currY ))
        return;

    if( !chess->board[currY][currX] || chess->board[currY][currX]->IsWhite() != isWhite )
        AddMove( moveList, 10*currY + currX +11 );

    if( (dirX || dirY) && !(chess->board[currY][currX]) )
        SeekMove( chess, moveList, isWhite, currX + dirX, currY + dirY, dirX, dirY );
}

void SeekMovePawn( Board* chess, int* moveList, bool isWhite, int currX, int currY ){

	if( !IsOnBoard( currX, currY ))
        return;

    if( !chess->board[currY][currX] )
        AddMove( moveList, 10*currY + currX +11 );

    if( IsOnBoard( currX - 1, currY ) && chess->board[currY][currX-1] && chess->board[currY][currX-1]->IsWhite() != isWhite )
        AddMove( moveList, 10*currY + currX +10 );

    if( IsOnBoard( currX + 1, currY ) && chess->board[currY][currX+1] && chess->board[currY][currX+1]->IsWhite() != isWhite )
        AddMove( moveList, 10*currY + currX +12 );

}



void ChessPiece::InitPiece( Board* board ){
    board->board[this->GetRow()][this->GetCol()] = this;
}

void ChessPiece::Move( Board* board, short int vect ){
    short int x = -1 + vect%10;
    short int y = -1 + vect/10;

    board->board[this->GetRow()][this->GetCol()] = NULL;
    board->board[y][x] = this;
    this->row = y;
    this->col = x;


    this->firstMove = false;
}

void ChessPiece::ShowMoves( Board* chess, int* moveList ){
    if( this->GetSign() == 'P' ){
        SeekMovePawn( chess, moveList, this->IsWhite(), this->GetCol(), this->GetRow() -1 );
        if( this->FirstMove() )
            SeekMove( chess, moveList, this->IsWhite(), this->GetCol(), this->GetRow() -2, 0, 0 );
        }
    if( this->GetSign() == 'p' ){
        SeekMovePawn( chess, moveList, this->IsWhite(), this->GetCol(), this->GetRow() +1 );
        if( this->FirstMove() )
            SeekMove( chess, moveList, this->IsWhite(), this->GetCol(), this->GetRow() +2, 0, 0 );
        }

    if( this->GetSign() == 'N' || this->GetSign() == 'n' )
        for( int i = -2; i <= 2; ++i )
            for( int j = -2; j <= 2; ++j )
                if( ( i && j ) && ( i+j==1 || i+j==3 || i+j==-1 || i+j==-3) )
                    SeekMove( chess, moveList, this->IsWhite(), this->GetCol() + i, this->GetRow() + j, 0, 0 );

if( this->GetSign() == 'B' || this->GetSign() == 'b' )
        for( int i = -1; i < 2; ++i )
            for( int j = -1; j < 2; ++j )
                if( ( i && j ) )
                    SeekMove( chess, moveList, this->IsWhite(), this->GetCol() + i, this->GetRow() + j, i, j );

if( this->GetSign() == 'R' || this->GetSign() == 'r' )
        for( int i = -1; i < 2; ++i )
            for( int j = -1; j < 2; ++j )
                if( ( i || j ) && !( i && j ) )
                    SeekMove( chess, moveList, this->IsWhite(), this->GetCol() + i, this->GetRow() + j, i, j );

if( this->GetSign() == 'Q' || this->GetSign() == 'q' )
        for( int i = -1; i < 2; ++i )
            for( int j = -1; j < 2; ++j )
                if( ( i || j ) )
                    SeekMove( chess, moveList, this->IsWhite(), this->GetCol() + i, this->GetRow() + j, i, j );

    if( this->GetSign() == 'K' || this->GetSign() == 'k' )
        for( int i = -1; i < 2; ++i )
            for( int j = -1; j < 2; ++j )
                if( ( i || j ) )
                    SeekMove( chess, moveList, this->IsWhite(), this->GetCol() + i, this->GetRow() + j, 0, 0 );



}

void ChessPiece::PromotePawn( char newSign ){

    if( this->IsWhite() ){
        if( newSign == 'Q' || newSign == 'q')
            this->sign = 'Q';
        if( newSign == 'R' || newSign == 'r')
            this->sign = 'R';
        if( newSign == 'B' || newSign == 'b')
            this->sign = 'B';
        if( newSign == 'N' || newSign == 'n')
            this->sign = 'N';
    }else{
        if( newSign == 'Q' || newSign == 'q')
            this->sign = 'q';
        if( newSign == 'R' || newSign == 'r')
            this->sign = 'r';
        if( newSign == 'B' || newSign == 'b')
            this->sign = 'b';
        if( newSign == 'N' || newSign == 'n')
            this->sign = 'n';
    }
}
