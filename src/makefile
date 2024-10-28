files = main

filesToCompile = $(patsubst %,%.cpp,$(files))

main:
	g++ -g -std=c++98 ${filesToCompile} -o main

clean:
	rm *.o *.gcov *.gcda *.gcno *.gz *.html *.css output.txt coverage.txt -f ${files}