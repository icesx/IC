objects = main.o getdata.o calc.o putdata.o 
main: $(objects)
	gcc ¨Co main $(objects)
main.o : main.c getdata.h putdata.h calc.h define.h
	gcc -c main.c
getdata.o : getdata.c getdata.h define.h
	gcc -c getdata.c
calc.o : calc.c calc.h
	gcc -c calc.c
putdata.o : putdata.c putdata.h
	gcc -c putdata.c
clean:
	rm *.o
	rm main
