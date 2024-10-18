#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "file_funcs.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();      // Создание нового файла


private:
    Ui::MainWindow *ui;
    FileHandler fileHandler;
    QString currentFilePath;  // Хранение пути к открытому файлу
};

#endif // MAINWINDOW_H
