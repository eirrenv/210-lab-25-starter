#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
#include <algorithm> // vector sort :)
using namespace std;
using namespace std::chrono;

int main() {
    

    string codeToInsert;
    vector<string> data;
    vector<string> codeVector;
    list<string> codeList;
    set<string> codeSet;
    ifstream fin("codes.txt");
    while (fin >> codeToInsert) {
        data.push_back(codeToInsert);
    }
    // vector reading time
    auto start = high_resolution_clock::now();
    for (const auto &x : data) codeVector.push_back(x);
    auto end = high_resolution_clock::now();
    auto vectorSpeed = duration_cast<nanoseconds>(end - start);

    // list reading time
    start = high_resolution_clock::now();
    for (const auto &x : data) codeList.push_back(x);
    end = high_resolution_clock::now();
    auto listSpeed = duration_cast<nanoseconds>(end - start);

    // set reading time
    start = high_resolution_clock::now();
    for (const auto &x : data) codeSet.insert(x);
    end = high_resolution_clock::now();
    auto setSpeed = duration_cast<nanoseconds>(end - start);

    // test speed prints
    cout << "Reading Speed:" << endl;
    cout << "Vector speed: " << vectorSpeed.count() << " nanoseconds" << endl;
    cout << "List speed: " << listSpeed.count() << " nanoseconds" << endl;
    cout << "Set speed: " << setSpeed.count() << " nanoseconds" << endl;

    // vector sorting time
    start = high_resolution_clock::now();
    sort(codeVector.begin(), codeVector.end());
    end = high_resolution_clock::now();
    vectorSpeed = duration_cast<nanoseconds>(end - start);

    // list sorting time
    start = high_resolution_clock::now();
    codeList.sort();
    end = high_resolution_clock::now();
    listSpeed = duration_cast<nanoseconds>(end - start);

    // test sort prints, set already sorted
    cout << "Sorting speed:" << endl;
    cout << "Vector speed: " << vectorSpeed.count() << " nanoseconds" << endl;
    cout << "List speed: " << listSpeed.count() << " nanoseconds" << endl;
    cout << "Set speed: " << "-1" << " nanoseconds" << endl;

    codeToInsert = "TESTCODE";

    // vector inserting time
    start = high_resolution_clock::now();
    codeVector.insert(codeVector.begin() + data.size() / 2, codeToInsert);
    end = high_resolution_clock::now();
    vectorSpeed = duration_cast<nanoseconds>(end - start);

    // list inserting time
    start = high_resolution_clock::now();
    auto it = codeList.begin();
    advance(it, codeList.size() / 2);
    codeList.insert(it, codeToInsert);
    end = high_resolution_clock::now();
    listSpeed = duration_cast<nanoseconds>(end - start);

    // set inserting time
    start = high_resolution_clock::now();
    codeSet.insert(codeToInsert);
    end = high_resolution_clock::now();
    setSpeed = duration_cast<nanoseconds>(end - start);

    // test insert prints
    cout << "Inserting speed:" << endl;
    cout << "Vector speed: " << vectorSpeed.count() << " nanoseconds" << endl;
    cout << "List speed: " << listSpeed.count() << " nanoseconds" << endl;
    cout << "Set speed: " << setSpeed.count() << " nanoseconds" << endl;

    // vector deletion time
    start = high_resolution_clock::now();
    codeVector.erase(codeVector.begin() + codeVector.size() / 2);
    end = high_resolution_clock::now();
    vectorSpeed = duration_cast<nanoseconds>(end - start);
    
    // list deletion time
    start = high_resolution_clock::now();
    it = codeList.begin();
    advance(it, codeList.size() / 2);
    codeList.erase(it);
    end = high_resolution_clock::now();
    listSpeed = duration_cast<nanoseconds>(end - start);

    // set deletion time
    start = high_resolution_clock::now();
    codeSet.erase(codeToInsert);
    end = high_resolution_clock::now();
    setSpeed = duration_cast<nanoseconds>(end - start);

    // test deletion prints
    cout << "Deletion speed:" << endl;
    cout << "Vector speed: " << vectorSpeed.count() << " nanoseconds" << endl;
    cout << "List speed: " << listSpeed.count() << " nanoseconds" << endl;
    cout << "Set speed: " << setSpeed.count() << " nanoseconds" << endl;

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<nanoseconds>(end - start)
duration.count() references elapsed nanoseconds
*/