#include "Blockchain.h"

int main()
{
    Blockchain bChain = Blockchain();

    cout << "Mining block 1..." << endl;
    bChain.AddBlock(Block(1, "Bloc 1 de Data"));

    cout << "Mining block 2..." << endl;
    bChain.AddBlock(Block(2, "Adjanie"));

    cout << "Mining block 3..." << endl;
    bChain.AddBlock(Block(3, "Touradj"));

    return 0;
}
