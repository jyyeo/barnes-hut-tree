# g++ -Iinclude -c library/vector.cpp library/body.cpp library/tree.cpp library/main.cpp

# g++ vector.o body.o tree.o main.o

# ./a.out

objects = out/vector.o out/body.o out/tree.o

main: $(objects) library/main.cpp
	g++ -o main -Iinclude $(objects) library/main.cpp

out/vector.o: library/vector.cpp include/vector.h
	g++ -c -Iinclude library/vector.cpp -o out/vector.o

out/body.o: library/body.cpp include/body.h
	g++ -c -Iinclude library/body.cpp -o out/body.o

out/tree.o: library/tree.cpp include/tree.h
	g++ -c -Iinclude library/tree.cpp -o out/tree.o

# out/main.o: library/main.cpp out/vector.o out/body.o out/tree.o
# 	gcc -c -Iinclude library/main.cpp

clean:
	rm main $(objects)