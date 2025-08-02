#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <Windows.h>
#include <limits>
#include <iomanip>
using namespace std;

int input; //Define input as a global variable to be used in the main function

// Function prototypes. Defined here to let code know these functions exist, and will be programmed later in the file and used later.
void mainMenu();
void displayMenu();
void getRice();
void getNoodles();
void getDessert();
void getDrink();
void payment();

//Define menu items and prices
//Rice category items defined globally as an array of objects for vector usage
vector<int> riceItemNumbers = {1, 2, 3, 4, 5};
vector<string> riceItemNames = {"Egg Fried Rice", "Chicken Rice", "Seafood Rice", "Nasi Lemak", "Nasi Kukus"};
vector<double> riceItemPrices = {7.00, 8.00, 11.00, 4.50, 8.00};

//Noodles category items defined globally as an array of objects for vector usage
vector<int> noodlesItemNumbers = {1, 2, 3, 4, 5};
vector<string> noodlesItemNames = {"Pan Mee", "Szechuan Noodles", "Wan Tan Mee", "Tonkotsu Ramen", "Noodles 5"};
vector<double> noodlesItemPrices = {6.00, 7.00, 8.00, 9.00, 10.00};

// Dessert category items defined globally as an array of objects for vector usage
vector<int> dessertItemNumbers = {1, 2, 3, 4, 5};
vector<string> dessertItemNames = {"Chocolate Brownie", "Cheesecake", "Neapolitan Ice Cream", "Macarons", "Fruit Pudding"};
vector<double> dessertItemPrices = {5.00, 6.00, 4.50, 3.00, 5.00};

//Fetch order details as a global function
vector<int> orderItemNumbers;
vector<string> orderItemNames;
vector<int> orderQuantities;
vector<double> orderUnitPrices;
vector<double> orderTotalPrices;

void mainMenu() {
     //Main Menu
    cout << "                                                                      {~.~}" << endl;
	cout << "                                                                     <(___)>" << endl;
    cout << " *******   ****     ****  ****        *******   ********  ******** **********     **     **     ** *******       **     ****     ** **********" << endl;
    cout << "/**////** /**/**   **/** */// *      /**////** /**/////  **////// /////**///     ****   /**    /**/**////**     ****   /**/**   /**/////**/// " << endl;
    cout << "/**   /** /**//** ** /**/*   /*      /**   /** /**      /**           /**       **//**  /**    /**/**   /**    **//**  /**//**  /**    /**    " << endl;
    cout << "/*******  /** //***  /**/ ****       /*******  /******* /*********    /**      **  //** /**    /**/*******    **  //** /** //** /**    /**    " << endl;
    cout << "/**///**  /**  //*   /** */// *      /**///**  /**////  ////////**    /**     **********/**    /**/**///**   **********/**  //**/**    /**    " << endl;
    cout << "/**  //** /**   /    /**/*   /*      /**  //** /**             /**    /**    /**//////**/**    /**/**  //** /**//////**/**   //****    /**    " << endl;
    cout << "/**   //**/**        /**/ ****       /**   //**/******** ********     /**    /**     /**//******* /**   //**/**     /**/**    //***    /**    " << endl;
    cout << "//     // //         //  ////        //     // //////// ////////      //     //      //  ///////  //     // //      // //      ///     //     " << endl;
	cout << "Welcome to RM8 restaurant" << endl;
	cout << "Choose the option you want" << endl;
	cout << "1. Menu" << endl;
	cout << "2. Background of this restaurant" << endl;
	cout << "Please insert by number thank you" << endl;
    cin >> input;

    if(input == 1) {
        cin.clear(); // Clear the input buffer
        cin.ignore(); // Clear the input buffer
        displayMenu(); // Show menu
    }

    if (cin.fail()) {
        cout << "Invalid input. Please enter a number." << endl;
        cin.clear(); // Clear the error flag
        cin.ignore(); // Clear the input buffer
        mainMenu(); // Show the menu again
    }
}

void displayMenu() {
    while (true) {
        cout << " MENU " << endl;
        cout << "*********************************************************************************" << endl;
        cout << "1. Rice" << endl;
        cout << "2. Noodles" << endl;
        cout << "3. Dessert" << endl;
        cout << "4. Drink" << endl;
        cout << "0. Proceed to payment." << endl;
        cout << "Insert the number you want to proceed to details menu." << endl;
        cin >> input;

        if (input == 1) {
            getRice();
            break;
        } else if (input == 2) {
            getNoodles();
            break;
        } else if (input == 3) {
            getDessert();
            break;
        } else if (input == 4) {
            getDrink();
            break;
        } else if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore( );
            displayMenu(); // Prompt again
            break; // Exit the loop to avoid infinite prompting
        } else if (input == 0) {
            payment();
            break; // Exit the loop to proceed to payment
        } else {
            cout << "Invalid input. Please try again." << endl;
        }
    }
}

void getRice() {
    do {
        // Show menu
        cout << "\n=== MENU ===\n";
        cout << "Item No\tName\t\tPrice (RM)\n";

        for (size_t i = 0; i < riceItemNumbers.size(); ++i) {
            cout << riceItemNumbers[i] << "\t" << left << setw(12) << riceItemNames[i] << "RM " << fixed << setprecision(2) << riceItemPrices[i] << endl;
        }

        cout << "0. Choose from other categories." << endl;

        // Get input
        int itemNum;
        cout << "\nEnter item number: ";
        cin >> itemNum;

        // Search for item in menu
        int index = -1;
        for (size_t i = 0; i < riceItemNumbers.size(); ++i) {
            if (riceItemNumbers[i] == itemNum) {
                index = i;
                break;
            }
        }

        if (cin.fail()) {
            cout << "Invalid item number.\n";
            cin.clear(); // Clear the error flag
            cin.ignore(); // Clear the input buffer
            continue; // Continue to prompt for item number
        }

        if (itemNum == 0) {
            displayMenu();
            return; // Exit the function to avoid further processing
        } else if (index == -1) {
            cout << "Invalid item number. Please try again." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(); // Clear the input buffer
            continue; // Prompt again
        }

        // Get quantity
        int qty;
        cout << "Enter quantity: ";
        cin >> qty;
        
        // Store in order vectors
        orderItemNumbers.push_back(riceItemNumbers[index]);
        orderItemNames.push_back(riceItemNames[index]);
        orderQuantities.push_back(qty);
        orderUnitPrices.push_back(riceItemPrices[index]);
        orderTotalPrices.push_back(qty * riceItemPrices[index]);

    } while (true);
}

void getNoodles() {
    do {
        // Show menu
        cout << "\n=== MENU ===\n";
        cout << "Item No\tName\t\tPrice (RM)\n";
        for (size_t i = 0; i < noodlesItemNumbers.size(); ++i) {
            cout << noodlesItemNumbers[i] << "\t" << left << setw(12) << noodlesItemNames[i]
                 << "RM " << fixed << setprecision(2) << noodlesItemPrices[i] << endl;
        }
        cout << "0. Choose from other categories." << endl;

         // Get input
        int itemNum;
        cout << "\nEnter item number: ";
        cin >> itemNum;

        // Search for item in menu
        int index = -1;
        for (size_t i = 0; i < noodlesItemNumbers.size(); ++i) {
            if (noodlesItemNumbers[i] == itemNum) {
                index = i;
                break;
            }
        }

        if (cin.fail()) {
            cout << "Invalid item number.\n";
            cin.clear(); // Clear the error flag
            cin.ignore( ); // Clear the input buffer
            continue; // Continue to prompt for item number
        }

        if (itemNum == 0) {
            displayMenu();
            return; // Exit the function to avoid further processing
        } else if (index == -1) {
            cout << "Invalid item number. Please try again." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore( ); // Clear the input buffer and allow the first digit to be read
            continue; // Prompt again
        }

        // Get quantity
        int qty;
        cout << "Enter quantity: ";
        cin >> qty;
        
        // Store in order vectors
        orderItemNumbers.push_back(noodlesItemNumbers[index]);
        orderItemNames.push_back(noodlesItemNames[index]);
        orderQuantities.push_back(qty);
        orderUnitPrices.push_back(noodlesItemPrices[index]);
        orderTotalPrices.push_back(qty * noodlesItemPrices[index]);

    } while (true);
}

void getDessert() {
    // Dessert menu logic goes here
    cout << "Dessert menu is not implemented yet." << endl;
    displayMenu(); // Go back to menu selection
}

void getDrink() {
    // Drink menu logic goes here
    cout << "Drink menu is not implemented yet." << endl;
    displayMenu(); // Go back to menu selection
}

void payment() {
    // Print receipt
    double grandTotal = 0.0;
    cout << "\n=== RECEIPT ===\n";
    cout << "Item\t\tQty\tUnit Price\tTotal\n";
    for (size_t i = 0; i < orderItemNumbers.size(); ++i) {
        cout << left << setw(12) << orderItemNames[i]
             << "\t" << orderQuantities[i]
             << "\tRM " << fixed << setprecision(2) << orderUnitPrices[i]
             << "\tRM " << orderTotalPrices[i] << endl;
        grandTotal += orderTotalPrices[i];
    }

    cout << "-------------------------------\n";
    cout << "Total: RM " << fixed << setprecision(2) << grandTotal << endl;
    return;
}

int main() {
    void displayMenu(); // Function prototype for displaying the menu
    void getRice(); // Function prototype for getting rice orders   
    void getNoodles(); // Function prototype for getting noodles orders

    mainMenu(); // Call the main menu function, and the start of the program

    return 0;
}
