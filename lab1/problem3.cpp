#include <iostream>
using namespace std;

void checkOrder(int orderQuantity, int storeQuantity) {
    if (orderQuantity > storeQuantity) {
        cout << "Not enough quantity" << endl;
    } else {
        if (storeQuantity >= 40 || orderQuantity <= 16) {
            cout << "Your order is accepted" << endl;
        } else {
            cout << "You cannot order more than 16 items" << endl;
        }
    }
}

int main() {
    int orderQuantity, storeQuantity;
    cout << "Enter the medicine quantity in store: ";
    cin >> storeQuantity;
    cout << "Enter the order quantity: ";
    cin >> orderQuantity;
    checkOrder(orderQuantity, storeQuantity);

    return 0;
}
