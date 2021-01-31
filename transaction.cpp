#include "transaction.h"

transaction::transaction(std::string sender, std::string receiver, float amount) {
    sender = sender;
    receiver = receiver;
    amount = amount;
}

transaction::to_string() {
    return sender + "/" + receiver + "/" + std::to_string(amount);
}
