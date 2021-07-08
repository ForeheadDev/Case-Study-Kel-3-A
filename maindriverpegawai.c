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
 * maindriverpegawai.h
 * Main Driver dari ADT Data Pegawai
 */

#include <stdio.h>
#include <stdlib.h>
#include "datapegawai.h"

int main()
{
	DataPegawai D;
	BuatDataPegawai(&D);

	address root = TambahPegawai(&D.root, 1, "test");
	address rootsd12a = TambahPegawai(&D.root, 7, "test6");
	address rootsda = TambahPegawai(&D.root, 6, "test6");
	address root2 = TambahPegawai(&D.root, 4, "test4");
	address root3 = TambahPegawai(&D.root, -1, "test-1");
	address root4 = TambahPegawai(&D.root, -2, "test-2");

	address p = CariPegawai(D.root, 6);
	HapusPegawai(D.root, *p);
	PrintPegawaiInOrder(D.root);


	return 0;
}

