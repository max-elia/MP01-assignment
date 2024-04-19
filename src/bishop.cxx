#include "bishop.hxx"

bishop::bishop(bool isWhite) 
    : piece(isWhite, 3, isWhite ? "img/b-w.png" : "img/b-b.png") {}

std::string bishop::getType() const {
    return "bishop";
}

Move bishop::getBestMove(const board& b, int x, int y) const {
    Move m;
    m.x0 = x;
    m.y0 = y;
    // m.x1 = 6;
    // m.y1 = 1;
    // return m;

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
            if (b.getPiece(x + 1, y + 1)->getIsWhite() != this->getIsWhite() && b.getPiece(x + 1, y + 1)->getValue() >= m.value){
                if (b.getPiece(x + 1, y + 1)->getValue() == m.value && rand() % 2 == 0){
                    m.x1 = x + 1;
                    m.y1 = y + 1;
                    m.value = b.getPiece(x + 1, y + 1)->getValue();
                } else {
                    m.x1 = x + 1;
                    m.y1 = y + 1;
                    m.value = b.getPiece(x + 1, y + 1)->getValue();
                }
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
                if (b.getPiece(x - 1, y + 1)->getValue() >= m.value) {
                    if (b.getPiece(x - 1, y + 1)->getValue() == m.value && rand() % 2 == 0){
                        m.x1 = x - 1;
                        m.y1 = y + 1;
                        m.value = b.getPiece(x - 1, y + 1)->getValue();
                    } else {
                        m.x1 = x - 1;
                        m.y1 = y + 1;
                        m.value = b.getPiece(x - 1, y + 1)->getValue();
                    }
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
                if (b.getPiece(x + 1, y - 1)->getValue() >= m.value) {
                    if (b.getPiece(x + 1, y - 1)->getValue() == m.value && rand() % 2 == 0){
                        m.x1 = x + 1;
                        m.y1 = y - 1;
                        m.value = b.getPiece(x + 1, y - 1)->getValue();
                    } else {
                        m.x1 = x + 1;
                        m.y1 = y - 1;
                        m.value = b.getPiece(x + 1, y - 1)->getValue();
                    }
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
                if (b.getPiece(x - 1, y - 1)->getValue() >= m.value) {
                    if (b.getPiece(x - 1, y - 1)->getValue() == m.value && rand() % 2 == 0){
                        m.x1 = x - 1;
                        m.y1 = y - 1;
                        m.value = b.getPiece(x - 1, y - 1)->getValue();
                    } else {
                        m.x1 = x - 1;
                        m.y1 = y - 1;
                        m.value = b.getPiece(x - 1, y - 1)->getValue();
                    }
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