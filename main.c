#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int x,i=0,j, sayac, secim, bassaat,varissaat, anasecim, firmasecim, musterisecim ,  kisi_basi_ucret[100] ;
char sefer_basehri,sefer_varisehri;

struct Otobus{
    int arac_kapasite[100];
    int arac_personel[100];
    int araclar[100];
    char arac_model[30];
    int arac_no[100];


}arac;
struct Sefer{
    int sefer_bassaat[100];
    int sefer_varis[100];
   int sefer_no[5] ;
   char sefer_basehri;
   char sefer_varisehri;
    char sefer_hasilat[100];

}sefer;
void Ana_Menu()
{
    printf("\t1.FIRMA GIRISI\n");
    printf("\t2.MUSTERI GIRISI\n");
    printf("\t3.CIKIS\n");
    printf("\tLutfen bir giris yapiniz\n");
    scanf("%d",&anasecim);
}
void Firma_Giris_Menusu()
{
    printf("\t1.Otobus Ekle\n");
    printf("\t2.Sefer Bilgisi Ekle\n");
    printf("\t3.Sefer/Koltuk Bilgisi\n");
    printf("\t4.Bir Ust Menuye Don\n");
    scanf("%d",&firmasecim);
}
void Musteri_Giris()
{
    printf("\t1.Seferleri Listele\n");
    printf("\t2.Sefer Rezervasyon yap\n");
    printf("\t3.Bir Ust Menuye Don\n");
    printf("\t4.Rezervasyon Goster\n");
    scanf("%d",&musterisecim);

}


void OtobusEkle()
{

    printf("Otobunusun yolcu kapasitesini belirleyiniz  \n");
    scanf("%d",&arac.arac_kapasite[i]);
    printf("Otobunusun modelini belirleyiniz  \n");
    scanf ("%s",&arac.arac_model[i]);
    arac.arac_no[i]=i+1;
           // printf("Girdiğiniz otobusun numarası: %d",oto_no);
    printf("Otobusunuzde calisacak personel sayisini belirleyiniz  ");
    scanf("%d",&arac.arac_personel[i]);
    i++;

}
void SeferBilgiEkle()
{
   /* srand(time(NULL));
    for(k=2; k<6; k++){
        sefer_no[k]=rand()%;
    }*/
    printf("Hangi otobusu kullanmak istiyorsaniz numarasini giriniz\n");
    scanf("%d",&j);
    printf("Sefer baslangic saatini giriniz\n");
    scanf("%d",&bassaat);
    if(bassaat >= 0025 && bassaat >= 2325){
        sefer.sefer_bassaat[j] = bassaat;
    }
    else{
        printf("Sefer bu saatte gerceklesemez.");
    }
    varisaati();
    if(varissaat-bassaat >400 ){
        if(arac.arac_personel[j] == 2 && arac.arac_kapasite[j] <=30){
           printf("yanlis bir secim yaptiniz!!");
           varisaati();
        }
    }
    else{
        sefer.sefer_varis[j] = varissaat;
    }

    printf("Seferin baslangic sehrini berlirleyiniz.\n");
    gets(sefer_basehri);
    printf("Seferin varis sehrini berlirleyiniz.\n");
    gets(sefer_varisehri);
    printf("Sefer inin istenilen toplam hasilati belirleyiniz.\n");
    scanf("%d",&sefer.sefer_hasilat[j]);
    kisi_basi_ucret[j] = sefer.sefer_hasilat[j]/arac.arac_kapasite[j];
    j++;
    Firma_Giris_Menusu();
}
void varisaati()
{
    printf("Sefer varis saatini giriniz\n");
    scanf("%d",&varissaat);
}
/*void seferno()
{
    srand(time(NULL));
    for(k=2; k<6; k++){
        sefer_no[k]=rand()%;
    }
}*/
void SeferKoltukBilgisi()
{
    for(sayac=0; sayac<j; j++){
         printf("%d\n",arac.arac_no[j]);//sadece j yıde dene sonra
    }
    printf("istediğiniz seferin bilgilerini görmek için bir sefer numarasi seciniz.");
    scanf("%d",&secim);  // j indeksi yani arac noyu seciyor
    printf("Otobus no : %d",arac.arac_no[secim-1]);
   // printf("Sefer no : %d",sefer_no[secim]);
    printf("Sefer baslangic saati : %d",sefer.sefer_bassaat[secim-1]);
    printf("Sefer varis saati : %d",sefer.sefer_varis[secim-1]);
    //printf("Sefer baslangic sehri : %d",sefer_basehri);
   // printf("Sefer varis sehri : %d",sefer_varisehri);
    printf("Seferde istenilen toplam hasilat : %d",sefer.sefer_hasilat[secim-1]);
    printf("Seferde musteri basina düsen ücret : %d",kisi_basi_ucret[secim-1]);
    Firma_Giris_Menusu();


}

int main()
{
     // otono i+1 kadar

    Ana_Menu();
    switch(anasecim){
        case 1:
        system("cls");
        Firma_Giris_Menusu();
        if(firmasecim == 1){
            OtobusEkle();
        }
        else if (firmasecim == 2){
            SeferBilgiEkle();
        }
        else if (firmasecim == 3){
            SeferKoltukBilgisi();
        }
        else if (firmasecim == 4){
            system("cls");
            Ana_Menu();
        }


    case 2:
        Musteri_Giris();
        if(musterisecim == 1){
            if(scanf("%d",&x)){
                Musteri_Giris();
            }
        }
        else if(musterisecim == 2){

        }
        else if(musterisecim == 3){

        }
        else if(musterisecim == 4){

        }
        else {

        }


    case 3:
        Ana_Menu();

    default:
        printf("Hatali bir giris yaptiniz!!! Lutfen dogru bir giris yapiniz\n");
        Ana_Menu();
    }


void Ana_Menu()
{
    printf("\t1.FIRMA GIRISI\n");
    printf("\t2.MUSTERI GIRISI\n");
    printf("\t3.CIKIS\n");
    printf("\tLutfen bir giris yapiniz\n");
    scanf("%d",&anasecim);
}
void Firma_Giris_Menusu()
{
    printf("\t1.Otobus Ekle\n");
    printf("\t2.Sefer Bilgisi Ekle\n");
    printf("\t3.Sefer/Koltuk Bilgisi\n");
    printf("\t4.Bir Ust Menuye Don\n");
    scanf("%d",&firmasecim);
}
void Musteri_Giris()
{
    printf("\t1.Seferleri Listele\n");
    printf("\t2.Sefer Rezervasyon yap\n");
    printf("\t3.Bir Ust Menuye Don\n");
    printf("\t4.Rezervasyon Goster\n");
    scanf("%d",&musterisecim);

}


    return 0;
}
