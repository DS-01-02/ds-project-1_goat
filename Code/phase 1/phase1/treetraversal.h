#ifndef TREETRAVERSAL_H
#define TREETRAVERSAL_H

#include <QWidget>

namespace Ui {
class treetraversal;
}

class treetraversal : public QWidget
{
    Q_OBJECT

public:
    explicit treetraversal(QWidget *parent = nullptr);
    ~treetraversal();

private:
    Ui::treetraversal *ui;
};

#endif // TREETRAVERSAL_H
