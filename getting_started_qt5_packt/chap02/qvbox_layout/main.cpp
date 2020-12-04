#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QWidget* window = new QWidget;
    QLabel* label1 = new QLabel("Username");
    QLabel* label2 = new QLabel("Password");
    QLineEdit* usernameLineEdit = new QLineEdit;
    usernameLineEdit->setPlaceholderText("Enter your username");
    QLineEdit* passwordLineEdit = new QLineEdit;
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    passwordLineEdit->setPlaceholderText("Enter your password");
    QPushButton* button1 = new QPushButton("&Login");
    QPushButton* button2 = new QPushButton("&Register");
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(label1);
    layout->addWidget(usernameLineEdit);
    layout->addWidget(label2);
    layout->addWidget(passwordLineEdit);
    layout->addWidget(button1);
    layout->addWidget(button2);
    window->setLayout(layout);
    window->show();

    return app.exec();

}