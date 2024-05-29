#ifndef CHAT_ROOM_H
#define CHAT_ROOM_H

#include <string>
#include <set>
#include "Observer.h" // Assuming Observer class is defined in Observer.h

class ChatRoom : public Observable
{
public:
    explicit ChatRoom(std::string name);

    void SendMessage(std::string const& message);

    std::string GetName() const;

    std::string const& GetDataFromKey(design::AccessKey<Observer>, const void* dataKey);

private:
    const std::string name_;
};

#endif // CHAT_ROOM_H
