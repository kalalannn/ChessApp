#ifndef CHESS_LOGIC_H
#define CHESS_LOGIC_H

#include "chess_board.h"

//! QIncludes
#include <QPointer>
#include <QPair>
#include <QChar>

#define WHITE true
#define BLACK false

#define STRAIGHT 1
#define DIAGONAL 2
#define STRAIGHT_ROCKIROVKA 3

//! Chess Logic
class ChessLogic : public QObject {
  Q_OBJECT

public:
	explicit ChessLogic(QObject *parent = nullptr,
	                    QPointer <ChessBoard> board = nullptr);

  //--------SET_METHODS--------//
  void setBoard (QPointer <ChessBoard> board) { m_board = board ;     }
  void setHand (QPoint coordinates)           { m_hand = coordinates; }
  void setPlayer (bool player)                { m_player = player; }
  void changePlayer()                         { m_player = not m_player; }
  void setKing(bool color, QPoint coordinate);
  void setKingWasMoved(int color, bool state);
  void concOutput (QString conc)              { m_output += conc; }
  void concOutput (QChar conc)                { m_output += conc; }


  //--------GET_METHODS--------//
  QPointer <ChessBoard> board()   { return m_board; }
  QChar piece(QPoint coordinates) { return m_board->piece(ChessBoard::index(coordinates)); }
  QPoint hand()                   { return m_hand; }
  bool player()                   { return m_player; }
  QList <QString> history()       { return m_history; }
  QPoint king(bool color);
  bool kingWasMoved(int color);
  QString output()                { return m_output; }

  //--------DEBUG--------------//

  void Debug();
  //--------LOGIC--------------//

  //---------TESTING-----------//
  static QVector <QPoint> getKnightCells(QPoint coordinate);
  static QVector <QPoint> getStraightCells(QPoint coordinate);
  static QVector <QPoint> getDiagonalCells(QPoint coordinate);
  static QVector <QPoint> getKingCells(QPoint coordinate);
  static QVector <QPoint> getCellsToCoordinate(QPoint cell, QPoint attacker);
  QVector <QPoint> cellAttackers(bool color, QPoint cell);
  bool isMat(bool color);
  bool checkCellsToCoordinate(QPoint from, int offset_x, int offset_y, int direction);
  bool canMove(QPoint from, QPoint to);
  bool tryMove(QPoint from, QPoint to, bool color);
  //---------DEVEL-------------//


  bool checkFinalCell(QPoint from, QPoint to, bool color);
  void registerMove (QPoint from, QPoint to, bool sach, bool mat, bool attack, bool, bool,bool);
  QPair <QChar,QChar> transferPos(QPoint coordinate);


  bool getPiece(QPoint coordinate);
  bool putPiece(QPoint coordinate);

signals:
  void onMat(bool color);


private:
	QPointer <ChessBoard> m_board;
	QPoint                m_hand;
	bool                  m_player;
  QPair <QPoint,QPoint> m_kings;
  QPair <bool,bool>     m_king_was_moved;
  QList <QString>       m_history;
  QString               m_output;
};

#endif // CHESS_LOGIC_H
