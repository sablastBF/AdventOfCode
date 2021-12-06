CFLAGS = -std=c++17 

a.out: *.cpp 
	g++ $(CFLAGS) -L `pkg-config --cflags --libs opencv4` -o a.out *.cpp 


.PHONY: test clean

test: a.out
	./a.out

clean:
	rm -f a.out