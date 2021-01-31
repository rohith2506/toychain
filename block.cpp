#include "block.h"
#include "sha256.h"

Block::Block(std::string previous_block_hash, ll block_number, std::vector<transaction> txns) {
    previous_block_hash = previous_block_hash;
    block_number = block_number;
    total_txns = txns.size();
    txns = txns;
}

std::string Block::generate_unique_string(std::vector<transaction> txns) {
    std::string result = "";
    for(auto txn: txns) {
        result += txn.to_string();
    }
    return result;
}

ll Block::get_block_number() {
    return block_number;
}

std::string Block::get_string() {
    return previous_block_hash + "/" + std::to_string(block_number) + "/" \
        + std::to_string(total_txns) + "/" + generate_unique_string(txns);
}
