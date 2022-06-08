/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
 *  Modul               : 9 - Tugas Besar
 *  Kelompok            : B7
 *  Hari dan Tanggal    : Rabu, 20 April 2022
 *  Asisten (NIM)       : Elkhan Julian Brillianshah
 *  Nama File           : exfile_lib.h
 *  Deskripsi           : Header file untuk library exfile.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 255

/** checkFile. Mengecek file.txt yang diinput apakah file tersebut valid, invalid, atau kosong, 
 * jika file kosong atau invalid maka program akan memberikan pesan bahwa file kosong atau invalid 
 * dan program langsung berakhir.
 * 
 * @param filename nama file yang telah diinput oleh user.
 * 
 */
void checkFile (char filename[MAX_LEN]);

/** nVertexFile. Mengambil nilai yang berupa banyaknya vertex pada file yang diinput.
 * 
 * @param fp File yang valid yang telah diinput oleh user.
 * @return nVertex banyaknya vertex yang terdapat pada file yang diinput.
 * 
 */
int nVertexFile (FILE* fp);

/** mtrxFile. Mengambil seluruh nilai yang berupa elemen matrix pada file yang diinput dan
 * menyimpannya pada matriks yang telah diinisialisasi. 
 * 
 * @param fp File yang valid yang telah diinput oleh user.
 * @param mtrx matrix untuk menyimpan nilai elemen matrix dari file yang diinput.
 * @param nRow banyaknya baris pada mtrx.
 * @param nCol banyaknya kolom pada mtrx.
 */
void mtrxFile(FILE* fp, int **mtrx, int nRow, int nCol);

/** createFile. Menambahkan file.txt baru yang berisi seluruh kombinasi jalur pada graphs.
 * 
 * @param filename nama untuk file baru yang akan ditambahkan.
 * @param mtrxPath matrix yang berisi seluruh kombinasi jalur pada graphs.
 * @param nRow banyaknya baris pada mtrxPath.
 * @param nCol banyaknya kolom pada mtrxPath.
 * @param nPath banyaknya jalur yang terdapat pada graphs yang diberikan.
 * 
 */
void createFile(char filename[MAX_LEN], int **mtrxPath, int nRow, int nCol, int nPath);

