#pragma once
#include "Vector.h"
#include "MyString.h"
#include <iostream>
#include <sstream>

int GetNumber(char const* s);
MyString* NumToChar(int num);

int main()
{
    setlocale(LC_ALL, "Rus");

    MyString str = "aaa aaa qqq we  ee wrwe fsdf  fesf";   
    auto s = str.Split('a');

    for (int i = 0; i < s->length; i++)
    {
        std::cout << s->collection[i].GetStr() << " | ";
    }
    std::cout << std::endl;
    std::cout << NumToChar(255555) << " ";
    //std::cout << s->collection[0].GetStr() << " | " << s->collection[1].GetStr();



	//Vector *vect = new Vector();
	//int n = 0;
	//for (int i = 0; i < 20; i++)
	//{
	//	vect->Push(GetNumber("Введите число в вектор: "));
	//}
	//std::cout << std::endl;
	//for (int i = 0; i < 20; i++)
	//{
	//	std::cout << (*vect)[i] << ", ";
	//}
 //   std::cout << std::endl;
 //   int a[10]{ 1,2,3,45,46,47,48,49,50,10 };
 //   vect->AddRange(a,10);
 //   for (int i = 0; i < 30; i++)
 //   {
 //       std::cout << (*vect)[i] << ", ";
 //   }

}

int GetNumber(char const *s)
{
    int num;
    while (true)
    {
        std::cout << s;
        std::cin >> num;
        if (std::cin.fail()) //проверяем, не заблокирован ли буфер ввода, если да, значит значения ввода юыло некоректным.
        {
            std::cin.clear(); //возвращаем буфер в обычный режим
            std::cin.ignore(32767, '\n'); // очищаем буфер ввода
            std::cout << "некоректное значение, попробуйте снова" << std::endl; //просим повторный ввод
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очищаем буфер ввода от лишних символов, если таковые есть
            return num; // выходим из функции.
        }
    }
}
MyString VectorToString(Vector vec)
{
    MyString str = *(new MyString());
    for (int i = 0; i < vec.Length(); i++)
    {
        MyString temp = NumToChar(vec[i])->GetStr();
        str.AddRange(temp.GetStr(), temp.Length());
        delete[] &temp;
    }
    return str;
}
MyString* NumToChar(int num)
{
    MyString *str = new MyString();
    while (num > 0)
    {
        str->Push((char)(num % 10 + '0'));
        num /= 10;
    }
    return str;
}