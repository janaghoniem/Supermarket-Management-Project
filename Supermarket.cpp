#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <map>
#include <iomanip>
using namespace std;

int main ()
{ 
    cout << setw(50) << "*********************" << endl;
    cout << setw(55) << "WELCOME TO PICK'N GO SUPERMARKET" << endl;
    cout << setw(50) << "*********************" << endl;
    cout << endl;
    int question;
    char owners_choice;
    string main_menu;
    cout << "Are you an Owner (1) or a Customer (2)?" << endl;
	cin >> question;
    cout << endl;
    //Arrays
    string Products [50] = {"laundry detergent 1 kg", "shampoo 500 ml","conditioner 500 ml", "large salt chips",
    "small salt chips","soda can","small water bottle", "frozen shrimp 1 kg", "chicken breasts 1 kg", 
    "milk 1 L" , "croissants"};
    double Prices [50] = {5.99, 2.99, 2.95, 3.00, 1.50, 1.00, 0.50, 9.50, 8.85, 5.00, 2.85, };
    int ID [50] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111};

	while (true) {
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
            cout << endl;
            cin >> owners_choice;
            cout << endl;

           
            //Submenu
            switch (owners_choice)
            {
                //Preview list of available products (Jana)
                case('a'):
                {
                cout << "The available products are: " << endl;
                cout << endl;
                cout << setw(25) << left << "Product ID" << setw(25) << left << "Product name" << setw(30) << left << "Price" << endl;
                cout << endl;
                for (int j = 0; j <= (sizeof(Products)/sizeof(Products[0])); j++)
                {
                    if(ID[j] != 0 && Products[j] != "0" && Prices[j] != 0.00)
                    cout << setw(25) << left << ID[j] << setw(25) << left << Products[j] << setw(25) << left << Prices[j] << "$" << endl;
                    else
                    break;
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

                //Create list of products (Nouran)
                case ('b'):
                {
                    cout << "b. Create a list of products" << endl;
				    cout << "how many product will you use while creating the list? ";
				    int products_num;
				    cin >> products_num;
				    for (int o= 0; o < products_num; o++) 
                    {
					string product_name[products_num];
					double product_price[products_num];
					cout << "please enter the product name : ";
					cin >> product_name[o];
					cout << "please enter " << product_name[o] << " price : ";
					cin >> product_price[o];
					cout << product_name[o] << setw(15) << product_price[o] << "$" << endl;
				    }
				break;
                }
                case ('c'):
                {
                    int edit, new_ID, additional_items, count = 1, k = 0;
                    string new_name;
                    double new_price;
                    cout << setw(10) << left << "Edit list of products" << endl;
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
                         cin >>  ID[11 + k];
                         cout << "What is the name of the product you wish to add: " << endl;
                         cin >> Products[11 + k];
                         cout << "What is the price of the product you wish to add: " << endl;
                         cin >> Prices[11 + k] ;
                         count++ ;
                         ++k ;
                        }
                        for (int j = 0; j <= (sizeof(Products)/sizeof(Products[0])); j++)
                        {
                         if(ID[j] != 0 && Products[j] != "0" && Prices[j] != 0.00)
                         cout << setw(25) << left << ID[j] << setw(25) << left << Products[j] << setw(25) << left << Prices[j] << "$" << endl;
                         else
                         break;
                        }
                        cout << endl;
                        cout << "Would you like to exit to main menu?" << endl;
                        cin >> main_menu;
                        if(main_menu == "Yes" || main_menu == "yes")
                        {
                         continue; 
                        }
                    }
                    if (edit == 2)
                    {

                    }
                    
                    break;
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
		}
        }
	}
