# Makefile for SOParser
obj = 	Processor.o \
	InputProcessor.o \
	MapReader.o \
	OutputProcessor.o \
	CircularShiftProcessor.o \
	SortProcessor.o \
	sop.o 

# Data.o \
# Word.o \
# Comparator.o \
# 
# StreamAdapter.o \


sop:	${obj}
	g++ ${obj} -o SOParser
	rm -f *.o

CircularShiftProcessor.o:	CircularShiftProcessor.h CircularShiftProcessor.cpp Processor.h Word.h Data.h
	g++ -c -g CircularShiftProcessor.cpp

InputProcessor.o:	InputProcessor.h InputProcessor.cpp Processor.h Word.h Data.h
	g++ -c -g InputProcessor.cpp

MapReader.o:	MapReader.h MapReader.cpp Word.h  Data.h
	g++ -c -g MapReader.cpp

OutputProcessor.o:	OutputProcessor.h OutputProcessor.cpp
	g++ -c -g OutputProcessor.cpp

SortProcessor.o:	SortProcessor.h SortProcessor.cpp Comparator.h Processor.h Word.h  Data.h
	g++ -c -g SortProcessor.cpp

sop.o:	main.cpp StreamAdapter.h Word.h  Data.h
	g++ -c -g main.cpp -o sop.o	

#Data.o:	Data.h Word.h
#	g++ -c -g Data.h

#Word.o:	Word.h 
#	g++ -c -g Word.h
	
#Comparator.o:	Comparator.h 
#	g++ -c -g Comparator.h

Processor.o:	Processor.h Processor.cpp
	g++ -c -g Processor.cpp

#StreamAdapter.o:	StreamAdapter.h 
#	g++ -c -g StreamAdapter.h



clean:
	rm -f *.o
	rm -f *~
	rm -f *.gch
	rm -f SOParser


