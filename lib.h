/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
 *  Modul               : 9 - Tugas Besar
 *  Kelompok            : B7
 *  Hari dan Tanggal    : Rabu, 20 April 2022
 *  Asisten (NIM)       : Elkhan Julian Brillianshah
 *  Nama File           : lib.h
 *  Deskripsi           : Header file untuk fungsi utama.
 */

#include<stdio.h>
#include<stdlib.h>

/** nVertexFile. Mengambil nilai yang berupa banyaknya vertex pada file yang diinput.
 * 
 * @param mtrx matrix yang akan diatur ukurannya sesuai dengan besar nRow dan nCol yang diberikan.
 * @param nRow banyaknya baris pada mtrx.
 * @param nCol banyaknya kolom pada mtrx.
 * @return mtrx matrix dengan ukuran nRow x nCol.
 * 
 */
int** MtrxMalloc(int **mtrx, int nRow, int nCol);

/** freeMatrix. Membebaskan alokasi memori yang telah digunakan oleh matrix.
 * 
 * @param mtrx matrix yang akan dibebaskan alokasi memorinya.
 * @param nRow banyaknya baris pada mtrx.
 * 
 */
void freeMatrix(int **mtrx, int nRow);

/** main. Fungsi utama.
 * 
 */
int main();
