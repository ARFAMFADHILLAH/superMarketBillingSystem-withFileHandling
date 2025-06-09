#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <string>
#include <algorithm>
using namespace std;

class Bill {
private:
    string Item;
    int Rate, Quantity;
public:
    Bill() : Item(""), Rate(0), Quantity(0) {}

    void setItem(string item) {
        Item = item;
    }

    void setRate(int rate) {
        Rate = rate;
    }

    void setQuant(int quant) {
        Quantity = quant;
    }

    string getItem() {
        return Item;
    }

    int getRate() {
        return Rate;
    }

    int getQuant() {
        return Quantity;
    }
};

void addItem(Bill b) {
    bool close = false;
    while (!close) {
        int choice;
        cout << "\t1. Add.\n";
        cout << "\t2. Close.\n";
        cout << "\tEnter Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            system("cls");
            string item;
            int rate, quant;

            cout << "\tEnter Item Name: ";
            getline(cin, item);
            b.setItem(item);

            cout << "\tEnter Rate Of Item: ";
            cin >> rate;
            b.setRate(rate);

            cout << "\tEnter Quantity Of Item: ";
            cin >> quant;
            b.setQuant(quant);

            ofstream out("D:/Bill.txt", ios::app);
            if (!out) {
                cout << "\tError: File Can't Open!" << endl;
            } else {
                out << b.getItem() << " : " << b.getRate() << " : " << b.getQuant() << endl;
            }
            out.close();
            cout << "\tItem Added Successfully" << endl;
            Sleep(3000);
        } else if (choice == 2) {
            system("cls");
            close = true;
            cout << "\tBack To Main Menu!" << endl;
            Sleep(3000);
        }
    }
}

void PrintBill(Bill b) {
    system("cls");
    int count = 0;
    bool close = false;

    while (!close) {
        system("cls");
        int choice;
        cout << "\t1. Add Bill.\n";
        cout << "\t2. Close Session.\n";
        cout << "\tEnter Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string item;
            int quant;
            cout << "\tEnter Item: ";
            getline(cin, item);
            cout << "\tEnter Quantity: ";
            cin >> quant;

            ifstream in("D:/Bill.txt");
            ofstream out("D:/Bill_Temp.txt");

            string line;
            bool found = false;

            while (getline(in, line)) {
                stringstream ss(line);
                string itemName;
                int itemRate, itemQuant;

                size_t pos1 = line.find(" : ");
                size_t pos2 = line.find(" : ", pos1 + 3);
                if (pos1 != string::npos && pos2 != string::npos) {
                    itemName = line.substr(0, pos1);
                    itemRate = stoi(line.substr(pos1 + 3, pos2 - (pos1 + 3)));
                    itemQuant = stoi(line.substr(pos2 + 3));

                    // Trim whitespace
                    itemName.erase(remove(itemName.begin(), itemName.end(), '\t'), itemName.end());
                    itemName.erase(itemName.find_last_not_of(" ") + 1);

                    if (item == itemName) {
                        found = true;
                        if (quant <= itemQuant) {
                            int amount = itemRate * quant;
                            cout << "\n\tItem\tRate\tQuantity\tAmount\n";
                            cout << "\t" << itemName << "\t" << itemRate << "\t" << quant << "\t\t" << amount << endl;
                            int newQuant = itemQuant - quant;
                            count += amount;

                            if (newQuant > 0)
                                out << itemName << " : " << itemRate << " : " << newQuant << endl;
                        } else {
                            cout << "\tSorry, not enough quantity in stock!" << endl;
                            out << line << endl;
                        }
                    } else {
                        out << line << endl;
                    }
                }
            }

            if (!found) {
                cout << "\tItem Not Available!" << endl;
            }

            in.close();
            out.close();
            remove("D:/Bill.txt");
            rename("D:/Bill_Temp.txt", "D:/Bill.txt");
            Sleep(3000);
        } else if (choice == 2) {
            close = true;
            cout << "\tCounting Total Bill..." << endl;
            Sleep(2000);
        }
    }

    system("cls");
    cout << "\n\n\tTotal Bill ----------------- : " << count << endl << endl;
    cout << "\tThanks For Shopping!" << endl;
    Sleep(4000);
}

int main() {
    Bill b;
    bool exit = false;
    while (!exit) {
        system("cls");
        int val;

        cout << "\tWelcome To Super Market Billing System\n";
        cout << "\t***************************************\n";
        cout << "\t1. Add Item\n";
        cout << "\t2. Print Bill\n";
        cout << "\t3. Exit\n";
        cout << "\tEnter Choice: ";
        cin >> val;
        cin.ignore();

        if (val == 1) {
            addItem(b);
        } else if (val == 2) {
            PrintBill(b);
        } else if (val == 3) {
            system("cls");
            exit = true;
            cout << "\tGood Luck!" << endl;
            Sleep(3000);
        } else {
            cout << "\tInvalid Choice!" << endl;
            Sleep(2000);
        }
    }
    return 0;
}
