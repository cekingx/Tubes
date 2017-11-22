#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *file;
typedef struct{
       int tanggal;
       int bulan;
       int tahun;
}Date;

typedef struct{
       char nama[30];
       char no_ktp[30];
       char alamat[50];
       Date tanggal_sewa;
       Date tanggal_kembali;
}Penyewa;

Penyewa penyewa[100];

void sewa();
char con_tanggal();

int main(){
       char str1[10],str2[10];
       int i=0,j,str;
       do{
              strcpy(str1,"0");
              printf("Masukkan nama : "); gets_s(penyewa[i].nama,20);
              printf("Masukkan no_ktp : "); gets_s(penyewa[i].no_ktp,20);
              printf("Masukkan alamat : "); gets_s(penyewa[i].alamat,20);
              sewa(i);
              i++;
              j=strcmp(penyewa[i].nama,str1);
              itoa(j,str2,10);
              str=strcmp(str1,str2);
       }while(str!=0);

       return 0;
}

void sewa(int i){
       file=fopen("Database/sewa.txt","a+");
       if (file == NULL){
              printf("Error");
       }
       else{
              fprintf(file, "%s\t%s\t%s\t",penyewa[i].nama, penyewa[i].no_ktp, penyewa[i].alamat);
       }
       fclose(file);
}
