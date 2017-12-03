#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
       char input[20];
}freee;

void tambah();
void hapus();
void tb_bebas();

FILE *file;
freee bebas[5];

int main(){
       int menu;
       char again;

       do{
              printf("Menu :\n");
              printf("1. Tambah\n");
              printf("2. Show\n");
              printf("3. Hapus\n");
              printf("Pilih menu > ");scanf("%d",&menu);
              switch(menu){
                     case 1:{
                            tambah();
                            getchar();
                            break;
                     }
                     case 2:{
                            tb_bebas();
                            getchar();
                            break;
                     }
                     case 3:{
                            tb_bebas();
                            getchar();
                            printf("\n\n");
                            hapus();
                            getchar();
                            break;
                     }
              }
              printf("Ulang > ");scanf("%c",&again);
       }while(again == 'y' || again == 'Y');
       return 0;
}

void tambah(){
       system("clear");
       file=fopen("deltest.txt","a");
       for(int i=0;i<5;i++){
              getchar();
              printf("Tambah Data > ");scanf("%s",bebas[i].input);
              fprintf(file,"%s\n",bebas[i].input);
       }
       fclose(file);
}

void tb_bebas(){
       system("clear");
       int i = 0;
       file=fopen("deltest.txt","r");
       while(fgets(bebas[i].input,20,file)){
              bebas[i].input[strlen(bebas[i].input) - 1] = '\0';
              i++;
       }
       fclose(file);
       printf("+---+----------------------+\n");
       printf("| No|          Data        |\n");
       printf("+---+----------------------+\n");
       for(int j=0;j<i;j++){
              printf("|%3d| %20s |",j+1,bebas[j].input);
              printf("\n");
       }
       printf("+---+----------------------+\n");
}

void hapus(){
       int no;
       printf("Pilih no yang akan dihapus > ");scanf("%d",&no);

       int i = 0;
       file=fopen("deltest.txt","r");
       while(fgets(bebas[i].input,20,file)){
              bebas[i].input[strlen(bebas[i].input) - 1] = '\0';
              i++;
       }
       fclose(file);

       for(int j=no-1;j<i;j++){
              strcpy(bebas[j].input,bebas[j+1].input);
       }

       file=fopen("deltest.txt","w");
       for(int j=0;j<i-1;j++){
              fprintf(file,"%s\n",bebas[j].input);
       }
       fclose(file);
}
