# 🎬 CineSystem - Sistema de Gestão de Vendas e Reservas de Cinema

O **CineSystem** é uma aplicação de terminal desenvolvida em **Linguagem C** para automatizar o controle de reservas, venda de ingressos e faturamento de uma sala de cinema.

Este projeto foi desenvolvido como parte de um trabalho acadêmico para demonstrar a aplicação prática de **matrizes bidimensionais**, **vetores auxiliares**, **laços de repetição aninhados** e **algoritmos de busca/validação**.

## 📌 Funcionalidades Principais

* \[x\] **Mapeamento em Tempo Real:** Exibição do mapa de assentos da sala organizados em uma grade visual de 6x8.

* \[x\] **Venda e Reserva com Validação:** Leitura de coordenadas por letra da fileira (A-F) e número da cadeira (1-8), impedindo a seleção de posições inválidas ou assentos já ocupados.

* \[x\] **Diferenciação de Ingressos:** Suporte a ingressos do tipo **Inteira** (R\$ 30,00) e **Meia-Entrada** (R\$ 15,00).

* \[x\] **Relatório de Bilheteria:** Processamento estatístico da matriz com cálculo automatizado da taxa de ocupação, total de lugares vendidos e faturamento bruto.

* \[x\] **Destaque de Vendas (Bônus):** Algoritmo de busca que identifica e exibe a(s) fileira(s) campeã(s) de bilheteria (trata empates).

## 🛠️ Estruturas de Dados Utilizadas

O sistema utiliza estruturas de dados estáticas alocadas na memória para gerenciar a sala e as estatísticas:

| Estrutura | Declaração | Tipo | Descrição / Papel | 
| ----- | ----- | ----- | ----- | 
| **Matriz da Sala** | `sala[6][8]` | `int` | Matriz bidimensional que armazena o estado de cada assento (`0` = Livre, `1` = Inteira, `2` = Meia). | 
| **Rótulo das Fileiras** | `rotuloFileiras[6]` | `char` | Vetor de mapeamento visual para converter os índices `0-5` nas letras `A-F`. | 
| **Tabela de Preços** | `tabelaPrecos[2]` | `float` | Vetor para armazenar os valores unitários dos ingressos (`30.00` e `15.00`). | 

## 🖥️ Layout e Exibição do Terminal

A interface de linha de comando foi projetada utilizando alinhamento de colunas e indicadores visuais simples:

```
================== TELA DO CINEMA ==================

       01  02  03  04  05  06  07  08
   A [ L ][ L ][ X ][ X ][ L ][ L ][ L ][ L ]
   B [ L ][ L ][ L ][ L ][ L ][ L ][ L ][ L ]
   C [ L ][ L ][ X ][ L ][ L ][ X ][ L ][ L ]
   D [ L ][ L ][ L ][ L ][ L ][ L ][ L ][ L ]
   E [ X ][ X ][ X ][ X ][ L ][ L ][ L ][ L ]
   F [ L ][ L ][ L ][ L ][ L ][ L ][ L ][ L ]

Legenda: [ L ] = Livre | [ X ] = Ocupado / Vendido
====================================================

```

## 🚀 Como Compilar e Executar

### Pré-requisitos

* Compilador GCC instalado (MinGW / MSYS2 no Windows, ou nativo no Linux/macOS).

### Passo a Passo

1. **Clone este repositório:**

   ```
   git clone https://github.com/seu-usuario/nome-do-repositorio.git
   cd nome-do-repositorio
   
   ```

2. **Compile o código-fonte:**

   ```
   gcc -Wall -Wextra Cinema.c -o Cinema
   
   ```

3. **Execute a aplicação:**

   * **Windows:**

     ```
     Cinema.exe
     
     ```

   * **Linux / macOS:**

     ```
     ./Cinema
     
     ```

## 👨‍💻 Autor

Desenvolvido como projeto de fixação de conceitos em Análise e Desenvolvimento de Sistemas.

* **LinkedIn:** linkedin.com/in/daniel-soares-610804379/?isSelfProfile=true

* **GitHub:** github.com/DanielSoares45