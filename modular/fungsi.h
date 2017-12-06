#ifndef FUNGSI_H_
#define FUNGSI_H_

typedef struct{
       int dd;
       int mm;
       int yyyy;
}tanggal;

typedef struct{
       char plat[15];
       char nama[20];
       char cc[5];
       char tahun[5];
}motor;

typedef struct{
       char nama[20];
       char ID[20];
       char alamat[20];
       motor motor;
       int lama_sewa;
       int biaya;
       tanggal tgl_sewa;
       tanggal tgl_kembali;
}data_diri;



FILE *file;
data_diri arrpenyewaan[50];
motor arrmotor[50];

void tambah_motor();
//void ganti_harga();
void Sewa();
void log_Sewa();
void pengembalian();
void tb_motor();
void edit_motor();
void hapus_motor();
int lama_sewa(tanggal tgl_sewa, tanggal tgl_kembali);

#endif
