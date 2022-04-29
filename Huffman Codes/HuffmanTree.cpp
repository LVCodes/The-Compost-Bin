#include "HuffmanTree.hpp"
#include "HeapQueue.hpp"
#include <stack>


void HuffmanTree :: setPrefixMap(HuffmanNode *node, std::string str = ""){
    if(node->isLeaf())
        prefixMap[node->getCharacter()] = str;
    if(node->left)
        setPrefixMap(node->left, str + '0');
    if(node->right)
        setPrefixMap(node->right, str + '1');
}


std::string HuffmanTree :: compress(const std::string inputStr){

    for(auto ch : inputStr){
        if(cfm.count(ch) > 0)
            ++cfm[ch];
        else
            cfm[ch] = 1;
    }

    //this the priority queueueueueeu for huffman nodes
    HeapQueue<HuffmanNode*, LessThan> hq;
    //pair is for each map pair we iterating through
    for(auto pair : cfm){
        //dynamic allocation of temp pointer for priority queueueueeueueueueueueueueue
        HuffmanNode *temp = new HuffmanNode(pair.first, pair.second);
        hq.insert(temp);
    }
    //look for the last meeber of the queue to finish the tree
    while(hq.size() > 1){
        HuffmanNode *ltemp;
        HuffmanNode *rtemp;
        ltemp = hq.min();
        hq.removeMin();
        rtemp = hq.min();
        hq.removeMin();

        HuffmanNode *parent = new HuffmanNode('\0',
                                              (rtemp->getFrequency() + ltemp->getFrequency()),
                                              nullptr, ltemp, rtemp);
        hq.insert(parent);
    }

    root = hq.min();
    hq.removeMin();

    setPrefixMap(root);
    std::string strCoded = "";
    for(auto ch : inputStr)
        strCoded += prefixMap[ch];

    return strCoded;
}

std::string HuffmanTree :: postOrder(HuffmanNode* node, std::string sTree = "") const {
    if(node->isBranch())
        return sTree + postOrder(node->left, sTree) + postOrder(node->right, sTree) + "B";
    else
        return (sTree + "L" + node->getCharacter());
}

std::string HuffmanTree :: serializeTree() const{
    return postOrder(root);
}

void HuffmanTree :: deleteTree(HuffmanNode* node){
    if(node->left)
        deleteTree(node->left);
    if(node->right)
        deleteTree(node->right);
    delete node;
}

char HuffmanTree :: getChar(HuffmanNode* node, std::string str, int &i){
    if(node->isLeaf())
        return node->getCharacter();
    return getChar((str.at(i++) == '0' ? node->left : node->right), str, i);
}

std::string HuffmanTree :: decompress(const std::string inputCode, const std::string serializedTree){
    if(root != nullptr)
        deleteTree(root);

    std::stack<HuffmanNode*> stk;

    bool isNextLeaf = false;      //tea if next is leaf :)
    for(auto curr : serializedTree){
        if (isNextLeaf) {
            stk.push(new HuffmanNode(curr, 0));
            isNextLeaf = false;
        }
        else if(curr == 'B'){
            HuffmanNode* r;
            HuffmanNode* l;
            r = stk.top();
            stk.pop();
            l = stk.top();
            stk.pop();
            HuffmanNode* p = new HuffmanNode('\0', 0, nullptr, l, r);
            stk.push(p);
        }
        else if (curr == 'L')
            isNextLeaf = true;
    }

    root = stk.top();
    stk.pop();

    int i = 0;
    std::string OGstring = "";
    while((size_t)i < inputCode.length())
        OGstring += getChar(root, inputCode, i);

    return OGstring;
}

HuffmanTree :: ~HuffmanTree(){
    if(root != nullptr)
        deleteTree(root);
}
