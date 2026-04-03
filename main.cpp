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
    auto vectorSpeed = duration_cast<milliseconds>(end - start);

    // list reading time
    start = high_resolution_clock::now();
    for (const auto &x : data) codeList.push_back(x);
    end = high_resolution_clock::now();
    auto listSpeed = duration_cast<milliseconds>(end - start);

    // set reading time
    start = high_resolution_clock::now();
    for (const auto &x : data) codeSet.insert(x);
    end = high_resolution_clock::now();
    auto setSpeed = duration_cast<milliseconds>(end - start);

    // test speed prints
    cout << "Reading Speed:" << endl;
    cout << "Vector speed: " << vectorSpeed.count() << " milliseconds" << endl;
    cout << "List speed: " << listSpeed.count() << " milliseconds" << endl;
    cout << "Set speed: " << setSpeed.count() << " milliseconds" << endl;

    // vector sorting time
    start = high_resolution_clock::now();
    sort(codeVector.begin(), codeVector.end());
    end = high_resolution_clock::now();
    vectorSpeed = duration_cast<milliseconds>(end - start);

    // list sorting time
    start = high_resolution_clock::now();
    codeList.sort();
    end = high_resolution_clock::now();
    listSpeed = duration_cast<milliseconds>(end - start);

    // test sort prints, set already sorted
    cout << "Sorting speed:" << endl;
    cout << "Vector speed: " << vectorSpeed.count() << " milliseconds" << endl;
    cout << "List speed: " << listSpeed.count() << " milliseconds" << endl;
    cout << "Set speed: " << "-1" << " milliseconds" << endl;

    


    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/