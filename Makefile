all: iCoder.o AccountHandler.o Constants.o Home.o Settings.o UIhandler.o
	g++ obj\iCoder.o obj\AccountHandler.o obj\Constants.o obj\Home.o obj\Settings.o obj\UIhandler.o -o Test.exe

iCoder.o: iCoder.cpp
	g++ -c -Wall iCoder.cpp -o obj\iCoder.o

AccountHandler.o: src\AccountHandler.cpp
	g++ -c -Wall src\AccountHandler.cpp -o obj\AccountHandler.o

Constants.o: src\Constants.cpp
	g++ -c -Wall src\Constants.cpp -o obj\Constants.o

Home.o: src\Home.cpp
	g++ -c -Wall src\Home.cpp -o obj\Home.o

Settings.o: src\Settings.cpp
	g++ -c -Wall src\Settings.cpp -o obj\Settings.o

UIhandler.o: src\UIhandler.cpp
	g++ -c -Wall src\UIhandler.cpp -o obj\UIhandler.o