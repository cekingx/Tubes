#include <stdio.h>
#include <stdlib.h>
#include "fungsi.h"
#include "menu.h"

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
                            //loading();
                            break;
                     }
                     case 2 :{
                            getchar();
                            log_Sewa();
                            printf("Kembali ke menu ?[y/t] > ");scanf("%c",&again);
                            //loading();
                            break;
                     }
                     case 3 :{
                            getchar();
                            again='t';
                            //loading();
                            break;
                     }
              }
       }while(again == 'y' || again == 'Y');
}

void judul(){
       printf("\t\t\t   ========================");
       printf("\n\t\t\t   ||PROGRAM RENTAL MOTOR||");
       printf("\n\t\t\t   ========================\n\n");
}
