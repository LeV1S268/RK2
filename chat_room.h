#pragma once

#include <string>

// Forward declaration of classes to avoid circular dependencies
class Observable;

// Observer interface
class Observer {
public:
    virtual ~Observer() = default;
    virtual void Update(Observable& observable, const void* dataKey) = 0;
};

// Observable interface
class Observable {
public:
    virtual ~Observable() = 0;
    void Attach(Observer& observer);
    void Detach(Observer& observer);
    void Notify(const void* dataKey);

private:
    std::set<Observer*> observerSet_;
};

// ChatRoom class
class ChatRoom : public Observable {
public:
    explicit ChatRoom(std::string name);
    void SendMessage(std::string const& message);
    std::string GetName() const;
    std::string const& GetDataFromKey(design::AccessKey<Observer>, const void* dataKey);

private:
    const std::string name_;
};

// User class
class User : public Observer {
public:
    explicit User(std::string name);
    void Update(Observable& observable, const void* dataKey) override;
    void JoinChatRoom(ChatRoom& chatRoom);

private:
    std::string name_;
    std::set<ChatRoom*> chatRoomSet_;
};
