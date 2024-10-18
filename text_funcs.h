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
};

#endif // TEXT_FUNCS_H
