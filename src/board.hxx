#ifndef BOARD_H
#define BOARD_H

#include "piece.hxx"
#include "pawn.hxx"
#include "rook.hxx"
#include "knight.hxx"
#include "bishop.hxx"
#include "queen.hxx"
#include "king.hxx"

class board {
    piece* b[8][8];

public:
    board();
    ~board();
    piece* getPiece(int x, int y) const;
    void setPiece(int x, int y, piece* p);
    void movePiece(int x0, int y0, int x1, int y1);
    void reset();
};

#endif