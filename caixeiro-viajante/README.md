# Inteligência Artificial

## Problema do caixeiro viajante

Um caixeiro viajante precisa visitar 10 cidades do interior de Pernambuco. Ele pede a
um agente de busca que determine uma rota para sua visita tal que cada cidade só
seja visitada uma única vez, e ele percorra o menor espaço possível (em Km). O
agente de busca tem um mapa do estado, e portanto sabe as distâncias entre as
cidades.
Formule e implemente este problema em termos de estado inicial, estado final,

operadores e função de avaliação para Busca por melhoras iterativas com Hill-
Climbing.

O operador considerado para gerar os filhos do estado corrente é permutar as
cidades da rota atual duas a duas, e verificar em seguida se o caminho está
conectado (segundo a tabela abaixo, que representa o mapa da questão). A cidade
inicial deve ser mantida, uma vez que o caixeiro mora lá ! A rota é fechada (ele volta
à cidade de origem no final).

---

### Para executar:
      cd caixeiro-viajante
      gcc main.c grafo.c path.c -o main
      ./main

OBS: Ele irá pedir uma entradas, que corresponderá a sua cidade de origem (e portanto de destino final), que deve ser inserida no formato númerico (1, para representar a cidade 1; 2, para representar a estação 2 e assim por diante).


### Exemplo de saída obtida:

      Qual a sua cidade de origem? Digite no formato '1', '2', ..., '10'.
      6
      --------------------------------------
      A melhor rota saindo da cidade 6 e retornando para ela eh:

      Cidade 6 -> Cidade 7 -> Cidade 10 -> Cidade 2 -> Cidade 1 -> Cidade 4 -> Cidade 8 -> Cidade 3 -> Cidade 5 -> Cidade 9 -> Cidade 6 

      Voce ira percorrer um total de 558 km e viajara por 10 cidades do interior de Pernambuco, incluindo a sua de origem.

      Tenha uma boa viagem!
      --------------------------------------

### Algoritmo:

      Algoritmo Hill Climbing utilizado para a implementação em C da resolução desse problema.
---
      
