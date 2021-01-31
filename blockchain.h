class BlockChain {
    private:
        std::vector<Block> blocks;
    public:
        Blockchain();
        void append_new_block();
        std::vector<Block> broadcast_current_blockchain();
}
