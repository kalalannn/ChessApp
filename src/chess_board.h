#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

//! Constants
#define SIZE 8

//! QIncludes
#include <QObject>
#include <QVector>
#include <QPoint>

//! C++11 includes
#include <iostream>

//! Chess Board abstraction
class ChessBoard : public QObject {
  Q_OBJECT

public:
  explicit ChessBoard(QObject *parent = nullptr);

  //! Create a new board and set default figures
  void new_board();

  //! Map function for QVector [0-7][0-7]
  static int index(QPoint coordinates){ return (coordinates.y() * SIZE) + coordinates.x(); }

  //! Get/Move char from index/to index
  QChar piece(int index) { return m_board[index]; }
  void move(int index_from, int index_to);

  //! Print a state of a board
  void print();

  //---------NOT_IMPLEMENTED-------------//

private:
	QVector <QChar> m_board;
};

#endif // CHESS_BOARD_H