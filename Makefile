realeaseVersion = v1.2

prod:
	rm -f build/ranqo
	g++ -o build/ranqo-linux-${realeaseVersion} src/main.cpp

debug:
	rm -f build/ranqo
	g++ -o build/ranqo src/main.cpp
	ruby build/build-tools/test.rb