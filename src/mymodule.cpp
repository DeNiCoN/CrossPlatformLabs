#include <boost/python.hpp>

#include <algorithm>
#include <boost/python.hpp>
#include <string>
#include <vector>

using namespace boost::python;

class Product {
public:
  Product(const std::string &name, int quantity, double price)
      : name_(name), quantity_(quantity), price_(price) {}

  std::string name() const { return name_; }
  int quantity() const { return quantity_; }
  double price() const { return price_; }

  void set_name(const std::string &name) { name_ = name; }
  void set_quantity(int quantity) { quantity_ = quantity; }
  void set_price(double price) { price_ = price; }

private:
  std::string name_;
  int quantity_;
  double price_;
};

std::vector<Product> products;

void add_product(const std::string &name, int quantity, double price) {
  products.emplace_back(name, quantity, price);
}

Product *find_product(const std::string &name) {
  auto it = std::find_if(
      products.begin(), products.end(),
      [&](const Product &product) { return product.name() == name; });
  return it != products.end() ? &(*it) : nullptr;
}

void update_product(Product *product, int quantity, double price) {
  if (product) {
    product->set_quantity(quantity);
    product->set_price(price);
  }
}

void remove_product(const std::string &name) {
  auto it = std::remove_if(
      products.begin(), products.end(),
      [&](const Product &product) { return product.name() == name; });
  products.erase(it, products.end());
}

list get_products() {
  list result;
  for (const auto &product : products) {
    result.append(product);
  }
  return result;
}

BOOST_PYTHON_MODULE(mymodule) {
  class_<Product>("Product", init<const std::string &, int, double>())
      .def("name", &Product::name)
      .def("quantity", &Product::quantity)
      .def("price", &Product::price)
      .def("set_name", &Product::set_name)
      .def("set_quantity", &Product::set_quantity)
      .def("set_price", &Product::set_price);

  def("add_product", &add_product);
  def("find_product", &find_product, return_internal_reference<>());
  def("update_product", &update_product);
  def("remove_product", &remove_product);
  def("get_products", &get_products);
}
