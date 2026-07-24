typedef struct No {
    int valor;
    struct No *esq, *dir;
} No;

No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

int main() {
    // Construindo a raiz e os primeiros filhos manualmente
    No* raiz = criarNo(15);
    raiz->esq = criarNo(8);
    raiz->dir = criarNo(22);
    
    // Filhos do 8
    raiz->esq->esq = criarNo(4);
    raiz->esq->dir = criarNo(11);
    
    // ... (e assim por diante para o resto)
    return 0;
}
