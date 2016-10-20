#ifndef __PROGTEST__
#include <stdio.h>
#include <assert.h>
#endif /* __PROGTEST__ */

int segment(int cislo)
{
int pocet=0;

switch (cislo) {
    default:
        printf("Something went terribly wrong :(");
        break;
    case 0: case 6: case 9:
        pocet=6;
        break;
    case 2: case 3: case 5:
        pocet=5;
        break;
    case 1:
        pocet=2;
        break;
    case 4:
        pocet=4;
        break;
    case 7:
        pocet=3;
        break;
    case 8:
        pocet=7;
        break;
    }

return pocet;
}

int pocet_s(int cislo)
{
int pocseg;
pocseg=segment(cislo/10)+segment(cislo%10);
if (cislo<10) pocseg-=6;
return pocseg;
}

int pocet_s_m(int min)
{
int pocseg;
pocseg=segment(min/10)+segment(min%10);
return pocseg;
}

int prestupny(int rok)
{
    int prest;
    prest=0;
    if ((rok%4==0)&&(rok%100!=0)&&(rok%4000!=0)) prest=1;
    if (rok%400==0) prest=1;
    return prest;
}

int pocet_dni(int mesic, int rok)
{

if (mesic==1 || mesic==3 || mesic==5 || mesic==7 || mesic==8 || mesic==10 || mesic==12) return 31;
if (mesic==4 || mesic==6 || mesic==9 || mesic==11) return 30;
if (mesic==2 && (prestupny(rok)==1)) return 29;
if (mesic==2 && (prestupny(rok)==0)) return 28;
return 0;
}


int min_ve_dni(int hod,int min)
{
return (hod*60+min);
}

long long int rozdil(int y1, int m1, int d1,
                   int y2, int m2, int d2)
{
long long int a1,a2,den1,den2;
a1=(long long int)((14-m1)/12.0);
a2=(long long int)((14-m2)/12.0);
y1=y1+4800-a1;
y2=y2+4800-a2;
m1=m1+12*a1-3;
m2=m2+12*a2-3;

den1=365*y1+(long long int)(y1/4.0) - (long long int)(y1/100.0) + (long long int)(y1/400.0) - (long long int)(y1/4000.0) + (long long int)((153*m1+2)/5.0) + d1;
den2=365*y2+(long long int)(y2/4.0) - (long long int)(y2/100.0) + (long long int)(y2/400.0) - (long long int)(y2/4000.0) + (long long int)((153*m2+2)/5.0) + d2;

return den2-den1;
}

int rozdil_min(int h1, int i1, int h2, int i2)
{
int rozdil_2=0;
rozdil_2=(((h2*60)+i2)-(h1*60+i1));
return rozdil_2;
}


long long int digitalClock ( int y1, int m1, int d1, int h1, int i1,
                   int y2, int m2, int d2, int h2, int i2, long long int * consumption )
 {
    int j,l,hodina1,hodina2,minuta1,minuta2;
    long long int soucet;
    l=1;
    j=1;
    hodina1=h1;
    hodina2=h2;
    minuta1=i1;
    minuta2=i2;
    soucet=0;


            /*OSETRENI*/
    if (y1<1600 || y2<1600 || m1<1 || m2<1 || m1>12 || m2>12 || d1<1 || d2<1 || d1>31 || d2>31 || h1<0 || h2<0 || h1>23 || h2>23 || i1<0 ||i2<0 || i1>59 || i2>59) return 0;
    if (((m1==4)||(m1==6)||(m1==9)||(m1==11)) && (d1>30)) return 0;
    if (((m2==4)||(m2==6)||(m2==9)||(m2==11)) && (d2>30)) return 0;
    if ((prestupny(y1)==0)&&(m1==2)&&(d1>28)) return 0;
    if ((prestupny(y2)==0)&&(m2==2)&&(d2>28)) return 0;
    if ((m1==2)&&(d1>29)) return 0;
    if ((m2==2)&&(d2>29)) return 0;
    if (rozdil(y1,m1,d1,y2,m2,d2)<0) return 0;
    if ((rozdil(y1,m1,d1,y2,m2,d2)==0) && (rozdil_min(h1,i1,h2,i2)<0)) return 0;
            /*OSETRENI*/

soucet=2185920*rozdil(y1,m1,d1,y2,m2,d2);

if (rozdil_min(h1,i1,h2,i2)>0) {

    for (l=1;l<=(rozdil_min(h1,i1,h2,i2)+1);l++)
    {
        soucet+=564+60*(pocet_s_m(minuta1)+pocet_s(hodina1));
        minuta1++;
        if (minuta1>59)
        {
            hodina1++;
            minuta1=0;

        }
    }
}


if (rozdil_min(h1,i1,h2,i2)<0) {
minuta1-=1;
if(minuta1<0)
{
    minuta1=59;
    hodina1--;
}
    for (j=1;j<=(rozdil_min(h2,i2,h1,i1)-1);j++)
    {

        soucet-=(564+60*(pocet_s_m(minuta1)+pocet_s(hodina1)));
        minuta1--;
        if (minuta1<0)
        {
            hodina1--;
            minuta1=59;
        }

    }

}


/*59056245516LL*/


if (rozdil_min(h1,i1,h2,i2)==0)
{
soucet+=564+60*(pocet_s_m(minuta2)+pocet_s(hodina2));
}





*consumption=soucet;



return 1;
 }

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
 {
   long long int consumption;
/*
long long int test;


test=digitalClock(1997, 7, 24, 20, 0, 2071, 7, 13, 11, 53, &consumption);
printf("%lld\n\n",test);


test=rozdil_min(22,35,6,29);
printf("%lld\n\n",test);
*/
assert ( digitalClock ( 1976, 6, 17, 11, 44, 2049, 11, 25, 10, 43, &consumption )  == 1	&& consumption==58635032160LL);

assert ( digitalClock ( 1997, 7, 24, 20, 0, 2071, 7, 13, 11, 53, &consumption ) == 1 && consumption==59056245516);

   assert ( digitalClock ( 2014, 10,  1, 13, 15,
                           2014, 10,  1, 18, 45, &consumption ) == 1
            && consumption == 510384LL );
   assert ( digitalClock ( 2014, 10,  1, 13, 15,
                           2014, 10,  2, 11, 20, &consumption ) == 1
            && consumption == 2015964LL );
   assert ( digitalClock ( 2014,  1,  1, 13, 15,
                           2014, 10,  5, 11, 20, &consumption ) == 1
            && consumption == 605329884LL );
   assert ( digitalClock ( 2012,  1,  1, 13, 15,
                           2012, 10,  5, 11, 20, &consumption ) == 1
            && consumption == 607515804LL );
   assert ( digitalClock ( 1900,  1,  1, 13, 15,
                           1900, 10,  5, 11, 20, &consumption ) == 1
            && consumption == 605329884LL );
   assert ( digitalClock ( 2014, 10,  1,  0,  0,
                           2014, 10,  1, 12,  0, &consumption ) == 1
            && consumption == 1033464LL );
   assert ( digitalClock ( 2014, 10,  1,  0, 15,
                           2014, 10,  1,  0, 25, &consumption ) == 1
            && consumption == 15804LL );
   assert ( digitalClock ( 2014, 10,  1, 12,  0,
                           2014, 10,  1, 12,  0, &consumption ) == 1
            && consumption == 1704LL );
   assert ( digitalClock ( 2014, 10,  1, 12,  0,
                           2014, 10,  1, 12,  1, &consumption ) == 1
            && consumption == 3168LL );
   assert ( digitalClock ( 2014, 11,  1, 12,  0,
                           2014, 10,  1, 12,  0, &consumption ) == 0 );
   assert ( digitalClock ( 2014, 10, 32, 12,  0,
                           2014, 11, 10, 12,  0, &consumption ) == 0 );
   assert ( digitalClock ( 2100,  2, 29, 12,  0,
                           2100,  2, 29, 12,  0, &consumption ) == 0 );
   assert ( digitalClock ( 2400,  2, 29, 12,  0,
                           2400,  2, 29, 12,  0, &consumption ) == 1
            && consumption == 1704LL );


    assert ( digitalClock ( 1844, 1, 1, 0, 0, 1844, 2, 20, 0, 0, &consumption ) == 1
            && consumption == 109297644LL );


    assert ( digitalClock ( 1916, 10, 27, 13, 37, 2002, 5, 27, 14, 58, &consumption ) == 1 && consumption == 68327610828LL );

    assert ( digitalClock ( 2069, 2, 19, 5, 22, 2151, 8, 24, 19, 15, &consumption ) == 1 && consumption == 65873958336LL );

    assert ( digitalClock ( 1852, 1, 1, 0, 0, 1852, 1, 6, 0, 0, &consumption ) == 1 && consumption == 10931244LL );

    assert ( digitalClock ( 2000, 11, 30, 0, 0, 2000, 12, 24, 0, 0, &consumption )==1 && consumption==52463724);

    assert ( digitalClock ( 2095, 11, 8, 6, 28, 2160, 10, 3, 16, 13, &consumption )==1 && consumption==51818111604);






  assert ( digitalClock ( 2023, 8, 1, 22, 35, 2194, 11, 11, 6, 29, &consumption )  == 1	&& consumption==136747478160LL);
  assert ( digitalClock ( 1976, 6, 17, 11, 44, 2049, 11, 25, 10, 43, &consumption )  == 1	&& consumption==58635032160LL);
  assert ( digitalClock ( 2047, 10, 17, 20, 18, 2195, 5, 6, 13, 36, &consumption ) == 1 && consumption == 117802972296LL );
  assert ( digitalClock ( 2000, 2, 29, 0, 0, 2000, 12, 29, 0, 0, &consumption ) == 1 && consumption == 664521324LL );
  assert ( digitalClock ( 1938, 2, 18, 13, 16, 2108, 1, 19, 11, 37, &consumption )==1 && consumption==135660233268LL);
  assert ( digitalClock ( 2074, 2, 7, 2, 29, 2197, 3, 10, 11, 0, &consumption )  == 1	&& consumption==98270965548LL);
  assert ( digitalClock ( 1910, 4, 9, 21, 10, 1921, 11, 6, 21, 30, &consumption )  == 1	&& consumption==9244287084LL);
  assert ( digitalClock ( 2074, 4, 2, 10, 36, 2108, 2, 29, 12, 32, &consumption )  == 1	&& consumption==27072790908LL);
  assert ( digitalClock ( 2044, 1, 4, 2, 19, 2122, 3, 6, 19, 26, &consumption ) == 1 && consumption == 62409550092LL );
assert ( digitalClock ( 2033, 2, 28, 8, 13, 2098, 10, 11, 7, 54, &consumption ) == 1 && consumption == 52387731408LL);


  assert ( digitalClock ( 2000, 2, 29, 0, 0, 2000, 3, 28, 0, 0, &consumption )== 1 && consumption==61207404);


   return 0;
 }


#endif /* __PROGTEST__ */
