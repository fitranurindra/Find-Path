/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
 *  Modul               : 9 - Tugas Besar
 *  Kelompok            : B7
 *  Hari dan Tanggal    : Rabu, 20 April 2022
 *  Asisten (NIM)       : Elkhan Julian Brillianshah
 *  Nama File           : findpath_lib.h
 *  Deskripsi           : Header file untuk library findpath.
 */

#include <stdio.h>
#include <stdlib.h>

/** countPath. Menghitung banyaknya jalur yang terdapat pada graphs yang diberikan.
 * 
 * @param count variabel untuk menyimpan nilai dari banyaknya jalur pada graphs yang diberikan.
 * @param nVertex banyaknya vertex yang terdapat pada graphs yang diberikan.
 * @param nEdges banyaknya edges yang telah diinput oleh user.
 * @param vStart vertex asal yang telah diinput oleh user.
 * @param vEnd vertex tujuan yang telah diinput oleh user.
 * @param mtrx adjacent matrix dari graphs yang telah diinput oleh user.
 * 
 */
void countPath(int *count, int nVertex, int nEdges, int vStart, int vEnd, int **mtrx);

/** findPath. Mencari seluruh kombinasi jalur yang terdapat pada graphs yang diberikan
 * dan hasilnya disimpan dalam sebuah matrix.
 * 
 * @param tempCount dummy variabel untuk mengecek apakah seluruh kombinasi jalur sudah tersimpan atau belum.
 * @param nPath banyaknya jalur yang terdapat pada graphs yang diberikan.
 * @param mtrxPath matrix untuk menyimpan seluruh kombinasi jalur yang terdapat pada graphs yang diberikan.
 * @param nVertex banyaknya vertex yang terdapat pada graphs yang diberikan.
 * @param nEdges banyaknya edges yang telah diinput oleh user.
 * @param vStart vertex asal yang telah diinput oleh user.
 * @param vEnd vertex tujuan yang telah diinput oleh user.
 * @param mtrx adjacent matrix dari graphs yang telah diinput oleh user.
 * 
 */
void findPath(int *tempCount, int nPath, int **mtrxPath, int nVertex, int nEdges, int vStart, int vEnd, int **mtrx);

/** printPath. Menampilkan seluruh kombinasi jalur yang terdapat pada graphs.
 * 
 * @param nRow banyaknya baris pada mtrxPath.
 * @param nCol banyaknya kolom pada mtrxPath.
 * @param mtrxPath matrix yang berisi seluruh kombinasi jalur pada graphs.
 * 
 */
void printPath(int nRow, int nCol, int **mtrxPath);

