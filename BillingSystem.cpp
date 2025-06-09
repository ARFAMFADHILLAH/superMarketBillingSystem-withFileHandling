#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

class Bill {
private:
    string Item;
    int Rate, Quantity;
public:
    Bill() : Item(""), Rate(0), Quantity(0) {}

    void setItem(const string& item) {
        Item = item;
    }

    void setRate(int rate) {
        Rate = rate;
    }

    void setQuant(int quant) {
        Quantity = quant;
    }

    string getItem() const {
        return Item;
    }

    int getRate() const {
        return Rate;
    }

    int getQuant() const {
        return Quantity;
    }
};

// Helper function to trim whitespace
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    size_t last = str.find_last_not_of(" \t\r\n");
    if (first == string::npos || last == string::npos)
        return "";
    return str.substr(first, last - first + 1);
}

void addItem(Bill& b) {
    bool close = false;
    while (!close) {
        int choice;
        cout << "\n\t1. Add Item\n";
        cout << "\t2. Close\n";
        cout << "\tEnter Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            system("cls");
            string item;
            int rate, quant;

            cout << "\tEnter Item Name: ";
            getline(cin, item);
            b.setItem(trim(item));

            cout << "\tEnter Rate Of Item: ";
            while (!(cin >> rate)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "\tInvalid input. Enter a number: ";
            }
            b.setRate(rate);

            cout << "\tEnter Quantity Of Item: ";
            while (!(cin >> quant)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "\tInvalid input. Enter a number: ";
            }
            b.setQuant(quant);
            cin.ignore();

            ofstream out("D:/Bill.txt", ios::app);
            if (!out.is_open()) {
                cerr << "\tError: File Can't Open!" << endl;
            } else {
                out << b.getItem() << " : " << b.getRate() << " : " << b.getQuant() << endl;
                out.close();
                cout << "\tItem Added Successfully\n";
            }
            Sleep(2000);
        } else if (choice == 2) {
            close = true;
            cout << "\tReturning to main menu...\n";
            Sleep(1500);
        } else {
            cout << "\tInvalid choice!\n";
            Sleep(1500);
        }
    }
}

void PrintBill(Bill& b) {
    system("cls");
    int totalAmount = 0;
    bool close = false;

    while (!close) {
        int choice;
        cout << "\n\t1. Add Bill Item\n";
        cout << "\t2. Close Session\n";
        cout << "\tEnter Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string inputItem;
            int inputQuantity;

            cout << "\tEnter Item Name: ";
            getline(cin, inputItem);
            inputItem = trim(inputItem);

            cout << "\tEnter Quantity: ";
            while (!(cin >> inputQuantity)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "\tInvalid input. Enter a number: ";
            }
            cin.ignore();

            ifstream inFile("D:/Bill.txt");
            ofstream tempFile("D:/Bill_Temp.txt");

            if (!inFile.is_open() || !tempFile.is_open()) {
                cerr << "\tError opening files.\n";
                return;
            }

            string line;
            bool found = false;

            while (getline(inFile, line)) {
                stringstream ss(line);
                string itemName;
                int itemRate, itemQuant;

                size_t pos1 = line.find(" : ");
                size_t pos2 = line.find(" : ", pos1 + 3);
                if (pos1 != string::npos && pos2 != string::npos) {
                    itemName = trim(line.substr(0, pos1));
                    itemRate = stoi(line.substr(pos1 + 3, pos2 - (pos1 + 3)));
                    itemQuant = stoi(line.substr(pos2 + 3));

                    if (itemName == inputItem) {
                        found = true;
                        if (inputQuantity <= itemQuant) {
                            int amount = itemRate * inputQuantity;
                            cout << "\n\tItem\tRate\tQuantity\tAmount\n";
                            cout << "\t" << itemName << "\t" << itemRate << "\t" << inputQuantity << "\t\t" << amount << endl;
                            totalAmount += amount;

                            int newQuant = itemQuant - inputQuantity;
                            if (newQuant > 0)
                                tempFile << itemName << " : " << itemRate << " : " << newQuant << endl;
                        } else {
                            cout << "\tInsufficient stock!\n";
                            tempFile << line << endl;
                        }
                    } else {
                        tempFile << line << endl;
                    }
                }
            }

            if (!found) {
                cout << "\tItem Not Found!\n";
            }

            inFile.close();
            tempFile.close();

            remove("D:/Bill.txt");
            rename("D:/Bill_Temp.txt", "D:/Bill.txt");

            Sleep(3000);
        } else if (choice == 2) {
            close = true;
            cout << "\n\tCalculating total bill...\n";
            Sleep(2000);
        } else {
            cout << "\tInvalid Choice!\n";
            Sleep(1500);
        }
    }

    system("cls");
    cout << "\n\tTotal Bill ----------------- : " << totalAmount << "\n";
    cout << "\tThank You for Shopping!\n\n";
    Sleep(4000);
}

int main() {
    Bill b;
    bool exit = false;

    while (!exit) {
        system("cls");
        int choice;

        cout << "\tWelcome to Supermarket Billing System\n";
        cout << "\t======================================\n";
        cout << "\t1. Add Item\n";
        cout << "\t2. Print Bill\n";
        cout << "\t3. Exit\n";
        cout << "\tEnter Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            addItem(b);
            break;
        case 2:
            PrintBill(b);
            break;
        case 3:
            exit = true;
            cout << "\n\tExiting... Thank you!\n";
            Sleep(2000);
            break;
        default:
            cout << "\tInvalid Choice! Please try again.\n";
            Sleep(1500);
        }
    }

    return 0;
}
