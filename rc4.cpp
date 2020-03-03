#include "rc4.h"
#include <QByteArray>

//Конструктор
RC4::RC4(QByteArray key)
{
  //Инициализируем последовательность на основе ключа
  //KSA
  S = new QByteArray[256];
  for (int i(0); i < 256; i++)
  {
    QString chr;
    chr.setNum(i);
    S[i] = chr.toUtf8();
  }

  int j = 0;
  for (int i(0); i < 256; i++)
  {
    j = (j + S[i].toInt() + key[i%key.size()])%256;
    QString temp(S[i]);
    S[i] = S[j];
    S[j] = temp.toUtf8();
  }
}

//Метод шифровки и дишифровки
QByteArray RC4::work(QByteArray data)
{
  QByteArray result;
  QString chr;
  for (auto && i : data)
  {
   chr = (i ^ keyItem().back());
   result.push_back(chr.toUtf8());
  }
  return result;
}

//Метод генерации псевдослучайного слова
//PRGA
QByteArray RC4::keyItem()
{
  x = (x + 1) % 256;
  y = (y + S[x].toInt()) % 256;
  QString temp(S[x]);
  S[x] = S[y];
  S[y] = temp.toUtf8();

  return S[(S[x].toInt() + S[y].toInt()) % 256];
}
