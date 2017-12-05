#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "fungsi.h"

void menu();

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
              printf("Menu : \n");
              printf("1. Penyewaan\n");
              printf("2. Tambah Motor\n");
              printf("3. Database Motor\n");
              printf("4. Ganti Harga\n");
              printf("5. Keluar\n");
              printf("\n\n");
              printf("Pilih menu > ");scanf("%d",&menu);
              switch(menu){
                     case 1 :{
                            penyewaan(); //menu.c
                            //getchar();
                            printf("Kembali ke menu utama? [y/t] > ");scanf("%c",&again);
                            break;
                     }
                     case 2 :{
                            tambah_motor(); //fungsi.c
                            //getchar();
                            printf("Kembali ke menu utama? [y/t] > ");scanf("%c",&again);
                            break;
                     }
                     case 3 :{
                            db_motor(); //menu.c
                            //getchar();
                            printf("Kembali ke menu utama? [y/t] > ");scanf("%c",&again);
                            break;
                     }
                     case 4 :{
                            //ganti_harga(); //fungsi.c
                            //getchar();
                            printf("Kembali ke menu utama? [y/t] > ");scanf("%c",&again);
                            break;
                     }
                     case 5:{
                            getchar();
                            again = 't';
                            break;
                     }
              }

       }while( again == 'y' || again == 'Y' );
}
