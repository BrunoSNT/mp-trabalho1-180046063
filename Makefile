CC=g++

romano: gtest_main.cc romano.cc testa_romano.cc
	$(CC) -std=c++11 -stdlib=libc++ gtest_main.cc romano.cc testa_romano.cc -lgtest -lpthread -o romano 