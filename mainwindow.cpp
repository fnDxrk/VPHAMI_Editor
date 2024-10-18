#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actionNew_triggered() {
    QString filePath = QFileDialog::getSaveFileName(this, "Create New File");
    if (!filePath.isEmpty()) {
        if (fileHandler.createFile(filePath)) {
            currentFilePath = filePath;
            ui->textEdit->clear();
        } else {
            QMessageBox::warning(this, "Warning", "File already exists!");
        }
    }
}









