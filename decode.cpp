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
    cout << "There was an error opening your file... opening codewords.txt."
    in.open("codewords.txt");
  }

  //STORE HUFFMAN CODES IN MAP
   string temporary;
  while(!in.eof()) {
    in >> temporary;
    ascii = stoi(temporary);
    in >> word;

    the_code.insert(pair<int,string>(ascii,word));
  }

  string jibberish;
  cin >> jibberish;
  //cout << "OK SO: " <<jibberish<<endl;
  //getline(cin, jibberish);

  cout << "NOTE THAT: " <<jibberish.length()<<endl;
 string sum;

  for(int i = 0; i < jibberish.length(); i++) {
  //for (char &c : jibberish) {
      //char c = jibberish[i];
      //cout << "C IS: " <<c <<endl;
      //bits.to_ulong()
      bitset<8> b =bitset<8>(jibberish[i]);
      char* c = (char*)&b;

      //cout << b.to_string() << endl;
      //cout << "NOW C IS: " <<c <<endl;
      //cout << "THE TO STIRNG IS: " <<temp.to_string() <<endl;
      sum += b.to_string();
  }
  //cout << sum;
  string code;
  string final_output = "";
  for(int i = 0; i < sum.length(); i++) {
    code += sum[i];
    if(the_code.count(code)!=0) {
      it = the_code.find(code);
  	  int x = it->first;
      final_output += x.to_string();
      code = "";
    }
  }
  cout << final_output;

  return 0;
}
