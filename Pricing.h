#ifndef PRICING_H
#define PRICING_H

#include "Cart.h"
#include "Catalog.h"

// Handles pricing calculations
class Pricing
{
public:

    double computeSubtotal(Cart cart, Catalog& catalog)
    {
        double subtotal = 0;

        vector<CartItem> items = cart.getItems();

        for (int i = 0; i < items.size(); i++)
        {
            Product* product = catalog.findProduct(items[i].productId);

            if (product != nullptr)
            {
                subtotal += product->getPrice() * items[i].quantity;
            }
        }

        return subtotal;
    }

    double computeDiscount(double subtotal)
    {
        if (subtotal > 10)
        {
            return subtotal * 0.10;
        }

        return 0;
    }

    double computeTax(double amount)
    {
        return amount * 0.06;
    }

    double computeTotal(double subtotal)
    {
        double discount = computeDiscount(subtotal);
        double taxableAmount = subtotal - discount;
        double tax = computeTax(taxableAmount);

        return taxableAmount + tax;
    }
};

#endif
