#include "text_funcs.h"
#include <QClipboard>
#include <QApplication>
#include <QMessageBox>
#include <QTextCursor>

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

void EditFunctions::clearText(QTextEdit *textEdit)
{
    textEdit->clear();
}

void EditFunctions::undoText(QTextEdit *textEdit)
{
    textEdit->undo();
}

void EditFunctions::redoText(QTextEdit *textEdit)
{
    textEdit->redo();
}

void EditFunctions::copyText(QTextEdit *textEdit)
{
    textEdit->copy();
}

void EditFunctions::pasteText(QTextEdit *textEdit)
{
    textEdit->paste();
}
