#ifndef STATSDIALOG_H
#define STATSDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>

#include <registerbank.h>
#include <statistics.h>

class StatsDialog : public QDialog
{
public:
    StatsDialog(QWidget *parent = nullptr);
};

#endif // STATSDIALOG_H
