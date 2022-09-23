// Jacob Drew
// 4280 P0
// Main.c++

#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include "node.h"
#include "tree.h"

using namespace std;

int main(int argc, char *argv[])
{
  // output file strings
  string inorderOutputString;
  string preorderOutputString;
  string postorderOutputString;
  string outputFileNameString;

  FILE *redirectionFile;
  string line = "";
  redirectionFile = fopen("stdinInput.txt", "w");
  ifstream inputFile;

  // handle command args
  //  if the arg is two we read the file otherwise we have to deal with keyboard input / read from stdin
  if (argc == 2)
  {
    inputFile.open(argv[1]);
    if (!inputFile)
    {
      perror("ERROR! Bad File!"); //print out useful error message
    }
    outputFileNameString = argv[1];
  }
  if (argc == 1)
  {
    fstream redirectionFstream;
    redirectionFstream.open("stdinInput.txt", ios::in | ios::out);
    cout << "Please input text for the tree. You can input multiple lines. Enter 'ctrl+D' when finished:" << endl;
    cout << "Input text:" << endl;
    while (cin >> line)
    {
      redirectionFstream << line << endl;
    }
    redirectionFstream.close();
    inputFile.open("stdinInput.txt");
    outputFileNameString = "output";
  }

  inorderOutputString = outputFileNameString + ".inorder";
  preorderOutputString = outputFileNameString + ".preorder";
  postorderOutputString = outputFileNameString + ".postorder";

  struct node_t *root = buildTree(inputFile);

  FILE *inorderFile;
  inorderFile = fopen(inorderOutputString.c_str(), "w");

  FILE *preorderFile;
  preorderFile = fopen(preorderOutputString.c_str(), "w");

  FILE *postOrderFile;
  postOrderFile = fopen(postorderOutputString.c_str(), "w");

  printInorder(root, inorderFile);
  printPreorder(root, preorderFile);
  printPostorder(root, postOrderFile);

  inputFile.close();
  fclose(inorderFile);
  fclose(preorderFile);
  fclose(postOrderFile);
  remove("stdinInput.txt");

  return 0;
}