#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <string>
class board;

struct Move {
    int x0;
    int y0;
    int x1 = -1;  // To know if a piece has no valid moves
    int y1;
    int value = 0;
};

class piece {
    bool isWhite;
    int value;
    std::string imgPath;
public:
    piece(bool isWhite, int value, std::string imgPath);
    virtual ~piece() = default;
    bool getIsWhite() const;
    int getValue() const;
    std::string getImgPath() const;
    virtual Move getBestMove(const board& b, int x, int y) const = 0;
    virtual std::string getType() const  = 0;
};

#endif