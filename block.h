#include <string>
typedef long long int ll;

class Block {
    private:
        std::string previous_block_hash;
        ll block_number;
        int total_txns;
        std::vector<transaction> txns;
    public:
        Block(std::string previous_block_hash, ll block_number, std::vector<transaction> txns);
        Block create_block();
        void append_transactions();
        std::string generate_unique_string(std::vector<transaction> txns); 
        ll get_block_number();
        std::string get_string();
}
