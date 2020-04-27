OBJDS = obj\Array.o obj\DataStructure.o  obj\String.o
OBJGAMES= obj\Games.o obj\TicTacToe.o
OBJCOD = obj\cod_algorithm.o obj\cod_array.o obj\cod_limits.o obj\cod_pair.o obj\cod_scan.o obj\cod_string.o
OBJS = obj\Account.o obj\AccountHandler.o obj\AnimeHandler.o obj\Constants.o obj\CreateAccount.o obj\ExHandler.o obj\FileHandler.o obj\Help.o obj\Home.o obj\Security.o obj\Settings.o obj\UIhandler.o obj\iCoder.o
OBJF = obj/*.o
LIBS = -static
CC = g++
LFLAG = -Wall
CFLAGS = -Wall -c

### Build the Project

all: $(OBJDS) $(OBJGAMES) $(OBJCOD) $(OBJS)
	$(CC) $(LFLAG) $(OBJF) $(LIBS) -o iCoder

### Algorithm files are compiled from below

### Code Analysis files are compiled from below

### Data Structure files are compiled from below

obj\Array.o: dsa\src\Array.cpp dsa\header\Array.hpp
	$(CC) $(CFLAGS) dsa\src\Array.cpp -o obj\Array.o

obj\DataStructure.o: dsa\src\DataStructure.cpp dsa\header\DataStructure.hpp
	$(CC) $(CFLAGS) dsa\src\DataStructure.cpp -o obj\DataStructure.o

obj\String.o: dsa\src\String.cpp dsa\header\String.hpp
	$(CC) $(CFLAGS) dsa\src\String.cpp -o obj\String.o

### Game files are compiled from below

obj\Games.o: games\src\Games.cpp games\header\Games.hpp
	$(CC) $(CFLAGS) games\src\Games.cpp -o obj\Games.o

obj\TicTacToe.o: games\src\TicTacToe.cpp games\header\TicTacToe.hpp
	$(CC) $(CFLAGS) games\src\TicTacToe.cpp -o obj\TicTacToe.o

### Info files are compiled from below

### Minor feature files are compiled from below

### Namespace files are compiled from below

obj\cod_algorithm.o: namespace\src\cod_algorithm.cpp namespace\header\cod_algorithm.hpp
	$(CC) $(CFLAGS) namespace\src\cod_algorithm.cpp -o obj\cod_algorithm.o
	
obj\cod_array.o: namespace\src\cod_array.cpp namespace\header\cod_array.hpp
	$(CC) $(CFLAGS) namespace\src\cod_array.cpp -o obj\cod_array.o

obj\cod_limits.o: namespace\src\cod_limits.cpp namespace\header\cod_limits.hpp
	$(CC) $(CFLAGS) namespace\src\cod_limits.cpp -o obj\cod_limits.o

obj\cod_pair.o: namespace\src\cod_pair.cpp namespace\header\cod_pair.hpp
	$(CC) $(CFLAGS) namespace\src\cod_pair.cpp -o obj\cod_pair.o

obj\cod_scan.o: namespace\src\cod_scan.cpp namespace\header\cod_scan.hpp
	$(CC) $(CFLAGS) namespace\src\cod_scan.cpp -o obj\cod_scan.o

obj\cod_string.o: namespace\src\cod_string.cpp namespace\header\cod_string.hpp
	$(CC) $(CFLAGS) namespace\src\cod_string.cpp -o obj\cod_string.o

### Common files are compiled from below

obj\Account.o: src\Account.cpp header\Account.hpp
	$(CC) $(CFLAGS) src\Account.cpp -o obj\Account.o

obj\AccountHandler.o: src\AccountHandler.cpp header\AccountHandler.hpp
	$(CC) $(CFLAGS) src\AccountHandler.cpp -o obj\AccountHandler.o

obj\AnimeHandler.o: src\AnimeHandler.cpp header\AnimeHandler.hpp
	$(CC) $(CFLAGS) src\AnimeHandler.cpp -o obj\AnimeHandler.o

obj\Constants.o: src\Constants.cpp header\Constants.hpp
	$(CC) $(CFLAGS) src\Constants.cpp -o obj\Constants.o

obj\CreateAccount.o: src\CreateAccount.cpp header\CreateAccount.hpp
	$(CC) $(CFLAGS) src\CreateAccount.cpp -o obj\CreateAccount.o

obj\ExHandler.o: src\ExHandler.cpp header\ExHandler.hpp
	$(CC) $(CFLAGS) src\ExHandler.cpp -o obj\ExHandler.o

obj\FileHandler.o: src\FileHandler.cpp header\FileHandler.hpp
	$(CC) $(CFLAGS) src\FileHandler.cpp -o obj\FileHandler.o

obj\Help.o: src\Help.cpp header\Help.hpp
	$(CC) $(CFLAGS) src\Help.cpp -o obj\Help.o

obj\Home.o: src\Home.cpp header\Home.hpp
	$(CC) $(CFLAGS) src\Home.cpp -o obj\Home.o

obj\Security.o: src\Security.cpp header\Security.hpp
	$(CC) $(CFLAGS) src\Security.cpp -o obj\Security.o

obj\Settings.o: src\Settings.cpp header\Settings.hpp
	$(CC) $(CFLAGS) src\Settings.cpp -o obj\Settings.o

obj\UIhandler.o: src\UIhandler.cpp header\UIhandler.hpp
	$(CC) $(CFLAGS) src\UIhandler.cpp -o obj\UIhandler.o

obj\iCoder.o: iCoder.cpp
	$(CC) $(CFLAGS) iCoder.cpp -o obj\iCoder.o

### Extras

clean:
	rm -f obj/*.o iCoder