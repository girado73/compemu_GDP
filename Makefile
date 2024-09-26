compemu:
	clang++ -include src/reader.h -c src/reader.cpp -o bin/reader.o -std=c++17 -Wall -Wextra
	clang++ -include src/comp.h -c src/comp.cpp -o bin/comp.o -std=c++17 -Wall -Wextra
	clang++ -c src/main.cpp -o bin/main.o -std=c++17 -Wall -Wextra
	clang++ -o bin/compemu bin/main.o bin/reader.o bin/comp.o -std=c++17 -Wall -Wextra

tests:
	clang++ -include src/reader.h -c src/reader.cpp -o bin/reader.o -std=c++17 -Wall -Wextra
	clang++ -include src/comp.h -c src/comp.cpp -o bin/comp.o -std=c++17 -Wall -Wextra
	clang++ -c src/test.cpp -o bin/test.o -std=c++17 -Wall -Wextra
	clang++ -o bin/tester bin/test.o bin/reader.o bin/comp.o -std=c++17 -Wall -Wextra

