# Detective Quest - Mapa em Árvore Binária

## Descrição
Implementação de um jogo de exploração em C que simula uma mansão misteriosa utilizando uma estrutura de dados de árvore binária. Cada nó da árvore representa um cômodo da mansão, e o jogador pode navegar entre os cômodos explorando o ambiente.

## Estrutura do Projeto
O projeto consiste em um único arquivo C (`detective_quest_mapa.c`) que implementa:
- Estrutura de dados em árvore binária para representar o mapa
- Sistema de navegação interativa
- Histórico de navegação usando pilha
- Visualização do mapa completo

## Requisitos do Programa

### Requisitos de Sistema
- **Compilador C**: GCC 4.8+ ou Clang 3.4+
- **Sistema Operacional**: Linux, macOS, Windows (com MinGW ou WSL)
- **Memória**: Mínimo de 1 MB de RAM disponível

### Bibliotecas Utilizadas
O programa utiliza apenas bibliotecas padrão do C:
- `stdio.h` - Entrada e saída padrão
- `stdlib.h` - Alocação dinâmica de memória
- `string.h` - Manipulação de strings

## Instruções de Compilação

### Linux/macOS
```bash
# Compilar o programa
gcc detective_quest_mapa.c -o detective_quest

# Ou com warnings habilitados
gcc -Wall -Wextra detective_quest_mapa.c -o detective_quest
```

### Windows (MinGW)
```cmd
# Compilar o programa
gcc detective_quest_mapa.c -o detective_quest.exe
```

### Windows (Visual Studio)
```cmd
# Compilar usando cl.exe
cl detective_quest_mapa.c
```

## Instruções de Execução

### Linux/macOS
```bash
./detective_quest
```

### Windows
```cmd
detective_quest.exe
```

## Como Funciona o Programa

### Estrutura do Mapa
O mapa da mansão é implementado como uma árvore binária:
```
            Entrada Principal
           /                 \
      Biblioteca         Sala de Jantar
      /        \            /          \
 Escritório  Sala de   Cozinha    Salão de
              Música                 Festas
```

### Navegação Interativa
O programa oferece um sistema de navegação em tempo real:

#### Comandos Disponíveis
- **E** ou **e**: Move para o cômodo à esquerda
- **D** ou **d**: Move para o cômodo à direita
- **V** ou **v**: Volta para o cômodo anterior (usando histórico)
- **M** ou **m**: Exibe o mapa completo da mansão
- **S** ou **s**: Sai da mansão e encerra o programa

#### Fluxo de Funcionamento
1. **Inicialização**: O programa constrói a árvore binária representando a mansão
2. **Posição Inicial**: O jogador começa na "Entrada Principal" (raiz da árvore)
3. **Exploração**: 
   - O programa exibe o cômodo atual com descrição
   - Mostra as opções de movimento disponíveis
   - Aguarda comando do usuário
4. **Navegação**:
   - Ao se mover, o cômodo atual é salvo no histórico (pilha)
   - O jogador pode voltar usando o comando 'V'
5. **Finalização**: Ao escolher 'S', a memória é liberada e o programa termina

### Características Técnicas

#### Gerenciamento de Memória
- **Alocação Dinâmica**: Todos os cômodos são alocados dinamicamente com `malloc()`
- **Liberação de Memória**: Função `liberarMapa()` percorre a árvore em pós-ordem liberando todos os nós
- **Segurança**: Verificação de alocação bem-sucedida antes de usar ponteiros

#### Histórico de Navegação
- Implementado como uma pilha de ponteiros (array estático de 100 posições)
- Permite voltar pelos cômodos visitados
- Usa índice `topo` para controlar a pilha

#### Visualização do Mapa
- Usa travessia in-ordem da árvore binária
- Lista todos os cômodos disponíveis em ordem alfabética/estrutural

## Exemplo de Uso

```
===== BEM-VINDO AO DETECTIVE QUEST =====
Explore a mansão misteriosa...

============================================
Localização: Entrada Principal
============================================
Um grande hall com um lustre de cristal. Portas à esquerda e direita.

Opções de movimento:
  [E] Ir para a esquerda (Biblioteca)
  [D] Ir para a direita (Sala de Jantar)
  [V] Voltar
  [S] Sair da mansão

Escolha uma opção: e

============================================
Localização: Biblioteca
============================================
Estantes repletas de livros antigos. Há uma porta secreta na parede.

Opções de movimento:
  [E] Ir para a esquerda (Escritório)
  [D] Ir para a direita (Sala de Música)
  [V] Voltar
  [S] Sair da mansão

Escolha uma opção: m

========== MAPA DA MANSÃO ==========
Cômodos disponíveis:
- Escritório
- Biblioteca
- Sala de Música
- Entrada Principal
- Cozinha
- Sala de Jantar
- Salão de Festas
====================================
```

## Possíveis Melhorias Futuras
- Adicionar itens coletáveis nos cômodos
- Implementar sistema de pistas e enigmas
- Adicionar mais cômodos e níveis
- Salvar/carregar progresso do jogo
- Interface gráfica
- Sistema de inventário
- NPCs (personagens não-jogáveis)

## Conceitos de Programação Aplicados
- **Estruturas de Dados**: Árvore Binária
- **Algoritmos**: Travessia de árvore (in-ordem, pós-ordem)
- **Gerenciamento de Memória**: Alocação e liberação dinâmica
- **Recursão**: Funções recursivas para percorrer e liberar a árvore
- **Estruturas**: `typedef struct` para criar tipos personalizados
- **Pilha**: Implementação de histórico de navegação

## Licença
Este projeto é de código aberto e está disponível para fins educacionais.

## Autor
Desenvolvido como projeto educacional para demonstrar o uso de árvores binárias em C.
