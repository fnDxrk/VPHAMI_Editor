#include "file_funcs.h"

#include <QFile>
#include <QTextStream>

FileHandler::FileHandler() {}

bool FileHandler::createFile(const QString& filePath) {
    QFile file(filePath);
    if (file.exists()) {
        return false;
    }
    return file.open(QIODevice::WriteOnly);
}

QString FileHandler::openFile(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        return QString();
    }

    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    return content;
}

bool FileHandler::saveFile(const QString& filePath, const QString& content) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        return false;
    }

    QTextStream out(&file);
    out << content;
    file.close();

    return true;
}
