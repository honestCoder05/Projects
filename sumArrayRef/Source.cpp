#include<iostream>
#include<array>

void sumArray(std::array<int, 5> myArray, int &res);

int main()
{
	std::array<int, 5>myArray;
	int sum = 0;

	for (int i = 0; i < myArray.size(); i++)
	{
		std::cout << "Insert a number in myArray: ";
		int num;
		std::cin >> num;
		myArray[i] = num;
	}
	sumArray(myArray, sum);
	std::cout << "Sum of myArray is " << sum;

}

void sumArray(std::array<int, 5> myArray, int &sum)
{
	for (auto i : myArray)
	{
		sum += i;
	}
}