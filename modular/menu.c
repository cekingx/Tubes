#include <stdio.h>
#include <stdlib.h>
#include "fungsi.h"
#include "menu.h"

void penyewaan(){
       int menu;
       char again;
       system("clear");
       do{
              system("clear");
              judul_menu_penyewaan();
              printf("Menu (Penyewaan) : \n");
              printf("1. Sewa baru\n");
              printf("2. Log Penyewaan\n");
              printf("3. Pengembalian\n");
              printf("4. Keluar\n");
              printf("\n\n");
              printf("Pilih > ");scanf("%d",&menu);
              switch(menu){
                     case 1 :{
                            Sewa(); //fungsi.c
                            getchar();
                            printf("Kembali ke menu penyewaan?[y/t] > ");scanf("%c",&again);
                            //loading();
                            break;
                     }
                     case 2 :{
                            log_Sewa(); //fungsi.c
                            getchar();
                            printf("Kembali ke menu penyewaan?[y/t] > ");scanf("%c",&again);
                            //loading();
                            break;
                     }
                     case 3 :{
                            pengembalian();// fungsi.c
                            getchar();
                            printf("Kembali ke menu penyewaan?[y/t] > ");scanf("%c",&again);
                            //loading();
                            break;
                     }
                     case 4 :{
                            getchar();
                            again='t';
                            //loading();
                            break;
                     }
              }
       }while(again == 'y' || again == 'Y');
}

void db_motor(){
       int menu;
       char again;
       system("clear");
       do{
              system("clear");
              judul_database_motor();
              printf("Menu ( Database Sepeda Motor ) : \n");
              printf("1. Edit Motor\n");
              printf("2. Hapus Motor\n");
              printf("3. Keluar\n");
              printf("\n\n");
              printf("Pilih > ");scanf("%d",&menu);
              switch(menu){
                     case 1 :{
                            edit_motor(); //fungsi.c
                            getchar();
                            printf("\nKembali ke menu Database Sepeda Motor?[y/t] > ");scanf("%c",&again);
                            //loading();
                            break;
                     }
                     case 2 :{
                            hapus_motor(); //fungsi.c
                            getchar();
                            printf("\nKembali ke menu Database Sepeda Motor?[y/t] > ");scanf("%c",&again);
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
