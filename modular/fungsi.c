#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fungsi.h"
#include "menu.h"

void Sewa(){
       char pilih;
       data_diri temp;
       system("clear");
       judul();

       printf("\n\nData Diri Pelanggan : \n\n");
       printf("Nama > ");scanf("%s",temp.nama);
       printf("No. KTP/SIM > ");scanf("%s",temp.ID);
       printf("Alamat > ");scanf("%s",temp.alamat);

       printf("\n\n Review Data Diri : \n\n");
       printf("Nama : %s\n",temp.nama);
       printf("No. KTP/SIM : %s\n",temp.ID);
       printf("Alamat : %s\n",temp.alamat);
       getchar();

       printf("\nApakah data tersebut sudah benar ?[y/t] > ");scanf("%c",&pilih);
       if(pilih == 'y' || pilih == 'Y'){
              file=fopen("nama.txt","a");
              fprintf(file,"%s\n",temp.nama);
              fclose(file);

              file=fopen("ID.txt","a");
              fprintf(file,"%s\n",temp.ID);
              fclose(file);

              file=fopen("alamat.txt","a");
              fprintf(file,"%s\n",temp.alamat);
              fclose(file);
       }
       else{
              Sewa();
       }
}

void log_Sewa(){
       system("clear");

       file=fopen("nama.txt","r");
       int i=0;
       while(fgets(arrpenyewaan[i].nama, 20, file)){
              arrpenyewaan[i].nama[strlen(arrpenyewaan[i].nama) -1 ]=' ' ; //menambahkan spasi di akhir string
              arrpenyewaan[i].nama[strlen(arrpenyewaan[i].nama) ]='\0' ;
              i++;
       }
       fclose(file);

       file=fopen("ID.txt","r");
       i=0;
       while(fgets(arrpenyewaan[i].ID, 20, file)){
              arrpenyewaan[i].ID[strlen(arrpenyewaan[i].ID) -1 ]=' ' ; //menambahkan spasi di akhir string
              arrpenyewaan[i].ID[strlen(arrpenyewaan[i].ID)  ]='\0' ;
              i++;
       }
       fclose(file);

       file=fopen("alamat.txt","r");
       i=0;
       while(fgets(arrpenyewaan[i].alamat, 20, file)){
              arrpenyewaan[i].alamat[strlen(arrpenyewaan[i].alamat) -1 ]=' ' ; //menambahkan spasi di akhir string
              arrpenyewaan[i].alamat[strlen(arrpenyewaan[i].alamat)  ]='\0' ;
              i++;
       }
       fclose(file);

       printf("+---+---------------------+------------------+--------------------------+\n");
       printf("| No|\t     Nama Penyewa |        ID        |          Alamat          |\n");
       printf("+---+---------------------+------------------+--------------------------+\n");
       for(int j=0;j<i;j++){
              printf("|%3d|%21s|%18s|%26s|",j+1,arrpenyewaan[j].nama,arrpenyewaan[j].ID,arrpenyewaan[j].alamat);
              printf("\n");
       }
       printf("+---+---------------------+------------------+--------------------------+\n\n");
}

