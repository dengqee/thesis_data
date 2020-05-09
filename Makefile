GCC = g++
CFLAGS = -g -std=c++11
FILES = Cal_real.out flow_cut.out transform.out

all: $(FILES)

Cal_real.out: Cal_real.cpp
	$(GCC) $(CFLAGS) $^ -o Cal_real.out 

flow_cut.out: flow_cut.cpp
	$(GCC) $(CFLAGS) $^ -o flow_cut.out 
	
transform.out: transform.cpp
	$(GCC) $(CFLAGS) $^ -o transform.out 

clean:
	rm -f *.o *.out
