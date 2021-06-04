default:
	g++ -std=c++20 -I./src/ -O3 -Wall src/*.cpp src/safety/*.cpp src/safety/formulas/*.cpp -o main
debug:
	g++ -std=c++20 -I./src/ -g -Wall src/*.cpp src/safety/*.cpp src/safety/formulas/*.cpp -o main
test:
	g++ -std=c++20 -I./src/ -Wall src/safety/*.cpp src/safety/formulas/*.cpp testing/safety-tests.cpp -o test
	./test
clean:
	rm -f main test
