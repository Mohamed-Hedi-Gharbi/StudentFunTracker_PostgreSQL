cc = gcc
CFLAGS = -Wall -Wextra
OBJS = main.o student.o utils.o file_operations.c


gestion_dossiers: $(OBJS)
	$(CC) $(CFLAGS) -o gestion_dossiers $(OBJS)


%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o gestion_dossiers
