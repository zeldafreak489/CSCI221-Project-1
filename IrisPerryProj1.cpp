 // Author: Iris Perry
 // Version: 06-11-2023


#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

void reverse(char* front, char* rear);
// Precondition: front and rear are pointing to the front
//               and rear of a C-string, respectively
// Postcondition: The C-string is reversed

string* addEntry(string* dynamiccArray, int& size, string newEntry);
// Precondition: dynamicArray points to a array of strings with given size,
//               newEntry is a string
// Postcondition: A new dynamic array is created, which is one larger than
//                dynamicArray. All elements from dynamicArray are copied to
//                new array, the new entry is added to new array, the size
//                is increased, the dynamicArray is deleted, and the new dynamic
//                array is returned.

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete);
// Precondition: dynamicArray points to a array of strings with given size,
//               newEntry is a string
// Postcondition: The function should search dynamicArray for entryToDelete.
//                If not found, the request should be ignored and the
//                unmodified dynamicArray returned. If found, create a new
//                dynamic array one element smaller than dynamicArray. Copy
//                all element except entryToDelete into the new array, delete
//                dynamicArray, decrement size, and return the new dynamic
//                array

void print(const string* dynamicArray, int size);
// Precondition: dynamicArray points to a array of strings with given size
// Postcondition: The elements in dynamicArray will be print out. One
//                element per line followed by its index

int main() {
    // code to test reverse function
    char* front, * rear, str[100];

    // get string from user
    cout << "Please input a string under 100 characters. Press Enter when complete: \n";
    cin.getline(str, 100);
    // repeat string back to user
    cout << "Your input: " << str << endl;

    // set front to beginning of string and rear to end of string
    front = str;
    rear = str + strlen(str);

    // call reverse function to reverse string
    reverse(front, rear);

    // display reversed string
    cout << "The reverse of the string you entered is: " << str << endl;
    cout << endl;


    // code to test add entry and delete entry function
    int size = 5;
    string* names = new string[size];
    names[0] = "Zelda";
    names[1] = "Link";
    names[2] = "Rauru";
    names[3] = "Sonia";
    names[4] = "Purah";

    cout << "Initial List:" << endl;
    print(names, size);

    // Add names to names
    names = addEntry(names, size, "Impa");
    names = addEntry(names, size, "Robbie");
    cout << "After adding names:" << endl;
    print(names, size);

    // Delete some names from names
    names = deleteEntry(names, size, "Rauru");
    names = deleteEntry(names, size, "Josha"); // Name not in list
    names = deleteEntry(names, size, "Robbie");
    cout << "After deleting names:" << endl;
    print(names, size);

    // Delete array
    delete[] names;

    return 0;
}

void reverse(char* front, char* rear) {
    while (front < rear) {
        --rear;
        char temp = *front;
        *front = *rear;
        *rear = temp;
        ++front;
    }
}

string* addEntry(string* dynamicArray, int& size, string newEntry) {
    string* newArray = new string[size + 1];
    for (int i = 0; i < size; i++) {
        newArray[i] = dynamicArray[i];
    }
    newArray[size] = newEntry;
    size++;
    delete[] dynamicArray;
    return newArray;
}

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete) {
    string* result = dynamicArray;
    int indexOfEntryToDelete = -1;
    for (int i = 0; i < size; i++) {
        if (dynamicArray[i] == entryToDelete) {
            indexOfEntryToDelete = i;
            break;
        }
    }
    if (indexOfEntryToDelete == -1) {
        return result;
    }
    else {
        result = new string[size - 1];
        int indexNewArray = 0;
        for (int i = 0; i < size; i++) {
            if (i != indexOfEntryToDelete) {
                result[indexNewArray] = dynamicArray[i];
                indexNewArray++;
            }
            else {
                // i == indexOfEntryToDelete
            }
        }
        size--;
        delete[] dynamicArray;
    }
    return result;
}

void print(const string* dynamicArray, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Name: " << dynamicArray[i] << " Index: " << i << endl;
    }
    cout << endl;
}