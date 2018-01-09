#pragma execution_character_set("utf-8")


#include "frmnavbutton.h"
#include "ui_frmnavbutton.h"
#include "iconhelper.h"
#include "qdebug.h"

frmNavButton::frmNavButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmNavButton)
{
    ui->setupUi(this);
    this->initForm();

    qDebug()<<NavButton::TextAlign_Bottom;

}

frmNavButton::~frmNavButton()
{
    delete ui;
}

void frmNavButton::initForm()
{
    //从图形字体获得图片,也可以从资源文件或者路径文件获取
    QChar icon = 0xf061;
    QPixmap iconNormal = IconHelper::Instance()->getPixmap(QColor(100, 100, 100).name(), icon);
    QPixmap iconHover = IconHelper::Instance()->getPixmap(QColor(255, 255, 255).name(), icon);
    QPixmap iconCheck = IconHelper::Instance()->getPixmap(QColor(255, 255, 255).name(), icon);

    btns1 << ui->navButton11 << ui->navButton12 << ui->navButton13 << ui->navButton14;
    for (int i = 0; i < btns1.count(); i++) {
        btns1.at(i)->setPaddingLeft(32);
        btns1.at(i)->setLineSpace(6);

        btns1.at(i)->setShowIcon(true);
        btns1.at(i)->setIconSpace(15);
        btns1.at(i)->setIconSize(QSize(10, 10));
        btns1.at(i)->setIconNormal(iconNormal);
        btns1.at(i)->setIconHover(iconHover);
        btns1.at(i)->setIconCheck(iconCheck);

        connect(btns1.at(i), SIGNAL(clicked(bool)), this, SLOT(buttonClick1()));
    }

    QList<QChar> pixChar;
    pixChar << 0xf2ba << 0xf002 << 0xf013 << 0xf021 << 0xf0e0 << 0xf135;
    QColor normalBgColor = QColor("#2D9191");
    QColor hoverBgColor = QColor("#187294");
    QColor checkBgColor = QColor("#145C75");
    QColor normalTextColor = QColor("#FFFFFF");
    QColor hoverTextColor = QColor("#FFFFFF");
    QColor checkTextColor = QColor("#FFFFFF");

    btns2 << ui->navButton21 << ui->navButton22 << ui->navButton23 << ui->navButton24;
    for (int i = 0; i < btns2.count(); i++) {
        btns2.at(i)->setPaddingLeft(35);
        btns2.at(i)->setLineSpace(0);
        btns2.at(i)->setLineWidth(8);
        btns2.at(i)->setLineColor(QColor(255, 107, 107));
        btns2.at(i)->setShowTriangle(true);

        btns2.at(i)->setShowIcon(true);
        btns2.at(i)->setIconSpace(10);
        btns2.at(i)->setIconSize(QSize(22, 22));

        //分开设置图标
        QChar icon = pixChar.at(i);
        QPixmap iconNormal = IconHelper::Instance()->getPixmap(normalTextColor.name(), icon, 15, 30, 30);
        QPixmap iconHover = IconHelper::Instance()->getPixmap(hoverTextColor.name(), icon, 15, 30, 30);
        QPixmap iconCheck = IconHelper::Instance()->getPixmap(checkTextColor.name(), icon, 15, 30, 30);

        btns2.at(i)->setIconNormal(iconNormal);
        btns2.at(i)->setIconHover(iconHover);
        btns2.at(i)->setIconCheck(iconCheck);

        btns2.at(i)->setNormalBgColor(normalBgColor);
        btns2.at(i)->setHoverBgColor(hoverBgColor);
        btns2.at(i)->setCheckBgColor(checkBgColor);
        btns2.at(i)->setNormalTextColor(normalTextColor);
        btns2.at(i)->setHoverTextColor(hoverTextColor);
        btns2.at(i)->setCheckTextColor(checkTextColor);

        connect(btns2.at(i), SIGNAL(clicked(bool)), this, SLOT(buttonClick2()));
    }

    normalBgColor = QColor("#292F38");
    hoverBgColor = QColor("#1D2025");
    checkBgColor = QColor("#1D2025");
    normalTextColor = QColor("#54626F");
    hoverTextColor = QColor("#FDFDFD");
    checkTextColor = QColor("#FDFDFD");

    btns3 << ui->navButton31 << ui->navButton32 << ui->navButton33 << ui->navButton34;
    for (int i = 0; i < btns3.count(); i++) {
        btns3.at(i)->setPaddingLeft(35);
        btns3.at(i)->setLineWidth(10);
        btns3.at(i)->setLineColor(QColor("#029FEA"));
        btns3.at(i)->setShowTriangle(true);
        btns3.at(i)->setTextAlign(NavButton::TextAlign_Left);
        btns3.at(i)->setTrianglePosition(NavButton::TrianglePosition_Left);
        btns3.at(i)->setLinePosition(NavButton::LinePosition_Right);

        btns3.at(i)->setShowIcon(true);
        btns3.at(i)->setIconSpace(10);
        btns3.at(i)->setIconSize(QSize(22, 22));

        //分开设置图标
        QChar icon = pixChar.at(i);
        QPixmap iconNormal = IconHelper::Instance()->getPixmap(normalTextColor.name(), icon, 15, 30, 30);
        QPixmap iconHover = IconHelper::Instance()->getPixmap(hoverTextColor.name(), icon, 15, 30, 30);
        QPixmap iconCheck = IconHelper::Instance()->getPixmap(checkTextColor.name(), icon, 15, 30, 30);

        btns3.at(i)->setIconNormal(iconNormal);
        btns3.at(i)->setIconHover(iconHover);
        btns3.at(i)->setIconCheck(iconCheck);

        btns3.at(i)->setNormalBgColor(normalBgColor);
        btns3.at(i)->setHoverBgColor(hoverBgColor);
        btns3.at(i)->setCheckBgColor(checkBgColor);
        btns3.at(i)->setNormalTextColor(normalTextColor);
        btns3.at(i)->setHoverTextColor(hoverTextColor);
        btns3.at(i)->setCheckTextColor(checkTextColor);

        connect(btns3.at(i), SIGNAL(clicked(bool)), this, SLOT(buttonClick3()));
    }

    icon = 0xf105;
    iconNormal = IconHelper::Instance()->getPixmap(QColor(100, 100, 100).name(), icon, 12, 15, 15);
    iconHover = IconHelper::Instance()->getPixmap(QColor(255, 255, 255).name(), icon, 12, 15, 15);
    iconCheck = IconHelper::Instance()->getPixmap(QColor(255, 255, 255).name(), icon, 12, 15, 15);

    btns4 << ui->navButton41 << ui->navButton42 << ui->navButton43 << ui->navButton44;
    for (int i = 0; i < btns4.count(); i++) {
        btns4.at(i)->setLineSpace(10);
        btns4.at(i)->setLineWidth(10);
        btns4.at(i)->setPaddingRight(25);
        btns4.at(i)->setShowTriangle(true);
        btns4.at(i)->setTextAlign(NavButton::TextAlign_Right);
        btns4.at(i)->setTrianglePosition(NavButton::TrianglePosition_Left);
        btns4.at(i)->setLinePosition(NavButton::LinePosition_Right);

        btns4.at(i)->setShowIcon(true);
        btns4.at(i)->setIconSpace(25);
        btns4.at(i)->setIconSize(QSize(15, 15));
        btns4.at(i)->setIconNormal(iconNormal);
        btns4.at(i)->setIconHover(iconHover);
        btns4.at(i)->setIconCheck(iconCheck);

        connect(btns4.at(i), SIGNAL(clicked(bool)), this, SLOT(buttonClick4()));
    }

    QFont font;
    font.setPixelSize(15);
    font.setBold(true);

    normalBgColor = QColor("#292929");
    hoverBgColor = QColor("#064077");
    checkBgColor = QColor("#10689A");
    normalTextColor = QColor("#FFFFFF");
    hoverTextColor = Qt::yellow;
    checkTextColor = QColor("#FFFFFF");

    btns5 << ui->navButton51 << ui->navButton52 << ui->navButton53 << ui->navButton54 << ui->navButton55;
    for (int i = 0; i < btns5.count(); i++) {
        btns5.at(i)->setFont(font);
        btns5.at(i)->setPaddingLeft(20);
        btns5.at(i)->setShowLine(false);
        btns5.at(i)->setTextAlign(NavButton::TextAlign_Center);
        btns5.at(i)->setLinePosition(NavButton::LinePosition_Bottom);

        btns5.at(i)->setShowIcon(true);
        btns5.at(i)->setIconSpace(15);
        btns5.at(i)->setIconSize(QSize(22, 22));

        //分开设置图标
        QChar icon = pixChar.at(i);
        QPixmap iconNormal = IconHelper::Instance()->getPixmap(normalTextColor.name(), icon, 15, 30, 30);
        QPixmap iconHover = IconHelper::Instance()->getPixmap(hoverTextColor.name(), icon, 15, 30, 30);
        QPixmap iconCheck = IconHelper::Instance()->getPixmap(checkTextColor.name(), icon, 15, 30, 30);

        btns5.at(i)->setIconNormal(iconNormal);
        btns5.at(i)->setIconHover(iconHover);
        btns5.at(i)->setIconCheck(iconCheck);

        btns5.at(i)->setNormalBgColor(normalBgColor);
        btns5.at(i)->setHoverBgColor(hoverBgColor);
        btns5.at(i)->setCheckBgColor(checkBgColor);
        btns5.at(i)->setNormalTextColor(normalTextColor);
        btns5.at(i)->setHoverTextColor(hoverTextColor);
        btns5.at(i)->setCheckTextColor(checkTextColor);

        connect(btns5.at(i), SIGNAL(clicked(bool)), this, SLOT(buttonClick5()));
    }

    normalBgColor = QColor("#E6393D");
    hoverBgColor = QColor("#EE0000");
    checkBgColor = QColor("#A40001");
    normalTextColor = QColor("#FFFFFF");
    hoverTextColor = QColor("#FFFFFF");
    checkTextColor = QColor("#FFFFFF");

    btns6 << ui->navButton61 << ui->navButton62 << ui->navButton63 << ui->navButton64 << ui->navButton65;
    for (int i = 0; i < btns6.count(); i++) {
        btns6.at(i)->setFont(font);
        btns6.at(i)->setPaddingLeft(20);
        btns6.at(i)->setShowLine(false);
        btns6.at(i)->setTextAlign(NavButton::TextAlign_Center);
        btns6.at(i)->setLinePosition(NavButton::LinePosition_Bottom);

        btns6.at(i)->setShowIcon(true);
        btns6.at(i)->setIconSpace(15);
        btns6.at(i)->setIconSize(QSize(22, 22));

        //分开设置图标
        QChar icon = pixChar.at(i);
        QPixmap iconNormal = IconHelper::Instance()->getPixmap(normalTextColor.name(), icon, 15, 30, 30);
        QPixmap iconHover = IconHelper::Instance()->getPixmap(hoverTextColor.name(), icon, 15, 30, 30);
        QPixmap iconCheck = IconHelper::Instance()->getPixmap(checkTextColor.name(), icon, 15, 30, 30);

        btns6.at(i)->setIconNormal(iconNormal);
        btns6.at(i)->setIconHover(iconHover);
        btns6.at(i)->setIconCheck(iconCheck);

        btns6.at(i)->setNormalBgColor(normalBgColor);
        btns6.at(i)->setHoverBgColor(hoverBgColor);
        btns6.at(i)->setCheckBgColor(checkBgColor);
        btns6.at(i)->setNormalTextColor(normalTextColor);
        btns6.at(i)->setHoverTextColor(hoverTextColor);
        btns6.at(i)->setCheckTextColor(checkTextColor);

        connect(btns6.at(i), SIGNAL(clicked(bool)), this, SLOT(buttonClick6()));
    }

    //设置背景色为画刷
    QLinearGradient normalBgBrush(0, 0, 0, ui->navButton61->height());
    normalBgBrush.setColorAt(0.0, QColor("#3985BF"));
    normalBgBrush.setColorAt(0.5, QColor("#2972A9"));
    normalBgBrush.setColorAt(1.0, QColor("#1C6496"));

    QLinearGradient hoverBgBrush(0, 0, 0, ui->navButton61->height());
    hoverBgBrush.setColorAt(0.0, QColor("#4897D1"));
    hoverBgBrush.setColorAt(0.5, QColor("#3283BC"));
    hoverBgBrush.setColorAt(1.0, QColor("#3088C3"));

    btns7 << ui->navButton71 << ui->navButton72 << ui->navButton73 << ui->navButton74 << ui->navButton75 << ui->navButton76;
    for (int i = 0; i < btns7.count(); i++) {
        btns7.at(i)->setFont(font);
        btns7.at(i)->setPaddingLeft(0);
        btns7.at(i)->setLineSpace(0);
        btns7.at(i)->setShowTriangle(true);
        btns7.at(i)->setTextAlign(NavButton::TextAlign_Center);
        btns7.at(i)->setTrianglePosition(NavButton::TrianglePosition_Bottom);
        btns7.at(i)->setLinePosition(NavButton::LinePosition_Top);

        btns7.at(i)->setNormalTextColor(normalTextColor);
        btns7.at(i)->setHoverTextColor(hoverTextColor);
        btns7.at(i)->setCheckTextColor(checkTextColor);

        btns7.at(i)->setNormalBgBrush(normalBgBrush);
        btns7.at(i)->setHoverBgBrush(hoverBgBrush);
        btns7.at(i)->setCheckBgBrush(hoverBgBrush);

        connect(btns7.at(i), SIGNAL(clicked(bool)), this, SLOT(buttonClick7()));
    }



    btns8 << ui->navButton77 << ui->navButton78 << ui->navButton79 << ui->navButton80 ;
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

        btns8.at(i)->setAutoExclusive(true);
        btns8.at(i)->setCheckable(true);

        connect(btns8.at(i), SIGNAL(clicked(bool)), this, SLOT(buttonClick8()));
    }
    ui->navButton78->setLinePosition(NavButton::LinePosition_Top);
    ui->navButton78->setIconPosition(NavButton::IconPosition_Top);
    ui->navButton78->setTextAlign(NavButton::TextAlign_Center);

    ui->navButton79->setPaddingLeft(15); //不让左边距变小，文字显示不全
    ui->navButton79->setLinePosition(NavButton::LinePosition_Right);
    ui->navButton79->setIconPosition(NavButton::IconPosition_Right);

    ui->navButton80->setLinePosition(NavButton::LinePosition_Bottom);
    ui->navButton80->setIconPosition(NavButton::IconPosition_Bottom);
    ui->navButton80->setTextAlign(NavButton::TextAlign_Center);



    ui->navButton11->setChecked(true);
    ui->navButton23->setChecked(true);
    ui->navButton31->setChecked(true);
    ui->navButton44->setChecked(true);
    ui->navButton53->setChecked(true);
    ui->navButton61->setChecked(true);
    ui->navButton75->setChecked(true);
}

void frmNavButton::buttonClick1()
{
    NavButton *btn = (NavButton *)sender();
    for (int i = 0; i < btns1.count(); i++) {
        btns1.at(i)->setChecked(btns1.at(i) == btn);
    }
}

void frmNavButton::buttonClick2()
{
    NavButton *btn = (NavButton *)sender();
    for (int i = 0; i < btns2.count(); i++) {
        btns2.at(i)->setChecked(btns2.at(i) == btn);
    }
}

void frmNavButton::buttonClick3()
{
    NavButton *btn = (NavButton *)sender();
    for (int i = 0; i < btns3.count(); i++) {
        btns3.at(i)->setChecked(btns3.at(i) == btn);
    }
}

void frmNavButton::buttonClick4()
{
    NavButton *btn = (NavButton *)sender();
    for (int i = 0; i < btns4.count(); i++) {
        btns4.at(i)->setChecked(btns4.at(i) == btn);
    }
}

void frmNavButton::buttonClick5()
{
    NavButton *btn = (NavButton *)sender();
    for (int i = 0; i < btns5.count(); i++) {
        btns5.at(i)->setChecked(btns5.at(i) == btn);
    }
}

void frmNavButton::buttonClick6()
{
    NavButton *btn = (NavButton *)sender();
    for (int i = 0; i < btns6.count(); i++) {
        btns6.at(i)->setChecked(btns6.at(i) == btn);
    }
}

void frmNavButton::buttonClick7()
{
    NavButton *btn = (NavButton *)sender();
    for (int i = 0; i < btns7.count(); i++) {
        btns7.at(i)->setChecked(btns7.at(i) == btn);
    }
}

void frmNavButton::buttonClick8()
{
     NavButton *btn = (NavButton *)sender();
     btn->setChecked(true);
}
