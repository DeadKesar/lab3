#pragma once
#include "Vector.h"
#include "MyString.h"
#include <iostream>
#include <sstream>

int GetNumber(char const* s);
MyString* NumToChar(int num);
MyString* VectorToString(Vector vec);

int main()
{
    setlocale(LC_ALL, "Rus");

    Vector* vect = new Vector((new int[]{ 1,2,3,4,5,6,7,8,9,10 }),10);
 /*   for (int i = 0; i < 10; i++)
    {
        vect->Push(GetNumber("Введите число в вектор: "));
    }*/
    std::cout << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << (*vect)[i] << ", ";
    }
    std::cout << std::endl;
    int a[10]{ 1,2,3,45,46,47,48,49,50,10 };
    vect->AddRange(a,10);
    for (int i = 0; i < 20; i++)
    {
       std::cout << (*vect)[i] << ", ";
    }

    MyString *str = VectorToString(*vect); 

    std::cout << std::endl<< str->GetStr();
    auto s = str->Split('|');

    std::cout << std::endl;
    for (int i = 0; i < s->length; i++)
    {
        std::cout << s->collection[i].GetStr() << " / ";
    }
    std::cout << std::endl;
    std::cout << NumToChar(12345)->GetStr() << " ";
    //std::cout << s->collection[0].GetStr() << " | " << s->collection[1].GetStr();

    MyString str2 = "Mather washed windows";
    std::cout <<std::endl << str2.GetStr();
    if (str2.EndsWith(*(new MyString("windows"))))
    {
        std::cout << std::endl << "Yes";
    }
    else
    {
        std::cout << std::endl << "No";
    }
    if (str2.StartsWith(*(new MyString("Mather"))))
    {
        std::cout << std::endl << "Yes";
    }
    else
    {
        std::cout << std::endl << "No";
    }

    std::cout << std::endl << str2.IndexOf(*(new MyString(" w")));
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
MyString* VectorToString(Vector vec)
{
    MyString *str = new MyString();
    for (int i = 0; i < vec.Length(); i++)
    {
        MyString temp = NumToChar(vec[i])->GetStr();
        str->AddRange(temp.GetStr(), temp.Length());
        str->Push('|');
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
    str->Reverse();
    return str;
}