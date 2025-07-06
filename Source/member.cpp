#pragma once 
#include <iostream>
using namespace std;
#include "date.cpp"


class member 
{
    friend class container;
    string nick_name;
    string family_name;
    string given_name;
    string place;
    string *group;
    int group_total;
    Date birth;
    public:
    
    void add_group(){
        
        string name;
        cout << "How many groups to join?";
        cin >> group_total;
        group = new string[group_total];
        

        for(int i = 0 ; i < group_total ; i++){
            cout<< "Enter group " << i+1 << ":";
            cin >> name;
            group[i] = name;

        }
        
        
           
    }

    void fill(){
        char c;
        cout << "Enter nick name:";
        cin >> nick_name;
        cout << "Enter family name:";
        cin >> family_name;
        cout << "Enter given name:";
        cin >> given_name;
        cout << "Enter place name:";
        cin >> place;
        birth.add_date();

        group_total = 0;
        group = NULL;
        cin.clear();

        cout << "Do you want to join groups?(y/n)";
        cin >> c;
        while(c != 'y' && c != 'n'){
          cout << "Invalid Choice";
          cin >> c;   
        }
        if (c == 'y'){
            add_group();
        }


    }
    
    

};
