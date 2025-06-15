# Leitura e Processamento de Notas em C

Este projeto em C realiza a leitura de um arquivo de notas de alunos, imprime as notas, calcula médias, mostra alunos aprovados e gera um novo arquivo com as médias e situação de aprovação.

## Funcionalidades

- **Leitura de arquivo**: Lê um arquivo texto contendo nome e duas notas por aluno.
- **Impressão das notas**: Mostra todas as notas lidas do arquivo.
- **Cálculo e impressão das médias**: Calcula e exibe a média de cada aluno.
- **Listagem de aprovados**: Exibe apenas os alunos com média maior ou igual a 5.
- **Geração de novo arquivo**: Cria um arquivo `notas_com_media_aprovados.txt` com nome, notas, média e situação (APROVADO/REPROVADO) de cada aluno.

## Como usar

1. **Prepare o arquivo de entrada**  
   Crie um arquivo chamado `notas.txt` no mesmo diretório do programa, com o seguinte formato:
   ```
   NomeAluno1 7.5 8.0
   NomeAluno2 4.0 6.0
   NomeAluno3 9.0 5.5
   ```
   (Nome seguido de duas notas separadas por espaço)

2. **Compile o programa**
   ```sh
   gcc notas.c -o notas
   ```

3. **Execute o programa**
   ```sh
   ./notas
   ```

4. **Saída**
   - O programa exibirá as notas, médias e aprovados no terminal.
   - Um novo arquivo chamado `notas_com_media_aprovados.txt` será criado com as informações completas.

## Estrutura do código

- `verificar_leitura` e `verificar_criacao`: Garantem que os arquivos foram abertos corretamente.
- `le_arquivo`: Abre o arquivo de notas para leitura.
- `print_notas`: Imprime todas as notas dos alunos.
- `print_media`: Imprime a média de cada aluno.
- `print_aprovados`: Imprime apenas os alunos aprovados.
- `add_media_aprovado`: Cria um novo arquivo com nome, notas, média e situação de cada aluno.

## Observações

- O programa considera aprovado quem tem média maior ou igual a 5.
- O arquivo de entrada deve estar no formato especificado.
- O código é compatível com compiladores C padrão (GCC, Clang, etc).
---
