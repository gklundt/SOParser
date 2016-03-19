# Makefile for SOParser
obj = 	sop.o

sop:	${obj}
	g++ ${obj} -o SOParser

#Edge.o: Edge.h Edge.cpp
#	g++ -c -g Edge.cpp

#TGA.o:	TGA.h TGA.cpp
#	g++ -c -g TGA.cpp
	
sop.o:	main.cpp
	g++ -c -g main.cpp -o sop.o	

clean:
	rm -f *.o
	rm -f *~
	rm -f SOParser
