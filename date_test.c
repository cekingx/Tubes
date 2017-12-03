#include <stdio.h>

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
       char nama[30];
       char ID[20];
       char alamat[50];
       motor motor;
       int waktu_sewa;
       tanggal tgl_sewa;
       tanggal tgl_kembali;
}data_diri;

data_diri test;

int lama_sewa(tanggal tgl_sewa, tanggal tgl_kembali);

int main(){
       int temp;
       tanggal tgl_sewa, tgl_kembali;

       printf("Gunakan (spasi) sebagai pemisah, contoh 13 7 1999\n");
       printf("Tanggal sewa    > ");scanf("%d %d %d", &test.tgl_sewa.dd, &test.tgl_sewa.mm, &test.tgl_sewa.yyyy);
       printf("Tanggal kembali > ");scanf("%d %d %d", &test.tgl_kembali.dd, &test.tgl_kembali.mm, &test.tgl_kembali.yyyy);
       temp = lama_sewa(test.tgl_sewa, test.tgl_kembali);
       printf("Lama sewa adalah %d hari\n",temp);
}

int lama_sewa(tanggal tgl_sewa, tanggal tgl_kembali){
       int total1, total2, total;
       int bln1 = 0, bln2 = 0;
       int bln[]={31,28,31,30,31,30,31,31,30,31,30,31};
       int i;
       int j;

       if(tgl_sewa.mm==1){
              bln1=0;
       }
       else{
              for(i=0;i<tgl_sewa.mm-1;i++)
                     bln1=bln1+bln[i];
       }
       total1=bln1+tgl_sewa.dd;

       if(tgl_kembali.mm==1){
              bln2=0;
       }
       else{
              for(j=0;j<tgl_kembali.mm-1;j++)
                     bln2=bln2+bln[j];
       }
       total2=bln2+tgl_kembali.dd;

       total=((tgl_kembali.yyyy-tgl_sewa.yyyy)*365)+(total2-total1);
       return total;
}
