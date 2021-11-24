# Inteligência Artificial

## Problema dos missionários

Três missionários e três canibais estão em um lado do rio, juntamente com um
barco que pode conter uma ou duas pessoas. Descubra um meio de fazer todos
atravessarem o rio, sem deixar que um grupo de missionários de um lado fique em
número menor que o número de canibais nesse lado do rio. Esse problema é famoso
em IA, porque foi assunto do primeiro artigo que abordou a formulação de problemas a
partir de um ponto de vista analítico (Amarel, 1968).
Implemente e resolva o problema de forma ótima, utilizando um algoritmo de busca
apropriado. É boa idéia verificar a existência de estados repetidos?

---

### Saída obtida:

      Execute a travessia de 0 missionario e 2 canibais para a borda direita do rio.
      Execute a travessia de 0 missionario e 1 canibal para a borda esquerda do rio.
      Execute a travessia de 0 missionario e 2 canibais para a borda direita do rio.
      Execute a travessia de 0 missionario e 1 canibal para a borda esquerda do rio.
      Execute a travessia de 2 missionario(s) e 0 canibal para a borda direita do rio.
      Execute a travessia de 1 missionario e 1 canibal para a borda esquerda do rio.
      Execute a travessia de 2 missionario(s) e 0 canibal para a borda direita do rio.
      Execute a travessia de 0 missionario e 1 canibal para a borda esquerda do rio.
      Execute a travessia de 0 missionario e 2 canibais para a borda direita do rio.
      Execute a travessia de 1 missionario e 0 canibal para a borda esquerda do rio.
      Execute a travessia de 1 missionario e 1 canibal para a borda direita do rio.

### Para executar:
      cd missionarios
      gcc queue.c state.c main.c -o main
      ./main > main.txt
      
### Algoritmo:

      Algoritmo busca em largura utilizado para a implementação em C da resolução desse problema.
---
      
