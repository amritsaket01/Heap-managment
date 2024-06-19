all: addition.o driver.o multiplication.o subtraction.o storing.o initialize.o compare.o
	gcc addition.o driver.o multiplication.o subtraction.o storing.o initialize.o compare.o -o out


addition.o: addition.c
	gcc -c addition.c

multiplication.o: multiplication.c
	gcc -c multiplication.c

subtraction.o: subtraction.c
	gcc -c subtraction.c

driver.o: driver.c
	gcc -c driver.c

storing.o: storing.c
	gcc -c storing.c

initialize.o: initialize.c
	gcc -c initialize.c

compare.o: compare.c
	gcc -c compare.c