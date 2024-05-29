#include <gtest/gtest.h>
#include "chat_room.cpp"

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
