all: Lexer_Parser

Lexer_Parser: problem_st.o problem_lx.o problem_st_main.o
	gcc problem_st_main.o problem_lx.o problem_st.o -o Lexer_Parser

problem_st_main.o: problem_st_main.c
	gcc -c problem_st_main.c -g

problem_st.o: problem_st.c
	gcc -c problem_st.c -g

problem_lx.o: problem_lx.c
	gcc -c problem_lx.c -g

clean:
	rm -rf *.o 
