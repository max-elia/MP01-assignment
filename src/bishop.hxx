#ifndef BISHOP_HXX
#define BISHOP_HXX

#include <iostream>
#include "piece.hxx"
#include "board.hxx"

class bishop : public piece {
public:
    bishop(bool isWhite);
    Move getBestMove(const board& b, int x, int y) const;
    std::string getType() const;
};

#endif