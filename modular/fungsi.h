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

typedef struct{
       char plat[15];
       char nama[20];
       char cc[5];
       char tahun[5];
}motor;

typedef struct{
       int dd;
       int mm;
       int yyyy;
}tanggal;

FILE *file;
data_diri arrpenyewaan[50];
motor arrmotor[50];
tanggal tgl_sewa;
tanggal tgl_kembali;

void tambah_motor();
void ganti_harga();
void Sewa();
void log_Sewa();
void pengembalian();
void tb_motor();
void edit_motor();
void hapus_motor();

#endif
