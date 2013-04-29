default:
	g++ -I./src/ -O3 -Wall src/*.cpp src/safety/src/*.cpp src/safety/formulas/src/*.cpp -o main
clean:
	rm main
