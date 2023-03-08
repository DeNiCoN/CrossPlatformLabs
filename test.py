#!/usr/bin/env python3


import mymodule

# Add some products to the vector
mymodule.add_product("Apple", 10, 1.99)
mymodule.add_product("Orange", 5, 2.49)

for product in mymodule.get_products():
    print(product.name(), product.quantity(), product.price())

apple = mymodule.find_product("Apple")
apple.set_quantity(15)

for product in mymodule.get_products():
    print(product.name(), product.quantity(), product.price())

mymodule.remove_product("Orange")

for product in mymodule.get_products():
    print(product.name(), product.quantity(), product.price())
