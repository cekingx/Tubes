#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct data_diri{
       char nama[30];
       char ID[20];
       char alamat[50];
       char motor[30];
       char tanggal_sewa[20];
       char tanggal_kembali[20];
}data_diri;

FILE *file;
struct data_diri arrpenyewaan[50];

void menu();
void Sewa();
void log_Sewa();
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
              printf("2. Log Penyewaan\n");
              printf("3. Keluar\n");
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
                            log_Sewa();
                            //getchar();
                            printf("Kembali ke menu ?[y/t] > ");scanf("%c",&again);
                            loading();
                            break;
                     }
                     case 3 :{
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

void log_Sewa(){
       system("clear");
       file=fopen("nama.txt","r");
       int i=0;
       while(fgets(arrpenyewaan[i].nama, 20, file)){
             arrpenyewaan[i].nama[strlen(arrpenyewaan[i].nama) -1 ]='\0' ;
              i++;
       }
       fclose(file);
       file=fopen("ID.txt","r");
       i=0;
       while(fgets(arrpenyewaan[i].ID, 20, file)){
             arrpenyewaan[i].ID[strlen(arrpenyewaan[i].ID) -1 ]='\0' ;
              i++;
       }
       fclose(file);
       file=fopen("alamat.txt","r");
       i=0;
       while(fgets(arrpenyewaan[i].alamat, 20, file)){
             arrpenyewaan[i].alamat[strlen(arrpenyewaan[i].alamat) -1]='\0' ;
              i++;
       }
       fclose(file);
       printf("+---+---------------------+------------------+--------------------------+\n");
       printf("| No|\t     Nama Penyewa |        ID        |          Alamat          |\n");
       printf("+---+---------------------+------------------+--------------------------+\n");
       for(int j=0;j<i;j++){
              printf("|%3d|%21s|%18s|%26s|",j+1,arrpenyewaan[j].nama,arrpenyewaan[j].ID,arrpenyewaan[j].alamat);
              /*printf("|%3d|",j+1);
              printf("%21s|",arrpenyewaan[j].nama);
              fflush(stdout);
              printf("%20s|",arrpenyewaan[j].ID);
              fflush(stdout);
              printf("%20s|",arrpenyewaan[j].alamat);
              fflush(stdout);*/
              printf("\n");
       }

}

void judul(){
       printf("\t\t\t   ========================");
       printf("\n\t\t\t   ||PROGRAM RENTAL MOTOR||");
       printf("\n\t\t\t   ========================\n\n");
}

void loading(){
       //sleep(2);
}
