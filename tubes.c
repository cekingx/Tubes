#include <stdio.h>

typedef struct{
    int dd; //Date
    int mm; //Month
}Tanggal;

typedef struct {
    char Nama[20];
    char Asal[50];
    char Id[20];
    Tanggal pinjam;
}pelanggan;

//Variabel Global
pelanggan orang[3];//kuota 3 pelanggan
Tanggal kembali;

//Deklarasi fungsi dan prosedur
void Input(int i);
void Output(int j);
int Hitung(Tanggal awal,Tanggal akhir);

int main(){
    int i;
    int j;
    int hari;
    for(int n=0;n<3;n++){
        Input(n);
    }
    printf("Output : ");scanf("%d",&j);
    printf("Tanggal kembali : ");scanf("%d-%d",&(kembali.dd),&(kembali.mm));
    Output(j-1);
    hari=Hitung(orang[j-1].pinjam,kembali);
    printf("Dipinjam %d hari\n",hari );
    return 0;
}

void Input(int i){
    //while (getchar() != '\n');
        printf("Nama pelanggan ke %d : ",i+1);scanf("%s",&(orang[i].Nama));
        printf("Asal pelanggan ke %d : ",i+1);scanf("%s",&(orang[i].Asal));
        printf("Id   pelanggan ke %d : ",i+1);scanf("%s",&(orang[i].Id));
        printf("Tanggal pinjam      : ");scanf("%d-%d",&(orang[i].pinjam.dd),&(orang[i].pinjam.mm));
        printf("\n");
}

void Output(int j){
    printf("Nama pelanggan ke %d : %s\n",j+1,orang[j].Nama );
    printf("Asal pelanggan ke %d : %s\n",j+1,orang[j].Asal );
    printf("Id   pelanggan ke %d : %s\n",j+1,orang[j].Id );
    printf("Tanggal pinjam      : %d - %d - 2017\n",orang[j].pinjam.dd,orang[j].pinjam.mm);
}

int Hitung(Tanggal awal,Tanggal akhir){
    int total,total1,total2;
    int bln1 = 0;
    int bln2 = 0;
    int bln[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    if(awal.mm == 1){//Hitung tanggal peminjaman
        bln1=0;
    }
    else{
        for(int i =0;i<awal.mm-1;i++)
            bln1=bln1+bln[i];
    }
    total1=bln1+awal.dd;

    if(akhir.mm == 1){//Hitung tanggal pengembalian
        bln2=0;
    }
    else{
        for(int i =0;i<akhir.mm-1;i++)
            bln2=bln2+bln[i];
    }
    total2=bln2+akhir.dd;

    total=total2-total1;

    return total;
}
