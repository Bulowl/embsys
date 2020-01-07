SONAME = libhook.so
GCC = gcc

all:
	$(GCC) -c -fPIC hook.c -o hook.o
	$(GCC) -shared -Wl,-soname,$(SONAME) -o $(SONAME) hook.o -lm

clean:
	rm -f *.so *.o
