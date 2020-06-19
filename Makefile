# g++ -Iinclude -c library/vector.cpp library/body.cpp library/tree.cpp library/main.cpp

# g++ vector.o body.o tree.o main.o

# ./a.out

objects = out/vector.o out/body.o out/tree.o

main: $(objects) library/main.cpp
	gcc -o main $(objects)

out/vector.o: library/vector.cpp include/vector.h
	gcc -c -Iinclude library/vector.cpp

out/body.o: library/body.cpp include/body.h
	gcc -c -Iinclude library/body.cpp

out/tree.o: library/tree.cpp include/tree.h
	gcc -c -Iinclude library/tree.cpp

# out/main.o: library/main.cpp out/vector.o out/body.o out/tree.o
# 	gcc -c -Iinclude library/main.cpp

clean:
	rm main $(objects)