/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
 *  Modul               : 9 - Tugas Besar
 *  Kelompok            : B7
 *  Hari dan Tanggal    : Kamis, 20 April 2022
 *  Asisten (NIM)       : Elkhan Julian Brillianshah
 *  Nama File           : main.c
 *  Deskripsi           : Program untuk mencari semua kombinasi jalur yang terdapat pada Graphs tersebut lalu mencetak
jumlahnya pada layar. Selain itu, program juga akan menghasilkan file eksternal yang berisi seluruh
kombinasi jalur yang ada.
 */

#include "exfile_lib.c"
#include "findpath_lib.c"
#include "lib.h"

int** MtrxMalloc(int **mtrx, int nRow, int nCol){
	mtrx = (int**) malloc(nRow * sizeof(int*));

    int i;
	for (i = 0; i < nRow; i++){
   		mtrx[i] = (int*) malloc(nCol * sizeof(int));
    }  
    return mtrx;
}

void freeMatrix(int **mtrx, int nRow){
	int i;
	for (i = 0; i < nRow; i++){
		free(mtrx[i]);
	}

    free(mtrx);
}

int main() {
    char filename[MAX_LEN];
    printf("Masukkan Graphs: ");
	scanf("%s", filename);

    checkFile(filename); // Program akan langsung berakhir dan mengeluarkan pesan jika kondisi ini
    
    FILE* fp = fopen(filename, "r");

    int nVertex = nVertexFile(fp);

    int i;
    int **adjMtrx;

    adjMtrx = MtrxMalloc(adjMtrx, nVertex, nVertex);

    mtrxFile(fp, adjMtrx, nVertex,nVertex);

    fclose(fp);

    int vStart;
    printf("Masukkan Vertex Asal: ");
    scanf("%d", &vStart);
    while(vStart < 1 || vStart > nVertex){
        printf("\nVertex Asal Tidak Valid!\n");
        printf("Vertex Asal yang Valid adalah : 1 - %d\n", nVertex);
        printf("\nMasukkan Vertex Asal: ");
        scanf("%d", &vStart);
    }

    int vEnd;
    printf("Masukkan Vertex Tujuan: ");
    scanf("%d", &vEnd);
    while(vEnd < 1 || vEnd > nVertex){
        printf("\nVertex Tujuan Tidak Valid!\n");
        printf("Vertex Tujuan yang Valid adalah : 1 - %d\n", nVertex);
        printf("\nMasukkan Vertex Tujuan: ");
        scanf("%d", &vEnd);
    }

    int nEdges;
    printf("Masukkan Batas Edges: ");
    scanf("%d", &nEdges);

    int nPath = 0;
    countPath(&nPath, nVertex, nEdges, vStart-1, vEnd-1, adjMtrx);

    printf("\nBanyak Jalur: %d\n", nPath);

    printf("Jalur: \n");

    int **mtrxPath;

    if (nPath > 0){
        mtrxPath = MtrxMalloc(mtrxPath, nPath+1, nEdges+1);

        for (i = 0; i < nPath; i++){
            mtrxPath[i][nEdges] = vStart;
            mtrxPath[i][0] = vEnd;
        }

        int temp_nPath = 0;
        findPath(&temp_nPath, nPath, mtrxPath, nVertex, nEdges, vStart-1, vEnd-1, adjMtrx);

        printPath(nPath, nEdges+1, mtrxPath); 
    }

    else{
        printf("Tidak Ada Jalur Yang Memenuhi\n");
    }

    createFile(filename, mtrxPath, nPath, nEdges+1, nPath);

    freeMatrix(mtrxPath, nPath);

    freeMatrix(adjMtrx, nVertex);

	return 0;
}
