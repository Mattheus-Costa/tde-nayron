
typedef struct{
    int codigo;
    char nome [30];
    int  estoque;   
}Produto;

typedef struct Lista Lista;

Lista * cria_lista();
void libera_lista(Lista *li);
int insere_lista(Lista *li, Produto *p);
int busca_lista_pos(Lista *li, int pos, Produto **p);
int busca_lista_cod(Lista *li, int codigo, Produto **p);
int remove_lista(Lista *li, int cod, Produto **p);
void exibe_lista(Lista *li);
