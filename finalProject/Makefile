build:
	flex calc.l
	yacc -d calc.y
	gcc lex.yy.c y.tab.c -o sigma -lfl -lm  -lssl -lcrypto
clean:
	rm -f lex.yy.c y.tab.c sigma y.tab.h