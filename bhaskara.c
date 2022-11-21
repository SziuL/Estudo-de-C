#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double delta(double a, double b, double c){
	double conta;
	conta = b*b - 4 * a * c;
	return conta;
}

int main(){
	double a, b, c;
	double deltaa;
	
	scanf("%lf%lf%lf", &a, &b, &c);
	deltaa = delta(a,b,c);
	double a2 = 2*a;

	if(deltaa < 0){
		printf("Impossivel calcular\n");
	}else if( deltaa == 0 ) {
		printf( "The only root is: %.5f", (-b+sqrt(deltaa))/a2 );
	}else{
		printf("R1 = %.5lf\n", (-b+sqrt(deltaa))/a2 );
		printf("R2 = %.5lf\n", (-b-sqrt(deltaa))/a2 );
	}
	
	return 0;	
}