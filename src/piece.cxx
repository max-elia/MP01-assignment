#include "piece.hxx"
#include "board.hxx"
#include <string>

piece::piece(bool isWhite, int value, std::string imgPath) 
    : isWhite(isWhite), value(value), imgPath(imgPath) {}

bool piece::getIsWhite() const {
    return isWhite;
}
int piece::getValue() const {
    return value;
}
std::string piece::getImgPath() const {
    return imgPath;
}
