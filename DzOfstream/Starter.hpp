#ifndef STARTER_HPP
#define STARTER_HPP

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<Windows.h>
#include<string>

void Menu();
void FileCheck(std::string fileName,bool fileCheck);
void FileIn(std::string fileName);
void FileOut();

void AddToEnd(std::string*& arr, int& size, std::string element);
void DelDynArr(std::string*& arr);
void CrDynArr(std::string*& arr, int& size);
#endif // !STARTER_HPP
