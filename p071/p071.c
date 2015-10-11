#include <stdio.h>
#include <math.h>

int gcd_iter (int u, int v){
	int t;
	while (v){
		t = u;
		u = v;
		v = t % v;
	}
	return u < 0 ? -u : u;
}

int main(){
	double answer;
	double max_val = 0;
	double d       = 1000000.0f;
	double n;
	
	do{
		n = floor(d * 3 / 7);

		while ( gcd_iter (n, d) != 1){
			n--;
		}

		if( (n/d) > max_val){
			max_val = n/d;
			answer = n;
		}
	}
	while (--d > 7);
	printf("%.0f \n", answer);
}
