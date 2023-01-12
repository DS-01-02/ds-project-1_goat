#ifndef TREE_H
#define TREE_H

#include <QMainWindow>
#include "BinarySearchTree.h"
#include "fstream"
#include "QCompleter"

namespace Ui {
class tree;
}

class tree : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief tree
     * @param parent
     */
    explicit tree(QWidget *parent = nullptr);
    ~tree();
    /**
     * @brief fillingCompletersList_AND_CreatingTree
     */
    void fillingCompletersList_AND_CreatingTree();
    /**
     * @brief warningForOrderCmb
     * @return
     */
    bool warningForOrderCmb ();
    /**
     * @brief warningForInvalidSubfolderName
     * @return
     */
    bool warningForInvalidSubfolderName(string & flag);

private slots:
    /**
     * @brief on_cancel_clicked
     */
    void on_cancel_clicked();
    /**
     * @brief on_ok_clicked
     */
    void on_ok_clicked();

    void on_ln_name_editingFinished();

private:
    Ui::tree *ui;
    QCompleter * sub_folder_completer ;
    QStringList folder_list ;
    Tree * tree_creator ;
    Node * root ;
    Node * subfolder ;
    Tree * new_tr ;
};

#endif // TREE_H
