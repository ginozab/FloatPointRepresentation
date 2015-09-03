//**************************
// Brandon Ginoza
// Computer Science 210
// Lab 6
// Purpose: Convert float point decimal into 
// binary hex and IEEE 754 also give sign, exponent,
// fraction and significand
//**************************

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>


// define true and false for use in loops
#define true 1
#define false (!true)


// Function to print out arrays of binary
// Pass in g as arguement that way I can use it for
// multiple arrays

void PrintArray(int array[],int g){
	int j;
	for (j = 0; j < g; j++){
	printf("%d", array[j]);
	}

}

// Same as previous print function but needed to start 
// at 0 instead of 1
void PrintArrayFB(int array[],int g){
	int j;
	
	for (j = 0; j < g; j++){
	printf("%d", array[j]);
	}

}


// Function to convert Integer part of float into binary
int IntegerConvert(int a, int array[]) {
	int i = 19;
	
	// loop through dividing number by 2
	while(true){
		// if a = 0 get out of loop
		if (a ==0) {
		break;
		}

		// if a / 2 has no remainder put 0 into array
		if (a%2 == 0){
		array[i] = 0;
		}

		// if a / 2 has a remainder put 1 into array
		if (a%2 !=0){
		array[i] = 1;
		}

		// divide a / 2 after checks
		a = a/2;

		// decrement counter. This also acts as a counter 
		// that is the opposite of the exponent
		i--;
	}
	
	// return opposite of exponent
	return i+1;
	
}

// Function to convert biased exponent into binary
void ExponentConvert(int a, int array[]) {
	int i = 7;

		while(true){
		// if = 0 break out of loop
		if (a ==0) {
		break;
		}
		
		// if no remainder add 0 to array
		if (a%2 == 0){
		array[i] = 0;
		}
		
		// if remainder add 1 to array
		if (a%2 !=0){
		array[i] = 1;
		}
			
		// divide a by 2
		a = a/2;

		// decrement counter
		i--;
	}
	
	//return i;
	
}

// function to convert float fraction of user input
void FractionConvert(float f, int array[]){

	int c = 0;
	// if fraction is 0 skip code
	if (f != 0){
	// break if f = 1 & c = 50
	while (f != 1 & c != 50){
		
		// times f by 2
		f = f * 2;
		
		// if f > 1 put 1 into array and then 
		// subtract 1 from f to get fraction
		if (f > 1.0){
		array[c] = 1;
		f = f - 1;
		}
		
		// if f < 1 just put in 0 to array
		else if (f < 1.0){
		array[c] = 0;
		}
		// add to counter
		c++;
	}
	// put final 1 into array
	array[c-1] = 1;
	}
	
}

// function to get the exponent for the float value
int GetExponent(int e, int array[]){

	// this if statement is if the integer is zero 
	// we have to look into the binary fraction array
	if (e == 20){
	
	// initialize counters
	int g = 0;
	int k = 0;
	int check;

	while (true){
		
		// get value of array at point
		check = array[g];
		
		// if the value is a one it is the 
		// first one therefore return the value of k counter
		// and break out of loop 
		if (check == 1){
		return k - 1;
		break;
		}
		
		// if the value is equal to zero continue through
		// the array and move the counters along
		if (check == 0){
		g++;
		k--;
		}

	}
	}
	
	// if there is an integer then to get exponent
	// subtract the given parameter in e from 19
	else {
	return 19 - e;
	}
}

// function to get the IEEE fraction part
void BinaryFraction(int v, int Iarray[], int Farray[], int FBarray[]){
	int FB = 0;
	// if the exponent of the float is positive
	if (v > 0){
		
		// this for loop takes the integer part of the binary
		// and puts it into FBarray
		int dec = 20 - v;
		int z;
		for (z = dec; z < 20; z++){
			FBarray[FB] = Iarray[z];
			FB++;
		}
		
		// this for loop takes the fraction part of the binary
		// and puts it into FBarray

		int Fa = 0;
		int a;
		for (a = FB; a < 23; a++){
			FBarray[a] = Farray[Fa];
			Fa++;
	}
	}
	
	// if the exponent of the float is negative
	else if (v < 0 || v == 0) {

		int FBa = 0;

		// start counter at correct spot in Farray
		int move = abs(v);
		
		//printf(" %d ", move);
		int m;
		
		// for loop that takes values from Farray and puts them
		// into the FBarray until FBarray is filled
		for (m = move; m < (23+ move); m++){
			
			FBarray[FBa] = Farray[m];
			FBa++;

		}
		
	}

}

// this function gets the fraction part of the output
float GetFraction(int array[]){
	// initialize fraction value
	float fr = 0.0;
	
	// loop through IEEE fraction array and multiply
	// each value by 2 to the negative position in array
	// I times by the value of the array at each point
	// therefore if it is a zero it wont add to the fraction
	int r;
	for(r = 1; r <= 23; r++){
		
		fr = fr + pow(2,-r) * array[r-1];	
		
	}
	// return
	return fr;

}


int main() {
	
	time_t now;
	time(&now);
	printf("Brandon Ginoza \nLab6\n%s\n", ctime(&now));

	// array for integer part of binary conversion
	int IBinary[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	// array for fraction part of binary conversion
	int FBinary[50] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	// array for exponent part of IEEE
	int EBinary[8] = {0,0,0,0,0,0,0,0};
	// array for fraction part of IEEE
	int FracBinary[23] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	// initialize user input variable
	float Fnum;
	
	// prompt/ take in user input
	printf("Enter a float value: ");
	scanf("%f", &Fnum);

	// print out the hex value of the user input
	printf("In hex: ");
	printf("%X\n", *(int *)&Fnum);
	
	// get absolute value of the integer part of user input float
	int rounded = abs((int)Fnum);
	// get the absolute value of user input
	float fab = (float)fabs(Fnum);
	// get fraction of user input float 
	float fraction = fab - rounded;

	// convert integer part of user float into binary
	IntegerConvert(rounded, IBinary);
	//PrintArray(IBinary,20);
	//printf(".");

	// convert fraction part of user float into binary
	FractionConvert(fraction, FBinary);
	//PrintArray(FBinary,50);
	//printf("\n");

	// if user float is positive print 0 for IEEE binary
	if (Fnum > 0){
	printf("0 ");
	}
	
	// if user float is negative print 1 for IEEE binary
	if (Fnum < 0){
	printf("1 ");
	}
	
	// get opposite value of exponent to use in GetExponent function
	int exp = IntegerConvert(rounded,IBinary);

	// get the exponent of the user float
	int exponent = GetExponent(exp,FBinary);
	// get decimal biased exponent for IEEE binary
	int biased = 127 + exponent;
	
	// convert / print the binary of the biased exponent
	ExponentConvert(biased,EBinary);
	PrintArray(EBinary,8);
	
	// get/ print the fraction for the IEEE binary
	printf(" ");
	BinaryFraction(exponent, IBinary, FBinary, FracBinary);
	PrintArrayFB(FracBinary,23);



	// if user float is greater than 0 print +
	if (Fnum > 0){
	printf("\nSign: +\n");
	}
	// if user float is less than 0 print -
	if (Fnum < 0){
	printf("\nSign: -\n");
	}
	
	int exponent1 = GetExponent(exp,FBinary);
	// print out exponent
	printf("Exponent: 2^");
	printf("%d\n",exponent);
	
	// get significand
	float frac = GetFraction(FracBinary);
	
	// get / print out fraction
	float sig = frac + 1;
	printf("Fraction: %f\n",frac);

	// print significand
	printf("Significand: %f\n", sig);
	

}

