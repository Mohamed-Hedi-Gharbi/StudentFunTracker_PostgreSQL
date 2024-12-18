#* Déclaration des variables  
CC = gcc
CFLAGS = -Wall -Wextra -I/usr/include/postgresql -Iinclude
OBJS = build/main.o build/student.o build/utils.o build/file_operations.o build/database.o

#* Dossier pour les exécutables
BIN_DIR = bin

#* Règle principale pour créer l'exécutable  
$(BIN_DIR)/gestion_dossiers: $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/gestion_dossiers $(OBJS) -lpq -lconfig

#* Règle pour compiler les fichiers sources en objets 
build/%.o: src/%.c
	@mkdir -p build $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

#* Règle pour nettoyer les fichiers temporaires 
clean:
	rm -f build/*.o $(BIN_DIR)/gestion_dossiers
