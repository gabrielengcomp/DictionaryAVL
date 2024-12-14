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
