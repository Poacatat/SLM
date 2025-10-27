all: slm

slm: src/slm.cpp src/Generator.cpp src/Model.cpp
	g++ -o slm src/slm.cpp src/Generator.cpp src/Model.cpp