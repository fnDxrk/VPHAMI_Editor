#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "text_funcs.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QFontDialog>
#include <QDebug>
#include <QSpinBox>
#include <QLabel>
#include <QDialogButtonBox>
#include <QSettings>
#include <QTextTable>

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

void MainWindow::on_actionFind_triggered() {
    QDialog dialog(this);
    dialog.setWindowTitle("Find");

    QLineEdit *findLineEdit = new QLineEdit(&dialog);
    QLabel *label = new QLabel("Enter text to find:", &dialog);
    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, &dialog);

    QVBoxLayout *layout = new QVBoxLayout(&dialog);
    layout->addWidget(label);
    layout->addWidget(findLineEdit);
    layout->addWidget(buttonBox);

    connect(buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted) {
        QString text = findLineEdit->text().trimmed();

        if (!text.isEmpty()) {
            EditFunctions::findText(ui->textEdit, text);
        } else {
            QMessageBox::warning(this, "Warning", "Please enter text to search.");
        }
    }
}

void MainWindow::on_actionReplace_triggered() {
    QDialog dialog(this);
    dialog.setWindowTitle("Replace");

    QLineEdit *oldTextLineEdit = new QLineEdit(&dialog);
    QLineEdit *newTextLineEdit = new QLineEdit(&dialog);
    QLabel *labelOld = new QLabel("Enter text to replace:", &dialog);
    QLabel *labelNew = new QLabel("Enter new text:", &dialog);
    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, &dialog);

    QVBoxLayout *layout = new QVBoxLayout(&dialog);
    layout->addWidget(labelOld);
    layout->addWidget(oldTextLineEdit);
    layout->addWidget(labelNew);
    layout->addWidget(newTextLineEdit);
    layout->addWidget(buttonBox);

    connect(buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted) {
        QString oldText = oldTextLineEdit->text();
        QString newText = newTextLineEdit->text();

        if (!oldText.isEmpty() && !newText.isEmpty()) {
            EditFunctions::replaceText(ui->textEdit, oldText, newText);
        }
    }
}

void MainWindow::on_actionClear_triggered() {
    EditFunctions::clearText(ui->textEdit);
}

void MainWindow::on_actionUndo_triggered() {
    EditFunctions::undoText(ui->textEdit);
}

void MainWindow::on_actionRedo_triggered() {
    EditFunctions::redoText(ui->textEdit);
}

void MainWindow::on_actionCopy_triggered() {
    EditFunctions::copyText(ui->textEdit);
}

void MainWindow::on_actionPaste_triggered() {
    EditFunctions::pasteText(ui->textEdit);
}

