//Vivek Bhandari
//January 13, 2019
//Bank Project-modified
#include <iostream>
using namespace std;
#include <ctime>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

int main()
{
    time_t currentTime = time(0);
    char * dateTime = ctime(&currentTime);
    cout<<dateTime<<endl;

    cout<<"     Welcome to HSBC Bank Canada"<<endl;
    cout<<"       Start Banking With Us"<<endl;
    cout<<"...Headstart Online Banking System..."<<endl;

    int option;
    srand(time(0));
    int randnum=rand()%(100-999+1)+1;

    cout<<"\n"<<randnum<<" is your verification code, you will need it to close and view all accounts"<<endl;

    menu:

    cout<<"\nSelect one option below"<<endl;
    cout<<"1: Open an Account"<<endl;
    cout<<"2: Balance Enquiry "<<endl;
    cout<<"3: Deposit "<<endl;
    cout<<"4: Withdrawal "<<endl;
    cout<<"5: Close an Account "<<endl;
    cout<<"6: Show All Accounts "<<endl;
    cout<<"7: Quit "<<endl;
    cout<<"\t-->Enter Your choice: ";
    cin>>option;

    string name, lname, address;
    char account;
    double initial_balance;
    int accnum;

    if (option==1)
    {
        ofstream obj1("Option_1.txt", ios::app);
        cout<<"What Number is this Account: ";
        cin>> accnum;
        obj1<<accnum<<" ";

        cout<<"Enter your first name: ";
        cin>> name;
        obj1<<name<<" ";

        cout<<"Enter your last name: ";
        cin>> lname;
        obj1<<lname<<" ";

        cin.ignore();

        cout<<"Enter your city name: ";
        cin>>address;
        obj1<<address<<" ";

        cout<<"What type of account is this (S for saving and C for Checking): ";
        cin>> account;
        obj1<<account<<" ";

        cout<<"Enter initial Balance: ";
        cin>> initial_balance;
        obj1<<initial_balance<<"\n";


        cout<<"\nCongratulations! Your account has been created "<<name<<endl;

        cout<<"Account Number: "<<accnum<<endl;

        cout<<"Name: "<<name<<endl;

        cout<<"Last Name: "<<lname<<endl;

        cout<<"City Name: "<<address<<endl;

        cout<<"Account Type: "<<account<<endl;

        cout<<"Available Balance: $"<<initial_balance<<endl;


        system ("pause");
        system ("cls");


         goto menu;

    }

    else if (option==2)
    {
        string name, lname, address, line;
        char account;
        double initial_balance;
        int accnum, accnum_check;
        ifstream obj("Option_1.txt", ios::in);

        cout<<"Enter your account number"<<endl;
        cin>>accnum_check;


        while ( getline (obj,line) )
        {
            vector<string> result;
            std::istringstream iss(line);
            for(std::string line; iss >> line; )
                result.push_back(line);
            if (stoi(result[0]) == accnum_check){
                    cout <<"Name: "<< result[1] << '\n';
                    cout <<"Last Name: "<< result[2] << '\n';
                    cout <<"City Name: "<< result[3] << '\n';
                    cout <<"Account Type: "<< result[4] << '\n';
                    cout <<"Balance: $"<< result[5] << '\n';
            }
        }


        }

        else if (option==3)
        {

            string name, lname, address, line, lines;
            char account;
            double initial_balance, deposit;
            int accnum, accnum_check;
            ifstream obj("Option_1.txt", ios::in);

            cout<<"\nEnter your account number"<<endl;
            cin>>accnum_check;

            cout<<"Enter how much money you would like to deposit"<<endl;
            cin>>deposit;


            vector< vector<string> > results;

            while (getline(obj,line))
            {
                vector<string> result;
                std::istringstream iss(line);
                for(std::string line; iss >> line; )
                    result.push_back(line);

                results.push_back(result);
            }

            for (int i=0; i<results.size(); i++){
                if (stoi(results[i][0]) == accnum_check){
                    results[i][5] = to_string(stoi(results[i][5]) + deposit);
                }
            }

            ofstream obj2("Option_1.txt", ios::out);

            for (int i=0; i<results.size(); i++){
                for(int j=0; j<6; j++){
                    obj2 << results[i][j] << " ";


                }

                    obj2<<"\n";
            }


            int n=accnum_check-1;
            for (int i=n; i<accnum_check; i++)
            {


                    cout<<"\nAccount Number: "<<results[i][0]<<'\n';
                    cout <<"Name: "<< results[i][1] << '\n';
                    cout <<"Last Name: "<< results[i][2] << '\n';
                    cout <<"City Name: "<< results[i][3] << '\n';
                    cout <<"Account Type: "<< results[i][4] << '\n';
                    cout <<"New Balance: $"<< results[i][5]<<endl;
            }

            goto menu;
        }

        else if (option==4)
        {

            string name, lname, address, line, lines;
            char account;
            double initial_balance, withdrawal;
            int accnum, accnum_check;
            ifstream obj("Option_1.txt", ios::in);

            cout<<"\nEnter your account number"<<endl;
            cin>>accnum_check;

            cout<<"Enter how much money you would like to withdrawal"<<endl;
            cin>>withdrawal;


            vector< vector<string> > results;

            while (getline(obj,line))
            {
                vector<string> result;
                std::istringstream iss(line);
                for(std::string line; iss >> line; )
                    result.push_back(line);

                results.push_back(result);
            }

            for (int i=0; i<results.size(); i++){
                if (stoi(results[i][0]) == accnum_check){
                    results[i][5] = to_string(stoi(results[i][5]) - withdrawal);
                }
            }

            ofstream obj2("Option_1.txt", ios::out);

            for (int i=0; i<results.size(); i++){
                for(int j=0; j<6; j++){
                    obj2 << results[i][j] << " ";
                }
                    obj2<<"\n";
            }

            int n=accnum_check-1;
            for (int i=n; i<accnum_check; i++)
            {
                    cout<<"\nAccount Number: "<<results[i][0]<<'\n';
                    cout <<"Name: "<< results[i][1] << '\n';
                    cout <<"Last Name: "<< results[i][2] << '\n';
                    cout <<"City Name: "<< results[i][3] << '\n';
                    cout <<"Account Type: "<< results[i][4] << '\n';
                    cout <<"New Balance: $"<< results[i][5]<<endl;
            }

            goto menu;

        }

        else if (option==5)
        {
            ifstream obj("Option_1.txt", ios::in);

            string name, lname, address, line, lines;
            char account;
            double initial_balance, withdrawal;
            int accnum, accnum_check;

             vector< vector<string> > results;

            while (getline(obj,line))
            {
                vector<string> result;
                std::istringstream iss(line);
                for(std::string line; iss >> line; )
                    result.push_back(line);

                results.push_back(result);
            }

            int verification;
            string deleteline;

            cout<<"\nEnter your verification code:"<<endl;
            cin>>verification;


            if (verification==randnum)
            {
                cout<<"Enter the account number that you would like to close the account of"<<endl;
                cin>>accnum_check;

                string close, closell, closel;

                close="xxxxxxx";

                closel="0";

                for (int i=0; i<results.size(); i++){

                if (stoi(results[i][0]) == accnum_check){
                    results[i][0] = closel;
                    results[i][1] = close;
                    results[i][2] = close;
                    results[i][3] = close;
                    results[i][4] = close;
                    results[i][5] = close;
                    cout<<"This account has been closed."<<endl;
                }

            }


        ofstream obj2("Option_1.txt", ios::out);
                  for (int i=0; i<results.size(); i++){
                for(int j=0; j<6; j++){

                    obj2 << results[i][j] << " ";

                    }
                    obj2<<"\n";
                }
            }

            else
            {
                cout<<"Sorry that is not the correct verification code"<<endl;
            }

            goto menu;

        }

        else if (option==6)
        {
            string name, lname, address, line;
            char account;
            double initial_balance, withdrawal;
            int accnum, accnum_check;
            ifstream obj("Option_1.txt", ios::in);

            int verification;

            cout<<"\nEnter your verification code:"<<endl;
            cin>>verification;

            if (verification==randnum)
            {

            vector< vector<string> > results;

            while (getline(obj,line))
            {
                vector<string> result;
                std::istringstream iss(line);
                for(std::string line; iss >> line; )
                    result.push_back(line);

                results.push_back(result);
            }


            for (int i=0; i<results.size(); i++)
            {


                    cout<<"\nAccount Number: "<<results[i][0]<<'\n';
                    cout <<"Name: "<< results[i][1] << '\n';
                    cout <<"Last Name: "<< results[i][2] << '\n';
                    cout <<"City Name: "<< results[i][3] << '\n';
                    cout <<"Account Type: "<< results[i][4] << '\n';
                    cout <<"New Balance: $"<< results[i][5]<<endl;
            }
            }
            else
            {
                cout<<"Sorry that is not the correct verification code"<<endl;
            }

            goto menu;

        }

        else if (option==7)
        {
            cout<<"\nThank you for choosing HSBC Bank Canada, come again Soon!"<<endl;
        }

        else
        {
            cout<<"Please select a provided option"<<endl;
            goto menu;
        }


    return 0;
}






