#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <math.h>
int main()
{
	/*float p, r, n;
	r = 0.07;
	n = 10;
	p = pow(1 + r, n);
	printf("p=%f\n", p);*/
	double r5, r3, r2, r1, r0, p, p1, p2, p3, p4, p5;
	printf("«Î ‰»Î±æΩ:\n");
	scanf("%lf", &p);
	r5 = 0.03;
	r3 = 0.0275;
	r2 = 0.021;
	r1 = 0.015;
	r0 = 0.0035;
	p1 = p * (1 + r5 * 5);
	p2 = p * (1 + 2 * r2) * (1 + 3 * r3);
	p3 = p * (1 + 3 * r3) * (1 + 2 * r2);
	p4 = p * pow(1 + r1, 5);
	p5 = p * pow(1 + r0 / 4, 4 * 5);
	printf("p1=%lf\n,p2=%lf\n,p3=%lf\n,p4=%lf\n,p5=%lf\n", p1, p2, p3, p4, p5);



	return 0;
}