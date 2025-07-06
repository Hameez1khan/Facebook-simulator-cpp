#pragma once
#include "member.cpp"
#include <iostream>
#include <string>
#include <stdbool.h>
#include <fstream>
#include <sstream>
using namespace std;


class container
{
    int elementNum;
    member * pData;
    public:
    container():elementNum(0),pData(NULL){}
    ~container(){
        for(int i = 0; i < elementNum; i++ ){
            delete[] pData[i].group; 
        }
        delete[] pData;}

    void add_member() {
        
        member* new_data = new member[elementNum + 1];

      
        for (int i = 0; i < elementNum; ++i) {
            new_data[i] = pData[i];
        }

        
        new_data[elementNum].fill();

        delete[] pData;
       
        pData = new_data;

    
        ++elementNum;
    }

    void delete_member(){
        
        string name;
        cout << "Enter the member nick_name to be deleted: ";
        cin >> name;

        int count = 0;
        for(int i = 0; i < elementNum; i++){
            if(pData[i].nick_name.compare(name) == 0){
                count++;
                member* new_data = NULL;
                if(elementNum > 1){
        
                   member* new_data = new member[elementNum - 1];
                }
        
                for (int j = 0; j < elementNum-1; j++) {
                    
                    if(j >= i){
                       new_data[j] = pData[j+1];
                    }
                    else{
                       new_data[j] = pData[j];
                    }

                }
                
                
                

                delete[] pData;
        
                pData = new_data;

        
                elementNum--;
                i--;
            }
        } 
    }

    void add_member(const member & to_add){
        member* new_data = new member[elementNum + 1];

      
        for (int i = 0; i < elementNum; i++) {
            new_data[i] = pData[i];
        }

        
        new_data[elementNum] = to_add;

        delete[] pData;
       
        pData = new_data;

    
        elementNum++;
    }

    void display() const{
        for(int i = 0 ; i < elementNum ; i++){

            cout << "nick name: " << pData[i].nick_name << endl ;
            cout << "family name: " << pData[i].family_name << endl;
            cout << "given name: " << pData[i].given_name << endl;
            cout << "place: " << pData[i].place << endl;
            pData[i].birth.show();
            cout << "The user had joined " << pData[i].group_total << " group(s)" << endl;
            for(int j = 0 ; j < pData[i].group_total ; j++){
                cout << "group" << j+1 << " : " << pData[i].group[j] << endl;
            }
            cout << endl << endl << endl;

        }
    }

    void display_single_member(int position){
        cout << "nick name: " << pData[position].nick_name << endl ;
        cout << "family name: " << pData[position].family_name << endl;
        cout << "given name: " << pData[position].given_name << endl;
        cout << "place: " << pData[position].place << endl;
        pData[position].birth.show();
        cout << "The user had joined " << pData[position].group_total << " group(s)" << endl;
        for(int j = 0 ; j < pData[position].group_total ; j++){
            cout << "group" << j+1 << " : " << pData[position].group[j] << endl;
        }
        cout << endl << endl << endl;
    }

    void search_member(){
        string name;
        int count = 0;
        cout << "Enter the member nick_name: " ;
        cin >> name;

        for (int i = 0 ; i < elementNum; i++)
            if(pData[i].nick_name.compare(name) == 0 )
            {
                display_single_member(i);
                count++;
            }

        
        if (count== 0) 
           cout << endl <<"No member with such nick name exists" << endl;
    }



    void add_member_in_group() {
    string group, nick_name;
    bool memberFound = false, groupAdded = false;
    cout << "Enter a group to add: ";
    cin >> group;

    cout << "Enter the member nickname to add in group: ";
    cin >> nick_name;

   
    for (int i = 0; i < elementNum; i++) {
        if (pData[i].nick_name == nick_name) {
            memberFound = true;

            
            bool alreadyInGroup = false;
            for (int j = 0; j < pData[i].group_total; j++) {
                if (pData[i].group[j] == group) {
                    alreadyInGroup = true;
                    cout << "Member already in this group." << endl;
                    break;
                }
            }

            if (!alreadyInGroup) {
                string* newGroups = new string[pData[i].group_total + 1];
                for (int k = 0; k < pData[i].group_total; k++) {
                    newGroups[k] = pData[i].group[k];
                }
                newGroups[pData[i].group_total] = group;
                delete[] pData[i].group;
                pData[i].group = newGroups;
                pData[i].group_total++;
                groupAdded = true;
                cout << "Member successfully added to the group." << endl;
            }
            break;
        }
    }

    

    
        if (!memberFound) 
        {
            cout << "Member with the nickname '" << nick_name << "' not found." << endl;
        } 
        
        else if (groupAdded)
        {
            cout << "Group '" << group << "' added to " << nick_name << "'s list." << endl;
        }
    }

 
    void delete_member_in_group() {
    string group, nick_name;
    bool memberFound = false, groupDeleted = false;
    cout << "Enter the group from which to remove: ";
    cin >> group;
    cout << "Enter the member nickname to remove from the group: ";
    cin >> nick_name;

        
        for (int i = 0; i < elementNum; i++) {
            if (pData[i].nick_name == nick_name) {
                memberFound = true;

               
                for (int j = 0; j < pData[i].group_total; j++) {
                    if (pData[i].group[j] == group) {
                       


                        for (int k = j; k < pData[i].group_total - 1; k++) {
                            pData[i].group[k] = pData[i].group[k + 1];
                        }
                        pData[i].group_total--;
                        


                        groupDeleted = true;
                        cout << "Member removed from the group successfully." << endl;
                        break;
                    }
                }
                if (!groupDeleted) {
                    cout << "Member not found in the specified group." << endl;
                }
                break;
            }
        }

        if (!memberFound) {
            cout << "Member with the nickname '" << nick_name << "' not found." << endl;
        } else if (groupDeleted) {
            cout << "Group '" << group << "' removed from " << nick_name << "'s list." << endl;
        }
    }




    void print_group_members(){

    cout << "Enter a group name:"; 
    string group_name;
    cin >> group_name;

    bool found = false;  

    for(int i = 0; i < elementNum ; i++)
        for(int j = 0; j < pData[i].group_total; j++){
            if(pData[i].group[j].compare(group_name) == 0){

                display_single_member(i);

                found = true;

                break;                    
            }
        }
    

        if (!found) 
            cout << "No members found in the group " << group_name << "." << endl;
    
    }


    void save_data_to_file() {
    ofstream outFile("facebook.txt"); 

    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    
    for (int i = 0; i < elementNum; i++) {
        outFile << pData[i].nick_name << ",";
        outFile << pData[i].family_name << ",";
        outFile << pData[i].given_name << ",";
        outFile << pData[i].place << ",";
        pData[i].birth.save_to_file(outFile); 
        outFile << pData[i].group_total ;
        if(pData[i].group_total > 0)
           outFile << ",";

        // Save group information if any
        for (int j = 0; j < pData[i].group_total; j++) {
            outFile << pData[i].group[j];
            if (j < pData[i].group_total - 1)
                outFile << ","; // Use semicolon to separate groups
        }
        outFile << "\n"; 
        }

    outFile.close(); 
    cout << "Data successfully saved to facebook.txt" << endl;
    }

   void load_data_from_file() {
        ifstream inFile("facebook.txt");  // Open the file

        if (!inFile) {
            cerr << "Error opening file for reading." << endl;
            return;
        }

        string line;
        while (getline(inFile, line)) {  
            if (line.empty()) continue;  

            stringstream ss(line);
            int y,m,d,group_total;
            string nick_name, family_name, given_name, place, birthStr, groupStr,g_total;
            getline(ss, nick_name, ',');
            getline(ss, family_name, ',');
            getline(ss, given_name, ',');
            getline(ss, place, ',');
            getline(ss, birthStr, ',');
            getline(ss, g_total, ',');
            

            group_total = stoi(g_total);

            istringstream dateStream(birthStr);
            char delimiter;  
            dateStream >> y >> delimiter >> m >> delimiter >> d ;

            member newMember;
            newMember.nick_name = nick_name;
            newMember.family_name = family_name;
            newMember.given_name = given_name;
            newMember.place = place;
            newMember.birth.change_date(y,m ,d ); 
            newMember.group_total = group_total;
            newMember.group = new string[group_total];

            
            if (group_total > 0) {
                getline(ss, groupStr, '\n'); 
                stringstream groupSS(groupStr);
                string group;
                int i;
                for (i = 0; i < group_total-1; i++) {
                    getline(groupSS, group, ',');
                    newMember.group[i] = group;
                }
                
                getline(groupSS, group, '\n');
                newMember.group[i] = group;
            }

            add_member(newMember); 
        }

        inFile.close();
        cout << "Data successfully loaded from facebook.txt" << endl;
    }



};
