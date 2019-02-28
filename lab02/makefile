CC := gcc

CFLAGS := -std=c99 -Wall -Werror

OBJ := proc.o io.o

app.exe : $(OBJ) main.o
	$(CC) $^ -o app.exe
	
%.o : %.c *.h
	$(CC) $(CFLAGS) -c $<
	
clean :
	$(RM) *.exe *.o