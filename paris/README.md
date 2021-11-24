# Inteligência Artificial

## Problema dos missionários

Suponha que queremos construir um sistema para auxiliar um usuário do metrô de Paris a saber o trajeto mais rápido entre a estação onde ele se encontra e a estação de destino. O usuário tem um painel com o mapa, podendo selecionar a sua estação
de destino. O sistema então acende as luzes sobre o mapa mostrando o melhor trajeto a seguir (em termos de quais estações ele vai atravessar, e quais as conexões mais rápidas a fazer – e for o caso).

Considere que:
- a distância em linha reta entre duas estações quaisquer é dada em uma tabela.
Para facilitar a vida, considere apenas 4 linhas do metrô.
- a velocidade média de um trem é de 30km/h;
- tempo gasto para trocar de linha dentro de mesma estação (fazer baldeação) é de
4 minutos.

Formule e implemente este problema em termos de estado inicial, estado final, operadores e função de avaliação para Busca heurística com A*.

---

### Para executar:
      cd paris
      gcc main.c grafo.c queue.c path.c -o main
      ./main

OBS: Ele irá pedir duas entradas: a sua estação de origem e a de destino, que deve ser inserida no formato númerico (1, para representar a estação 1, 2, para representar aestação 2 e assim por diante).


### Exemplo de saída obtida:

      Digite sua estacao de origem: 1
      Digite sua estacao de destino: 14
      Voce saira da estacao 1 e ira para a estacao 14.

      [...] Rota encontrada.

      Para viajar pelo trajeto mais rapido, siga as instrucoes a seguir:

      A partir da estacao 1, va para as seguintes estacoes:
      Estacao 2 -> Estacao 3 -> Estacao 13 -> Estacao 14

      A estimativa para a sua viagem eh de 42 km e 84 min, com o trem a uma velocidade media de 30km/h.

      Tenha uma boa viagem!

### Algoritmo:

      Algoritmo A* utilizado para a implementação em C da resolução desse problema.
---
      
