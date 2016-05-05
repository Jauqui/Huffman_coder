#include "HuffmanCoder.h"


HuffmanCoder::HuffmanCoder()
{
  for (int i=0; i<256; i++)
    m_Frequency.push_back(0);
}


void HuffmanCoder::SetString(std::string coderString)
{
  for (std::string::iterator it = coderString.begin(); it < coderString.end(); it++)
  {
    int asciiCode = (int)*it;
    m_Frequency[asciiCode]++;
  }
}

void HuffmanCoder::process()
{
  std::cout << "Char\t|\tFrequency" << std::endl;
  int ascii = 0;

  std::vector<HuffmanTree> tempHuffmanTree;
  // Create trees, plot character and their frequency
  for (std::vector<int>::iterator it = m_Frequency.begin(); it<m_Frequency.end(); it++, ascii++)
  {
    if (*it>0)
    {
      HuffmanTree tree(*it, (char) ascii);
      tempHuffmanTree.push_back(tree);

      std::cout << "'" << (char)ascii << "'" <<"\t|\t" << *it << std::endl;
    }
  }

  // For every letter we create an empty string of code
  m_Codes.resize(tempHuffmanTree.size(), "");
  std::cout << std::endl << std::endl << std::endl << "Grouping the trees (" <<
               tempHuffmanTree.size() << ")" << std::endl;

  std::vector<HuffmanTree>::iterator it0;
  std::vector<HuffmanTree>::iterator it1;
  while (tempHuffmanTree.size()>1)
  {
    char minChar0 = '\0';
    char minChar1 = '\0';
    int minFreq0 = std::numeric_limits<int>::max();
    int minFreq1 = std::numeric_limits<int>::max();

    for (std::vector<HuffmanTree>::iterator it = tempHuffmanTree.begin(); it < tempHuffmanTree.end(); it++)
    {
      HuffmanTree currentHuffman = *it;
      if (currentHuffman.GetFrequency()<minFreq1)
      {
        if (currentHuffman.GetFrequency()<minFreq0)
        {
          minFreq1 = minFreq0;
          minChar1 = minChar0;
          it1      = it0;

          minFreq0 = currentHuffman.GetFrequency();
          minChar0 = currentHuffman.GetCharacter();
          it0      = it;
        }
        else
        {
          minFreq1 = currentHuffman.GetFrequency();
          minChar1 = currentHuffman.GetCharacter();
          it1      = it;
        }
      }
    }
    // Don't kwnow the parent tree character...
    HuffmanTree newHuffmanTree(*it0, *it1);
    //We have to remove in this order or the second position (it1) will change
    if (it1>it0)
    {
      tempHuffmanTree.erase(it1);
      tempHuffmanTree.erase(it0);
    }
    else
    {
      tempHuffmanTree.erase(it0);
      tempHuffmanTree.erase(it1);
    }
    tempHuffmanTree.push_back(newHuffmanTree);
    std::cout << "Remaining " << tempHuffmanTree.size()-1 << std::endl;
  }
  HuffmanTree huffmanTree = *tempHuffmanTree.begin();
  ProcessLetters(huffmanTree, std::string(""));
}

void HuffmanCoder::ProcessLetters(HuffmanTree huffmanTree, std::string codeString)
{
  if ((int)huffmanTree.GetCharacter()==0)
  {
    ProcessLetters(*huffmanTree.Get0Child(), codeString + std::string("0"));
    ProcessLetters(*huffmanTree.Get1Child(), codeString + std::string("1"));
  }
  else
  {
    //Add letter
    std::cout << "'" << huffmanTree.GetCharacter() << "'\t|\t" << codeString << std::endl;
  }
}
