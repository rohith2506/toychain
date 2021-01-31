#include <string>

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
        transaction(std::string sender, std::string recipient, float amount);
        std::string to_string();
};
