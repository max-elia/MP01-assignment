#ifndef KING_HXX
#define KING_HXX

#include <iostream>
#include "piece.hxx"
#include "board.hxx"

class king : public piece {
public:
    king(bool isWhite);
    Move getBestMove(const board& b, int x, int y) const;
    std::string getType() const;
};

#endif