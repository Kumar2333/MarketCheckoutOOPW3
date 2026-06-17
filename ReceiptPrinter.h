#ifndef RECEIPTPRINTER_H
#define RECEIPTPRINTER_H

#include <iostream>
#include "Cart.h"
#include "Catalog.h"
#include "Pricing.h"

using namespace std;

// Prints the final receipt
class ReceiptPrinter
{
public:
    void printReceipt(Cart cart, Catalog& catalog, Pricing& pricing)
    {
        vector<CartItem> items = cart.getItems();

        cout << "----- MARKET RECEIPT -----" << endl;

        for (int i = 0; i < items.size(); i++)
        {
            Product* product = catalog.findProduct(items[i].productId);

            if (product != nullptr)
            {
                cout << product->getName()
                     << " x " << items[i].quantity
                     << " = RM "
                     << product->getPrice() * items[i].quantity
                     << endl;
            }
        }

        double subtotal = pricing.computeSubtotal(cart, catalog);
        double discount = pricing.computeDiscount(subtotal);
        double tax = pricing.computeTax(subtotal - discount);
        double total = pricing.computeTotal(subtotal);

        cout << "--------------------------" << endl;
        cout << "Subtotal: RM " << subtotal << endl;
        cout << "Discount: RM " << discount << endl;
        cout << "Tax: RM " << tax << endl;
        cout << "Total: RM " << total << endl;
    }
};

#endif
