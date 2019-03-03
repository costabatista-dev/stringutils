all: install clean
install: compile libstringutil.so
	sudo cp -v libstringutil.so /usr/lib/
compile: header
	gcc -c lib/stringutil.c -o stringutil.o -fpic -Werror -Wall -O3
	gcc -shared stringutil.o -o libstringutil.so
header:
	sudo cp -v include/stringutil.h /usr/include/

uninstall:
	sudo rm -v /usr/include/stringutil.h
	sudo rm -v /usr/lib/libstringutil.so
clean:
	rm -v *.o *.so
