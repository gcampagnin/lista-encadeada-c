#include <stdio.h>
#include <stdlib.h>

typedef struct elemento Elemento;

struct elemento {
	int info;
	Elemento* prox;
};

/*Cria uma lista e atribui como vazia */
Elemento* lst_cria (void) {
	return NULL;
}

/*insere um elemento e retorna a lista*/
Elemento* lst_insere (Elemento* lst, int val) {
	Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
	novo->info = val;
	novo->prox = lst;
	return novo;
}

/* função para imprimir elementos da lista*/
void lst_imprime (Elemento* lst) {
	Elemento* p;
	for (p = lst; p != NULL; p = p->prox)
		printf("info = %d\n", p->info);
}

/*função de busca*/
Elemento* busca (Elemento* lst, int v){
	Elemento* p;
	for (p = lst; p != NULL; p = p->prox) {
		if(p->info == v)
			printf("Elemento %d encontrado\n", p->info);
	}
	return NULL;
}

/*remove elemento da lista*/
Elemento* lst_remove (Elemento* lst, int val) {
	Elemento* a = NULL;
	Elemento* p = lst;
	
	while (p != NULL && p->info != val) {
		a = p;
		p = p->prox;
	}
	
	if(p == NULL)
		return lst;
	
	if(a == NULL) {
		lst = p->prox;
	} else {
		a->prox = p->prox;
	}
	
	printf("Elemento %d removido\n", p->info);
	free(p);
	
	printf("Lista Atualizada\n");
	lst_imprime(lst);
	
	return lst;
}


int main(int argc, char *argv[]) {
	
	Elemento* lst;  /*declara uma lista, mas nao inicializa ela*/
	lst = lst_cria(); /* cria e inicializa uma lista, como vazia */
	lst = lst_insere(lst, 8);
	lst = lst_insere(lst, 11);
	lst = lst_insere(lst, 33);
	lst = lst_insere(lst, 44);
	lst = lst_insere(lst, 6);
	
	lst_imprime(lst);
	busca(lst,33);
	lst_remove(lst, 11);
	
	return 0;
}
