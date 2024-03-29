#ifndef CHOOSEMODE_H
#define CHOOSEMODE_H

#include <QDialog>
#include "learning.h"
#include "brainstorm.h"

namespace Ui {
class ChooseMode;
}

class rating;
class ChooseMode : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseMode(rating *table, QWidget *parent = nullptr);
    ~ChooseMode();

signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();
   void on_pushButton_2_clicked();

   void on_pushButton_3_clicked();

private:
    Ui::ChooseMode *ui;
    learning *mode1;
    brainstorm *mode2;
    rating *ratingTable;

};

#endif // CHOOSEMODE_H
