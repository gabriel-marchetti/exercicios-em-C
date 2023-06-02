#include <ArvoreBinaria.h>

void createTree(arvbin **T)
{
    if ( T == NULL ){
        *T = (arvbin *)calloc(1, sizeof(arvbin));
    }
}

arvbin *createNode(int info)
{
    arvbin *p = (arvbin *)calloc(1, sizeof(arvbin));
    p->info = info;
    return p;
}

arvbin *createTreeSimPos(int *sim, int *pos, int n)
{
    int position = n-1;
    int elem = pos[position];
    nodeArvbin *p = createNode(elem);
    /* Já usei a posição para achar o último da pós-Ordem, então vou usar essa mesma var.*/
    position = searchPos(sim, n, elem);
    /* Agora preciso dividir a sim e a pos para a próxima iteração. */
    int sim1[position - 1], sim2[n - position - 1];
    int pos1[position - 1], pos2[n - position - 1];
    // Vamos pensar na seguinte árvore.
    // Sim = [4, 8, 2, 5, 1, 6, 3, 7]
    // Pos = [8, 4, 5, 2, 6, 7, 3, 1]
    // Queremos:
    // sim1 = [4, 8, 2, 5] pos1 = [8, 4, 5, 2]
    // sim2 = [6, 3, 7] pos2 = [6, 7, 3]
    for( int i = 0; i < position - 1; i++){ 
        sim1[i] = sim[i];
        pos1[i] = pos[i];
    }
    // Consegui sim1 e pos1
    for( int i = 0 ; i < n - position - 1; i++){
        sim2[i] = sim[position + i +1];
        pos2[i] = pos[position + i];
    }
    p->esq = createTreeSimPos(sim1, pos1, position - 1);
    p->dir = createTreeSimPos(sim2, pos2, n - position - 1);
    
    return p;
}

int searchPos(int *array, int n, int wanted)
{
    for (int i = 0 ; i < n ; i++){
        if ( array[i] == wanted) return(i);
    }
}