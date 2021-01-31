#include <string>

class transaction {
    private:
        std::string sender_address;
        std::string receiver_address;
        std::string message;
        std::string signature;

    public:
        transaction(std::string sender, std::string recipient, float amount);
        transaction create_transaction();
        bool verify_transaction();
        std::string generate_unique_id(); 
        ~transaction();
};
