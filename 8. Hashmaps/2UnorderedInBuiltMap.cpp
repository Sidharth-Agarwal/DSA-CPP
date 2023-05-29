#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
    // Creating
    // Inserting directly into the map
    unordered_map<string, int> map = {{"Hiii",10}};
    
    // Insertion
    // 1
    pair<string, int> p("Hello", 1);
    map.insert(p);
    
    // 2
    pair<string, int> p2("hi", 5);
    map.insert(p2);

    // 3
    map["hey"] = 3;
    map["hey"] = 4; // Value against the string "hey" is updated

    // Find or Access
    // 1 Using directly the key
    // This creates a (key,0) pair if the key is not already present
    cout << map["Hiee"] << endl;

    // 2 Using at() function
    // This gives error if the (key,value) pair is not already present
    cout << map.at("Hello") << endl;

    // Size of the map
    cout << "Size : " << map.size() << endl;

    // Count - checks the presence of the particular key
    // If the key is present it return 1
    // Else 0
    cout << map.count("hey") << endl;

    // Erase a key
    map.erase("Hiee");
    cout << "Size : " << map.size() << endl;
    cout << endl;

    // Traversing the map using iterator
    unordered_map<string, int>::iterator it = map.begin();
    while(it != map.end())
    {
        cout << "First : " << it->first << " Second : " << it->second << endl;
        it++;
    }

    // Travering the map using for loop
    for(auto i:map)
    {
        cout << "First : " << i.first << " Second : " << i.second << endl;
    }
    cout << endl;

    // Find
    string key = "Hiii";
    cout << "Finding Key : ";
    if(map.find(key) != map.end())
    {
        cout << key << endl;
    }
}