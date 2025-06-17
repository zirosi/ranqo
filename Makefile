prod:
	rm -f build/ranqo
	g++ -o build/ranqo-linux-v1.2 src/main.cpp

debug:
	rm -f build/ranqo
	g++ -o build/ranqo src/main.cpp
	ruby build/build-tools/test.rb