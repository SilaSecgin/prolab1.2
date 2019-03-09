#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char *al;
char *giris[10];  /// .giris YÇYNDEKY VERYLER ///
char *deger2[30]; /// YLK DOSYA YÇYNDEKY DE?ERLER ///
char *cikis[20];   /// .cikis YÇYNDEKY VERYLER ///
char *kapi[25];  /// .kapi-1 YÇYNDEKY VERYLER ///
char *kapi2[25];  /// .kapi-2 YÇYNDEKY VERYLER ///
char *kapi3[25]; /// .kapi-3 YÇYNDEKY VERYLER ///
char *kapi4[25]; /// .kapi-4 YÇYNDEKY VERYLER ///
char *baskaDosya[10]; /// .baskadosya VAR YSE YSMYNY YÇYNE YAZIYOR ///
char *degerler[30];  /// A B C DE?Y?YSEN BURADA TUTUYOR ///
char *son[10];
char *komut[30];
char *giris2[10];
time_t t;
struct tm *zaman_bilgisi;





int main(){
    char Hal,Lal,Gal;

    while(1){
        printf(">");
        scanf("%s",&al);


        if (al=='y' || al =='Y') {yukle();}

        if (al=='i' || al =='I') ilklendir();

        if (al=='h' || al =='H') {

                printf("H <");
                scanf("%s",&Hal);
                Lojik1H(&Hal);      }

        if (al=='l' || al =='L') {
                printf("L <");
                scanf("%s",&Lal);
                Lojik1L(&Lal);  }

        if (al=='s' || al =='S')  simule();

        if (al=='g' || al =='G') {

                printf("G <");
                scanf("%s",&Gal);
                GalGoster(&Gal);  }

        if (al=='u*' || al =='u') GalTumGoster(); /// G* olduğunu görmüyor

        if(al=='k' || al =='K') Komut();

        if (al=='c' || al =='C') return 0;

    }

   return 0;


}

void baska(){
    int i=0;
    printf("Baskaya Girdi\n");
    /// DOSYA OKUYUP EKRANA YAZMA ///
    char dizi[1000];
    char *dizi2[1000];
    FILE *ptDosya;
    char ch;
    int k=0;
    const char s[2] = "\t";
    char *token;
    char *a[1000];

    ptDosya = fopen("../rpolab2/devre2-parcali/baska_dosya.txt", "r");
    do
    {
        ch = getc(ptDosya);
        printf("%c", ch);
        dizi[i]=ch;
        printf("\n%c",dizi[i]);
        i++;
    }
    while (ch != EOF);
    printf("\n\ndosya sonuna gelindi, okuma islemi bitti!!\n");
    fclose(ptDosya);
    token = strtok(dizi, s);

    while( token != NULL )
    {
         printf(" %s\n", token );
        dizi2[k]=token;
        printf("%s\n",dizi2[k]);
        token = strtok(NULL, s);
        k++;
    }

    int tutucu =0;
    int temp=0;
    int say=0;
    int say2 = strlen(giris);
    int dene=0;
    int len=strlen(giris);
    say=say2;
    /// BASKA DOSYA GİRİS DEGERİ KONTROL ETME VE ATAMA
    for(int i=1; dizi2[i] != '\0'; i++)
    {

        if (strcmp(dizi2[i],".cikis")==0)
        {
            temp=i+1;
            say=0;
            break;
        }
        dene=0;
        for (int j=0; giris[j]!='\0'; j++)
        {
        printf("dizi2[] = %s -- giris[] = %s \n",dizi2[i],giris[j]);
            if (strcmp(giris[j],dizi2[i])==0)
                break;
            else
                dene++;
        }
        printf("%d",dene);
        if(dene==len)
        {
            giris[say]=dizi2[i];

            printf("%s \n",giris[say]);
        }

        say++;
    }

    say2 = strlen(cikis);
    int len2=strlen(cikis);
    len2=len2-1;
    say=say2-1;
    /// BASKA DOSYA CİKİS DEGERİ KONTROL ETME VE ATAMA
    for(int i=temp; dizi2[i] != '\0'; i++)
    {

        if (strcmp(dizi2[i],".kapi")==0)
        {
            temp=i+1;
            say=0;
            break;
        }
        dene=0;
        for (int j=0; cikis[j]!='\0'; j++)
        {
            printf("dizi2[] = %s -- cikis[] = %s \n",dizi2[i],cikis[j]);
            if (strcmp(cikis[j],dizi2[i])==0)
                break;
            else
                dene++;
        }
        printf("%d -- %d \n",dene,len2);
        if(dene==len2)
        {
            cikis[say]=dizi2[i];

            printf("%s \n",cikis[say]);
        }

        say++;
    }
    ///BASKA DOSYA KAPIYA ATAMA
    for(int i=temp; dizi2[i] != '\0'; i++){
         if (strcmp(dizi2[i],".kapi"  )==0 ){
            temp=i+1;
            say=0;
            break;
         }
         if (strcmp(dizi2[i],".son")==0) return 0;
        kapi4[say]=dizi2[i];
        printf("%s \n",kapi4[say]);
         say++;
    }





}
void yukle(){
    int i=0;
    printf("Yukleye Girdi\n");
    /// DOSYA OKUYUP EKRANA YAZMA ///
    char dizi[1000];
    char *dizi2[1000];
    FILE *ptDosya;
    char ch;
    int k=0;
    const char s[2] = "\t";
    char *token;
    char *a[1000];

    ptDosya = fopen("../rpolab2/devre2-parcali/devre.txt", "r");
    do
    {
        ch = getc(ptDosya);
        //printf("%c", ch);
        dizi[i]=ch;
        //printf("\n%c",dizi[i]);
        i++;
    }
    while (ch != EOF);
    // printf("\n\ndosya sonuna gelindi, okuma islemi bitti!!\n");
    fclose(ptDosya);
    token = strtok(dizi, s);

    while( token != NULL )
    {
        // printf(" %s\n", token );
        dizi2[k]=token;
       // printf("%s\n",dizi2[k]);
        token = strtok(NULL, s);
        k++;
    }

    int tutucu =0;
    int temp=0;
    int say=0;

    ///BA?KA DOSYA KONTROLÜ ///
    for(int i=0; dizi2[i] != '\0'; i++){

         if (strcmp(dizi2[i],".include")==0){
            temp=i+1;
             break;
         }
         else break;
    }


    ///BASKA DOSYA YSMY ALMA///
     for(int i=temp; dizi2[i] != '\0'; i++){

         if (strcmp(dizi2[i],".giris")==0){
            temp=i+1;
            say=0;
            break;
         }
        baskaDosya[say]=dizi2[i];
        //printf("%s \n",baskaDosya[say]);
         say++;

    }

    /// GYRYS DE?ERLERY ALMA ///
     for(int i=temp; dizi2[i] != '\0'; i++){

         if (strcmp(dizi2[i],".cikis")==0){
            temp=i+1;
            say=0;
            break;
         }
        giris[say]=dizi2[i];
       // printf("%s \n",giris[say]);
         say++;
    }

    /// CYKYS DE?ERLERY ALMA

        for(int i=temp; dizi2[i] != '\0'; i++){
         if (strcmp(dizi2[i],".kapi")==0){
            temp=i+1;
            say=0;
            break;
         }
        cikis[say]=dizi2[i];
        //printf("%s \n",cikis[say]);
         say++;
    }

    /// KAPY1 DE?ERLERY ALMA ///

     for(int i=temp; dizi2[i] != '\0'; i++){
         if (strcmp(dizi2[i],".kapi")==0){
            temp=i+1;
            say=0;
            break;
         }
        kapi[say]=dizi2[i];
        //printf("%s \n",kapi[say]);
         say++;
    }
     /// KAPY2 DE?ERLERY ALMA ///

     for(int i=temp; dizi2[i] != '\0'; i++){
         if (strcmp(dizi2[i],".kapi"  )==0  ){
            temp=i+1;
            say=0;
            break;
         }
         if (strcmp(dizi2[i],".son")==0) {
            if(strlen(baskaDosya)!=0)
            return baska();
         else return 0;
         }

        kapi2[say]=dizi2[i];
        //printf("%s \n",kapi2[say]);
         say++;
    }

    /// KAPY3 DE?ERLERY ALMA ///

     for(int i=temp; dizi2[i] != '\0'; i++){
         if (strcmp(dizi2[i],".kapi"  )==0 ){
            temp=i+1;
            say=0;
            break;
         }
         if (strcmp(dizi2[i],".son")==0) {
            if(strlen(baskaDosya)!=0)
            return baska();
         else return 0;
         }
        kapi3[say]=dizi2[i];
        //printf("%s \n",kapi3[say]);
         say++;
    }

    /// KAPY4 DE?ERLERY ALMA ///

     for(int i=temp; dizi2[i] != '\0'; i++){
         if (strcmp(dizi2[i],".kapi"  )==0 ){
            temp=i+1;
            say=0;
            break;
         }
         if (strcmp(dizi2[i],".son")==0) {
            if(strlen(baskaDosya)!=0)
            return baska();
         else return 0;
         }
        kapi4[say]=dizi2[i];
        //printf("%s \n",kapi4[say]);
         say++;
    }

    return 0;
}
void ilklendir(){

    printf("ilklendire Girdi\n");

     int i=0;
    /// DOSYA OKUYUP EKRANA YAZMA ///
    char dizi[1000];
    //char *dizi2[1000];
    FILE *ptDosya;
    char ch;
    int k=0;
    const char s[2] = "\t";
    char *token;

    //char *a[1000];

    ptDosya = fopen("../rpolab2/devre2-parcali/deger.txt", "r+");
    do{
        ch = getc(ptDosya);
        //printf("%c", ch);
        dizi[i]=ch;
        //printf("\n%c",dizi[i]);
        i++;
    }
    while (ch != EOF);
    // printf("\n\ndosya sonuna gelindi, okuma islemi bitti!!\n");
    fclose(ptDosya);
    token = strtok(dizi, s);


    while( token != NULL )
    {
        // printf(" %s\n", token );
        deger2[k]=token;
        //printf("%s\n",dizi[k]);
        token = strtok(NULL, s);
        k++;
    }


    for (int i=0; deger2[i]!='\0';i++ ){

         degerler[i]=deger2[i];
         /// DYZY YÇYNDEKY KARAKTER SAYISI 2 GÖRÜNÜYOR VE B DE?Y?EMYYORUZ ///
        /*int a = strlen(degerler[i]);
        if (a>1)
        printf("--%d-- \n",a);
        */

        //printf("--%s\n",degerler[i]);

       }


}
void Lojik1H(char *Hal){
///DE?ER2 NYN A DAN SONRAKY ELEMANIN DE?ERYNY 1 YAP.

    printf("LojikH'a Girdi\n");

    int k=0,j=0;

          for (int i=0; degerler[i]!='\0';i++ ){

             if(strcmp(degerler[k],Hal)==0) {  j=k; }
                k++;
          }

        j=j+1;

    for (int i=0; degerler[i]!='\0';i++ ){

        if(i==j) degerler[i]="1";
    printf("%s\n",degerler[i]);   }

    return 0;
}
void Lojik1L(char *Lal){

     printf("LojikL'a Girdi\n");

    int k=0,j=0;
    for (int i=0; degerler[i]!='\0';i++ ){

             if(strcmp(degerler[k],Lal)==0) {  j=k; }
                k++;
          }

        j=j+1;
    for (int i=0; degerler[i]!='\0';i++ ){

        if(i==j) degerler[i]="0";
    printf("%s\n",degerler[i]);   }
}
void GalGoster(char *Gal){

    printf("Gal'a Girdi\n");
    int k=0,j=0;
    for (int i=0; degerler[i]!='\0';i++ ){

             if(strcmp(degerler[k],Gal)==0) j=k;
                k++;
          }

        int c=j;
        j=j+1;

    printf("%s = %s \n",degerler[c],degerler[j]);

}
void GalTumGoster(){
    printf("GalTumGoster'e Girdi\n");
    char *tutucu[30];
    for (int i=0; degerler[i]!='\0';i++ ){

            if(i%2==0)
             printf("%s = %s \n",degerler[i],degerler[i+1]);

          }

}
void simule(){

    //printf("%s",asctime(zaman_bilgisi));





    /// DOSYA YAZMA KODLARI ///


   /* FILE *dosya_yaz;
    dosya_yaz = fopen("../rpolab2/devre2-parcali/log.txt","w");
    fprintf(dosya_yaz,"Dosya Acildi \n");
    time (&t);
    zaman_bilgisi = localtime (&t); */




    printf("Simule Girdi \n");

        ///ZAMAN 0
        for (int i=0; degerler[i]!='\0';i++ ){
            if(degerler[i]!=deger2[i]){
             printf("0 ns: %s %s -> %s \n",degerler[i-1],deger2[i],degerler[i]);
            //fprintf(dosya_yaz,"0 ns: %s %s -> %s %s \n",degerler[i-1],deger2[i],degerler[i],asctime(zaman_bilgisi));
               }
          }
        //fclose(dosya_yaz);
        /// ZAMAN 1
    int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,ji=0,say=0,tut=0;

         if(strcmp(kapi[5],"1")==0){

             for (int j=0; degerler[j]!='\0'; j++ ){
                if(strcmp(kapi[3],degerler[j])==0){

                   // printf("\nGiris 1 = %s \n",degerler[j+1]);
                    a = atoi(degerler[j+1]);
                }
                if(strcmp(kapi[4],degerler[j])==0){

                    //printf("\nGiris 2 = %s \n",degerler[j+1]);
                    b = atoi(degerler[j+1]);
                }
                if(strcmp(kapi[2],degerler[j])==0){

                    //printf("\nCikis 1 = %s \n",degerler[j+1]);
                    c = atoi(degerler[j+1]);
                    tut =j+1;
                }
            }

             if (strcmp(kapi[0],"NAND")==0) c= NAND(a,b);
             if (strcmp(kapi[0],"NOR")==0) c= NOR(a,b);
             if (strcmp(kapi[0],"XOR")==0) c= XOR(a,b);
             if (strcmp(kapi[0],"AND")==0) c= AND(a,b);
             if (strcmp(kapi[0],"OR")==0) c= OR(a,b);

             //printf("deger = %d  \n ",c);
             degerler[tut]=itoa(c,degerler[tut],1);

            say=atoi(degerler[tut]);

            if(say==0) { say=1; }
            else { say=0; }

            printf("1 ns: %s %d -> %s \n",degerler[tut-1],say,degerler[tut]);
           // fprintf(dosya_yaz,"1 ns: %s %d -> %s %s\n",degerler[tut-1],say,degerler[tut],asctime(zaman_bilgisi));
         }
            //fclose(dosya_yaz);
        if(strcmp(kapi[5],"2")==0){

             for (int j=0; degerler[j]!='\0'; j++ ){
                if(strcmp(kapi[3],degerler[j])==0){

                   // printf("\nGiris 1 = %s \n",degerler[j+1]);
                    a = atoi(degerler[j+1]);
                }
                if(strcmp(kapi[4],degerler[j])==0){

                    //printf("\nGiris 2 = %s \n",degerler[j+1]);
                    b = atoi(degerler[j+1]);
                }
                if(strcmp(kapi[2],degerler[j])==0){

                    //printf("\nCikis 1 = %s \n",degerler[j+1]);
                    c = atoi(degerler[j+1]);
                    tut =j+1;
                }
            }
             if (strcmp(kapi[0],"NAND")==0) c= NAND(a,b);
             if (strcmp(kapi[0],"NOR")==0) c= NOR(a,b);
             if (strcmp(kapi[0],"XOR")==0) c= XOR(a,b);
             if (strcmp(kapi[0],"AND")==0) c= AND(a,b);
             if (strcmp(kapi[0],"OR")==0) c= OR(a,b);

             //printf("deger = %d  \n ",c);
             degerler[tut]=itoa(c,degerler[tut],1);

             say=atoi(degerler[tut]);

            if(say==0) { say=1; }
            else { say=0; }

            printf("2 ns: %s %d -> %s \n",degerler[tut-1],say,degerler[tut]);
            //fprintf(dosya_yaz,"2 ns: %s %d -> %s %s \n",degerler[tut-1],say,degerler[tut],asctime(zaman_bilgisi));
         }

         if(strcmp(kapi[5],"3")==0){

             for (int j=0; degerler[j]!='\0'; j++ ){
                if(strcmp(kapi[3],degerler[j])==0){

                   // printf("\nGiris 1 = %s \n",degerler[j+1]);
                    a = atoi(degerler[j+1]);
                }
                if(strcmp(kapi[4],degerler[j])==0){

                    //printf("\nGiris 2 = %s \n",degerler[j+1]);
                    b = atoi(degerler[j+1]);
                }
                if(strcmp(kapi[2],degerler[j])==0){

                    //printf("\nCikis 1 = %s \n",degerler[j+1]);
                    c = atoi(degerler[j+1]);
                    tut =j+1;
                }
            }
             if (strcmp(kapi[0],"NAND")==0) c= NAND(a,b);
             if (strcmp(kapi[0],"NOR")==0) c= NOR(a,b);
             if (strcmp(kapi[0],"XOR")==0) c= XOR(a,b);
             if (strcmp(kapi[0],"AND")==0) c= AND(a,b);
             if (strcmp(kapi[0],"OR")==0) c= OR(a,b);

            // printf("deger = %d  \n ",c);
             degerler[tut]=itoa(c,degerler[tut],1);

             say=atoi(degerler[tut]);

            if(say==0) { say=1; }
            else { say=0; }

            printf("3 ns: %s %d -> %s \n",degerler[tut-1],say,degerler[tut]);
             //fprintf(dosya_yaz,"3 ns: %s %d -> %s %s\n",degerler[tut-1],say,degerler[tut],asctime(zaman_bilgisi));
         }

         if(strcmp(kapi[5],"4")==0){

             for (int j=0; degerler[j]!='\0'; j++ ){
                if(strcmp(kapi[3],degerler[j])==0){

                   // printf("\nGiris 1 = %s \n",degerler[j+1]);
                    a = atoi(degerler[j+1]);
                }
                if(strcmp(kapi[4],degerler[j])==0){

                    //printf("\nGiris 2 = %s \n",degerler[j+1]);
                    b = atoi(degerler[j+1]);
                }
                if(strcmp(kapi[2],degerler[j])==0){

                    //printf("\nCikis 1 = %s \n",degerler[j+1]);
                    c = atoi(degerler[j+1]);
                    tut =j+1;
                }
            }
             if (strcmp(kapi[0],"NAND")==0) c= NAND(a,b);
             if (strcmp(kapi[0],"NOR")==0) c= NOR(a,b);
             if (strcmp(kapi[0],"XOR")==0) c= XOR(a,b);
             if (strcmp(kapi[0],"AND")==0) c= AND(a,b);
             if (strcmp(kapi[0],"OR")==0) c= OR(a,b);

             //printf("deger = %d  \n ",c);
             degerler[tut]=itoa(c,degerler[tut],1);

             say=atoi(degerler[tut]);

            if(say==0) { say=1;}
            else { say=0;}

            printf("4 ns: %s %d -> %s \n",degerler[tut-1],say,degerler[tut]);
            //fprintf(dosya_yaz,"4 ns: %s %d -> %s %s\n",degerler[tut-1],say,degerler[tut],asctime(zaman_bilgisi));

         }

        if(strcmp(kapi2[5],"1")==0){

             for (int j=0; degerler[j]!='\0'; j++ ){
                if(strcmp(kapi2[3],degerler[j])==0){

                    //printf("\nGiris 1 = %s \n",degerler[j+1]);
                    d = atoi(degerler[j+1]);
                }
                if(strcmp(kapi2[4],degerler[j])==0){

                    //printf("\nGiris 2 = %s \n",degerler[j+1]);
                    e = atoi(degerler[j+1]);
                }
                if(strcmp(kapi2[2],degerler[j])==0){

                   // printf("\nCikis 1 = %s \n",degerler[j+1]);
                    f = atoi(degerler[j+1]);
                    tut =j+1;
                }
            }
             if (strcmp(kapi2[0],"NAND")==0) f= NAND(d,e);
             if (strcmp(kapi2[0],"NOR")==0) f= NOR(d,e);
             if (strcmp(kapi2[0],"XOR")==0) f= XOR(d,e);
             if (strcmp(kapi2[0],"AND")==0) f= AND(d,e);
             if (strcmp(kapi2[0],"OR")==0) f= OR(d,e);

             //printf("Deger 2 = %d \n" ,f);
             degerler[tut]=itoa(f,degerler[tut],2);
              say=atoi(degerler[tut]);

            if(say==0) { say=1; }
            else { say=0; }

            printf("1 ns: %s %d -> %s \n",degerler[tut-1],say,degerler[tut]);
            //fprintf(dosya_yaz,"1 ns: %s %d -> %s %s\n",degerler[tut-1],say,degerler[tut],asctime(zaman_bilgisi));
         }

        if(strcmp(kapi2[5],"2")==0){

             for (int j=0; degerler[j]!='\0'; j++ ){
                if(strcmp(kapi2[3],degerler[j])==0){

                    //printf("\nGiris 1 = %s \n",degerler[j+1]);
                    d = atoi(degerler[j+1]);
                }
                if(strcmp(kapi2[4],degerler[j])==0){

                    //printf("\nGiris 2 = %s \n",degerler[j+1]);
                    e = atoi(degerler[j+1]);
                }
                if(strcmp(kapi2[2],degerler[j])==0){

                   // printf("\nCikis 1 = %s \n",degerler[j+1]);
                    f = atoi(degerler[j+1]);
                    tut =j+1;
                }
            }
             if (strcmp(kapi2[0],"NAND")==0) f= NAND(d,e);
             if (strcmp(kapi2[0],"NOR")==0) f= NOR(d,e);
             if (strcmp(kapi2[0],"XOR")==0) f= XOR(d,e);
             if (strcmp(kapi2[0],"AND")==0) f= AND(d,e);
             if (strcmp(kapi2[0],"OR")==0) f= OR(d,e);

            // printf("Deger 3 = %d \n" ,f);
             degerler[tut]=itoa(f,degerler[tut],2);
              say=atoi(degerler[tut]);

            if(say==0) { say=1; }
            else { say=0; }

            printf("2 ns: %s %d -> %s \n",degerler[tut-1],say,degerler[tut]);
            //fprintf(dosya_yaz,"2 ns: %s %d -> %s %s\n",degerler[tut-1],say,degerler[tut],asctime(zaman_bilgisi));
         }

         if(strcmp(kapi2[5],"3")==0){

             for (int j=0; degerler[j]!='\0'; j++ ){
                if(strcmp(kapi2[3],degerler[j])==0){

                    //printf("\nGiris 1 = %s \n",degerler[j+1]);
                    d = atoi(degerler[j+1]);
                }
                if(strcmp(kapi2[4],degerler[j])==0){

                    //printf("\nGiris 2 = %s \n",degerler[j+1]);
                    e = atoi(degerler[j+1]);
                }
                if(strcmp(kapi2[2],degerler[j])==0){

                   // printf("\nCikis 1 = %s \n",degerler[j+1]);
                    f = atoi(degerler[j+1]);
                    tut =j+1;
                }
            }
             if (strcmp(kapi2[0],"NAND")==0) f= NAND(d,e);
             if (strcmp(kapi2[0],"NOR")==0) f= NOR(d,e);
             if (strcmp(kapi2[0],"XOR")==0) f= XOR(d,e);
             if (strcmp(kapi2[0],"AND")==0) f= AND(d,e);
             if (strcmp(kapi2[0],"OR")==0) f= OR(d,e);

             //printf("Deger 2 = %d \n" ,f);
             degerler[tut]=itoa(f,degerler[tut],2);
              say=atoi(degerler[tut]);

            if(say==0) { say=1;}
            else { say=0;}

            printf("3 ns: %s %d -> %s \n",degerler[tut-1],say,degerler[tut]);
            //fprintf(dosya_yaz,"3 ns: %s %d -> %s %s\n",degerler[tut-1],say,degerler[tut],asctime(zaman_bilgisi));
         }



         if(strcmp(kapi2[5],"4")==0){

             for (int j=0; degerler[j]!='\0'; j++ ){
                if(strcmp(kapi2[3],degerler[j])==0){

                    //printf("\nGiris 1 = %s \n",degerler[j+1]);
                    d = atoi(degerler[j+1]);
                }
                if(strcmp(kapi2[4],degerler[j])==0){

                    //printf("\nGiris 2 = %s \n",degerler[j+1]);
                    e = atoi(degerler[j+1]);
                }
                if(strcmp(kapi2[2],degerler[j])==0){

                   // printf("\nCikis 1 = %s \n",degerler[j+1]);
                    f = atoi(degerler[j+1]);
                    tut =j+1;
                }
            }
             if (strcmp(kapi2[0],"NAND")==0) f= NAND(d,e);
             if (strcmp(kapi2[0],"NOR")==0) f= NOR(d,e);
             if (strcmp(kapi2[0],"XOR")==0) f= XOR(d,e);
             if (strcmp(kapi2[0],"AND")==0) f= AND(d,e);
             if (strcmp(kapi2[0],"OR")==0) f= OR(d,e);

            // printf("Deger 2 = %d \n" ,f);
             degerler[tut]=itoa(f,degerler[tut],2);
              say=atoi(degerler[tut]);

            if(say==0) { say=1;}
            else { say=0; }

            printf("4 ns: %s %d -> %s \n",degerler[tut-1],say,degerler[tut]);
            //fprintf(dosya_yaz,"4 ns: %s %d -> %s %s\n",degerler[tut-1],say,degerler[tut],asctime(zaman_bilgisi));
         }

        int aaa = strlen(kapi3);

        if (aaa>0){

            if(strcmp(kapi3[5],"1")==0){

             for (int j=0; degerler[j]!='\0'; j++ ){
                if(strcmp(kapi3[3],degerler[j])==0){

                    //printf("\nGiris 1 = %s \n",degerler[j+1]);
                    d = atoi(degerler[j+1]);
                }
                if(strcmp(kapi3[4],degerler[j])==0){

                    //printf("\nGiris 2 = %s \n",degerler[j+1]);
                    e = atoi(degerler[j+1]);
                }
                if(strcmp(kapi3[2],degerler[j])==0){

                   // printf("\nCikis 1 = %s \n",degerler[j+1]);
                    f = atoi(degerler[j+1]);
                    tut =j+1;
                }
            }
             if (strcmp(kapi3[0],"NAND")==0) f= NAND(d,e);
             if (strcmp(kapi3[0],"NOR")==0) f= NOR(d,e);
             if (strcmp(kapi3[0],"XOR")==0) f= XOR(d,e);
             if (strcmp(kapi3[0],"AND")==0) f= AND(d,e);
             if (strcmp(kapi3[0],"OR")==0) f= OR(d,e);

             //printf("Deger 2 = %d \n" ,f);
             degerler[tut]=itoa(f,degerler[tut],2);
              say=atoi(degerler[tut]);

            if(say==0) { say=1; }
            else { say=0; }

            printf("1 ns: %s %d -> %s \n",degerler[tut-1],say,degerler[tut]);
            //fprintf(dosya_yaz,"1 ns: %s %d -> %s %s\n",degerler[tut-1],say,degerler[tut],asctime(zaman_bilgisi);
         }

         if(strcmp(kapi3[5],"2")==0){

             for (int j=0; degerler[j]!='\0'; j++ ){
                if(strcmp(kapi3[3],degerler[j])==0){

                    //printf("\nGiris 1 = %s \n",degerler[j+1]);
                    d = atoi(degerler[j+1]);
                }
                if(strcmp(kapi3[4],degerler[j])==0){

                    //printf("\nGiris 2 = %s \n",degerler[j+1]);
                    e = atoi(degerler[j+1]);
                }
                if(strcmp(kapi3[2],degerler[j])==0){

                   // printf("\nCikis 1 = %s \n",degerler[j+1]);
                    f = atoi(degerler[j+1]);
                    tut =j+1;
                }
            }
             if (strcmp(kapi3[0],"NAND")==0) f= NAND(d,e);
             if (strcmp(kapi3[0],"NOR")==0) f= NOR(d,e);
             if (strcmp(kapi3[0],"XOR")==0) f= XOR(d,e);
             if (strcmp(kapi3[0],"AND")==0) f= AND(d,e);
             if (strcmp(kapi3[0],"OR")==0) f= OR(d,e);

             //printf("Deger 2 = %d \n" ,f);
             degerler[tut]=itoa(f,degerler[tut],2);
             if(say==0) { say=1; }
            else { say=0; }

            printf("2 ns: %s %d -> %s \n",degerler[tut-1],say,degerler[tut]);
            //fprintf(dosya_yaz,"2 ns: %s %d -> %s %s\n",degerler[tut-1],say,degerler[tut],asctime(zaman_bilgisi));
         }

          if(strcmp(kapi3[5],"3")==0){

             for (int j=0; degerler[j]!='\0'; j++ ){
                if(strcmp(kapi3[3],degerler[j])==0){

                    //printf("\nGiris 1 = %s \n",degerler[j+1]);
                    d = atoi(degerler[j+1]);
                }
                if(strcmp(kapi3[4],degerler[j])==0){

                    //printf("\nGiris 2 = %s \n",degerler[j+1]);
                    e = atoi(degerler[j+1]);
                }
                if(strcmp(kapi3[2],degerler[j])==0){

                   // printf("\nCikis 1 = %s \n",degerler[j+1]);
                    f = atoi(degerler[j+1]);
                    tut =j+1;
                }
            }
             if (strcmp(kapi3[0],"NAND")==0) f= NAND(d,e);
             if (strcmp(kapi3[0],"NOR")==0) f= NOR(d,e);
             if (strcmp(kapi3[0],"XOR")==0) f= XOR(d,e);
             if (strcmp(kapi3[0],"AND")==0) f= AND(d,e);
             if (strcmp(kapi3[0],"OR")==0) f= OR(d,e);

             //printf("Deger 2 = %d \n" ,f);
             degerler[tut]=itoa(f,degerler[tut],2);
            if(say==0) { say=1; }
            else { say=0; }

            printf("3 ns: %s %d -> %s \n",degerler[tut-1],say,degerler[tut]);
           // fprintf(dosya_yaz,"3 ns: %s %d -> %s %s\n",degerler[tut-1],say,degerler[tut],asctime(zaman_bilgisi));
         }

          if(strcmp(kapi3[5],"4")==0){

             for (int j=0; degerler[j]!='\0'; j++ ){
                if(strcmp(kapi3[3],degerler[j])==0){

                    //printf("\nGiris 1 = %s \n",degerler[j+1]);
                    d = atoi(degerler[j+1]);
                }
                if(strcmp(kapi3[4],degerler[j])==0){

                    //printf("\nGiris 2 = %s \n",degerler[j+1]);
                    e = atoi(degerler[j+1]);
                }
                if(strcmp(kapi3[2],degerler[j])==0){
                   // printf("\nCikis 1 = %s \n",degerler[j+1]);
                    f = atoi(degerler[j+1]);
                    tut =j+1;
                }
            }
             if (strcmp(kapi3[0],"NAND")==0) f= NAND(d,e);
             if (strcmp(kapi3[0],"NOR")==0) f= NOR(d,e);
             if (strcmp(kapi3[0],"XOR")==0) f= XOR(d,e);
             if (strcmp(kapi3[0],"AND")==0) f= AND(d,e);
             if (strcmp(kapi3[0],"OR")==0) f= OR(d,e);

             //printf("Deger 2 = %d \n" ,f);
             degerler[tut]=itoa(f,degerler[tut],2);
            if(say==0) { say=1; }
            else { say=0; }

            printf("4 ns: %s %d -> %s \n",degerler[tut-1],say,degerler[tut]);
            //fprintf(dosya_yaz,"4 ns: %s %d -> %s %s\n",degerler[tut-1],say,degerler[tut],asctime(zaman_bilgisi));
         }
         //fclose(dosya_yaz);

        }
}
void Komut (){

    printf("Komuta Girdi\n");

     int i=0;
    /// DOSYA OKUYUP EKRANA YAZMA ///
    char dizi[1000];
    //char *dizi2[1000];
    FILE *ptDosya;
    char ch;
    int k=0;
    const char s[2] = "\t";
    char *token;

    //char *a[1000];

    ptDosya = fopen("../rpolab2/devre2-parcali/komut.txt", "r+");
    do{
        ch = getc(ptDosya);
        //printf("%c", ch);
        dizi[i]=ch;
        //printf("\n%c",dizi[i]);
        i++;
    }
    while (ch != EOF);
    // printf("\n\ndosya sonuna gelindi, okuma islemi bitti!!\n");
    fclose(ptDosya);
    token = strtok(dizi, s);


    while( token != NULL )
    {
        // printf(" %s\n", token );
        komut[k]=token;
        //printf("%s\n",dizi[k]);
        token = strtok(NULL, s);
        k++;
    }


    for (int i=0; komut[i]!='\0';i++ ){

         if (strcmp(komut[i],"y")==0) yukle();
          if (strcmp(komut[i],"i")==0) ilklendir();
           if (strcmp(komut[i],"h")==0) Lojik1H(komut[i+1]);
             if (strcmp(komut[i],"l")==0) Lojik1L(komut[i+1]);
              if (strcmp(komut[i],"g")==0) GalGoster(komut[i+1]);
               if (strcmp(komut[i],"u")==0) GalTumGoster();
                if (strcmp(komut[i],"s")==0) simule();
                 if (strcmp(komut[i],"c")==0) exit(0);
       }




}
void XOR (int a, int b){
    printf("%d",a);
    printf("%d",b);
    int c=0;
    if (a==b) c=0;
    else c=1;

    return c;

}
void AND (int a, int b){

    int c=0;
    if (a==1 && b==1) c=1;
    else c=0;

    return c;

}
void OR (int a, int b){

    int c=0;
    if (a==0 && b==0) c=0;
    else c=1;

    return c;
}
void NAND (int a, int b){

    int c=0;
    if (a==1 && b==1) c=0;
    else c=1;

    return c;

}
void NOR (int a, int b){

    int c=0;
    if (a==1 && b==1) c=1;
    else c=0;

    return c;

}
void NOT(int a){

    int c=0;
    if (a==0 ) c=1;
    else if (a==1) c=0;

    return c;

}



