# g++ -Iinclude -c library/vector.cpp library/body.cpp library/tree.cpp library/main.cpp

# g++ vector.o body.o tree.o main.o

# ./a.out
CC = g++

objects = out/vector.o out/body.o out/tree.o

main: $(objects) library/main.cpp
	$(CC) -o main -Iinclude $(objects) library/main.cpp

out/vector.o: library/vector.cpp include/vector.h
	$(CC) -c -Iinclude library/vector.cpp -o out/vector.o

out/body.o: library/body.cpp include/body.h
	$(CC) -c -Iinclude library/body.cpp -o out/body.o

out/tree.o: library/tree.cpp include/tree.h
	$(CC) -c -Iinclude library/tree.cpp -o out/tree.o

# out/main.o: library/main.cpp out/vector.o out/body.o out/tree.o
# 	gcc -c -Iinclude library/main.cpp

clean:
	rm main $(objects)