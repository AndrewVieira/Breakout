#ifndef MESSAGE_QUEUE_HPP
#define MESSAGE_QUEUE_HPP

#include <queue>

enum MessageId {
    MESSAGE_NONE,
    MESSAGE_QUIT
};

struct Message {
    MessageId id = MESSAGE_NONE;
    void* data = nullptr;
};

class MessageQueue {
    public:
        bool startUp();
        void shutDown();

        void pushMessage(Message message);
        void pushMessage(MessageId id);
        void pushMessage(MessageId id, void* data);
        Message popMessage();

        bool isEmpty();
    
    private:
        std::queue<Message> mQueue;
};

#endif // MESSAGE_QUEUE_HPP
