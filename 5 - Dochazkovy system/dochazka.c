#include<stdio.h>
#include<stdlib.h>



struct struktura
{
	int id;
  	int cas;
  	char prichod;
  	int doba;
};

struct dynpole
{
	int vel, al_space;
  	struct struktura *data;
};

int prevods(int h, int m, int s)
{
return s+60*m+3600*h;
}


struct dynpole* novepole()
{
 	struct dynpole *pole = (struct dynpole*) malloc(sizeof(struct dynpole));

    pole->al_space = 0;
  	pole->data = 0;
    pole->vel = 0;

  	return pole;
}


void pridej(struct struktura data, struct dynpole *pole)
{
    if (pole->al_space==0)
    {
        pole->data = (struct struktura*) malloc(2*sizeof(struct struktura));
        pole->al_space=2;
        pole->data[pole->vel]=data;
        pole->vel++;
    } else if (pole->vel==pole->al_space)
    {
        pole->data = (struct struktura*)realloc(pole->data,2*pole->al_space*sizeof(struct struktura));
        pole->al_space*=2;
        pole->data[pole->vel]=data;
        pole->vel++;
    } else
    {
        pole->data[pole->vel]=data;
        pole->vel++;
    }
}


int porovnani(const void *a, const void *b)
{
  	struct struktura *s1 = (struct struktura*)a;
  	struct struktura *s2 = (struct struktura*)b;

    if (s1->id > s2->id) return 1;
    if (s1->id < s2->id) return -1;
    if (s1->id == s2->id)
        {
                if (s1->cas > s2->cas) return 1;
                if (s1->cas < s2->cas) return -1;
        };
    return 0;
}


int porovnani2(const void *a, const void *b)
{
  	struct struktura *s1 = (struct struktura*)a;
  	struct struktura *s2 = (struct struktura*)b;

    if (s1->doba > s2->doba) return 1;
    if (s1->doba < s2->doba) return -1;
    if (s1->id == s2->id)
        {
                if (s1->id > s2->id) return 1;
                if (s1->id < s2->id) return -1;
        };
    return 0;
}


int osetreni (int h, int m, int s, int idcko, char znak)
{


    if ((znak!='+') && (znak !='-') && (znak!='#'))
        {
            return 1;
        }

    if (idcko<1 || idcko>10000)
        {
            return 1;
        }

    if ((h<0)||(h>23)||(m<0)||(m>59)||(s<0)||(s>59))
        {
            return 1;
        }
return 0;
}



int main(void) {

char znak;
int h,m,s,idcko,test,prevod,i,nejdelsi,counter,opravdu_uz_posledni_promenna;
struct dynpole *pole = novepole();
struct struktura prvek;
counter=0; i=0;
znak='0';


printf("Zaznamy o dochazce:\n");
while ((scanf(" %c",&znak)!=EOF))
{
    if (znak=='#') {counter=0; continue;}
    if (znak!='-' && znak!='+')
        {
            printf("Nespravny vstup.\n");
            goto konec;
        }
    test=scanf("%d:%d:%d %d",&h,&m,&s,&idcko);
    if ((test!=4))

        {
            printf("Nespravny vstup.\n");
            goto konec;
        }

        if (osetreni(h,m,s,idcko,znak)==1)
        {
            printf("Nespravny vstup.\n");
            goto konec;
        }

        prevod=prevods(h,m,s);
        prvek.prichod=znak;
        prvek.id=idcko;
        prvek.cas=prevod;
        prvek.doba=0;
        pridej(prvek,pole);

        if (counter>0)
            {
                if((pole->data[pole->vel-1].cas) <= (pole->data[pole->vel-2].cas))
                {
                    printf("Nespravny vstup.\n");
                    goto konec;
                }
            }
        counter++;
}




if(pole->vel%2 !=0 || pole->vel==0)
{
    printf("Nespravny vstup.\n");
    goto konec;
}

qsort(pole->data, pole->vel, sizeof(struct struktura), porovnani);





for(i=0;i<pole->vel;)
{
    pole->data[i].doba += (pole->data[i+1].cas - pole->data[i].cas);
    if (pole->data[i+2].id == pole->data[i].id) pole->data[i+2].doba+=pole->data[i].doba;
    if ((pole->data[i].doba-pole->data[i+1].doba != pole->data[i].doba) || (pole->data[i].cas==pole->data[i+1].cas && pole->data[i].id==pole->data[i+1].id))
        {
            printf("Nespravny vstup.\n");
            goto konec;
        }
    if (pole->data[i].prichod == pole->data[i-1].prichod)
        {
            printf("Nespravny vstup.\n");
            goto konec;
        }
    if(pole->data[i].prichod=='-' && pole->data[i].id==pole->data[i+1].id)
        {
            printf("Nespravny vstup.\n");
            goto konec;
        }

    i+=2;
}


qsort(pole->data, pole->vel, sizeof(struct struktura), porovnani2);
nejdelsi=pole->data[pole->vel-1].doba;
printf("Nejdelsi pracovni doba: %d:%02d:%02d\n",nejdelsi/3600,(nejdelsi%3600)/60,((nejdelsi%3600)%60)%60);

if (pole->data[pole->vel-1].doba == pole->data[pole->vel-2].doba) printf("Pracovnici dne: ");
else printf ("Pracovnik dne: ");



counter=0;
opravdu_uz_posledni_promenna=0;


i=pole->vel-1;
while((pole->data[i].doba==nejdelsi))
    {
            opravdu_uz_posledni_promenna++;
            i--;
    }

i=pole->vel-1;



for(i=0;i<opravdu_uz_posledni_promenna-1;i++)
{
    printf("%d, ",pole->data[pole->vel-opravdu_uz_posledni_promenna+i].id);
}

printf("%d\n",pole->data[pole->vel-1].id);




/*
for (i=0;i<pole->vel;i++)
{
    printf("%d ",pole->data[i].id);
    printf("%d ",pole->data[i].cas);
    printf("%c ",pole->data[i].prichod);
    printf("%d ",pole->data[i].doba);
    printf("\n");
}
*/



konec:
free(pole->data);
free(pole);


return 0;
}

