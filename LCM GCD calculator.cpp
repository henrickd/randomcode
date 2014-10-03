#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;


int le_prime_counter(int testvalue) /* This function returns the number of primes smaller than or equal to the test value to define the size of the array holding them */
{	
	int modresult, primecount=1;
	
	for (int i=testvalue; i>=2; i--) /* This loop tests every number smaller than or equal to the test value to determine if they are prime and, if so, adds to the counter */
	{	
		for (int j=2; j<i; j++)
		{
			modresult = i%j;
			if (modresult == 0)
				break;
			if (j == i-1)
				primecount++;
		}

	}
	return primecount;
	
}

int* le_prime_finder(int testvalue, int arrsize) /* This function returns a list of primes that are smaller than or equal to the test values */
{
	int modresult, arrcount=0, scndline=0, quotient=testvalue, arr[arrsize];
	int *arraypoint;
	arraypoint = (int*) malloc(2*arrsize*sizeof(int));
		
	for (int i=testvalue; i>=2; i--) /* This loop writes every prime smaller than or equal to the test value into an array */
	{	
		for (int j=2; j<i; j++)
		{
			modresult = i%j;
			if (modresult == 0)
				break;
			if (j == i-1)
			{
				arr[arrcount]=i;
				arrcount++;
			}
				
		}
	
	}
	arr[arrcount]=2;
	
	for (int k=0; k<=arrcount; k++) /* This loop assigns every prime which is smaller than or equal to the test value to a pointer */
	{
		*(arraypoint+k) = (arr[arrcount-k]);
	}
	return arraypoint;
}

int* le_prime_factorer(int testvalue, int arrsize) /* This function factors the test value into primes */
{
	int modresult, arrcount=0, quotient=testvalue, arr[2][arrsize];
	int *arraypoint;
	arraypoint = (int*) malloc(2*arrsize*sizeof(int));
		
	for (int i=testvalue; i>=2; i--) /* This loop writes every prime smaller than or equal to the test value into an array */
	{	
		for (int j=2; j<i; j++)
		{
			modresult = i%j;
			if (modresult == 0)
				break;
			if (j == i-1)
			{
				arr[0][arrcount]=i;
				arrcount++;
			}
				
		}
	
	}
	arr[0][arrcount]=2;

	for (int set=arrcount; set>=0; set--) /* This loop sets all the elements of the array corresponding to the exponents of the primes to 0 */
	{
		arr[1][set]=0;
	}
	
	for (int j=arrcount; j>=0; j--) /* This loop factors the test value into primes by attempting division by all primes smaller than or equal to the test value */
	{
		for (;;)
		{
			modresult = quotient%arr[0][j];
			if (modresult != 0)
				break;
			else if (modresult == 0)
			{
				quotient=quotient/arr[0][j];
				arr[1][j]++;
			}
			
		}
		
	}
	
	for (int k=0; k<=arrcount; k++) /* This loop assigns every prime which is smaller than or equal to the test value to a pointer */
	{
		*(arraypoint+k) = (arr[1][arrcount-k]);
	}
	return arraypoint;
}

int le_lcm_finder(int *arr1, int *arr2, int *exp_arr1, int *exp_arr2, int number1, int number2, int count1, int count2) /* This function finds the LCM of number1 and number2 */
{
	int accumulator=1, no1=number1, no2=number2;
	
	if (number1>=number2) /* This condition makes sure that if number1 is greater than number2, number2's prime factorization is checked first */
	{
		int lcm_arr[count1];
		int lcm_exp_arr[count1];
		
		for (int set=0; set<count1; set++) /* This loop sets all the elements of the array corresponding to the exponents of the primes to 0 */
		{
			lcm_exp_arr[set]=0;
		}
		
		for (int i=0;i<count1;i++) /* This loop determines the primes that can be part of the prime factorization of the LCM */
		{
			lcm_arr[i]=*(arr1+i);
		}
		
		for (int j=0;j<count2;j++) /* This loop determines the smallest possible exponents of the primes for the prime factorization of the LCM */
		{
			lcm_exp_arr[j]=exp_arr2[j];
		}
		
		for (int k=0;k<count1;k++) /* This loop determines the largest possible exponents of the primes for the prime factorization of the LCM*/
		{
			if (exp_arr1[k]>lcm_exp_arr[k])
				lcm_exp_arr[k]=exp_arr1[k];
		}
		
		for (int l=0;l<count1;l++) /* This loop constructs the LCM from its prime factorization */
		{
			accumulator = accumulator*pow(lcm_arr[l],lcm_exp_arr[l]);
		}
	}
	
	else if (number2>=number1) /* This condition makes sure that if number2 is greater than number1, number1's prime factorization is checked first */
	{
		int lcm_arr[count2];
		int lcm_exp_arr[count2];
		
		for (int set=0; set<count2; set++) /* This loop sets all the elements of the array corresponding to the exponents of the primes to 0 */
		{
			lcm_exp_arr[set]=0;
		}
		
		for (int i=0;i<count2;i++) /* This loop determines the primes that can be part of the prime factorization of the LCM */
		{
			lcm_arr[i]=*(arr2+i);
		}
		
		for (int j=0;j<count1;j++) /* This loop determines the smallest possible exponents of the primes for the prime factorization of the LCM */
		{
			lcm_exp_arr[j]=exp_arr1[j];
		}
		
		for (int k=0;k<count1;k++) /* This loop determines the largest possible exponents of the primes for the prime factorization of the LCM*/
		{
			if (exp_arr2[k]>lcm_exp_arr[k])
				lcm_exp_arr[k]=exp_arr2[k];
		}
		
		for (int l=0;l<count2;l++) /* This loop constructs the LCM from its prime factorization */
		{
			accumulator = accumulator*pow(lcm_arr[l],lcm_exp_arr[l]);
		}	
	}
	return accumulator;
}

int le_gcd_finder(int *arr1, int *arr2, int *exp_arr1, int *exp_arr2, int number1, int number2, int count1, int count2) /* This function finds the GCD of number1 and number2 */
{
	int accumulator=1, no1=number1, no2=number2;
	
	if (number1>=number2) /* This condition makes sure that if number1 is greater than number2, number2's prime factorization is checked first */
	{
		int gcd_arr[count1];
		int gcd_exp_arr[count1];
		
		for (int set=0; set<count1; set++) /* This loop sets all the elements of the array corresponding to the exponents of the primes to 0 */
		{
			gcd_exp_arr[set]=0;
		}
		
		for (int i=0;i<count1;i++) /* This loop determines the primes that can be part of the prime factorization of the GCD */
		{
			gcd_arr[i]=*(arr1+i);
		}
		
		for (int j=0;j<count2;j++) /* This loop determines the largest possible exponents of the primes for the prime factorization of the GCD */
		{
			gcd_exp_arr[j]=exp_arr2[j];
		}
		
		for (int k=0;k<count1;k++) /* This loop determines the smallest possible exponents of the primes for the prime factorization of the GCD */
		{
			if (exp_arr1[k]<gcd_exp_arr[k])
				gcd_exp_arr[k]=exp_arr1[k];
		}
		
		for (int l=0;l<count1;l++) /* This loop constructs the GCD from its prime factorization */
		{
			accumulator = accumulator*pow(gcd_arr[l],gcd_exp_arr[l]);
		}
	}
	
	else if (number2>=number1)
	{
		int gcd_arr[count2];
		int gcd_exp_arr[count2];
		
		for (int set=0; set<count2; set++) /* This loop sets all the elements of the array corresponding to the exponents of the primes to 0 */
		{
			gcd_exp_arr[set]=0;
		}
		
		for (int i=0;i<count2;i++) /* This loop determines the primes that can be part of the prime factorization of the GCD */
		{
			gcd_arr[i]=*(arr2+i);
		}
		
		for (int j=0;j<count1;j++) /* This loop determines the largest possible exponents of the primes for the prime factorization of the GCD */
		{
			gcd_exp_arr[j]=exp_arr1[j];
		}
		
		for (int k=0;k<count2;k++) /* This loop determines the smallest possible exponents of the primes for the prime factorization of the GCD */
		{
			if (exp_arr2[k]<gcd_exp_arr[k])
				gcd_exp_arr[k]=exp_arr2[k];
		}
		
		for (int l=0;l<count2;l++) /* This loop constructs the GCD from its prime factorization */
		{
			accumulator = accumulator*pow(gcd_arr[l],gcd_exp_arr[l]);
		}
	}
	return accumulator;
}

int main()
{
	
	int number1, number2, count1, count2;
	int *arr1, *exp_arr1, *arr2, *exp_arr2;
	string calctype;
	cout << "Enter \"LCM\" to calculate the lowest common multiple of 2 numbers or \"GCD\" to\ncalculate the greatest common divisor of 2 numbers: ";
	getline(cin,calctype);
	
	if (calctype == "LCM")
	{
		int lcm;
		cout << "\nEnter both numbers for which you want to calculate the LCM:\n";
		cin >> number1;
		cin >> number2;
		if ((number1 == 0) || (number2 == 0))
		{
			cout << "\nThe LCM of " << number1 << " and " << number2 << " is 0.";
			exit;

		}
			
		else if (number1 == 1)
		{
			cout << "\nThe LCM of " << number1 << " and " << number2 << " is " << number2 << ".";
			exit;
		}
		
		else if (number2 == 1)
		{
			cout << "\nThe LCM of " << number1 << " and " << number2 << " is " << number1 << ".";
			exit;
		}
		else
		{
			count1 = le_prime_counter(number1);
			count2 = le_prime_counter(number2);
			arr1 = le_prime_finder(number1, count1);
			arr2 = le_prime_finder(number2, count2);
			exp_arr1 = le_prime_factorer(number1, count1);
			exp_arr2 = le_prime_factorer(number2, count2);
			for (int l=0;l<count2;l++)
			lcm = le_lcm_finder(arr1, arr2, exp_arr1, exp_arr2, number1, number2, count1, count2);
			cout << "\nThe LCM of " << number1 << " and " << number2 << " is " << lcm << ".\n\n";
		}
}

	else if (calctype == "GCD")
	{
		int gcd;
		cout << "\nEnter both numbers for which you want to calculate the GCD:\n";
		cin >> number1;
		cin >> number2;
		if ((number1 == 1) || (number2 == 1))
		{
			cout << "\nThe GCD of " << number1 << " and " << number2 << " is 1.";
			exit;

		}
			
		else if (number1 == 0)
		{
			cout << "\nThe GCD of " << number1 << " and " << number2 << " is " << number2 << ".";
			exit;
		}
		
		else if (number2 == 0)
		{
			cout << "\nThe GCD of " << number1 << " and " << number2 << " is " << number1 << ".";
			exit;
		}
		else
		{
			count1 = le_prime_counter(number1);
			count2 = le_prime_counter(number2);
			arr1 = le_prime_finder(number1, count1);
			arr2 = le_prime_finder(number2, count2);
			exp_arr1 = le_prime_factorer(number1, count1);
			exp_arr2 = le_prime_factorer(number2, count2);
			for (int l=0;l<count2;l++)
			gcd = le_gcd_finder(arr1, arr2, exp_arr1, exp_arr2, number1, number2, count1, count2);
			cout << "\nThe GCD of " << number1 << " and " << number2 << " is " << gcd << ".\n\n";
		}
	
	}
	else
		exit;
	system("pause");
	return 0;
}

