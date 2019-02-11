#ifndef USER_TEST_H
#define USER_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../battle_tank/user.h"

class UserTest : public ::testing::Test {
protected:
    void SetUp()
    {
        user = new User();
    }

    void TearDown()
    {
        delete user;
    }
    User *user;
};

TEST_F(UserTest, setIP)
{
   int IP_right = 2000;
   int result = user->set_IP(IP_right);
   EXPECT_EQ(user->get_IP(), IP_right);
   EXPECT_EQ(result, SUCCESS);

   int IP_wrong = -2131;
   result = user->set_IP(IP_wrong);
   EXPECT_EQ(user->get_IP(), IP_right);
   EXPECT_EQ(result, USER_IP_MUST_BE_POSITIVE);
};

TEST_F(UserTest, setStatus)
{
   int status_right = PLAYER;
   int result = user->set_status(status_right);
   EXPECT_EQ(user->get_status(), status_right);
   EXPECT_EQ(result, SUCCESS);

   int status_wrong = 500;
   result = user->set_status(status_wrong);
   EXPECT_EQ(user->get_status(), status_right);
   EXPECT_EQ(result, USER_UNKNOWN_STATUS);
};

TEST_F(UserTest, setName)
{
   std::string name = "test player";
   int result = user->set_name(name);
   EXPECT_EQ(user->get_name(), name);
   EXPECT_EQ(result, SUCCESS);

   std::string name_empty = "";
   result = user->set_name(name_empty);
   EXPECT_EQ(user->get_name(), name);
   EXPECT_EQ(result, USER_EMPTY_NAME);
};

TEST_F(UserTest, setReady)
{
   user->set_ready(true);
   EXPECT_TRUE(user->get_ready());

   user->set_ready(false);
   EXPECT_FALSE(user->get_ready());
};


#endif // USER_TEST_H
