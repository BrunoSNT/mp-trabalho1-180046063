CC=g++

romano: romano.cpp testa_romano.cpp
	$(CC) -std=c++11 -stdlib=libc++ romano.cpp testa_romano.cpp -o romano -lgtest -lpthread -I /usr/local/include