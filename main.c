#include <stdio.h>
#include <stdlib.h>
#define max 10

FILE *cfile;

int main(void)
{
  dosyaYaz ();
  return 0;
}

void dosyaYaz(){
  char cevap,swap;
  int cevapa=0,cevapb=0,cevapc=0,cevapd=0,cevape=0,cevapbos=0;
  int i,j,kisi=0,toplam;
  char dizi[max][max];
  if ((cfile=fopen ("anket.txt","r"))==NULL)
      printf ("File cannot opened");
  else{
      printf ("Soru No  %%A\t%%B\t%%C\t%%D\t%%E\t%%BOS\n");
      printf ("_______  _\t_\t_\t_\t_\t___\n");
      fscanf(cfile,"%c",&cevap);
      while (!feof(cfile)){
        for (i=0;i<6;i++){
            for (j=0;j<10;j++){
                if (cevap!='\n')
                    dizi[i][j]=cevap;
                else
                    j--;
                fscanf(cfile,"%c",&cevap);
                }
            kisi++;
             }
        }
        fclose(cfile);
        for (j=0;j<10;j++){
            for (i=0;i<kisi;i++){
                swap=dizi[i][j];
                if (swap=='a')
                    cevapa++;
                if (swap=='b')
                    cevapb++;
                if (swap=='c')
                    cevapc++;
                if (swap=='d')
                    cevapd++;
                if (swap=='e')
                    cevape++;
                if (swap==' ')
                    cevapbos++;
                toplam=cevapa+cevapb+cevapc+cevapd+cevape+cevapbos;
        }
            printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d",j+1,100*cevapa/toplam,100*cevapb/toplam,100*cevapc/toplam,100*cevapd/toplam,100*cevape/toplam,100*cevapbos/toplam);
            cevapa=0,cevapb=0,cevapc=0,cevapd=0,cevape=0,cevapbos=0,toplam=0;
        }
    }
    printf("\nKisi Sayisi=%d",kisi);
}
