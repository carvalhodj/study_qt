#include <QApplication>
#include <QtSql>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <Qt>
#include <QTableView>
#include <QHeaderView>

int main(int argc, char **argv) {
    QApplication app(argc, argv);
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

    enum {
        ID = 0,
        LastName = 1,
        FirstName = 2,
        PhoneNumber = 3,
    };

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
    contactsTableModel->setHeaderData(ID, Qt::Horizontal, QObject::tr("ID"));
    contactsTableModel->setHeaderData(LastName, Qt::Horizontal, QObject::tr("Last Name"));
    contactsTableModel->setHeaderData(FirstName, Qt::Horizontal, QObject::tr("First Name"));
    contactsTableModel->setHeaderData(PhoneNumber, Qt::Horizontal, QObject::tr("Phone Number"));
    contactsTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    // For changes be applied automatically in database
    // contactsTableModel->setEditStrategy(QSqlTableModel::OnRowChange);

    QTableView *contactsTableView = new QTableView();
    contactsTableView->setModel(contactsTableModel);
    contactsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    contactsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    QHeaderView *header = contactsTableView->horizontalHeader();
    header->setStretchLastSection(true);
    
    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout();
    QPushButton *saveToDbPushButton = new QPushButton("Save");
    layout->addWidget(contactsTableView);
    layout->addWidget(saveToDbPushButton);
    QObject::connect(saveToDbPushButton, SIGNAL(clicked()),
                    contactsTableModel, SLOT(submitAll()));
    window.setLayout(layout);
    window.show();

    return app.exec();
}