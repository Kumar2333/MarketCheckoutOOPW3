#ifndef CART_H
#define CART_H

#include <vector>
using namespace std;

// Stores product id and quantity in cart
struct CartItem
{
    int productId;
    int quantity;
};

// Manages the shopping cart
class Cart
{
private:
    vector<CartItem> items;

public:
    void addItem(int productId, int quantity)
    {
        CartItem newItem;
        newItem.productId = productId;
        newItem.quantity = quantity;

        items.push_back(newItem);
    }

    void removeItem(int productId)
    {
        for (int i = 0; i < items.size(); i++)
        {
            if (items[i].productId == productId)
            {
                items.erase(items.begin() + i);
                break;
            }
        }
    }

    vector<CartItem> getItems()
    {
        return items;
    }
};

#endif
