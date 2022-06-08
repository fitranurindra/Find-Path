/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
 *  Modul               : 9 - Tugas Besar
 *  Kelompok            : B7
 *  Hari dan Tanggal    : Kamis, 21 April 2022
 *  Asisten (NIM)       : Elkhan Julian Brillianshah
 *  Nama File           : findpath_lib.c
 *  Deskripsi           : Implementation file untuk library findpath.
 */


#include "findpath_lib.h"

void countPath(int *count, int nVertex, int nEdges, int vStart, int vEnd, int **mtrx){
    int i,j;
    int currEdges = nEdges;
    int *temp = (int*) malloc(nVertex*sizeof(int));

    for (i = 0; i < nVertex; i++){
        if (mtrx[vStart][i] == 1){
            for(j = 0; j < nVertex; j++){
                temp[j] = mtrx[j][vStart];
                mtrx[j][vStart] = 0;
            }

            nEdges -= 1;

            if(nEdges == 0 && i == vEnd){
                *count += 1;
            }
            else if (nEdges > 0 && i != vEnd){
                countPath(count, nVertex, nEdges, i, vEnd, mtrx);
            }

            for(j = 0; j < nVertex; j++){
                mtrx[j][vStart] = temp[j];
            }
        }

        nEdges = currEdges;
    }
    
    free(temp);
}

void findPath(int *count, int nPath, int **mtrxPath, int nVertex, int nEdges, int vStart, int vEnd, int **mtrx){
    int i,j;
    int currEdges = nEdges;
    int *temp = (int*) malloc(nVertex*sizeof(int));

    for (i = 0; i < nVertex; i++){
        if (mtrx[vStart][i] == 1){
            for(j = 0; j < nVertex; j++){
                temp[j] = mtrx[j][vStart];
                mtrx[j][vStart] = 0;
            }

            if (*count != nPath){
                mtrxPath[*count][nEdges] = vStart+1;
            }

            nEdges -= 1;

            if(nEdges == 0 && i == vEnd){
                mtrxPath[*count][nEdges] = vEnd+1;
                *count += 1;
            }
            
            else if (nEdges > 0 && i != vEnd){
                findPath(count, nPath, mtrxPath, nVertex, nEdges, i, vEnd, mtrx); 
            }
            
            for(j = 0; j < nVertex; j++){
                mtrx[j][vStart] = temp[j];
            }
        }

        nEdges = currEdges;
    }
    
    free(temp);
}

void printPath(int nRow, int nCol, int **mtrxPath){
    int i;
    int j;

    for(i = 0; i < nRow; i++){
        for(j = nCol-1; j >= 0; j--){
            if (j != 0){
                printf("%d-", mtrxPath[i][j]);
            }
            else{
                printf("%d", mtrxPath[i][j]);
            }
        }

        printf("\n");
    }
}
