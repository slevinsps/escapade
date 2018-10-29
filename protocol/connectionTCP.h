#ifndef CONNECTION_TCP
#define CONNECTION_TCP
class connectionTCP: connection{
public:
  connectionTCP();
  ~connectionTCP();
  vurtual void connect(const user* usr);
  vurtual void send(void*  data, size_t* NumByte);
  vurtual void receive(void* data, size_t* NumByte);
  vurtual void close();
private:
  boost::asio::ip::tcp::socket socket;
};
#endif
