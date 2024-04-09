#include<iostream>

int multiply(int num1, int num2, int num3);

int main()
{
	int num1, num2, num3;
	std::cout << "Enter three numbers for computing product: ";
	std::cin >> num1 >> num2 >> num3;
	
	std::cout << "Product of entered numbers is " << multiply(num1, num2, num3);

	return 0;

}

int multiply(int num1, int num2, int num3)
{
	return num1 * num2 * num3;
}