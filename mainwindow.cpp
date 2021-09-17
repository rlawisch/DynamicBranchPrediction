#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_readFileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open assembly file"), "", tr("Assembly files (*.asm *.txt"));

    if(fileName != "")
    {
        this->registerBank = new RegisterBank();
        FileParser *fileParser = new FileParser(this->registerBank);
        QList<Instruction*> instructionList = fileParser->parse(fileName);
        delete fileParser;

        this->programMemory = new ProgramMemory(instructionList);
        this->pipeline = new Pipeline(programMemory);
    }
}

