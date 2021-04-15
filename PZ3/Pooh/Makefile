all: pooh

pooh: pooh.o flying_bear.o bear.o engine.o pid.o
	g++ pooh.o flying_bear.o bear.o engine.o pid.o -o pooh

pooh.o: pooh.cpp 
	g++ -c pooh.cpp

flying_bear.o: flying_bear.cpp 
	g++ -c flying_bear.cpp

bear.o: bear.cpp 
	g++ -c bear.cpp

engine.o: engine.cpp 
	g++ -c engine.cpp

pid.o: pid.cpp 
	g++ -c pid.cpp

clean:
	rm *.o
	rm pooh

