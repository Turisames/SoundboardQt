#ifndef TABBEDSOUNDBOARD_H
#define TABBEDSOUNDBOARD_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <string>

namespace Ui {
class TabbedSoundBoard;
}

class TabbedSoundBoard : public QMainWindow
{
    Q_OBJECT

public:
    explicit TabbedSoundBoard(QWidget *parent = 0);
    ~TabbedSoundBoard();

    void make_sounds_list();
    void play_sound();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

private:
    Ui::TabbedSoundBoard *ui;

    // Omat muuttujat tänne
    QMediaPlayer * soitin;
    QMediaPlaylist * soittolista;
    const std::string PATH{"C:\\Users\\Ville\\Documents\\Koodit\\Qt_koodit\\Soundboard\\"};
    unsigned int volyymi;
};

#endif // TABBEDSOUNDBOARD_H
