#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
using namespace std;
using namespace std::chrono;

int main() {
    auto start = high_resolution_clock::now();

    string codeToInsert;
    vector<string> codeVector;
    list<string> codeList;
    set<string> codeSet;
    ifstream fin("codes.txt");
    while (fin >> codeToInsert) {
        codeVector.push_back(codeToInsert);
        codeList.push_back(codeToInsert);
        codeSet.insert(codeToInsert);
    }
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(end - start);

    cout << "Time taken: " << duration.count() << " nanoseconds" << endl;

    


    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/