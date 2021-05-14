rm a.exe
make fclean
make
gcc -o a.exe main.c -L. -lftprintf
./a.exe
