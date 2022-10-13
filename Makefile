CC = gcc -g
CFLAGS = -W -Wall -Wextra
EXEC = main
SOURCES = $(wildcard *.c)
OBJETS = $(SOURCES:.c=.o)

$(EXEC) : $(OBJETS)
	@echo "\n==== Linking ===="
	$(CC) $(CFLAGS) -o $@ $^ -lm

%.o : %.c 
	@echo "\n---- Rule " $@ "----"
	$(CC) $(CFLAGS) -c $<  

clean :
    rm -f *.o
	rm -f *.out
	rm -r latex
	rm -r html

doc : 
	doxygen Doxyfile

archive :
	tar -cf TEISSANDIER_Alban__GOETZ_Arnaud.tar.gz *.c *.h Makefile *.txt README.md Doxyfile
	

