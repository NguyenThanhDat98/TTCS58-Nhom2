#include<stdio.h>

int main()
{
	int month,year;
	printf("moi nhap thang: ");
	scanf("%d",&month);
	printf("moi nhap nam: ");
	scanf("%d",&year);
	if(year<1582){
		printf("nhap nam ko hop le");
		return 0;
	}
	if(month<1 || month>12){
		printf("thang khong hop le");
		return 0;
	}
	int top=31;
	switch (month){
		case 4: case 6: case 9: case 11:
			top =30;
		break;
		case 2:
			top=((year%4==0 && year %100!=0) || (year%400==0) )? 29:28;
		break; 
	}
//	if(day<1 || day>top)
//	{
//		printf("ngay khong hop le");
//		return 3;
//	}
//	printf("Ngay hop le \n");
	int d = 1;
	int a = (14-month)/12;
	int y = year - a;
	int m = month+12*a-2;
	int dow=(d+y+y/4-y/100+y/400+(31*m)/12)%7;
	printf("%3s%3s%3s%3s%3s%3s%3s","T2","T3","T4","T5","T6","T7","CN");
	printf("\n");
	for(int i=0;i<7;i++)
	{
		if(i<dow-1)
			printf("   ");
		else
			printf("%3d",d++);
	}
	printf("\n");
	do{
		for(int i=0;i<7;i++)
			if(d<=top)
				printf("%3d",d++);
		printf("\n");
	}while(d<=top);
	return 0;
}
