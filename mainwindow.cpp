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

void MainWindow::on_actionOpen_triggered() {
    QString filePath = QFileDialog::getOpenFileName(this, "Open File");
    if (!filePath.isEmpty()) {
        QString content = fileHandler.openFile(filePath);
        if (!content.isEmpty()) {
            currentFilePath = filePath;
            ui->textEdit->setPlainText(content);
        } else {
            QMessageBox::warning(this, "Warning", "Failed to open file!");
        }
    }
}

void MainWindow::on_actionSave_triggered() {
    if (currentFilePath.isEmpty()) {
        currentFilePath = QFileDialog::getSaveFileName(this, "Save File");
    }

    if (!currentFilePath.isEmpty()) {
        QString content = ui->textEdit->toPlainText();
        if (!fileHandler.saveFile(currentFilePath, content)) {
            QMessageBox::warning(this, "Warning", "Failed to save file!");
        }
    }
}







