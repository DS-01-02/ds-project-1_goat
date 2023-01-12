#include "treetraversal.h"
#include "ui_treetraversal.h"
#include "fstream"
#include "string"
#include "QTableWidgetItem"
#include "QString"
#include "QColor"

using namespace std ;

treetraversal::treetraversal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::treetraversal)
{
     ui->setupUi(this);
    this->setGeometry(950,300,138,441);
    fstream file ;
    file.open("order.txt" , ios::in) ;
    string order ;
    QTableWidgetItem * cell;

    while (getline(file,order))
    {
        if (order == "preorder")
        {
            fstream file_order ;
            file_order.open("preorder.txt" , ios::in);
            int row_index = 0 ;
            while(getline(file_order, order))
            {
                cell = new QTableWidgetItem ;
                cell->setText(QString::fromStdString(order));
                ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                ui->tableWidget->setItem(row_index,0, cell);
                if(!cell->text().contains("."))
                {
                    ui->tableWidget->item(row_index,0)->setBackgroundColor(QColor (255, 0, 0) );
                }
                row_index++ ;
            }
             file_order.close();
        }
        else if (order == "inorder")
        {
            fstream file_order ;
            file_order.open("inorder.txt" , ios::in);
            int row_index = 0 ;
            while(getline(file_order, order))
            {
             cell = new QTableWidgetItem ;
             cell->setText(QString::fromStdString(order));
             ui->tableWidget->insertRow(ui->tableWidget->rowCount());
             ui->tableWidget->setItem(row_index,0, cell);
             if(!cell->text().contains("."))
             {
                 ui->tableWidget->item(row_index,0)->setBackgroundColor(QColor (255, 0, 0) );
             }
             row_index++ ;
            }
             file_order.close();
        }
        else if(order == "postorder")
        {
            fstream file_order ;
            file_order.open("postorder.txt" , ios::in);
            int row_index = 0 ;
            while(getline(file_order, order))
            {
                cell = new QTableWidgetItem ;
                cell->setText(QString::fromStdString(order));
                ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                ui->tableWidget->setItem(row_index,0, cell);
                if(!cell->text().contains("."))
                {
                    ui->tableWidget->item(row_index,0)->setBackgroundColor(QColor (255, 0, 0) );
                }
                row_index++ ;
            }
            file_order.close();
        }
    }
   ui->tableWidget->setEnabled(true);
   ui->tableWidget->resizeColumnToContents(0);
}

treetraversal::~treetraversal()
{
    delete ui;
}

void treetraversal::on_back_clicked()
{
    this->hide();
}

