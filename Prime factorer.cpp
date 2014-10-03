#include <iostream>
using namespace std;

int number, testvalue, divider, modresult, modresult2, x=0;

void le_prime_counter()
{
	if (number <2)
		cout << "Numbers below 2 have no prime factorization";
		exit;
		
	for (testvalue=number; testvalue >=2; testvalue--)
	{	
		for (divider=2; divider<=testvalue; divider++)
		{
			modresult = testvalue%divider;
			if (modresult == 0)
				break;
			if (divider == testvalue-1)
			{
				x++;
			}
				
		}
	
	}
	x++;
}

void le_prime_finder_factorer()
{
	int y=0, quotient=number, symcounter=-1, arr[x];
		
	for (testvalue=number; testvalue >=2; testvalue--)
	{	
		for (divider=2; divider<=testvalue; divider++)
		{
			modresult = testvalue%divider;
			if (modresult == 0)
				break;
			if (divider == testvalue-1)
			{
				arr[y]=testvalue;
				y++;
			}
				
		}
	
	}
	arr[y]=2;

	int exp_arr[y+1];
	
	for (int set=y; set>=0; set--)
	{
		exp_arr[set]=0;
	}
	
	for (int i=y; i>=0; i--)
	{
		for (;;)
		{
			modresult = quotient%arr[i];
			if (modresult != 0)
				break;
			else if (modresult == 0)
			{
				quotient=quotient/arr[i];
				exp_arr[i]++;
			}
			
		}
		
	}
	for (int j=y; j>0; j--)
	{
		if (exp_arr[j] != 0)
			symcounter++;
	}

	cout << "The prime factorization of ";
	cout << number;
	cout << " is: ";
	for (int k=y; k>=0; k--)
	{
		if (exp_arr[k] != 0)
		{
			cout << arr[k];
			cout << "^";
			cout << exp_arr[k];
			if (symcounter>0)
			{
				cout << " x ";
				symcounter--;
			}
		}
		
	}
	cout << "\n";		
}



int main()
{
	cout << "Enter the number that you want to factor: ";
	cin >> number;
	le_prime_counter();
	le_prime_finder_factorer();
	system("pause");
	return 0;
}


