#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10000

long long int porovnani(long long int *x, long long int *y)
{
    return *x-*y;
}


int main(void) {
int pocet,test,prvni,druhy,treti;
long long cislo,vysledek,pole[MAXSIZE];
printf("Delky nosniku:\n");
pocet=0; prvni=0; druhy=1; treti=2; vysledek=0;


    /*Cteni cisel do pole*/
while((test=scanf("%lld", &cislo)) != EOF)
  {
    if (test==0)
        {
            printf("Nespravny vstup.\n");
            return 0;
        }
    if (cislo<=0)
    {
        printf("Nespravny vstup.\n");
        return 0;
    }
    pole[pocet]=cislo;
    pocet++;
  }

    /*Osetreni vstupu*/
if (pocet<3 || pocet>10000)
    {
        printf("Nespravny vstup.\n");
        return 0;
    }

    /* Serazeni pole funkci qsort */
qsort((void *) pole, pocet, sizeof(pole[0]),(int (*)(const void *, const void *)) porovnani);


for (prvni=0;prvni<pocet-2;)
{
    for (druhy=prvni+1;druhy<pocet-1;)
    {
        for (treti=druhy+1;treti<pocet;)
          {
            if((pole[prvni]+pole[druhy])>pole[treti]) vysledek++;
            treti++;
            while(pole[treti]==pole[treti-1]) treti++;
          }
        druhy++;
        while(pole[druhy]==pole[druhy-1]) druhy++;
    }
    prvni++;
    while(pole[prvni]==pole[prvni-1]) prvni++;
}



printf("Trojuhelniku: %lld\n",vysledek);

return 0;
}
