#include <iostream>
//#include <boost.asio>
#include <gtest/gtest.h>
namespace testing {
namespace gmock_nice_strict_test {

using testing::GMOCK_FLAG(verbose);
using testing::HasSubstr;
using testing::NaggyMock;
using testing::NiceMock;
using testing::StrictMock;

#if GTEST_HAS_STREAM_REDIRECTION
using testing::internal::CaptureStdout;
using testing::internal::GetCapturedStdout;
#endif


#include "gmock/gmock.h"
#include "Connection.h"
#include "connectionTCP.h"
#include "connectionUDP.h"

//заглушка
class User{
public:
  User();
  ~User();
  string IP;
  int status;
  string Name;
  string getIP(){ return IP;}
  int getStatus() { return status;}
  string getName() { return Name;}
}
enum statuses {
    DISSCONECTED = -1,
    OBSERVER = 0,
    PLAYER = 1};

template <class conn>
class TestConnection : public ::testing::Test
{
protected:
	void SetUp()
	{
		connection = new conn;
    someUser = new User;
		someUser->IP = "0.0.0.1";
    someUser->Name = "nobody"
    someUser->status = DISSCONECTED;
	}
	void TearDown()
	{
		delete connection;
    delete someUser;
	}
	connectionTCP *connection;
  User* someUser;
};

TEST_F(TestConnection<connectionTCP>, test1)
{
	EXPECT_FALSE(conTCP->isWorks());
  EXPECT_STREQ(conTCP->user.getIP, "0.0.0.0");
  EXPECT_STREQ(conTCP->user.getName, "");
  EXPECT_EQ(conTCP->user.getStatus, DISSCONECTED);
}

TEST_F(TestConnection<connectionTCP>, test2)
{
  ASSERT_ANY_THROW(connection.send(someuser));
}

template <class conn>
class MockConnection : public conn {
 public:
  MockConnection() {}
  void Delete() { delete this; }

  MOCK_METHOD1(connect, void());
  MOCK_METHOD2(send, void(void* data, size_t* NumByte));
  MOCK_METHOD2(receive, void(void* data, size_t* NumByte));
  MOCK_METHOD0(close, void());

 private:
  GTEST_DISALLOW_COPY_AND_ASSIGN_(MockConnectionTCP);
};
// Tests that a raw mock generates warnings for uninteresting calls
// that delete the mock object.
TEST(RawMockTest, WarningForUninterestingCallAfterDeath) {
  const std::string saved_flag = GMOCK_FLAG(verbose);
  GMOCK_FLAG(verbose) = "warning";

  MockConnection* const raw_Connection = new MockConnection<connectionTCP>;

  ON_CALL(*raw_Connection, connection())
      .WillByDefault(Invoke(raw_Connection, &MockConnection::Delete));

  CaptureStdout();
  raw_Connection->connection();
  EXPECT_THAT(GetCapturedStdout(),
              HasSubstr("Uninteresting mock function call"));

  GMOCK_FLAG(verbose) = saved_flag;
}

// Tests that a raw mock generates informational logs for
// uninteresting calls.
TEST(RawMockTest, InfoForUninterestingCall) {
  MockConnectionTCP raw_ConnectionTCP;

  const std::string saved_flag = GMOCK_FLAG(verbose);
  GMOCK_FLAG(verbose) = "info";
  CaptureStdout();
  raw_ConnectionTCP.connection();
  EXPECT_THAT(GetCapturedStdout(),
              HasSubstr("Uninteresting mock function call"));

  GMOCK_FLAG(verbose) = saved_flag;
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
