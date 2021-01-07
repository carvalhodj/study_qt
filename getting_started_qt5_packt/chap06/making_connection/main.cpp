#include <QApplication>
#include <QtSql>
#include <QDebug>
/*
use contact_db;
CREATE TABLE IF NOT EXISTS contacts (
id INT AUTO_INCREMENT,
last_name VARCHAR(255) NOT NULL,
first_name VARCHAR(255) NOT NULL,
phone_number VARCHAR(255) NOT NULL,
PRIMARY KEY (id)
) ENGINE=INNODB;
*/
int main(int argc, char **argv) {
    QSqlDatabase db_conn = 
        QSqlDatabase::addDatabase("QMYSQL", "contact_db");
    db_conn.setHostName("127.0.0.1");
    db_conn.setDatabaseName("contact_db");
    db_conn.setUserName("root");
    db_conn.setPassword("123");
    db_conn.setPort(3306);

    if (!db_conn.open()) {
        qDebug() << db_conn.lastError();
        return 1;
    } else {
        qDebug() << "Database connection established !";
    }
}