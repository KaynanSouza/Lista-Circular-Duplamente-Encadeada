#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcoes.c"
#include "funcoesDinamicas.c"


int main(){

    setlocale(LC_ALL, "Portuguese");

    int operacao;
    do {
        operacao = 0;

        operacao = menu();

        switch(operacao)
        {
            case 1: // Lista est�tica
                listaEstatica();
                break;
            case 2: // Lista din�mica
                listaDinamica();
                break;
            case 3: // Saindo
                break;
            default: // Erro
                break;
        }
    } while (operacao != 3);

    return 0;
}
