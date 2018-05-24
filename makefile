SOURCE = main.pc
OUTPUT = resultat
LIB = -lm -lSDl -lSDL_ttf
LDLIBS = -lecpg -lpq
OPT = -Wall

all: $(OUTPUT)

clean: $(OUTPUT)
	@rm $(OUTPUT)


$(OUTPUT):
	@clear
	proc HEADER=fonctions INAME=main.pc
	@gcc -o resultat main.c -L$ORACLE_HOME/lib/ -L$ORACLE_HOME/lib/libclntsh.so -I$ORACLE_HOME/sdk/include
	@printf "\n"
	@printf "No errors, yeah !\n"
