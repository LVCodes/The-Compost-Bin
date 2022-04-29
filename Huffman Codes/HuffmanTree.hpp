#ifndef __HUFFMAN_H_
#define __HUFFMAN_H_
#include "HuffmanBase.hpp"
#include <map>

struct LessThan{
    bool operator()(HuffmanNode& l, HuffmanNode& r) const{
        return (l.getFrequency() == r.getFrequency() ?
                l.getCharacter() < r.getCharacter() :
                l.getFrequency() < r.getFrequency());
    }

    bool operator()(HuffmanNode *l, HuffmanNode *r) const{
        return operator()(*l, *r);
    }
};

class HuffmanTree : public HuffmanTreeBase {
    public:
        //Compress the input string using the method explained in the rubric.
        //Note: Typically we would be returning a number of bits to represent the code,
        //but for this project we are returning a string
        std::string compress(const std::string inputStr);


        //Serialize the tree using the above method. We do not need the frequency values
        //to rebuild the tree, just the characters on the leaves and where the branches
        //are in the post order.
        std::string serializeTree() const;


        //Given a string created with the compress method and a serialized version of the
        //tree, return the decompressed original string
        std::string decompress(const std::string inputCode, const std::string serializedTree);

        std::map<char, size_t> cfm;
        std::map<char, std::string> prefixMap;
        ~HuffmanTree();

    private:
        //cfm = CharacterFrequencyMap
        HuffmanNode *root = nullptr;

        void setPrefixMap(HuffmanNode*, std::string);
        //sTree is serialized tree :)
        std::string postOrder(HuffmanNode*,std::string) const;
        void deleteTree(HuffmanNode*);
        char getChar(HuffmanNode* node, std::string str, int &i);
};

#endif // __HUFFMAN_H_
