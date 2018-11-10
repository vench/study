BINARY := opengl

mdir:
	mkdir -p build

func: func.cpp 
	g++ -c -Wall func.cpp -o build/func.o
	
main:   mdir func 
	g++ main.cpp build/func.o -o build/$(BINARY) -lglut -lGLU -lGL
	 
        
clean:
	rm -f \
		build/func.o \
		build/$(BINARY) 
		        
        
all: main

run: main
	`bash ./build/opengl`
