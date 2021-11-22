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

 - [Resolução](https://github.com/liliangisellyps/inteligencia-artificial/tree/master/missionarios)

---

## Problema do metrô de Paris

Suponha que queremos construir um sistema para auxiliar um usuário do metrô de Paris a saber o trajeto mais rápido entre a estação onde ele se encontra e a estação de destino. O usuário tem um painel com o mapa, podendo selecionar a sua estação
de destino. O sistema então acende as luzes sobre o mapa mostrando o melhor trajeto a seguir (em termos de quais estações ele vai atravessar, e quais as conexões mais rápidas a fazer – e for o caso).

Considere que:
- a distância em linha reta entre duas estações quaisquer é dada em uma tabela.
Para facilitar a vida, considere apenas 4 linhas do metrô.
- a velocidade média de um trem é de 30km/h;
- tempo gasto para trocar de linha dentro de mesma estação (fazer baldeação) é de
4 minutos.

Formule e implemente este problema em termos de estado inicial, estado final, operadores e função de avaliação para Busca heurística com A*.

- [Resolução](https://github.com/liliangisellyps/inteligencia-artificial/tree/master/paris)
---

