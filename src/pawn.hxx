#ifndef PAWN_HXX
#define PAWN_HXX

#include <iostream>
#include "piece.hxx"
#include "board.hxx"

class pawn : public piece {
public:
    pawn(bool isWhite);
    Move getBestMove(const board& b, int x, int y) const;
    std::string getType() const;
};

#endif