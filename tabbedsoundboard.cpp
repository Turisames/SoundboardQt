#include "tabbedsoundboard.h"
#include "ui_tabbedsoundboard.h"

#include <QUrl>
#include <QDebug>

TabbedSoundBoard::TabbedSoundBoard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TabbedSoundBoard)
{
    ui->setupUi(this);

    // Omaa koodia tänne
    soitin = new QMediaPlayer;
    soittolista = new QMediaPlaylist(soitin);
    soittolista->clear();
    volyymi = 100;
    soitin->setVolume(volyymi);

    // Lisätään äänet
    make_sounds_list();

}

TabbedSoundBoard::~TabbedSoundBoard()
{
    delete ui;
}

void TabbedSoundBoard::make_sounds_list()
{
    // Lisätään äänet

    soittolista->addMedia(QUrl("qrc:/sounds/HarbingerVoices/IAmLimitlessYouAreBacteria.wav"));
    soittolista->addMedia(QUrl("qrc:/sounds/HarbingerVoices/YouAreNoLongerRelevant.ogg"));
    soittolista->addMedia(QUrl("qrc:/sounds/HarbingerVoices/AssumingControl.ogg"));
    soittolista->addMedia(QUrl("qrc:/sounds/HarbingerVoices/YouHaveOnlyDelayedTheInevitable.ogg"));
    soittolista->addMedia(QUrl("qrc:/sounds/HarbingerVoices/YouHaveFailed.ogg"));
    soittolista->addMedia(QUrl("qrc:/sounds/HarbingerVoices/YourAttackIsAnInsult.ogg"));
    soittolista->addMedia(QUrl("qrc:/sounds/HarbingerVoices/YouProlongTheInevitable.ogg"));
    soittolista->addMedia(QUrl("qrc:/sounds/HarbingerVoices/IKnowYouFeelThis.ogg"));

    //soitin->setMedia(QUrl("qrc:/sounds/IAmLimitlessYouAreBacteria.wav"));
    qDebug() << "C:\\Users\\Ville\\Documents\\Koodit\\Qt_koodit\\Soundboard\\HarbingerVoices\\ThisIsTruePower.ogg";
}

void TabbedSoundBoard::play_sound()
{
    if(soitin->state() == QMediaPlayer::PlayingState){
        soitin->setPosition(0);
    }else if (soitin->state() == QMediaPlayer::StoppedState){
        soitin->play();
    }
}

void TabbedSoundBoard::on_pushButton_6_clicked()
{
    soittolista->setCurrentIndex(1);

    play_sound();
}

void TabbedSoundBoard::on_pushButton_clicked()
{
    soittolista->setCurrentIndex(0);

    play_sound();
}
