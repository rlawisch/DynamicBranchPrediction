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
#include <programcounter.h>
#include <registerbank.h>
#include <pipeline.h>
#include <statistics.h>
#include <statsdialog.h>
#include <twobitpredictor.h>

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
    ProgramCounter* programCounter;
    RegisterBank* registerBank;
    Pipeline* pipeline;
    Statistics* statistics;
    TwoBitPredictor* twoBitPredictor;
    bool usePredictions;

    QMap<QString, QAction*> buttons;

    QString compiledCode;
};
#endif // MAINWINDOW_H
