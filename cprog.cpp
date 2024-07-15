#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Product {
    int id;
    string name;
    int quantity;
    double price;
};

vector<Product> inventory;

void loadInventory() {
    ifstream file("inventory.txt");
    if (file.is_open()) {
        Product product;
        while (file >> product.id >> product.name >> product.quantity >> product.price) {
            inventory.push_back(product);
        }
        file.close();
    }
}

void saveInventory() {
    ofstream file("inventory.txt");
    if (file.is_open()) {
        for (const auto& product : inventory) {
            file << product.id << " " << product.name << " " << product.quantity << " " << product.price << endl;
        }
        file.close();
    }
}

void addProduct() {
    Product product;
    cout << "Enter product ID: ";
    cin >> product.id;
    cout << "Enter product name: ";
    cin >> product.name;
    cout << "Enter product quantity: ";
    cin >> product.quantity;
    cout << "Enter product price: ";
    cin >> product.price;
    inventory.push_back(product);
    saveInventory();
    cout << "Product added successfully!" << endl;
}

void deleteProduct() {
    int id;
    cout << "Enter product ID to delete: ";
    cin >> id;
    auto it = remove_if(inventory.begin(), inventory.end(), [id](const Product& product) { return product.id == id; });
    if (it != inventory.end()) {
        inventory.erase(it, inventory.end());
        saveInventory();
        cout << "Product deleted successfully!" << endl;
    } else {
        cout << "Product not found!" << endl;
    }
}

void updateProductQuantity() {
    int id, quantity;
    cout << "Enter product ID to update: ";
    cin >> id;
    cout << "Enter new quantity: ";
    cin >> quantity;
    for (auto& product : inventory) {
        if (product.id == id) {
            product.quantity = quantity;
            saveInventory();
            cout << "Product quantity updated successfully!" << endl;
            return;
        }
    }
    cout << "Product not found!" << endl;
}

void viewAllProducts() {
    cout << "ID\tName\tQuantity\tPrice" << endl;
    for (const auto& product : inventory) {
        cout << product.id << "\t" << product.name << "\t" << product.quantity << "\t" << product.price << endl;
    }
}

void generateReports() {
    int totalProducts = 0;
    double totalValue = 0.0;
    for (const auto& product : inventory) {
        totalProducts += product.quantity;
        totalValue += product.quantity * product.price;
    }
    cout << "Total number of products: " << totalProducts << endl;
    cout << "Total inventory value: $" << totalValue << endl;
}

int main() {
    loadInventory();
    int choice;
    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add Product\n";
        cout << "2. Delete Product\n";
        cout << "3. Update Product Quantity\n";
        cout << "4. View All Products\n";
        cout << "5. Generate Reports\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addProduct(); break;
            case 2: deleteProduct(); break;
            case 3: updateProductQuantity(); break;
            case 4: viewAllProducts(); break;
            case 5: generateReports(); break;
            case 6: saveInventory(); cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}


