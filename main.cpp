#include <iostream>
#include <vector>
#include <string>
#include "transaction.h"
#include "block.h"
#include "sha256.h"

typedef long long int ll;
const int MAX_TRANSACTIONS_PER_BLOCK = 3;


int main(int argc, char *argv[]) {
    // Create transactions
    transaction txn1("Alice", "Bob", 10.0);
    transaction txn2("Bob", "Rob", 20.0);
    transaction txn3("Rob", "Alice", 30.0);
    
    std::vector<transaction> txns = { txn1, txn2, txn3 };

    // create a genesis block
    BlockContent *block_content = new BlockContent("", 1, txns);
    Block block(block_content);

    return 0;
}
