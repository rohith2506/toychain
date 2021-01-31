class User {
    private:
        std::string public_key;
        std::string secret_key;
        std::string name;
    public:
        user(std::string public_key, std::string secret_key, std::string name);
        transaction send_transaction();
        transaction receive_transaction();
        blockchain get_latest_verified_blockchain();
}
