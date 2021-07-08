#include "datapegawai.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void MenambahkanPegawai(DataPegawai *data);
void MenampilkanPegawai(DataPegawai data);
void MenghapusPegawai(DataPegawai *data);
void MencariPegawai(DataPegawai data);
int MainMenu();

int main()
{	
	DataPegawai data;
	int choice;
	
	BuatDataPegawai(&data);
	
	while(true)
	{
		choice = MainMenu();
		switch(choice)
		{
			case 0 :
				exit(0); 
				
			case 1 :
				MenambahkanPegawai(&data);
				break;
			
			case 2:
				MenampilkanPegawai(data);
				break;
				
			case 3:
				MenghapusPegawai(&data);
				break;
			
			case 4:
				MencariPegawai(data);
				break;
		}
	}
	
	return 0;
}

int MainMenu(){
    int menu = -1;
    while(true){
        system("cls");
        printf("[1] Tambah Data Pegawai Baru\n");
        printf("[2] Menampilkan Seluruh Data Pegawai\n");
        printf("[3] Hapus Data Pegawai\n");
        printf("[4] Cari Data Pegawai\n");
        printf("[0] Keluar Program\n");
        printf("INPUT :");
        if(scanf("%d",&menu) != 1){
            printf("input tidak sesuai!!!\n");
            system("pause");
        }    
        else{
            if(menu >= 0 && menu < 5)
                break;
            printf("Menu tidak tersedia!!!\n");
            system("pause");
        }
    }
    return menu;    
}

void MenambahkanPegawai(DataPegawai *data)
{
	Pegawai pegawai;
	
	printf("==========================\n");
	printf("Masukan Informasi Pegawai\n\n");
	
	printf("Id Pegawai : ");
	scanf("%d", &pegawai.id);
	
	fflush(stdin);
	printf("Nama       : ");
	scanf("%[^\n]", &pegawai.nama);
	
	data->root = TambahPegawai(data->root, pegawai.id, pegawai.nama);
	
	printf("\nData berhasil ditambahkan\n\n");
    system("pause");
}

void MenampilkanPegawai(DataPegawai data){
    int menu = -1;
    printf("\n==========================\n");
    if(data.root == NULL){
        printf("Tidak Ada Data\n");
        system("pause");
        return;
    } 
    printf("Pilih Urutan Tampilan: \n");
    printf("[1] PreOrder\n");
    printf("[2] PostOrder\n");
    printf("[3] InOrder\n");
    while(true){
        printf("INPUT : ");
        if(scanf("%d",&menu) != 1){
            printf("input tidak sesuai!!!\n");
            system("pause");
           }    
        else{
            if(menu >= 0 && menu < 4)
                break;
            printf("Menu tidak tersedia!!!\n");
            system("pause");
        }
    }
    switch(menu){
        case 1:
            PrintPegawaiPreOrder(data.root); break;
        case 2:
            PrintPegawaiPostOrder(data.root); break;
        case 3:
            PrintPegawaiInOrder(data.root); break;
    }
    printf("\n");
    system("pause");
}

void MenghapusPegawai(DataPegawai *data)
{
	Pegawai pegawai;
	
	printf("\n==========================\n");
	printf("Masukan Informasi ID Pegawai Yang Dihapus\n");
	
	printf("Id Pegawai : ");
	scanf("%d", &pegawai.id);
	
	bool status = false;
	data->root = HapusPegawai(data->root, pegawai, &status);
	
	if(status)
		printf("\nData Berhasil Dihapus");
	else
		printf("\nData tidak ditemukan, id: %d", pegawai.id);
	
	printf("\n");
    system("pause");
}

void MencariPegawai(DataPegawai data)
{
	int id;
	
	printf("\n==========================\n");
	printf("Masukan Informasi ID Pegawai Yang Dicari\n\n");
	
	printf("Id Pegawai : ");
	scanf("%d", &id);
	
	address find = CariPegawai(data.root, id);
	
	if(find != NULL)
		printf("Data Ditemukan:\nId Pegawai : %d\nNama       : %s\n\n", find->id, find->nama);
	else
		printf("Data tidak ditemukan\n\n");
	
	printf("\n");
    system("pause");
}