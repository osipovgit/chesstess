CFLAGS = -Wall -Werror -std=c++11
OBJ = g++ $(CFLAGS) -c $< -o $@
TEST = g++ -std=c++11 $(GFLAGS) -I thirdparty/catch2 -c $< -o $@

.PHONY: clean

all:folder folder2 bin/chess.exe bin/tests.exe

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


bin/tests.exe: build/test.o build/CreateBoard_test.o build/Bishop_test.o build/King_test.o build/Queen_test.o build/kNight_test.o build/Pawn_test.o build/Rook_test.o build/CheckStep_test.o
	g++ $(CFLAGS) $^ -o $@

build/test.o: test/test.cpp test/head.h
	$(TEST)

build/CreateBoard_test.o: test/CreateBoard_test.cpp test/head.h
	$(TEST)

build/Bishop_test.o: test/Bishop_test.cpp test/head.h
	$(TEST)

build/King_test.o: test/King_test.cpp test/head.h
	$(TEST)

build/Queen_test.o: test/Queen_test.cpp test/head.h
	$(TEST)

build/kNight_test.o: test/kNight_test.cpp test/head.h
	$(TEST)

build/Rook_test.o: test/Rook_test.cpp test/head.h
	$(TEST)

build/Pawn_test.o: test/Pawn_test.cpp test/head.h
	$(TEST)

build/CheckStep_test.o: test/CheckStep_test.cpp test/head.h
	$(TEST)

clean:
	rm build/*.o
	rm bin/*.exe
	rm -R build
	rm -R bin
