all:
	g++ src/main.cpp src/Game.cpp src/Pet.cpp -o sfml-app -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -std=gnu++11
