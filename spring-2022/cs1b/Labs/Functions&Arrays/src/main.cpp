#include <iostream>
#include <fstream>
#include <string>

void readData(std::string fileName, size_t arraySize, int arrayofInts[], float arrayofFloats []);
double averageForIntegerDataset(size_t arraySize, int arrayofInts[]);

int main()
{
	std::string fileName {"data.txt"};
	std::string temp {};
	size_t arraySize {};
	std::fstream fin(fileName, std::ios::in);
	while(std::getline(fin, temp))
		++arraySize;
	arraySize /= 2;
	fin.close();

	int arrayofInts[arraySize];
	float arrayofFloats[arraySize];
	readData(fileName, arraySize, arrayofInts, arrayofFloats);

	std::cout << "Array of ints: ";
	for(size_t i {0}; i < arraySize; i++)
		std::cout << "[" << arrayofInts[i] << "] ";

	std::cout << "\nArray of floats: ";
	for(auto i : arrayofFloats)
		std::cout << "[" << i << "] ";

	std::cout << "\nAverage for ints: " << averageForIntegerDataset(arraySize, arrayofInts) << "\n";
	return 0;
}

void readData(std::string fileName, size_t arraySize, int arrayofInts[], float arrayofFloats [])
{
	std::fstream fin(fileName, std::ios::in);
	for(size_t i {0}; i < arraySize; i++)
	{
		fin >> arrayofInts[i] >> arrayofFloats[i];
	}
}
double averageForIntegerDataset(size_t arraySize, int arrayofInts[])
{
	double sum {};
	for(size_t i {0}; i < arraySize; i++)
		sum += arrayofInts[i];

	return sum/arraySize;
}