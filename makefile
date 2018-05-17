SOURCE = main.pc, source.h
OUTPUT = resultat
LIB = -lm -lSDl -lSDL_ttf
LDLIBS = -lecpg -lpq
OPT = -Wall
.SUFFIXES: .pc
.pc.c:
	proc main.pc

all: $(OUTPUT)

clean: $(OUTPUT)
	@rm $(OUTPUT)


$(OUTPUT): proc
	@clear
	@gcc -o resultat main.c -L$ORACLE_HOME/lib/ -L$ORACLE_HOME/lib/libclntsh.so -I$ORACLE_HOME/sdk/include
	@printf "\n"
	@printf "No errors, yeah !\n"

proc:
	proc main.pc
