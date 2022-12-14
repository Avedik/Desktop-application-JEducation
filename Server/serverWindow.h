#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QWidget>
class Server;

namespace Ui {
  class ServerWindow;
}

class ServerWindow : public QWidget
{
    //! Позволяет использовать механизм сигналов и слотов в QT
    Q_OBJECT

    //! Отключает использование конструкторов копии
    //! и операторов присваивания для ServerWindow
    Q_DISABLE_COPY(ServerWindow)

    Ui::ServerWindow *ui;
    Server *m_Server;

public:
    explicit ServerWindow(QWidget* parent = nullptr);
    ~ServerWindow();

private slots:
    //! Регистрирует сообщение в журнале
    void logMessage(const QString& msg);

    void StartServer();
};

#endif // SERVERWINDOW_H
