OBJS = iCoder.o Account.o AccountHandler.o Constants.o CreateAccount.o Home.o Recursion.o Settings.o UIhandler.o
OBJCOD = cod_recursion.o
OBJF = obj/*.o
CC = g++
LFLAG = -Wall
CFLAGS = -Wall -c

### Build the Project

all: $(OBJS) $(OBJCOD)
	$(CC) $(LFLAG) $(OBJF) -o iCoder.exe

### Common program files

iCoder.o: iCoder.cpp
	$(CC) $(CFLAGS) iCoder.cpp -o obj\iCoder.o

Account.o : src\Account.cpp header\Account.hpp
	$(CC) $(CFLAGS) src\Account.cpp -o obj\Account.o

AccountHandler.o: src\AccountHandler.cpp header\AccountHandler.hpp
	$(CC) $(CFLAGS) src\AccountHandler.cpp -o obj\AccountHandler.o

Constants.o: src\Constants.cpp header\Constants.hpp
	$(CC) $(CFLAGS) src\Constants.cpp -o obj\Constants.o

CreateAccount.o: src\CreateAccount.cpp header\CreateAccount.hpp
	$(CC) $(CFLAGS) src\CreateAccount.cpp -o obj\CreateAccount.o

Home.o: src\Home.cpp header\Home.hpp
	$(CC) $(CFLAGS) src\Home.cpp -o obj\Home.o

Recursion.o: src\Recursion.cpp header\Recursion.hpp
	$(CC) $(CFLAGS) src\Recursion.cpp -o obj\Recursion.o


Settings.o: src\Settings.cpp header\Settings.hpp
	$(CC) $(CFLAGS) src\Settings.cpp -o obj\Settings.o

UIhandler.o: src\UIhandler.cpp header\UIhandler.hpp
	$(CC) $(CFLAGS) src\UIhandler.cpp -o obj\UIhandler.o

### Namespace files are compiled from below

cod_recursion.o: namespace\src\cod_recursion.cpp namespace\header\cod_recursion.hpp
	$(CC) $(CFLAGS) namespace\src\cod_recursion.cpp -o obj\cod_recursion.o

### Extras
clean:
	\rm -f obj/*.o iCoder

tar:
	tar cfv iCoder.tar Makefile src/*.cpp header/*.hpp