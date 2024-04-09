#include<iostream>

int sumArray(int myArray[], int n);

int main()
{
	const int n=5;
	int myArray[n];

	for (int i = 0; i < n; i++)
	{	
		std::cout << "Enter the element to be inserted in the array: ";
		int num;
		std::cin >> num;
		myArray[i] = num;
	}
	std::cout << "Sum of myArray is: " << sumArray(myArray, n);
}

int sumArray(int myArray[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += myArray[i];
	}
	return sum;
}