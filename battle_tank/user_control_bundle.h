#ifndef USER_CONTROL_H
#define USER_CONTROL_H

#include "unit_control.h"
#include "user.h"
#include "loader.h"

class UserControlBundle : public Loader
{
private:
    User user;
    UnitControl algorithm;
public:
    UserControlBundle(User _user, UnitControl _algorithm) :
        user(_user), algorithm(_algorithm){}

    virtual ~UserControlBundle();
    User getUser() const;

    UnitControl getUnitControl() const;
    void setUnitControl(UnitControl UC);
    // Алгоритм поменяться может, игрок - нет

    int load(Socket socket) override;
    int send(Socket socket) override;
};

#endif // USER_CONTROL_H