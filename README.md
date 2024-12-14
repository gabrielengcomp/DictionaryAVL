# AVL Tree Dictionary

This project implements a dictionary using an AVL tree in C. It supports word insertion, search, removal, and balanced reorganization using AVL rotations. The tree ensures efficient operations by maintaining balance, making it suitable for quick lookup and dynamic dictionary operations.

## Features

- **Insertions**: Add new words along with their meanings while maintaining tree balance.
- **Search**: Find words and their meanings efficiently.
- **Removal**: Delete words from the dictionary and rebalance the tree automatically.
- **In-order Print**: Display the dictionary in alphabetical order.
- **Balancing**: Automatically balances the tree using AVL rotations (LL, RR, LR, RL).
- **Performance Metrics**:
  - Number of insertions.
  - Total rotations performed.
  - Execution time for insertions and searches.

## How to Use

1. **Compile the Code**:
   ```bash
   gcc -o avl_dictionary avl_dictionary.c
   ```

2. **Run the Program**:
   ```bash
   ./avl_dictionary
   ```

3. **Menu Options**:
   - `1`: Create a new dictionary.
   - `2`: Remove a word from the dictionary.
   - `3`: Insert a new word and its meaning.
   - `4`: Search for a word in the dictionary.
   - `5`: Display the dictionary in alphabetical order.
   - `7`: Exit the program and display performance metrics.

## Input Format

### Insert Word
When prompted with option `3`:
1. Enter the word to insert (e.g., `apple`).
2. Enter its meaning, ending with a newline (e.g., `A fruit that grows on trees.`).

### Search Word
When prompted with option `4`, enter the word to search for.

### Remove Word
When prompted with option `2`, enter the word to be removed.

## Example Execution

```
1
# Output: Arvore vazia criada com sucesso

3
apple
A fruit that grows on trees.
# Output: Palavra apple inserida com sucesso

3
banana
A yellow fruit.
# Output: Palavra banana inserida com sucesso

4
apple
# Output: Palavra encontrada: apple, A fruit that grows on trees.

5
# Output:
# apple
# Significado: A fruit that grows on trees.
#
# banana
# Significado: A yellow fruit.

2
apple
# Output: Palavra removida com sucesso: apple

7
# Output:
# -------------------------------------------------
# Tempo de execução da Inserção: 5s
# Palavras inseridas: 2
# Rotações feitas: 1
# -------------------------------------------------
```

## Code Overview

### Functions
- **`criaArvore`**: Initializes an empty AVL tree.
- **`criaNo`**: Creates a new node with a given word and meaning.
- **`insereAVL`**: Inserts a word into the AVL tree and rebalances it.
- **`remocaoAVL`**: Removes a word and rebalances the tree.
- **`Balanceamento`**: Handles tree balancing after insertions or deletions.
- **`buscaNo`**: Searches for a word in the tree.
- **`PrintAVLemOrdemAlfabetica`**: Prints the AVL tree in alphabetical order.
- **Rotations (LL, RR, LR, RL)**: Performs specific AVL rotations to maintain balance.

### Metrics
- **`ContaRot`**: Tracks the number of rotations performed.
- **Execution Times**: Measures time for insertions and searches.

============================================================================================================

# Dicionário com Árvore AVL

Este projeto implementa um dicionário utilizando uma **Árvore AVL** em C. Ele suporta operações de inserção, busca, remoção e reorganização balanceada através de rotações AVL. A árvore mantém o balanceamento automaticamente, garantindo eficiência nas operações de consulta e gerenciamento dinâmico do dicionário.

## Funcionalidades

- **Inserção**: Adiciona novas palavras e seus significados, mantendo o balanceamento da árvore.
- **Busca**: Encontra palavras e seus significados de forma eficiente.
- **Remoção**: Remove palavras do dicionário e reequilibra a árvore automaticamente.
- **Impressão em Ordem Alfabética**: Exibe o dicionário em ordem alfabética.
- **Balanceamento Automático**: Realiza rotações AVL (LL, RR, LR, RL) para garantir o equilíbrio da árvore.
- **Métricas de Desempenho**:
  - Número de inserções realizadas.
  - Total de rotações feitas.
  - Tempo de execução para inserções e buscas.

## Como Utilizar

1. **Compilar o Código**:
   ```bash
   gcc -o dicionario_avl dicionario_avl.c
   ```

2. **Executar o Programa**:
   ```bash
   ./dicionario_avl
   ```

3. **Opções do Menu**:
   - `1`: Criar um novo dicionário.
   - `2`: Remover uma palavra do dicionário.
   - `3`: Inserir uma nova palavra e seu significado.
   - `4`: Buscar uma palavra no dicionário.
   - `5`: Exibir o dicionário em ordem alfabética.
   - `7`: Sair do programa e exibir métricas de desempenho.

## Formato de Entrada

### Inserir Palavra
Ao escolher a opção `3`:
1. Insira a palavra a ser adicionada (exemplo: `maçã`).
2. Insira seu significado, terminando com uma quebra de linha (exemplo: `Uma fruta que cresce em árvores.`).

### Buscar Palavra
Ao escolher a opção `4`, insira a palavra que deseja buscar.

### Remover Palavra
Ao escolher a opção `2`, insira a palavra a ser removida.

## Exemplo de Execução

```
1
# Saída: Arvore vazia criada com sucesso

3
maçã
Uma fruta que cresce em árvores.
# Saída: Palavra maçã inserida com sucesso

3
banana
Uma fruta amarela.
# Saída: Palavra banana inserida com sucesso

4
maçã
# Saída: Palavra encontrada: maçã, Uma fruta que cresce em árvores.

5
# Saída:
# maçã
# Significado: Uma fruta que cresce em árvores.
#
# banana
# Significado: Uma fruta amarela.

2
maçã
# Saída: Palavra removida com sucesso: maçã

7
# Saída:
# -------------------------------------------------
# Tempo de execução da Inserção: 5s
# Palavras inseridas: 2
# Rotações feitas: 1
# -------------------------------------------------
```

## Resumo do Código

### Funções
- **`criaArvore`**: Inicializa uma árvore AVL vazia.
- **`criaNo`**: Cria um novo nó com uma palavra e significado.
- **`insereAVL`**: Insere uma palavra na árvore e realiza o balanceamento.
- **`remocaoAVL`**: Remove uma palavra e reequilibra a árvore.
- **`Balanceamento`**: Realiza o balanceamento da árvore após inserções ou remoções.
- **`buscaNo`**: Busca uma palavra na árvore.
- **`PrintAVLemOrdemAlfabetica`**: Exibe a árvore AVL em ordem alfabética.
- **Rotações (LL, RR, LR, RL)**: Realiza rotações específicas para manter o equilíbrio da árvore.

### Métricas
- **`ContaRot`**: Acompanha o número de rotações realizadas.
- **Tempos de Execução**: Mede o tempo de inserções e buscas.
