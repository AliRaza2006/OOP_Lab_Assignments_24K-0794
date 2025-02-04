#include<iostream>
#include<string>
using namespace std;

typedef struct {
    int id;
    string name;
} Person;

void input(Person* p, int* count, int len) {
    if (*count == len) {
        cout << "Max limit reached!" << endl << endl;
    } else {
        cout << "Enter Id: ";
        cin >> p[*count].id;
        cout << "Enter name: ";
        getchar();  
        getline(cin, p[*count].name);
        cout << endl;
        (*count)++;
    }
}

void sort(Person* p, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (p[j].id < p[j + 1].id) {
                Person temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
        if (p[i].id == p[i + 1].id && p[i].name > p[i + 1].name) {
            Person temp = p[i];
            p[i] = p[i + 1];
            p[i + 1] = temp;
        }
    }
    }
}

int main() {
    int size, count = 0;
    cout << "Enter the size of structure: ";
    cin >> size;
    Person per[size];
    int choice;

    while (1) {
        cout << "Choose from the following options: " << endl
             << "1. Add a record" << endl
             << "2. Sort Data" << endl
             << "Press another key to exit" << endl
             << "Choice: ";
        cin >> choice;
        while (getchar() != '\n');
        cout << endl;

        switch (choice) {
            case 1:
                input(per, &count, size);
                break;

            case 2:
                if (count < 2) {
                    cout << "There is only one record and the data is already sorted." << endl << endl; 
                } else {
                    sort(per, count);
                    cout << "Sorted!" << endl;
                    for (int i = 0; i < count; i++) {
                        cout << "ID: " << per[i].id << endl;
                        cout << "Name: " << per[i].name << endl << endl;
                    }
                }
                break;

            default:
                cout << "Exiting program......." << endl;
                exit(0);
        }
    }
}
