#ifndef USER_CONTROL_H
#define USER_CONTROL_H

#include "unit_control.h"
#include "user.h"
#include "loader.h"

class UserControlBundle : public Loader
{
private:
    User user_;
    UnitControl algorithm_;
public:
    UserControlBundle(User user, UnitControl algorithm);

    ~UserControlBundle();

    User getUser() const;

    UnitControl getUnitControl() const;
    void setUnitControl(UnitControl UC);

    // Алгоритм поменяться может, игрок - нет

    bool operator == (const UserControlBundle &other) const;

    bool operator != (const UserControlBundle &other) const;

    int load(Socket socket) override;
    int send(Socket socket) override;
};

#endif // USER_CONTROL_H
