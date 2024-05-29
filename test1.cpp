#include <gtest/gtest.h>
#include "chat_room.cpp"

TEST(ChatRoomTest, SendMessageTest) {
    ChatRoom chatRoom("TestRoom");
    User user("TestUser");
    user.JoinChatRoom(chatRoom);

    testing::internal::CaptureStdout();
    chatRoom.SendMessage("Hello, World!");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "[TestUser][TestRoom] Hello, World!\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
