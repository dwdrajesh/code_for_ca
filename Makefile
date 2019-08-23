CC=g++
CFLAGS=-I

all: csv_parse.cpp
	$(CC) -o csv_parse csv_parse.cpp -I ./rapidcsv.h
