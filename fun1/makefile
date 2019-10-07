dailywork:main.o func.o func2.o
	gcc main.o func.o func2.o -o work1
main.o:main.c
	gcc main.c -c
func.o:func.c
	gcc func.c -c
func2.o:func2.c
	gcc func2.c -c
clean:
	rm -f *.o
