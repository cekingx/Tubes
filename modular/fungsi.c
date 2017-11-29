#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fungsi.h"
#include "menu.h"

void Sewa(){
       char pilih;
       data_diri temp;
       system("clear");
       //judul "Penyewaan"

       printf("\n\nData Diri Pelanggan : \n\n");
       printf("Nama        > ");scanf("%s",temp.nama);
       printf("No. KTP/SIM > ");scanf("%s",temp.ID);
       printf("Alamat      > ");scanf("%s",temp.alamat);

       printf("\n\n Review Data Diri : \n\n");
       printf("Nama        : %s\n",temp.nama);
       printf("No. KTP/SIM : %s\n",temp.ID);
       printf("Alamat      : %s\n",temp.alamat);
       getchar();

       printf("\nApakah data tersebut sudah benar ?[y/t] > ");scanf("%c",&pilih);
       if(pilih == 'y' || pilih == 'Y'){
              file=fopen("nama_pelanggan.txt","a");
              fprintf(file,"%s\n",temp.nama);
              fclose(file);

              file=fopen("id_pelanggan.txt","a");
              fprintf(file,"%s\n",temp.ID);
              fclose(file);

              file=fopen("alamat_pelanggan.txt","a");
              fprintf(file,"%s\n",temp.alamat);
              fclose(file);
       }
       else{
              Sewa();
       }
}

void log_Sewa(){
       system("clear");

       file=fopen("nama_pelanggan.txt","r");
       int i=0;
       while(fgets(arrpenyewaan[i].nama, 20, file)){
              arrpenyewaan[i].nama[strlen(arrpenyewaan[i].nama) -1 ]=' ' ; //menambahkan spasi di akhir string
              arrpenyewaan[i].nama[strlen(arrpenyewaan[i].nama) ]='\0' ;
              i++;
       }
       fclose(file);

       file=fopen("id_pelanggan.txt","r");
       i=0;
       while(fgets(arrpenyewaan[i].ID, 20, file)){
              arrpenyewaan[i].ID[strlen(arrpenyewaan[i].ID) -1 ]=' ' ; //menambahkan spasi di akhir string
              arrpenyewaan[i].ID[strlen(arrpenyewaan[i].ID)  ]='\0' ;
              i++;
       }
       fclose(file);

       file=fopen("alamat_pelanggan.txt","r");
       i=0;
       while(fgets(arrpenyewaan[i].alamat, 20, file)){
              arrpenyewaan[i].alamat[strlen(arrpenyewaan[i].alamat) -1 ]=' ' ; //menambahkan spasi di akhir string
              arrpenyewaan[i].alamat[strlen(arrpenyewaan[i].alamat)  ]='\0' ;
              i++;
       }
       fclose(file);

       printf("+---+---------------------+------------------+--------------------------+\n");
       printf("| No|    Nama Penyewa     |        ID        |          Alamat          |\n");
       printf("+---+---------------------+------------------+--------------------------+\n");
       for(int j=0;j<i;j++){
              printf("|%3d|%21s|%18s|%26s|",j+1,arrpenyewaan[j].nama,arrpenyewaan[j].ID,arrpenyewaan[j].alamat);
              printf("\n");
       }
       printf("+---+---------------------+------------------+--------------------------+\n\n");
}

void tb_motor(){
       int i=0;
       file=fopen("nama_motor.txt","r");
       while(fgets(arrmotor[i].nama,20,file)){
              arrmotor[i].nama[strlen(arrmotor[i].nama) -1 ] = '\0';
              i++;
       }
       fclose(file);

       i=0;
       file=fopen("plat_motor.txt","r");
       while(fgets(arrmotor[i].plat,15,file)){
              arrmotor[i].plat[strlen(arrmotor[i].plat) -1 ] = '\0';
              i++;
       }
       fclose(file);

       i=0;
       file=fopen("cc_motor.txt","r");
       while(fgets(arrmotor[i].cc,5,file)){
              arrmotor[i].cc[strlen(arrmotor[i].cc) -1 ] = '\0';
              i++;
       }
       fclose(file);

       i=0;
       file=fopen("tahun_motor.txt","r");
       while(fgets(arrmotor[i].tahun,5,file)){
              arrmotor[i].tahun[strlen(arrmotor[i].tahun) -1 ] = '\0';
              i++;
       }
       fclose(file);

       printf("+---+----------------------+-----------------+-------+-------+");
       printf("| No|      Nama Motor      |       Plat      |  CC   | Tahun |");
       printf("+---+----------------------+-----------------+-------+-------+");
       for(int j=o;j<i;j++){
              printf("|%3d| %20s | %15s | %5s | %5s |",j+1, arrmotor[j].nama, arrmotor[j].plat, arrmotor[j].cc, arrmotor[j].tahun);
              printf("\n");
       }
       printf("+---+----------------------+-----------------+-------+-------+");
}

void tambah_motor(){
       char pilih;
       motor temp;
       system("clear");
       //judul "Tambah Motor"

       printf("\n\nTambah Sepeda Motor : ");
       printf("Nama Sepeda Motor > ");scanf("%s",temp.nama);
       printf("Plat Kendaraan    > ");scanf("%s",temp.plat);
       printf("Kapasitas Mesin   > ");scanf("%s",temp.cc);
       printf("Tahun Produksi    > ");scanf("%s",temp.tahun);

       printf("\n\nReview Data Sepeda Motor :\n\n");
       printf("Nama Sepeda Motor : %s\n",temp.nama);
       printf("Plat Kendaraan    : %s\n",temp.plat);
       printf("Kapasitas Mesin   : %s\n",temp.cc);
       printf("Tahun Produksi    : %s\n",temp.tahun);
       getchar();

       printf("\nApakah data tersebut sudah benar ?[y/t] > ");scanf("%c",&pilih);
       if(pilih == 'y' || pilih == 'Y'){
              file=fopen("nama_motor.txt","a");
              fprintf(file,"%s\n",temp.nama);
              fclose(file);

              file=fopen("plat_motor.txt","a");
              fprintf(file,"%s\n",temp.plat);
              fclose(file);

              file=fopen("cc_motor.txt","a");
              fprintf(file,"%s\n",temp.cc);
              fclose(file);

              file=fopen("tahun_motor.txt","a");
              fprintf(file,"%s\n",temp.tahun);
              fclose(file);
       }
       else{
              tambah_motor();
       }
}

