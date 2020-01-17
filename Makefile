OBJS = iCoder.o Account.o AccountHandler.o Constants.o CreateAccount.o Home.o LoginAccount.o Settings.o UIhandler.o
OBJF = obj\iCoder.o obj\Account.o obj\AccountHandler.o obj\Constants.o obj\CreateAccount.o obj\Home.o obj\LoginAccount.o obj\Settings.o obj\UIhandler.o
CC = g++
LFLAG = -Wall
CFLAGS = -Wall -c

all: $(OBJS)
	$(CC) $(LFLAG) $(OBJF) -o iCoder.exe

iCoder.o: iCoder.cpp
	$(CC) $(CFLAGS) iCoder.cpp -o obj\iCoder.o

Account.o : src\Account.cpp header\Account.hpp
	$(CC) $(CFLAGS) src\Account.cpp -o obj\Account.o

AccountHandler.o: src\AccountHandler.cpp header\AccountHandler.hpp
	$(CC) $(CFLAGS) src\AccountHandler.cpp -o obj\AccountHandler.o

Constants.o: src\Constants.cpp header\iCoder.hpp
	$(CC) $(CFLAGS) src\Constants.cpp -o obj\Constants.o

CreateAccount.o: src\CreateAccount.cpp header\CreateAccount.hpp
	$(CC) $(CFLAGS) src\CreateAccount.cpp -o obj\CreateAccount.o

Home.o: src\Home.cpp header\Home.hpp
	$(CC) $(CFLAGS) src\Home.cpp -o obj\Home.o

LoginAccount.o: src\LoginAccount.cpp header\LoginAccount.hpp
	$(CC) $(CFLAGS) src\LoginAccount.cpp -o obj\LoginAccount.o

Settings.o: src\Settings.cpp header\Settings.hpp
	$(CC) $(CFLAGS) src\Settings.cpp -o obj\Settings.o

UIhandler.o: src\UIhandler.cpp header\UIhandler.hpp
	$(CC) $(CFLAGS) src\UIhandler.cpp -o obj\UIhandler.o

clean:
	\rm obj/*.o iCoder

tar:
	tar cfv iCoder.tar Makefile src/*.cpp header/*.hpp