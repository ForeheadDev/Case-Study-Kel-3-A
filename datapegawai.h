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
address BuatPegawai(int id, char* nama);
void TambahPegawai(DataPegawai* D, address pegawai);
void HapusPegawai(DataPegawai* D, address pegawai);
void HapusSemuaPegawai(DataPegawai* D);
address CariPegawai(DataPegawai* D, int id);
void PrintPegawaiPreOrder(address pegawai);
void PrintPegawaiPostOrder(address pegawai);
void PrintPegawaiInOrder(address pegawai);

#endif
