# Jogo da Forca em C++

Este é um jogo da forca simples implementado em C++ que permite ao jogador adivinhar palavras aleatórias e até adicionar novas palavras ao banco de dados.

## 📝 Descrição do Projeto

O programa sorteia uma palavra secreta de um arquivo texto (`palavras.txt`) e o jogador deve tentar adivinhar a palavra letra por letra, com um limite de 5 erros.

## 🛠️ Funcionalidades Principais

- **Sorteio de palavras aleatórias** a partir de um arquivo externo
- **Controle de tentativas** (máximo 5 erros)
- **Interface simples** com cabeçalho formatado
- **Sistema de feedback** que mostra letras acertadas e erradas
- **Adição de novas palavras** ao banco de dados durante o jogo

## 📂 Estrutura de Arquivos

- `Jogodaforca.cpp` - Código fonte principal
- `palavras.txt` - Banco de palavras (formato: primeira linha = número de palavras, seguido pelas palavras)
- `makefile` - Para compilação automatizada

## 🚀 Como Executar

1. **Compilar**:
   ```bash
   mingw32-make
   ```

2. **Executar**:
   ```bash
   .\Jogodaforca
   ```

## 🎮 Como Jogar

1. O programa sorteia automaticamente uma palavra secreta
2. Digite letras para tentar adivinhar a palavra
3. Você pode errar no máximo 5 letras
4. Ao final do jogo, pode adicionar novas palavras ao banco

## 🛠️ Requisitos

- Compilador C++ (como g++)
- Sistema operacional com terminal

## 📝 Formato do arquivo palavras.txt

```
N
PALAVRA1
PALAVRA2
...
PALAVRAN
```

Onde `N` é o número total de palavras no arquivo.

## ✨ Melhorias Futuras

- [ ] Adicionar suporte para letras minúsculas
- [ ] Implementar interface gráfica
- [ ] Adicionar sistema de pontuação
- [ ] Incluir dicas ou categorias de palavras

---

Desenvolvido por [Seu Nome] - Sinta-se à vontade para contribuir ou modificar!
