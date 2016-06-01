all:
	g++ main.cpp Game.cpp Pet.cpp -o sfml-app -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -std=gnu++11
