# include  <stdio.h>
# include  <stdlib.h>
# include <time.h>
int sayac=0,hekza=0x7FCA,secim,anasecim,firmasecim,musterisecim,x,j=0,i=0,no,b_saat,v_saat,kisi_basi_ucret[100];
struct Otobus {
    int arac_kapasite [100];
    int arac_personel [100];
    int araclar [100];
    char arac_model [30];
    int arac_no [100];
} arac;
struct Sefer {
	int sefer_baslangic [100];
    int sefer_varis [100];
   	int sefer_no [6];
   	char sefer_b_sehri[100];
  	char sefer_v_sehri[100];
    char sefer_hasilat [100];

} sefer;
void Ana_Menu(){
    printf("\t1.FIRMA GIRISI\n");
    printf("\t2.MUSTERI GIRISI\n");
    printf("\t3.CIKIS\n");
    printf("\tLutfen bir giris yapiniz\n");
    scanf("%d",&anasecim);
    a_secim();
}
void Firma_Giris_Menusu(){
    printf("\t1.Otobus Ekle\n");
    printf("\t2.Sefer Bilgisi Ekle\n");
    printf("\t3.Sefer/Koltuk Bilgisi\n");
    printf("\t4.Bir Ust Menuye Don\n");
    scanf("%d",&firmasecim);
    f_secim();
}
void Musteri_Giris(){
    printf("\t1.Seferleri Listele\n");
    printf("\t2.Sefer Rezervasyon yap\n");
    printf ( "\t 3.Bir Ust Menuye Yapma \n" );
    printf ( "\t 4.Rezervasyon Goster \n" );
    scanf ( "%d" ,&musterisecim);
    m_secim();

}
void cikis(){
    system("cls");
    printf("Cikis Yapiliyor ...");
}
void a_secim(){
	switch(anasecim){
		case 1:
			system("cls");
			Firma_Giris_Menusu();

		case 2:
			system("cls");
			Musteri_Giris();

		case 3:
			system("cls");
        	Ana_Menu();
        default:
        	printf("\nHatali bir giris yaptiniz!!! Lutfen dogru bir giris yapiniz\n");
        	Ana_Menu();
	}
}
void f_secim(){
	if(firmasecim==1){
			system("cls");
			OtobusEkle ();
		}
		else if(firmasecim == 2){
            SeferBilgiEkle();
		}
		else if(firmasecim == 3){
            SeferKoltukBilgisi();
		}
		else if(firmasecim == 4){
            system("cls");
            Ana_Menu();
		}
		else{
            printf("Yanlis bir secim yaptiniz!!");
            system("cls");           //sonra istersek sileriz
            Ana_Menu();
		}
}
void m_secim(){
	if(musterisecim == 1){
            if(scanf("%d",&x)){
            	system("cls");
                seferListele();
            }
        }
        else if(musterisecim == 2){
            seferRezervasyonYap();
        }
        else if(musterisecim == 3){
            Ana_Menu();
        }
        else if(musterisecim == 4){
            RezervasyonGoster();
        }
        else {

        }
}
void  OtobusEkle (){

    printf("Otobunusun yolcu kapasitesini belirleyiniz  \n");
    scanf("%d",&arac.arac_kapasite[i]);
    printf("Otobunusun modelini belirleyiniz  \n");
    gets (arac.arac_model);
    arac.arac_no[i]=i+1;
    printf("\nGirdiginiz otobusun numarasi: %d\n",arac.arac_no[i]);
    printf("Otobusunuzde calisacak personel sayisini belirleyiniz\n");
    scanf("%d",&arac.arac_personel[i]);
    printf("Otobusunuzde calisacak personel sayisi: %d\n",arac.arac_personel[i]);
    //printf("%d\t%s\t%d\n",arac.arac_kapasite[i],arac.arac_model[i],arac.arac_personel[i]);
    printf("%d \n",arac.arac_kapasite[i]);
    printf(arac.arac_model);
    printf("%d \n",arac.arac_personel[i]);
    i++;
    Ana_Menu();
}
void SeferBilgiEkle(){

    sayac++;
    srand(time(NULL));
    hekza=10000+rand()%10050;
    sefer.sefer_no[j]=hekza;
    if(sayac>=2){
        if(sefer.sefer_no[j] == sefer.sefer_no[j--]){
            seferno();
        }
    }
  //  printf("---%X\n",sefer.sefer_no[j]);
    printf("Hangi otobusu kullanmak istiyorsaniz numarasini giriniz\n");
    scanf("%d",&no);
    printf("Sefer baslangic saatini giriniz\n");
    scanf("%d",&b_saat);
    if(b_saat >= 0025 && b_saat >= 2325){
        sefer.sefer_baslangic[j] = b_saat;
    }
    else{
        printf("Sefer bu saatte gerceklesemez.");
    }
   varisSaati();
    if(v_saat-b_saat >400 ){
        if(arac.arac_personel[j] == 2 && arac.arac_kapasite[j] <=30){
            printf("yanlis bir secim yaptiniz!!");
            varisSaati();
        }
    }
    else{
        sefer.sefer_varis[j] = v_saat;
    }
    printf("Seferin baslangic sehrini berlirleyiniz.\n");
    gets(sefer.sefer_b_sehri[j]);
    printf("---------%s\n",sefer.sefer_b_sehri[j]);
    printf("Seferin varis sehrini berlirleyiniz.\n");
    gets(sefer.sefer_v_sehri[j]);
    printf("Sefer inin istenilen toplam hasilati belirleyiniz.\n");
    scanf("%d",&sefer.sefer_hasilat[j]);
    kisi_basi_ucret[j] = sefer.sefer_hasilat[j]/arac.arac_kapasite[j];
    j++;
    Firma_Giris_Menusu();
}
void varisSaati(){
    printf("Sefer Varis saatinizi giriniz.\n");
    scanf("%d",sefer.sefer_varis[j]);
}
void seferno(){
    srand(time(NULL));
    hekza=10000+rand()%10050;
    sefer.sefer_no[j]=hekza;
}
void SeferKoltukBilgisi(){
    for(x=0; x<j; j++){
         printf("%d\n",arac.arac_no[j]);//sadece j yýde dene sonra
    }
    printf("istediðiniz seferin bilgilerini görmek için bir sefer numarasi seciniz.");
    scanf("%d",&secim);  // j indeksi yani arac noyu seciyor
    printf("Otobus no : %d",arac.arac_no[secim-1]);
    printf("Sefer no :25%d",sefer.sefer_no[secim]);
    printf("Sefer baslangic saati : %d",sefer.sefer_baslangic[secim-1]);
    printf("Sefer varis saati : %d",sefer.sefer_varis[secim-1]);
    //printf("Sefer baslangic sehri : %d",sefer_basehri);
   // printf("Sefer varis sehri : %d",sefer_varisehri);
    printf("Seferde istenilen toplam hasilat : %d",sefer.sefer_hasilat[secim-1]);
    printf("Seferde musteri basina düsen ücret : %d",kisi_basi_ucret[secim-1]);
    Firma_Giris_Menusu();
}
void seferListele(){

}
void seferRezervasyonYap(){

}
void RezervasyonGoster(){

}

int main()
{
	Ana_Menu();

    return  0 ;
}








