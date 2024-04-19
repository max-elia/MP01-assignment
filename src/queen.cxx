#include "queen.hxx"

queen::queen(bool isWhite) 
    : piece(isWhite, 9, isWhite ? "img/q-w.png" : "img/q-b.png") {}

std::string queen::getType() const {
    return "queen";
}

Move queen::getBestMove(const board& b, int x, int y) const {
    Move m;
    m.x0 = x;
    m.y0 = y;
    
    while (x < 7) {
        if (b.getPiece(x + 1, y) == nullptr) {
            if (m.x1 == -1){
                m.x1 = x + 1;
                m.y1 = y;
            } else if (m.value == 0 && rand() % 2 == 0){
                m.x1 = x + 1;
                m.y1 = y;
            }
        } else {
            if (b.getPiece(x + 1, y)->getIsWhite() != this->getIsWhite()) {
                m.x1 = x + 1;
                m.y1 = y;
                m.value = b.getPiece(x + 1, y)->getValue();
                break;
            } else {
                break;
            }
        }
        x++;
    }

    x = m.x0;
    y = m.y0;

    while (x > 0) {
        if (b.getPiece(x - 1, y) == nullptr) {
            if (m.x1 == -1){
                m.x1 = x - 1;
                m.y1 = y;
            } else if (m.value == 0 && rand() % 2 == 0){
                m.x1 = x - 1;
                m.y1 = y;
            }
        } else {
            if (b.getPiece(x - 1, y)->getIsWhite() != this->getIsWhite()) {
                if (b.getPiece(x - 1, y)->getValue() > m.value) {
                    m.x1 = x - 1;
                    m.y1 = y;
                    m.value = b.getPiece(x - 1, y)->getValue();
                }
                break;
            } else {
                break;
            }
        }
        x--;
    }

    x = m.x0;
    y = m.y0;

    while (y < 7) {
        if (b.getPiece(x, y + 1) == nullptr) {
            if (m.x1 == -1){
                m.x1 = x;
                m.y1 = y + 1;
            } else if (m.value == 0 && rand() % 2 == 0){
                m.x1 = x;
                m.y1 = y + 1;
            }
        } else {
            if (b.getPiece(x, y + 1)->getIsWhite() != this->getIsWhite()) {
                if (b.getPiece(x, y + 1)->getValue() > m.value) {
                    m.x1 = x;
                    m.y1 = y + 1;
                    m.value = b.getPiece(x, y + 1)->getValue();
                }
                break;
            } else {
                break;
            }
        }
        y++;
    }

    x = m.x0;
    y = m.y0;

    while (y > 0) {
        if (b.getPiece(x, y - 1) == nullptr) {
            if (m.x1 == -1){
                m.x1 = x;
                m.y1 = y - 1;
            } else if (m.value == 0 && rand() % 2 == 0){
                m.x1 = x;
                m.y1 = y - 1;
            }
        } else {
            if (b.getPiece(x, y - 1)->getIsWhite() != this->getIsWhite()) {
                if (b.getPiece(x, y - 1)->getValue() > m.value) {
                    m.x1 = x;
                    m.y1 = y - 1;
                    m.value = b.getPiece(x, y - 1)->getValue();
                }
                break;
            } else {
                break;
            }
        }
        y--;
    }

    x = m.x0;
    y = m.y0;

    while (x < 7 && y < 7) {
        if (b.getPiece(x + 1, y + 1) == nullptr) {
            if (m.x1 == -1){
                m.x1 = x + 1;
                m.y1 = y + 1;
            } else if (m.value == 0 && rand() % 2 == 0){
                m.x1 = x + 1;
                m.y1 = y + 1;
            }
        } else {
            if (b.getPiece(x + 1, y + 1)->getIsWhite() != this->getIsWhite()) {
                m.x1 = x + 1;
                m.y1 = y + 1;
                m.value = b.getPiece(x + 1, y + 1)->getValue();
                break;
            } else {
                break;
            }
        }
        x++;
        y++;
    }

    x = m.x0;
    y = m.y0;

    while (x > 0 && y < 7) {
        if (b.getPiece(x - 1, y + 1) == nullptr) {
            if (m.x1 == -1){
                m.x1 = x - 1;
                m.y1 = y + 1;
            } else if (m.value == 0 && rand() % 2 == 0){
                m.x1 = x - 1;
                m.y1 = y + 1;
            }
        } else {
            if (b.getPiece(x - 1, y + 1)->getIsWhite() != this->getIsWhite()) {
                if (b.getPiece(x - 1, y + 1)->getValue() > m.value) {
                    m.x1 = x - 1;
                    m.y1 = y + 1;
                    m.value = b.getPiece(x - 1, y + 1)->getValue();
                }
                break;
            } else {
                break;
            }
        }
        x--;
        y++;
    }

    x = m.x0;
    y = m.y0;

    while (x < 7 && y > 0) {
        if (b.getPiece(x + 1, y - 1) == nullptr) {
            if (m.x1 == -1){
                m.x1 = x + 1;
                m.y1 = y - 1;
            } else if (m.value == 0 && rand() % 2 == 0){
                m.x1 = x + 1;
                m.y1 = y - 1;
            }
        } else {
            if (b.getPiece(x + 1, y - 1)->getIsWhite() != this->getIsWhite()) {
                if (b.getPiece(x + 1, y - 1)->getValue() > m.value) {
                    m.x1 = x + 1;
                    m.y1 = y - 1;
                    m.value = b.getPiece(x + 1, y - 1)->getValue();
                }
                break;
            } else {
                break;
            }
        }
        x++;
        y--;
    }

    x = m.x0;
    y = m.y0;

    while (x > 0 && y > 0) {
        if (b.getPiece(x - 1, y - 1) == nullptr) {
            if (m.x1 == -1){
                m.x1 = x - 1;
                m.y1 = y - 1;
            } else if (m.value == 0 && rand() % 2 == 0){
                m.x1 = x - 1;
                m.y1 = y - 1;
            }
        } else {
            if (b.getPiece(x - 1, y - 1)->getIsWhite() != this->getIsWhite()) {
                if (b.getPiece(x - 1, y - 1)->getValue() > m.value) {
                    m.x1 = x - 1;
                    m.y1 = y - 1;
                    m.value = b.getPiece(x - 1, y - 1)->getValue();
                }
                break;
            } else {
                break;
            }
        }
        x--;
        y--;
    }


    return m;
}