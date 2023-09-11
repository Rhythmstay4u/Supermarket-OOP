#include <iostream>
#include <vector>
#include <string>

class Item {
public:
    std::string name;
    double price;

    Item(std::string name, double price) : name(name), price(price) {}

    std::string getName() {
        return name;
    }

    double getPrice() {
        return price;
    }
};

class GroceryItem : public Item {
public:
    GroceryItem(std::string name, double price) : Item(name, price) {}
};

class ElectronicItem : public Item {
public:
    ElectronicItem(std::string name, double price) : Item(name, price) {}
};

class HealthCareItem : public Item {
public:
    HealthCareItem(std::string name, double price) : Item(name, price) {}
};

class HouseholdItem : public Item {
public:
    HouseholdItem(std::string name, double price) : Item(name, price) {}
};

class ShoppingCart {
public:
    std::vector<Item*> items;

    void addItem(Item* item) {
        items.push_back(item);
    }

    void removeItem(Item* item) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if ((*it)->getName() == item->getName()) {
                items.erase(it);
                break;
            }
        }
    }

    double calculateTotal() {
        double total = 0.0;
        for (Item* item : items) {
            total += item->getPrice();
        }
        return total;
    }

    void displayCart() {
        std::cout << "Shopping Cart:" << std::endl;
        for (Item* item : items) {
            std::cout << item->getName() << " - Rs." << item->getPrice() << std::endl;
        }
    }
};

int main() {
    ShoppingCart cart;

    while (true) {
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Add item to cart" << std::endl;
        std::cout << "2. Remove item from cart" << std::endl;
        std::cout << "3. View cart" << std::endl;
        std::cout << "4. Checkout" << std::endl;
        std::cout << "5. Exit" << std::endl;

        int option;
        std::cin >> option;
        std::cin.ignore(); // Consume the newline character

        switch (option) {
            case 1: {
                std::cout << "Enter item name:" << std::endl;
                std::string itemName;
                std::getline(std::cin, itemName);
                std::cout << "Enter item price:" << std::endl;
                double itemPrice;
                std::cin >> itemPrice;
                std::cin.ignore();
                std::cout << "Enter item category (1. Grocery, 2. Electronics, 3. HealthCare, 4. Household):" << std::endl;
                int categoryChoice;
                std::cin >> categoryChoice;
                std::cin.ignore();
                Item* newItem;
                if (categoryChoice == 1) {
                    newItem = new GroceryItem(itemName, itemPrice);
                } else if (categoryChoice == 2) {
                    newItem = new ElectronicItem(itemName, itemPrice);
                } else if (categoryChoice == 3) {
                    newItem = new HealthCareItem(itemName, itemPrice);
                } else if (categoryChoice == 4) {
                    newItem = new HouseholdItem(itemName, itemPrice);
                } else {
                    std::cout << "Invalid category choice" << std::endl;
                    continue;
                }
                cart.addItem(newItem);
                std::cout << itemName << " has been added to the cart." << std::endl;
                break;
            }
            case 2: {
                std::cout << "Enter the name of the item to remove:" << std::endl;
                std::string itemToRemove;
                std::getline(std::cin, itemToRemove);
                for (auto it = cart.items.begin(); it != cart.items.end(); ++it) {
                    if ((*it)->getName() == itemToRemove) {
                        cart.removeItem(*it);
                        delete *it; // Free the memory allocated for the removed item
                        std::cout << itemToRemove << " has been removed from the cart." << std::endl;
                        break;
                    }
                }
                break;
            }
            case 3:
                cart.displayCart();
                break;
            case 4: {
                double total = cart.calculateTotal();
                std::cout << "Total: Rs." << total << std::endl;
                break;
            }
            case 5:
                std::cout << "Thank you for shopping with us!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
