#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fungsi.h"
#include "menu.h"

void Sewa(){
       char pilih;
       data_diri temp;
       int pilih_motor, harga;
       system("clear");
       tanggal tgl_sewa, tgl_kembali;
       //judul "Penyewaan"

       tb_motor();
       printf("\n\nData Diri Pelanggan : \n\n");
       printf("Nama            > ");scanf("%s",temp.nama);
       printf("No. KTP/SIM     > ");scanf("%s",temp.ID);
       printf("Alamat          > ");scanf("%s",temp.alamat);
       printf("Motor           > ");scanf("%d",pilih_motor);
       printf("Tanggal Sewa    > ");scanf("%d-%d-%d", &temp.tgl_sewa.dd, &temp.tgl_sewa.mm, &temp.tgl_sewa.yyyy);
       printf("Tanggal Kembali > ");scanf("%d-%d-%d", &temp.tgl_kembali.dd, &temp.tgl_kembali.mm, &temp.tgl_kembali.yyyy);

       temp.lama_sewa = lama_sewa(tgl_sewa, tgl_kembali);
       temp.biaya = harga*temp.lama_sewa;
       strcpy(temp.motor.nama, arrmotor[pilih_motor-1].nama);
       //temp.motor.nama = arrmotor[pilih_motor-1].nama;

       printf("\n\n Review Data Diri : \n\n");
       printf("Nama            : %s\n",temp.nama);
       printf("No. KTP/SIM     : %s\n",temp.ID);
       printf("Alamat          : %s\n",temp.alamat);
       printf("Motor           : %s\n",temp.motor.nama);
       printf("Tanggal Sewa    : %d-%d-%d \n", temp.tgl_sewa.dd, temp.tgl_sewa.mm, temp.tgl_sewa.yyyy);
       printf("Tanggal Kembali : %d-%d-%d \n", temp.tgl_kembali.dd, temp.tgl_kembali.mm, temp.tgl_kembali.yyyy);
       printf("Lama Sewa       : %d hari\n",temp.lama_sewa);
       printf("Biaya           : Rp %d \n",temp.biaya);
       getchar();

       printf("\nApakah data tersebut sudah benar ?[y/t] > ");scanf("%c",&pilih);
       if(pilih == 'y' || pilih == 'Y'){
              if((file=fopen("db_pelanggan/nama_pelanggan.txt","r"))==NULL){ // Membuat directory db_pelanggan
                     system("mkdir db_pelanggan");
                     fclose(file);
              }

              file=fopen("db_pelanggan/nama_pelanggan.txt","a"); //1. Nama Pelanggan
              fprintf(file,"%s\n",temp.nama);
              fclose(file);

              file=fopen("db_pelanggan/id_pelanggan.txt","a"); //2. ID Pelanggan
              fprintf(file,"%s\n",temp.ID);
              fclose(file);

              file=fopen("db_pelanggan/alamat_pelanggan.txt","a"); //3. Alamat Pelanggan
              fprintf(file,"%s\n",temp.alamat);
              fclose(file);

              file=fopen("db_pelanggan/motor_pelanggan.txt","a"); //4. Nama Motor
              fprintf(file,"%s\n",temp.motor.nama);
              fclose(file);

              file=fopen("db_pelanggan/tgl_sewa_pelanggan.txt","a"); //5. Tanggal Penyewaan
              fprintf(file,"%d-%d-%d\n",temp.tgl_sewa.dd, temp.tgl_sewa.mm, temp.tgl_sewa.yyyy);
              fclose(file);

              file=fopen("db_pelanggan/tgl_kembali_pelanggan.txt","a"); //6. Tanggal Pengembalin
              fprintf(file,"%d-%d-%d\n",temp.tgl_kembali.dd, temp.tgl_kembali.mm, temp.tgl_kembali.yyyy);
              fclose(file);

              file=fopen("db_pelanggan/lama_sewa_pelanggan.txt","a"); //7. Lama Sewa
              fprintf(file,"%d\n",temp.lama_sewa);
              fclose(file);

              file=fopen("db_pelanggan/biaya_pelanggan.txt","a"); //8. Biaya
              fprintf(file,"%d\n",temp.biaya);
              fclose(file);
       }
       else{
              Sewa();
       }
}

void log_Sewa(){
       system("clear");
       char detail_log;

       file=fopen("db_pelanggan/nama_pelanggan.txt","r"); //1. Nama Pelanggan
       int i=0;
       while(fgets(arrpenyewaan[i].nama, 20, file)){
              arrpenyewaan[i].nama[strlen(arrpenyewaan[i].nama) -1 ]='\0' ;
              i++;
       }
       fclose(file);

       file=fopen("db_pelanggan/id_pelanggan.txt","r"); //2. ID Pelanggan
       i=0;
       while(fgets(arrpenyewaan[i].ID, 20, file)){
              arrpenyewaan[i].ID[strlen(arrpenyewaan[i].ID) -1 ]='\0' ;
              i++;
       }
       fclose(file);

       file=fopen("db_pelanggan/alamat_pelanggan.txt","r"); //3. ALamat Pelanggan
       i=0;
       while(fgets(arrpenyewaan[i].alamat, 20, file)){
              arrpenyewaan[i].alamat[strlen(arrpenyewaan[i].alamat) -1 ]='\0' ;
              i++;
       }
       fclose(file);

       file=fopen("db_pelanggan/motor_pelanggan.txt","r"); //4. Nama Motor
       i=0;
       while(fgets(arrpenyewaan[i].motor.nama, 20, file)){
              arrpenyewaan[i].motor.nama[strlen(arrpenyewaan[i].motor.nama) -1 ]='\0' ;
              i++;
       }
       fclose(file);

       file=fopen("db_pelanggan/tgl_sewa_pelanggan.txt","r"); //5. Tanggal Penyewaan
       i=0;
       while(!feof(file)){
              fscanf(file,"%d-%d-%d", &arrpenyewaan[i].tgl_sewa.dd, &arrpenyewaan[i].tgl_sewa.mm, &arrpenyewaan[i].tgl_sewa.yyyy);
              i++;
       }
       fclose(file);

       file=fopen("db_pelanggan/tgl_kembali_pelanggan.txt","r"); //6. Tanggal Pengembalian
       i=0;
       while(!feof(file)){
              fscanf(file,"%d-%d-%d", &arrpenyewaan[i].tgl_kembali.dd, &arrpenyewaan[i].tgl_kembali.mm, &arrpenyewaan[i].tgl_kembali.yyyy);
              i++;
       }
       fclose(file);

       file=fopen("db_pelanggan/lama_sewa_pelanggan.txt","r"); //7. Lama Sewa
       i=0;
       while(!feof(file)){
              fscanf(file,"%d", &arrpenyewaan[i].lama_sewa);
              i++;
       }
       fclose(file);

       file=fopen("db_pelanggan/biaya_pelanggan.txt","r"); //8. Biaya
       i=0;
       while(!feof(file)){
              fscanf(file,"%d", &arrpenyewaan[i].biaya);
              i++;
       }
       fclose(file);


       printf("+---+----------------------+--------------+-----------------+-----------+------------+\n");
       printf("| No|    Nama Penyewa      | Tanggal Sewa | Tanggal Kembali | Lama Sewa |    Biaya   |\n");
       printf("+---+----------------------+--------------+-----------------+-----------+------------+\n");
       for(int j=0;j<i;j++){
              printf(
                     "|%3d| %20s |   %2d-%2d-%4d |      %2d-%2d-%4d | %3d Hari | Rp %7d |\n",
                     j+1,
                     arrpenyewaan[j].nama,
                     arrpenyewaan[j].tgl_sewa.dd, arrpenyewaan[j].tgl_sewa.mm, arrpenyewaan[j].tgl_sewa.yyyy,
                     arrpenyewaan[j].tgl_kembali.dd, arrpenyewaan[j].tgl_kembali.mm, arrpenyewaan[j].tgl_kembali.yyyy,
                     arrpenyewaan[j].lama_sewa,
                     arrpenyewaan[j].biaya
                     );
       }
       printf("+---+----------------------+--------------+-----------------+-----------+------------+\n\n");

       getchar();
       printf("Ingin Melihat Detail ?[y/t] > ");scanf("%c",detail_log);
       if ( detail_log == 'y' || detail_log == 'Y' ){
              printf("+---+----------------------+----------------------+----------------------+----------------------+\n");
              printf("| No|    Nama Penyewa      |          ID          |        Alamat        |      Nama Motor      |\n");
              printf("+---+----------------------+----------------------+----------------------+----------------------+\n");
              for(int j=0;j<i;j++){
              printf(
                     "|%3d| %20s | %20s | %20s | %20s |\n",
                     j+1,
                     arrpenyewaan[j].nama,
                     arrpenyewaan[j].ID,
                     arrpenyewaan[j].alamat,
                     arrpenyewaan[j].motor.nama
                     );
              }
              printf("+---+----------------------+----------------------+----------------------+----------------------+\n\n");
       }
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
       for(int j=0;j<i;j++){
              printf(
                     "|%3d| %20s | %15s | %5s | %5s |\n",
                     j+1,
                     arrmotor[j].nama,
                     arrmotor[j].plat,
                     arrmotor[j].cc,
                     arrmotor[j].tahun
                     );
       }
       printf("+---+----------------------+-----------------+-------+-------+");
}

void tambah_motor(){
       char pilih;
       motor temp;
       system("clear");
       //judul "Tambah Motor"

       printf("\n\nTambah Sepeda Motor : \n");
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
              if((file=fopen("db_motor/nama_motor.txt","r"))==NULL){ // Membuat directory db_motor
                     system("mkdir db_motor");
                     fclose(file);
              }

              file=fopen("db_motor/nama_motor.txt","a");
              fprintf(file,"%s\n",temp.nama);
              fclose(file);

              file=fopen("db_motor/plat_motor.txt","a");
              fprintf(file,"%s\n",temp.plat);
              fclose(file);

              file=fopen("db_motor/cc_motor.txt","a");
              fprintf(file,"%s\n",temp.cc);
              fclose(file);

              file=fopen("db_motor/tahun_motor.txt","a");
              fprintf(file,"%s\n",temp.tahun);
              fclose(file);
       }
       else{
              tambah_motor();
       }
}

void pengembalian(){
       system("clear");
       int hapus,j;
       char yakin;

       file=fopen("db_pelanggan/nama_pelanggan.txt","r"); //1. Nama Pelanggan
       int i=0;
       while(fgets(arrpenyewaan[i].nama, 20, file)){
              arrpenyewaan[i].nama[strlen(arrpenyewaan[i].nama) -1 ]='\0' ;
              i++;
       }
       fclose(file);

       file=fopen("db_pelanggan/id_pelanggan.txt","r"); //2. ID Pelanggan
       i=0;
       while(fgets(arrpenyewaan[i].ID, 20, file)){
              arrpenyewaan[i].ID[strlen(arrpenyewaan[i].ID) -1 ]='\0' ;
              i++;
       }
       fclose(file);

       file=fopen("db_pelanggan/alamat_pelanggan.txt","r"); //3. ALamat Pelanggan
       i=0;
       while(fgets(arrpenyewaan[i].alamat, 20, file)){
              arrpenyewaan[i].alamat[strlen(arrpenyewaan[i].alamat) -1 ]='\0' ;
              i++;
       }
       fclose(file);

       file=fopen("db_pelanggan/motor_pelanggan.txt","r"); //4. Nama Motor
       i=0;
       while(fgets(arrpenyewaan[i].motor.nama, 20, file)){
              arrpenyewaan[i].motor.nama[strlen(arrpenyewaan[i].motor.nama) -1 ]='\0' ;
              i++;
       }
       fclose(file);

       file=fopen("db_pelanggan/tgl_sewa_pelanggan.txt","r"); //5. Tanggal Penyewaan
       i=0;
       while(!feof(file)){
              fscanf(file,"%d-%d-%d", &arrpenyewaan[i].tgl_sewa.dd, &arrpenyewaan[i].tgl_sewa.mm, &arrpenyewaan[i].tgl_sewa.yyyy);
              i++;
       }
       fclose(file);

       file=fopen("db_pelanggan/tgl_kembali_pelanggan.txt","r"); //6. Tanggal Pengembalian
       i=0;
       while(!feof(file)){
              fscanf(file,"%d-%d-%d", &arrpenyewaan[i].tgl_kembali.dd, &arrpenyewaan[i].tgl_kembali.mm, &arrpenyewaan[i].tgl_kembali.yyyy);
              i++;
       }
       fclose(file);

       file=fopen("db_pelanggan/lama_sewa_pelanggan.txt","r"); //7. Lama Sewa
       i=0;
       while(!feof(file)){
              fscanf(file,"%d", &arrpenyewaan[i].lama_sewa);
              i++;
       }
       fclose(file);

       file=fopen("db_pelanggan/biaya_pelanggan.txt","r"); //8. Biaya
       i=0;
       while(!feof(file)){
              fscanf(file,"%d", &arrpenyewaan[i].biaya);
              i++;
       }
       fclose(file);


       printf("+---+----------------------+----------------------+----------------------+----------------------+------------+\n");
       printf("| No|    Nama Penyewa      |          ID          |        Alamat        |      Nama Motor      |    Biaya   |\n");
       printf("+---+----------------------+----------------------+----------------------+----------------------+------------+\n");
       for(j=0;j<i;j++){
              printf(
                     "|%3d| %20s | %20s | %20s | %20s | Rp %7d |\n",
                     j+1,
                     arrpenyewaan[j].nama,
                     arrpenyewaan[j].nama,
                     arrpenyewaan[j].ID,
                     arrpenyewaan[j].alamat,
                     arrpenyewaan[j].motor.nama,
                     arrpenyewaan[j].biaya
                     );
       }
       printf("+---+----------------------+--------------+-----------------+-----------+------------+\n\n");

       getchar();
       printf("Pilih nomor dari penyewa yang melakukan pengembalian > ");scanf("%d", &hapus);

       printf("\n\n Review Data Diri : \n\n");
       printf("Nama            : %s\n",arrpenyewaan[hapus].nama);
       printf("No. KTP/SIM     : %s\n",arrpenyewaan[hapus].ID);
       printf("Alamat          : %s\n",arrpenyewaan[hapus].alamat);
       printf("Motor           : %s\n",arrpenyewaan[hapus].motor.nama);
       printf("Tanggal Sewa    : %d-%d-%d \n", arrpenyewaan[hapus].tgl_sewa.dd, arrpenyewaan[hapus].tgl_sewa.mm, arrpenyewaan[hapus].tgl_sewa.yyyy);
       printf("Tanggal Kembali : %d-%d-%d \n", arrpenyewaan[hapus].tgl_kembali.dd, arrpenyewaan[hapus].tgl_kembali.mm, arrpenyewaan[hapus].tgl_kembali.yyyy);
       printf("Lama Sewa       : %d hari\n",arrpenyewaan[hapus].lama_sewa);
       printf("Biaya           : Rp %d \n",arrpenyewaan[hapus].biaya);
       getchar();

       printf("\nAnda yakin ?[y/t] > ");scanf("%c",yakin);
       if(yakin == 'y' || yakin == 'Y'){
              if((file=fopen("db_pelanggan/nama_pelanggan.txt","r")) == NULL){
                     printf("Gagal membuka file\n");
                     fclose(file);
              }

              file=fopen("db_pelanggan/nama_pelanggan.txt","r"); //1. Nama Pelanggan
              int i=0;
              while(fgets(arrpenyewaan[i].nama, 20, file)){
                     arrpenyewaan[i].nama[strlen(arrpenyewaan[i].nama) -1 ]='\0' ;
                     i++;
              }
              fclose(file);

              for(j=hapus-1;j<i;j++){
                     strcpy(arrpenyewaan[j].nama, arrpenyewaan[j+1].nama);
              }

              file=fopen("db_pelanggan/nama_pelanggan.txt","w");
              for(j=0;j<i-1;j++){
                     fprintf(file,"%s\n",arrpenyewaan[j].nama);
              }
              fclose(file);



              file=fopen("db_pelanggan/id_pelanggan.txt","r"); //2. ID Pelanggan
              i=0;
              while(fgets(arrpenyewaan[i].ID, 20, file)){
                     arrpenyewaan[i].ID[strlen(arrpenyewaan[i].ID) -1 ]='\0' ;
                     i++;
              }
              fclose(file);

              for(j=hapus-1;j<i;j++){
                     strcpy(arrpenyewaan[j].ID, arrpenyewaan[j+1].ID);
              }

              file=fopen("db_pelanggan/id_pelanggan.txt","w");
              for(j=0;j<i-1;j++){
                     fprintf(file,"%s\n",arrpenyewaan[j].ID);
              }
              fclose(file);



              file=fopen("db_pelanggan/alamat_pelanggan.txt","r"); //3. ALamat Pelanggan
              i=0;
              while(fgets(arrpenyewaan[i].alamat, 20, file)){
                     arrpenyewaan[i].alamat[strlen(arrpenyewaan[i].alamat) -1 ]='\0' ;
                     i++;
              }
              fclose(file);

              for(j=hapus-1;j<i;j++){
                     strcpy(arrpenyewaan[j].alamat, arrpenyewaan[j+1].alamat);
              }

              file=fopen("db_pelanggan/alamat_pelanggan.txt","w");
              for(j=0;j<i-1;j++){
                     fprintf(file,"%s\n",arrpenyewaan[j].alamat);
              }
              fclose(file);



              file=fopen("db_pelanggan/motor_pelanggan.txt","r"); //4. Nama Motor
              i=0;
              while(fgets(arrpenyewaan[i].motor.nama, 20, file)){
                     arrpenyewaan[i].motor.nama[strlen(arrpenyewaan[i].motor.nama) -1 ]='\0' ;
                     i++;
              }
              fclose(file);

              for(j=hapus-1;j<i;j++){
                     strcpy(arrpenyewaan[j].motor.nama, arrpenyewaan[j+1].motor.nama);
              }

              file=fopen("db_pelanggan/motor_pelanggan.txt","w");
              for(j=0;j<i-1;j++){
                     fprintf(file,"%s\n",arrpenyewaan[j].motor.nama);
              }
              fclose(file);



              file=fopen("db_pelanggan/tgl_sewa_pelanggan.txt","r"); //5. Tanggal Penyewaan
              i=0;
              while(!feof(file)){
                     fscanf(
                            file,
                            "%d-%d-%d",
                            &arrpenyewaan[i].tgl_sewa.dd,
                            &arrpenyewaan[i].tgl_sewa.mm,
                            &arrpenyewaan[i].tgl_sewa.yyyy
                            );
                     i++;
              }
              fclose(file);

              for(j = hapus-1;j<i;j++){
                     arrpenyewaan[j].tgl_sewa.dd = arrpenyewaan[j+1].tgl_sewa.dd;
                     arrpenyewaan[j].tgl_sewa.mm = arrpenyewaan[j+1].tgl_sewa.mm;
                     arrpenyewaan[j].tgl_sewa.yyyy = arrpenyewaan[j+1].tgl_sewa.yyyy;
              }

              file=fopen("db_pelanggan/tgl_sewa_pelanggan.txt","w");
              for(j=0;j<i-2;j++){
                     fprintf(
                            file,
                            "%d-%d-%d\n",
                            arrpenyewaan[j].tgl_sewa.dd,
                            arrpenyewaan[j].tgl_sewa.mm,
                            arrpenyewaan[j].tgl_sewa.yyyy
                            );
              }
              fclose(file);



              file=fopen("db_pelanggan/tgl_kembali_pelanggan.txt","r"); //6. Tanggal Pengembalian
              i=0;
              while(!feof(file)){
                     fscanf(
                            file,
                            "%d-%d-%d",
                            &arrpenyewaan[i].tgl_kembali.dd,
                            &arrpenyewaan[i].tgl_kembali.mm,
                            &arrpenyewaan[i].tgl_kembali.yyyy
                            );
                     i++;
              }
              fclose(file);

              for(j = hapus-1;j<i;j++){
                     arrpenyewaan[j].tgl_kembali.dd = arrpenyewaan[j+1].tgl_kembali.dd;
                     arrpenyewaan[j].tgl_kembali.mm = arrpenyewaan[j+1].tgl_kembali.mm;
                     arrpenyewaan[j].tgl_kembali.yyyy = arrpenyewaan[j+1].tgl_kembali.yyyy;
              }

              file=fopen("db_pelanggan/tgl_kembali_pelanggan.txt","w");
              for(j=0;j<i-2;j++){
                     fprintf(
                            file,
                            "%d-%d-%d\n",
                            arrpenyewaan[j].tgl_kembali.dd,
                            arrpenyewaan[j].tgl_kembali.mm,
                            arrpenyewaan[j].tgl_kembali.yyyy
                            );
              }
              fclose(file);



              file=fopen("db_pelanggan/lama_sewa_pelanggan.txt","r"); //7. Lama Sewa
              i=0;
              while(!feof(file)){
                     fscanf(file,"%d", &arrpenyewaan[i].lama_sewa);
                     i++;
              }
              fclose(file);

              for(j = hapus-1;j<i;j++){
                     arrpenyewaan[j].lama_sewa = arrpenyewaan[j+1].lama_sewa;
              }

              file=fopen("db_pelanggan/lama_sewa_pelanggan.txt","w");
              for(j=0;j<i-2;j++){
                     fprintf(file,"%d\n", arrpenyewaan[j].lama_sewa);
              }
              fclose(file);



              file=fopen("db_pelanggan/biaya_pelanggan.txt","r"); //8. Biaya
              i=0;
              while(!feof(file)){
                     fscanf(file,"%d", &arrpenyewaan[i].biaya);
                     i++;
              }
              fclose(file);

              for(j = hapus-1;j<i;j++){
                     arrpenyewaan[j].biaya = arrpenyewaan[j+1].biaya;
              }

              file=fopen("db_pelanggan/biaya_pelanggan.txt","w");
              for(j=0;j<i-2;j++){
                     fprintf(file,"%d\n", arrpenyewaan[j].biaya);
              }
              fclose(file);
       }
}

void edit_motor(){
       int pilih, i, j;
       motor temp;

       tb_motor();
       printf("\nPilih Motor Yang Akan Diedit > ");scanf("%d",pilih);
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

       i=0;
       file=fopen("db_motor/nama_motor.txt","r"); //1. Edit Nama
       while(fgets(arrmotor[i].nama, 20, file)){
              arrmotor[i].nama[strlen(arrmotor[i].nama) - 1] = '\0';
              i++;
       }
       fclose(file);

       strcpy(arrmotor[pilih-1].nama, temp.nama);

       file=fopen("db_motor/nama_motor.txt","w");
       for(j=0;j<i;j++){
              fprintf(file,"%s\n", arrmotor[j].nama);
       }
       fclose(file);


       i=0;
       file=fopen("db_motor/plat_motor.txt","r"); //2. Edit Plat
       while(fgets(arrmotor[i].plat, 20, file)){
              arrmotor[i].plat[strlen(arrmotor[i].plat) - 1] = '\0';
              i++;
       }
       fclose(file);

       strcpy(arrmotor[pilih-1].plat, temp.plat);

       file=fopen("db_motor/plat_motor.txt","w");
       for(j=0;j<i;j++){
              fprintf(file,"%s\n", arrmotor[j].plat);
       }
       fclose(file);


       i=0;
       file=fopen("db_motor/cc_motor.txt","r"); //3. Edit CC
       while(fgets(arrmotor[i].cc, 20, file)){
              arrmotor[i].cc[strlen(arrmotor[i].cc) - 1] = '\0';
              i++;
       }
       fclose(file);

       strcpy(arrmotor[pilih-1].cc, temp.cc);

       file=fopen("db_motor/cc_motor.txt","w");
       for(j=0;j<i;j++){
              fprintf(file,"%s\n", arrmotor[j].cc);
       }
       fclose(file);


       i=0;
       file=fopen("db_motor/tahun_motor.txt","r"); //4. Edit Tahun
       while(fgets(arrmotor[i].tahun, 20, file)){
              arrmotor[i].tahun[strlen(arrmotor[i].tahun) - 1] = '\0';
              i++;
       }
       fclose(file);

       strcpy(arrmotor[pilih-1].tahun, temp.tahun);

       file=fopen("db_motor/tahun_motor.txt","w");
       for(j=0;j<i;j++){
              fprintf(file,"%s\n", arrmotor[j].tahun);
       }
       fclose(file);
}

void hapus_motor(){
       int hapus;
       int i,j;
       char yakin;

       tb_motor();
       printf("Pilih Motor Yang Akan Dihapus > ");scanf("%d",&hapus);
       printf("Anda Yakin ?[y/t] > ");scanf("%c",yakin);

       if( yakin == 'y' || yakin == 'Y'){

              i=0;
              file=fopen("db_motor/nama_motor.txt","r"); //1. Hapus Nama
              while(fgets(arrmotor[i].nama, 20, file)){
                     arrmotor[i].nama[strlen(arrmotor[i].nama) - 1] = '\0';
                     i++;
              }
              fclose(file);

              for(j=hapus-1;j<i;j++){
                     strcpy(arrmotor[j].nama, arrmotor[j+1].nama);
              }

              file=fopen("db_motor/nama_motor.txt","w");
              for(j=0;j<i-1;j++){
                     fprintf(file,"%s\n", arrmotor[j].nama);
              }
              fclose(file);


              i=0;
              file=fopen("db_motor/plat_motor.txt","r"); //2. Hapus Plat
              while(fgets(arrmotor[i].plat, 20, file)){
                     arrmotor[i].plat[strlen(arrmotor[i].plat) - 1] = '\0';
                     i++;
              }
              fclose(file);

              for(j=hapus-1;j<i;j++){
                     strcpy(arrmotor[j].plat, arrmotor[j+1].plat);
              }

              file=fopen("db_motor/plat_motor.txt","w");
              for(j=0;j<i-1;j++){
                     fprintf(file,"%s\n", arrmotor[j].plat);
              }
              fclose(file);


              i=0;
              file=fopen("db_motor/cc_motor.txt","r"); //3. Hapus CC
              while(fgets(arrmotor[i].cc, 20, file)){
                     arrmotor[i].cc[strlen(arrmotor[i].cc) - 1] = '\0';
                     i++;
              }
              fclose(file);

              for(j=hapus-1;j<i;j++){
                     strcpy(arrmotor[j].cc, arrmotor[j+1].cc);
              }

              file=fopen("db_motor/cc_motor.txt","w");
              for(j=0;j<i-1;j++){
                     fprintf(file,"%s\n", arrmotor[j].cc);
              }
              fclose(file);


              i=0;
              file=fopen("db_motor/tahun_motor.txt","r"); //4. Hapus Tahun
              while(fgets(arrmotor[i].tahun, 20, file)){
                     arrmotor[i].tahun[strlen(arrmotor[i].tahun) - 1] = '\0';
                     i++;
              }
              fclose(file);

              for(j=hapus-1;j<i;j++){
                     strcpy(arrmotor[j].tahun, arrmotor[j+1].tahun);
              }

              file=fopen("db_motor/tahun_motor.txt","w");
              for(j=0;j<i-1;j++){
                     fprintf(file,"%s\n", arrmotor[j].tahun);
              }
              fclose(file);
       }

}

int lama_sewa(tanggal tgl_sewa, tanggal tgl_kembali){
       int total1, total2, total;
       int bln1 = 0, bln2 = 0;
       int bln[]={31,28,31,30,31,30,31,31,30,31,30,31};
       int i;
       int j;

       if(tgl_sewa.mm==1){
              bln1=0;
       }
       else{
              for(i=0;i<tgl_sewa.mm-1;i++)
                     bln1=bln1+bln[i];
       }
       total1=bln1+tgl_sewa.dd;

       if(tgl_kembali.mm==1){
              bln2=0;
       }
       else{
              for(j=0;j<tgl_kembali.mm-1;j++)
                     bln2=bln2+bln[j];
       }
       total2=bln2+tgl_kembali.dd;

       total=((tgl_kembali.yyyy-tgl_sewa.yyyy)*365)+(total2-total1);
       return total;
}


