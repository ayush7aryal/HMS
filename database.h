#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <string>
#include <QVariant>
#include "package.h"
#include "guest.h"
#include "room.h"


class Database
{

private:
    QSqlDatabase db;
    Package inactivepackages[10];
    Package activepackages[10];

public:
    bool connectDB();
    QSqlDatabase getDB();
    void addPackages(QString name, QString company, QString details, int price, bool available);
    bool removePackages(int id);
    void makeAvailable(int id);
    void makeUnavailable(int id);
    Package getPackageByID(int id);
    void getRooms(Guest guests[]);
    void getUsers(Room rooms[]);

    Guest getGuestDetailByRoomNo(int no);
    bool guestCheckOut(int id);
    bool payAmount(int amount, int id);
};

#endif // DATABASE_H
