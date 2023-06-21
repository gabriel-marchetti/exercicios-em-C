#include "FilaPrioridade.h"

void insertMaxHeap(clientheap **order, client new)
{
    ((*order)->fila)[(*order)->size - 1] = new;
    ((*order)->size)++;
    PercolateMax(order, (*order)->size - 1);
}

void insertMinHeap(clientheap **order, client new)
{
    ((*order)->fila)[(*order)->size - 1] = new;
    ((*order)->size)++;
    PercolateMin(order, (*order)->size - 1);
}

void percolateMinHeap(clientheap **order, int pos)
{
    if ( pos <= 0 ) return;
    int parentposition = parent(pos);
    if ( ((*order)->fila)[parentposition].priority > ((*order)->fila)[pos].priority ){
        swapClient(order, pos, parentposition);
        percolateMinHeap(order, parentposition);
    } else {
        return;
    }
}

void percolateMaxHeap(clientheap **order, int pos)
{
    if ( pos <= 0 ) return;
    int parentposition = parent(pos);
    if ( ((*order)->fila)[parentposition].priority < ((*order)->fila)[pos].priority ){
        swapClient(order, pos, parentposition);
        percolateMaxHeap(order, parentposition);
    } else {
        return;
    }
}

client popMax(clientheap **order){
    if ( (*order)->size < 1 ){
        client erro;
        erro.name = "erro"; erro.priority = -1;
        printf("Heap Underflow.\n");
        return erro;
    } else {
        client max = ((*order)->fila)[0];
        ((*order)->fila)[0] = ((*order)->fila)[(*order)->size - 1];
        ((*order)->size)--;
        // Definir função min heapify
        MaxHeapify();
        return max;
    }
}

void MaxHeapify(clientheap **Heap, int pos)
{

}

void swapClient(clientheap **order, int p1, int p2)
{
    int aux = p1;
    ((*order)->fila)[p1] = ((*order)->fila)[p2];
    ((*order)->fila)[p2] = ((*order)->fila)[aux];
}

