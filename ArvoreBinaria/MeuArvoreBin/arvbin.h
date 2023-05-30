#ifndef _arvbin_
#define _arvbin_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define TAM_MAX 100


typedef struct _arvbin{
    int info;
    struct _arvbin *esq, *dir;
} arvbin, nodeArvbin;


#endif