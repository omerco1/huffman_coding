#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <bitset>
#include <string>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
  map<string, int> the_code;
  map<string,int>::iterator it = the_code.begin();
  string word;
  int ascii;
  fstream in;
  in.open(argv[1]);

  //IF YOU INCORRECTLY ENTERED THE FILE NAME TO ARGV[] I WILL OPEN IT MANUALLY
  if (!in.is_open()) {
    cout << "There was an error opening your file... opening codewords.txt." <<endl;
    return 0;
    in.open("codewords.txt");
  }

  //STORE HUFFMAN CODES IN MAP
   string temporary;
  while(!in.eof()) {
    in >> temporary;
    ascii = stoi(temporary);
    in >> word;

    the_code.insert(pair<string,int>(word,ascii));
  }

  string jibberish;
  string line;
  string g;
  int padding;
  getline(cin, line);
  stringstream ss(line);
  ss >> word;
  ss >> g;
  padding = stoi(g);
  //cout << "PADDING IS: " <<padding<<endl;

  cin >> jibberish;
  //cout << "JIBERISH IS: " <<endl;
  //cout << jibberish << endl;

  //cin >> jibberish;
  //cout << "OK SO: " <<jibberish<<endl;
  //getline(cin, jibberish);

  //cout << "NOTE THAT: " <<jibberish.length()<<endl;
  string sum;
  for(int i = 0; i < jibberish.length(); i++) {

      bitset<8> b =bitset<8>(jibberish[i]);
      //auto bitset = std::bitset<8>(jibberish[i]);
      //char c= static_cast<char>(bitset.to_ulong());

      sum += b.to_string();
      //sum += b.to_string();
  }

  //cout << sum;

  string code;
  string final_output = "";
  for(int i = 0; i < sum.length()-padding; i++) {
    code += sum[i];
    if(the_code.count(code)!=0) {
      it = the_code.find(code);
  	  char x = it->second;

      final_output += x;
      code = "";
    }
  }
  cout << final_output;

  return 0;
}
