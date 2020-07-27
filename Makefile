OBJ_ANIME = #obj\AnimeHandler.o obj\LoadAnime.o obj\SignOutAnime.o
OBJ_CONST = obj\Core.o obj\enum.o obj\File.o obj\Menu.o
OBJ_DS = #obj\Array.o obj\DataStructure.o obj\String.o
OBJ_EXTRA = obj\Changelog.o obj\Extras.o obj\Updates.o
OBJ_GAMES= obj\Games.o obj\TicTacToe.o
OBJ_COD = obj\cod_exception.o obj\cod_limits.o obj\cod_scan.o #obj\cod_array.o obj\cod_string.o
OBJ_SET = obj\Settings.o
OBJ = obj\Account.o obj\AccountHandler.o obj\CreateAccount.o obj\FileHandler.o obj\IMenu.o obj\ISaveable.o obj\More.o obj\Security.o obj\Ui.o obj\iCoder.o
OBJ_RES = obj\icon.o
OBJ_FILES = obj/*.o
LIBS = -static
CC = g++
L_FLAG = -Wall
C_FLAGS = -Wall -c

### Build the Project

all: $(OBJ_ANIME) $(OBJ_CONST) $(OBJ_DS) $(OBJ_EXTRA) $(OBJ_GAMES) $(OBJ_COD) $(OBJ_SET) $(OBJ) $(OBJ_RES)
	$(CC) $(l_FLAG) $(OBJ_FILES) $(LIBS) -o iCoder

### Animation files are compiled from below

obj\AnimeHandler.o: animation\src\AnimeHandler.cpp animation\header\AnimeHandler.hpp
	$(CC) $(C_FLAGS) animation\src\AnimeHandler.cpp -o obj\AnimeHandler.o
	
obj\LoadAnime.o: animation\src\LoadAnime.cpp animation\header\LoadAnime.hpp
	$(CC) $(C_FLAGS) animation\src\LoadAnime.cpp -o obj\LoadAnime.o

obj\SignOutAnime.o: animation\src\SignOutAnime.cpp animation\header\SignOutAnime.hpp
	$(CC) $(C_FLAGS) animation\src\SignOutAnime.cpp -o obj\SignOutAnime.o

### Constant files are compiled below

obj\Core.o: constant\src\Core.cpp constant\Constants.hpp
	$(CC) $(C_FLAGS) constant\src\Core.cpp -o obj\Core.o

obj\enum.o: constant\src\enum.cpp constant\enum.hpp
	$(CC) $(C_FLAGS) constant\src\enum.cpp -o obj\enum.o

obj\File.o: constant\src\File.cpp constant\Constants.hpp
	$(CC) $(C_FLAGS) constant\src\File.cpp -o obj\File.o

obj\Menu.o: constant\src\Menu.cpp constant\Constants.hpp
	$(CC) $(C_FLAGS) constant\src\Menu.cpp -o obj\Menu.o

### Data Structure files are compiled from below

obj\Array.o: dsa\src\Array.cpp dsa\header\Array.hpp
	$(CC) $(C_FLAGS) dsa\src\Array.cpp -o obj\Array.o

obj\DataStructure.o: dsa\src\DataStructure.cpp dsa\header\DataStructure.hpp
	$(CC) $(C_FLAGS) dsa\src\DataStructure.cpp -o obj\DataStructure.o

obj\String.o: dsa\src\String.cpp dsa\header\String.hpp
	$(CC) $(C_FLAGS) dsa\src\String.cpp -o obj\String.o

### Extras file are compiled below

obj\Changelog.o: extras\src\Changelog.cpp extras\Extras.hpp
	$(CC) $(C_FLAGS) extras\src\Changelog.cpp -o obj\Changelog.o

obj\Extras.o: extras\src\Extras.cpp extras\Extras.hpp
	$(CC) $(C_FLAGS) extras\src\Extras.cpp -o obj\Extras.o

obj\Updates.o: extras\src\Updates.cpp extras\Extras.hpp
	$(CC) $(C_FLAGS) extras\src\Updates.cpp -o obj\Updates.o

### Game files are compiled from below

obj\Games.o: games\src\Games.cpp games\header\Games.hpp
	$(CC) $(C_FLAGS) games\src\Games.cpp -o obj\Games.o

obj\TicTacToe.o: games\src\TicTacToe.cpp games\header\TicTacToe.hpp
	$(CC) $(C_FLAGS) games\src\TicTacToe.cpp -o obj\TicTacToe.o

### Namespace files are compiled from below

obj\cod_array.o: namespace\src\cod_array.cpp namespace\header\cod_array.hpp
	$(CC) $(C_FLAGS) namespace\src\cod_array.cpp -o obj\cod_array.o

obj\cod_exception.o: namespace\src\cod_exception.cpp namespace\header\cod_exception.hpp
	$(CC) $(C_FLAGS) namespace\src\cod_exception.cpp -o obj\cod_exception.o

obj\cod_limits.o: namespace\src\cod_limits.cpp namespace\header\cod_limits.hpp
	$(CC) $(C_FLAGS) namespace\src\cod_limits.cpp -o obj\cod_limits.o

obj\cod_scan.o: namespace\src\cod_scan.cpp namespace\header\cod_scan.hpp
	$(CC) $(C_FLAGS) namespace\src\cod_scan.cpp -o obj\cod_scan.o

obj\cod_string.o: namespace\src\cod_string.cpp namespace\header\cod_string.hpp
	$(CC) $(C_FLAGS) namespace\src\cod_string.cpp -o obj\cod_string.o

# Settings files are compiled from below


obj\Settings.o: settings\src\Settings.cpp settings\header\Settings.hpp
	$(CC) $(C_FLAGS) settings\src\Settings.cpp -o obj\Settings.o


### Common files are compiled from below

obj\Account.o: src\Account.cpp header\Account.hpp
	$(CC) $(C_FLAGS) src\Account.cpp -o obj\Account.o

obj\AccountHandler.o: src\AccountHandler.cpp header\AccountHandler.hpp
	$(CC) $(C_FLAGS) src\AccountHandler.cpp -o obj\AccountHandler.o

obj\CreateAccount.o: src\CreateAccount.cpp header\CreateAccount.hpp
	$(CC) $(C_FLAGS) src\CreateAccount.cpp -o obj\CreateAccount.o

obj\FileHandler.o: src\FileHandler.cpp header\FileHandler.hpp
	$(CC) $(C_FLAGS) src\FileHandler.cpp -o obj\FileHandler.o

obj\IMenu.o: src\IMenu.cpp header\IMenu.hpp
	$(CC) $(C_FLAGS) src\IMenu.cpp -o obj\IMenu.o

obj\ISaveable.o: src\ISaveable.cpp header\ISaveable.hpp
	$(CC) $(C_FLAGS) src\ISaveable.cpp -o obj\ISaveable.o

obj\More.o: src\More.cpp header\More.hpp
	$(CC) $(C_FLAGS) src\More.cpp -o obj\More.o

obj\Security.o: src\Security.cpp header\Security.hpp
	$(CC) $(C_FLAGS) src\Security.cpp -o obj\Security.o

obj\Ui.o: src\Ui.cpp header\Ui.hpp
	$(CC) $(C_FLAGS) src\Ui.cpp -o obj\Ui.o

obj\iCoder.o: iCoder.cpp iCoder.hpp
	$(CC) $(C_FLAGS) iCoder.cpp -o obj\iCoder.o

### Other

obj\icon.o: resources.rc
	windres resources.rc -O coff -o obj\icon.o

clean:
	rm -f obj/*.o iCoder