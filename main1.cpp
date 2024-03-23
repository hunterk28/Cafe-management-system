//Kamil Saeed, 23i-2035, Project.


#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>
#include "header.h"
#include<stdio.h>
#define RESET "\033[0m"																						//To Add colour.
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define BOLD "\033[1m"

using namespace std;

int main()
{
		char arrid[25], arrpass[25];
		int user, oper, cho, emp, quan, pri, tprice, idno, cho1, cho2;
		char item[20];
		int l, y, stu, ord, f;
		
		cout<<"\t\t\t   "<<BLUE<<setfill('_')<<setw(41)<<"_"<<endl;
		cout<<"\t\t\t  /"<<setfill(' ')<<setw(40)<<" "<<"/"<<endl;
		cout<<"\t\t\t /"<<RESET<<RED<<" Welcome to Fast Cafe Management System"<<RESET<<BLUE" /"<<endl;
		cout<<"\t\t\t/"<<setfill('_')<<setw(40)<<"_"<<"/"<<RESET<<endl;
		cout<<setfill(' ')<<setw(1)<<endl;
		cout<<endl;
	do
	{
		do
		{
			cout<<YELLOW<<"\nChoose User"<<RESET<<endl;														//Choosing which user is it
			cout<<"\n1. Admin"<<endl;
			cout<<"2. Employee"<<endl;
			cout<<"3. Student/Faculty\n"<<endl;
		
			cout<<"Please Enter: ";
			cin>>user;
		

			if(user==1)																					  //Admin User.
			{
				adminidpass();      																	  //Calling function of login and password.
				lowstock();
			do 
			{
				do 
				{
					do
					{	
				cout<<YELLOW<<"\n\nChoose Operation to perform:"<<RESET<<endl;							  //Choose what admin wants to do.
				cout<<"\n1.Manage stock"<<endl;
				cout<<"2.Display Notifications"<<endl;
				cout<<"3.View Complaints"<<endl;
				cout<<"4.Employee's Credentials"<<endl;
				cout<<"5.User Credentials"<<endl;
				cout<<"6.View scheduled orders"<<endl;
				cout<<BLUE<<"7.Back"<<RESET<<endl;
				cin>>oper;

				if(oper==7)
					break;

				if(oper==1)																				  //Managing Stocks.
				{
					do
					{
						do
						{
							cout<<YELLOW<<"\n\nChoose what you want to do: "<<RESET<<endl;				  //Choose what to do with stocks.
							cout<<"\n1.Display Menu "<<endl;
							cout<<"2.Add Items "<<endl;
							cout<<"3.Delete Items "<<endl;
							cout<<"4.Search Items"<<endl;
							cout<<"5.Sorting Items"<<endl;
							cout<<BLUE<<"6.Back"<<RESET<<endl;
							cin>>cho;

								if(cho==6)
									break;

							if(cho==1)																	    //Displaying items in stock.
							{
								dishes();																    //Calling the function for display.
								cout<<"\nPress '0' to back and '1' to close"<<endl;
								cin>>l;
							}
						
							else if(cho==2)																	//Adding items.
							{
								cout<<"\nAdd Items:"<<endl;	

								cout<<"\nID_No: ";													         //ID No input.
								cin>>idno;

								cout<<"Item name: ";												         //Name of item.
								cin.ignore();
								cin.getline(item, '\n');

								cout<<"Price: ";														     //Price input.
								cin>>pri;

								cout<<"Quantity: ";													         //Quantity input.
								cin>>quan;

								tprice= (quan*pri);														     //Total Price.

								add(idno, item, pri, quan, tprice);										     //Calling function.

								cout<<"Press '0' to back and '1' to close."<<endl;					         //To proceed or end program.
								cin>>l;
							}

							else if(cho==3)																	 //Deleting items.
							{
								cout<<"\nDeleting items: "<<endl;

								dele();																	     //Function for deleting items.

								cout<<"\nPress '0' to back and '1' to close."<<endl;
								cin>>l;
							}

							else if(cho==4)																	 //Searching items.
							{
								cout<<"\nSearching items: ";

								search();																     //Function to search items.

								cout<<"\nPress '0' to back and '1' to close."<<endl;
								cin>>l;
							}

							else if(cho==5)																	 //Sorting k liye
							{
								cout<<"\nSorting: ";

								sorting();																	 //Sorting ka function.

								cout<<"\nPress '0' to back and '1' to close."<<endl;
								cin>>l;

							}

							else if(cho==6)																	 //Going back.
							{
								cout<<"\nGoing back"<<endl;
								
							}

							else//(cho!=1 && cho!=2 && cho!=3 && cho!=4 && cho!=5) 							 //Check for valid entry.
							{
								cout<<RED<<"Invalid Entry!"<<RESET<<endl;
							}
							
						}while(l==0);																		//Check to retun back.

					}while(cho!=1 && cho!=2 && cho!=3 && cho!=4 && cho!=5 && cho!=6);						//Check for invalid.

				}
				else if(oper==2)																			//Notification k liye.		
				{
					cout<<"\nNotification Tab: (max 100 char)"<<endl;										
					notifi();																				//Notification ka function.

					cout<<"\nPress '0' to back and '1' to close."<<endl;
					cin>>y;

				}
					else if(oper==3)																		//Complaints k liye.
					{
						cout<<"\nComplaints: "<<endl;
						cout<<endl;
						comp();																			    //Complaints ka function.
						cout<<"\n";

						cout<<"\nPress '0' to back and '1' to close."<<endl;
						cin>>y;
					}
						else if(oper==4)																    //Employee Credentials.
						{
							do 
							{
								do 
								{
									cout<<YELLOW<<"\n\nChoose what you want to do: "<<RESET<<endl;			//Choose what to do.
									cout<<"\n1.Display Credentials "<<endl;
									cout<<"2.Add Credentials"<<endl;
									cout<<"3.Delete Credentials "<<endl;
									cout<<"4.View Bestseller "<<endl;
									cout<<BLUE<<"5.Back"<<RESET<<endl;
									cin>>cho1;
									if(cho1==5)
										break;

									if(cho1==1)															    //Displaying employee k user name aur password.
									{
										cout<<"\nDisplaying employee's Credentials: "<<endl;
										cout<<endl;

										disemp();															//Function display k liye.

										cout<<"\nPress '0' to back and '1' to close"<<endl;
										cin>>l;
									}
						
									if(cho1==2)																//Adding employee.
									{
										cout<<"\nAdding credentials: "<<endl;

										addemp();															//Function employee add krne k liye.

										cout<<"\nPress '0' to back and '1' to close."<<endl;
										cin>>l;
									}

									if(cho1==3)																//Deleting employee.
									{
										cout<<"\nDeleting items: "<<endl;

										deleemp();															//Function employee delete krne k liye.

										cout<<"\nPress '0' to back and '1' to close."<<endl;
										cin>>l;
									}
						
									if(cho1==4)																//Bestseller.
									{
										cout<<"\nBestseller\n"<<endl;

										seller();															//Function best seller k liye.

										cout<<"\nPress '0' to back and '1' to close."<<endl;
										cin>>l;
									}

									if(cho1==5)																//To return back.
									{
										cout<<"\nGoing back"<<endl;
									}

									if(cho1!=1 && cho1!=2 && cho1!=3 && cho1!=4 && cho1!=5) 				//Check for valid input.
									{
										cout<<RED<<"Invalid Entry!"<<RESET<<endl;
									}
							
								}while(l==0);																//To go back on menu to choose.

								if(cho1==5)
								break;

							}while(cho1!=1 && cho1!=2 && cho1!=3 && cho1!=4 && cho1!=5);					//Loop for invalid input.
						}
							else if(oper==5)																//Student or faculty k credentials.
							{
								do 
								{
									do 
									{
										cout<<YELLOW<<"\n\nChoose what you want to do: "<<RESET<<endl;		//Choose what to do.
										cout<<"\n1.Display Credentials "<<endl;
										cout<<"2.Add Credentials"<<endl;
										cout<<"3.Delete Credentials "<<endl;
										cout<<BLUE<<"4.Back"<<RESET<<endl;
										cin>>cho2;

										if(cho2==4)
										break;

										if(cho2==1)															//Displaying user id and password.
										{
											cout<<"\nDisplaying User Credentials: "<<endl;

											disuser();														//Function users k id pass dekhane k liye

											cout<<"\nPress '0' to back and '1' to close."<<endl;
											cin>>l;

										}

										if(cho2==2)															//User add krne k liye.
										{
											cout<<"\nAdding credentials: "<<endl;

											adduser();														//Function user add krne ka

											cout<<"\nPress '0' to back and '1' to close."<<endl;
											cin>>l;
										}

										if(cho2==3)															//User delete krne k liye.
										{
											cout<<"\nDeleting User: "<<endl;
											
											duser();														//Function user delete krne k liye.

											cout<<"\nPress '0' to back and '1' to close."<<endl;
											cin>>l;
										}

										if(cho2==4)															//Wapis uper janay k liye.
										{
											cout<<"\nGoing back"<<endl;
										}

										if(cho2!=1 && cho2!=2 && cho2!=3 && cho2!=4) 						//Check invalid entry k liye.
										{
											cout<<RED<<"Invalid Entry!"<<RESET<<endl;
										}

									}while(l==0);															//Back janay k liye.

									if(cho2==4)
										break;

								}while(cho2!=1 && cho2!=2 && cho2!=3 && cho2!=4);							//loop invalid k liye.

								}
								else if(oper==6)															//Scheduled order lene k liye.
								{
									cout<<"\nOrders: "<<endl;
									cout<<endl;

									adminsorder();															//admin order approve krne k liye.

									remove("order.txt");													//order remove krne k liye.
									remove("time.txt");														//order time delete krne k liye.

									cout<<"\nPress '0' to back and '1' to close."<<endl;
									cin>>y;
								}
									else if(oper==7)														//Back jane k liye.
									{
											cout<<"\nGoing Back"<<endl;
									}
										else 
										{
											cout<<RED<<"Invalid Entry!"<<RESET<<endl;
										}

					}while(oper!=1 && oper!=2 && oper!=3 && oper!=4 && oper!=5 && oper!=6 && oper!=7);		//Loop invalid input k liye.
					if(oper==7)
						break;

				}while(y==0);																				//condition true hone pr back jane k liye.
				if(oper==7)
					break;
			}while(cho==6 || cho1==5 || cho2==4);																//check to go back.

			}

			else if(user==2)																				//Employee User.
			{
					cout<<"\nEnter Your Employee User ID or Password"<<endl;
					empidpass();																			//Employee ID password.
			do 
			{	
				do
				{
					cout<<YELLOW<<"\nChoose what to do: "<<RESET<<endl;										//What you want to perform.
					cout<<"\n1.Display Menu "<<endl;
					cout<<"2.Search Items "<<endl;
					cout<<"3.Take order "<<endl;
					cout<<"4.Scheduled order "<<endl;
					cout<<BLUE<<"5.Back"<<RESET<<endl;
					cin>>emp;
					if(emp==5)
						break;

					if(emp==1)																				//Display menu for employee
					{
						cout<<"\nDisplaying Menu:"<<endl;

						menu();

						cout<<"\nPress '0' to back and '1' to close"<<endl;
						cin>>l;
					}

					if(emp==2)																				//Search item by employee.
					{
						cout<<"\nSearching items: "<<endl;

						searchemp();

						cout<<"\nPress '0' to back and '1' to close."<<endl;
						cin>>l;
					}
					
					if(emp==3)																				//Employee taking order.
					{
						cout<<"\nTaking Order: "<<endl;

						empord();

						cout<<"\nPress '0' to back and '1' to close."<<endl;
						cin>>l;
					}

					if(emp==4)																				//Employee viewing online order.
					{
						cout<<"\nViewing Online orders: "<<endl;
						
						adminsorder();

						remove("order.txt");																//Removing file where there is online order.
						remove("time.txt");																	//Removing file where order time is store.

						cout<<"\nPress '0' to back and '1' to close."<<endl;
						cin>>l;

					}

					if(emp==5)																				//Returning back.
					{
						cout<<"Returning back"<<endl;
					}

					if(emp!=1 && emp!=2 && emp!=3 && emp!=4 && emp!=5)										//Invalid input.
					{
						cout<<RED<<"\nError! Invalid Entry"<<RESET<<endl;
					}

				}while(l==0);

				if(emp==5)
					break;
			
			}while(emp!=1 && emp!=2 && emp!=3 && emp!=4 && emp!=5);											//loop if invalid input.

			}
				else if(user==3)																			//Employee or Student user.
				{
					do 
					{
					do 
					{
						cout<<"\n1.Display Menu"<<endl;
						cout<<"2.Scheduled Order"<<endl;
						cout<<"3.Complaint's"<<endl;
						cout<<"4.Search items"<<endl;
						cout<<BLUE<<"5.Back"<<RESET<<endl;
						cin>>stu; 

							if(stu==5)
								break;
					
						if(stu==1)																			//User display menu.
						{		

								cout<<"\nDisplaying Menu:\n\n\n";
								menudis();

								cout<<"\nPress '0' to back and '1' to close"<<endl;
								cin>>l;
						}
						else if(stu==2)																		//User scheduled order.
						{
								char arrid[25];
								cout<<"\nScheduled order"<<endl;
					
								cout<<"\nEnter Your ID Password"<<endl;
								useridpass();															    //Function for user id password.

								cout<<"\nEnter ID again for confirmation: ";
								cin.getline(arrid, 25);

								sorder(arrid);															   //Function for scheduled order.

								cout<<"\nPress '0' to back and '1' to close"<<endl;
								cin>>l;
								
						}
							else if(stu==3)									   							   //User adding complaints.
							{
								cout<<"\nAdding complaint's"<<endl;
								ucomp();

								cout<<"\nPress '0' to back and '1' to close"<<endl;
								cin>>l;
						
							}
								else if(stu==4)															  //User searching items.
								{
									cout<<"\nSearching items"<<endl;

									searchuser();

									cout<<"\nPress '0' to back and '1' to close."<<endl;
									cin>>l;
								}
									else if(stu==5)														 //Rturning back.
									{
											cout<<"\nReturning back "<<endl;
									}
										else
										{
										cout<<RED<<"Invalid Entry! "<<RESET<<endl;
										}

					}while(l==0);
					if(stu==5)
						break;

					}while(stu!=1 && stu!=2 && stu!=3 && stu!=4 && stu!=5);								//Loop for invalid input.

				}
					else
					{
							cout<<RED<<"\nInvalid Entry!\n"<<RESET<<endl;
					}
				

		}while(oper==7 || emp==5 || stu==5);														  //Lopp for invalid input.

	}while(user!=1 && user!=2 && user!=3);															  //Loop for invalid input.

}