/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
 *  Modul               : 9 - Tugas Besar
 *  Kelompok            : B7
 *  Hari dan Tanggal    : Rabu, 20 April 2022
 *  Asisten (NIM)       : Elkhan Julian Brillianshah
 *  Nama File           : exfile_lib.c
 *  Deskripsi           : Implementation file untuk library exfile.
 */

#include "exfile_lib.h"

void checkFile (char filename[MAX_LEN])
{
    FILE* fp = fopen(filename, "r");
    int size;

    if (fp == NULL){
        printf("\nError: file invalid!");
        exit(1);
    }

    else{
        fseek (fp, 0, SEEK_END);
        size = ftell(fp);
    
        if (size == 0) {
            printf("\nError: file empty!");
            exit(1);
        }
        fclose(fp);
    }
}

int nVertexFile (FILE* fp)
{
    int nVertex;

    fscanf(fp, "%d", &nVertex);

    return nVertex;
}

void mtrxFile(FILE* fp, int **mtrx, int nRow, int nCol)
{
    int i,j;
    for(j = 0; j < nRow; j++) {
        for(i = 0; i < nCol; i++) {
            if(fscanf(fp, "%d,", &mtrx[j][i]) != 1) {
                exit(1);
            }
        }  
    }
}

void createFile(char filename[MAX_LEN], int **mtrx, int nRow, int nCol,int nPath)
{
    char fileExname[MAX_LEN] = "jalur-";
    strcat(fileExname,filename);

    FILE* fp = fopen(fileExname, "w");

    int i,j;

    if (nPath > 0){
        for(i = 0; i < nRow; i++){
            for(j = nCol-1; j >= 0; j--){
                if (j != 0){
                    fprintf(fp, "%d-", mtrx[i][j]);
                }
                else{
                    fprintf(fp, "%d", mtrx[i][j]);
                }
            }

            fprintf(fp, "\n");
        }
    }
    else{
        fprintf(fp, "Tidak Ada Jalur Yang Memenuhi\n");
    }

    fclose(fp);
}
