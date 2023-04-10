# Trabalho Algoritmos
## Para compilar o programa no gcc:
### 1. gcc -c function_atleta.c -o function_atleta.o
### 2. ar rcs libatleta.a function_atleta.o 
### 3. gcc carta_atleta.c -o atleta -I./lib -L./lib -latleta
