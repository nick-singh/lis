#include <stdio.h>
#include <stdlib.h>

#define max 50

int A[max], E[max], L[max], i, j, n;

FILE* in, *out;


void LIS(){
	for(i = 0; i<n; i++){
		E[i] = i;
		L[i] = 1;
	}
	for(i = 1; i<n; i++){
		for(j=0; j<i; j++){
			if(A[i] > A[j] && L[i] < L[j] +1){
				L[i] = L[j] +1;
				E[i] = j;
			}			
		}
		
	}
}


int main()
{
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");

	fscanf(in, "%d", &n);

	for(i=0;i<=n;i++){
		fscanf(in, "%d", &A[i]);		
	}

	LIS();

	for (i = 0; i < n; i++)
	{
		printf("E[%d] = %d, L[%d] = %d\n",i+1,E[i]+1,i+1,L[i]);
	}

	fclose(in);
	fclose(out);

	return 0;
}