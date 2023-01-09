#include "adding.h"
#include "ui_adding.h"


Adding::Adding(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Adding)
{
    ui->setupUi(this);
    setGeometry(680,400,395,137);
    setFixedSize(395,137);
    ui->add->setEnabled(false);
    ui->ln_date->setEnabled(false);
    fillingCompletersLists();
    date_completer = new QCompleter (date_list,this);
    type_completer = new QCompleter (type_list,this);
    ui->ln_date->setCompleter(date_completer);
    ui->ln_type->setCompleter(type_completer);
    ui->ln_type->setEnabled(false);
    adjustLayout();


}
//Basically it is for adding ui
void Adding::adjustLayout()
{
  setWindowTitle("Adding new File");
}

void Adding::fillingCompletersLists()
{
    for ( int i = 1800 ; i <= 2023 ; i++)
    {
        date_list.append(QString::fromStdString(to_string(i)));
    }

    type_list << "png" << "jpeg" << "jpg" << "gif" << "mp4" << "mov" << "mkv" << "avl" << "wav" << "aiff" << "txt" << "pdf" ;

}

Adding::~Adding()
{
    delete ui;
}

void Adding::on_ln_name_editingFinished()
{
    if(ui->ln_name->text()!= "")
    {
        ui->ln_date->setEnabled(true);
    }
}


void Adding::on_ln_date_editingFinished()
{
    if(ui->ln_date->text().toStdString() != "")
    {
        ui->ln_type->setEnabled(true);
    }
}


void Adding::on_ln_type_editingFinished()
{
    if(ui->ln_type->text().toStdString() != "")
    {
        ui->add->setEnabled(true);
    }
}


//adding => with add_clicked()...


void Adding::on_discard_clicked()
{
    QSize size ;
    QMessageBox  msg ;
    size.setWidth(100);
    size.setHeight(100);
    msg.setFixedSize(size);
    msg.setGeometry(690 , 435 , 200 , 200);
    msg.setStandardButtons(QMessageBox::No |QMessageBox::Discard);
    msg.setDefaultButton(QMessageBox::No);
    msg.setIcon(QMessageBox::Warning);
    msg.setWindowTitle("Warning");
    msg.setText("Are you sure you want to discard changes ?\n");
    int result = msg.exec();
    switch (result)
    {
    case QMessageBox::Discard:
        msg.hide();
        this->close();
        return ;
        break;
    case QMessageBox::No:
        return ;
        break;
        //should never reach
    default:
        break;

    }

}

