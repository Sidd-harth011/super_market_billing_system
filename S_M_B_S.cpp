#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;

class Bill
{
private:
    string Item;
    int Rate, Quantity;

public:
    Bill() : Item(""), Rate(0), Quantity(0) {};
    void setItem(string item)
    {
        Item = item;
    };
    void setRate(int rate)
    {
        Rate = rate;
    };
    void setQuant(int quant)
    {
        Quantity = quant;
    };
    string getItem()
    {
        return Item;
    };
    int getRate()
    {
        return Rate;
    };
    int getQuant()
    {
        return Quantity;
    };
};

void addItem(Bill &b)
{
    bool close = false;
    while (!close)
    {
        int choice;
        cout << "\t1.add" << endl;
        cout << "\t2.close" << endl;
        cout << "\tenter choice" << endl;
        cin >> choice;
        if (choice == 1)
        {
            system("cls");
            string item;
            int rate, quant;
            cout << "\tenter item name" << endl;
            cin >> item;
            b.setItem(item);
            cout << "\tenter rate of item" << endl;
            cin >> rate;
            b.setRate(rate);
            cout << "\tenter quantity of item" << endl;
            cin >> quant;
            b.setQuant(quant);
            ofstream out("C:\\Users\\Siddharth\\Desktop\\C++ Projects\\super_market_billing_system\\S_M_S_B.txt", ios::app);
            // ofstream used to write in the file; and ios::app is used to append new data after the old data;
            if (!out)
            {
                cout << "\terror:file can't be opened" << endl;
            }
            else
            {
                out << "\t" << b.getItem() << " : " << b.getRate() << " : " << b.getQuant() << endl
                    << endl; // passing data to the file
            };
            out.close(); // closing the file
            cout << "item added successfully" << endl;
            Sleep(3000);
        }
        else if (choice == 2)
        {
            close = true;
            cout << "\tback to main menu" << endl;
            Sleep(3000);
        }
    }
}

void printBill(){
    system("cls");
    int count = 0;
    bool close = false;
    while(!close){
        system("cls");
        int choices;
        cout<<"\t1.add bill"<<endl;
        cout<<"\t2.close session"<<endl;
        cout<<"\tenter choices"<<endl;
        cin>>choices;

        if(choices == 1){
            string item;
            int quant;
            cout<<"\tenter item"<<endl;
            cin>>item;
            cout<<"\tenter quantity"<<endl;
            cin>>quant;
            ifstream in("C:\\Users\\Siddharth\\Desktop\\C++ Projects\\super_market_billing_system\\S_M_S_B.txt");
            ofstream out("C:\\Users\\Siddharth\\Desktop\\C++ Projects\\super_market_billing_system\\Bill temp.txt");
            string line;
            bool found = false;
            while(getline(in,line)){
                stringstream ss;
                ss<<line;
                string itemName;
                int itemRate,itemQuant;
                char delimiter;
                ss>>itemName>>delimiter>>itemRate>>delimiter>>itemQuant;
                //setting boundary using delimiter keyword;
                if(item == itemName){
                    found = true;
                
                if(quant <= itemQuant){
                    int amount = itemRate * quant; 
                    cout<<"\titem | Rate | Quantity | Amount "<<endl<<"\t"<<itemName<<"\t"<<itemRate<<"\t"<<quant<<"\t"<<amount<<endl;
                    int newQuant = itemQuant - quant;
                    itemQuant = newQuant;
                    count += amount;
                    out<<"\t"<<itemName<<" : "<<itemRate<<" : "<<itemQuant<<endl<<endl;
                }else{
                    //not quantity;
                    cout<<"\tsorry "<<item<<"not in stock"<<'\n';
                }
                }
                else{
                    out<<line;

                    //item not found;
                }

            }
            if(!found){
                cout<<"\tItem is not available"<<endl;
            }
            out.close();
            in.close();
            remove("C:\\Users\\Siddharth\\Desktop\\C++ Projects\\super_market_billing_system\\Bill temp.txt");
            rename("C:\\Users\\Siddharth\\Desktop\\C++ Projects\\super_market_billing_system\\Bill temp.txt" , "C:\\Users\\Siddharth\\Desktop\\C++ Projects\\super_market_billing_system\\S_M_S_B.txt");
        }
        else if(choices == 2){
            close = true;
            cout<<"\tCounting total bill"<<endl;
        }
        Sleep(3000);
    }
    system("cls");
    cout<<endl<<endl;
    cout<<"\t total bill : "<<count<<endl;
    cout<<endl;
    cout<<"\thanks for shopping"<<endl;
    Sleep(5000);
}

int main()
{
    Bill b;
    bool exit = false;
    while (!exit)
    {
        system("cls"); // clear screen
        int val;
        cout << "\tWelcome to super market billing system" << endl;
        cout << "\t**************************************" << endl;
        cout << "\t1.add item." << endl;
        cout << "\t2.print Bill." << endl;
        cout << "\t3.exit." << endl;
        cout << "\tenter choice" << endl;
        cin >> val;

        if (val == 1)
        {   
            system("cls");
            addItem(b);
            Sleep(3000);
        }
        else if(val == 2){
            system("cls");
            printBill();
            Sleep(3000);
        }
        else if(val == 3){
            system("cls");
            exit = true;
            cout<<"\tgood luck"<<endl;
            Sleep(3000);
        }
    }
    return 0;
}