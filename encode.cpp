#include <iostream>
#include <vector>
#include <fstream>
#include <bitset>
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

  ofstream of;
  of.open("test.txt");

  //STDIN FROM USER
  string acum;
  for(string line; getline(cin, line) && line.compare("");) {
    line += "\n";
    for(int i = 0; i < line.length(); i++) {
      int index_char = line[i];
      it = the_code.find(index_char);
      string code = it->second;

      acum += code;

    }
  }
  //cout << acum <<endl;
  int char_blocks;
  int padding = acum.length()%8;
  //char pad = char(padding);
  //cout << "OMER " <<endl;
  cout << "pad: ";
  cout << padding << "\n";

  if (padding ==0) {
    char_blocks = acum.length()/8;
  } else {
    char_blocks = acum.length()/8 + 1; //ADD ONE?????
    for(int i =0; i < 8-padding; i++){
      acum += "0";
    }
    //char_blocks = acum.length()/8 + 1;

  }
  //TO DO: GET REMAINDER TO OUTPUT LAST BITS

  //cout << "CHAR BLOCKS IS: " <<char_blocks <<endl;

  for(int i = 0; i < char_blocks; i++) {

        string temp = acum.substr(i*8,8);

        // bitset<8> b(temp);
        // char* c = (char*)&b;
        // cout << *c;


        auto bitset = std::bitset<8>(temp);
        char c= static_cast<char>(bitset.to_ulong());
        cout << c;

  }

  return 0;


}
