#include "board.hxx"

// Constructor
board::board() {
    reset();
}

// Destructor
board::~board() {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			delete b[i][j];
			b[i][j] = nullptr;
		}
	}
}

piece* board::getPiece(int x, int y) const {
    return b[x][y];
}

void board::setPiece(int x, int y, piece* p) {
    b[x][y] = p;
}

void board::movePiece(int x0, int y0, int x1, int y1) {
	piece* p1 = b[x1][y1];
	if (p1 != nullptr) {
		if (p1->getValue() == 10) {
			std::cout << (!p1->getIsWhite() ? "White" : "Black") <<" wins" << std::endl;
			throw std::exception();
		}
	}
    b[x1][y1] = b[x0][y0];
	b[x0][y0] = nullptr;
	piece* p0 = b[x1][y1];
	if (p0->getValue() == 1 && (p0->getIsWhite() && y1 == 7 || !p0->getIsWhite() && y1 == 0)) {
		b[x1][y1] = new queen(p0->getIsWhite());
	}
}
void board::reset(){
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			delete b[i][j];
			b[i][j] = nullptr;
		}
	}
	setPiece(0, 0, new rook(1));
	setPiece(1, 0, new knight(1));
	setPiece(2, 0, new bishop(1));
	setPiece(3, 0, new queen(1));
	setPiece(4, 0, new king(1));
	setPiece(5, 0, new bishop(1));
	setPiece(6, 0, new knight(1));
	setPiece(7, 0, new rook(1));
	setPiece(0, 1, new pawn(1));
	setPiece(1, 1, new pawn(1));
	setPiece(2, 1, new pawn(1));
	setPiece(3, 1, new pawn(1));
	setPiece(4, 1, new pawn(1));
	setPiece(5, 1, new pawn(1));
	setPiece(6, 1, new pawn(1));
	setPiece(7, 1, new pawn(1));
	
	setPiece(0, 6, new pawn(0));
	setPiece(1, 6, new pawn(0));
	setPiece(2, 6, new pawn(0));
	setPiece(3, 6, new pawn(0));
	setPiece(4, 6, new pawn(0));
	setPiece(5, 6, new pawn(0));
	setPiece(6, 6, new pawn(0));
	setPiece(7, 6, new pawn(0));
	setPiece(0, 7, new rook(0));
	setPiece(2, 7, new knight(0));
	setPiece(2, 7, new bishop(0));
	setPiece(3, 7, new queen(0));
	setPiece(4, 7, new king(0));
	setPiece(5, 7, new bishop(0));
	setPiece(6, 7, new knight(0));
	setPiece(7, 7, new rook(0));
}