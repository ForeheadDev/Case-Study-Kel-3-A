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
 * datapegawai.c
 * Implementasi modul dari ADT Data Pegawai
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datapegawai.h"

void BuatDataPegawai(DataPegawai* D)
{
    /*
    * [Author]
    * Nama : Zahwa Putri Hamida
    * Nim  : 201524032
    * 
    * [Deskripsi]
    * Mengosongkan nilai dari stuktur data DataPegawai
    */
    D->root = NULL;
}
address BuatPegawai(int id, char* nama)
{
    /*
    * [Author]
    * Nama : M Rasyid Fadlurrahman
    * Nim  : 201524019
    * 
    * [Deskripsi]
    * Menghasilkan address hasil alokasi sebuah node
    * jika alokasi berhasil maka adress tidak NULL
    * P.id = id, P.nama = nama, P.right = NULL, P.left = NULL
    * Jika alokasi gagal maka akan mengembalikan nilai NULL
    */
    address P = (address)malloc(sizeof(Pegawai));
    if (P != NULL){
        P->id = id;
        strcpy(P->nama, nama);
        P->left = NULL;
        P->right = NULL;
    }

    return P;
}
address TambahPegawai(address* root, int value, char* nama)
{
    /*
    * [Author]
    * Nama : M Nabil Haritshah Away
    * Nim  : 201524018
    * 
    * [Deskripsi]
    * Menambahkan Pegawai pada DataPegawai
    */
    if ((*root) == NULL) //kondisi tree kosong
    {
        (*root) = BuatPegawai(value, nama);
        return *root;
    }

    if (value < (*root)->id)
        (*root)->left = TambahPegawai(&(*root)->left, value, nama);
    else if (value > (*root)->id)
        (*root)->right = TambahPegawai(&(*root)->right, value, nama);

    return *root;
}

address minIdPegawai(address pegawai)
{
    /*
    * [Author]
    * Nama : M Fauzi Rizki Hamdalah
    * Nim  : 201524015
    * 
    * [Deskripsi]
    * Mencari pegawai dengan id terkecil
    */
    address find = pegawai;

    // temukan pegawai yang paling kiri
    while (pegawai && pegawai->left != NULL)
        find = find->left;

    return find;
}
address HapusPegawai(address root, Pegawai pegawai)
{
    /*
    * [Author]
    * Nama : M Fauzi Rizki Hamdalah
    * Nim  : 201524015
    * 
    * [Deskripsi]
    * Mendealokasikan memori yang dipesan untuk menampung data Pegawai
    */   
    // base case
    if (root == NULL)
        return root;

    // Pegawai yang didelete ada di sebelah kiri
    if (pegawai.id < root->id)
        root->left = HapusPegawai(root->left, pegawai);

    // Pegawai yang didelete ada di sebelah kanan
    else if (pegawai.id > root->id)
        root->right = HapusPegawai(root->right, pegawai);

    // Pegawai yang didelete adalah root
    else
    {
        // Jika punya satu anak
        if (root->left == NULL)
        {
            address temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            address temp = root->left;
            free(root);
            return temp;
        }

        // jika memiliki dua anak

        // cari inorder successor
        Pegawai temp = *minIdPegawai(root->right);

        // pindahkan info inorder successor ke root
        root->id = temp.id;
        strcpy(root->nama, temp.nama);

        // delete in order successor
        root->right = HapusPegawai(root->right, temp);
    }

    return root;
}
void HapusSemuaPegawai(address* pegawai)
{
    /*
    * [Author]
    * Nama : Rafli Lutfiansyah Mauluddin
    * Nim  : 2015240
    * 
    * [Deskripsi]
    * Mendealokasikan semua Pegawai yang terdapat di dalam DataPegawai
    */
    if(*pegawai == NULL)
		return;
	HapusSemuaPegawai(&(*pegawai)->left);
	HapusSemuaPegawai(&(*pegawai)->right);
	free(*pegawai);
    *pegawai = NULL;
}
address CariPegawai(address root, int id)
{
    /*
    * [Author]
    * Nama : Hasanah
    * Nim  : 201524010
    * 
    * [Deskripsi]
    * Menemukan Pegawai pada DataPegawai berdasarkan id
    */
    while (root != NULL) {
        if (id < root->id)
            root = root->left;
        else if (id > root->id)
            root = root->right;
        else
            return root;
    }
    return root;
}
void PrintPegawaiPreOrder(address pegawai)
{
    /*
    * [Author]
    * Nama : M Fauzi Rizki Hamdalah
    * Nim  : 201524015
    * 
    * [Deskripsi]
    * Menampilkan seluruh Pegawai pada DataPegawai dengan ketentuan penampilan secara Pre-Order
    */
    if(pegawai == NULL)
    return;

    // print data pegawai
    printf("%d - %s\n", pegawai->id, pegawai->nama);

    // Telusuri anak kiri
    PrintPegawaiPreOrder(pegawai->left);

    // Telusuri anak kanan
    PrintPegawaiPreOrder(pegawai->right);
}
void PrintPegawaiPostOrder(address pegawai)
{
    /*
    * [Author]
    * Nama : Ihsan Fauzan Hanif
    * Nim  : 201524011
    * 
    * [Deskripsi]
    * Menampilkan seluruh Pegawai pada DataPegawai dengan ketentuan penampilan secara Post-Order
    */
    if (!pegawai) return;
    // Telusuri anak kiri
    PrintPegawaiPostOrder(pegawai->left);
    // Telusuri anak kanan
    PrintPegawaiPostOrder(pegawai->right);

	printf("%d - %s\n",pegawai->id,pegawai->nama);    
}
void PrintPegawaiInOrder(address pegawai)
{
    /*
    * [Author]
    * Nama : Rafli Lutfiansyah Mauluddin
    * Nim  : 2015240
    * 
    * [Deskripsi]
    * Menampilkan seluruh Pegawai pada DataPegawai dengan ketentuan penampilan secara In-Order
    */
    if(pegawai == NULL)
		return;
	PrintPegawaiInOrder(pegawai->left);
	printf("%d - %s\n",pegawai->id,pegawai->nama);
	PrintPegawaiInOrder(pegawai->right);
}