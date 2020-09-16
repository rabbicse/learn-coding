encrypt_string.o: encrypt_string.c encrypt.h
	gcc -c encrypt_string.c

encrypt.o: encrypt.c encrypt.h
	gcc -c encrypt.c

launch: encrypt_string.o encrypt.o
	gcc encrypt_string.o encrypt.o -o launch
