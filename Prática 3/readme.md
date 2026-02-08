# Henrique Neitzke Mulling - M1

# 701. Insert into a Binary Search Tree

Você recebe um rootnó de uma árvore binária de busca (BST) e um valor valuepara inserir na árvore. Retorne o nó raiz da BST após a inserção . É garantido que o novo valor não existe na BST original.

Note  que podem existir várias maneiras válidas de realizar a inserção, desde que a árvore permaneça uma BST após a inserção. Você pode retornar qualquer uma delas .

Exemplo 1:

Entrada: raiz = [4,2,7,1,3], val = 5
 Saída: [4,2,7,1,3,5]
 Explicação: Outra árvore aceita é:

Exemplo 2:

Entrada: raiz = [40,20,60,10,30,50,70], val = 25
 Saída: [40,20,60,10,30,50,70,null,null,25]
Exemplo 3:

Entrada: raiz = [4,2,7,1,3,null,null,null,null,null,null], val = 5
 Saída: [4,2,7,1,3,5]
 
Restrições:

O número de nós na árvore estará no intervalo de .[0, 104]
-108 <= Node.val <= 108
Todos os valores Node.valsão únicos .
-108 <= val <= 108
É garantido que isso valnão existe na BST original.