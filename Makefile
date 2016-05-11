
all: main.cpp
	g++ -o a.out -O3 main.cpp
clean:
	$(RM) ./a.out*
