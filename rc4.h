#ifndef RC4_H
#define RC4_H

#include <QString>
#include <QByteArray>

class RC4
{
public:
  RC4(QByteArray key);
  QByteArray work(QByteArray data);
private:
  QByteArray keyItem();

  QByteArray* S;
  int x = 0;
  int y = 0;

};

#endif // RC4_H
