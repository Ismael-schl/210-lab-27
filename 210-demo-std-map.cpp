//Lab 27 | COMSC 210 | Ismael Hadi
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerColors;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerColors["Audie"] = {6, "Beetle", "Gotta go fast!"};
    villagerColors["Raymond"] = {7, "Hedgehog", "Nice shot!"};
    villagerColors.insert({"Marshal", {2, "Lizard", "Misson failed."}});

    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagerColors) {
        cout << pair.first << ": ";
        cout << get<0>(pair.second) << ", " << get<1>(pair.second) << ", " << get<2>(pair.second) << endl;
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their species/catchphrases (iterators):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagerColors.begin(); 
                                               it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        cout << get<0>(it->second) << ", " << get<1>(it->second) << ", " << get<2>(it->second);
        cout << endl;
    }

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s species and catchphrase: ";
        cout << get<1>(it->second) << ", " << get<2>(it->second); // range loop to traverse the value/vector
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}
