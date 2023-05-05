readData.o: readData.cpp structure_define.h target.h
		g++ -pedantic-errors -std=c++11 -c readData.cpp

market.o: market.cpp target.h structure_define.h 
		g++ -pedantic-errors -std=c++11 -c market.cpp

business.o: business.cpp target.h structure_define.h 
		g++ -pedantic-errors -std=c++11 -c business.cpp

spend_money.o: spend_money.cpp target.h
		g++ -pedantic-errors -std=c++11 -c spend_money.cpp

startGame.o: startGame.cpp business.o market.o target.h readData.o spend_money.o
		g++ -pedantic-errors -std=c++11 -c startGame.cpp

talent.o: talent.cpp 
		g++ -pedantic-errors -std=c++11 -c talent.cpp

target: startGame.o target.h spend_money.o business.o market.o readData.o talent.o
		g++ -pedantic-errors -std=c++11 startGame.o business.o market.o readData.o spend_money.o talent.o -o target
		

clean:
		rm -f market.o business.o startGame.o readData.o spend_money.o talent.o target

.PHONY: clean
