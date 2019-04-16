CC=g++

romano: gtest_main.cpp romano.cpp testa_romano.cpp
	$(CC) -std=c++11 -stdlib=libc++ gtest_main.cpp romano.cpp testa_romano.cpp -lgtest -lpthread -o romano 