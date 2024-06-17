#include <stdio.h>
#include <math.h>

#include <climits>



int main()
{
   char zprava1='\0'; //symbol pro vstup pro 1. spravu
   int pocet_palek1=0;// promnene pro pocet '|' v 1 sprave
   int sum1_1=0,sum1_2=0; // summy pro do a po palce pro kazdou zpravu
   int chyba =0; // promnena pro chybny vstup -> jestli neco spatneho -> vyvod nespravny vstup
   printf("Zpravy:\n");
   
   while(zprava1!='\n')
   {
   	if(scanf("%c", &zprava1)!=1 ) // Vvod symbola
   	{
   		printf("Nespravny vstup.\n");
   		return 1;
   	}
   	int cislo_zpravy = (int)zprava1;//cislo charu v ascii tabulce
   	if((cislo_zpravy<97 || cislo_zpravy>122) && zprava1!='\n' && zprava1 !='|') //proverka jesli symblo je v diapasonu noralich pisem a jesli symboly z diapazonu nejsou enter nebo palka
   	{
   			chyba = 1 ;
   	}
 
   	if(chyba!=1 && (zprava1!='\n' && zprava1!='|')) // proverka jesli nejsou chyby -> machinace s cislemi
   	{
  	
   		if(pocet_palek1==0) // jesli prvni cast
   		{
   			//printf("cislo zpravy=%d\n", sum1_1);
   			sum1_1+=pow(2,(cislo_zpravy-97));
   		}
   		else if(pocet_palek1==1)//jesli druha cast vstupu
   		{
   			sum1_2+=pow(2,(cislo_zpravy-97));
   		}
   	}
   	
   	if(zprava1=='|' ) // prechod na novu palku
   	{
   		pocet_palek1++;
   	}
   	
   }
   char zprava2='\0'; //symbol pro vstup pro 2. spravu
   int pocet_palek2=0;// promnene pro pocet '|' v 2 sprave
   int sum2_1=0,sum2_2=0;
   int chyba2 = 0;
   
   while(zprava2!='\n')
   {
   	if(scanf("%c", &zprava2)!=1 ) // Vvod symbola
   	{
   		printf("Nespravny vstup.\n");
   		return 1;
   	}
   	int cislo_zpravy = (int)zprava2;//cislo charu v ascii tabulce
   	if((cislo_zpravy<97 || cislo_zpravy>122) && zprava2!='\n' && zprava2 !='|') 
   	{
   			chyba2 = 1 ;
   	}
   	if(chyba2!=1 && (zprava2!='\n' && zprava2!='|')) // proverka jesli nejsou chyby -> machinace s cislemi
   	{
  	
   		if(pocet_palek2==0) // jesli prvni cast
   		{
   			//printf("cislo zpravy=%d\n", sum1_1);
   			sum2_1+=pow(2,(cislo_zpravy-97));
   		}
   		else if(pocet_palek1==1)//jesli druha cast vstupu
   		{
   			sum2_2+=pow(2,(cislo_zpravy-97));
   		}
   	}
   	
   	if(zprava2=='|') // prechod na novu palku
   	{
   		pocet_palek2++;
   	}
   	
   }
   	
  
  if(chyba!=0 || chyba2!=0 || pocet_palek1!=1 || pocet_palek2!=1) // proverka jesli nejsou chyby ve stupu a jsou po jedne palce
  {
  	printf("Nespravny vstup.\n");
  	return 1;
  }
  
  
  if((sum1_1 == 0 && sum2_1 == 0) && (sum1_2 == 0 && sum2_2 == 0))
  {
  	printf("Nespravny vstup.\n");
  }
  else if((sum1_1 == 0 && sum1_2 == 0) || (sum2_1 == 0 && sum2_2 == 0))
  {
  	printf("Nespravny vstup.\n");
  }
  else if(sum1_1 == 0 || sum2_1 == 0 || sum1_2 == 0 || sum2_2 == 0)
  {
  	printf("Synchronizace za: 0\n");
  }
  else
  {
      int dist1 = sum1_1+sum1_2; 
      int dist2 = sum2_1+sum2_2; 
      int cesta1=sum1_1;
      int cesta2=sum2_1;
  	while(1) 
  	{
		if(cesta1 == cesta2)
		{
			break;
		}
		else if(cesta1<cesta2)
		{
			cesta1+=dist1;
		}
		else if(cesta2<cesta1)
		{
			cesta2+=dist2;
		}
		if(cesta1>999999999)
		{
			printf("Nelze dosahnout.\n");
			return 1;
		}
	
	}
		printf("Synchronizace za: %d\n",cesta1);
  
  }

 
 /*printf("sum11=%d\nsum12=%d\npocet_palek1=%d\nchyba=%d\n\n\n",sum1_1,sum1_2,pocet_palek1,chyba);
 printf("sum21=%d\nsum22=%d\npocet_palek2=%d\nchyba2=%d\n",sum2_1,sum2_2,pocet_palek2,chyba2);*/
	
 return 0;
}
