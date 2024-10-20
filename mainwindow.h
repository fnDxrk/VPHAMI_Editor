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

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_actionNew_triggered();       // Создание нового файла
    void on_actionOpen_triggered();    // Открытие файла
    void on_actionSave_triggered();  // Сохранение файла
    void on_actionFind_triggered(); // Поиск в тексте
    void on_actionReplace_triggered(); // Замена в тексте
    void on_actionClear_triggered(); // Очистка текста
    void on_actionUndo_triggered(); // Отмена последнего изменения
    void on_actionRedo_triggered(); // Возврат к последнему изменению
    void on_actionCopy_triggered(); // Копирование текста
    void on_actionPaste_triggered(); // Вставка текста
    void on_actionExit_triggered(); // Закрытие файла

private:
    Ui::MainWindow *ui;
    FileHandler fileHandler;
    QString currentFilePath;  // Хранение пути к открытому файлу
    bool isModified = false;
};

#endif // MAINWINDOW_H
