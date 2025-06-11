all: 
	main

main:
	g++ -o build/ranqo src/main.cpp

clean:
	rm -f build/ranqo	
