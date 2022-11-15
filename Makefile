CC = gcc -g
CFLAGS = -W -Wall -Wextra
EXEC = main
SOURCES = $(wildcard *.c)
OBJETS = $(SOURCES:.c=.o)
LDFLAGS = -lm

$(EXEC) : $(OBJETS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o : %.c 
	$(CC) $(CFLAGS) -c $<  

clean :
	rm -f *.o
	rm -f *.out
	
clean_doc :
	rm -rf latex
	rm -rf html

clean_sdl_config :
	rm -rf install_dir

full_clean :
	$(MAKE) clean
	$(MAKE) clean_doc
	$(MAKE) clean_sdl_config

doc : 
	rm -f *.bak
	doxygen Doxyfile

sdl_config :
	if [ ! -e "install_dir" ]; then \
		cd SDL2/; \
		./configure --prefix=$$PWD/../install_dir; \
		make install -j6; \
		cd ..; \
	fi

archive :
	tar -cf TEISSANDIER_Alban__GOETZ_Arnaud.tar.gz *.c *.h Makefile *.txt README.md Doxyfile
	

