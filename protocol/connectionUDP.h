class connectionUDP: connection{
public:
  connectionUDP();
  ~connectionUDP();
  void connect(const user* usr);
  void send(void*  data, size_t* NumByte);
  void receive(void* data, size_t* NumByte);
  bool TCPisWork( const connectionTCP* _connectionTCP);
  void close();
private:
  boost::asio::ip::udp::socket socket;
};
