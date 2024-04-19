PROJECT_EXE = ChessGame

DIR_SOURCES = ../src

CC = g++ -std=c++11

CFLAGS = -I$(DIR_SOURCES) -I/opt/homebrew/include/SDL2 # Change this to your SDL2 include path.
# On linux usually -I/usr/local/include/SDL2
# On macOS with Homebrew, it is -I/opt/homebrew/include/SDL2
LIBS = -lm -lSDL2 -lSDL2_image

_SOURCES = main.cxx board.cxx piece.cxx pawn.cxx rook.cxx knight.cxx bishop.cxx queen.cxx king.cxx
SOURCES = $(patsubst %,$(DIR_SOURCES)/%,$(_SOURCES))

$(PROJECT_EXE): $(SOURCES)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
