

class KeyboardKey {
 public:
  KeyboardKey() {}

  virtual bool IsKeyNumber(){};

 protected:
  char code;
};