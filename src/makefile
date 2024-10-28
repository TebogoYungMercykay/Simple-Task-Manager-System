main:
	g++ -g *.cpp -std=c++98 -pedantic -o main

clean:
	rm -f *.o *.gcov *.gcda *.gcno *.gz *.html main *.css output.txt coverage.txt
	reset
	clear

run:
	valgrind --leak-check=full ./main

tar:
	tar -cvz *.* -f Code.tar.gz

untar:
	tar -zxvf *.tar.gz
