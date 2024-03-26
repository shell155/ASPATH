#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <map>
using namespace std;
vector<string> split(const string &, const char);
bool compare( const pair<string, set<string>>&,  const pair<string, set<string>> &);

int main() {
    string line;
    map<string,set<string>> map;
    while(getline(cin,line)) {
        vector<string> aspath = split(line, ' ');
        for (int i = 0; i < aspath.size(); i++) {
            if(i+1 < aspath.size()){
                map[aspath[i]].insert(aspath[i+1]);
            }
            if(i > 0){
                map[aspath[i]].insert(aspath[i-1]);
            }
        }
    }

    vector<pair<string,set<string>>> vect(map.begin(),map.end());
    sort(vect.begin(),vect.end(),compare);
    int k = 0;
    for(auto pairs: vect)
    {
        cout << pairs.first << ":" << pairs.second.size()<< endl;
        k++;
        if(k == 10)
            break;
    }
    return 0;
}

//Split function from examples/r2
vector<string> split(const string &s, const char c) {
    string field;
    vector<string> vs;
    istringstream ss(s);
    while (getline(ss, field, c)) {
        vs.push_back(field);
    }

    return vs;
}

bool compare( const pair<string, set<string>> &a,  const pair<string, set<string>> &b) {
    if(a.second.size() == b.second.size())
        return stoi(a.first) > stoi(b.first);

    return a.second.size() > b.second.size();
}
