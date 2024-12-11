#* Déclaration des variables  
CC = gcc
CFLAGS = -Wall -Wextra -I/usr/include/postgresql -I./include

#* Dossier des fichiers objets compilés
OBJDIR = build

#* Liste des fichiers objets
OBJS = $(OBJDIR)/main.o $(OBJDIR)/student.o $(OBJDIR)/utils.o $(OBJDIR)/file_operations.o

#* Règle principale pour créer l'exécutable  
gestion_dossiers: $(OBJS)
	$(CC) $(CFLAGS) -o gestion_dossiers $(OBJS) -lpq  

#* Règle pour compiler les fichiers sources en objets 
$(OBJDIR)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

#* Règle pour nettoyer les fichiers temporaires 
clean:
	rm -f $(OBJDIR)/*.o gestion_dossiers
