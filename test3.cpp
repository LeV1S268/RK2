#include <gtest/gtest.h>
#include "../chat_room.cpp"

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
