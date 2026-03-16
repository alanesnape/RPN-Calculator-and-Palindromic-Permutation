CC=	gcc
CFLAGS=	-Wall -std=gnu99 -g
LD=	gcc
LDFLAGS=


#--------- Do not modify anything above this line -----------------

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

unit_array:	unit_array.o array.o
	$(LD) $(LDFLAGS) -o $@ $^

unit_stack:	unit_stack.o array.o stack.o
	$(LD) $(LDFLAGS) -o $@ $^

unit_set: unit_set.o array.o set.o
	$(LD) $(LDFLAGS) -o $@ $^

rpn: rpn.o array.o stack.o
	$(LD) $(LDFLAGS) -o $@ $^

palindromic: palindromic.o array.o set.o
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -f rpn palindromic unit_array unit_stack unit_set *.o
