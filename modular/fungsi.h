#ifndef FUNGSI_H_
#define FUNGSI_H_

typedef struct{
       char nama[30];
       char ID[20];
       char alamat[50];
       char motor[30];
       char tanggal_sewa[20];
       char tanggal_kembali[20];
}data_diri;

FILE *file;
data_diri arrpenyewaan[50];

void Sewa();
void log_Sewa();

#endif
