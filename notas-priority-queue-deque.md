# Priority Queue & Deque — Padrões de Resolução

Notas de estudo de DSA. Todo o código em C++ (ou pseudo-código).

---

## Parte 1 — Priority Queue (Fila de Prioridade)

### O que é

- `priority_queue<T>` = **heap máximo** (top é o maior).
- `priority_queue<T, vector<T>, greater<T>>` = **heap mínimo** (top é o menor).
- `top()` → O(1), `push`/`pop` → O(log n).
- **Limitação do C++:** não dá para iterar nem remover elemento arbitrário. Para "remover" um item que não é o top, usa-se **lazy deletion** (Padrão 3).

---

### Padrão 1 — Sweep line em intervalos (máxima sobreposição)

**Problemas:** Restaurant Customers (CSES 1619) · Dinossauros (NEPS 2039)

**Quando usar:** "quantas coisas acontecem ao mesmo tempo", "máximo de pessoas/salas ocupadas em um instante", "quantos dinossauros vivos no mesmo ano".

**Ideia:** ordena por início e usa uma **min-heap dos fins** dos intervalos ativos. Em cada início, remove da heap todos que já terminaram (`fim < inicio`). O tamanho da heap = sobreposição atual.

**Pseudo-código:**
```
ordenar intervalos por inicio
pq = min-heap            // guarda os fins dos intervalos ativos
res = 0
para cada (a, b) em ordem:
    enquanto pq não vazio e pq.top() < a:   // já terminou antes de a começar
        pq.pop()
    pq.push(b)                              // ativa este intervalo
    res = max(res, pq.size())               // resposta candidata
```

**C++:**
```cpp
sort(v.begin(), v.end());
priority_queue<int, vector<int>, greater<int>> q;
int res = 0;
for (auto [a, b] : v) {
    while (!q.empty() && a > q.top()) q.pop();   // expira quem terminou
    q.push(b);
    res = max(res, (int)q.size());
}
cout << res;
```

**Detalhe:** a condição é **estrita** (`fim < inicio`), porque intervalo é [a, b) — quem sai em b não está mais presente quando o outro entra em b.

---

### Padrão 2 — K servidores/recursos idênticos (agendamento)

**Problemas:** Telemarketing (NEPS 265) · Banco (NEPS 273) · Room Allocator (CSES 1164)

**Quando usar:** "vários caixas/atendentes/salas, cada um atende 1 de cada vez, quem fica livre pega a próxima tarefa".

**Ideia:** a min-heap guarda o **instante em que cada recurso fica livre**. O top é o recurso que libera primeiro. Ao atribuir, atualiza-se o instante livre (soma a duração) e **re-insere na heap** — não precisa de fila separada de "livres".

**Pseudo-código:**
```
// primeiros K (ou todos) recebem a 1ª tarefa; heap guarda (tempo_livre, id)
para cada tarefa restante, em ordem de chegada:
    (livre, id) = pq.top(); pq.pop()        // recurso que libera mais cedo
    inicio = max(livre, chegada_tarefa)     // (banco: cliente pode chegar depois)
    se inicio - chegada > 20: res++         // regra do problema (banco)
    pq.push({inicio + duracao, id})         // re-insere com novo fim
```

**C++ (telemarketing):**
```cpp
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; // (tempo livre, id)
for (int i = 0; i < n; i++) { pq.push({v[i], i}); res[i]++; }
for (int i = n; i < l; i++) {
    auto f = pq.top(); pq.pop();
    res[f.second]++;
    f.first += v[i];        // somar a duração no próprio funcionário
    pq.push(f);
}
```

**Lição (anotada no próprio arquivo):** simular uma "fila de atendentes livres" dá errado. O jeito é **somar o tempo no recurso** — a heap é simultaneamente "quem está ocupado" e "quando libera".

**Room Allocator (variação):** a heap guarda `(fim, sala)` e, além de reutilizar, precisa devolver **qual sala** cada cliente usou. Critério de reutilização é estrito: `inicio > fim` da ocupação anterior. Guarda o índice original do cliente para imprimir na ordem certa.

```cpp
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> exit; // (fim, sala)
for (int i = 0; i < n; i++) {
    int r = -1;
    if (!exit.empty() && v[i].first.first > exit.top().first) {
        r = exit.top().second; exit.pop();
    }
    if (r == -1) { ctn++; r = ctn; }         // nenhuma livre: abre sala nova
    rooms[v[i].second] = r;                  // v[i].second = índice original
    exit.push({v[i].first.second, r});
}
```

---

### Padrão 3 — Melhor item por categoria + deleção preguiçosa (lazy deletion) ⭐

**Problema:** Feira de Artesanato (OBI 2025 Fase 2 · NEPS 3266)

**Quando usar:** precisa sempre do **melhor elemento de uma classe** (ex: mais barato de um tipo), mas um mesmo item pode ser removido por outra classe. Remover "na hora do uso" em vez de procurar o item em todas as heaps.

**Ideia:**
1. Vetor global `itens` guarda `(id, tipo, preco, vendido)`.
2. Uma heap por tipo + uma heap global, ambas guardando **índices** e usando um **comparador custom** (ordena por `(preco, tipo)`).
3. Ao vender, marca `vendido = true`. Quando for usar uma heap, **descarta do topo todos os já vendidos** (`while`) — isso é o lazy deletion.

**Pseudo-código:**
```
para cada cliente c:
    heap_alvo = heap do tipo c            // se c == 0, heap global
    enquanto heap_alvo.top() já vendido: heap_alvo.pop()   // lazy deletion
    se heap_alvo vazio: continue
    id = heap_alvo.top(); heap_alvo.pop()
    itens[id].vendido = true
    res += itens[id].preco
```

**C++:**
```cpp
struct item { int id, tipo, preco; bool vendido; };
vector<item> v;

struct comp {
    bool operator()(int a, int b) const {
        return tie(v[a].preco, v[a].tipo) > tie(v[b].preco, v[b].tipo);
    }
};

unordered_map<int, priority_queue<int, vector<int>, comp>> tp; // heap por tipo
priority_queue<int, vector<int>, comp> pg;                     // heap global

while (!tp[ci].empty() && v[tp[ci].top()].vendido) tp[ci].pop();
if (!tp[ci].empty()) {
    int id = tp[ci].top();
    res += v[id].preco;
    v[id].vendido = true;
    tp[ci].pop();
}
```

**Armadilhas (erros que deram WA nessa questão):**
- **Comparador custom** com dois critérios → use `tie(v[a].preco, v[a].tipo)`. Não esqueça do `const` no `operator()`.
- **Soma total pode estourar `int`** → use `long long`. (Foi exatamente esse o motivo do WA na feira.)
- Heap guarda **índices**, não valores — evita duplicar os dados.
- Cuidado: `unordered_map` com heap → `tp[ci]` cria entry vazia; ok, mas `count()` para checar existência evita surpresa.

---

## Parte 2 — Deque (Janela Deslizante Monotônica)

### O que é / quando usar

- Deque permite `push`/`pop` **nos dois extremos** em O(1) amortizado.
- Usar quando precisar do **máximo/mínimo de uma janela que desliza** ou dos "melhores candidatos" de uma faixa contígua.

**Regra de ouro: a deque guarda ÍNDICES, não valores** — valores podem se repetir, mas cada posição tem índice único (usado para saber o que entra/sai da janela).

---

### Padrão 1 — Fila monotônica para max/mín de janela

**Problema:** Sliding Window Maximum (LeetCode 239)

**Ideia:** a deque mantém só candidatos úteis. O valor fica em ordem **decrescente** (heap de máximo) ou **crescente** (mínimo).
- **Inserir `i`:** remove do fim todos os piores ou iguais (`<=` p/ max), porque nunca mais serão máximos.
- **Deslizar:** remove da frente quem saiu da janela (compara por índice: `i - front + 1 > k`).
- `front` = resposta em O(1).

**Pseudo-código:**
```
para i em 0..n-1:
    enquanto dq não vazio e nums[dq.back()] <= nums[i]: dq.pop_back()
    dq.push_back(i)
    se i - dq.front() + 1 > k: dq.pop_front()      // saiu da janela
    se i >= k-1: res.push(nums[dq.front()])        // janela completa
```

**C++:**
```cpp
deque<int> dq;
for (int i = 0; i < n; i++) {
    while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
    dq.push_back(i);
    if (i - dq.front() + 1 > k) dq.pop_front();
    if (i >= k - 1) res.push_back(nums[dq.front()]);
}
```

**Por que O(n)?** Cada índice entra e sai da deque no máximo uma vez → amortizado linear.

---

### Padrão 2 — Duas filas monotônicas + two pointers (maior subarray válido)

**Problema:** Longest Continuous Subarray com |max − min| ≤ limit (LeetCode 1438)

**Ideia:** janela `[l, r]` válida se `max - min <= limit`. Mantém **duas** deques: `maxq` (decrescente) e `minq` (crescente). Quando fica inválida, anda `l` e remove das deques os índices que saíram.

**Pseudo-código:**
```
l = 0; res = 0
para r em 0..n-1:
    inserir r em maxq e minq (regras do Padrão 1)
    enquanto maxq.front() - minq.front() > limit:
        se maxq.front() == l: maxq.pop_front()
        se minq.front() == l: minq.pop_front()
        l++
    res = max(res, r - l + 1)
```

**C++:**
```cpp
deque<int> maxq, minq;
int l = 0, res = 0;
for (int r = 0; r < n; r++) {
    while (!maxq.empty() && nums[maxq.back()] < nums[r]) maxq.pop_back();
    maxq.push_back(r);
    while (!minq.empty() && nums[minq.back()] > nums[r]) minq.pop_back();
    minq.push_back(r);

    while (l <= r && nums[maxq.front()] - nums[minq.front()] > limit) {
        if (maxq.front() == l) maxq.pop_front();
        if (minq.front() == l) minq.pop_front();
        l++;
    }
    res = max(res, r - l + 1);
}
```

**Pontos-chave (comentados no próprio código do problema):**
- A saída da janela é detectada por **`front == l`**. Se o índice `l` já foi descartado por um elemento melhor, ele nem está mais na deque — por isso checamos `==` e não removemos à força.
- A diferença sempre é recalculada após mover `l` (o `front` pode ter mudado).

---

### ⚠️ books.cpp (Codeforces 279B) — problema MISTURADO

O arquivo está na pasta `deque/`, mas **não é problema de deque** — é **two pointers** (maior janela cuja soma ≤ tempo disponível). E a implementação atual está **errada**: não lê entrada e calcula outra coisa.

**Solução correta:**
```cpp
int l = 0, res = 0, sum = 0;
for (int r = 0; r < n; r++) {
    sum += a[r];
    while (sum > t) sum -= a[l++];      // encolhe a janela pela esquerda
    res = max(res, r - l + 1);
}
```

---

## Resumo rápido — qual padrão usar

| Cenário | Estrutura | Padrão |
|---|---|---|
| Máximo de eventos simultâneos (intervalos) | min-heap de fins | Sweep line (PQ 1) |
| K atendentes/caixas/salas + fila de tarefas | min-heap de tempo livre | Agendamento (PQ 2) |
| Melhor item por categoria, com remoções | heap por categoria + lazy deletion | Feira (PQ 3) |
| Máximo/mínimo de janela deslizante | deque monotônica | Janela (Deque 1) |
| Maior subarray que satisfaz condição de max/min | 2 deques + two pointers | Janela + 2P (Deque 2) |
