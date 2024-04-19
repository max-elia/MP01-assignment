# ATHENS CHESS

Chess game submission for the course "Le langage C++" at the Athens Student Exchange at Mines de Paris.

The chess piece png images are downloaded from: https://brosen.itch.io/pixel-chess

## Build

To build the project, you need to have the following dependencies installed:
`SDL2, SDL2_image`

You need to change the makefile to include the location of the SDL2 and SDL2_image in order to compile the project.

```makefile
CFLAGS = -I$(DIR_SOURCES) -I/opt/homebrew/include/SDL2
# Change this to your SDL2 include path.
# On linux usually -I/usr/local/include/SDL2
# On macOS with Homebrew, it is -I/opt/homebrew/include/SDL2
```

Then run the following commands:

```bash
cd src
make
./ChessGame
```

## Documentation

The game logic is very simplified. At every move, all pieces check their possible moves.

A `Move` has a value of 0 if the move is to an empty square, 1 for capturing enemy pawn, 3 for enemy bishop and knight, 5 for enemy rook, 9 for enemy queen and 10 for enemy king.

Moves with higher value are always preferred. Pieces don't know, if they are under attack.

The game ends when the king is captured.

Another game is started when the space key is pressed.

## Assignment requirements

### Classes

-   [x] Piece (parent class) -> Pawn, Rook, Knight, Bishop, Queen, King (child classes)
-   [x] Board

#### Inheritance / Polymorphism

The `Piece` class has a virtual method `getBestMove` which is overridden by the child classes.

### Exceptions

-   The initialization of the SDL library is wrapped in a try-catch block.
-   An exception is thrown when the king is captured.

### Std Library

-   `std::exception` is used to throw and catch an exception when the king is captured.
-   `std::string` is used to store the name of the pieces.
-   `std::vector` is used to store the best Move of each piece and randomly select one.
-   `std::cout` is used to print the moves.

### Templates

A template is used for the genereic printMove function getting the type of the piece as a template parameter.

```cpp
template <typename T>
void printMove(const T& piece, const Move& m) {
    std::string color = piece.getIsWhite() ? "White" : "Black";
    std::cout << color << " " << piece.getType() << " moves: " << (char)('A' + m.x0) << m.y0 + 1 << " -> " << (char)('A' + m.x1) << m.y1 + 1 << std::endl;
}
```
