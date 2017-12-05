#include <stdio.h>
#include <stdlib.h>

FILE *file;

int main(){
       char nama[20];

       printf("Masukkan Nama > ");scanf("%s",nama);
       if((file = fopen("dir_test/dir_test.txt","r")) == NULL){
              system("mkdir dir_test");
       }
       file = fopen("dir_test/dir_test.txt","a");
       fprintf(file,"%s\n",nama);
       fclose(file);
}
