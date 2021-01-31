class Miner {
    public:
        Miner();
        void listen_transactions();
        void perform_proof_of_work();
        block release_block();
}
