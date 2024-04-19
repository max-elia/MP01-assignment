#include "knight.hxx"

knight::knight(bool isWhite) 
    : piece(isWhite, 3, isWhite ? "img/h-w.png" : "img/h-b.png") {}

std::string knight::getType() const {
    return "knight";
}

Move knight::getBestMove(const board& b, int x, int y) const {
    Move m;
    m.x0 = x;
    m.y0 = y;
    
    if (x < 6 && y < 7 && ((b.getPiece(x + 2, y + 1) == nullptr) || (b.getPiece(x + 2, y + 1) != nullptr && b.getPiece(x + 2, y + 1)->getIsWhite() != this->getIsWhite()))) {
        m.x1 = x + 2;
        m.y1 = y + 1;
        m.value = b.getPiece(x + 2, y + 1) == nullptr ? 0 : b.getPiece(x + 2, y + 1)->getValue();
    }
    if (x < 6 && y > 0 && ((b.getPiece(x + 2, y - 1) == nullptr && m.value == 0) || (b.getPiece(x + 2, y - 1) != nullptr && b.getPiece(x + 2, y - 1)->getIsWhite() != this->getIsWhite() && m.value <= b.getPiece(x + 2, y - 1)->getValue()))) {
        m.x1 = x + 2;
        m.y1 = y - 1;
        m.value = b.getPiece(x + 2, y - 1) == nullptr ? 0 : b.getPiece(x + 2, y - 1)->getValue();
    }

    if (x > 1 && y < 7 && ((b.getPiece(x - 2, y + 1) == nullptr && m.value == 0) || (b.getPiece(x - 2, y + 1) != nullptr && b.getPiece(x - 2, y + 1)->getIsWhite() != this->getIsWhite() && m.value <= b.getPiece(x - 2, y + 1)->getValue()))) {
        m.x1 = x - 2;
        m.y1 = y + 1;
        m.value = b.getPiece(x - 2, y + 1) == nullptr ? 0 : b.getPiece(x - 2, y + 1)->getValue();
    }

    if (x > 1 && y > 0 && ((b.getPiece(x - 2, y - 1) == nullptr && m.value == 0) || (b.getPiece(x - 2, y - 1) != nullptr && b.getPiece(x - 2, y - 1)->getIsWhite() != this->getIsWhite() && m.value <= b.getPiece(x - 2, y - 1)->getValue()))) {
        m.x1 = x - 2;
        m.y1 = y - 1;
        m.value = b.getPiece(x - 2, y - 1) == nullptr ? 0 : b.getPiece(x - 2, y - 1)->getValue();
    }

    if (x < 7 && y < 6 && ((b.getPiece(x + 1, y + 2) == nullptr && m.value == 0) || (b.getPiece(x + 1, y + 2) != nullptr && b.getPiece(x + 1, y + 2)->getIsWhite() != this->getIsWhite() && m.value <= b.getPiece(x + 1, y + 2)->getValue()))) {
        m.x1 = x + 1;
        m.y1 = y + 2;
        m.value = b.getPiece(x + 1, y + 2) == nullptr ? 0 : b.getPiece(x + 1, y + 2)->getValue();
    }

    if (x < 7 && y > 1 && ((b.getPiece(x + 1, y - 2) == nullptr && m.value == 0) || (b.getPiece(x + 1, y - 2) != nullptr && b.getPiece(x + 1, y - 2)->getIsWhite() != this->getIsWhite() && m.value <= b.getPiece(x + 1, y - 2)->getValue()))) {
        m.x1 = x + 1;
        m.y1 = y - 2;
        m.value = b.getPiece(x + 1, y - 2) == nullptr ? 0 : b.getPiece(x + 1, y - 2)->getValue();
    }

    if (x > 0 && y < 6 && ((b.getPiece(x - 1, y + 2) == nullptr && m.value == 0) || (b.getPiece(x - 1, y + 2) != nullptr && b.getPiece(x - 1, y + 2)->getIsWhite() != this->getIsWhite() && m.value <= b.getPiece(x - 1, y + 2)->getValue()))) {
        m.x1 = x - 1;
        m.y1 = y + 2;
        m.value = b.getPiece(x - 1, y + 2) == nullptr ? 0 : b.getPiece(x - 1, y + 2)->getValue();
    }

    if (x > 0 && y > 1 && ((b.getPiece(x - 1, y - 2) == nullptr && m.value == 0) || (b.getPiece(x - 1, y - 2) != nullptr && b.getPiece(x - 1, y - 2)->getIsWhite() != this->getIsWhite() && m.value <= b.getPiece(x - 1, y - 2)->getValue()))) {
        m.x1 = x - 1;
        m.y1 = y - 2;
        m.value = b.getPiece(x - 1, y - 2) == nullptr ? 0 : b.getPiece(x - 1, y - 2)->getValue();
    }
    // std::cout << "Knight: " << m.x0 << " " << m.y0 << " " << m.x1 << " " << m.y1 << " value:" << m.value << std::endl;
    return m;
}