class connection{
public:
  virtual connection();
  virtual ~connection();
  bool isWorks();
  virtual void connect(const user* usr) = 0;
  virtual void send(void*  data, size_t* NumByte) = 0;
  virtual void receive(void* data, size_t* NumByte) = 0;
  virtual void close() = 0;
protected:
  boost::asio::io_service service;
  bool itWorks;
  user user;
};
