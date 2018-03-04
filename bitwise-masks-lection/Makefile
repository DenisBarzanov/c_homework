FLAGS=-Wall -pedantic -std=c11
DEPS=sum.h
OBJS=exercise.o sum.o
EXE=exe.out
it: $(OBJS) $(DEPS)
	gcc $(FLAGS) exercise.o sum.o -o $(EXE)
exercise.o: exercise.c
	gcc -c $(FLAGS) exercise.c
sum.o: sum.c
	gcc -c $(FLAG) sum.c
clean:
	rm -f $(OBJS) $(EXE)

