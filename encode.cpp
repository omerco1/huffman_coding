#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
  map<int, string> the_code;
  map<int,string>::iterator it = the_code.begin();
  string word;
  int ascii;
  fstream in;
  in.open(argv[1]);

  //IF YOU INCORRECTLY ENTERED THE FILE NAME TO ARGV[] I WILL OPEN IT MANUALLY
  if (!in.is_open()) {
    in.open("codewords.txt");
  }

  //STORE HUFFMAN CODES IN MAP
  string temp;
  while(!in.eof()) {
    in >> temp;
    ascii = stoi(temp);
    in >> word;

    the_code.insert(pair<int,string>(ascii,word));
  }
  //debug print out the map 
  // for (it=the_code.begin(); it!=the_code.end(); ++it) {
  //     cout << it->first << "     " << it->second <<endl;
  // }

  //STDIN FROM USER
  for(string line; getline(cin, line) && line.compare("");) {
    line += "\n";
    for(int i = 0; i < line.length(); i++) {
      int index_char = line[i];
      it = the_code.find(index_char);
      string code = it->second;
      cout <<code;

    }
  }

  return 0;




}
