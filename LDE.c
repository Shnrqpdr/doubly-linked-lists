#include <stdio.h>
#include <stdlib.h>
// #include <unistd.h>

void capa()
{
	//char string1[]="Bem vindo.";
	//char string2[]="Neste programa você trabalhará utilizando as estruturas de dados usuais.";
	//char string3[]="Programa desenvolvido pelo aluno desesperado Pedro Santos.";
	//char string4[]="Aperte ENTER para iniciar.";

	system("clear");

	printf("\n\n\n\n\t\t\t\t\t\tWelcome.");
	//imprimir(string1);
	
	printf("\n\n\t\tIn this program you are work with Ordered Doubly Linked Lists.     ");
	//imprimir(string2);
	
	printf("\n\n\t\tThis program has been development by Pedro Henrique Santos.      ");
	//imprimir(string3);

	printf("\n\n\t\tPress ENTER to begin.   ");
	//imprimir(string4);
	
	while(getchar()!='\n');
	system("clear");
}

struct lde
{
	int chave;
	struct lde *dprox;
	struct lde *eprox;
};

struct lde *cria(int n)
{
	struct lde *p, *ini, *ult, *aux, *t, *u;
	int valor, i;

	ini = NULL;
	ult = NULL;

	for(i=1; i<=n; i++)
	{
		printf("\nEnter with the value that you want to insert in the list: ");
		scanf("%d", &valor);

		p = (struct lde *) malloc(sizeof(struct lde));
		p->chave = valor;
		p->eprox = NULL;
		p->dprox = NULL;

		if(ult == NULL)
		{
			ini = p;
			ult = ini;
		}
		else
		{
			if(ult->chave > p->chave)
			{
				if(ult->eprox == NULL) // ou ult == ini, para quando você vai inserir o segundo nó
				{
					p->dprox = ult;
					ult->eprox = p;
					ini = p;
				}
				else //quando você ja inseriu 2 nós.
				{
					aux = ini;
					
					while(aux->chave < p->chave) //percorrendo a lista
					{
						aux = aux->dprox;
					}
					
					if(aux->eprox == NULL) //para marcar o inicio da lista
					{
						if(p->chave < aux->chave)
						{
							aux->eprox = p;
							p->dprox = aux;
							ini = p;
						}
					}
					else
					{
					
						t = aux->eprox;
						p->eprox = t;
						t->dprox->eprox = p;
						p->dprox = t->dprox;
						t->dprox = p;
					}
				}
			}
			else //quando o novo nó P tem a chave maior que o ult nó da lista.
			{
				ult->dprox = p;
				p->eprox = ult;
			
				ult = p;
			}
		}
	}

	return (ini);
}

struct lde *insereNo(struct lde *dupla, int valor)
{
	struct lde *p, *q, *aux;
	
	p = (struct lde *) malloc(sizeof(struct lde));
	p->chave = valor;
	p->eprox = NULL;
	p->dprox = NULL;
	
	q = dupla;
	
	if(p->chave < q->chave)
	{
		q->eprox = p;
		p->dprox = q;
		return (p);
	}
	else
	{
	
		while(q->chave < p->chave)
		{
			if(q->dprox == NULL)
			{
				if(q->eprox == NULL)
				{
					p->dprox = q;
					q->eprox = p;
					return (p);
				}
				else
				{
					q->dprox = p;
					p->eprox = q;
					
					return (dupla);
				}
			}
			else
			{
				if(q->eprox == NULL)
				{
					q->eprox = p;
					p->dprox = q;
					
					return(dupla);
				}
				q = q->dprox;
			}
		}

		
		q->eprox->dprox = p;
		p->eprox = q->eprox;
		p->dprox = q;
		q->eprox = q;
		
		return (dupla);
	}
}

struct lde *removeNo(struct lde *dupla, int valor)
{
	struct lde *p, *q, *t;
	
	p = dupla;
	
	while(p->chave != valor)
	{
		p = p->dprox;
	}
	
	if(p->eprox == NULL)
	{
		q = p->dprox;
		q->eprox = NULL;
		p->dprox = NULL;
		free(p);
		return(q);
	}
	else
	{
	
		if(p->dprox == NULL)
		{
			q = p->eprox;
			q->dprox = NULL;
			p->eprox = NULL;
			free(p);
			
			return(dupla);
		}
		
		q = p->dprox;
		t = p->eprox;
		t->dprox = q;
		q->eprox = t;
		
		free(p);
		return (dupla);
	}
}
		
void imprimeLDE(struct lde *dupla)
{
	struct lde *p;
	
	p = dupla;
	
	while(p != NULL)
	{
		printf("\t%d", p->chave);
		p = p->dprox;
	}
	
}

int buscaNo(struct lde *dupla, int valor)
{
	struct lde *p;
	
	p = dupla;
	
	while(p != NULL)
	{
		if(p->chave == valor)
			return 1;
	
		p = p->dprox;
	}
	
	return 0;
}

int contaNos(struct lde *dupla)
{
	struct lde *p;
	int n;

	p = dupla;
	
	if(p == NULL)
		return 0;
	else
	{
		n = 0;
		while(p != NULL)
		{
			n++;
			p = p->dprox;
		}
		
		return (n);
	}
}


void main(){

    capa();

    system("clear");
	
	struct lde *dupla;
	int n, valor, i, optiondupla, k;
	
	printf("\nEnter with the quantity of nodes you want create in the list: ");
	scanf("%d", &n);
	
	printf("\nCreating...\n");
	
	dupla = cria(n);

    system("clear");
	
	do
	{
		printf("\n\n------------- [MENU: ORDERED DOUBLY LINKED LISTS] ------------------------\n\t1 - Insert a node\n\t2 - Delete a node\n\t3 - View list\n\t4 - Search a node\n\t5 - Count the nodes\n\t6 - Exit\n\n");
		printf("\nEnter a option: ");
		scanf("%d", &optiondupla);
		
		switch(optiondupla)
		{
			case 1:
				printf("\nEnter with the node-value: ");
				scanf("%d", &valor);
				
				dupla = insereNo(dupla, valor);
				break;
			
			case 2:
				printf("\nEnter with the node-value you want to remove: ");
				scanf("%d", &k);
				
				dupla = removeNo(dupla, k);
				break;
			
			case 3:
				imprimeLDE(dupla);
				break;
			case 4:
				printf("\nEnter with the key-node you want to search: ");
				scanf("%d", &valor);
				
				k = buscaNo(dupla, valor);
				
				if(k == 1)
					printf("\nThis node has been found!\n");
				else
				{
					printf("\nOps! This node has been not found\n");
				}
				break;
			case 5:
				printf("\nYour list has %d nodes.\n", contaNos(dupla));
				break;
			case 6:
                printf("\nThank you...\n");
				break;
			
			default:
				printf("\nInvalid option\n");
		}
	}while(optiondupla!=6);

}