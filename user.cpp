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

void useridpass(void)                                                                               //User ka id pass.
{
        char arrid[25];
        char arrpass[25];
        char arr1[25];
        char arr2[25];
        int x;

        ifstream fin;
    do 
    {
        fin.open("userid.txt", ios::in);                                                            //File open ki likhne k liye.
        cin.ignore();
        cout<<"\nEnter User ID: ";                                                                  //User se ID PASS liya.
        cin.getline(arrid, 25);
        cout<<"Enter Password: ";
        cin.getline(arrpass, 25);

        if(!fin)
        {
                cout<<RED<<"\nError reading file"<<endl;
                cout<<"Check file name"<<RESET<<endl;
        }

        else
        {
            while(fin.getline(arr1, 9, ' '),fin.getline(arr2, 10, '\n'))                        //File ka content read kiya.
            {
                if(strcmp(arrid,arr1)==0 and strcmp(arrpass,arr2)==0)                           //Compare kiya id pass se.
                {
                        x=1;
                    break;
                }
            }

            if(x!=1)
            {
                cout<<RED<<"\nWrong username or password"<<RESET;
            }
            else
            {
                break;
            }
        }
        fin.close();

    }while(strcmp(arrid,arr1)!=0 and strcmp(arrpass,arr2)!=0);                                  //Check lgaya.

}
void menudis(void)                                                                              //Menu display liya user k liye
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
        
        in1.open("dishes1.txt", ios::in);                                                                          //Reading file for dishes.
        
        if(!in1)                                                                                                   //Checking if file available or not.
        {
                cout<<RED<<"\nError reading file. "<<endl;
                cout<<"Check file name"<<RESET<<endl;
        }

        else
        {
            cout<<endl;

            cout<<"IDs  "<<setw(10)<<left<<"Item Name"<<setw(10)<<"Price"<<endl;                                  //Printing Header.
        

            while(in1>>ID_No , in1.getline( Id_Name , 10 , '\t'), in1>>Price>>No_Items>>Total_Price)             //while loop reading data from file.
            {
                cout<<ID_No<<"     "<<setw(10)<<left<<Id_Name<<setw(10)<<Price<<endl;
            }
        }
        
        in1.close();                                                                                              //Closing file.
        cout<<"\n\n";

}

void sorder(char x[])                                                                                           //Scheduled order.
{
        ofstream fout1;
        ifstream fin;
        ofstream fout;

        int y,z,a,e;

        char time[10];
        int ID_No;
        char Id_Name[10];
        int Price;
        int No_Items;
        int Total_Price;

        cout<<"\nEnter Time of order: ";                                                                       //Time aur Id le user se.
        cin.getline(time, 10);

        fout1.open("time.txt", ios::out);                                                                      //file open ki likhne k liye.
        
        if(!fout1)
        {
            cout<<RED<<"\nError time.txt not available"<<RESET<<endl;
        }
        else 
        {
            fout1<<x<<" "<<time<<"\n";
        }

        fout1.close();
    do 
    {
        menu();                                                                                                //Menu print krwaya

        cout<<"\nEnter item ID No: ";                                                                          //Quantity aur item ID le.
        cin>>y;

        cout<<"\nEnter quantity: ";
        cin>>z;

        fin.open("dishes1.txt", ios::in);                                                                     //REading aur writing k liye file open ki.
        fout.open("order.txt", ios::out | ios::app);

        if(!fin)
        {
            cout<<RED<<"\nError reading file"<<endl;
            cout<<"Check file name"<<RESET<<endl;
        }

        else 
        {
            while(fin>>ID_No, fin.getline(Id_Name, 10, '\t'), fin>>Price>>No_Items>>Total_Price)            //file k content liye.
            {
                if(ID_No==y)                                                                                //Order milgeya.
                {
                        a=1;
                    break;
                }
            }

            if(a==1)
            {
                fout<<ID_No<<Id_Name<<"\t"<<Price<<"\t"<<z<<"\n";                                           //File mei likha.
            }
        }
        
        fin.close();                                                                                        
        fout.close();

        cout<<"\nPress '0' to add items and '1' to send order"<<endl;                                      //Poocha kuch aur add tou nhi krna.
        cin>>e;
    
    }while(e==0);

}


void ucomp(void)                                                                                             //Function for complaints.
{
        char arr1[100];                                                                                      //Character array.

        ofstream fout;                                                  

        fout.open("complaints.txt", ios::out | ios::app);                                      //Opening file in writing mode.

        if(!fout)                                                                              //Checking if file available.
        {
                cout<<RED<<"Error!"<<endl;
                cout<<"File not found"<<RESET<<endl;
        }

        else
        {
                cout<<"\nEnter complaint's "<<endl;                                             //Adding complaints in file.
                cin.ignore();
                cin.getline(arr1, 100, '\n');

                fout<<"\n"<<arr1;

                cout<<GREEN<<"\n\nComplaint submitted"<<endl;
                cout<<"Thankyou for your Feedback"<<RESET<<endl;

        }

        fout.close();                                                                           //Closing file.
}

void searchuser(void)                                                                                           //Search user se krwane k liye items.
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
        cout<<"\nEnter the ID No to search item"<<endl;                                                         //ID pooche user se jo item search krna
        cin>>x;

        ifstream fin;

        fin.open("dishes1.txt", ios::in);

        if(!fin)
        {
            cout<<RED<<"\nError reading file. "<<endl;
            cout<<"Check file name"<<RESET<<endl;
        }

        else
        {
            while(fin>>ID_No , fin.getline( Id_Name , 10 , '\t'), fin>>Price>>No_Items>>Total_Price)            //Menu wali file se content liya
            {
                if(ID_No==x)                                                                                    //Jo chahiye mil geya
                {
                        y=1;
                    break;
                }
            }

            if(y==1)
            {
                cout<<"\nItem Found:"<<endl;
                cout<<"\nIDs  "<<setw(10)<<left<<"Item Name"<<setw(10)<<"Price"<<endl;
                cout<<ID_No<<"     "<<setw(10)<<left<<Id_Name<<setw(10)<<Price<<endl;                          //Print krwa liya.
            }
            else
            {
                cout<<RED<<"\nItem not found!"<<RESET<<endl;
            }

        }

        fin.close();                                                                                           //File close krwa le.
    
    }while(y!=1);

}
