#include <stdio.h>
#include <stdlib.h>
#include "produtos.h"

struct Lista{
    int qtd;
    Produto *dados [100];
};

Lista* cria_lista(){ 
    Lista *li;
    li = malloc(sizeof(Lista));
    if (li != NULL)
        li->qtd = 0;
    return li;

}

void libera_lista(Lista *li){
   if (li == NULL)
        return;

    for (int i = 0; i < li->qtd; i++)
        free(li->dados[i]);

    free(li);
}

int insere_lista(Lista *li, Produto *p){
    if (li == NULL)
        return 0;

    if (li->qtd == 100)
        return 0;
    
    li->dados[li->qtd] = p;
    li->qtd++;
    return 1;
}
int busca_lista_cod(Lista *li, int cod, Produto **p){
    if (li == NULL)
        return 0;

    int i = 0;
    while(i < li->qtd && li->dados[i]->codigo != cod)
        i++;
    if (i == li->qtd)
    return 0;

    *p = li->dados[i];
    return 1;
}

int busca_lista_pos (Lista *li, int pos, Produto **p){
     if (li == NULL || pos <= 0 || pos > li->qtd)
        return 0;

    *p = li->dados[pos-1];
    return 1;
}



int remove_lista(Lista *li, int cod, Produto **p){
    if (li == NULL)
        return 0;

    if (li->qtd == 0)
        return 0;

    int i = 0;

    while(i < li->qtd && li->dados[i]->codigo != cod)
        i++;
    if (i == li->qtd)
        return 0;
    
    *p = li->dados[i];
  
    li->dados[i] =  li->dados[li->qtd - 1];
    li->qtd--;
    return 1;
}

void exibe_lista(Lista *li){
        if (li == NULL)
        return;

    if (li->qtd == 0)
        return;
    
    
    for(int i=0; i < li->qtd; i++){
       printf("====PRODUTO %d====\n", i+1);
       printf("Nome: %s\n", li->dados[i]->nome);
       printf("Codigo: %d\n", li->dados[i]->codigo);
       printf("Estoque: %d\n", li->dados[i]->estoque);
    }
   
}