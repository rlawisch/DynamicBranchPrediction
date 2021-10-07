#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    textEdit_ = new QPlainTextEdit(this);
    textEdit_->setStyleSheet("padding: 10px;");

    QToolBar *toolBar = new QToolBar(this);
    toolBar->setStyleSheet("QToolBar{spacing: 6px;}");

    QAction *save    = toolBar->addAction(QIcon(":/images/save"   ), "Save"      );
    QAction *load    = toolBar->addAction(QIcon(":/images/load"   ), "Load"      );
    toolBar->addSeparator();
    QAction *compile = toolBar->addAction(QIcon(":/images/compile"), "Compile"   );
    QAction *run     = toolBar->addAction(QIcon(":/images/run"    ), "Run"       );
    toolBar->addSeparator();
    QAction *stats   = toolBar->addAction(QIcon(":/images/stats"  ), "Statistics");

    run->setEnabled(false);

    buttons.insert("save"   , save   );
    buttons.insert("load"   , load   );
    buttons.insert("compile", compile);
    buttons.insert("run"    , run    );
    buttons.insert("stats"  , stats  );

    connect(save   , SIGNAL(triggered()), this, SLOT(saveToFile() ));
    connect(load   , SIGNAL(triggered()), this, SLOT(loadFile()   ));
    connect(compile, SIGNAL(triggered()), this, SLOT(compileCode()));
    connect(run    , SIGNAL(triggered()), this, SLOT(runCode()    ));

    connect(textEdit_, SIGNAL(textChanged()), this, SLOT(updateRunButton()));

    this->setCentralWidget(textEdit_);
    this->addToolBar(toolBar);
}

void MainWindow::saveToFile()
{
    qDebug() << "Saving to file...";

    QString fileName = QFileDialog::getSaveFileName(this, "Save file", "C:/");
    if(fileName.isEmpty())
        return;

    if(!fileName.endsWith(".txt"))
        fileName.append(".txt");

    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream output(&file);
    output << textEdit_->toPlainText();

    file.close();
}

void MainWindow::loadFile()
{
    qDebug() << "Loading file...";

    QString fileName = QFileDialog::getOpenFileName(this, "Load file", "C:/");
    if(fileName.isEmpty())
        return;

    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream input(&file);
    textEdit_->setPlainText(input.readAll());

    file.close();
}

void MainWindow::compileCode()
{
    qDebug() << "Compiling code...";

    this->registerBank = new RegisterBank();
    FileParser *fileParser = new FileParser(this->registerBank);

    QList<Instruction*> instructionList = fileParser->parse(textEdit_->toPlainText());
    delete fileParser;

    this->programMemory = new ProgramMemory(instructionList);
    this->pipeline = new Pipeline(programMemory);

    compiledCode = textEdit_->toPlainText();

    buttons["run"]->setEnabled(true);
}

void MainWindow::runCode()
{

    this->pipeline->run();
}

void MainWindow::updateRunButton()
{
    if(compiledCode == textEdit_->toPlainText())
        buttons["run"]->setEnabled(true);
    else
        buttons["run"]->setEnabled(false);
}
