#include "recursionsec4.h"
#include "ui_recursionsec4.h"

recursionSec4::recursionSec4(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::recursionSec4)
{
    ui->setupUi(this);
}

recursionSec4::~recursionSec4()
{
    delete ui;
}

