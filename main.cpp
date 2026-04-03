#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
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

    cout << "Vector speed: " << vectorSpeed.count() << " nanoseconds" << endl;
    cout << "List speed: " << listSpeed.count() << " nanoseconds" << endl;
    cout << "Set speed: " << setSpeed.count() << " nanoseconds" << endl;

    


    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/