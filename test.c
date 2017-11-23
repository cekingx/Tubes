#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct{
       char nama[30];
       char ID[20];
       char alamat[50];
       char motor[30];
       char tanggal_sewa[20];
       char tanggal_kembali[20];
}data_diri;

FILE *file;

void menu();
void Sewa();
void judul();
void loading();

int main(){
       menu();
       printf("Terima Kasih\n");
       return 0;
}

void menu(){
       int menu;
       char again;
       system("clear");
       do{
              system("clear");
              judul();
              printf("Pilih Menu : \n");
              printf("1. Sewa baru\n");
              printf("2. Keluar\n");
              printf("Pilih > ");scanf("%d",&menu);
              switch(menu){
                     case 1 :{
                            Sewa();
                            getchar();
                            printf("Kembali ke menu ?[y/t] > ");scanf("%c",&again);
                            loading();
                            break;
                     }
                     case 2 :{
                            getchar();
                            again='t';
                            loading();
                            break;
                     }
              }
       }while(again == 'y' || again == 'Y');

}

void Sewa(){
       char pilih;
       system("clear");
       judul();

       printf("\n\nData Diri Pelanggan : \n\n");
       printf("Nama > ");scanf("%s",data_diri.nama);
       printf("No. KTP/SIM > ");scanf("%s",data_diri.ID);
       printf("Alamat > ");scanf("%s",data_diri.alamat);

       printf("\n\n Review Data Diri : \n\n");
       printf("Nama : %s\n",data_diri.nama);
       printf("No. KTP/SIM : %s\n",data_diri.ID);
       printf("Alamat : %s\n",data_diri.alamat);
       getchar();

       printf("\nApakah data tersebut sudah benar ?[y/t] > ");scanf("%c",&pilih);
       if(pilih == 'y' || pilih == 'Y'){
              file=fopen("nama.txt","a");
              fprintf(file,"%s\n",data_diri.nama);
              fclose(file);

              file=fopen("ID.txt","a");
              fprintf(file,"%s\n",data_diri.ID);
              fclose(file);

              file=fopen("alamat.txt","a");
              fprintf(file,"%s\n",data_diri.alamat);
              fclose(file);
       }
       else{
              Sewa();
       }
}

void judul(){
       printf("\t\t\t   ========================");
       printf("\n\t\t\t   ||PROGRAM RENTAL MOTOR||");
       printf("\n\t\t\t   ========================\n\n");
}

void loading(){
       sleep(2);
}
