all: slm

slm: slm.cpp
	g++ -Wall -o slm slm.cpp
