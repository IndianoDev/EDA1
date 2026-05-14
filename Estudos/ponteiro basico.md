int *p; // ponteiro para inteiro
float *q;   // ponteiro para float
char *r; // ponteiro para caractere

// o * indica que a variavel é um ponteiro
// <!-- 
//& operador de endereço 9 retorna o endereço de uma variavel
// * operador de desreferencia (acessa o valor guardado no endereço apontado) -->

//exemplo:

int num = 42;
int *ptr = &num; // ptr recebe o endereco de num

printf("%d\n", *ptr); // imprime 42 (valor de num)
printf("%p\n", ptr); // imprime o endereço de num(algo como 0x77ffcc)]

ilustração didadica:

variavel comum: num 42 (endereço: 0x1000)

ponteiro: ptr = 0x1000 (endereço do ponteiro: 0x2000)

ao usar *ptr, voce vai ate o endereço 0x1000 e le 42.




