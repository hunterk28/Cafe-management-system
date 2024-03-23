//Kamil Saeed, 23i-2035

#include<iostream>
#include<fstream>
#include<cstring>
#include "header.h"
#include<stdio.h>
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define BOLD "\033[1m"


using namespace std;

void empidpass(void)                                                                //Function for ID and password of first employee
{
    char arrid[25], arrpass[25];
    char arr1[25], arr2[25];
    int x=0;

    do
    {

    ifstream fin1;
    ofstream fout;

    fin1.open("empid.txt", ios::in);                                                //Reading file.
    cin.ignore();
    cout<<"\nEnter User ID: ";                                                      //Takin Input User ID.
    cin.getline(arrid, 25);
    cout<<"\nEnter Password: ";
    cin.getline(arr2, 25);                                                          //Taking Input Password.

    
    if(!fin1)                                                                       //Checking if file is created or not.
    {
            cout<<RED<<"\nError reading file"<<endl;
            cout<<"Check file name"<<RESET<<endl;
    }

    else
    {
        
        while(fin1.getline(arr1, 9, ' ') , fin1.getline( arrpass , 10, '\n'))
        {
            if(strcmp(arrid,arr1)==0 and strcmp(arrpass,arr2)==0)                   //Comparining ID and Password.
            {
                    x=1;                                                            //Flag set.
                break;
            }
        }                                                

        if(x!=1)
        {
            cout<<RED<<"Wrong username or ID! Press any key to enter"<<RESET;
        }
        else
        {
            fout.open("bestseller.txt", ios::out | ios::app);                      //Opening file to write.

            if(!fout)
            {
                cout<<RED<<"\nError file not available"<<RESET<<endl;
            }

            else 
            {
                fout<<arrid<<" ";                                                  //Writing Id in file for bestseller purpose.
            }

            fout.close();
            break;
        }
                
    }
    fin1.close();                                                                  //Closing file.

    }while(strcmp(arrid,arr1)!=0 and strcmp(arrpass,arr2)!=0);                    //Loop will run if ID Pass is wrong.

}

void menu(void)
{
        ifstream in1;
        char x;

        int ID_No;
        char Id_Name[10];
        int Price;
        int No_Items;
        int Total_Price;
    

        cout<<"\nItems Displayed: "<<endl;
        cout<<"\n\nItems: "<<endl;
        
        in1.open("dishes1.txt", ios::in);                               //Reading file for dishes.
        
        if(!in1)                                                       //Checking if file available or not.
        {
            cout<<RED"\nError reading file. "<<endl;
            cout<<"Check file name"<<RESET<<endl;
        }

        else
        {
            cout<<endl;

            cout<<"IDs  "<<setw(10)<<left<<"Item Name"<<setw(10)<<"Price"<<setw(10)<<"No_Items"<<endl;
            

             while(in1>>ID_No , in1.getline( Id_Name , 10 , '\t'), in1>>Price>>No_Items>>Total_Price)                                         //Loop for taking data char by char from file.
            {
                    cout<<ID_No<<"     "<<setw(10)<<left<<Id_Name<<setw(10)<<Price<<No_Items<<endl;
            }
        }
        in1.close();                                                 //Closing file.
        cout<<"\n\n";

}

void searchemp(void)                                                //Searching item
{
        int x;
        int y, z;
        
        int ID_No;
        char Id_Name[10];
        int Price;
        int No_Items;
        int Total_Price;
    do
    {
        cout<<"\nEnter the ID No to search item"<<endl;
        cin>>x;

        ifstream fin;

        fin.open("dishes1.txt", ios::in);                                                                   //Opening file in writing mode.

        if(!fin)
        {
            cout<<RED<<"\nError reading file. "<<endl;
            cout<<"Check file name"<<RESET<<endl;
        }

        else
        {
            while(fin>>ID_No , fin.getline( Id_Name , 10 , '\t'), fin>>Price>>No_Items>>Total_Price)       //Taking content of file.
            {
                if(ID_No==x)                                                                               //if condition true it will skip the ID and move forward.
                {
                        y=1;
                    break;
                }
            }

            if(y==1)
            {
                cout<<"\nItem Found:"<<endl;
                cout<<"\nIDs  "<<setw(10)<<left<<"Item Name"<<setw(10)<<"Price"<<setw(10)<<"No_Items"<<endl;
                cout<<ID_No<<"     "<<setw(10)<<left<<Id_Name<<setw(10)<<Price<<setw(10)<<No_Items<<endl;       //Printing the searched item.
            }
            else
            {
                cout<<RED<<"\nItem not found!"<<RESET<<endl;
            }

        }

        fin.close();                                                                                            //Closing file.
    
    }while(y!=1);

}

void empord(void)                                                                                               //Function for employee taking order.
{
        ifstream fin;
        ofstream fout;
        int y,z,a,e, b;
        int bill=0, iprice, tbill;

        int ID_No;
        char Id_Name[10];
        int Price;
        int No_Items;
        int Total_Price;
        int i=0;
    
    do 
    {
        menu();

        cout<<"\nEnter item ID No: ";                                                                           //Entering ID and Quantity of food.
        cin>>y;

        cout<<"\nEnter quantity: ";
        cin>>z;

        fin.open("dishes1.txt", ios::in);                                                                      //Opening files for reading and writing.
        fout.open("temp.txt", ios::out);

        if(!fin)
        {
            cout<<RED<<"\nError reading file"<<RESET<<endl;

        }
        else
        {
            while(fin>>ID_No, fin.getline(Id_Name, 10, '\t'), fin>>Price>>No_Items>>Total_Price)              //Reading content of file
            {
                if(ID_No==y)                                                                                  //Item of order found
                {
                    if(z<No_Items && z>0)                                                                     //Checking if enough quantity available or not.
                    {
                        a=1,b=1;                                                                              //Decreasing items in back hand.
                        No_Items = No_Items-z;
                        Total_Price = Price*No_Items;
                        iprice = Price*z;
                        bill = bill+iprice;
                    }
                    else
                    {
                        cout<<RED<<"\nStock not available"<<RESET<<endl;
                    }
                }
                if(a==1)
                {
                    fout<<ID_No<<Id_Name<<"\t"<<Price<<"\t"<<No_Items<<"\t"<<Total_Price<<"\n";             //Writing items back in file.
                    
                }
            }
            cout<<"\nPress '0' to add more items and '1' to generate bill"<<endl;
            cin>>e;
            
        }
        fin.close();
        fout.close();

        remove("dishes1.txt");                                                                             //Purani file remove krne k liye
        rename("temp.txt","dishes1.txt");                                                                  //Naye file rename krne k liye

    }while(e==0);

    cout<<"\nYour total bill is: Rs "<<bill<<endl;                                                         //Bill print krne k liye.

    if(b==1)
    {
        ofstream fout1;

        fout1.open("bestseller.txt", ios::out | ios::app);                                                 //File open ki likhne k liye.

        if(!fout1)
        {
            cout<<RED<<"\nError file not avaliable"<<RESET<<endl;
        }

        else
        {
            tbill= tbill+ bill;
            fout1<<tbill<<"\n";                                                                          //Bill print kr diya.
        }
    
        fout1.close();
    }

}