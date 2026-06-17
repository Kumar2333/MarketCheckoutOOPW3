#ifndef CATALOG_H
#define CATALOG_H

#include <vector>
#include "Product.h"

using namespace std;

// Manages the product list
class Catalog
{
private:
    vector<Product> products;

public:
    void loadProducts()
    {
        products.push_back(Product(1, "Apple", 0.50));
        products.push_back(Product(2, "Bread", 1.50));
        products.push_back(Product(3, "Milk", 2.00));
        products.push_back(Product(4, "Chocolate", 1.00));
    }

    Product* findProduct(int id)
    {
        for (int i = 0; i < products.size(); i++)
        {
            if (products[i].getId() == id)
            {
                return &products[i];
            }
        }

        return nullptr;
    }
};

#endif
