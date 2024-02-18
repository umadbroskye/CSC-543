#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

struct HuffmanNode {
    char symbol;
    unsigned frequency;

    std::shared_ptr<HuffmanNode> leftChild, rightChild;

    HuffmanNode(char symbol, unsigned frequency) 
    : symbol(symbol), frequency(frequency), leftChild(nullptr), rightChild(nullptr) {}
};

void printHuffmanCodes(const std::shared_ptr<HuffmanNode>& node, const std::string& code = "") {
    if (!node) return;

    if (node->symbol != '$') {
        std::cout << node->symbol << ": " << code << "\n";
    }

    printHuffmanCodes(node->leftChild, code + "0");
    printHuffmanCodes(node->rightChild, code + "1");
}

void insertSorted(std::vector<std::shared_ptr<HuffmanNode>>& nodes, std::shared_ptr<HuffmanNode> newNode) {
    nodes.push_back(newNode);
    std::sort(nodes.begin(), nodes.end(), [](const std::shared_ptr<HuffmanNode>& a, const std::shared_ptr<HuffmanNode>& b) {
        return a->frequency < b->frequency;
    });
}

void generateHuffmanCodes(std::vector<char> symbols, std::vector<int> frequencies, int totalSymbols) {
    std::vector<std::shared_ptr<HuffmanNode>> nodes;

    for (int i = 0; i < totalSymbols; ++i) {
        insertSorted(nodes, std::make_shared<HuffmanNode>(symbols[i], frequencies[i]));
    }

    while (nodes.size() > 1) {
        auto left = nodes.front();
        nodes.erase(nodes.begin());

        auto right = nodes.front();
        nodes.erase(nodes.begin());

        auto parent = std::make_shared<HuffmanNode>('$', left->frequency + right->frequency);
        parent->leftChild = left;
        parent->rightChild = right;

        insertSorted(nodes, parent);
    }

    printHuffmanCodes(nodes.front());
}

int main() {
    int symbolCount;
    std::cout << "Enter the number of symbols: ";
    std::cin >> symbolCount;

    std::vector<char> inputSymbols(symbolCount);
    std::vector<int> symbolFrequencies(symbolCount);

    std::cout << "Enter symbols followed by their frequencies (eg, a5 b3 c7):\n";
    for (int i = 0; i < symbolCount; ++i) {
        std::cin >> inputSymbols[i] >> symbolFrequencies[i];
    }

    generateHuffmanCodes(inputSymbols, symbolFrequencies, symbolCount);

    return 0;
}
