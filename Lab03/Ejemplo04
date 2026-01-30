#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char texto[] = "Juan,Pedro,Ana";

    char* token = strtok(texto, ",");

    while (token != nullptr) {
        cout << token << endl;
        token = strtok(nullptr, ",");
    }
}
