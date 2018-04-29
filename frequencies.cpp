#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {

    map<int, int> charmap;
    map<int,int>::iterator it = charmap.begin();
    for(string line; getline(cin, line) && line.compare("");) {
        for(int i = 0; i < line.length(); i++) {
            char temp = line[i];
            if(charmap.count(line[i])==0) {
                charmap.insert(pair<int,int>(line[i],1));
            } else {
                it = charmap.find(line[i]);
                it->second += 1;
            }

        }
	
	if(charmap.count('\n')==0) {
	  charmap.insert(pair<int,int>('\n',1));
	} else {
	  it = charmap.find('\n');
	  it->second += 1;
	}


    }
   for (it=charmap.begin(); it!=charmap.end(); ++it) {
       cout << it->first << "     " << it->second <<endl;
   }
    return 0;
}

// bool checkChar(int word,vector<character> charvec) {
//     for (int i = 0; i < charvec.size(); i++) {
//         if (charvec[i].entry == word)
//             return false;
//     }
//     return true;
// }
//
// int getIndex(int word,vector<character> charvec) {
//     for (int i = 0; i < charvec.size(); i++) {
//         if (charvec[i].entry == word)
//             return i;
//     }
//     return 45;
// }
