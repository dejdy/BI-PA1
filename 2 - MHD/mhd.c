#include<stdio.h>
#include<stdlib.h>

int prevod (int hod, int min)
{
  int minuty;
  minuty=(hod*60+min);
  return minuty;
}



int main(void)
{
int h1,m1,h2,m2,odjh,odjm,minuty1,minuty2,min_odj,i,vyslmin;
int pole1[65001];
int pole2[65001];

i=1;
vyslmin=0;

printf("Interval spoje #1:\n");
if (scanf("%d:%d",&h1,&m1)!=2)
    {
        printf("Nespravny vstup.\n");
        return 0;
    }

if (h1<0 || m1<0 || m1>59 || (prevod(h1,m1)<=0))
    {
        printf("Nespravny vstup.\n");
        return 0;
    }


printf("Interval spoje #2:\n");
if (scanf("%d:%d",&h2,&m2)!=2)
    {
        printf("Nespravny vstup.\n");
        return 0;
    }

if (h2<0 || m2<0 || m2>59 || (prevod(h2,m2)<=0))
    {
        printf("Nespravny vstup.\n");
        return 0;
    }



printf("Cas od odjezdu spoje #2:\n");
if (scanf("%d:%d",&odjh,&odjm)!=2)
    {
        printf("Nespravny vstup.\n");
        return 0;
    }


if (odjh<0 || odjm<0 || odjm>59)
    {
        printf("Nespravny vstup.\n");
        return 0;
    }




if (prevod(odjh,odjm)>=prevod(h2,m2))
    {
    printf("Nespravny vstup.\n");
    return 0;
    }


minuty1=prevod(h1,m1);
minuty2=prevod(h2,m2);
min_odj=prevod(odjh,odjm);
pole2[0]=minuty2-min_odj;
pole1[0]=0;
pole1[1]=minuty1;


if (minuty2-min_odj==1)
    {
        printf("Spoj #2 bude odjizdet 1 minutu po prijezdu spoje #1 prave nyni.\n");
        return 0;
    }




if (minuty1==minuty2)
{
    printf("Spoj #2 nikdy nebude odjizdet 1 minutu po prijezdu spoje #1.\n");
    return 0;
}



if (minuty1>minuty2) {
for (i=1; i<60000; i++)
    {
        pole1[i]=pole1[i-1]+minuty1;
        pole2[i]=pole2[i-1]+minuty2;


        while (pole2[i]<pole1[i-1])
            {pole2[i]=pole2[i]+minuty2;};


        if (pole2[i]==pole1[i-1]+1)
        {
            vyslmin=pole1[i-1];
            break;
        }

        if (i==59999)
        {
            printf("Spoj #2 nikdy nebude odjizdet 1 minutu po prijezdu spoje #1.\n");
            return 0;
        }
    }
}


if (minuty1<minuty2) {

for (i=1; i<60000; i++)
    {
        pole1[i]=pole1[i-1]+minuty1;
        pole2[i]=pole2[i-1]+minuty2;

        while (pole1[i]<pole2[i-1]-minuty1)
            {pole1[i]=pole1[i]+minuty1;};


        if (pole2[i-1]==(pole1[i]+1))
        {
            vyslmin=pole1[i];
            break;
        }



        if (i==59999)
        {
            printf("Spoj #2 nikdy nebude odjizdet 1 minutu po prijezdu spoje #1.\n");
            return 0;
        }



    }
}




if (vyslmin%60<10) printf("Spoj #2 bude odjizdet 1 minutu po prijezdu spoje #1 za %d:0%d.\n",vyslmin/60,vyslmin%60);
else printf("Spoj #2 bude odjizdet 1 minutu po prijezdu spoje #1 za %d:%d.\n",vyslmin/60,vyslmin%60);


return 0;
}
