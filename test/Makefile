all:
	g++ core/*.cpp test.cpp -I ./include -c -fprofile-arcs -ftest-coverage 
	g++ *.o -lgcov -lgtest -lpthread -o test 
	
run:
	./test
	lcov -c -d . -o test.info --rc lcov_branch_coverage=1 
	genhtml -o result test.info 

clean:
	# rm test
	rm *.o
	rm *.gcno
	rm *.gcda 
	rm test.info 
	rm -r result 
	