OBJ_ACC = obj\Account.o obj\AccountHandler.o obj\CreateAccount.o 
OBJ_ANIME = #obj\AnimeHandler.o obj\LoadAnime.o obj\SignOutAnime.o
OBJ_BASE = obj\AbstractMenu.o obj\AbstractSaveable.o obj\FileData.o
OBJ_CONST = obj\ConstCore.o obj\ConstFile.o obj\ConstMenu.o
OBJ_DS = #obj\Array.o obj\DataStructure.o obj\String.o
OBJ_EXCEPT = obj\Exception.o obj\Start.o
OBJ_EXTRA = obj\Changelog.o obj\Extras.o obj\Updates.o
OBJ_GAMES = obj\Games.o obj\TicTacToe.o
OBJ_MAIN = obj\File.o obj\iCoder.o obj\More.o obj\Security.o obj\Ui.o
OBJ_COD = obj\cod_limits.o obj\cod_scan.o #obj\cod_array.o obj\cod_string.o
OBJ_SET = obj\Settings.o #obj\Hints.o
OBJ_RES = obj\icon.o
OBJ_FILES = obj/*.o
LIBS = -static
CC = g++
L_FLAG = -Wall
C_FLAGS = -Wall -c

### Build the Project

all: $(OBJ_ACC) $(OBJ_ANIME) $(OBJ_BASE) $(OBJ_CONST) $(OBJ_DS) $(OBJ_EXCEPT) $(OBJ_EXTRA) $(OBJ_GAMES) $(OBJ_MAIN) $(OBJ_COD) $(OBJ_SET) $(OBJ_RES)
	$(CC) $(l_FLAG) $(OBJ_FILES) $(LIBS) -o iCoder

### Account files are compiled from below

obj\Account.o: account\src\Account.cpp account\header\Account.hpp
	$(CC) $(C_FLAGS) account\src\Account.cpp -o obj\Account.o

obj\AccountHandler.o: account\src\AccountHandler.cpp account\header\AccountHandler.hpp
	$(CC) $(C_FLAGS) account\src\AccountHandler.cpp -o obj\AccountHandler.o

obj\CreateAccount.o: account\src\CreateAccount.cpp account\header\CreateAccount.hpp
	$(CC) $(C_FLAGS) account\src\CreateAccount.cpp -o obj\CreateAccount.o

### Animation files are compiled from below

obj\AnimeHandler.o: animation\src\AnimeHandler.cpp animation\header\AnimeHandler.hpp
	$(CC) $(C_FLAGS) animation\src\AnimeHandler.cpp -o obj\AnimeHandler.o
	
obj\LoadAnime.o: animation\src\LoadAnime.cpp animation\header\LoadAnime.hpp
	$(CC) $(C_FLAGS) animation\src\LoadAnime.cpp -o obj\LoadAnime.o

obj\SignOutAnime.o: animation\src\SignOutAnime.cpp animation\header\SignOutAnime.hpp
	$(CC) $(C_FLAGS) animation\src\SignOutAnime.cpp -o obj\SignOutAnime.o

# Base files are compiled below

obj\AbstractMenu.o: base\src\AbstractMenu.cpp base\header\AbstractMenu.hpp
	$(CC) $(C_FLAGS) base\src\AbstractMenu.cpp -o obj\AbstractMenu.o

obj\AbstractSaveable.o: base\src\AbstractSaveable.cpp base\header\AbstractSaveable.hpp
	$(CC) $(C_FLAGS) base\src\AbstractSaveable.cpp -o obj\AbstractSaveable.o

obj\FileData.o: base\src\FileData.cpp base\header\FileData.hpp
	$(CC) $(C_FLAGS) base\src\FileData.cpp -o obj\FileData.o

### Constant files are compiled below

obj\ConstCore.o: constant\src\ConstCore.cpp constant\Constants.hpp
	$(CC) $(C_FLAGS) constant\src\ConstCore.cpp -o obj\ConstCore.o

obj\ConstFile.o: constant\src\ConstFile.cpp constant\Constants.hpp
	$(CC) $(C_FLAGS) constant\src\ConstFile.cpp -o obj\ConstFile.o

obj\ConstMenu.o: constant\src\ConstMenu.cpp constant\Constants.hpp
	$(CC) $(C_FLAGS) constant\src\ConstMenu.cpp -o obj\ConstMenu.o

### Data Structure files are compiled from below

obj\Array.o: dsa\src\Array.cpp dsa\header\Array.hpp
	$(CC) $(C_FLAGS) dsa\src\Array.cpp -o obj\Array.o

obj\DataStructure.o: dsa\src\DataStructure.cpp dsa\header\DataStructure.hpp
	$(CC) $(C_FLAGS) dsa\src\DataStructure.cpp -o obj\DataStructure.o

obj\String.o: dsa\src\String.cpp dsa\header\String.hpp
	$(CC) $(C_FLAGS) dsa\src\String.cpp -o obj\String.o

### Exception files are compiled from below

obj\Exception.o: exception\src\Exception.cpp exception\header\Exception.hpp
	$(CC) $(C_FLAGS) exception\src\Exception.cpp -o obj\Exception.o

obj\Start.o: exception\src\Start.cpp exception\header\Start.hpp
	$(CC) $(C_FLAGS) exception\src\Start.cpp -o obj\Start.o

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

### Main files are compiled from below

obj\File.o: main\src\File.cpp main\header\File.hpp
	$(CC) $(C_FLAGS) main\src\File.cpp -o obj\File.o

obj\iCoder.o: main\src\iCoder.cpp main\header\iCoder.hpp
	$(CC) $(C_FLAGS) main\src\iCoder.cpp -o obj\iCoder.o

obj\More.o: main\src\More.cpp main\header\More.hpp
	$(CC) $(C_FLAGS) main\src\More.cpp -o obj\More.o

obj\Security.o: main\src\Security.cpp main\header\Security.hpp
	$(CC) $(C_FLAGS) main\src\Security.cpp -o obj\Security.o

obj\Ui.o: main\src\Ui.cpp main\header\Ui.hpp
	$(CC) $(C_FLAGS) main\src\Ui.cpp -o obj\Ui.o

### Namespace files are compiled from below

obj\cod_array.o: namespace\src\cod_array.cpp namespace\header\cod_array.hpp
	$(CC) $(C_FLAGS) namespace\src\cod_array.cpp -o obj\cod_array.o

obj\cod_limits.o: namespace\src\cod_limits.cpp namespace\header\cod_limits.hpp
	$(CC) $(C_FLAGS) namespace\src\cod_limits.cpp -o obj\cod_limits.o

obj\cod_scan.o: namespace\src\cod_scan.cpp namespace\header\cod_scan.hpp
	$(CC) $(C_FLAGS) namespace\src\cod_scan.cpp -o obj\cod_scan.o

obj\cod_string.o: namespace\src\cod_string.cpp namespace\header\cod_string.hpp
	$(CC) $(C_FLAGS) namespace\src\cod_string.cpp -o obj\cod_string.o

# Settings files are compiled from below

obj\Hints.o: settings\src\Hints.cpp settings\header\Hints.hpp
	$(CC) $(C_FLAGS) settings\src\Hints.cpp -o obj\Hints.o

obj\Settings.o: settings\src\Settings.cpp settings\header\Settings.hpp
	$(CC) $(C_FLAGS) settings\src\Settings.cpp -o obj\Settings.o

### Other

obj\icon.o: resources\resources.rc
	windres resources\resources.rc -O coff -o obj\icon.o

clean:
	rm -f obj/*.o iCoder.exe