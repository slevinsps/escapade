class connectionTCP: connection{
public:
  connectionTCP();
  ~connectionTCP();
  void connect(const user* usr);
  void send(void*  data, size_t* NumByte);
  void receive(void* data, size_t* NumByte);
  void close();
private:
  boost::asio::ip::tcp::socket socket;
};
