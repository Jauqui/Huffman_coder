#include <iostream>
#include <fstream>

#include "HuffmanCoder.h"


int main(int argc, char *argv[])
{
  //Read file
  std::ifstream myFile;
  myFile.open("F:\\Sources\\Karlskrona\\Huffman_coding\\data\\Huffman_text.txt");
  if(myFile.fail()){
    std::cout << "Error opening file... this can be caused because file is not located where expected" << std::endl;
    return -1;
  }
  std::string str;

  std::string tempString;
  while(std::getline(myFile, tempString))
  {
    str.append(tempString);
  }

  HuffmanCoder* coder = new HuffmanCoder();
  coder->SetString(str);
  myFile.close();
  coder->process();

  return 0;
}
