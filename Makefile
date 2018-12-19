BINARY := opengl

mdir:
	mkdir -p build

func: func.cpp 
	g++ -std=c++11 -c -Wall func.cpp -o build/func.o
	
main:   mdir func 
	g++ -std=c++11 main.cpp build/func.o -o build/$(BINARY)
	 
        
clean:
	rm -f \
		build/func.o \
		build/$(BINARY) 
		        
        
all: main

run: main
	`bash ./build/opengl`
