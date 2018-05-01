#include <iostream>
#include <vector>
#include <fstream>
#include <bitset>
#include <string>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
  int in_char;
	vector<char> user_in;
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

  //GETLINE NOT WORKING!!!!
  // string acum;
  // for(string line; getline(cin, line) && line.compare("");) {
  //   line += "\n";
  //   for(int i = 0; i < line.length(); i++) {
  //     int index_char = line[i];
  //     it = the_code.find(index_char);
  //     string code = it->second;
  //
  //     acum += code;
  //
  //   }
  // }

  //CHAR AT A TIME
	while ((in_char = getc(stdin)) != EOF) //EOF is a flag
		user_in.push_back(static_cast<char>(in_char));


  string acum;
  for(int i = 0; i < user_in.size(); i++) {
    int index_char = user_in[i];
    it = the_code.find(index_char);
    string code = it->second;
    acum += code;
  }


  int char_blocks;
  int padding = acum.length()%8;
  if(padding == 0){
    cout << "pad: ";
    cout << padding <<endl;
    char_blocks = acum.length()/8;
  }
  else {
    padding = 8-acum.length()%8;
    char_blocks = acum.length()/8 + 1;
    cout << "pad: ";
    cout << padding << endl;
    for(int i =0; i < padding; i++)
      acum += "0";
  }

  int i;
  //vector<char> binary;
  for(i = 0; i < char_blocks; i++) {
        string temp = acum.substr(i*8,8);
        // bitset<8> b(temp);
        // char* c = (char*)&b;
        // cout << *c;
        //auto bitset = std::bitset<8>(temp);
        bitset<8> bitset(temp);
        char c= static_cast<char>(bitset.to_ulong());
        cout << c;
        //binary.push_back(c);

  }

  in.close();
  return 0;
}
