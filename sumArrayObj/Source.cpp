#include<iostream>
#include<array>

int sumArray(std::array<int, 10> myArray);

int main()
{
	std::array<int, 10> myArray;

	for (int i = 0; i < myArray.size(); i++)
	{
		std::cout << "Insert a number in the array: ";
		int num;
		std::cin >> num;
		myArray[i] = num;
	}
	std::cout << "Sum of myArray is " << sumArray(myArray);
}

int sumArray(std::array<int, 10> myArray)
{	
	int sum = 0;
	for ( auto item : myArray){
		sum += item;
	}

	return sum;

}