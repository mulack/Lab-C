# TR12_541013

<h2 align="center">Como Baixar o Codigo</h2>

<p align="center">Vá até a área do codigo,
então clique no codigo .c e você verá o conteúdo,
clique na opção Raw (está na barra de opções acima do conteúdo).
  
Depois pressione o botão direito e clique em Salvar como:
  
confirme, e pronto!
  
Então clique agora no codigo .h,
clique na opção Raw (está na barra de opções acima do conteúdo).
  
Depois pressione o botão direito e clique em Salvar como:
  
confirme, e pronto</p>

<h2 align="center">Como gerar a biblioteca para usar no seu código</h2>

<p align="center"> Execute:

```
gcc -c heap.c
```

Será gerado um arquivo chamado ordvetor.o

Exemplo de como compilar junto com seu código:

```
gcc main.c heap.o -o nome_do_programa
```
</p>

<h2 align="center">Sobre o Codigo</h2>

<p align="center">Esse codigo serve para criar uma bibliotaca em C com as funções para criar uma heap, adicionar e remover na heap. O usuário específica como quer ordenar com a função de comparação(COMP)</p>
