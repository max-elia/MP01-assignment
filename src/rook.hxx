#ifndef ROOK_HXX
#define ROOK_HXX

#include <iostream>
#include "piece.hxx"
#include "board.hxx"

class rook : public piece {
public:
    rook(bool isWhite);
    Move getBestMove(const board& b, int x, int y) const;
    std::string getType() const;
};

#endif