## Casos de Teste

### Caso de Teste 1: Inserção de Mercadorias

- **Pré-condição:** Hash Table vazia.
- **Ação:** Inserir três mercadorias com códigos e nomes distintos.
- **Resultado esperado:** A Hash Table deve conter as três mercadorias inseridas.

### Caso de Teste 2: Busca por Mercadoria

- **Pré-condição:** Hash Table contém várias mercadorias.
- **Ação:** Buscar por uma mercadoria que existe na Hash Table.
- **Resultado esperado:** O programa deve encontrar a mercadoria e exibir suas informações.

### Caso de Teste 3: Remoção de Mercadoria

- **Pré-condição:** Hash Table contém uma mercadoria específica.
- **Ação:** Remover a mercadoria usando seu código.
- **Resultado esperado:** A mercadoria deve ser removida da Hash Table. A tentativa de buscar pela mesma mercadoria posteriormente não deve retornar resultados.

### Caso de Teste 4: Busca por Mercadoria Inexistente

- **Pré-condição:** Hash Table contém várias mercadorias, mas não a que será buscada.
- **Ação:** Buscar por uma mercadoria usando um código que não corresponde a nenhuma mercadoria presente na Hash Table.
- **Resultado esperado:** O programa deve indicar que a mercadoria não foi encontrada, demonstrando o correto manejo de buscas por itens inexistentes.

### Caso de Teste 5: Remoção de Mercadoria Inexistente

- **Pré-condição:** Hash Table contém várias mercadorias, mas não a que será removida.
- **Ação:** Tentar remover uma mercadoria usando um código que não corresponde a nenhuma mercadoria presente na Hash Table.
- **Resultado esperado:** O programa deve indicar que a mercadoria não foi encontrada ou que não há nada a ser removido, assegurando que a tentativa de remover uma mercadoria inexistente é tratada de maneira adequada.

## Resultados dos Testes

Você pode incluir capturas de tela do terminal após executar os casos de teste, mostrando a saída do programa para cada caso.
