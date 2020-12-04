#include <QApplication>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QWidget* window = new QWidget;
    QLineEdit* urlLineEdit = new QLineEdit;
    QPushButton* exportButton = new QPushButton("Export");
    urlLineEdit->setPlaceholderText("Enter URL to export. Eg, http://yourdomain.com/items");
    urlLineEdit->setFixedWidth(400);
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(urlLineEdit);
    layout->addWidget(exportButton);

    window->setLayout(layout);
    window->show();

    return app.exec();
}