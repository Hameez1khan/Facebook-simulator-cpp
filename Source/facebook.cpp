#include <iostream>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#include <limits.h>
#include "container.cpp"


using namespace std;




void menu(){
    cout << "Welcome to Facebook By Muhammad hameez khan"<< endl ;
    cout << "Please select among the follwing options" << endl << endl;
    cout << "1. Enter a new member in the data." << endl;
    cout << "2. search a member in the data." << endl ;
    cout << "3. delete a member in the data." << endl;
    cout << "4. add a member in a group" << endl;
    cout << "5. remove a group member." << endl;
    cout << "6. list all group members." << endl;
    cout << "7. list all the members in the data." << endl;
    cout << "8. Exit the program" << endl << endl;
}

int main()
{

    int choice;
    container data;

    data.load_data_from_file();
    do{
       menu();
       
       try{
        cin >> choice;
        system("cls");
        if (cin.fail()){
            throw runtime_error("Invalid input");
            getch();
        }
        cin.clear();
        
        
       }
       catch(exception &e){
        fflush(stdin);
        cerr << "Error: " << e.what() << endl;
        cout << "please Enter a correct choice" << endl ; 
    
        cin.clear();
        getch();
       }
       
       
       system("cls") ;
       switch(choice){
        case 1 : 
            data.add_member();
            getch();
            break;
        case 2:
            data.search_member();
            break;
        case 3:
            data.delete_member();
            break;
        case 4:
            data.add_member_in_group();
            break;
        case 5:
            data.delete_member_in_group();
            break;
        case 6:
            data.print_group_members();
            break;
        case 7:  
            data.display();
            break;
        case 8 :
            data.save_data_to_file();
            cout<< "goodbye" ; 
            break;
        }
        getch();


    }while(choice != 8);
    

    return 0;
}

