#adapted from: GNU make - An Introduction to Makefiles, found in the 
#Make help page under the Resources module of CS 162 

CXXFLAGS = -std=c++0x
CXXFLAGS += -g
CXXFLAGS += -Wall

OBJS = main.o  getLimitedInteger.o Overbaked.o Space.o Refrigerator.o mainMenu.o Pantry.o Bowl.o StandMixer.o Oven.o Dish.o Window.o Trash.o
HDRS = getLimitedInteger.hpp Overbaked.hpp Space.hpp Refrigerator.hpp mainMenu.hpp Pantry.hpp Bowl.hpp StandMixer.hpp Oven.hpp Dish.hpp Window.hpp Trash.hpp ingredients.hpp spaceType.hpp

final: $(OBJS) $(HDRS)
	g++ $(CXXFLAGS) $(OBJS) -o final

main.o:	main.cpp 
	g++ $(CXXFLAGS) -c main.cpp

getLimitedInteger.o:	getLimitedInteger.cpp getLimitedInteger.hpp
	g++ $(CXXFLAGS) -c getLimitedInteger.cpp 

Overbaked.o:	Overbaked.cpp Overbaked.hpp ingredients.hpp spaceType.hpp
	g++ $(CXXFLAGS) -c Overbaked.cpp

Space.o:	Space.cpp Space.hpp ingredients.hpp spaceType.hpp
	g++ $(CXXFLAGS) -c Space.cpp

Refrigerator.o:	Refrigerator.cpp Refrigerator.hpp ingredients.hpp spaceType.hpp
	g++ $(CXXFLAGS) -c Refrigerator.cpp

mainMenu.o:	mainMenu.cpp mainMenu.hpp ingredients.hpp spaceType.hpp
	g++ $(CXXFLAGS) -c mainMenu.cpp

Pantry.o:	Pantry.cpp Pantry.hpp ingredients.hpp spaceType.hpp
	g++ $(CXXFLAGS) -c Pantry.cpp

Bowl.o:	Bowl.cpp Bowl.hpp ingredients.hpp spaceType.hpp
	g++ $(CXXFLAGS) -c Bowl.cpp

StandMixer.o:	StandMixer.cpp StandMixer.hpp ingredients.hpp spaceType.hpp
	g++ $(CXXFLAGS) -c StandMixer.cpp

Oven.o:	Oven.cpp Oven.hpp ingredients.hpp spaceType.hpp
	g++ $(CXXFLAGS) -c Oven.cpp

Dish.o:	Dish.cpp Dish.hpp ingredients.hpp spaceType.hpp
	g++ $(CXXFLAGS) -c Dish.cpp

Window.o:	Window.cpp Window.hpp ingredients.hpp spaceType.hpp
	g++ $(CXXFLAGS) -c Window.cpp

Trash.o:	Trash.cpp Trash.hpp ingredients.hpp spaceType.hpp
	g++ $(CXXFLAGS) -c Trash.cpp

.PHONY: clean

clean:
	-rm *.o final
