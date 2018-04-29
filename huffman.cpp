#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <fstream>
#include <map>

using namespace std;

//**************
//METHODS
void traverseTree(struct Node* root, string str, int &total_bits,string output[]);
void writeCodes(string output[]);

//**************
//STRUCTS
struct Node {
  Node() {}
    int ascii_char;
    bool is_in_node = false;
    int freq;
    Node* left = NULL;
    Node* right = NULL;
};

struct compatorator {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// bool operator<(const Node& a, const Node& b) {
//   return a.freq > b.freq;
// }

int main(int argc, char* argv[]) {
  int frequency;
  char ascii_num;
  string word;

  priority_queue<Node*, vector<Node*>, compatorator> qq;

  for(string line; getline(cin, line) && line.compare("");) {
      stringstream ss(line);
      ss >> word;
      int val = stoi(word);
      ascii_num = val;
      ss >> word;
      val = stoi(word);
      frequency = val;


      // cout << "THe Char is: " << ascii_num <<endl;
      // cout << "freq is:  " << frequency <<endl;
      Node* newNode = new Node(); //=new Node(ascii_num, frequency);
      newNode->ascii_char = ascii_num;
      newNode->is_in_node = false;
      newNode->freq = frequency;

      // newNode.freq = frequency;
      // newNode.ascii_char = ascii_num;
      // newNode.is
      //Node *temp= &newNode;
      qq.push(newNode);

    }

    Node* left;
    Node* right;
  while (qq.size() != 1) {
      left = qq.top();
      qq.pop();

      right = qq.top();
      qq.pop();

      Node *comb= new Node();
      comb->ascii_char = '0';
      comb->freq = (left->freq + right->freq);
      comb->is_in_node = true;

      comb->left = left;
      comb->right = right;

      qq.push(comb);
  }

  int total_bits = 0;


  string output[300];
  traverseTree(qq.top(), "", total_bits, output);
  //cout << "TOTAL BITS: " << total_bits <<endl;

  writeCodes(output);


  cout << total_bits <<endl;

}

void traverseTree(struct Node* root, string str, int &total_bits, string output[]) {
    if (root == NULL) {
        return;
    }

    if (root->is_in_node != true) {
        //cout << root->ascii_char << ": " << str <<endl;
        //cout << "NOTE THAT: " << root->ascii_char << endl;
        output[root->ascii_char] = str;
        total_bits += str.length()*root->freq;
    }
    else {
      traverseTree(root->left, str + "0", total_bits, output);
      traverseTree(root->right, str + "1",total_bits, output);
    }
}

void writeCodes(string output[]) {
  ofstream of;
  of.open("codewords.txt");

  for(int i = 0; i < 300; i++) {
    if(output[i] == "")
      continue;
    else {
      of <<  i  << "\t" << output[i] << "\n";
    }
  }
  of.close();
}
