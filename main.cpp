 // Темы:
// Простое наследование. Виртуальные функции. Абстрактные классы.
// Битовые поля.


// #include <tchar.h>
#include <iostream>
#include "myString.h"

using namespace std;

#define	  stop 

int main(int argc, char* argv[])
{

        std::cout << "Ok\n";

            
        {
        
            MyString s("test");
            MyString s1("test");
            MyString s2("test");
            MyString s3("test");
            std::cout << s << "\n";
        } //see desctructr

        {
            MyString s1("xyz");
            MyString s2("abc");
            MyString s3("def"); 
            MyString s4("abx");
            MyString s7("test");
            std::cout << s1 << " - " << s2 <<  " " <<  s3 << "\n";
            
            
            MyString::PrintAllString();
            MyString::ChnageRegisterAllString();
            MyString::PrintAllString();
            MyString::ChnageSortAllString();
            MyString::PrintAllString();
            
        }
	
	return 0;
}//endmain


