#ifndef CONNECTION_H
#define CONNECTION_H

#include <QString>
#include <QSqlDatabase>

class Connection {
public:
    static Connection& getInstance();
    bool connect(const QString &host, const QString &base,
                 const QString &user, const QString &password);
    bool isConnected() const;
    QSqlDatabase getDatabase() const;

private:
    Connection() {}
    Connection(const Connection&) = delete;
    Connection& operator=(const Connection&) = delete;
    QSqlDatabase db;
};

#endif