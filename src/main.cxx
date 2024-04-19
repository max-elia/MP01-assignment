#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "img/boardImg.h"
#include "board.hxx"

board b;

int const WIDTH = 640;
int const HEIGHT = 640;

struct global_t {
	SDL_Window * window = NULL;
	SDL_Renderer * renderer = NULL;
};

global_t g;

void paint_piece(const char* filepath, int x, int y) {
    int scale = 80; // Every square is 80x80 px
    SDL_Surface* surface = IMG_Load(filepath);
    if (!surface) {
        printf("Error loading image: %s\n", IMG_GetError());
        return;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(g.renderer, surface);
    if (!texture) {
        printf("Error creating texture: %s\n", SDL_GetError());
        SDL_FreeSurface(surface);
        return;
    }
    SDL_Rect dst;
    dst.x = x * scale;
    dst.y = (7 - y) * scale; // Start with white at the bottom
    dst.w = scale;
    dst.h = scale;
    SDL_RenderCopy(g.renderer, texture, NULL, &dst);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void paint_image(const char* filepath) {
	SDL_RenderClear(g.renderer);

	SDL_Surface* surface = IMG_Load(filepath);
	if (!surface) {
		printf("Error loading image: %s\n", IMG_GetError());
		return;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(g.renderer, surface);
	if (!texture) {
		printf("Error creating texture: %s\n", SDL_GetError());
		SDL_FreeSurface(surface);
		return;
	}
	SDL_Rect dst;
	dst.x = 0;
	dst.y = 0;
	dst.w = WIDTH;
	dst.h = HEIGHT;
	SDL_RenderCopy(g.renderer, texture, NULL, &dst);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);

	SDL_RenderPresent(g.renderer);
}

void paint_board() {
	SDL_RenderClear(g.renderer);

	int scale = 80; // 640 / 8
	for (int j = 0; j < px::height; ++j) {
		for (int i = 0; i < px::width; ++i) {
			unsigned char* color = px::header_data_cmap[px::header_data[j*px::width+i]];
			SDL_SetRenderDrawColor(g.renderer, color[0], color[1], color[2], SDL_ALPHA_OPAQUE);
			SDL_Rect r = { i*scale, j*scale, scale, scale };
			SDL_RenderFillRect(g.renderer, &r);
		}
	}

	for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
			piece* p = b.getPiece(i, j);
            if (p != nullptr) {
				paint_piece(p->getImgPath().c_str(), i, j);
            }
        }
    }

	SDL_RenderPresent(g.renderer);
}

void init_sdl(){
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		throw std::runtime_error("SDL_Init Error: " + std::string(SDL_GetError()));
	}

	g.window = SDL_CreateWindow("Chess", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 640, SDL_WINDOW_SHOWN);
	if (g.window == nullptr){
		SDL_Quit();
		throw std::runtime_error("SDL_CreateWindow Error: " + std::string(SDL_GetError()));
	}

	g.renderer = SDL_CreateRenderer(g.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (g.renderer == nullptr){
		SDL_DestroyWindow(g.window);
		SDL_Quit();
		throw std::runtime_error("SDL_CreateRenderer Error: " + std::string(SDL_GetError()));
	}
}

template <typename T>
void printMove(const T& piece, const Move& m) {
    std::string color = piece.getIsWhite() ? "White" : "Black";
    std::cout << color << " " << piece.getType() << " moves: " << (char)('A' + m.x0) << m.y0 + 1 << " -> " << (char)('A' + m.x1) << m.y1 + 1 << std::endl;
}

int main(int argc, char ** argv)
{
	srand(time(0));
	
	try {
		init_sdl();
	} catch (std::runtime_error & e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	Uint32 last_action_time = SDL_GetTicks();
	bool game_over = false;
	bool isWhiteTurn = true;
	while (1) {
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) break;
			if (e.type == SDL_KEYDOWN) {
				if (e.key.keysym.sym == SDLK_ESCAPE) break;
				if (e.key.keysym.sym == SDLK_SPACE) {
					b.reset();
					game_over = false;
					isWhiteTurn = true;
				}
			}
		}


		if (game_over) {
			if (isWhiteTurn) paint_image("img/black-wins.png");
			else paint_image("img/white-wins.png");
			continue;
		}
		Uint32 current_time = SDL_GetTicks();
		// One move every second
		if (current_time - last_action_time >= 1000) {
			if (isWhiteTurn) {
				std::vector<Move> bestMoves;
				int bestValue = -1;

				for (int i=0; i<8; i++) {
					for (int j=0; j<8; j++) {
						piece* p = b.getPiece(i, j);
						if (p != nullptr && p->getIsWhite()) {
							Move m = p->getBestMove(b, i, j);
							if (m.x1 != -1) {
								if (m.value > bestValue) {
									bestMoves.clear();
									bestMoves.push_back(m);
									bestValue = m.value;
								} else if (m.value == bestValue) {
									bestMoves.push_back(m);
								}
							}
						}
					}
				}
				if (!bestMoves.empty()) {
					Move nextMove = bestMoves[rand() % bestMoves.size()];
					if (nextMove.x1 != -1) {
						printMove(*b.getPiece(nextMove.x0, nextMove.y0), nextMove);
						try {
							b.movePiece(nextMove.x0, nextMove.y0, nextMove.x1, nextMove.y1);
						} catch (std::exception & e) {
							game_over = true;	
						}
					}
				}
			} else {
				std::vector<Move> bestMoves;
				int bestValue = -1;

				for (int i=0; i<8; i++) {
					for (int j=0; j<8; j++) {
						piece* p = b.getPiece(i, j);
						if (p != nullptr && !p->getIsWhite()) {
							Move m = p->getBestMove(b, i, j);
							if (m.x1 != -1) {
								if (m.value > bestValue) {
									bestMoves.clear();
									bestMoves.push_back(m);
									bestValue = m.value;
								} else if (m.value == bestValue) {
									bestMoves.push_back(m);
								}
							}
						}
					}
				}
				if (!bestMoves.empty()) {
					Move nextMove = bestMoves[rand() % bestMoves.size()];
					if (nextMove.x1 != -1) {
						printMove(*b.getPiece(nextMove.x0, nextMove.y0), nextMove);
						try {
							b.movePiece(nextMove.x0, nextMove.y0, nextMove.x1, nextMove.y1);
						} catch (std::exception & e) {
							game_over = true;
						}
					}
				}
			}
			isWhiteTurn = !isWhiteTurn;
			last_action_time = current_time;
		}

		paint_board();
	}

	SDL_DestroyRenderer(g.renderer);
	SDL_DestroyWindow(g.window);
	SDL_Quit();

	return 0;
}