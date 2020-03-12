OBJS = obj\iCoder.o obj\Account.o obj\AccountHandler.o obj\Array.o obj\Constants.o obj\CreateAccount.o obj\ExHandler.o obj\Home.o obj\Info.o obj\Scanner.o obj\Settings.o obj\UIhandler.o
OBJCOD = obj\cod_algorithm.o obj\cod_array.o obj\cod_limits.o obj\cod_pair.o
OBJF = obj/*.o
CC = g++
LFLAG = -Wall
CFLAGS = -Wall -c

### Build the Project

all: $(OBJS) $(OBJCOD)
	$(CC) $(LFLAG) $(OBJF) -o iCoder.exe

### Common program files

obj\iCoder.o: iCoder.cpp
	$(CC) $(CFLAGS) iCoder.cpp -o obj\iCoder.o

obj\Account.o: src\Account.cpp header\Account.hpp
	$(CC) $(CFLAGS) src\Account.cpp -o obj\Account.o

obj\AccountHandler.o: src\AccountHandler.cpp header\AccountHandler.hpp
	$(CC) $(CFLAGS) src\AccountHandler.cpp -o obj\AccountHandler.o

obj\Constants.o: src\Constants.cpp header\Constants.hpp
	$(CC) $(CFLAGS) src\Constants.cpp -o obj\Constants.o

obj\CreateAccount.o: src\CreateAccount.cpp header\CreateAccount.hpp
	$(CC) $(CFLAGS) src\CreateAccount.cpp -o obj\CreateAccount.o

obj\ExHandler.o: src\ExHandler.cpp header\ExHandler.hpp
	$(CC) $(CFLAGS) src\ExHandler.cpp -o obj\ExHandler.o

obj\Home.o: src\Home.cpp header\Home.hpp
	$(CC) $(CFLAGS) src\Home.cpp -o obj\Home.o

obj\Info.o: src\Info.cpp header\Info.hpp
	$(CC) $(CFLAGS) src\Info.cpp -o obj\Info.o

obj\Scanner.o: src\Scanner.cpp header\Scanner.hpp
	$(CC) $(CFLAGS) src\Scanner.cpp -o obj\Scanner.o

obj\Array.o: src\Array.cpp header\Array.hpp
	$(CC) $(CFLAGS) src\Array.cpp -o obj\Array.o

obj\Settings.o: src\Settings.cpp header\Settings.hpp
	$(CC) $(CFLAGS) src\Settings.cpp -o obj\Settings.o

obj\UIhandler.o: src\UIhandler.cpp header\UIhandler.hpp
	$(CC) $(CFLAGS) src\UIhandler.cpp -o obj\UIhandler.o

### Namespace files are compiled from below

obj\cod_algorithm.o: namespace\src\cod_algorithm.cpp namespace\header\cod_algorithm.hpp
	$(CC) $(CFLAGS) namespace\src\cod_algorithm.cpp -o obj\cod_algorithm.o
	
obj\cod_array.o: namespace\src\cod_array.cpp namespace\header\cod_array.hpp
	$(CC) $(CFLAGS) namespace\src\cod_array.cpp -o obj\cod_array.o

obj\cod_limits.o: namespace\src\cod_limits.cpp namespace\header\cod_limits.hpp
	$(CC) $(CFLAGS) namespace\src\cod_limits.cpp -o obj\cod_limits.o

obj\cod_pair.o: namespace\src\cod_pair.cpp namespace\header\cod_pair.hpp
	$(CC) $(CFLAGS) namespace\src\cod_pair.cpp -o obj\cod_pair.o

### Extras

clean:
	rm -f obj/*.o iCoder