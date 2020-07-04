#include "mainwindow.h"
#include <QApplication>

#include <QtCore/QDateTime>
#include <QtWidgets/QMessageBox>

#include <QProcess>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow *mainWindow = new MainWindow;

    int finalizar = app.exec();

    //Se liberan las variables
    mainWindow->liberar_variables();

    return finalizar;
}
