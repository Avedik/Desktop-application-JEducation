#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QImage>
#include <QPointF>
#include <QColor>
#include "dataTypes.h"

class QHostAddress;
class QJsonDocument;
class Controller : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Controller)

public:
    explicit Controller(QObject *parent = nullptr);
public slots:
    void connectToServer(const QHostAddress &address, quint16 port);
    void login(const QString &userName);
    void chooseMeeting(const QString &ID);
    void sendMessage(const QString &text);
    void sendImage(const QImage& image);
    void sendPoint(const QPointF& point, qint32 operationCode);
    void sendColor(const QColor& color);
    void sendQuestion(const QString &destUser, const QString &text);
    void sendScore(const QString &destUser, qint32 score);
    void sendAnswer(const QString &source, const QString &question, const QString &answer);
    void sendFile(DataTypes dataType, const QByteArray &data);
    void disconnectFromHost();

private slots:
    void onReadyRead();

signals:
    void connected();
    void loggedIn(const QString& userName);
    void loginError(const QString &reason);
    void disconnected();
    void messageReceived(const QString &sender, const QString &text);
    void scoreReceived(const QString &destUser, qint32 score);
    void questionReceived(const QString &sender, const QString &text);
    void answerReceived(const QString &from, const QString &to, const QString &ques, const QString &ans);
    void refreshUsersList(const QVariantMap& users, const QString& type);
    void error(QAbstractSocket::SocketError socketError);
    void userJoined(const QString &username, const QString &meetingID);
    void userLeft(const QString &username);
    void receiveImage(const QImage& image, const QString& source);
    void receivePoint(const QPointF& point, qint32 operationCode, qint32 senderID);
    void receiveColor(const QColor& color);
    void receiveFile(DataTypes dataType, const QByteArray &data);
private:
    QTcpSocket *m_clientSocket;
    bool m_loggedIn;
    void jsonReceived(const QJsonObject &doc);
};

#endif
