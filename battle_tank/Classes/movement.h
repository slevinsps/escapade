#ifndef MOVEMENT_H
#define MOVEMENT_H


class Movement
{
public:
  Movement(){
	
  };
	/*
    virtual ~Movement();

    int get_max_speed() const;

    int get_current_speed() const;

    void set_max_speed(int max_speed);

    void set_current_speed(int current_speed);
	*/
	static float get_angle(float ang_f);


	  //  bool SetActive(bool active) { return active; }
	/*
private:
    int max_speed_;
    int current_speed_;
	*/
};

#endif // MOVEMENT_H
