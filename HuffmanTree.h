#include <string>


class HuffmanTree
{
  public:
    HuffmanTree(int frequency, char character);
    HuffmanTree(HuffmanTree huffmanTree0, HuffmanTree huffmanTree1);


    void SetFrequency(int frequency);
    int  GetFrequency() { return m_Frequency; }
    void SetCharacter(char character);
    char GetCharacter() { return m_Character; }

    void SetChildrens(HuffmanTree huffmanTree0, HuffmanTree huffmanTree1);

    HuffmanTree* Get0Child() { return m_ChildHuffman0; }
    HuffmanTree* Get1Child() { return m_ChildHuffman1; }

  protected:
    char m_Character;
    int  m_Frequency;

    HuffmanTree* m_ChildHuffman0;
    HuffmanTree* m_ChildHuffman1;
};
