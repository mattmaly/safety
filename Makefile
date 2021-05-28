default:
	g++ -I./src/ -O3 -Wall src/*.cpp src/safety/*.cpp src/safety/formulas/*.cpp -o main
clean:
	rm main
