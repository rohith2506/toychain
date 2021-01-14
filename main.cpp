#include <iostream>
#include <vector>
#include <string>
#include "sha256.h"

typedef long long int ll;
const int MAX_TRANSACTIONS_PER_BLOCK = 3;


/*
A simple sha256 to generate the block hash
*/
std::string generate_block_hash(std::string message) {
    std::cout << "message: " << message << std::endl;
    return sha256(message);
}

/*
A transaction contains
1. Sender public address
2. Recipient public address
3. Amount to be transferred
*/

class transaction {
    private:
        std::string sender;
        std::string recipient;
        float amount;

    public:
        transaction(std::string sender, std::string recipient, float amount) {
            sender = sender;
            recipient = recipient;
            amount = amount;
        }

        std::string to_string() {
            return sender + "/" + recipient  + "/" + std::to_string(amount);
        }
};

/*
 * A block contains
 * 1. block hash
 * 2. block number
 * 3. previous block hash
 * 4. list of transactions
 */

class BlockContent {
    private:
        std::string previous_block_hash;
        ll block_number;
        int total_txns;
        std::vector<transaction> txns;
    public:
        BlockContent(std::string previous_block_hash, ll block_number, std::vector<transaction> txns) {
            previous_block_hash = previous_block_hash;
            block_number = block_number;
            total_txns = txns.size();
            txns = txns;
        }
        
        std::string generate_unique_string(std::vector<transaction> txns) {
            std::string result = "";
            for(auto txn: txns) {
                result += txn.to_string();
            }
            return result;
        }
    
        ll get_block_number() {
            return block_number;
        }

        std::string get_string() {
            return previous_block_hash + "/" + std::to_string(block_number) + "/" \
                + std::to_string(total_txns) + "/" + generate_unique_string(txns);
        }
};

class Block {
    private:
        std::string block_hash;
        BlockContent *block_content;

    public:
        Block(BlockContent *block_content) {
            ll block_number = block_content->get_block_number() + 1;
            std::string block_hash = generate_block_hash(block_content->get_string());
            block_hash = block_hash;
            block_content = block_content;
        }
};

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
