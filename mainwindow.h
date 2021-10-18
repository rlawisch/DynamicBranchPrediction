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
#include <statistics.h>
#include <statsdialog.h>

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
    void setPrediction(bool checked);

    void updateRunButton();

private:
    QPlainTextEdit *textEdit_;
    ProgramMemory* programMemory;
    Pipeline* pipeline;
    Statistics* statistics;
    bool usePredictions;

    QMap<QString, QAction*> buttons;

    QString compiledCode;
};
#endif // MAINWINDOW_H
