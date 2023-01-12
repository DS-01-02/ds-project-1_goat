#include "tree.h"
#include "ui_tree.h"
#include "mainwindow.h"
#include "treetraversal.h"

tree::tree(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tree)
{
    ui->setupUi(this);
    this->setGeometry(700,400,342,101);
    setFixedSize(342,101);
    setWindowTitle("Tree Traversal");
    root = nullptr ;
    subfolder = nullptr ;
    new_tr = new Tree ;
    fillingCompletersList_AND_CreatingTree();
    sub_folder_completer = new QCompleter(folder_list, this) ;
    tree_creator = new Tree();
    ui->ln_name->setCompleter(sub_folder_completer);
    ui->ok->setEnabled(false);



}

tree::~tree()
{
    delete ui;
}


void tree::fillingCompletersList_AND_CreatingTree()
{

    fstream Subfolder_for_completer_in_phase3 ;
    Subfolder_for_completer_in_phase3.open("sub.txt" , ios::in);
    if(Subfolder_for_completer_in_phase3.is_open())
    {
        string line ;
        while(getline(Subfolder_for_completer_in_phase3 , line ))
        {
            folder_list.append(QString::fromStdString(line)) ;
        }
    }
    else
    {
        cerr << "Could not open the file for making tree\n";
    }
    Subfolder_for_completer_in_phase3.close() ;
}


void tree::on_cancel_clicked()
{
    //First time to close a page ;
    this->close();

}


void tree::on_ok_clicked()
{
    QSize size ;
    QMessageBox  msg ;
    size.setWidth(200);
    size.setHeight(75);
    msg.setFixedSize(size);
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setDefaultButton(QMessageBox::Ok);
    msg.setIcon(QMessageBox::Critical);
    msg.setWindowTitle("Error");

    bool cmb_check = warningForOrderCmb();
    string flag = " " ;
    bool ln_check = warningForInvalidSubfolderName(flag);
    if (cmb_check && ln_check)
    {

        //preorder traversal
        Node * sub_folder = new_tr->findSubfolder(ui->ln_name->text().toStdString());
        if(ui->comboBox->currentText().toStdString() == "preorder")
        {
            new_tr->preorder(sub_folder) ;
        }
        //postorder traversal
        if(ui->comboBox->currentText().toStdString() == "postorder")
        {
            new_tr->postorder(sub_folder);
        }
        //inorder
        if(ui->comboBox->currentText().toStdString() == "inorder")
        {
            new_tr->inorder(sub_folder);
        }


        //inorder traversal
        //tree_creator->inorder(root , folder_list.size()+1);
        //  tree_creator->TreeInorder(root->child->next->next->next);

        fstream file ;
        file.open("order.txt",ios::out) ;
        if(file.is_open())
        {
            file << ui->comboBox->currentText().toStdString() << endl;
        }
        file.close();
        treetraversal * traversal = new treetraversal ;
        traversal->show() ;
        this->close();
    }
    else if (!ln_check)
    {
        if(flag.length()==0)
        {
            msg.setText("Name field is empty!!");
            msg.setInformativeText("Please fill out the form completely.");
        }
        else
        {
            msg.setText("Invalid name !!");
            msg.setInformativeText("Please fill out the form properly.");
        }
        int result = msg.exec();
        switch (result)
        {
        case QMessageBox::Ok:
            msg.hide();
            return ;
            break;
            //should never reach
        default:
            break;
        }

    }
    else if (!cmb_check)
    {
        msg.setText("You haven't chosen any orders !!");
        msg.setInformativeText("Please choose an order.");
        int result = msg.exec();
        switch (result)
        {
        case QMessageBox::Ok:
            msg.hide();
            return ;
            break;
            //should never reach
        default:
            break;
        }

    }
}


void tree::on_ln_name_editingFinished()
{
    if(ui->ln_name->text().toUtf8() != "")
    {
        ui->ok->setEnabled(true);
    }
}

bool tree::warningForOrderCmb()
{
    if(ui->comboBox->currentText().toUtf8() == "order...")
    {
        return false;
    }
    return true ;
}

bool tree::warningForInvalidSubfolderName(string &flag)
{
    flag = ui->ln_name->text().toStdString();
    if(!folder_list.contains(ui->ln_name->text()))
    {
        return false ;
    }
    return true ;
}

