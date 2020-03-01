#include "widget.h"
#include "ui_widget.h"
#include "rc4.h"

Widget::Widget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Widget)
{
  ui->setupUi(this);
}

Widget::~Widget()
{
  delete ui;
}

void Widget::on_WorkPB_clicked()
{
  QString key = ui->KeyTextLine->text();
  RC4 rc(key.toUtf8());
  if(!ui->SourcesText->toPlainText().isEmpty())
  {
    ui->EncodeText->setText(rc.work(ui->SourcesText->toPlainText().toUtf8()));
  }
  else
  {
    ui->SourcesText->setText(rc.work(ui->EncodeText->toPlainText().toUtf8()));
  }
}
