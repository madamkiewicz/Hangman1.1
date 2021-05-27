#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <fstream>
using namespace std;

int main()
{
    fstream file;
    string line;

    int x=0;
    int y=0;
    int line_number=0;
    bool change_category = false;

    file.open("category.txt", ios::in);

    if(!file.good())
    {
        cout<<"blad pliku";
        exit(0);
    }

     while(getline(file,line))
    {
        if(line=="zmiana")
        {
            change_category=true;
        }
        else if(!change_category)
        {
             x++;
        }
        else
        {
            y++;
        }
    }

    file.close();
    cout<<x<<" "<<y;


    file.open("category.txt", ios::in);

    if(!file.good())
    {
        cout<<"blad pliku";
        exit(0);
    }


    string* fruit = new string[x];
    string* animal = new string[y];


    change_category=false;

    while(getline(file,line))
    {
        if(!file.eof())
        {
          if(line=="zmiana")
            {
            change_category=true;
            line_number=0;
            }
        else if(!change_category)
            {
             fruit[line_number]=line;
            }
        else if(change_category)
            {
            animal[line_number]=line;
            }
        }
        line_number++;
    }


    for(int i=0;i<x;i++)
    {
        cout<<"\n"<<fruit[i]<<" ";
    }

    for(int i=0;i<y;i++)
    {
        cout<<"\n"<<animal[i]<<" ";
    }

    file.close();

    delete [] fruit;
    delete [] animal;

    return 0;
}
