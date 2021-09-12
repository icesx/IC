output/%.o: ../output/%.c
%.o : %.c
	$(CC) -c $< -o $@
