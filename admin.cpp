//Kamil Saeed, 23i-2035

#include<iomanip>
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

void adminidpass(void)                                                  //Function for admin id and password.
{
        char arrid[25];
        char arr1[25];
        char arrpass[25];
        char arr2[25];

        cin.ignore();                                                   //Reading file.
    do 
    {

        ifstream fout;
        
		cout<<"\nEnter User ID: ";
        
		cin.getline(arrid, 25);                                         //Input from user.

        fout.open("adminid.txt", ios::in);
        
        if(!fout)                                                       //Checking if file created or not.
        {
                cout<<RED<<"\nError reading file"<<endl;
                cout<<"Check file name"<<RESET<<endl;
        }

        else
        {
		    fout.getline(arr1, 12, ' ');                                 //Reading ID.

		if(strcmp(arrid,arr1)==0)                                        //Compairing the ID of admin user with the text file.
		{
			cout<<GREEN<<"Correct ID"<<RESET<<endl;
            do 
            {
                fout.seekg(13, ios::beg);                                //Placing cursor before password.
                cout<<"\nEnter Password: ";
                cin.ignore();
                cin.getline(arrpass,25);                                 //Taking password input.

                fout.getline(arr2, 13, ' ' );                            //Reading password.

                if(strcmp(arrpass,arr2)==0)                              //Compairing the Password of admin user with the text file.
                {
                    cout<<GREEN<<"Correct Password "<<RESET<<endl;
                }

                else
                {
                    cout<<RED<<"Incorrect Password! Enter password again."<<RESET<<endl;
                }
            }while(strcmp(arrpass,arr2)!=0);                            //Loop will run if password is incorrect.
		}
        else
		{
				cout<<RED"Incorrect ID! Enter ID again."<<RESET<<endl;              
		}

        }

        fout.close();                                                   //Closing file opened.

    }while(strcmp(arrid,arr1)!=0);                                      //Loop will run if ID is incorrect.

}

void dishes(void)                                                       //Function for menu displaying to admin.
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
        
        in1.open("dishes1.txt", ios::in);                              //Reading file for dishes.
        
        if(!in1)                                                       //Checking if file available or not.
        {
            cout<<RED<<"\nError reading file. "<<endl;
            cout<<"Check file name"<<RESET<<endl;
        }

        else
        {
            cout<<endl;

            cout<<"IDs  "<<setw(10)<<left<<"Item Name"<<setw(10)<<"Price"<<setw(10)<<"No_Items"<<setw(10)<<"Total_Price"<<endl;                //Printing header.
            

             while(in1>>ID_No , in1.getline( Id_Name , 10 , '\t'), in1>>Price>>No_Items>>Total_Price )                                         //Loop for taking data char by char from file.
            {
                    cout<<ID_No<<"     "<<setw(10)<<left<<Id_Name<<setw(10)<<Price<<setw(10)<<No_Items<<setw(10)<<Total_Price<<endl;
            }
        }
        in1.close();                                                    //Closing file.
        cout<<"\n\n";

}

void add(int a, char b[], int x, int y, int z)                          //Function for adding dishes.
{
        char c;
        int ID_No;
        char Id_Name[10];
        int Price;
        int No_Items;
        int Total_Price;

        ofstream fout;

        cout<<"\nAdding Items"<<endl;

        fout.open("dishes1.txt", ios::out | ios::app);                  //file opening.
        
        if(!fout)                                                       //Checking if file available or not.
        {
            cout<<RED<<"\nError reading file. "<<endl;
            cout<<"Check file name"<<RESET<<endl;
        }

        else                                                           //Printing user input in file.
        {
            fout<<a;
            fout<<b<<"\t";
            fout<<x<<"\t";
            fout<<y<<"\t";
            fout<<z<<endl;

        fout.close();                                                  //Closing file.
        }

        ifstream in1;
        
        cout<<"\nItems Displayed: "<<endl;                             //Displaying items in file.
        cout<<"\n\nItems: \n"<<endl;
        
        in1.open("dishes1.txt", ios::in);                              //Reading file for dishes.
        
        if(!in1)                                                       //Checking if file available or not.
        {
            cout<<endl;
            cout<<RED<<"\nError reading file. "<<endl;
            cout<<"Check file name"<<RESET<<endl;
        }

        else
        {
            cout<<endl;

            cout<<"IDs  "<<setw(10)<<left<<"Item Name"<<setw(10)<<"Price"<<setw(10)<<"No_Items"<<setw(10)<<"Total_Price"<<endl;                //Priting header.
            

             while(in1>>ID_No , in1.getline( Id_Name , 10 , '\t'), in1>>Price>>No_Items>>Total_Price )                                         //Reading content from file
            {
                    cout<<ID_No<<"     "<<setw(10)<<left<<Id_Name<<setw(10)<<Price<<setw(10)<<No_Items<<setw(10)<<Total_Price<<endl;
            }
        }

        in1.close();
}

void dele(void)                                                            //Menu for deleting dishes.
{

        int x;
        fstream in1;
        fstream fout;

        cout<<"\nEnter ID you want to remove: ";                         //Enter ID No of items that you want to delete.
        cin>>x;

        int ID_No;
        char Id_Name[10];
        int Price;
        int No_Items;
        int Total_Price;
        
        in1.open("dishes1.txt", ios::in);                               //Reading file for dishes.
        fout.open("temp.txt", ios::out);                                //Opening file for writing.
        

        in1.seekg(0,ios::beg);

        if(!in1)                                                       //Checking if file available or not.
        {
            cout<<endl;
            cout<<RED<<"\nError reading file. "<<endl;
            cout<<"Check file name"<<RESET<<endl;
        }

        else
        { 
            //header
            while(in1>>ID_No , in1.getline( Id_Name , 10 , '\t'), in1>>Price>>No_Items>>Total_Price )                                         //Loop for taking data char by char from file.
            {
                    in1.ignore();

                    if(ID_No==x)
                    {
                        continue;
                    }

                    fout<<ID_No<<Id_Name<<"\t"<<Price<<"\t"<<No_Items<<"\t"<<Total_Price<<"\n";                                               //Writing back in temp.txt file.
            }
        
        }

        in1.close();                                                //Closing file.
        fout.close();                                               //Closing file.

        remove("dishes1.txt");                                      //Removing file.
        rename("temp.txt","dishes1.txt");                           //Renaming file.
    
}

void search(void)                                                                                                           //Fumction for search.
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

        fin.open("dishes1.txt", ios::in);                                                                                  //Opening file for reading.

        if(!fin)                                                                                                           //Checking if file created or not.
        {
            cout<<RED<<"\nError reading file. "<<endl;
            cout<<"Check file name"<<RESET<<endl;
        }

        else
        {
            while(fin>>ID_No , fin.getline( Id_Name , 10 , '\t'), fin>>Price>>No_Items>>Total_Price)                      //Taking content of file in.
            {
                if(ID_No==x)                                                                                              //if id match break;
                {
                        y=1;
                    break;
                }
            }

            if(y==1)
            {
                cout<<"\nItem Found:"<<endl;
                cout<<"\nIDs  "<<setw(10)<<left<<"Item Name"<<setw(10)<<"Price"<<setw(10)<<"No_Items"<<setw(10)<<"Total_Price"<<endl;
                cout<<ID_No<<"     "<<setw(10)<<left<<Id_Name<<setw(10)<<Price<<setw(10)<<No_Items<<setw(10)<<Total_Price<<endl;            //Printing only searched items.
            }
            else
            {
                cout<<RED<<"\nItem not found!"<<RESET<<endl;
            }

        }

        fin.close();                                                                                                     //Closing file.
    
    }while(y!=1);                                                                                                        //loop until id is matched.

}

void notifi(void)                                                                                                      //Function for notification
{
        char c;
        int x;
        char arr1[100];

        ifstream in1;
        in1.open("notifi.txt", ios::in);                                                                               //Opening file.
        
        if(!in1)
        {
            cout<<RED<<"\nError reading file. "<<endl;
            cout<<"Check file name"<<RESET<<endl;
        }

        else
        {
            while(!in1.eof())                                                                                       //Loop for taking data char by char from file.
            {
                    in1.get(c);
                    cout<<c;
            }
        }
        in1.close();                                                                                                //Closing file.

    do 
    {
        cout<<"\n\nEnter '0' to add notification and '1' to continue "<<endl;
        cin>>x;

        if(x==0)                                                                                                   //If condition satisfies then take input.
            cout<<"Enter: "<<endl;

        ofstream fout;

        fout.open("notifi.txt", ios::out | ios::app);                                                              //Opening file for writting.

        if(!fout)
        {
            cout<<RED<<"\nError file not found "<<RESET<<endl;
        }

        else
        {
            cin.ignore();
            cin.getline(arr1, 100, '\n');                                                                         //Taking input.
            fout<<arr1;                                                                                           //Writing in file.
            

            fout.close();                                                                                         //Closing file.
        }
    }while(x==0);

        if(x==1)                                                                                                 //Reading content of file
            cout<<"Your notifications are: "<<endl;                                                         

        ifstream in2;

        in2.open("notifi.txt", ios::in);                                                                         //Opening file for reading .
        
        if(!in2)
        {
            cout<<RED<<"\nError reading file. "<<endl;
            cout<<"Check file name"<<RESET<<endl;
        }

        else
        {
            while(!in2.eof())                                                                                   //Loop for taking data char by char from file.
            {
                    in2.get(c);
                    cout<<c;
            }
            cout<<"\n\n";
        }   
        in2.close();                                                                                           //Closing file

}

void comp(void)                                                                                                //Function for complaints
{
        char c;
        ifstream fin;

        fin.open("complaints.txt", ios::in);                                                                   //Opening file for reading

        if(!fin)
        {
            cout<<RED<<"\nError reading file. "<<endl;
            cout<<"Check file name"<<RESET<<endl;
        }

        else
        {
                while(!fin.eof())                                                                              //Loop for taking data char by char from file.
                {
                        fin.get(c);
                        cout<<c;
                }
        }

        fin.close();                                                                                          //Close file.

}

void addemp(void)                                                                                             //Function for adding employees.
{
        char arrid[10];
        char arrpass[10];

        ofstream fout;
        fout.open("empid.txt", ios::out | ios::app);                                                         //Opening file for writing.

        if(!fout)
        {
                cout<<RED<<"Error File not found"<<endl;
                cout<<"Check file again"<<RESET<<endl;
        }
        else
        {
                cout<<"\nEnter new ID: ";
                cin.ignore();
                cin.getline(arrid, 10);                                                                     //Taking ID from user

                cout<<"Enter new Password: ";
                cin.getline(arrpass, 10);                                                                   //Taking password from user
                
                fout<<arrid<<" "<<arrpass<<"\n";                                                            //Writing back in file.
        }

        fout.close();
}

void deleemp(void)                                                                                          //Deleting employees.
{
        char arrid[10];
        char arrpass[10];
        char arr1[10];

        fstream fin;
        fstream fout;

        cout<<"\nEnter ID you want to remove: ";
        cin>>arr1;
        
        fin.open("empid.txt", ios::in);                                                                     //Reading file for dishes.
        fout.open("temp.txt", ios::out);                                                                    //Opening file for writing
        
        if(!fin)                                                                                            //Checking if file available or not.
        {
            cout<<endl;
            cout<<RED<<"\nError reading file. "<<endl;
            cout<<"Check file name"<<RESET<<endl;
        }

        else
        { 
            while(fin.getline(arrid ,10 , ' '), fin.getline(arrpass ,10 ,'\n'))                            //Loop for taking data char by char from file.
            {
                if(strcmp(arr1,arrid)==0)                                                                  //comparing id from user to that in file,
                {
                    continue;
                }

                fout<<arrid<<" "<<arrpass<<"\n";                                                           //writing back in new file.
            }
        }
                                                                                                            //Closing both files
        fin.close();
        fout.close();

        remove("empid.txt");                                                                               //Removing old file
        rename("temp.txt","empid.txt");                                                                    //Renaming new file.

}

void disemp(void)                                                                                          //Displaying employee id pass.
{       
        char c;

        ifstream fin;
        fin.open("empid.txt", ios::in);                                                                    //Opening file for reading.

        if(!fin)
        {
            cout<<RED<<"\nError Reading file: "<<endl;
            cout<<"Check file name."<<RESET<<endl;
        }

        else
        {
            while(!fin.eof())                                                                             //Loop for taking data char by char from file.
            {
                    fin.get(c);
                    cout<<c;
            }
        }
        fin.close();
}   

void disuser(void)                                                                                       //Displaying user id and password.
{
        char c;
        
        int ID_No;
        char Id_Name[10];
        int Price;
        int No_items;
        int Total_Price;

        ifstream fin;                                                                                   
        fin.open("userid.txt", ios::in);                                                                //Opening file for reading

        if(!fin)
        {
            cout<<RED<<"\nError reading file"<<endl;
            cout<<"Check file name"<<RESET<<endl;
        }

        else
        {
            cout<<endl;
            while(!fin.eof())                                                                           //Loop for taking data char by char from file.
            {
                    fin.get(c);
                    cout<<c;
            }
        }

        fin.close();
        cout<<"\n\n";

}

void adduser(void)                                                                                     //Adding new user.
{
        char arrid[10];
        char arrpass[10];

        ofstream fout;

        fout.open("userid.txt", ios::out | ios::app);                                                 //Opening file for writing.

        if(!fout)
        {
            cout<<RED<<"\nError file not found"<<endl;
            cout<<"Check file name"<<RESET<<endl;
        }

        else
        {
            cout<<"\nEnter ID: ";
            cin.ignore();
            cin.getline(arrid, 10);                                                                 //Taking input of ID from user.

            cout<<"\nEnter Password: ";
            cin.getline(arrpass, 10);                                                               //Taking input of password from user.

            fout<<arrid<<" "<<arrpass<<"\n";                                                       //Writing user ID and Password back in file.

        }

}

void duser(void)                                                                                    //Deleting user id password.
{
        char arr1[10];
        char arrid[10];
        char arrpass[10];

        cin.ignore();                                                                              //ignoring previous input.
        fstream fin, fout;

        cout<<"\nEnter the username of ID you want to delete: ";
        cin>>arr1;                                                                                 //Enter ID to delete user.

        fin.open("userid.txt", ios::in);                                                           //Opening file for reading.
        fout.open("temp.txt", ios::out);                                                           //Opening file for writing.

        if(!fin)
        {
            cout<<RED<<"\nError reading file"<<endl;
            cout<<"CCheck file name"<<RESET<<endl;
        }

        else 
        {
            while(fin.getline(arrid, 10, ' '),fin.getline(arrpass, 10, '\n'))                      //Taking content from file.
            {
                if(strcmp(arrid,arr1)==0)                                                          //Comparing id's
                {
                    continue;                                                                      //Skipping entered ID
                }

                fout<<arrid<<" "<<arrpass<<"\n";                                                   //Printing back in new file

            }
        }

        fin.close();
        fout.close();

        remove("userid.txt");                                                                      //Removing old file                                                       
        rename("temp.txt", "userid.txt");                                                          //Renaming new file.
        
}

void adminsorder(void)                                                                             //Function for approving online order.
{
        int y,z,a,e,c;
        int w;
        int totalq;
        char arrid[9];
        char arrtime[10];
        char ID_Name[10], name[10];
        int ID_No, Quantity, Price, Price1;
        int no, quan,No_Items,Total_Price;
        int bill;

        ifstream fin;
        ifstream fin1;
        fstream fin2, fout;

        fin.open("time.txt", ios::in);                                                             //Opemimg file to read time and name of user.

        if(!fin)
        {
            cout<<RED<<"\nError reading file"<<endl;
            cout<<"Check file name"<<RESET<<endl;
        }

        else
        {
            cout<<endl;
            while(fin.getline(arrid, 9, ' '), fin.getline(arrtime, 10, '\n'))
            {
                cout<<"User: "<<arrid<<"\t"<<"Time: "<<arrtime<<endl;
            }
        }
        fin.close();

        fin1.open("order.txt", ios::in);

        if(!fin1)
        {
            cout<<RED<<"\nError reading file"<<endl;
            cout<<"Check file name"<<RESET<<endl;
        }

        else
        {
            while(fin1>>ID_No,fin1.getline(ID_Name, 10, '\t'),fin1>>Price>>Quantity)
            {
                cout<<"\n\n"<<ID_No<<"."<<ID_Name<<endl;
                cout<<"Price: "<<Price<<endl;
                cout<<"Quantity: "<<Quantity<<endl;

                bill= bill+(Price*Quantity);
            }
        }
        fin1.close();

        cout<<"\nPress '1' to confirm and '0' to cancel"<<endl;
        cin>>w;

        if(w==1)
        {
            fin2.open("dishes1.txt", ios::in);
            fout.open("temp.txt", ios::out);

            if(!fin2)
            {
                cout<<RED<<"\nError reading file"<<RESET<<endl;

            }
            else
            {
                
                while(fin2>>y, fin2.getline(name, 10, '\t'), fin2>>Price1>>No_Items>>Total_Price)
                {
                    if(ID_No==y)
                    {
                        if(Quantity<No_Items && Quantity>0)
                        {
                            a=1;
                            No_Items = No_Items-Quantity;
                            Total_Price = Price1*No_Items;
                        }
                        else
                        {
                            cout<<RED<<"\nStock not available"<<RESET<<endl;
                        }
                    }
                    if(a==1)
                    {
                        fout<<y<<name<<"\t"<<Price1<<"\t"<<No_Items<<"\t"<<Total_Price<<"\n";
                    }
                }
            
            fin2.close();
            fout.close();
            }

            remove("dishes1.txt");
            rename("temp.txt","dishes1.txt");

            fin1.open("order.txt", ios::in);

            if(!fin1)
            {
                cout<<RED<<"\nError reading file"<<endl;
                cout<<"Check file name"<<RESET<<endl;
            }

            else
            {
                bill=0;
                cout<<"ID_No"<<"\t|\t"<<"ID_Name"<<"\t|\t"<<"Price"<<"\t|\t"<<"Quantity"<<"\t|\t\n";
                while(fin1>>ID_No,fin1.getline(ID_Name, 10, '\t'),fin1>>Price>>Quantity)
                {
                    cout<<ID_No<<"\t|\t"<<ID_Name<<"\t|\t"<<Price<<"\t|\t"<<Quantity<<"\t|\t\n";
                    bill= bill+(Price*Quantity);
                }
            }
            fin1.close();

            cout<<"\nTotal Amount: "<<bill<<endl;
        }

        else
        {
            cout<<RED<<"\nOrder cancelled"<<RESET<<endl;
        }

}

void seller(void)
{
        char id_name[10][10];
        int quan[10];
        int i=0;
        int sum1=0, sum2=0, sum3=0, sum4=0, sum5=0;

        ifstream fin;

        fin.open("bestseller.txt", ios::in);

        if(!fin)
        {
            cout<<RED<<"\nError reading file"<<endl;
            cout<<"Check file name"<<RESET<<endl;
        }

        else
        {
            while(fin.getline(id_name[i], 10, ' '), fin>>quan[i])
            {
                fin.ignore();
                i++;
            }

            for(int k=0; k<i; k++)
                {
                    if(strcmp(id_name[k],"rafay123")==0)
                    {
                        sum1=(sum1+quan[k]);
                    }
                    
                    if(strcmp(id_name[k],"shahzaib")==0)
                    {
                        sum2=(sum2+quan[k]);
                    }

                    if(strcmp(id_name[k],"sameer12")==0)
                    {
                        sum3=(sum3+quan[k]);
                    }

                    if(strcmp(id_name[k],"ali12345")==0)
                    {
                        sum4=(sum4+quan[k]);
                    }

                    if(strcmp(id_name[k],"hayyan_1")==0)
                    {
                        sum5=(sum5+quan[k]);
                    }
                }

            if(sum1>sum2 && sum1>sum3 && sum1>sum4 && sum1>sum5)
            {
                cout<<GREEN<<"Best Seller: Rafay"<<RESET<<endl;
            }

            if(sum2>sum1 && sum2>sum3 && sum2>sum4 && sum2>sum5)
            {
                cout<<GREEN<<"Best Seller: Shahzaib"<<RESET<<endl;
            }

            if(sum3>sum1 && sum3>sum2 && sum3>sum4 && sum3>sum5)
            {
                cout<<GREEN<<"Best Seller: Sameer"<<RESET<<endl;
            }

            if(sum4>sum1 && sum4>sum2 && sum4>sum3 && sum4>sum5)
            {
                cout<<GREEN<<"Best Seller: Ali"<<RESET<<endl;
            }

            if(sum5>sum2 && sum5>sum3 && sum5>sum4 && sum5>sum1)
            {
                cout<<GREEN<<"Best Seller: Hayyan"<<RESET<<endl;
            }
        }

        fin.close();
}

void lowstock(void)
{

        char ID_Name[10];
        int ID_No, Price, No_Items, Total_Price, a;
        ifstream fin;
        ofstream fout;

        fin.open("dishes1.txt", ios::in);
        fout.open("notifi.txt", ios::out | ios::app);

        if(!fin)
        {
            cout<<RED<<"\nError reading file"<<endl;
            cout<<"CHeck file name"<<RESET<<endl;
        }

        else
        {
            while(fin>>ID_No, fin.getline(ID_Name, 10, '\t'), fin>>Price>>No_Items>>Total_Price)
            {
                if(No_Items>0 && No_Items<15)
                {
                    a=1;
                    cout<<RED<<"\nLow stock!"<<endl;
                    cout<<"\nIDs  "<<setw(10)<<left<<"Item Name"<<setw(10)<<"No_Items"<<endl;
                    cout<<ID_No<<"     "<<setw(10)<<left<<ID_Name<<setw(10)<<No_Items<<endl;
                }
            }

            if(a==1)
            {
                fout<<"Item is low on stock"<<endl;
            }
            
        }
        
        fin.close();
        fout.close();
}

void sorting(void)
{
    char ID_Name[25][25];
    int ID_No[10], Price[10], No_Items[10], Total_Price[10];
    int i=0, a;

    ifstream fin;
    ofstream fout;

    fin.open("dishes1.txt", ios::in);
    fout.open("temp.txt", ios::out);

    if(!fin)
    {
        cout<<RED<<"\nError reading file"<<RESET<<endl;
    }

    else
    {
        while(fin>>ID_No[i], fin.getline(ID_Name[i], 10, '\t'), fin>>Price[i]>>No_Items[i]>>Total_Price[i])
        {
            fin.ignore();
            i++;
        }

        do
        {
            for(int k=0; k<i; k++)
            {
                if(ID_No[k]>ID_No[k+1])
                {
                        swap(ID_No[k],ID_No[k+1]);
                        swap(ID_Name[k],ID_Name[k+1]);
                        swap(Price[k],Price[k+1]);
                        swap(No_Items[k],No_Items[k+1]);
                        swap(Total_Price[k],Total_Price[k]);
                        a=1;
                }
            }

        }while(a==0);

        for(int k=0; k<i; k++)
        {
            fout<<ID_No[k]<<ID_Name[k]<<"\t"<<Price[k]<<"\t"<<No_Items[k]<<"\t"<<Total_Price[k]<<"\n";
        }
    }
    fin.close();
    fout.close();

    remove("dishes1.txt");
    rename("temp.txt","dishes1.txt");
    
}


