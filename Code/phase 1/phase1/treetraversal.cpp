#include "treetraversal.h"
#include "ui_treetraversal.h"

treetraversal::treetraversal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::treetraversal)
{
    ui->setupUi(this);
}

treetraversal::~treetraversal()
{
    delete ui;
}
