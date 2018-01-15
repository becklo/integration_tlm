CC=gcc
INCLUDE=-I. -I../..
CFLAGS=$(INCLUDE)

main.o: ../main.c hal.h ../../address_map.h
		$(CC) -o $@ -c ../main.c $(CFLAGS)

.PHONY: clean realclean
clean:
	$(RM) main.o

realclean: clean
	-$(RM) *~
