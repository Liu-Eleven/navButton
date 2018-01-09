#ifndef FORMBUTTON_H
#define FORMBUTTON_H

#include <QWidget>
class NavButton;
namespace Ui {
class formButton;
}

class formButton : public QWidget
{
    Q_OBJECT

public:
    explicit formButton(QWidget *parent = 0);
    ~formButton();

private:
    Ui::formButton *ui;

    QList<NavButton *> btns8;
};

#endif // FORMBUTTON_H
