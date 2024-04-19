#ifndef QUEEN_HXX
#define QUEEN_HXX

#include <iostream>
#include "piece.hxx"
#include "board.hxx"

class queen : public piece {
public:
    queen(bool isWhite);
    Move getBestMove(const board& b, int x, int y) const;
    std::string getType() const;
};

#endif