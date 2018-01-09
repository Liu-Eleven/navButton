#include "formbutton.h"
#include "ui_formbutton.h"
#include "navbutton.h"
#include "iconhelper.h"

formButton::formButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::formButton)
{
    ui->setupUi(this);



    QFont font;
    font.setPixelSize(15);
    font.setBold(true);
    QList<QChar> pixChar;
    pixChar << 0xf2ba << 0xf002 << 0xf013 << 0xf021 << 0xf0e0 << 0xf135;
    //设置背景色为画刷
    QLinearGradient normalBgBrush(0, 0, 0, ui->navButton77_2->height());
    normalBgBrush.setColorAt(0.0, QColor("#3985BF"));
    normalBgBrush.setColorAt(0.5, QColor("#2972A9"));
    normalBgBrush.setColorAt(1.0, QColor("#1C6496"));

    QLinearGradient hoverBgBrush(0, 0, 0, ui->navButton77_2->height());
    hoverBgBrush.setColorAt(0.0, QColor("#4897D1"));
    hoverBgBrush.setColorAt(0.5, QColor("#3283BC"));
    hoverBgBrush.setColorAt(1.0, QColor("#3088C3"));


    QColor normalTextColor = QColor("#FFFFFF");
    QColor hoverTextColor = QColor("#FFFFFF");
    QColor checkTextColor = QColor("#FFFFFF");

    btns8 << ui->navButton77_2 << ui->navButton78_2 << ui->navButton79_2 << ui->navButton80_2 ;
    for (int i = 0; i < btns8.count(); i++) {
        btns8.at(i)->setFont(font);
        btns8.at(i)->setPaddingLeft(20);
        btns8.at(i)->setShowLine(true);

        btns8.at(i)->setTextAlign(NavButton::TextAlign_Left);



        btns8.at(i)->setShowIcon(true);
        btns8.at(i)->setIconSpace(15);
        btns8.at(i)->setIconSize(QSize(50, 50));
        int icon_size = 45;
        int icon_width = 60;
        int icon_height = 60;

        //分开设置图标
        QChar icon = pixChar.at(i+1);
        QPixmap iconNormal = IconHelper::Instance()->getPixmap(normalTextColor.name(), icon, icon_size, icon_width, icon_height);
        QPixmap iconHover = IconHelper::Instance()->getPixmap(hoverTextColor.name(), icon, icon_size, icon_width, icon_height);
        QPixmap iconCheck = IconHelper::Instance()->getPixmap(checkTextColor.name(), icon, icon_size, icon_width, icon_height);

        btns8.at(i)->setIconNormal(iconNormal);
        btns8.at(i)->setIconHover(iconHover);
        btns8.at(i)->setIconCheck(iconCheck);


        btns8.at(i)->setNormalTextColor(normalTextColor);
        btns8.at(i)->setHoverTextColor(hoverTextColor);
        btns8.at(i)->setCheckTextColor(checkTextColor);

        btns8.at(i)->setNormalBgBrush(normalBgBrush);
        btns8.at(i)->setHoverBgBrush(hoverBgBrush);
        btns8.at(i)->setCheckBgBrush(hoverBgBrush);

        //connect(btns8.at(i), SIGNAL(clicked(bool)), this, SLOT(buttonClick7()));
    }
    ui->navButton78_2->setLinePosition(NavButton::LinePosition_Top);
    ui->navButton78_2->setIconPosition(NavButton::IconPosition_Top);
    ui->navButton78_2->setTextAlign(NavButton::TextAlign_Center);

    ui->navButton79_2->setPaddingLeft(15);
    ui->navButton79_2->setLinePosition(NavButton::LinePosition_Right);
    ui->navButton79_2->setIconPosition(NavButton::IconPosition_Right);

    ui->navButton80_2->setLinePosition(NavButton::LinePosition_Bottom);
    ui->navButton80_2->setIconPosition(NavButton::IconPosition_Bottom);
    ui->navButton80_2->setTextAlign(NavButton::TextAlign_Center);

#if 0
    ui->navButton77_2->setShowLine(false);
    ui->navButton77_2->setShowIcon(true);
    ui->navButton77_2->setIconSpace(15);
    ui->navButton77_2->setIconSize(QSize(50, 50));

    int icon_size = 30;
    int icon_width = 60;
    int icon_height = 60;

    //分开设置图标
    QChar icon = pixChar.at(1);
    QPixmap iconNormal = IconHelper::Instance()->getPixmap(normalTextColor.name(), icon, icon_size, icon_width, icon_height);
    QPixmap iconHover = IconHelper::Instance()->getPixmap(hoverTextColor.name(), icon, icon_size, icon_width, icon_height);
    QPixmap iconCheck = IconHelper::Instance()->getPixmap(checkTextColor.name(), icon, icon_size, icon_width, icon_height);

    ui->navButton77_2->setIconNormal(iconNormal);
    ui->navButton77_2->setIconHover(iconHover);
    ui->navButton77_2->setIconCheck(iconCheck);


    ui->navButton77_2->setNormalTextColor(normalTextColor);
    ui->navButton77_2->setHoverTextColor(hoverTextColor);
    ui->navButton77_2->setCheckTextColor(checkTextColor);

    ui->navButton77_2->setNormalBgBrush(normalBgBrush);
    ui->navButton77_2->setHoverBgBrush(hoverBgBrush);
    ui->navButton77_2->setCheckBgBrush(hoverBgBrush);
    ui->navButton77_2->setFont(font);
    ui->navButton77_2->setIconSpace(20);
    ui->navButton77_2->setIconPosition(NavButton::IconPosition_Bottom);
    ui->navButton77_2->setTextAlign(NavButton::TextAlign_Center);
#endif

}

formButton::~formButton()
{
    delete ui;
}
