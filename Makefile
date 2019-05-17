CFLAGS = -Wall -Werror -std=c++17
OBJ = g++ $(CFLAGS) -c $< -o $@

.PHONY: clean

all:folder folder2 bin/chess.exe

folder:
	mkdir -p build 

folder2:
	mkdir -p bin 

bin/chess.exe: build/main.o build/Bishop.o build/CheckStep.o build/King.o build/kNight.o build/Pawn.o build/PrintBoard.o build/Queen.o build/Rook.o build/CreateBoard.o
	g++ $(CFLAGS) $^ -o $@

build/main.o: src/main.cpp src/head.h 
	$(OBJ)

build/Bishop.o: src/Bishop.cpp src/head.h 
	$(OBJ)

build/CheckStep.o: src/CheckStep.cpp src/head.h 
	$(OBJ)

build/CreateBoard.o: src/CreateBoard.cpp src/head.h 
	$(OBJ)

build/King.o: src/King.cpp src/head.h 
	$(OBJ)

build/kNight.o: src/kNight.cpp src/head.h 
	$(OBJ)

build/Pawn.o: src/Pawn.cpp src/head.h 
	$(OBJ)

build/PrintBoard.o: src/PrintBoard.cpp src/head.h 
	$(OBJ)

build/Queen.o: src/Queen.cpp src/head.h 
	$(OBJ)

build/Rook.o: src/Rook.cpp src/head.h 
	$(OBJ)

clean:
	rm build/*.o
	rm bin/*.exe
	rm -R build
	rm -R bin
