#include "bits/stdc++.h"
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;
//https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/
int main() {

  int limit = 2;
  vector<int> nums = {2, 2, 2, 4, 4, 2, 5, 5, 5, 5, 5, 2};

  deque<int> maxq, minq;
  int n = nums.size();
  int res = 0;

  int l = 0;
  for (int r = 0; r < n; r++) {

    while (!maxq.empty() && nums[maxq.back()] < nums[r]) {
      maxq.pop_back();
    }
    maxq.push_back(r);

    while (!minq.empty() && nums[minq.back()] > nums[r]) {
      minq.pop_back();
    }

    minq.push_back(r);

    int maxLocal = nums[maxq.front()];
    int minLocal = nums[minq.front()];

    while (l <= r && maxLocal - minLocal > limit) {
      if (maxq.front() == l)
        maxq.pop_front();
      if (minq.front() == l)
        minq.pop_front();

      maxLocal = nums[maxq.front()];
      minLocal = nums[minq.front()];
      l++;
    }

    res = max(res, r - l + 1);
  }

  cout << res;

  // for (int i : res)
  //   cout << i << " ";
  return 0;
}

/*

As deques armazenam apenas os ÍNDICES dos candidatos a máximo (maxq) e mínimo
(minq) da janela, não todos os elementos.

Os índices permanecem em ordem crescente, enquanto os valores ficam:
- maxq: em ordem decrescente.
- minq: em ordem crescente.

Quando um elemento melhor entra na janela, removemos do final da deque todos os
índices que nunca mais poderão ser máximo/mínimo. Exemplo: em [2, 4], ao inserir
o 4, o índice do 2 é removido da maxq, pois ele nunca mais poderá ser o maior.

Se max - min > limit, diminuímos a janela movendo l. Exemplo:

sub = [2, 4], limit = 5
maxq = [1] (4)
minq = [0] (2)

Ao inserir o 8:
sub = [2, 4, 8]
maxq = [2]
minq = [0, 1, 2]

A diferença passa a ser 8 - 2 = 6 > limit. Então incrementamos l. Como l = 0 é
a frente da minq, removemos esse índice e a janela passa a ser [4, 8]. O novo
mínimo é 4 e a diferença passa a ser 8 - 4 = 4.



Ao mover l, removemos da deque apenas se front == l. Se não for, significa que
esse índice já havia sido descartado anteriormente por um elemento melhor e,
portanto, já não influenciava o máximo ou o mínimo da janela. Ou seja, movemos l diminuindo o intervalo
enquanto a dif for maior que lim, independentemente de l está ou não dentro de umas das queue

Importante: comparamos ÍNDICES, não valores. Valores podem se repetir, mas cada
posição do vetor possui um índice único, que determina qual elemento entra ou
sai da janela.
*/

