yacc -d parser.y -o parser.tab.c
flex -o scanner.yy.c scanner.l
gcc scanner.yy.c parser.tab.c -o exam.out -ll

./exam.out
