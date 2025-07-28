#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <Windows.h>
using namespace std;

int main() {
	int num1, menu1, quant_rice, quant_nood, quant_dess, quant_drink, price, pay_meth;
	char choice1;
	string rice, noodles, dessert, drink;
	vector<string> orders;
	step0:
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
	
	step1:	
	cin >> num1;
	step2:
	if (num1 == 1) {
		cout << " MENU " << endl;
		cout << "*********************************************************************************" << endl;
		cout << "1. Rice" << endl;
		cout << "2. Noodles" << endl;
		cout << "3. dessert" << endl;
		cout << "4. drink" << endl;
		cout << "Insert the number you want to proceed to details menu." << endl;
		cin >> menu1;
		cin.ignore(); // Clear the newline character from the input buffer
		if (menu1 == 1) {
			cout << "1. fried rice" << endl;
			cout << "2. rice 2" << endl;
			cout << "3. rice 3" << endl;
			cout << "4. rice 4" << endl;
			cout << "5. rice 5" << endl;
			cout << "6. rice 6" << endl;
			cout << "7. rice 7" << endl;
			cout << "8. rice 8" << endl;
			cout << "Insert the name of the rice you want." << endl;
			cout << "Insert (done) to end placing order in rice." << endl;
			while (true) {
				getline(cin, rice);
				if (rice == "done") {
					break;
				} else if (rice != "fried rice" && rice != "rice 2" && rice != "rice 3" && rice != "rice 4" && rice != "rice 5" && rice != "rice 6" && rice != "rice 7" && rice != "rice 8" && !rice.empty()) {
					cout << "Invalid rice option. Please try again." << endl;
					continue;
				}
				orders.push_back(rice);
			}
		}
		else if (menu1 == 2) {
			cout << "1. noodles 1" << endl;
			cout << "2. noodles 2" << endl;
			cout << "3. noodles 3" << endl;
			cout << "4. noodles 4" << endl;
			cout << "5. noodles 5" << endl;
			cout << "6. noodles 6" << endl;
			cout << "7. noodles 7" << endl;
			cout << "8. noodles 8" << endl;
			cout << "Insert the name of the noodles you want." << endl;
			cout << "Insert (done) to end placing order in noodles" << endl;
			while (true) {
				getline(cin, noodles);
				if (noodles == "done") {
					break;
				}
				if (!noodles.empty()) {
					orders.push_back(noodles);
				}
			}
		}
		else if (menu1 == 3) {
			cout << "1. dessert 1" << endl;
			cout << "2. dessert 2" << endl;
			cout << "3. dessert 3" << endl;
			cout << "4. dessert 4" << endl;
			cout << "5. dessert 5" << endl;
			cout << "6. dessert 6" << endl;
			cout << "7. dessert 7" << endl;
			cout << "8. dessert 8" << endl;
			cout << "Insert the name of the dessert you want." << endl;
			cout << "Insert (done) to end placing order in dessert" << endl;
			while (true) {
				getline(cin, dessert);
				if (dessert == "done") {
					break;
				}	
				if (!dessert.empty()) {
					orders.push_back(dessert);
				}
			}
		}
		else if (menu1 == 4) {
			cout << "1. drink 1" << endl;
			cout << "2. drink 2" << endl;
			cout << "3. drink 3" << endl;
			cout << "4. drink 4" << endl;
			cout << "5. drink 5" << endl;
			cout << "6. drink 6" << endl;
			cout << "7. drink 7" << endl;
			cout << "8. drink 8" << endl;
			cout << "Insert the name of the drink you want." << endl;
			cout << "Insert (done) to end placing order in drink" << endl;
			while (true) {
				getline(cin, drink);
				if (drink == "done") {
					break;
				}
			}
		}
		else {
			cout << "Please insert 1, 2, 3 or 4 to the blank space. Thank you" << endl;
			system("pause");
			goto step2;
		}
		step4:
			cout << "Do you wish to continue placing order? ";
			cin >> choice1;
			if (choice1 == 'y' || choice1 == 'Y') {
				goto step2;
			}
			else if (choice1 == 'n' || choice1 == 'N') {
				goto step3;
			}
			else {
				cout << "PLEASE INSERT Y OR N TO PROCEED!!!!!!!" << endl;
				goto step4;
			}
	}
	else if (num1 == 2) {
		cout << "write something" << endl;
		system("pause");
		goto step0;
	}
	else {
		cout << "Please insert 1 or 2 to the blank space. Thank you" << endl;
		system("pause");
		goto step0;
	}
step3:
	cout << "\nYou've ordered " << orders.size() << " item(s):\n" << endl;
	for (string item : orders) {
		cout << "- " << item << endl;
	}
	price = orders.size() * 8;
	cout << "Total price: RM" << price << endl;
	cout << "Choose your payment method:" << endl;
	cout << "1. eWallet" << endl;
	cout << "2. Credit Card" << endl;
	cin >> pay_meth;
	if (pay_meth == 1) {
		cout << "You have chosen eWallet." << endl;
	}
	else if (pay_meth == 2) {
		cout << "You have chosen Credit Card." << endl;
	}
	else {
		cout << "Invalid payment method selected." << endl;
		return 1;
	}
	for (int i = 3; i > 0; i--) {
		cout << i << endl;
		Sleep(1000);
	}
	cout << "Thank you for your order!" << endl;
	return 0;
}
