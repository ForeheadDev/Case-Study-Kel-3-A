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

	address root = TambahPegawai(&D.root, 15, "a");
	root = TambahPegawai(&D.root, 11, "a");
	root = TambahPegawai(&D.root, 51, "a");
	root = TambahPegawai(&D.root, 69, "a");
	root = TambahPegawai(&D.root, 67, "a");
	root = TambahPegawai(&D.root, 65, "a");
	root = TambahPegawai(&D.root, 91, "a");
	root = TambahPegawai(&D.root, 80, "a");
	PrintPegawaiPreOrder(D.root);


	return 0;
}

