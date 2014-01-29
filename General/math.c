#include<stdio.h>

void roundoff(float nm)
{
	int digits;
	float limit=0.5;
	printf("Round upto: ");
	scanf("%d",&digits);
	printf("%.*f\n",digits,nm);
}

void ciel(float nm)
{
	printf("Ciel Value = %d\n",(int)nm==nm?(int)nm:(int)nm+1 );
}

void floor_num(float nm)
{
        printf("Floor Value = %d\n",(int)nm );
}

int main()
{
	float nm;
	printf("Enter the Number :");
	scanf("%f",&nm);
	ciel(nm);
}
