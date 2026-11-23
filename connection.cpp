#include "connection.h"
#include <QSqlError>
#include <QDebug>

Connection& Connection::getInstance() {
    static Connection instance;
    return instance;
}

bool Connection::connect(const QString &host, const QString &base,
                         const QString &user, const QString &password) {
    if (QSqlDatabase::contains("main_connection"))
        QSqlDatabase::removeDatabase("main_connection");

    db = QSqlDatabase::addDatabase("QODBC", "main_connection");
    db.setDatabaseName(
        "DRIVER={MySQL ODBC 9.7 ANSI Driver};"
        "SERVER=" + host + ";"
                 "DATABASE=" + base + ";"
                 "USER=" + user + ";"
                 "PASSWORD=" + password + ";"
                     "PORT=3306;"
        );

    if (!db.open()) {
        qDebug() << "Erreur connexion:" << db.lastError().text();
        return false;
    }
    return true;
}

bool Connection::isConnected() const {
    return db.isOpen();
}

QSqlDatabase Connection::getDatabase() const {
    return db;
}