#include <gtest/gtest.h>
#include "../chat_room.cpp"

TEST(ChatRoomTest, SendMessageTest) {
    ChatRoom chatRoom("TestRoom");
    User user("TestUser");
    user.JoinChatRoom(chatRoom);

    testing::internal::CaptureStdout();
    chatRoom.SendMessage("Hello, World!");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "[TestUser][TestRoom] Hello, World!\n");
}

TEST(ChatRoomTest, MultipleUsersTest) {
    ChatRoom chatRoom("TestRoom");
    User user1("User1");
    User user2("User2");
    user1.JoinChatRoom(chatRoom);
    user2.JoinChatRoom(chatRoom);

    testing::internal::CaptureStdout();
    chatRoom.SendMessage("Hello, Users!");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "[User1][TestRoom] Hello, Users!\n[User2][TestRoom] Hello, Users!\n");
}

TEST(ChatRoomTest, MultipleChatRoomsTest) {
    ChatRoom chatRoom1("Room1");
    ChatRoom chatRoom2("Room2");
    User user("TestUser");
    user.JoinChatRoom(chatRoom1);
    user.JoinChatRoom(chatRoom2);

    testing::internal::CaptureStdout();
    chatRoom1.SendMessage("Message 1");
    chatRoom2.SendMessage("Message 2");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "[TestUser][Room1] Message 1\n[TestUser][Room2] Message 2\n");
}
