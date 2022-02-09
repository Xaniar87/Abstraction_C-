#ifndef RECURSIONSEC4_H
#define RECURSIONSEC4_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class recursionSec4; }
QT_END_NAMESPACE

class recursionSec4 : public QMainWindow
{
    Q_OBJECT

public:
    recursionSec4(QWidget *parent = nullptr);
    ~recursionSec4();

private:
    Ui::recursionSec4 *ui;
};
#endif // RECURSIONSEC4_H
