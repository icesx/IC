-include output/subdir.mk
-include input/subdir.mk
-include calc/subdir.mk
all:main
objs:=main.o input/getdata.o calc/calc.o output/putdata.o
main:$(objs)
	gcc -o main $(objs)
%.o:%.c
	$(CC) -c $< -o $@
clean:
	rm *.o
	rm main
