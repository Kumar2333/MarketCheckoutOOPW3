#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

// Stores information about a product
class Product
{
private:
    int id;
    string name;
    double price;

public:
    Product(int productId, string productName, double productPrice)
    {
        id = productId;
        name = productName;
        price = productPrice;
    }

    int getId()
    {
        return id;
    }

    string getName()
    {
        return name;
    }

    double getPrice()
    {
        return price;
    }
};

#endif
