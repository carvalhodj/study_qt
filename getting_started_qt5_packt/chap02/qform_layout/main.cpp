#include <QApplication>
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QStringList>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QWidget* window = new QWidget;
    QLineEdit* firstNameLineEdit = new QLineEdit;
    QLineEdit* lastNameLineEdit = new QLineEdit;
    QSpinBox* ageSpinBox = new QSpinBox;
    QComboBox* employmentStatusComboBox = new QComboBox;
    QStringList employmentStatus = {"Unemployed", "Employed", "NA"};
    ageSpinBox->setRange(1, 100);
    employmentStatusComboBox->addItems(employmentStatus);
    QFormLayout* personalInfoformLayout = new QFormLayout;
    personalInfoformLayout->addRow("First name:", firstNameLineEdit);
    personalInfoformLayout->addRow("Last name:", lastNameLineEdit);
    personalInfoformLayout->addRow("Age", ageSpinBox);
    personalInfoformLayout->addRow("Employment Status", employmentStatusComboBox);
    window->setLayout(personalInfoformLayout);
    window->show();

    return app.exec();
}