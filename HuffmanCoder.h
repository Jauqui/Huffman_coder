#include <stdio.h>
#include <string.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

#include "HuffmanTree.h"


class HuffmanCoder
{
  public:
    HuffmanCoder();

    void SetString(std::string coderString);

    void process();


  protected:
    void ProcessLetters(HuffmanTree huffmanTree, std::string codeString);


    std::vector<int> m_Frequency;
    std::vector<std::string> m_Codes;

};
