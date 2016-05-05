#include "HuffmanTree.h"


HuffmanTree::HuffmanTree(int frequency, char character)
{
  m_Frequency = frequency;
  m_Character = character;

  m_ChildHuffman0 = 0;
  m_ChildHuffman1 = 0;
}


HuffmanTree::HuffmanTree(HuffmanTree huffmanTree0, HuffmanTree huffmanTree1)
{
  m_ChildHuffman0 = new HuffmanTree(huffmanTree0);
  m_ChildHuffman1 = new HuffmanTree(huffmanTree1);
  m_Frequency     = huffmanTree0.GetFrequency() + huffmanTree1.GetFrequency();
  m_Character     = (char) 0;
}


void HuffmanTree::SetFrequency(int frequency)
{
  m_Frequency = frequency;
}


void HuffmanTree::SetCharacter(char character)
{
  m_Character = character;
}


void HuffmanTree::SetChildrens(HuffmanTree huffmanTree0, HuffmanTree huffmanTree1)
{
  //m_ChildHuffman = new HuffmanTree[2];
}
