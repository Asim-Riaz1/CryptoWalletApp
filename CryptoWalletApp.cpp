#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Wallet {
private:
    vector<string> currencyList;  // A vector to store the currency types
    double balance;               // The balance of the wallet

public:
    // Constructor to initialize the wallet
    Wallet() {
        balance = 0.0;
    }

    // Function to insert currency into the wallet
    void insertCurrency(const string& currency, double amount) {
        currencyList.push_back(currency);
        balance += amount;
        cout << amount << " " << currency << " inserted into the wallet. Balance: " << balance << endl;
    }

    // Function to remove currency from the wallet
    void removeCurrency(const string& currency, double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << amount << " " << currency << " removed from the wallet. Balance: " << balance << endl;
        } else {
            cout << "Insufficient balance to remove " << amount << " " << currency << endl;
        }
    }

    // Function to check the balance of the wallet
    double checkBalance() const {
        return balance;
    }

    // Function to check if a specific currency exists in the wallet
    bool hasCurrency(const string& currency) const {
        for (const auto& item : currencyList) {
            if (item == currency) {
                return true;
            }
        }
        return false;
    }

    // Function to display the current wallet status
    void showWalletStatus() const {
        cout << "Wallet Status: \n";
        cout << "Balance: " << balance << endl;
        cout << "Currencies: ";
        for (const auto& currency : currencyList) {
            cout << currency << " ";
        }
        cout << endl;
    }
};

int main() {
    Wallet myWallet;  // Create a wallet object
    int choice;
    string currency;
    double amount;

    while (true) {
        // Menu for user to choose actions
        cout << "\nWelcome to the Wallet Program!" << endl;
        cout << "1. Insert Currency" << endl;
        cout << "2. Remove Currency" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Check if Currency Exists" << endl;
        cout << "5. Show Wallet Status" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:  // Insert Currency
                cout << "Enter the currency type (e.g., USD, EUR): ";
                cin >> currency;
                cout << "Enter the amount to insert: ";
                cin >> amount;
                myWallet.insertCurrency(currency, amount);
                break;

            case 2:  // Remove Currency
                cout << "Enter the currency type (e.g., USD, EUR): ";
                cin >> currency;
                cout << "Enter the amount to remove: ";
                cin >> amount;
                myWallet.removeCurrency(currency, amount);
                break;

            case 3:  // Check Balance
                cout << "Current Balance: " << myWallet.checkBalance() << endl;
                break;

            case 4:  // Check if Currency Exists
                cout << "Enter the currency type (e.g., USD, EUR): ";
                cin >> currency;
                if (myWallet.hasCurrency(currency)) {
                    cout << currency << " is present in the wallet." << endl;
                } else {
                    cout << currency << " is not present in the wallet." << endl;
                }
                break;

            case 5:  // Show Wallet Status
                myWallet.showWalletStatus();
                break;

            case 6:  // Exit
                cout << "Thank you for using the Wallet Program!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
