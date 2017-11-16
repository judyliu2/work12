tester: fork.o
	@gcc fork.o -o tester

fork.o: fork.c
	@gcc -c fork.c

run: tester
	@./tester

clean:
	@rm *.o
	@rm *~
