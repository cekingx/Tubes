#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
       char nama[30];
       char ktp[30];
       char alamat[50];
}Penyewaan;

int indeks_sewa=0;
FILE *file;
Penyewaan arrsewa[50];

void input_data(int i);
void sewa_save_data();

int main(){
       sewa_save_data();
       printf("Thank You\n");

       return 0;
}

void input_data(int i){
       printf("Nama > ");scanf("%s",arrsewa[i].nama);
       printf("KTP > ");scanf("%s",arrsewa[i].ktp);
       printf("Alamat > ");scanf("%s",arrsewa[i].alamat);
}

void sewa_save_data(){
       char pilih;
       do{
              printf("Input data ?[y/t] > ");
              scanf("%c",&pilih);
              if(pilih == 'y' || pilih == 'Y'){
                     input_data(indeks_sewa);
                     indeks_sewa++;
              }
              else{
                     getchar();
                     break;
              }
       }while(pilih == 'y' || pilih == 'Y');
}
