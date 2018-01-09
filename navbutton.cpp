#pragma execution_character_set("utf-8")

#include "navbutton.h"
#include "qpainter.h"
#include "qdebug.h"

NavButton::NavButton(QWidget *parent) : QPushButton(parent)
{
    paddingLeft = 20;
    paddingRight = 5;
    paddingTop = 5;
    paddingBottom = 5;
    textAlign = TextAlign_Left;

    showTriangle = false;
    triangleLen = 5;
    trianglePosition = TrianglePosition_Right;
    triangleColor = QColor(255, 255, 255);

    showIcon = false;
    iconSpace = 10;
    iconSize = QSize(16, 16);
    iconNormal = QPixmap();
    iconHover = QPixmap();
    iconCheck = QPixmap();

    iconPaddingLeft = 0;                //图标左侧间隔 相对于文字
    iconPaddingRight = 20;              //图标右侧间隔 相对于右边距
    iconPaddingTop = 0;                 //图标顶部间隔 相对于顶部
    iconPaddingBottom = 0;              //图标底部间隔
    iconPosition = IconPosition_Left;

    showLine = false;
    lineSpace = 0;
    lineWidth = 5;
    linePosition = LinePosition_Left;
    lineColor = QColor(0, 187, 158);

    normalBgColor = QColor(230, 230, 230);
    hoverBgColor = QColor(130, 130, 130);
    checkBgColor = QColor(80, 80, 80);
    normalTextColor = QColor(100, 100, 100);
    hoverTextColor = QColor(255, 255, 255);
    checkTextColor = QColor(255, 255, 255);

    normalBgBrush = Qt::NoBrush;
    hoverBgBrush = Qt::NoBrush;
    checkBgBrush = Qt::NoBrush;

    hover = false;
    setCheckable(true);
}

void NavButton::enterEvent(QEvent *)
{
    hover = true;
    update();
}

void NavButton::leaveEvent(QEvent *)
{
    hover = false;
    update();
}

void NavButton::paintEvent(QPaintEvent *)
{
    //绘制准备工作,启用反锯齿
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    //绘制背景
    drawBg(&painter);
    //绘制文字
    drawText(&painter);
    //绘制图标
    drawIcon(&painter);
    //绘制边框线条
    drawLine(&painter);
    //绘制倒三角
    drawTriangle(&painter);
}

void NavButton::drawBg(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);

    int width = this->width();
    int height = this->height();

    QRect bgRect;
    if (linePosition == LinePosition_Left) {
        bgRect = QRect(lineSpace, 0, width - lineSpace, height);
    } else if (linePosition == LinePosition_Right) {
        bgRect = QRect(0, 0, width - lineSpace, height);
    } else if (linePosition == LinePosition_Top) {
        bgRect = QRect(0, lineSpace, width, height - lineSpace);
    } else if (linePosition == LinePosition_Bottom) {
        bgRect = QRect(0, 0, width, height - lineSpace);
    }

    //如果画刷存在则取画刷
    QBrush bgBrush;
    if (isChecked()) {
        bgBrush = checkBgBrush;
    } else if (hover) {
        bgBrush = hoverBgBrush;
    } else {
        bgBrush = normalBgBrush;
    }

    if (bgBrush != Qt::NoBrush) {
        painter->setBrush(bgBrush);
    } else {
        //根据当前状态选择对应颜色
        QColor bgColor;
        if (isChecked()) {
            bgColor = checkBgColor;
        } else if (hover) {
            bgColor = hoverBgColor;
        } else {
            bgColor = normalBgColor;
        }

        painter->setBrush(bgColor);
    }

    painter->drawRect(bgRect);

    painter->restore();
}

void NavButton::drawText(QPainter *painter)
{
    painter->save();
    painter->setBrush(Qt::NoBrush);

    //根据当前状态选择对应颜色
    QColor textColor;
    if (isChecked()) {
        textColor = checkTextColor;
    } else if (hover) {
        textColor = hoverTextColor;
    } else {
        textColor = normalTextColor;
    }
#if 0
    QRect textRect = QRect(paddingLeft, paddingTop, width() - paddingLeft - paddingRight - iconSpace, height() - paddingTop - paddingBottom);
    qDebug()<<textRect;

#endif

    QRect textRect ;//= QRect(paddingLeft, paddingTop, width() - paddingLeft - paddingRight, height() - paddingTop - paddingBottom);

    if(IconPosition_Top == iconPosition)
    {
        // （左边距 + 图标左边距 ， 顶边距 + 图标顶边距 + 图标高度 ， 按钮宽 - 左边距 - 图标左边距 - 右边距 - 图标右边距   ， 按钮高 - 文字顶边距 - 图标顶边距 - 图标高 - 图标底边距）
        //textRect = QRect(paddingLeft + iconPaddingLeft, paddingTop + iconPaddingTop+iconSize.height(), width() - paddingLeft-iconPaddingLeft - paddingRight - iconPaddingRight, height() - paddingTop-iconPaddingTop - iconSize.height() - paddingBottom);
         textRect = QRect(0, paddingTop + iconPaddingTop+iconSize.height(), width() , height() - paddingTop-iconPaddingTop - iconSize.height() - paddingBottom);
    }
    else if(IconPosition_Right == iconPosition)
    {
        // （左边距 ， 顶边距 ， 按钮宽 - 右边距 - 图标右边距 - 图标宽  ， 按钮高 - 文字顶边距 - 文字底边距）
        textRect = QRect(paddingLeft, paddingTop, width() - paddingLeft - paddingRight - iconPaddingRight - iconSize.width(), height() - paddingTop - paddingBottom);
    }
    else if(IconPosition_Bottom == iconPosition)
    {
        // （左边距 + 图标左边距 ， 顶边距 + 图标顶边距  ， 按钮宽 - 左边距 - 图标左边距 - 右边距 - 图标右边距   ， 按钮高 - 文字顶边距 - 图标顶边距 - 图标高 - 图标底边距）
        //textRect = QRect(paddingLeft + iconPaddingLeft, paddingTop + iconPaddingTop, width() - paddingLeft-iconPaddingLeft - paddingRight - iconPaddingRight, height() - paddingTop-iconPaddingTop - iconSize.height() - paddingBottom);
        textRect = QRect(0, paddingTop + iconPaddingTop, width() , height() - paddingTop-iconPaddingTop - iconSize.height() - paddingBottom);
    }
    if(IconPosition_Left == iconPosition )
    {
        textRect = QRect(paddingLeft+iconPaddingLeft + iconSize.width(), paddingTop, width() - paddingLeft - paddingRight, height() - paddingTop - paddingBottom);
    }

    painter->setPen(textColor);


    if( (TextAlign_Top == textAlign)
            || (TextAlign_Bottom == textAlign))
    {
        painter->drawText(textRect , textAlign | Qt::AlignHCenter , text());
    }
    else
        painter->drawText(textRect, textAlign | Qt::AlignVCenter, text());

    /*
    if(IconPosition_Top == iconPosition)
    {
        qDebug()<<textRect;
         painter->drawText(textRect ,  Qt::AlignCenter , text());
    }*/

    painter->restore();
}

void NavButton::drawIcon(QPainter *painter)
{
    if (!showIcon) {
        return;
    }

    painter->save();

    QPixmap pix;
    if (isChecked()) {
        pix = iconCheck;
    } else if (hover) {
        pix = iconHover;
    } else {
        pix = iconNormal;
    }

    if (!pix.isNull()) {


        //等比例平滑缩放图标
        pix = pix.scaled(iconSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
#if 0
        painter->drawPixmap(iconSpace, (height() - iconSize.height()) / 2, pix);
#endif
        if(IconPosition_Top == iconPosition)
        {
            painter->drawPixmap( (width()-iconSize.width()) / 2 , iconPaddingTop + paddingTop , pix);

        }
        else if(IconPosition_Right == iconPosition)
        {
            //按钮宽 - 图标右边距 - 图标宽度     垂直居中
            painter->drawPixmap( (width() - iconPaddingRight-iconSize.width()) , (height() - iconSize.height()) / 2, pix);
        }
        else if(IconPosition_Bottom == iconPosition)
        {
            painter->drawPixmap( (width()-iconSize.width()) / 2 , (height() - iconSize.height() - iconPaddingBottom-paddingBottom) , pix);
        }
        if(IconPosition_Left == iconPosition )
        {
            // 图标左边距 + 文字左边距  垂直居中
            painter->drawPixmap(this->iconPaddingLeft+paddingLeft, (height() - iconSize.height()) / 2, pix);
        }
    }

    painter->restore();
}

void NavButton::drawLine(QPainter *painter)
{
    if (!showLine) {
        return;
    }

    if (!isChecked()) {
        return;
    }

    painter->save();

    QPen pen;
    pen.setWidth(lineWidth);
    pen.setColor(lineColor);
    painter->setPen(pen);

    //根据线条位置设置线条坐标
    QPoint pointStart, pointEnd;
    if (linePosition == LinePosition_Left) {
        pointStart = QPoint(0, 0);
        pointEnd = QPoint(0, height());
    } else if (linePosition == LinePosition_Right) {
        pointStart = QPoint(width(), 0);
        pointEnd = QPoint(width(), height());
    } else if (linePosition == LinePosition_Top) {
        pointStart = QPoint(0, 0);
        pointEnd = QPoint(width(), 0);
    } else if (linePosition == LinePosition_Bottom) {
        pointStart = QPoint(0, height());
        pointEnd = QPoint(width(), height());
    }

    painter->drawLine(pointStart, pointEnd);

    painter->restore();
}

void NavButton::drawTriangle(QPainter *painter)
{
    if (!showTriangle) {
        return;
    }

    //选中或者悬停显示
    if (!hover && !isChecked()) {
        return;
    }

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(triangleColor);

    //绘制在右侧中间,根据设定的倒三角的边长设定三个点位置
    int width = this->width();
    int height = this->height();
    int midWidth = width / 2;
    int midHeight = height / 2;

    QPolygon pts;
    if (trianglePosition == TrianglePosition_Left) {
        pts.setPoints(3, triangleLen, midHeight, 0, midHeight - triangleLen, 0, midHeight + triangleLen);
    } else if (trianglePosition == TrianglePosition_Right) {
        pts.setPoints(3, width - triangleLen, midHeight, width, midHeight - triangleLen, width, midHeight + triangleLen);
    } else if (trianglePosition == TrianglePosition_Top) {
        pts.setPoints(3, midWidth, triangleLen, midWidth - triangleLen, 0, midWidth + triangleLen, 0);
    } else if (trianglePosition == TrianglePosition_Bottom) {
        pts.setPoints(3, midWidth, height - triangleLen, midWidth - triangleLen, height, midWidth + triangleLen, height);
    }

    painter->drawPolygon(pts);

    painter->restore();
}

int NavButton::getPaddingLeft() const
{
    return this->paddingLeft;
}

int NavButton::getPaddingRight() const
{
    return this->paddingRight;
}

int NavButton::getPaddingTop() const
{
    return this->paddingTop;
}

int NavButton::getPaddingBottom() const
{
    return this->paddingBottom;
}

NavButton::TextAlign NavButton::getTextAlign() const
{
    return this->textAlign;
}

bool NavButton::getShowTriangle() const
{
    return this->showTriangle;
}

int NavButton::getTriangleLen() const
{
    return this->triangleLen;
}

NavButton::TrianglePosition NavButton::getTrianglePosition() const
{
    return this->trianglePosition;
}

QColor NavButton::getTriangleColor() const
{
    return this->triangleColor;
}

bool NavButton::getShowIcon() const
{
    return this->showIcon;
}

int NavButton::getIconSpace() const
{
    return this->iconSpace;
}

QSize NavButton::getIconSize() const
{
    return this->iconSize;
}

QPixmap NavButton::getIconNormal() const
{
    return this->iconNormal;
}

QPixmap NavButton::getIconHover() const
{
    return this->iconHover;
}

QPixmap NavButton::getIconCheck() const
{
    return this->iconCheck;
}


int NavButton::getIconPaddingLeft() const
{
    return this->iconPaddingLeft;
}
int NavButton::getIconPaddingRight() const
{
    return this->iconPaddingRight;
}
int NavButton::getIconPaddingTop() const
{
    return this->iconPaddingTop;
}
int NavButton::getIconPaddingBottom() const
{
    return this->iconPaddingBottom;
}

NavButton::IconPosition NavButton::getIconPos() const
{
    return this->iconPosition;
}

bool NavButton::getShowLine() const
{
    return this->showLine;
}

int NavButton::getLineSpace() const
{
    return this->lineSpace;
}

int NavButton::getLineWidth() const
{
    return this->lineWidth;
}

NavButton::LinePosition NavButton::getLinePosition() const
{
    return this->linePosition;
}

QColor NavButton::getLineColor() const
{
    return this->lineColor;
}

QColor NavButton::getNormalBgColor() const
{
    return this->normalBgColor;
}

QColor NavButton::getHoverBgColor() const
{
    return this->hoverBgColor;
}

QColor NavButton::getCheckBgColor() const
{
    return this->checkBgColor;
}

QColor NavButton::getNormalTextColor() const
{
    return this->normalTextColor;
}

QColor NavButton::getHoverTextColor() const
{
    return this->hoverTextColor;
}

QColor NavButton::getCheckTextColor() const
{
    return this->checkTextColor;
}

QSize NavButton::sizeHint() const
{
    return QSize(100, 30);
}

QSize NavButton::minimumSizeHint() const
{
    return QSize(20, 10);
}

void NavButton::setPaddingLeft(int paddingLeft)
{
    if (this->paddingLeft != paddingLeft) {
        this->paddingLeft = paddingLeft;
        update();
    }
}

void NavButton::setPaddingRight(int paddingRight)
{
    if (this->paddingRight != paddingRight) {
        this->paddingRight = paddingRight;
        update();
    }
}

void NavButton::setPaddingTop(int paddingTop)
{
    if (this->paddingTop != paddingTop) {
        this->paddingTop = paddingTop;
        update();
    }
}

void NavButton::setPaddingBottom(int paddingBottom)
{
    if (this->paddingBottom != paddingBottom) {
        this->paddingBottom = paddingBottom;
        update();
    }
}

void NavButton::setPadding(int padding)
{
    setPadding(padding, padding, padding, padding);
}

void NavButton::setPadding(int paddingLeft, int paddingRight, int paddingTop, int paddingBottom)
{
    this->paddingLeft = paddingLeft;
    this->paddingRight = paddingRight;
    this->paddingTop = paddingTop;
    this->paddingBottom = paddingBottom;
    update();
}



void NavButton::setIconLeftPadding(int paddingLeft)
{
    if(this->iconPaddingLeft != paddingLeft)
    {
        this->iconPaddingLeft = paddingLeft;
        update();
    }
}
void NavButton::setIconRightPadding(int paddingRight)
{
    if(this->iconPaddingRight != paddingRight)
    {
        this->iconPaddingRight = paddingRight;
        update();
    }
}
void NavButton::setIconTopPadding(int paddingTop)
{
    if(this->iconPaddingTop != paddingTop)
    {
        this->iconPaddingTop = paddingTop;
        update();
    }
}
void NavButton::setIconBottomPadding(int paddingBottom)
{
    if(this->iconPaddingBottom != paddingBottom)
    {
        this->iconPaddingBottom = paddingBottom;
        update();
    }

}
void NavButton::setIconPadding(int padding)
{
    this->iconSpace = padding;

    setPadding(iconSpace , iconSpace , iconSpace , iconSpace);
}
void NavButton::setIconPadding(int paddingLeft, int paddingRight, int paddingTop, int paddingBottom)
{
    this->iconPaddingLeft = paddingLeft;
    this->iconPaddingRight = paddingRight;
    this->iconPaddingTop = paddingTop;
    this->iconPaddingBottom = paddingBottom;
    update();
}

void NavButton::setTextAlign(const NavButton::TextAlign &textAlign)
{
    if (this->textAlign != textAlign) {
        this->textAlign = textAlign;
        update();
    }
}

void NavButton::setShowTriangle(bool showTriangle)
{
    if (this->showTriangle != showTriangle) {
        this->showTriangle = showTriangle;
        update();
    }
}

void NavButton::setTriangleLen(int triangleLen)
{
    if (this->triangleLen != triangleLen) {
        this->triangleLen = triangleLen;
        update();
    }
}

void NavButton::setTrianglePosition(const NavButton::TrianglePosition &trianglePosition)
{
    if (this->trianglePosition != trianglePosition) {
        this->trianglePosition = trianglePosition;
        update();
    }
}

void NavButton::setTriangleColor(const QColor &triangleColor)
{
    if (this->triangleColor != triangleColor) {
        this->triangleColor = triangleColor;
        update();
    }
}

void NavButton::setShowIcon(bool showIcon)
{
    if (this->showIcon != showIcon) {
        this->showIcon = showIcon;
        update();
    }
}

void NavButton::setIconSpace(int iconSpace)
{
    if (this->iconSpace != iconSpace) {
        this->iconSpace = iconSpace;
        update();
    }
}

void NavButton::setIconSize(const QSize &iconSize)
{
    if (this->iconSize != iconSize) {
        this->iconSize = iconSize;
        update();
    }
}

void NavButton::setIconNormal(const QPixmap &iconNormal)
{
    this->iconNormal = iconNormal;
    update();
}

void NavButton::setIconHover(const QPixmap &iconHover)
{
    this->iconHover = iconHover;
    update();
}

void NavButton::setIconCheck(const QPixmap &iconCheck)
{
    this->iconCheck = iconCheck;
    update();
}



void NavButton::setIconPosition(const IconPosition &iconPos)
{
    this->iconPosition = iconPos;
    update();
}

void NavButton::setShowLine(bool showLine)
{
    if (this->showLine != showLine) {
        this->showLine = showLine;
        update();
    }
}

void NavButton::setLineSpace(int lineSpace)
{
    if (this->lineSpace != lineSpace) {
        this->lineSpace = lineSpace;
        update();
    }
}

void NavButton::setLineWidth(int lineWidth)
{
    if (this->lineWidth != lineWidth) {
        this->lineWidth = lineWidth;
        update();
    }
}

void NavButton::setLinePosition(const NavButton::LinePosition &linePosition)
{
    if (this->linePosition != linePosition) {
        this->linePosition = linePosition;
        update();
    }
}

void NavButton::setLineColor(const QColor &lineColor)
{
    if (this->lineColor != lineColor) {
        this->lineColor = lineColor;
        update();
    }
}

void NavButton::setNormalBgColor(const QColor &normalBgColor)
{
    if (this->normalBgColor != normalBgColor) {
        this->normalBgColor = normalBgColor;
        update();
    }
}

void NavButton::setHoverBgColor(const QColor &hoverBgColor)
{
    if (this->hoverBgColor != hoverBgColor) {
        this->hoverBgColor = hoverBgColor;
        update();
    }
}

void NavButton::setCheckBgColor(const QColor &checkBgColor)
{
    if (this->checkBgColor != checkBgColor) {
        this->checkBgColor = checkBgColor;
        update();
    }
}

void NavButton::setNormalTextColor(const QColor &normalTextColor)
{
    if (this->normalTextColor != normalTextColor) {
        this->normalTextColor = normalTextColor;
        update();
    }
}

void NavButton::setHoverTextColor(const QColor &hoverTextColor)
{
    if (this->hoverTextColor != hoverTextColor) {
        this->hoverTextColor = hoverTextColor;
        update();
    }
}

void NavButton::setCheckTextColor(const QColor &checkTextColor)
{
    if (this->checkTextColor != checkTextColor) {
        this->checkTextColor = checkTextColor;
        update();
    }
}

void NavButton::setNormalBgBrush(const QBrush &normalBgBrush)
{
    if (this->normalBgBrush != normalBgBrush) {
        this->normalBgBrush = normalBgBrush;
        update();
    }
}

void NavButton::setHoverBgBrush(const QBrush &hoverBgBrush)
{
    if (this->hoverBgBrush != hoverBgBrush) {
        this->hoverBgBrush = hoverBgBrush;
        update();
    }
}

void NavButton::setCheckBgBrush(const QBrush &checkBgBrush)
{
    if (this->checkBgBrush != checkBgBrush) {
        this->checkBgBrush = checkBgBrush;
        update();
    }
}
