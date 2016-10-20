#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int pocet=0;
int test=0;
int number=0;
int ind[10000];

int porovnani(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}


int check_case (char * retezec)
{
unsigned int i;
            for(i=0;i<strlen(retezec)-1;i++)
            {
                if (retezec[i]<97 || retezec[i]>122)
                    {
                        printf("Nespravny vstup.\n");
                        return -1;
                    }
            }
return 0;
}



int rekurze (char ** pole, char * zprava, int n, int pocet_slov)
{
int i;
    for(i=0; i<pocet_slov; i++)
        {
            /*printf("Zpracovavam: %s - %s\n\n",zprava,pole[i]);*/
            if (strncmp(zprava, pole[i], strlen(pole[i])) == 0)
            {
                if (strcmp(pole[i],zprava)==0)
                    {
                        pocet++;

                        number++;

                        if(test==0) ind[number]=i;

                        test=1;
                        /*printf("Pridan index\n");*/
                    }
                else
                    {
                        if (test==0)
                            {
                                ind[number+1]=i;
                          /*      printf("Pridan index\n");*/
                                number++;
                            }

                        rekurze (pole, zprava+strlen(pole[i]), n+strlen(pole[i]), pocet_slov);
                    }

              if (test==0)
                {
                    number=0;
                }
            }
        }

return 0;
}


int main(void)
{

char **pole = (char **)malloc(2 * sizeof(char *));
char *zprava;
int pocet_slov=0;
int allocated=2;
size_t delka, delka2;
int i;
int x=0;

zprava = (char *) malloc (sizeof(char *)+2);
zprava=0;
pole[0]=0;

printf("Slovnik:\n");
while(((x=(getline(&(pole[pocet_slov]), &delka, stdin)))))
    {
        if (check_case(pole[pocet_slov])!=0) goto konec;

        if (pole[pocet_slov][0]=='\n') break;

        if(pole[pocet_slov][x-1]=='\n') pole[pocet_slov][x-1]='\0';

        for (i=0;i<pocet_slov;i++)
            {
                if (strcmp(pole[pocet_slov],pole[i])==0)
                    {
                        printf("Nespravny vstup.\n");
                        goto konec;
                    }
            }



        pocet_slov++;
        if(pocet_slov==allocated)
            {
                pole = (char **)realloc (pole, 2 * allocated * (sizeof(char *)));
                allocated*=2;
            }
        pole[pocet_slov]=0; /* Kvuli inicializovani hodnot*/
    }

if (pocet_slov==0)
    {
        printf("Nespravny vstup.\n");
        goto konec;
    }


for (i=0;i<pocet_slov-1;i++)
    {
        if (strcmp(pole[i],pole[i+1])==0)
            {
                printf("Nespravny vstup.\n");
                goto konec;
            }
    }


printf("Zpravy:\n");
    while((getline(&zprava, &delka2, stdin) != EOF))
   {
        test=0;
        pocet=0;
        number=0;

        if (check_case(zprava)!=0) goto konec;
        if(zprava[strlen(zprava)-1]=='\n') zprava[strlen(zprava)-1]='\0';
        rekurze(pole, zprava, 0, pocet_slov);
        if (pocet != 1) printf(" => %d\n", pocet);
        else
            {
                printf(" => ");
                  for(i=1;i<number;i++)
                {
                    printf("%s ",pole[ind[i]]);
                }
            printf("%s\n",pole[ind[number]]);

            }
    }

konec:
free (zprava);
    for(i=0;i<pocet_slov;i++)
        {
            /*printf("%s\n",pole[i]);*/
            free(pole[i]);
        }


    free (pole[pocet_slov]);
    free (pole);


return 0;
}
