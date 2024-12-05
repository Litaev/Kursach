#ifndef FILEDIALOGHANDLER_H
#define FILEDIALOGHANDLER_H

#include <QObject>
#include <QFileDialog>  // Only include this
#include <QString>

class FileDialogHandler : public QObject
{
    Q_OBJECT
public:
    explicit FileDialogHandler(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE QString openFileDialog() {
        QString fileName = QFileDialog::getOpenFileName(nullptr, "Open File", "", "All Files (*)");
        return fileName;
    }

    Q_INVOKABLE QString saveFileDialog() {
        QString fileName = QFileDialog::getSaveFileName(nullptr, "Save File", "", "All Files (*)");
        return fileName;
    }
};

#endif // FILEDIALOGHANDLER_H
