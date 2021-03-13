calc/%.o: ../calc/%.c
%.o : %.c
	$(CC) -c $< -o $@
