// 28.Write FFT program (fast Fourier transform) on a speech file and show the spectrogram

#include <math.h>
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>

// Function to calculate the DFT
void calculateDFT(int len)
{
	int xn[len];
	float Xr[len];
	float Xi[len];
	int i, k, n, N = 0;
	//	srand(getpid());
	for (i = 0; i < len; i++) 
	{
		//		xn[i]=rand()%1001;
		printf("Enter the value of x[%d]: ",i);
		scanf("%d", &xn[i]);
	}
	
	//calculating the fft
	for (k = 0; k < len; k++) 
	{
		Xr[k] = 0;
		Xi[k] = 0;
		for (n = 0; n <len; n++) 
		{
			Xr[k] = ( Xr[k] + xn[n] * cos(2 * 3.141592 * k * n / len) );

			Xi[k] = (Xi[k] + xn[n] * sin(2 * 3.141592 * k * n / len));
		}
		// printing the equation
		printf("(%f) + j(%f)\n", Xr[k], Xi[k]);
	}
}

int main()
{
	int len = 0;
	printf("Enter the length of "
			"the sequence: ");
	scanf("%d4", &len);
	calculateDFT(len);

	return 0;
}
