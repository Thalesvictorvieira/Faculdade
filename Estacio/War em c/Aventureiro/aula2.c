//Alucação de memoria

int  *a, b;
:
:
b = 10;
a = (int*) malloc(sizeof(int));
*a = 20;
a = &b;
free(a); 