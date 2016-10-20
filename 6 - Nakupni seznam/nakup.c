#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct struktura
    {
        int puv_poradi;
        int typ; /*0 = regal; 1 = seznam*/
        int reg_sez; /*cislo regalu nebo seznamu*/
        int vysl_regal;
        int cislo_na_sez;
        char *retezec;
        char *retezec_old;
    };

struct dynpole
    {
        int vel, al_space;
        struct struktura *data;
    };

struct dynpole* novepole()
    {
        struct dynpole *pole = (struct dynpole*) malloc(sizeof(struct dynpole));
        pole->al_space = 0;
        pole->data = 0;
        pole->vel = 0;
        return pole;
    }

void pridej(int typ, int reg_sez, struct dynpole *pole)
    {


        if (pole->vel==pole->al_space-2) /*Kdyz jsme na konci pole*/
            {
                pole->data = (struct struktura*)realloc(pole->data,2*pole->al_space*sizeof(struct struktura)); /*Realokace*/
                pole->al_space*=2; /*Nastaveni velkkosti alokovane pameti*/
            }
        pole->data[pole->vel].typ=typ;
        pole->data[pole->vel].reg_sez=reg_sez;
        pole->vel++;
    }

int porovnani1(const void *a, const void *b)
{
  	struct struktura *s1 = (struct struktura*)a;
  	struct struktura *s2 = (struct struktura*)b;

    if (s1->vysl_regal > s2->vysl_regal) return 1;
    if (s1->vysl_regal < s2->vysl_regal) return -1;
    if (s1->vysl_regal == s2->vysl_regal)
        {
                if (s1->cislo_na_sez > s2->cislo_na_sez) return 1;
                if (s1->cislo_na_sez < s2->cislo_na_sez) return -1;
        };
    return 0;
}



int porovnani2(const void *a, const void *b)
{
  	struct struktura *s1 = (struct struktura*)a;
  	struct struktura *s2 = (struct struktura*)b;

    if (s1->puv_poradi > s2->puv_poradi) return 1;
    if (s1->puv_poradi < s2->puv_poradi) return -1;
    if (s1->puv_poradi == s2->puv_poradi) return 0;

    return 0;
}




int main(void)
{

    struct dynpole *pole = novepole();

    int cislo_sezn=0;
    int x=0;
    int z=0;
    int i=0;
    int j=0;
    int prv_pruch=0;
  	int typ=0;
  	int test=0;
  	int reg_sez=0;
  	int pocet_zbozi=0;
  	size_t delka;
  	int indexy [1000];
  	int polozek=0;
  	int predchozi=-1;



    /* ALOKACE POLE*/
        pole->data = (struct struktura*) malloc(8*sizeof(struct struktura));
        pole->al_space=8;
    /* ALOKACE POLE*/
    pole->data[pole->vel].retezec=0;



    while((x=(getline(&(pole->data[pole->vel].retezec), &delka, stdin))) != EOF)
        {

            if(prv_pruch==0) /*Pokud prvni radek neni #0*/
                {
                    prv_pruch=1;
                    if( pole->data[0].retezec[0]!='#' && pole->data[0].retezec[1]!='0' && strlen(pole->data[0].retezec)!=3)
                        {
                            printf("Nespravny vstup.\n");
                            return 0;
                        }
                }

            if (pole->data[i].retezec[0] == '#')
                {
                    ((test=sscanf(pole->data[i].retezec,"#%d",&reg_sez)));
                    if((reg_sez-1!=predchozi) || (test!=1))
                        {
                            printf("Nespravny vstup.\n");
                            goto konec;
                        }
                    predchozi=reg_sez;
                }

            if (pole->data[i].retezec[0] == '\n') /*Pokud byl zadan newline - nyni se nacita seznam*/
                {
                    typ=1;
                    if(pole->data[i-1].typ==0) reg_sez=0;

                    polozek=0;
                    reg_sez++;

                    indexy[reg_sez]=polozek+indexy[reg_sez-1];
                }

            if((pole->data[i].retezec[0] != '#') && (pole->data[i].retezec[0] != '\n'))
                {
                    if(pole->data[pole->vel].retezec[x-1]=='\n') pole->data[pole->vel].retezec[x-1]='\0';
                    pridej(typ, reg_sez, pole);
                    pole->data[i].cislo_na_sez=999999;
                    pole->data[i].vysl_regal=999999;
                    pole->data[i].puv_poradi=i;
                    i++;
                    if(typ==1) polozek++;
                    if (typ==0) pocet_zbozi++;

                }
            pole->data[pole->vel+1].retezec=0; /* Kvuli inicializovani hodnot :P*/
            indexy[reg_sez]=polozek+indexy[reg_sez-1];
        }

    if(typ==0) /*Pokud nebyl zadan nakupni seznam*/
        {
            printf("Nespravny vstup.\n");
            goto konec;
        }





for(z=1;z<=reg_sez;z++)
    {
                printf("Optimalizovany seznam:\n");
                    for (i=pocet_zbozi+indexy[z-1]; pole->data[i].reg_sez==z; i++)
                        {
                            for (j=0; j<pocet_zbozi; j++)
                                {
                                    if ((strcasecmp(pole->data[i].retezec,pole->data[j].retezec))==0)
                                        {
                                            pole->data[i].vysl_regal=pole->data[j].reg_sez;
                                            pole->data[i].cislo_na_sez=i-pocet_zbozi;
                                            pole->data[i].retezec_old=(char*)malloc((strlen(pole->data[j].retezec))*sizeof(char*)*2);
                                            strcpy(pole->data[i].retezec_old, pole->data[j].retezec);
                                        }
                                    else if (((strcasestr(pole->data[j].retezec,pole->data[i].retezec))!=NULL) && (pole->data[i].vysl_regal==999999))
                                    /*else if ((((strcasestr(pole->data[j].retezec, pole->data[i].retezec))!=NULL)&&(pole->data[i].vysl_regal==999999)))*/
                                        {
                                            pole->data[i].vysl_regal=pole->data[j].reg_sez;
                                            pole->data[i].cislo_na_sez=i-pocet_zbozi;
                                            pole->data[i].retezec_old=(char*)malloc((strlen(pole->data[j].retezec))*sizeof(char*)*2);
                                            strcpy(pole->data[i].retezec_old, pole->data[j].retezec);
                                        }
                                }
                        }





                    qsort(pole->data, pole->vel, sizeof(struct struktura), porovnani1);

                cislo_sezn=0;
                for(i=0;i<pole->vel;i++)
                {
                    if(pole->data[i].typ!=0 && pole->data[i].reg_sez==z)
                        {
                            printf(" %d. %s -> ",cislo_sezn, pole->data[i].retezec);
                            if (pole->data[i].vysl_regal != 999999)
                                {
                                    printf("#%d %s\n",pole->data[i].vysl_regal, pole->data[i].retezec_old);
                                    free(pole->data[i].retezec_old);
                                }
                            else printf("N/A\n");
                            cislo_sezn++;

                        }
                }


        qsort(pole->data, pole->vel, sizeof(struct struktura), porovnani2);
    }



/*
printf("\n\nPocet zbozi v regalech: %d\n",pocet_zbozi);
printf("\n\nPosledni zbozi: %s\n",pole->data[pocet_zbozi-1].retezec);

*/

konec:
    for (i=0;i<pole->vel;i++)
    {
/*        printf("%s",pole->data[i].retezec);
        printf("Puvodni poradi: %d\n",pole->data[i].puv_poradi);
        printf("Typ zbozi:%d\n",pole->data[i].typ);
        printf("Cislo regalu/seznamu: %d\n\n",pole->data[i].reg_sez);
*/
        free(pole->data[i].retezec);
    }



    free(pole->data[pole->vel].retezec);

    free(pole->data);
    free(pole);

    return 0;
}
