#ifndef TEXT_FUNCS_H
#define TEXT_FUNCS_H

#include <QTextEdit>

class EditFunctions {
public:
    EditFunctions();
    // Поиск в тексте
    static void findText(QTextEdit *textEdit, const QString &text);

    // Замена в тексте
    static void replaceText(QTextEdit *textEdit, const QString &oldText, const QString &newText);

    // Очистка текста
    static void clearText(QTextEdit *textEdit);

    // Отмена последнего изменения
    static void undoText(QTextEdit *textEdit);

    // Возврат к последнему изменению
    static void redoText(QTextEdit *textEdit);

    // Копирование текста
    static void copyText(QTextEdit *textEdit);

    // Вставка текста
    static void pasteText(QTextEdit *textEdit);
};

#endif // TEXT_FUNCS_H
