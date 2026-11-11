#include <iostream>
#include <string>
using namespace std;

int main() {
string usernames[5] = {"pogi", "azure", "rence", "goat", "rat"};
    int pins[5] = {1234, 2222, 3333, 4444, 5555};
    double balances[5] = {5000, 3000, 4000, 6000, 2500};
//for the stored info
    string username;
    int pin, choice;
    int user = -1;
    int attempts = 0;
    double wAmount, dAmount;
    double dTotal = 0;
    double wTotal = 0;
//this bool checks whether an account is locked
    bool locked[5] = {false, false, false, false, true};
    bool login = false;
    int rec = false;

    cout << "===== AZURE ATM MACHINE =====" << endl;

    cout << "Enter Username: ";
    cin >> username;
//the Username finder to
    for (int x = 0; x < 5; x++) {
        if (username == usernames[x]) {
            user = x;
            break;
        }
    }

    if (user == -1) {
        cout << ">> User Not Found! << \n>> Thank you for using our service! <<" << endl;
    }
    else if (locked[user] == true) {
        cout << ">> Account is Locked! <<" << endl;
    }
    else {
//PIN Attempts
        while (attempts < 3) {

            cout << "Enter PIN: ";
            cin >> pin;

            if (pin == pins[user]) {
                login = true;
                cout << "Login Successful!" << endl;
                break;
            }
            else {
                attempts++;

                cout << "Wrong PIN!" << endl;

                if (attempts < 3) {
                    cout << "Attempts left: " << 3 - attempts << endl;
                }
            }
        }

        if (login == false) {
            locked[user] = true;
            cout << "\n>> Account Locked! Too many wrong attempts. <<";
        }
    }
// MENU
    if (login == true) {

        while (true) {

            cout << "\n===== ATM MENU =====" << endl;
            cout << "1. Check Balance" << endl;
            cout << "2. Deposit" << endl;
            cout << "3. Withdraw" << endl;
            cout << "4. Exit" << endl;

            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) {
                cout << "\n>> Balance: ₱" << balances[user] << " <<" << endl;
            }
            else if (choice == 2) {
                cout << "Enter amount: ";
                cin >> dAmount;

                if (dAmount > 0) {
                    balances[user] += dAmount;
                    dTotal += dAmount;
                    cout << "\n >> Deposit Successful! << " << endl;
                }
                else {
                    cout << ">> Invalid Amount! <<" << endl;
                }
            }
            else if (choice == 3) {
                cout << "Enter amount: ";
                cin >> wAmount;

                if (wAmount > 0 && wAmount <= balances[user]) {
                    balances[user] -= wAmount;
                    wTotal += wAmount;
                    cout << ">> Withdraw Successful! <<" << endl;
                }
                else {
                    cout << ">> Insufficient Balance! <<" << endl;
                }
            }
                
            else if (choice == 4) {
                
                
                cout << "Would you like a receipt? (0 for \"No\", 1 for \"Yes\"): ";
                cin >> rec;
                
                if (rec == 1){
                    int rec; 
                    
                    cout << "\n===== AZURE ATM MACHINE RECEIPT =====" << endl;
                    cout << "Username: \t" << username << endl;
                    cout << "Deposited: \t" << dTotal << endl;
                    cout << "Withdrawn: \t" << wTotal << endl;
                    cout << "Remaining Balance: \t" << balances[user] << endl;
                    cout << "Thank you for using the AZURE ATM MACHINE!";
                } 
                else if (rec == 0) {
                    cout << "\nThank you for using the AZURE ATM MACHINE!";
                }
                else {

                    cout << ">> Oops! Invalid Choice! Please enter 0 or 1 only. <<" << endl;
                    continue;

                }

                break;
            }
            else {
                cout << "Invalid Choice!";
            }
        }
    }



    return 0;
}
