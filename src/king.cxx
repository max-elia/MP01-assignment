#include "king.hxx"

king::king(bool isWhite) 
    : piece(isWhite, 10, isWhite ? "img/k-w.png" : "img/k-b.png") {}

std::string king::getType() const {
    return "king";
}

Move king::getBestMove(const board& b, int x, int y) const {
    Move m;
    m.x0 = x;
    m.y0 = y;
    
    if (x < 7 && (b.getPiece(x + 1, y) == nullptr || b.getPiece(x + 1, y)->getIsWhite() != this->getIsWhite())){
        m.x1 = x + 1;
        m.y1 = y;
        m.value = b.getPiece(x + 1, y) == nullptr ? 0 : b.getPiece(x + 1, y)->getValue();
    }
    if (x > 0 && (b.getPiece(x - 1, y) == nullptr && m.value == 0 || b.getPiece(x - 1, y) != nullptr && b.getPiece(x - 1, y)->getIsWhite() != this->getIsWhite() && m.value < b.getPiece(x - 1, y)->getValue())) {
        m.x1 = x - 1;
        m.y1 = y;
        m.value = b.getPiece(x - 1, y) == nullptr && m.value == 0 ? 0 : b.getPiece(x - 1, y)->getValue();
    }
    if (y < 7 && (b.getPiece(x, y + 1) == nullptr && m.value == 0 || b.getPiece(x, y + 1) != nullptr && b.getPiece(x, y + 1)->getIsWhite() != this->getIsWhite() && m.value < b.getPiece(x, y + 1)->getValue())) {
        m.x1 = x;
        m.y1 = y + 1;
        m.value = b.getPiece(x, y + 1) == nullptr ? 0 : b.getPiece(x, y + 1)->getValue();
    }
    if (y > 0 && (b.getPiece(x, y - 1) == nullptr && m.value == 0 || b.getPiece(x, y - 1) != nullptr && b.getPiece(x, y - 1)->getIsWhite() != this->getIsWhite() && m.value < b.getPiece(x, y - 1)->getValue())) {
        m.x1 = x;
        m.y1 = y - 1;
        m.value = b.getPiece(x, y - 1) == nullptr ? 0 : b.getPiece(x, y - 1)->getValue();
    }
    if (x < 7 && y < 7 && (b.getPiece(x + 1, y + 1) == nullptr && m.value == 0 || b.getPiece(x + 1, y + 1) != nullptr && b.getPiece(x + 1, y + 1)->getIsWhite() != this->getIsWhite() && m.value < b.getPiece(x + 1, y + 1)->getValue())) {
        m.x1 = x + 1;
        m.y1 = y + 1;
        m.value = b.getPiece(x + 1, y + 1) == nullptr ? 0 : b.getPiece(x + 1, y + 1)->getValue();
    }
    if (x > 0 && y < 7 && (b.getPiece(x - 1, y + 1) == nullptr && m.value == 0 || b.getPiece(x - 1, y + 1) != nullptr && b.getPiece(x - 1, y + 1)->getIsWhite() != this->getIsWhite() && m.value < b.getPiece(x - 1, y + 1)->getValue())) {
        m.x1 = x - 1;
        m.y1 = y + 1;
        m.value = b.getPiece(x - 1, y + 1) == nullptr ? 0 : b.getPiece(x - 1, y + 1)->getValue();
    }
    if (x < 7 && y > 0 && (b.getPiece(x + 1, y - 1) == nullptr && m.value == 0 || b.getPiece(x + 1, y - 1) != nullptr && b.getPiece(x + 1, y - 1)->getIsWhite() != this->getIsWhite() && m.value < b.getPiece(x + 1, y - 1)->getValue())) {
        m.x1 = x + 1;
        m.y1 = y - 1;
        m.value = b.getPiece(x + 1, y - 1) == nullptr ? 0 : b.getPiece(x + 1, y - 1)->getValue();
    }
    if (x > 0 && y > 0 && (b.getPiece(x - 1, y - 1) == nullptr && m.value == 0 || b.getPiece(x - 1, y - 1) != nullptr && b.getPiece(x - 1, y - 1)->getIsWhite() != this->getIsWhite() && m.value < b.getPiece(x - 1, y - 1)->getValue())) {
        m.x1 = x - 1;
        m.y1 = y - 1;
        m.value = b.getPiece(x - 1, y - 1) == nullptr ? 0 : b.getPiece(x - 1, y - 1)->getValue();
    }
    return m;
}