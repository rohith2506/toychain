#include <iostream>
#include <string>
#include "SHA256.H"

typedef long long int ll
const int MAX_TRANSACTIONS_PER_BLOCK = 3;


/*
A simple sha256 to generate the block hash
*/
string generate_block_hash(string message) {
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
        string sender;
        string recipient;
        float amount;

    public:
        transaction(string sender, string recipient, float amount) {
            this.sender = sender;
            this.recipient = recipient;
            this.amount = amount;
        }

        operator std::string() const {
            return this.sender + "/" + this.recipient  + "/" + std::to_string(this.amount);
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
        string previous_block_hash;
        ll block_number;
        int total_txns;
        std::vector<transaction> txns;
    public:
        BlockContent(string previous_block_hash, ll block_number, std::vector<transaction> txns) {
            this.previous_block_hash = previous_block_hash;
            this.block_number = block_number;
            this.total_txns = txns.size();
            this.txns = txns;
        }
        
        std::string generate_unique_string(std::vector<transaction> txns) {
            std::string result = "";
            for(auto txn: txns) {
                result += txn.string();
            }
        }

        operator std::string() const {
            return this.previous_block_hash + "/"
                + std::to_string(this.block_number) + "/" +
                + std::to_string(this.total_txns) + "/" +
                + generate_unique_string(txns);
        }
};

class Block {
    private:
        string block_hash;
        BlockContent block_content;

    public:
        Block(string previous_block_hash, ll previous_block_number, std::vector<transaction> txns) {
            ll block_number = previous_block_number + 1;
            BlockContent block_content = new BlockContent(previous_block_hash, previous_block_number, txns);
            string block_hash = generate_block_hash(block_content.string());
            this.block_hash = block_hash;
            this.block_content = block_content;
        }
}

int main(int argc, char *argv[]) {
    return 0;
}
