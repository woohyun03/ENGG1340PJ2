FLAGS = -pedantic-errors -std=c++11

Map.o: Map.cpp Map.h Station.h MapChartDisplay.h
	g++ -c $<

MapChartDisplay.o: MapChartDisplay.cpp MapChartDisplay.h
	g++ -c $<

Player.o: Player.cpp Player.h
	g++ -c $<

Functions.o: Functions.cpp Functions.h Map.h Player.h Station.h
	g++ -c $<

main.o: main.cpp Functions.h Map.h Player.h Station.h Mal.h
	g++ -c $<

game: main.o Functions.o Player.o MapChartDisplay.o Map.o
	g++ $^ -o $@

clean:
	rm -f game main.o Functions.o Player.o MapChartDisplay.o Map.o

tar:
	tar -czvf game.tgz *.cpp *.h

.PHONY: clean tar
