Projeto Batalha Naval em C

Descrição

Este projeto em C implementa um jogo simplificado de **Batalha Naval** com um tabuleiro 10x10. Nele são posicionados quatro navios — dois posicionados horizontal ou verticalmente e dois posicionados diagonalmente — e três habilidades especiais que criam áreas de efeito no tabuleiro:

- Cone: Área em formato de cone apontando para baixo.
- Cruz: Área em formato de cruz, centrada no ponto de origem.
- Octaedro: Área em formato de losango (vista frontal de um octaedro).

O programa exibe o tabuleiro no terminal com:
- `~` para água,
- `#` para navios,
- `*` para áreas afetadas pelas habilidades.

---

Funcionalidades

- Inicialização do tabuleiro (matriz 10x10).
- Posicionamento validado de navios (horizontal, vertical e diagonal).
- Construção dinâmica das matrizes de habilidades usando loops e condicionais.
- Sobreposição das áreas de efeito das habilidades no tabuleiro.
- Impressão clara do tabuleiro com símbolos diferenciados.
