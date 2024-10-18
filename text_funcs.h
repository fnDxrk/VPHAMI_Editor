#ifndef TEXT_FUNCS_H
#define TEXT_FUNCS_H

#include <QTextEdit>

class EditFunctions {
public:
    EditFunctions();
    // Поиск в тексте
    static void findText(QTextEdit *textEdit, const QString &text);

    // Очистка текста
    static void clearText(QTextEdit *textEdit);

    //Отмена последнего изменения
    static void undoText(QTextEdit *textEdit);

    //Возврат к последнему изменению
    static void redoText(QTextEdit *textEdit);
};

#endif // TEXT_FUNCS_H
