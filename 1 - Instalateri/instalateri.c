#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void) {
int vstup1, vstup2, vstup3, rozmer, bod1_x, bod1_y, bod1_z, bod2_x, bod2_y, bod2_z, potrubi, sousedni, nejkratsi;
double hadice,nejkratsih;
sousedni=1;

/* Zadani rozmeru mistnosti, osetreni vstupu */
printf("Zadejte rozmer mistnosti:\n");
vstup1=scanf("%d", &rozmer);

    if (rozmer<=0)
    {
        printf("Nespravny vstup.\n");
        return 0;
    }
     if (vstup1!=1)
     {
        printf("Nespravny vstup.\n");
        return 0;
     }


/* VSTUP - BOD #1 */
printf("Bod #1:\n");
vstup2=scanf("%d %d %d", &bod1_x, &bod1_y, &bod1_z);

/* Neciselna hodnota */
     if (vstup2!=3)
     {
        printf("Nespravny vstup.\n");
        return 0;
     }

/* Bod nelezi na krychli */
     if (!(((bod1_x==0)||(bod1_x==rozmer))||((bod1_y==0)||(bod1_y==rozmer))||((bod1_z==0)||(bod1_z==rozmer))))
     {
        printf("Nespravny vstup.\n");
        return 0;
     }

/* Bod lezi mimo krychli */
    if ((bod1_x>rozmer)||(bod1_x>rozmer)||(bod1_z>rozmer))
    {
        printf("Nespravny vstup.\n");
        return 0;
     }

/* Bod lezi prilis blizko hrane */
    if ((bod1_x==0)||(bod1_x==rozmer))
    {
        if ((bod1_y<20)||((rozmer-bod1_y<20)))
        {
            printf("Nespravny vstup.\n");
            return 0;
        }

        if ((bod1_z<20)||((rozmer-bod1_z<20)))
        {
            printf("Nespravny vstup.\n");
            return 0;
        }

    }

/* Bod lezi prilis blizko hrane */
if ((bod1_y==0)||(bod1_y==rozmer))
    {
        if ((bod1_x<20)||((rozmer-bod1_x<20)))
        {
            printf("Nespravny vstup.\n");
            return 0;
        }

        if ((bod1_z<20)||((rozmer-bod1_z<20)))
        {
            printf("Nespravny vstup.\n");
            return 0;
        }

    }

/* Bod lezi prilis blizko hrane */
if ((bod1_z==0)||(bod1_z==rozmer))
    {
        if ((bod1_y<20)||((rozmer-bod1_y<20)))
        {
            printf("Nespravny vstup.\n");
            return 0;
        }

        if ((bod1_x<20)||((rozmer-bod1_x<20)))
        {
            printf("Nespravny vstup.\n");
            return 0;
        }

    }


/* VSTUP - BOD #2 */
printf("Bod #2:\n");
vstup3=scanf("%d %d %d", &bod2_x, &bod2_y, &bod2_z);
/* Neciselna hodnota */
     if (vstup3!=3)
     {
        printf("Nespravny vstup.\n");
        return 0;
     }

/* Bod nelezi na krychli */
     if (!(((bod2_x==0)||(bod2_x==rozmer))||((bod2_y==0)||(bod2_y==rozmer))||((bod2_z==0)||(bod2_z==rozmer))))
     {
        printf("Nespravny vstup.\n");
        return 0;
     }

/* Bod lezi mimo krychli */
    if ((bod2_x>rozmer)||(bod2_x>rozmer)||(bod2_z>rozmer))
    {
        printf("Nespravny vstup.\n");
        return 0;
     }

/* Bod lezi prilis blizko hrane */
    if ((bod2_x==0)||(bod2_x==rozmer))
    {
        if ((bod2_y<20)||((rozmer-bod2_y<20)))
        {
            printf("Nespravny vstup.\n");
            return 0;
        }

        if ((bod2_z<20)||((rozmer-bod2_z<20)))
        {
            printf("Nespravny vstup.\n");
            return 0;
        }

    }

/* Bod lezi prilis blizko hrane */
if ((bod2_y==0)||(bod2_y==rozmer))
    {
        if ((bod2_x<20)||((rozmer-bod2_x<20)))
        {
            printf("Nespravny vstup.\n");
            return 0;
        }

        if ((bod2_z<20)||((rozmer-bod2_z<20)))
        {
            printf("Nespravny vstup.\n");
            return 0;
        }

    }

/* Bod lezi prilis blizko hrane */
if ((bod2_z==0)||(bod2_z==rozmer))
    {
        if ((bod2_y<20)||((rozmer-bod2_y<20)))
        {
            printf("Nespravny vstup.\n");
            return 0;
        }

        if ((bod2_x<20)||((rozmer-bod2_x<20)))
        {
            printf("Nespravny vstup.\n");
            return 0;
        }

    }

/* Pokud body lezi ve stejne stene */
if (((((bod1_x==0)||(bod1_x==rozmer)))&&(bod2_x==bod1_x)) || ((((bod1_y==0)||(bod1_y==rozmer)))&&(bod2_y==bod1_y)) || ((((bod1_z==0)||(bod1_z==rozmer)))&&(bod2_z==bod1_z)))
 {
    sousedni=0;
    potrubi=((fabs(bod1_x-bod2_x))+fabs((bod1_y-bod2_y))+fabs((bod1_z-bod2_z)));
    hadice=(sqrt(((bod1_x-bod2_x)*(bod1_x-bod2_x))+((bod1_y-bod2_y)*(bod1_y-bod2_y))+((bod1_z-bod2_z)*(bod1_z-bod2_z))));
    printf("Delka potrubi: %d\n",potrubi);
    printf("Delka hadice: %f\n",hadice);
 }

/* Pokud body lezi v protejsi stene */
if (((fabs(bod1_x-bod2_x)==rozmer)) || ((fabs(bod1_y-bod2_y)==rozmer)) || ((fabs(bod1_z-bod2_z)==rozmer)))
{
    sousedni=0;

    if (((bod1_x==0) && (bod2_x==rozmer)) || ((bod2_x==0) && (bod1_x==rozmer)))
    {
        potrubi=((rozmer-bod1_z)+rozmer+(fabs(bod1_y-bod2_y))+(rozmer-bod2_z));
        nejkratsi=(bod1_z+rozmer+(fabs(bod1_y-bod2_y))+bod2_z);
        if (nejkratsi<potrubi) potrubi=nejkratsi;
        nejkratsi=(bod1_y+rozmer+(fabs(bod1_z-bod2_z))+bod2_y);
        if (nejkratsi<potrubi) potrubi=nejkratsi;
        nejkratsi=((rozmer-bod1_y)+rozmer+(fabs(bod1_z-bod2_z))+(rozmer-bod2_y));
        if (nejkratsi<potrubi) potrubi=nejkratsi;

        printf("Delka potrubi: %d\n",potrubi);
    }


if (((bod1_y==0) && (bod2_y==rozmer)) || ((bod2_y==0) && (bod1_y==rozmer)))
    {
        potrubi=((rozmer-bod1_z)+rozmer+(fabs(bod1_x-bod2_x))+(rozmer-bod2_z));
        nejkratsi=(bod1_z+rozmer+(fabs(bod1_x-bod2_x))+bod2_z);
        if (nejkratsi<potrubi) potrubi=nejkratsi;
        nejkratsi=(bod1_x+rozmer+(fabs(bod1_z-bod2_z))+bod2_x);
        if (nejkratsi<potrubi) potrubi=nejkratsi;
        nejkratsi=((rozmer-bod1_x)+rozmer+(fabs(bod1_z-bod2_z))+(rozmer-bod2_x));
        if (nejkratsi<potrubi) potrubi=nejkratsi;

        printf("Delka potrubi: %d\n",potrubi);
    }



if (((bod1_z==0) && (bod2_z==rozmer)) || ((bod2_z==0) && (bod1_z==rozmer)))
    {
        potrubi=((rozmer-bod1_x)+rozmer+(fabs(bod1_y-bod2_y))+(rozmer-bod2_x));
        nejkratsi=(bod1_x+rozmer+(fabs(bod1_y-bod2_y))+bod2_x);
        if (nejkratsi<potrubi) potrubi=nejkratsi;
        nejkratsi=(bod1_y+rozmer+(fabs(bod1_x-bod2_x))+bod2_y);
        if (nejkratsi<potrubi) potrubi=nejkratsi;
        nejkratsi=((rozmer-bod1_y)+rozmer+(fabs(bod1_x-bod2_x))+(rozmer-bod2_y));
        if (nejkratsi<potrubi) potrubi=nejkratsi;

        printf("Delka potrubi: %d\n",potrubi);
    }


if (((bod1_y==0) && (bod2_y==rozmer)) || ((bod1_y==rozmer)&&(bod2_y==0)))
{
    hadice=(sqrt(((((rozmer-bod1_x)+rozmer+(rozmer-bod2_x))*((rozmer-bod1_x)+rozmer+(rozmer-bod2_x)))+((fabs(bod1_z-bod2_z))*(fabs(bod1_z-bod2_z))))));
    nejkratsih=(sqrt((bod1_x+rozmer+bod2_x)*(bod1_x+rozmer+bod2_x)+((bod1_z-bod2_z)*(bod1_z-bod2_z))));
    if (nejkratsih<hadice) hadice=nejkratsih;
    nejkratsih=(sqrt(((bod1_z+rozmer+bod2_z)*(bod1_z+rozmer+bod2_z))+((bod1_x-bod2_x)*(bod1_x-bod2_x))));
    if (nejkratsih<hadice) hadice=nejkratsih;
    nejkratsih=(sqrt(((((rozmer-bod1_z)+rozmer+(rozmer-bod2_z))*((rozmer-bod1_z)+rozmer+(rozmer-bod2_z)))+((fabs(bod1_x-bod2_x))*(fabs(bod1_x-bod2_x))))));
    if (nejkratsih<hadice) hadice=nejkratsih;
    printf("Delka hadice: %f\n",hadice);
}


if (((bod1_x==0) && (bod2_x==rozmer)) || ((bod1_x==rozmer) && (bod2_x==0)))
{
    hadice=(sqrt(((((rozmer-bod1_y)+rozmer+(rozmer-bod2_y))*((rozmer-bod1_y)+rozmer+(rozmer-bod2_y)))+((fabs(bod1_z-bod2_z))*(fabs(bod1_z-bod2_z))))));
    nejkratsih=(sqrt((bod1_y+rozmer+bod2_y)*(bod1_y+rozmer+bod2_y)+((bod1_z-bod2_z)*(bod1_z-bod2_z))));
    if (nejkratsih<hadice) hadice=nejkratsih;
    nejkratsih=(sqrt(((bod1_z+rozmer+bod2_z)*(bod1_z+rozmer+bod2_z))+((bod1_y-bod2_y)*(bod1_y-bod2_y))));
    if (nejkratsih<hadice) hadice=nejkratsih;
    nejkratsih=(sqrt(((((rozmer-bod1_z)+rozmer+(rozmer-bod2_z))*((rozmer-bod1_z)+rozmer+(rozmer-bod2_z)))+((fabs(bod1_y-bod2_y))*(fabs(bod1_y-bod2_y))))));
    if (nejkratsih<hadice) hadice=nejkratsih;
    printf("Delka hadice: %f\n",hadice);
}




if (((bod1_z==0) && (bod2_z==rozmer))||((bod1_z==rozmer) && (bod2_z==0)))
{
    hadice=(sqrt(((((rozmer-bod1_x)+rozmer+(rozmer-bod2_x))*((rozmer-bod1_x)+rozmer+(rozmer-bod2_x)))+((fabs(bod1_y-bod2_y))*(fabs(bod1_y-bod2_y))))));
    nejkratsih=(sqrt((bod1_x+rozmer+bod2_x)*(bod1_x+rozmer+bod2_x)+((bod1_y-bod2_y)*(bod1_y-bod2_y))));
    if (nejkratsih<hadice) hadice=nejkratsih;
    nejkratsih=(sqrt(((bod1_y+rozmer+bod2_y)*(bod1_y+rozmer+bod2_y))+((bod1_x-bod2_x)*(bod1_x-bod2_x))));
    if (nejkratsih<hadice) hadice=nejkratsih;
    nejkratsih=(sqrt(((((rozmer-bod1_y)+rozmer+(rozmer-bod2_y))*((rozmer-bod1_y)+rozmer+(rozmer-bod2_y)))+((fabs(bod1_x-bod2_x))*(fabs(bod1_x-bod2_x))))));
    if (nejkratsih<hadice) hadice=nejkratsih;
    printf("Delka hadice: %f\n",hadice);
}



}



/* Pokud body lezi ve sousedni stene */
if (sousedni==1)
{
    potrubi=((fabs(bod1_x-bod2_x))+(fabs(bod1_y-bod2_y))+(fabs(bod1_z-bod2_z)));
    printf("Delka potrubi: %d\n",potrubi);



if ((((bod1_y==0 || bod1_y==rozmer) && (bod2_x==0 || bod2_x==rozmer))) || (((bod2_y==0 || bod2_y==rozmer) && (bod1_x==0 || bod1_x==rozmer))))
{
    hadice=(sqrt( ((fabs(bod1_y-bod2_y))+(fabs(bod1_x-bod2_x)))*((fabs(bod1_y-bod2_y))+(fabs(bod1_x-bod2_x))) + ((bod1_z-bod2_z)*(bod1_z-bod2_z))));
    printf("Delka hadice: %f\n",hadice);
}


if ((((bod1_y==0 || bod1_y==rozmer) && (bod2_z==0 || bod2_z==rozmer))) || (((bod2_y==0 || bod2_y==rozmer) && (bod1_z==0 || bod1_z==rozmer))))
{
    hadice=(sqrt( ((fabs(bod1_y-bod2_y))+(fabs(bod1_z-bod2_z)))*((fabs(bod1_y-bod2_y))+(fabs(bod1_z-bod2_z))) + ((bod1_x-bod2_x)*(bod1_x-bod2_x))));
    printf("Delka hadice: %f\n",hadice);
}


if ((((bod1_z==0 || bod1_z==rozmer) && (bod2_x==0 || bod2_x==rozmer))) || (((bod2_z==0 || bod2_z==rozmer) && (bod1_x==0 || bod1_x==rozmer))))
{
    hadice=(sqrt( ((fabs(bod1_z-bod2_z))+(fabs(bod1_x-bod2_x)))*((fabs(bod1_z-bod2_z))+(fabs(bod1_x-bod2_x))) + ((bod1_y-bod2_y)*(bod1_y-bod2_y))));
    printf("Delka hadice: %f\n",hadice);
}



}



return 0;
}
