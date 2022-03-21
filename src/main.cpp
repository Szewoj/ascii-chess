#include <iostream>
#include <string>
#include <stdlib.h>
#include "utilities.h"
#include "ChessPiece.h"

#define MOVELIST_SIZE 28


using namespace std;

int main()
{
    char c;
    bool whiteTurn = 1;
    short int decision;
    short int moveVect;
    short int promotionIdx;
    int moveList[MOVELIST_SIZE];
    Zeros( moveList, MOVELIST_SIZE );
    Board chess;
    chess.AddPieces();

    do{
        do{
            decision = -1;
            moveVect = -1;
            promotionIdx = 0;
            system( "clear" );
            if( whiteTurn )
                cout << "TURN: white (capital letters)" << endl << endl;
            else
                cout << "TURN: black (lowercase letters)" << endl << endl;
            cout << chess << endl << "Enter the piece's position in row and column format (RC) e.g. 46, or 0 to end the game" << endl;

            while( true ){ //
                while( true ){ //receiving a number while deleting other letters
                    cin >> c;
                    if(!cin)
                        break;
                    if(!isdigit(c))
                        continue;
                    cin.unget();
                    cin >> decision;
                    break;
                }

                if( !decision || (IsOnBoard( -1 + decision%10, -1 + decision/10 ) && chess.board[-1 + decision/10][-1 + decision%10] && chess.board[-1 + decision/10][-1 + decision%10]->IsWhite() == whiteTurn ))
                    break;
                cout << "Entered value in not appropriate! Please, try again:" << endl;
            }

            if( decision ){
                cout << endl;
                chess.board[-1 + decision/10][-1 + decision%10]->ShowMoves( &chess, moveList );
                PrintList( moveList );
                while( true ){
                    while( true ){
                        cin >> c;
                        if(!cin)
                            break;
                        if(!isdigit(c))
                            continue;
                        cin.unget();
                        cin >> moveVect;
                        break;
                    }

                    if( !moveVect || ProperMove( moveVect, moveList ) ){
                       break;
                    cout << "Entered move is not possible! Please, choose a value from the list above:" << endl;
                    }
                }
                if( moveVect ){
                    chess.board[-1 + decision/10][-1 + decision%10]->Move( &chess, moveVect );
                    Zeros( moveList, MOVELIST_SIZE );
                    whiteTurn = !whiteTurn;
                }
            }
        }while( !moveVect );

        promotionIdx = CanPromote( chess );
        if( promotionIdx ){
            cout << "A pawn on square " << promotionIdx << " can be promoted! Enter a letter Q, R, B or N to promote the pawn." << endl;

            while( true ){
                while( true ){
                    cin >> c;
                    if(!cin)
                        break;
                    if(!isdigit(c))
                        break;
                }

                if( IsSpecialPiece( c ) ){
                    break;
                cout << "Entered letter doeas not represent appropriate piece of chess! Please, try again:" << endl;
                }
            }
            chess.board[-1 + promotionIdx/10][-1 + promotionIdx%10]->PromotePawn( c );

        }

    }while( decision );

    cout << "Closing application..." << endl;
    chess.DelPieces();
    return 0;
}
