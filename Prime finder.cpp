#include <iostream>
using namespace std;

int main ()
{
	int number;
	int testvalue;
	int divider;
	int modresult;
	int primecount=1;
	cout << "Enter the upper bound for the list of prime numbers: ";
	cin >> number;
	if (number<2)
		cout << "There are no prime numbers equal to or smaller than the one you entered.\n";
	else
	{
		cout << "The primes smaller than or equal to " << number << " are: ";
		for (testvalue=number; testvalue >=2; testvalue--)
		{	
			for (divider=2; divider<=testvalue; divider++)
			{
				modresult = testvalue%divider;
				if (modresult == 0)
					break;
				if (divider == testvalue-1)
				{
					primecount++;
					cout << testvalue;
					cout << ",";
				}
				
			}
	
		}
		cout << "2.\n";
		cout << "There are " << primecount << " primes equal to or smaller than " << number << "\n";

	}
	system("pause");
	return 0;
}
