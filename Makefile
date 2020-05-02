main : main.c schedule.o
	gcc $^ -o $@

clean : 
	rm *.o main
