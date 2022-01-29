#include "MessageQueue.hpp"

bool MessageQueue::startUp() {
    return true;
}

void MessageQueue::shutDown() {
    while (mQueue.empty() == false)
        mQueue.pop();
}

void MessageQueue::pushMessage(Message message) {
    mQueue.push(message);
}

void MessageQueue::pushMessage(MessageId id) {
    mQueue.push({id, nullptr});
}

void MessageQueue::pushMessage(MessageId id, void* data) {
    mQueue.push({id, data});
}

Message MessageQueue::popMessage() {
    if (mQueue.empty() == true) { return {}; }

    Message message = mQueue.front();
    mQueue.pop();
    return message;
}

bool MessageQueue::isEmpty() {
    return mQueue.empty();
}