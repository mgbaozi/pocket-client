libs = liblodepng.a

all: $(libs)

liblodepng.a: lodepng.o
	ar rcs liblodepng.a lodepng.o

lodepng.o: lodepng.cc
	g++ -c lodepng.cc $(CXXFLAGS) -o lodepng.o

.PHONY: clean
clean:
	rm -f *.o
	rm -f *.a
