#ifndef KNIGHT_HXX
#define KNIGHT_HXX

#include <iostream>
#include "piece.hxx"
#include "board.hxx"

class knight : public piece {
public:
    knight(bool isWhite);
    Move getBestMove(const board& b, int x, int y) const;
    std::string getType() const;
};

#endif