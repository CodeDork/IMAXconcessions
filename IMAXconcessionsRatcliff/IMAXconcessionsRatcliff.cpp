#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Global constants
const double TAX_RATE = 0.07;

// Function declarations
void displayMenu();
void displaySubMenu(int choice, double& price);
void getQuantity(int& quantity);
void addToOrder(const string& itemName, double price, int quantity, double& total);

int main() {
    int choice, quantity;
    double total = 0.0;
    char continueOrder;
    string itemName;
    double itemPrice;

    cout << "Welcome to the AI IMAX Theatre Concessions!" << endl;

    do {
        displayMenu();
        cin >> choice;

        if (choice == 5) {
            break; // Stop the order
        }

        displaySubMenu(choice, itemPrice);
        getQuantity(quantity);

        switch (choice) {
        case 1:
            itemName = "Popcorn";
            break;
        case 2:
            itemName = "Candy";
            break;
        case 3:
            itemName = "Nachos";
            break;
        case 4:
            itemName = "Drink";
            break;
        default:
            itemName = "Unknown";
            break;
        }

        addToOrder(itemName, itemPrice, quantity, total);

        cout << "Do you want to continue ordering? (y/n): ";
        cin >> continueOrder;

    } while (continueOrder == 'y' || continueOrder == 'Y');

    // Output final total with tax
    double tax = total * TAX_RATE;
    double grandTotal = total + tax;

    cout << fixed << setprecision(2);
    cout << "\nOrder Summary: " << endl;
    cout << "Subtotal: $" << total << endl;
    cout << "Tax: $" << tax << endl;
    cout << "Grand Total: $" << grandTotal << endl;

    return 0;
}

void displayMenu() {
    cout << "\nSelect an item from the menu: " << endl;
    cout << "1 - Popcorn ............ $10.95" << endl;
    cout << "2 - Candy .............. $ 8.99" << endl;
    cout << "3 - Nachos ............. $ 7.95" << endl;
    cout << "4 - Drink .............. $ 6.69" << endl;
    cout << "5 - Exit" << endl;
    cout << "Enter your choice: ";
}

void displaySubMenu(int choice, double& price) {
    switch (choice) {
    case 1:
        cout << "Would you like butter on your popcorn? (y/n): ";
        char butter;
        cin >> butter;
        price = 10.95;
        if (butter == 'y' || butter == 'Y') {
            cout << "Butter added to popcorn." << endl;
            price += 0.50; // Additional charge for butter
        }
        break;
    case 2:
        cout << "What type of candy would you like?" << endl;
        cout << "1 - Chocolate, 2 - Gummies, 3 - Hard Candy: ";
        int candyType;
        cin >> candyType;
        price = 8.99;
        break;
    case 3:
        cout << "You selected Nachos." << endl;
        price = 7.95;
        break;
    case 4:
        cout << "What size drink? (1 - Small, 2 - Medium, 3 - Large): ";
        int size;
        cin >> size;
        if (size == 1) price = 6.69;
        else if (size == 2) price = 7.69;
        else price = 8.69;
        break;
    default:
        cout << "Invalid choice." << endl;
        break;
    }
}

void getQuantity(int& quantity) {
    cout << "How many would you like to order? ";
    cin >> quantity;
}

void addToOrder(const string& itemName, double price, int quantity, double& total) {
    double itemTotal = price * quantity;
    total += itemTotal;
    cout << "Added " << quantity << " " << itemName << "(s) to your order. Total so far: $" << total << endl;
}
