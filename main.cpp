#include "Product.h"
#include "Catalog.h"
#include "Cart.h"
#include "Pricing.h"
#include "ReceiptPrinter.h"

int main()
{
    Catalog catalog;
    catalog.loadProducts();

    Cart cart;
    cart.addItem(1, 2); // Apple
    cart.addItem(2, 1); // Bread
    cart.addItem(4, 3); // Chocolate

    Pricing pricing;
    ReceiptPrinter receipt;

    receipt.printReceipt(cart, catalog, pricing);

    return 0;
}
