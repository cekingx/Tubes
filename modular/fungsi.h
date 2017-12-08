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
motor arrmotor[25];

void tambah_motor();
void ganti_harga();
void Sewa();
void log_Sewa();
void pengembalian();
void tb_motor();
void edit_motor();
void hapus_motor();
int lama_sewa(tanggal tgl_sewa, tanggal tgl_kembali);

void judul_menu_utama();
void judul_menu_penyewaan();
void judul_database_motor();
void judul_sewa();
void judul_log_sewa();
void judul_detail_log_sewa();
void judul_tabel_motor();
void judul_tambah_motor();
void judul_pengembalian();
void judul_edit_motor();
void judul_hapus_motor();
void judul_ganti_harga();

#endif
