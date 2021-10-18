#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->usePredictions = true;
    this->statistics = Statistics::GetInstance();

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
    QAction *prediction = toolBar->addAction(QIcon(":images/setPrediction"), "Set Prediction");

    run->setEnabled(false);
    prediction->setCheckable(true);

    buttons.insert("save"      , save      );
    buttons.insert("load"      , load      );
    buttons.insert("compile"   , compile   );
    buttons.insert("run"       , run       );
    buttons.insert("prediction", prediction);

    connect(save      , SIGNAL(triggered(    )), this, SLOT(saveToFile()   ));
    connect(load      , SIGNAL(triggered(    )), this, SLOT(loadFile()     ));
    connect(compile   , SIGNAL(triggered(    )), this, SLOT(compileCode()  ));
    connect(run       , SIGNAL(triggered(    )), this, SLOT(runCode()      ));
    connect(prediction, SIGNAL(toggled  (bool)), this, SLOT(setPrediction(bool)));

    connect(textEdit_, SIGNAL(textChanged()), this, SLOT(updateRunButton()));

    this->setCentralWidget(textEdit_);
    this->setWindowTitle("BRTL Pipeline");
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

    FileParser *fileParser = new FileParser();

    QList<Instruction*> instructionList = fileParser->parse(textEdit_->toPlainText());
    delete fileParser;

    this->programMemory = new ProgramMemory(instructionList);
    this->pipeline = new Pipeline(programMemory, this->usePredictions);

    compiledCode = textEdit_->toPlainText();

    buttons["run"]->setEnabled(true);
}

void MainWindow::runCode()
{
    this->pipeline->run();

    StatsDialog *dialog = new StatsDialog(this);

    dialog->exec();
}

void MainWindow::setPrediction(bool checked)
{
    this->usePredictions = checked;
    qDebug() << this->usePredictions;
}

void MainWindow::updateRunButton()
{
    if(compiledCode == textEdit_->toPlainText())
        buttons["run"]->setEnabled(true);
    else
        buttons["run"]->setEnabled(false);
}
