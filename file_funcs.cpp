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



