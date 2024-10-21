#include "text_funcs.h"
#include <QClipboard>
#include <QApplication>
#include <QMessageBox>
#include <QTextCursor>

QString EditFunctions::lastContent = "";  // Инициализация переменной для хранения содержимого
bool EditFunctions::isCleared = false;    // Изначально текст не очищен

void EditFunctions::findText(QTextEdit *textEdit, const QString &text)
{
    if (text.isEmpty()) {
        QMessageBox::warning(textEdit, "Warning", "Please enter text to search.");
        return;
    }

    QString documentText = textEdit->toPlainText();

    int index = documentText.indexOf(text, 0, Qt::CaseInsensitive);

    if (index != -1) {
        textEdit->setFocus();

        QTextCursor cursor = textEdit->textCursor();
        cursor.setPosition(index);

        cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, text.length());
        textEdit->setTextCursor(cursor);

        textEdit->ensureCursorVisible();
    } else {
        QMessageBox::information(textEdit, "Search", "Text not found.");
    }
}

void EditFunctions::replaceText(QTextEdit *textEdit, const QString &oldText, const QString &newText) {
    if (!textEdit || oldText.isEmpty()) {
        return;
    }

    QString documentText = textEdit->toPlainText();
    documentText.replace(oldText, newText);
    textEdit->setPlainText(documentText);
}

void EditFunctions::clearText(QTextEdit *textEdit) {
    lastContent = textEdit->toPlainText();
    textEdit->clear();
    isCleared = true;
}

void EditFunctions::undoText(QTextEdit *textEdit) {
    if (isCleared) {
        textEdit->setPlainText(lastContent);
        isCleared = false;
    }
}

void EditFunctions::redoText(QTextEdit *textEdit) {
    if (!lastContent.isEmpty() && !isCleared) {
        textEdit->clear();
        isCleared = true;
    }
}

void EditFunctions::copyText(QTextEdit *textEdit)
{
    textEdit->copy();
}

void EditFunctions::pasteText(QTextEdit *textEdit)
{
    textEdit->paste();
}
