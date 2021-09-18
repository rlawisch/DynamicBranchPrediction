#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QPlainTextEdit>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>

#include <fileparser.h>
#include <programmemory.h>
#include <registerbank.h>
#include <pipeline.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

signals:
    void fileOpened(QString text);

public slots:
    void saveToFile();
    void loadFile();
    void compileCode();
    void runCode();

private slots:
    void on_readFileButton_clicked();

private:
    QPlainTextEdit *textEdit_;
    ProgramMemory* programMemory;
    RegisterBank *registerBank;
    Pipeline* pipeline;
};
#endif // MAINWINDOW_H
