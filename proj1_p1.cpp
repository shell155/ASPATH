#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    
    string line;
    while (getline(cin, line)) {
        int counter = 0;
        
        vector<string> extractedValues;

        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '|') {
                counter++;
            }

            if (counter == 6) {
                if (line[i] == '|') {
                    i++;
                }
                int start = i;

                while (i < line.size() && line[i] != '|' && line[i] != '[') {
                    i++;
                }

                int end = i;
                string extracted = line.substr(start, end - start);

                istringstream iss(extracted);
                string numbers;

                while (getline(iss, numbers, ' ')) {
                    bool isDuplicate = false;
                    for (int i = 0; i < extractedValues.size();i++) {
                        if (extractedValues[i] == numbers) {
                            isDuplicate = true;
                            break;
                        }
                    }

                    if (!isDuplicate) {
                        extractedValues.push_back(numbers);
                    }
                }

                counter++;
            }
        }

        for (int i = 0; i < extractedValues.size();i++) {
            cout << extractedValues[i] << ' ';
        }

        cout << endl;
    }

    return 0;
}

