/**
 * Kelompok 3
 * 
 * Anggota:
 * Hafiz M A    - 201524009
 * Hasanah      - 201524010
 * Ihsan F H    - 201524011
 * Khansa R     - 201524012
 * M Fauzi R H  - 201524015
 * M Fikri H    - 201524016
 * M Nabil H A  - 201524018
 * M Rasyid F   - 201524019
 * Rafli L M    - 201524021
 * Zahwa Putri  - 201524032
 * 
 * datapegawai.h
 * Abstract Data Type - Data Pegawai
 */

#ifndef __DATA_PEGAWAI_H__
#define __DATA_PEGAWAI_H__

typedef struct _Pegawai* address;
typedef struct _Pegawai {
    int id;
    char nama[50];
    address right;
    address left;
} Pegawai;

typedef struct _DataPegawai {
    address root;
} DataPegawai;

void BuatDataPegawai(DataPegawai* D);
/*
 * [Author]
 * Nama : Zahwa Putri Hamida
 * Nim  : 201524032
 * 
 * [Deskripsi]
 * Mengosongkan nilai dari stuktur data DataPegawai
 */

address BuatPegawai(int id, char* nama);
/*
 * [Author]
 * Nama : Zahwa Putri Hamida
 * Nim  : 201524032
 * 
 * [Deskripsi]
 * Mengalokasikan memori untuk menampung data pegawai
 */

address TambahPegawai(address *root, int value, char* nama);
/*
 * [Author]
 * Nama : M Nabil Haritshah Away
 * Nim  : 201524018
 * 
 * [Deskripsi]
 * Menambahkan Pegawai pada DataPegawai
 */

address minIdPegawai(address pegawai);
/*
 * [Author]
 * Nama : M Fauzi Rizki Hamdalah
 * Nim  : 201524015
 * 
 * [Deskripsi]
 * Mencari pegawai dengan id terkecil
 */

address HapusPegawai(address root, Pegawai pegawai);
/*
 * [Author]
 * Nama : M Fauzi Rizki Hamdalah
 * Nim  : 201524015
 * 
 * [Deskripsi]
 * Mendealokasikan memori yang dipesan untuk menampung data Pegawai
 */

void HapusSemuaPegawai(address* pegawai);
/*
 * [Author]
 * Nama : Rafli Lutfiansyah Mauluddin
 * Nim  : 2015240
 * 
 * [Deskripsi]
 * Mendealokasikan semua Pegawai yang terdapat di dalam DataPegawai
 */

address CariPegawai(address root, int id);
/*
 * [Author]
 * Nama : Hasanah
 * Nim  : 201524010
 * 
 * [Deskripsi]
 * Menemukan Pegawai pada DataPegawai berdasarkan id
 */

void PrintPegawaiPreOrder(address pegawai);
/*
 * [Author]
 * Nama : M Fauzi Rizki Hamdalah
 * Nim  : 201524015
 * 
 * [Deskripsi]
 * Menampilkan seluruh Pegawai pada DataPegawai dengan ketentuan penampilan secara Pre-Order
 */

void PrintPegawaiPostOrder(address pegawai);
/*
 * [Author]
 * Nama : Ihsan Fauzan Hanif
 * Nim  : 201524011
 * 
 * [Deskripsi]
 * Menampilkan seluruh Pegawai pada DataPegawai dengan ketentuan penampilan secara Post-Order
 */

void PrintPegawaiInOrder(address pegawai);
/*
 * [Author]
 * Nama : Rafli Lutfiansyah Mauluddin
 * Nim  : 2015240
 * 
 * [Deskripsi]
 * Menampilkan seluruh Pegawai pada DataPegawai dengan ketentuan penampilan secara In-Order
 */

#endif
