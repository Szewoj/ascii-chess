#include "utilities.h"

bool IsOnBoard( int x, int y ){
    return (x >= 0 && x <= 7 && y >= 0 && y <= 7);
}

void AddMove( int* moveList, int coord ){
    int i = 0;
    for(; moveList[i]; ++i );
    moveList[i] = coord;
}

void PrintList( int* moveList ){
    std::cout << "Choose move from list below or enter 0 to cancel:" << std::endl;
    if( moveList[0] )
        std::cout << moveList[0];
    for( int i = 1; moveList[i]; ++i )
        std::cout << ", " << moveList[i];
    std::cout << "." << std::endl;
}

void Zeros( int* table,  const int SIZE ){
    for( int i = 0; i < SIZE; ++i )
        table[i] = 0;
}

bool ProperMove( int vect, int* moveList ){
    for( int i = 0; moveList[i]; ++i )
        if( vect == moveList[i] )
            return true;
    return false;
}

bool IsSpecialPiece( char piece ){
    return ( piece == 'Q' || piece == 'q' || piece == 'R' || piece == 'r' || piece == 'B' || piece == 'b' || piece == 'N' || piece == 'n' );
}

short int CanPromote( Board& chess ){
    for( int i = 0; i < 8; ++i ){
        if( chess.board[0][i] && chess.board[0][i]->GetSign() == 'P' )
            return 11 + i;
        if( chess.board[7][i] && chess.board[7][i]->GetSign() == 'p' )
            return 81 + i;
    }
    return 0;
}

void Board::AddPieces(){
    int p = -1;
    this->pieces[++p] = new ChessPiece( 8, 4, 'Q', this );
    this->pieces[++p] = new ChessPiece( 1, 4, 'q', this );
    this->pieces[++p] = new ChessPiece( 8, 5, 'K', this );
    this->pieces[++p] = new ChessPiece( 1, 5, 'k', this );
    this->pieces[++p] = new ChessPiece( 8, 1, 'R', this );
    this->pieces[++p] = new ChessPiece( 8, 8, 'R', this );
    this->pieces[++p] = new ChessPiece( 8, 2, 'N', this );
    this->pieces[++p] = new ChessPiece( 8, 7, 'N', this );
    this->pieces[++p] = new ChessPiece( 8, 3, 'B', this );
    this->pieces[++p] = new ChessPiece( 8, 6, 'B', this );
    this->pieces[++p] = new ChessPiece( 1, 1, 'r', this );
    this->pieces[++p] = new ChessPiece( 1, 8, 'r', this );
    this->pieces[++p] = new ChessPiece( 1, 2, 'n', this );
    this->pieces[++p] = new ChessPiece( 1, 7, 'n', this );
    this->pieces[++p] = new ChessPiece( 1, 3, 'b', this );
    this->pieces[++p] = new ChessPiece( 1, 6, 'b', this );

    for( int i = 1; i < 9; ++i )
        this->pieces[++p] = new ChessPiece( 2, i, 'p', this );
    for( int i = 1; i < 9; ++i )
        this->pieces[++p] = new ChessPiece( 7, i, 'P', this );

}

void Board::DelPieces(){
    for( int i = 0; i <= 32; ++i )
        if( this->pieces[i] )
            delete this->pieces[i];
}

std::ostream& operator << ( std::ostream& out, const Board& chess ){

    out << "  12345678" << std::endl;
    for( int i = 0; i < 8; ++i ){
        out << i+1 << ' ';
        for( int j = 0; j < 8; ++j ){
            if( chess.board[i][j] ){
                out << chess.board[i][j]->GetSign();
                }
            else if( (i + j) % 2 )
                out << "░";
            else
                out << "▒";
        }
        out << ' ' << i+1 << std::endl;
    }
	out << "  12345678" << std::endl;

    return out;
}
