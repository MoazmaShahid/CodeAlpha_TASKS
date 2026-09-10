#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isUsernameTaken(string username) {
    ifstream file("users.txt");
    string storedUser, storedPass;

    while (file >> storedUser >> storedPass) {
        if (storedUser == username) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void registerUser() {
    string username, password;

    cout << "Enter a username: ";
    cin >> username;

    if (username.length() < 3) {
        cout << "Username too short! Must be at least 3 characters.\n";
        return;
    }

    if (isUsernameTaken(username)) {
        cout << "Sorry, this username is already taken.\n";
        return;
    }

    cout << "Enter a password: ";
    cin >> password;

    if (password.length() < 4) {
        cout << "Password too short! Must be at least 4 characters.\n";
        return;
    }

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful! You can now log in.\n";
}

void loginUser() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string storedUser, storedPass;
    bool found = false;

    while (file >> storedUser >> storedPass) {
        if (storedUser == username && storedPass == password) {
            found = true;
            break;
        }
    }
    file.close();

    if (found) {
        cout << "Login successful! Welcome, " << username << ".\n";
    } else {
        cout << "Invalid username or password.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            registerUser();
        } else if (choice == 2) {
            loginUser();
        } else if (choice == 3) {
            cout << "Goodbye!\n";
        } else {
            cout << "Invalid choice, try again.\n";
        }

    } while (choice != 3);

    return 0;
}