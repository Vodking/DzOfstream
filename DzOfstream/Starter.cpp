#include "Starter.hpp"

int sizeNames = 0;
int sizeCosts = 0;
int sizeCounts = 0;

std::string* namesArr = new std::string[sizeNames];
std::string* countsArr = new std::string[sizeCounts];
std::string* costsArr = new std::string[sizeCosts];


std::string dataIn;


std::string names = "Names.txt";
std::string costs = "Costs.txt";
std::string counts = "Counts.txt";

std::ofstream fileIn;

bool namesCheck = false;
bool costsCheck = false;
bool countsCheck = false;


char choice;

void Menu()
{

	int counter = 0;
	while(true)
	{
		std::cout << "Выберите файл:\n";
		std::cout << "1:Names.txt\n2:Costs.txt\n3:Counts.txt\n0:Выйти\n4:Таблица:\n";
		do
		{
			std::cin >> choice;
		} while (choice != '1' && choice != '2' && choice != '3' && choice != '0' && choice != '4');

		if (choice == '0')
		{
			break;
		}
		else if (choice == '1')
		{
			FileCheck(names,namesCheck);
			FileIn(names);
			namesCheck = true;
		}
		else if (choice == '2')
		{
			FileCheck(costs, costsCheck);
			FileIn(costs);
		}
		else if (choice == '3')
		{
			FileCheck(counts, countsCheck);
			FileIn(counts);
		}
		else if (choice == '4')
		{
			FileOut();
		}
	}
	DelDynArr(namesArr);
	DelDynArr(costsArr);
	DelDynArr(countsArr);

	

}

void FileCheck(std::string fileName,bool fileCheck)
{
	/*
	char sym = '*';
	fileOut.open(names);
	while (!fileOut.eof())
	{
		while (fileOut.get(sym))
		{
			if (sym != '*')
			{
				std::cout << "\nПерезаписать данные?\n";
				std::cout << "1 - Да 2 - Нет\n";
				do
				{
					std::cin >> choice;
				} while (choice != '1' || choice != '2');
				break;
			}
		}
	}
	fileOut.close();
	*/
	if (fileCheck)
	{
		std::cout << "\nПерезаписать данные?\n";
		std::cout << "1 - Да 2 - Нет\n";
		do
		{
			std::cin >> choice;
		} while (choice != '1' && choice != '2');
	}
}

void FileIn(std::string fileName)
{
	int counter = 0;
	if (choice == '1')
	{
		fileIn.open(fileName);
	}
	else if (choice == '2')
	{
		fileIn.open(fileName,std::ofstream::app);
	}
	do
	{
		counter++;
		std::cout << "Введите данные:";
		std::cin.ignore(32000, '\n');
		std::getline(std::cin, dataIn);
		std::cout << "Прекратить ввод товаров?\n";
		std::cout << "1 - Да";
		std::cin >> choice;
		fileIn << dataIn << '\n';
	} while (choice != '1');
	fileIn.close();
}

void FileOut()
{

	std::ifstream fileOut;
	std::string dataNames;
	std::string dataCosts;
	std::string dataCounts;
	char sym;
	dataNames = "";
	fileOut.open(names);
	while (!fileOut.eof())
	{
		while (fileOut.get(sym))
		{
			if (sym != '\n')
			{
				dataNames += sym;
			}
			else
			{
				AddToEnd(namesArr, sizeNames, dataNames);
			}

		}
	}
	fileOut.close();
	fileOut.open(costs);
	while (!fileOut.eof())
	{
		while (fileOut.get(sym))
		{
			if (sym != '\n')
			{
				dataCosts += sym;
			}
			else
			{
				AddToEnd(costsArr, sizeCosts, dataCosts);
			}

		}
	}
	fileOut.open(counts);
	while (!fileOut.eof())
	{
		while (fileOut.get(sym))
		{
			if (sym != '\n')
			{
				dataCounts += sym;
			}
			else
			{
				AddToEnd(countsArr, sizeCounts, dataCounts);
			}

		}
	}
	fileOut.close();
	std::cout << "ID название товара\tЦена\tКол-во\n";
	for (int i = 0; i < sizeNames; i++)
	{
		std::cout << i + 1 << ") " << namesArr[i] << "\t" << costsArr[i] << "\t" << countsArr[i];
	}
}

void AddToEnd(std::string*& arr, int& size, std::string element)
{
	std::string* temp = new std::string[size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	DelDynArr(arr);
	size++;
	CrDynArr(arr, size);
	for (int i = 0; i < size - 1; i++)
	{
		arr[i] = temp[i];
	}
	arr[size - 1] = element;
	DelDynArr(temp);
}

void DelDynArr(std::string*& arr)
{
	delete[] arr;
}

void CrDynArr(std::string*& arr, int& size)
{
	arr = new std::string[size];
}

