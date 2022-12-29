#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <string>
using namespace std;

int main()
{
    cout << setw(50) << "*********************" << endl;
    cout << setw(55) << "WELCOME TO PICK'N GO SUPERMARKET" << endl;
    cout << setw(50) << "*********************" << endl;
    cout << endl;
    int question, owners_choice2, products_num, count3 = 0;
    char owners_choice;
    string main_menu;
    cout << "Are you an Owner (1) or a Customer (2)?" << endl;
	cin >> question;
    cout << endl;
    //Arrays
    string Products [100] = {"0"};
    double Prices [100] = {0};
    int ID [100] = {0};

	while (true) 
    {
		if (question == 1) 
        {
            //Main Menu
            cout << endl;
			question = true;
			cout << "Hello Owner!" << endl;
            cout << endl;
            cout << "What would you like to do: " << endl;
            cout << "a. Preview list of available products" << endl;
            cout << "b. Create a list of products" << endl;
            cout << "c. Edit list of products" << endl;
            cout << "d. Edit products prices" << endl;
            cout << "e. Exit" << endl;
            cin >> owners_choice;
            cout << endl;
           
            //Submenu
            switch (owners_choice)
            {
                //Preview list of available products (Jana)
                case('a'):
                {
                    cout << "Preview list of availabe products:" << endl;
                    for(int l = 0; l < (sizeof(Products)/sizeof(Products[0])); l++)
                    {
                     if(Prices[l] == 0 && ID[l] == 0) 
                     {
                         count3++;
                         continue;
                     }
                    }

                    if (count3 == 100)
                    {
                        cout << setw(60) << left << "No products are currently available." << endl;
                        cout << endl;
                        cout << "Would you like to (1) return to main menu or (2) create a new list?" << endl;
                        cin >> owners_choice2;
                        if(owners_choice2 == 1)
                        {
                            break;
                        }
                    }
                    else
                    {
                        cout << "The available products are: " << endl;
                        cout << endl;
                        cout << setw(25) << left << "Product ID" << setw(25) << left << "Product name" << setw(30) << left << "Price" << endl;
                        cout << endl;
                        for (int j = 0; j < (sizeof(Products)/sizeof(Products[0])); j++)
                        {
                         if(Prices[j] == 0.00 && ID[j] == 0)
                         {
                            continue;
                         }
                         else
                         cout << setw(25) << left << ID[j] << setw(25) << left << Products[j] << setw(25) << left << Prices[j] << "$" << endl;
                        }
                        cout << endl;
                        cout << "Would you like to exit to main menu?" << endl;
                        cin >> main_menu;
                        if(main_menu == "Yes" || main_menu == "yes")
                        {
                         continue; 
                        }
                        break;
                    }
                    //no 'break;' so the user enters the "create a list" option
                } 

                //Create a list of products (Nouran)
                case('b'):
                {
                    cout << endl;
				    cout << "Create a list of products:" << endl;
				    cout << "How many products will be in the list?" << endl;
				    cin >> products_num;
				    for (int o = 0; o < products_num; o++)
                    {
                    cout << "Please enter the product ID: ";
                    cin >> ID[o];
					cout << "Please enter the product name: ";
					cin >> Products[o];
					cout << "please enter " << Products[o] << "'s price: ";
					cin >> Prices[o];
				    }
                    cout << "Data saved. Would you like to return to main menu?" << endl;
                    cin >> main_menu;
                    if(main_menu == "Yes" || main_menu == "yes")
                    {
                      continue; 
                    }
                    break;
                }

                //Edit list of products (Jana)
			    case('c'):
				{   int edit, additional_items, count = 1, k = 0;
                    cout << setw(10) << left << "Edit list of products:" << endl;
                    cout << "Do you want to (1) add or (2) delete products?" << endl;
                    cin >> edit;
                    cout << endl;
                    if(edit == 1)
                    {
                        cout << "How many items do you want to add? " << endl;
                        cin >> additional_items;
                        while (count <= additional_items)
                        {
                         cout << "What is the ID of the product you wish to add: " << endl;
                         cin >>  ID[products_num + k];
                         cout << "What is the name of the product you wish to add: " << endl;
                         cin >> Products[products_num + k];
                         cout << "What is the price of the product you wish to add: " << endl;
                         cin >> Prices[products_num + k] ;
                         count++ ;
                         ++k ;
                        }
                        cout << endl;
                        cout << "Data saved. Would you like to exit to main menu?" << endl;
                        cin >> main_menu;
                        if(main_menu == "Yes" || main_menu == "yes")
                        {
                         continue; 
                        }
                    }
                    if (edit == 2)
                    {
                        int number_of_items_deleted, count_2 = 0, deleted_ID;
                        cout << "How many products would you like to delete?" << endl;
                        cin >> number_of_items_deleted;
                        while (count_2 < number_of_items_deleted)
                        {
                            cout << "Enter the ID of the product you wish to delete from the list?" << endl;
                            cin >> deleted_ID;
                            count_2++ ; 
                            for(int w = 0; w < (sizeof(Products)/sizeof(Products[0])); w++)
                            {
                              if (ID[w]== deleted_ID)
                              {
                              ID[w] = 0; 
                              Products[w] = "0";
                              Prices[w] = 0.00;
                              }

                            }
                        }
                        cout << endl;
                        cout << "Data saved. Would you like to exit to main menu?" << endl;
                        cin >> main_menu;
                        if(main_menu == "Yes" || main_menu == "yes")
                        {
                         continue; 
                        }
                        break;
                    }
                }
            }
        }
     else if (question == 2)
     {
        question = true;
        cout << "Hello Customer!" << endl;
        break;
     }
	 else 
     {
		cout << "Invalid input, please try again..." << endl;
		cin >> question;
        continue;
	 }
     
    } 
}


