#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Product {
public:
    int id;
    std::string name;
    int quantity;
    double price;

    Product() = default;

    Product(int id, std::string name, int quantity, double price)
        : id(id), name(name), quantity(quantity), price(price) {}
    
    void display() const {
        std::cout << "ID: " << id << ", Name: " << name 
                  << ", Quantity: " << quantity << ", Price: " << price << std::endl;
    }
};
void saveToFile(const std::vector<Product>& inventory) {
    std::ofstream file("inventory.txt");
    for (const auto& product : inventory) {
        file << product.id << ' ' << product.name << ' ' 
             << product.quantity << ' ' << product.price << '\n';
    }
}

std::vector<Product> loadFromFile() {
    std::vector<Product> inventory;
    std::ifstream file("inventory.txt");
    int id, quantity;
    double price;
    std::string name;
    while (file >> id >> name >> quantity >> price) {
        inventory.emplace_back(id, name, quantity, price);
    }
    return inventory;
}
void addProduct(std::vector<Product>& inventory) {
    int id, quantity;
    double price;
    std::string name;
    std::cout << "Enter product ID, name, quantity, and price: ";
    std::cin >> id >> name >> quantity >> price;
    inventory.emplace_back(id, name, quantity, price);
    saveToFile(inventory);
}

void updateProduct(std::vector<Product>& inventory) {
    int id;
    std::cout << "Enter product ID to update: ";
    std::cin >> id;
    for (auto& product : inventory) {
        if (product.id == id) {
            std::cout << "Enter new name, quantity, and price: ";
            std::cin >> product.name >> product.quantity >> product.price;
            saveToFile(inventory);
            return;
        }
    }
    std::cout << "Product not found.\n";
}

void deleteProduct(std::vector<Product>& inventory) {
    int id;
    std::cout << "Enter product ID to delete: ";
    std::cin >> id;
    inventory.erase(std::remove_if(inventory.begin(), inventory.end(),
                                   [id](const Product& p) { return p.id == id; }),
                    inventory.end());
    saveToFile(inventory);
}

void displayInventory(const std::vector<Product>& inventory) {
    for (const auto& product : inventory) {
        product.display();
    }
}
void displayMenu() {
    std::cout << "1. Add Product\n"
              << "2. Update Product\n"
              << "3. Delete Product\n"
              << "4. Display Inventory\n"
              << "5. Exit\n";
}

int main() {
    std::vector<Product> inventory = loadFromFile();
    int choice;
    while (true) {
        displayMenu();
        std::cin >> choice;
        switch (choice) {
            case 1: addProduct(inventory); break;
            case 2: updateProduct(inventory); break;
            case 3: deleteProduct(inventory); break;
            case 4: displayInventory(inventory); break;
            case 5: return 0;
            default: std::cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}

