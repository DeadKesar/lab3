#pragma once
#include "Vector.h"
#include "MyString.h"
#include <iostream>
#include <sstream>

int GetNumber(char const* s);
MyString* NumToChar(int num);
MyString* VectorToString(Vector vec);
char GetChar();

int main()
{
    setlocale(LC_ALL, "Rus");


    std::cout << std::endl << "Введите предложение: ";
    MyString* str1 = new MyString();
    str1->GetInput();
    std::cout << std::endl << "Проверим конец: ";
    MyString* str2 = new MyString();
    str2->GetInput();
    if (str1->EndsWith(*str2))
    {
        std::cout << std::endl << "Yes";
    }
    else
    {
        std::cout << std::endl << "No";
    }
    std::cout << std::endl << "Проверим начало: ";
    MyString* str3 = new MyString();
    str3->GetInput();
    if (str1->StartsWith(*str3))
    {
        std::cout << std::endl << "Yes";
    }
    else
    {
        std::cout << std::endl << "No";
    }
    std::cout << std::endl << "Найёдм первое вхождение символа: ";
    MyString* str4 = new MyString();
    str4->GetInput();
    std::cout << std::endl << str1->IndexOf(*str4);

    std::cout << std::endl << "Используем символ разделитель: ";
    char ch = getchar();
    MyStringCollection* col = str1->Split(ch);
    if (col != nullptr)
    {
        for (int i = 0; i < col->length; i++)
        {
            std::cout << std::endl << col->collection[i].GetStr();
        }
    }


    std::cout << std::endl;
    std::cout << std::endl;

    Vector* vect = new Vector((new int[]{ 1,2,3,4,5,6,7,8,9,10 }),10);
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

    MyStringCollection *s = str->Split('|');
    std::cout << std::endl;
    for (int i = 0; i < s->length; i++)
    {
        std::cout << s->collection[i].GetStr() << " / ";
    }
    std::cout << std::endl;

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
char GetChar()
{
    char ch = ' ';
    while (true)
    {
        std::cout << "Введите символ разделитель: " << std::endl;
        std::cin >> ch;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << L"некоректное значение, попробуйте снова." << std::endl;
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        return ch;
    }
}