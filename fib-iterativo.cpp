#include "stdio.h"



int main() {

  int n;
  scanf("%d", &n);
  if(n == 0 || n == 1) {
      printf("%d", n);
    return 0;
  }
  const int MAXN = 1e4 + 10;
  int dp[MAXN];

  dp[1] = 1;

  for (int i = 2; i < n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  
  printf("%d", dp[n - 1]);

  return 0;
}
/*

Temos o big O de O(n), uma vez que, de forma iterativa, calculamos de cima para baixo os valores 
da sequencia, começando com 0 e 1, tabulando os dados num vetor até encontrarmos o que valor na
posição n-1 (isso com cóedigo indexado em 0);

*/
