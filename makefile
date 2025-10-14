all: slm run

slm: slm.cpp
	g++ -Wall -o slm slm.cpp
	
	
run: slm
	./slm
