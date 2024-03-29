#ifndef BRAINSTORM_H
#define BRAINSTORM_H

#include <QDialog>
#include <QGraphicsView>
#include <QPointF>
#include <QColor>
#include <QAbstractSocket>
#include <QMediaCaptureSession>
#include <QAudioInput>
#include <QMediaRecorder>
#include <QTemporaryDir>
#include <QTableWidgetItem>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "painter.h"
#include "dataTypes.h"

namespace Ui {
class brainstorm;
}

class Controller;
class brainstorm : public QDialog
{
    Q_OBJECT

public:
    enum class Instruments { Stylet, Eraser };
    explicit brainstorm(QWidget *parent = nullptr);
    ~brainstorm();
    Instruments getCurrentInstrument();
    void sendPoint(const QPointF& point, qint32 operationCode);

private slots:
    void on_styletButton_clicked();

    void on_eraserButton_clicked();

    void on_clearButton_clicked();
    void receivePoint(const QPointF& point, qint32 operationCode, qint32 senderID);
    void receiveColor(const QColor& color);
    void attemptConnection();
    void connectedToServer();
    void attemptLogin(const QString &userName);
    void loggedIn(const QString& userName);
    void loginFailed(const QString &reason);
    void disconnectedFromServer();
    void userJoined(const QString &username, const QString &meetingID);
    void error(QAbstractSocket::SocketError socketError);
    void refreshUsersQuantity(const QVariantMap& users, const QString& type);
    void receiveFile(DataTypes dataType, const QByteArray &data);

    void on_changeColorButton_clicked();
    void on_recordButton_clicked();

    void on_sendButton_clicked();

    void on_audioFilesBox_cellPressed(int row, int column);

    void on_newMeetingButton_clicked();

    void on_joinButton_clicked();

private:
    void switchEnabled(bool is_enabled);
    void switchButtonEnabled(QPushButton* button, bool is_enabled);

    bool is_connected;
    Instruments currentInstrument;
    Ui::brainstorm *ui;
    Painter *scene;
    Controller *m_Client;
    QString *meetingID = nullptr;
    QMediaCaptureSession *audioSession;
    QAudioInput *audioInput;
    QMediaRecorder *recorder;
    qint32 audioFilesCount;
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    QTemporaryDir *temporaryDir;
};

#endif // BRAINSTORM_H
