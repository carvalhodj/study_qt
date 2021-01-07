#include <QtSql>
#include <QDebug>

int main(int argc, char **argv) {
    
    // Database connection
    QSqlDatabase db_conn = QSqlDatabase::addDatabase("QMYSQL", "contact_db");
    db_conn.setHostName("127.0.0.1");
    db_conn.setDatabaseName("contact_db");
    db_conn.setUserName("root");
    db_conn.setPassword("123");
    db_conn.setPort(3306);

    if (!db_conn.open()) {
        qDebug() << db_conn.lastError();
        return 1;
    }

    // Drop table
    // QSqlQuery drop_statement("DROP TABLE contacts", db_conn);

    // Create table
    // QString table_definition = "use contact_db;\n"
    // "CREATE TABLE IF NOT EXISTS contacts (\n"
    // "id INT AUTO_INCREMENT,\n"
    // "last_name VARCHAR(255) NOT NULL,\n"
    // "first_name VARCHAR(255) NOT NULL,\n"
    // "phone_number VARCHAR(255) NOT NULL,\n"
    // "PRIMARY KEY (id)\n"
    // ") ENGINE=INNODB;";
    // QSqlQuery table_creator(table_definition, db_conn);

    // Use Database model
    QSqlTableModel *contactsTableModel = new QSqlTableModel(0, db_conn);
    contactsTableModel->setTable("contacts");
    contactsTableModel->select();
    for (int i = 0 ; i < contactsTableModel->rowCount() ; ++i) {
        QSqlRecord record = contactsTableModel->record(i);
        QString id = record.value("id").toString();
        QString last_name = record.value("last_name").toString();
        QString first_name = record.value("first_name").toString();
        QString phone_number = record.value("phone_number").toString();
        qDebug() << id << " : " << first_name << " : " << 
                    last_name << " : " << phone_number;
    }

    // Insert row
    int row = contactsTableModel->rowCount();
    contactsTableModel->insertRows(row, 1);
    contactsTableModel->setData(contactsTableModel->index(row, 1), "Stokes");
    contactsTableModel->setData(contactsTableModel->index(row, 2), "Nick");
    contactsTableModel->setData(contactsTableModel->index(row, 3), "+443569948");
    contactsTableModel->submitAll();

    // Custom filter
    qDebug() << "\nCustom filter: \n";
    contactsTableModel->setFilter("id=12 AND last_name like 'Stokes'");
    contactsTableModel->select();
    for (int i = 0 ; i < contactsTableModel->rowCount() ; ++i) {
        QSqlRecord record = contactsTableModel->record(i);
        QString id = record.value("id").toString();
        QString last_name = record.value("last_name").toString();
        QString first_name = record.value("first_name").toString();
        QString phone_number = record.value("phone_number").toString();
        qDebug() << id << " : " << first_name << " : " << 
                    last_name << " : " << phone_number;
    }
}