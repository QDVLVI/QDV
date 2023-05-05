readData.o: readData.cpp structure_define.h target.h
		g++ -pedantic-errors -std=c++11 -c readData.cpp


market.o: market.cpp target.h structure_define.h
		g++ -pedantic-errors -std=c++11 -c market.cpp

business.o: business.cpp target.h structure_define.h
		g++ -pedantic-errors -std=c++11 -c business.cpp

startGame.o: startGame.cpp business.o market.o target.h readData.o
		g++ -pedantic-errors -std=c++11 -c startGame.cpp

interface: startGame.o target.h
		g++ -pedantic-errors -std=c++11 startGame.o business.o market.o readData.o -o target

clean:
		rm -f market.o business.o startGame.o target

.PHONY: clean
