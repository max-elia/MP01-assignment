#include "pawn.hxx"

pawn::pawn(bool isWhite) 
    : piece(isWhite, 1, isWhite ? "img/p-w.png" : "img/p-b.png") {}

std::string pawn::getType() const {
    return "pawn";
}

Move pawn::getBestMove(const board& b, int x, int y) const {
    Move m;
    m.x0 = x;
    m.y0 = y;
    
    if (this->getIsWhite()) {
        if (y < 7 && b.getPiece(x, y + 1) == nullptr){
            m.x1 = x;
            m.y1 = y + 1;
            if (y == 1 && b.getPiece(x, y + 2) == nullptr && rand() % 2 == 0){
                m.x1 = x;
                m.y1 = y + 2;
            }
        }
        if (x < 7 && b.getPiece(x + 1, y + 1) != nullptr && b.getPiece(x + 1, y + 1)->getIsWhite() != this->getIsWhite()) {
            m.x1 = x + 1;
            m.y1 = y + 1;
            m.value = b.getPiece(x + 1, y + 1)->getValue();
        }
        if (x > 0 && b.getPiece(x - 1, y + 1) != nullptr && b.getPiece(x - 1, y + 1)->getIsWhite() != this->getIsWhite()) {
            if (b.getPiece(x - 1, y + 1)->getValue() > m.value)
            m.value = b.getPiece(x - 1, y + 1)->getValue();
            m.x1 = x - 1;
            m.y1 = y + 1;
        }

    } else {
        if (y > 0 && b.getPiece(x, y - 1) == nullptr){
            m.x1 = x;
            m.y1 = y - 1;
            if (y == 6 && b.getPiece(x, y - 2) == nullptr && rand() % 2 == 0){
                m.x1 = x;
                m.y1 = y - 2;
            }
        }
        if (x < 7 && b.getPiece(x + 1, y - 1) != nullptr && b.getPiece(x + 1, y - 1)->getIsWhite() != this->getIsWhite()) {
            m.x1 = x + 1;
            m.y1 = y - 1;
            m.value = b.getPiece(x + 1, y - 1)->getValue();
        }
        if (x > 0 && b.getPiece(x - 1, y - 1) != nullptr && b.getPiece(x - 1, y - 1)->getIsWhite() != this->getIsWhite()) {
            if (b.getPiece(x - 1, y - 1)->getValue() > m.value)
            m.value = b.getPiece(x - 1, y - 1)->getValue();
            m.x1 = x - 1;
            m.y1 = y - 1;
        }
    }
    return m;
}