input/%.o: ../input/%.c
%.o : %.c
	$(CC) -c $< -o $@
