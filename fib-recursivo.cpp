#include "stdio.h"

int fib(int n) {
  if (n <= 1)
    return n;

  return fib(n - 1) + fib(n - 2);
}

int main() {

  int n;
  scanf("%d", &n);


  printf("%d", fib(n -1));

  return 0;
}
/*

Temos o big O de O(2^n), uma vez que, de forma recursiva, cada chamada da função
resulta em duas novas chamadas, criando novo ramos na árvore, mesmo sendo com
recalculos redundante. Isso ocorre por que, podemos encontrar o mesmo cálculo em
difentes ramos, deixano a árvore com achamadas repetidas. uma forma de otmização
é com dp, guardando numa matriz os valores já calculados, diminuindo o Big O
para O(n) uma vez que cada valor de 0 a n é calculado uma vez só. A desvantagem
é o big O de memória
*/
