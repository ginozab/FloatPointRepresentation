# FloatPointRepresentation

This is a program that I wrote in C. I wrote it for an undergraduate class at Allegheny College.

# What it does

This program takes any user inputed floating value, and then outputs the floating point representations.

This program outputs:

Hexadecimal Value

Binary Representation

The sign + or -

Then in decimal representation it outputs the exponent, the fraction, and the significand. 

# Examples

Running Instructions:

```shell
ginozab@aldenv100:~/cs210f2014-ginozab/lab6$ gcc -o FloatPoint FloatPoint.c -lm 
ginozab@aldenv100:~/cs210f2014-ginozab/lab6$ ./FloatPoint 
```

Example output:

```shell
Enter a float value: 13.875 
In hex: 415E0000 
0 10000010 10111100000000000000000 
Sign: + 
Exponent: 2^3 
Fraction: 0.734375 
Significand: 1.734375 

ginozab@aldenv100:~/cs210f2014-ginozab/lab6$ ./FloatPoint 

Enter a float value: .0005 
In hex: 3A03126F 
0 01110100 00000110001001001101111 
Sign: + 
Exponent: 2^-11 
Fraction: 0.024000 
Significand: 1.024000 
```
