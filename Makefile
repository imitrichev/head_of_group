all:
	g++ -std=c++20 main.cpp -o a.out -lgtest -pthread
clean:
	rm a.out