//Lab 27 | COMSC 210 | Ismael Hadi
#include <iostream>
#include <map>
#include <vector>
using namespace std;


int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerMap;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerMap["Audie"] = {6, "Beetle", "Gotta go fast!"};
    villagerMap["Raymond"] = {7, "Hedgehog", "Nice shot!"};
    villagerMap.insert({"Marshal", {2, "Lizard", "Misson failed."}});

    // access the map using a range-based for loop
    cout << "Villagers and their friendship level, species, and catchphrase (range-based for loop):" << endl;
    for (auto pair : villagerMap) {
        cout << pair.first << ": ";
        cout << get<0>(pair.second) << ", " << get<1>(pair.second) << ", " << get<2>(pair.second) << endl;
        cout << endl;
    }

  

    // delete an element
    cout << "Now deleting a villager... ";
    villagerMap.erase("Raymond");
    cout << "New map: " << endl;
    
      // access the map using iterators
    cout << "\nVillagers and their species/catchphrases (iterators):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagerMap.begin(); 
                                               it != villagerMap.end(); ++it) {
        cout << it->first << ": ";
        cout << get<0>(it->second) << ", " << get<1>(it->second) << ", " << get<2>(it->second);
        cout << endl;
    }

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerMap.find(searchKey);
    if (it != villagerMap.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s species and catchphrase: ";
        cout << get<1>(it->second) << ", " << get<2>(it->second); // range loop to traverse the value/vector
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerMap.size() << endl;
    villagerMap.clear();
    cout << "Size after clear: " << villagerMap.size() << endl;

    return 0;
}
