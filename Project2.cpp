#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class User {
public:
    std::string username;
    std::vector<std::string> friends;
    std::vector<std::string> posts;

    void createProfile(const std::string& username) {
        this->username = username;
    }

    bool addFriend(const std::string& friend_username) {
        for (const std::string& friend : friends) {
            if (friend == friend_username) {
                return false; // Friend already exists
            }
        }
        friends.push_back(friend_username);
        return true; // Friend added successfully
    }

    void postMessage(const std::string& message) {
        posts.push_back(message);
    }

    // Methods for saving and loading user data to/from a file (using fstream)
};

class SocialNetwork {
private:
    std::vector<User> users;
    std::string dataFile;  // Path to the data file

public:
    SocialNetwork(const std::string& dataFile) : dataFile(dataFile) {
        // Load user data from file during initialization (optional)
        loadUsersFromFile();
    }

    User* registerUser(const std::string& username) {
        for (User& user : users) {
            if (user.username == username) {
                return nullptr; // Username already exists
            }
        }
        User newUser;
        newUser.createProfile(username);
        users.push_back(newUser);
        saveUsersToFile(); // Update data file
        return &users.back();
    }

    User* loginUser(const std::string& username) {
        for (User& user : users) {
            if (user.username == username) {
                return &user;
            }
        }
        return nullptr; // User not found
    }

    bool addFriend(const std::string& current_user, const std::string& friend_username) {
        User* user = findUser(current_user);
        if (user) {
            return user->addFriend(friend_username);
        }
        return false; // User not found
    }

    // Methods for saving and loading user data to/from a file (using fstream)
};

int main() {
    SocialNetwork socialNetwork("users.dat");  // Set data file path

    int choice, user_id;
    std::string username, friend_username, message;
    User* currentUser = nullptr;

    while (true) {
        std::cout << "\nSimple Social Network\n";
        if (!currentUser) {
            std::cout << "1. Register\n";
            std::cout << "2. Login\n";
            std::cout << "3. Exit\n";
        } else {
            std::cout << "Welcome, " << currentUser->username << "!\n";
            std::cout << "1. View Profile\n";
            std::cout << "2. Add Friend\n";
            std::cout << "3. Post Message\n";
            std::cout << "4. Logout\n";
            std::cout << "5. Exit\n";
        }
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: // Register
                std::cout << "Enter username: ";
                std::cin >> username;
                currentUser = socialNetwork.registerUser(username);
                break;
            // ... (implement other functionalities)
        }
    }

    return 0;
}
