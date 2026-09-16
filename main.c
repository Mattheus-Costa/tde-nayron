#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"


int main()
{
    Lista *li = NULL;
    int n, escolha;


    do{
        
    printf ("Selecione a acao:\n");
    printf ("(1) Cadastrar nova lista\n");
    printf ("(2) Inserir Produtos\n");
    printf ("(3) Exibir Lista cadastrada\n");
    printf ("(4) Buscar Produto por Codigo\n");
    printf ("(5) Buscar Produto por Posicao \n");
    printf ("(6) Remover Produto\n");
    printf ("(7) Sair \n ");
    printf ("Digite: ");

    scanf("%d", &escolha);
    
    switch(escolha){
        case 1:
                if (li != NULL) {
                    printf("A lista ja foi criada!\n");
                    break;
                    }
                li = cria_lista();
                if (li != NULL) {
                        printf("Lista criada!\n");
                    }
                else{
                    printf("Falha ao criar a lista!");
                }
                
                break;

       case 2:


                if (li == NULL) {
                printf("Crie uma lista primeiro!\n");
                break;
            }

                printf("Quantos produtos voce deseja cadastrar?: ");
                scanf("%d", &n);
               

                for (int i= 0; i<n; i++){

                    Produto *p1;
                
                    p1 = malloc(sizeof(Produto)); 
                    
                       if (p1 == NULL) {
                    printf("Erro ao alocar produto!\n");
                    break;
                }

                    printf("Digite o nome do produto: ");
                    scanf(" %29[^\n]", p1->nome);


                    printf("Digite o codigo do produto: ");
                    scanf("%d", &p1->codigo);

                    printf("Digite o estoque do produto: ");
                    scanf("%d", &p1->estoque);

                    if (!insere_lista(li, p1)) {
                        printf("Erro ao inserir produto!\n");
                        free(p1);
        }
    }
             break;  

        case 3:
                    if (li == NULL) {
                printf("Crie uma lista primeiro!\n");
                break;
            }

            exibe_lista(li);
            break;  
           

        case 4:

         {
                if (li == NULL) {
                    printf("Crie uma lista primeiro!\n");
                    break;
                }

                int cod;
                Produto *p;

                printf("Digite o codigo do produto a ser buscado: ");
                scanf("%d", &cod);

                   if (busca_lista_cod(li, cod, &p)) {
                    printf("Produto: %s\nEstoque: %d\n", p->nome, p->estoque);
                 
                }
                else {
                    printf("Produto nao encontrado!\n");
                }
                break; 
         }
              

        case 5:
         {
                if (li == NULL) {
                    printf("Crie uma lista primeiro!\n");
                    break;
                }

                int pos;
                Produto *p;

                printf("Digite a posicao do produto a ser buscado: ");
                scanf("%d", &pos);

                   if (busca_lista_pos(li, pos, &p)) {
                    printf("Produto: %s\nEstoque: %d\n", p->nome, p->estoque);
                   
                }
                else {
                    printf("Produto nao encontrado!\n");
                }
                break; 
         }


         case 6:
          {
                if (li == NULL) {
                    printf("Crie uma lista primeiro!\n");
                    break;
                }

                int cod;
                Produto *p;

                printf("Digite o codigo do produto a ser removido: ");
                scanf("%d", &cod);

                if (remove_lista(li, cod, &p)) {
                    printf("Produto removido: %s\n", p->nome);
                    free(p);
                }
                else {
                    printf("Produto nao encontrado!\n");
                }
                break; 
               }

        case 7:
               printf("Encerrando...");
               break;
         
        default:
            printf("Opcao Invalida!");
            break;
    }
   


} while(escolha !=7);

 libera_lista(li);

return 0;
} 





