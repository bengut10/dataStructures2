a4s2: sequenceTest.o 
	g++ sequenceTest.o -o a4s2
sequenceTest.o: sequenceTest.cpp sequence.template sequence.h
	g++ -Wall -ansi -pedantic -c sequenceTest.cpp

test:
	./a4s2 auto < a4test.in > a4test.out
clean:
	@rm -rf sequenceTest.o
cleanall:
	@rm -rf sequenceTest.o a4s2 


                                                              
