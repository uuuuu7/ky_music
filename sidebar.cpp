/*
 * Copyright (C) 2020, KylinSoft Co., Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "sidebar.h"
#include "musicDataBase.h"
#include "mainwid.h"
#include <QDebug>
#include <QMessageBox>

SideBar::SideBar(QWidget *parent) : QFrame(parent)
{
    setFixedWidth(210);

    this->setObjectName("SideBar");

    initTopWidget();
    sidecolor();
}

void SideBar::sidecolor()
{
    if(WidgetStyle::themeColor == 1)
    {
        PlayListBtn->setIcon(QIcon(":/img/default/songlist_w .png"));

        setStyleSheet("#SideBar{width: 210px;\
                      background: #1F2022;\
                      border-top-left-radius: 12px;border-bottom-left-radius:12px;}");

        logoLabel->setStyleSheet("border-image:url(:/img/kylin-music-logo.png);"
                                 "width:24px;height:24;");

        logoNameLabel->setStyleSheet("width: 56px;\
                                     height: 20px;\
                                     font-size: 14px;\
                                     font-family: PingFangSC-Medium, PingFang SC;\
                                     font-weight: 500;\
                                     color: #F9F9F9;\
                                     line-height: 20px;");
        recommendLabel->setStyleSheet("font-size: 14px;margin-left:26px;\
                                       \
                                      font-weight: 400;\
                                      border:none;\
                                      color: #8F9399;\
                                      line-height: 14px;"
                                        );
        PlayListBtn->setStyleSheet("QToolButton{padding-left:15px;margin-left:14px;\
                                   font-size: 14px;\
                                    \
                                   background:#3790FA;\
                                   color:#FFFFFF;border-radius:16px;}"
                                    "QToolButton::hover{background:#40A9FB;}"
                                    "QToolButton::pressed{background:#296CD9;}");

        MySongListLabel->setStyleSheet("font-size: 14px;margin-left:26px;\
                                \
                               color: #8F9399;\
                               line-height: 14px;");

        addSongListBtn->setStyleSheet("border-radius:4px;}"
                                      "QPushButton::hover{color:#8F9399;}"
                                      "QPushButton::pressed{color:#606265;}");

        songListWidget->setStyleSheet("QListWidget{background-color:#1F2022;border:0px;}"
                                      "QListWidget::item:selected{background-color:#1F2022;}"
                                      "QListWidget::item:hover{background-color:#1F2022;}"
                                      "QListWidget::item:pressed{background-color:#1F2022;}");
        songListWidget->setContentsMargins(20,20,20,20);
    }
    else if(WidgetStyle::themeColor == 0)
    {
        PlayListBtn->setIcon(QIcon(":/img/default/songlist_w .png"));

        setStyleSheet("#SideBar{width: 210px;\
                      background: #FAFAFA;\
                      border-top-left-radius: 12px;border-bottom-left-radius:12px;}");
        logoLabel->setStyleSheet("border-image:url(:/img/kylin-music-logo.png);");
        logoNameLabel->setStyleSheet("width: 56px;\
                                     height: 20px;\
                                     font-size: 14px;\
                                     font-family: PingFangSC-Medium, PingFang SC;\
                                     font-weight: 500;\
                                     color: #303133;\
                                     line-height: 20px;");

        recommendLabel->setStyleSheet("font-size: 14px;margin-left:26px;\
                                       \
                                      font-weight: 400;\
                                      border:none;\
                                      color: #8F9399;\
                                      line-height: 14px;"
                                        );
        PlayListBtn->setStyleSheet("QToolButton{padding-left:15px;margin-left:14px;\
                                 font-size: 14px;\
                                  \
                                 background:#3790FA;\
                                 color:#FFFFFF;border-radius:16px;}"
                                  "QToolButton::hover{background:#40A9FB;}"
                                  "QToolButton::pressed{background:#296CD9;}");
        MySongListLabel->setStyleSheet("font-size: 14px;margin-left:26px;\
                                \
                               color: #8F9399;\
                               line-height: 14px;");
        addSongListBtn->setStyleSheet("border-radius:4px;}"
                                      "QPushButton::hover{color:#8F9399;}"
                                      "QPushButton::pressed{color:#606265;}");

        songListWidget->setStyleSheet("QListWidget{background-color:#FAFAFA;border:0px;}"
                                      "QListWidget::item:selected{background-color:#FAFAFA;}"
                                      "QListWidget::item:hover{background-color:#FAFAFA;}"
                                      "QListWidget::item:pressed{background-color:#FAFAFA;}");

        }
}

void SideBar::initTopWidget()
{

    QVBoxLayout *sideBarLayout = new QVBoxLayout(this);

    QHBoxLayout *logoLayout = new QHBoxLayout(this);
    logoLabel = new QPushButton(this);
    logoNameLabel = new QLabel(this);
    logoNameLabel->setFixedSize(59,20);
//    logoNameLabel->setText("????????????");
    logoNameLabel->setText(tr("Kylin music"));
    //    logoLabel->setGeometry(40,20,100,30);
    logoLabel->setFixedSize(24,24);
    logoLabel->setIconSize(QSize(24,24));
    logoLayout->addWidget(logoLabel,Qt::AlignLeft);
    logoLayout->setSpacing(8);
    logoLayout->addWidget(logoNameLabel,0,Qt::AlignLeft);
    logoLayout->setContentsMargins(8,8,0,0);

    recommendLabel = new QLabel(this);
//    recommendLabel->setText("?????????");
    recommendLabel->setText(tr("Music library"));
    recommendLabel->setGeometry(38,73,45,20);

    PlayListBtn = new QToolButton(this);
//    PlayListBtn->setGeometry(16,99,180,32);
    PlayListBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    PlayListBtn->setIconSize(QSize(16,16));
//    PlayListBtn->setText(tr("????????????"));
    PlayListBtn->setText(tr("The song list"));
    PlayListBtn->setFixedSize(180,32);

    QHBoxLayout *addSongListLayout = new QHBoxLayout(this);
    MySongListLabel = new QLabel(this);

    addSongListBtn = new QPushButton(this);
    MySongListLabel->setGeometry(38,161,56,16);
//    MySongListLabel->setText("????????????");
    MySongListLabel->setText(tr("My song list"));


//    addSongListBtn->setGeometry(100,161,16,16);
    addSongListBtn->setFixedSize(16,16);
    addSongListBtn->setIcon(QIcon::fromTheme("list-add-symbolic"));
//    addSongListBtn->setIcon(QIcon(":/img/default/add.png"));

    addSongListLayout->addWidget(MySongListLabel);
    addSongListLayout->addWidget(addSongListBtn);
    addSongListLayout->addSpacing(20);

//    addSongListBtn->hide();   //????????????????????????

    songListWidget = new QListWidget(this);
//    songListWidget->setFrameShape(QListWidget::NoFrame);
//    songListWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    songListWidget->setFocusPolicy(Qt::NoFocus);

    QWidget *logoWid = new QWidget(this);
    logoWid->setFixedSize(100, 40);
    logoWid->setLayout(logoLayout);
//    logoWid->setGeometry(8,8,82,24);

    sideBarLayout->addWidget(logoWid);
    sideBarLayout->addSpacing(15);
    sideBarLayout->addWidget(recommendLabel);
    sideBarLayout->addSpacing(5);
    sideBarLayout->addWidget(PlayListBtn);
    sideBarLayout->addSpacing(15);
    sideBarLayout->addLayout(addSongListLayout);
    sideBarLayout->addWidget(songListWidget);

    sideBarLayout->setMargin(0);

    this->setLayout(sideBarLayout);

    newSonglistPup = new AllPupWindow(this);
//    newSonglistPup->titleLab->setText("????????????");
    newSonglistPup->titleLab->setText(tr("The new song list"));
    newSonglistPup->pupDialog->hide();

    connect(addSongListBtn, SIGNAL(clicked(bool)), this, SLOT(addSongList()));                    //??????????????????
    connect(newSonglistPup->confirmBtn,SIGNAL(clicked(bool)),this,SLOT(addItemToSongList()));
    connect(newSonglistPup->enterLineEdit,SIGNAL(returnPressed()),this,SLOT(addItemToSongList()));

    //????????????????????????????  stackWid->setCurrentIndex(1);
    promptSongListPup = new AllPupWindow(this);
//    promptSongListPup->titleLab->setText(tr("??????"));
    promptSongListPup->titleLab->setText(tr("prompt"));
    promptSongListPup->enterLineEdit->hide();

    //?????????????????????????  stackWid->setCurrentIndex(2);
    promptRenamePlayList = new AllPupWindow(this);
//    promptRenamePlayList->titleLab->setText(tr("????????????"));
    promptRenamePlayList->titleLab->setText(tr("Prompt information"));
    promptRenamePlayList->enterLineEdit->hide();

    //???????????????
    renameSongListPup = new AllPupWindow(this);
//    renameSongListPup->titleLab->setText(tr("?????????"));
    renameSongListPup->titleLab->setText(tr("rename"));
    renameSongListPup->pupDialog->hide();

    //???????????????   stackWid->setCurrentIndex(3);
    promptExistListPup = new AllPupWindow(this);
//    promptExistListPup->titleLab->setText(tr("????????????"));
    promptExistListPup->titleLab->setText(tr("Prompt information"));
    promptExistListPup->enterLineEdit->hide();

    //???????????????????????????  stackWid->setCurrentIndex(4);
    promptRemovePlayList = new AllPupWindow(this);
//    promptRemovePlayList->titleLab->setText(tr("????????????"));
    promptRemovePlayList->titleLab->setText(tr("Prompt information"));
    promptRemovePlayList->enterLineEdit->hide();

    rightChangeWid = new QStackedWidget(this);

    createSongList();
}

void SideBar::on_musicListChangeWid_customContextMenuRequested(const QPoint &pos)
{
    int ret;
//    qDebug()<<currentSelectList;
//    qDebug()<<musicListChangeWid[currentSelectList]->musicInfoWidget->count();
    if(musicListChangeWid[currentSelectList]->musicInfoWidget->count() <= 0)
    {
        QListWidgetItem *curItem1 = musicListChangeWid[currentPlayList]->musicInfoWidget->itemAt(pos);

        if(curItem1 == NULL)
        {
            return;
        }
    }
    menu = new QMenu(musicListChangeWid[currentSelectList]->musicInfoWidget);
    listPlayAct = new QAction(this);
    listNextAct = new QAction(this);
    listDeleAct = new QAction(this);
    listSongAct = new QAction(this);

    listPlayAct->setText(tr("play"));   //??????
    listNextAct->setText(tr("The following piece"));   //?????????
    listDeleAct->setText(tr("Delete the next song from the playlist"));  //??????????????????
    listSongAct->setText(tr("Song information")); //????????????

    QMenu *menu5 = new QMenu(this);
    menu5->setTitle(tr("Add to playlist"));    //???????????????
    QStringList playListNameList;

    ret = g_db->getPlayList(playListNameList);
    if(ret == DB_OP_SUCC)
    {
        for(int i = 0;i< playListNameList.size();i++)
        {

            QString listName = playListNameList.at(i);
            QAction *listaction = new QAction(this);
            listaction->setData(i);
            listaction->setText(listName);
            menu5->addAction(listaction);
        }
    }
//    menu->addAction(listPlayAct);
//    menu->addAction(listNextAct);
    menu->addMenu(menu5);
    menu->addAction(listDeleAct);
    menu->addAction(listSongAct);
//    connect(listPlayAct,&QAction::triggered,this,&SideBar::listPlayAct_slot);   //jialin
//    connect(listNextAct,&QAction::triggered,this,&SideBar::listNextAct_slot);
    connect(menu5,SIGNAL(triggered(QAction*)),this,SLOT(addMusicToPlayList(QAction*)));
    connect(listDeleAct,&QAction::triggered,this,&SideBar::deleteMusicFromSongList);
    connect(listSongAct,&QAction::triggered,this,&SideBar::listSongAct_slot);
    menu->exec(QCursor::pos());
    delete menu;
    delete listPlayAct;
    delete listNextAct;
    delete listDeleAct;
    delete listSongAct;
}

void SideBar::listPlayAct_slot()
{
    //    for(int i = 0;i < sidemodel->rowCount();i++)
    //    {

    qDebug()<<"listPlayAct_slot    currentSelectList"<<currentSelectList;
//    if (myMusicListWid->Music->state() == QMediaPlayer::PlayingState)
//    {
//        myMusicListWid->Music->stop();
//    }
    qDebug()<<"listPlayAct_slot   currentSelectList"<<currentSelectList;

    if(currentPlayList != -1 && currentPlayList != -2)
    {
        if (musicListChangeWid[currentSelectList]->Music->playlist() !=
            musicListChangeWid[currentSelectList]->PlayList)
        {
            qDebug() << "listPlayAct_slot  musicListChangeWid[currentSelectList]->PlayList";
            musicListChangeWid[currentSelectList]->Music->setPlaylist(musicListChangeWid[currentSelectList]->PlayList);
        }
    }

//    if(musicListChangeWid[currentSelectList]->Music->playlist() == musicListChangeWid[currentSelectList]->PlayList)
//    {
    qDebug() << "listPlayAct_slot  ";

    int row = musicListChangeWid[currentSelectList]->musicInfoWidget->currentIndex().row();

    // ??????????????????????????????????????????????????????
    if (currentSelectList == currentPlayList)
    {
        // ?????????????????????????????????????????????
        if (row == musicListChangeWid[currentSelectList]->PlayList->currentIndex())
        {
            // ??????????????????
            if(musicListChangeWid[currentSelectList]->Music->state() == QMediaPlayer::PlayingState)
            {
                qDebug()<<"??????";
                //                play_pause="??????";
                listPlayAct->setText(tr("pause"));
                musicListChangeWid[currentSelectList]->Music->pause();
            }
            // ??????????????????
            else
            {
                qDebug()<<"??????";
                //                play_pause="??????";
                listPlayAct->setText(tr("play"));
                musicListChangeWid[currentSelectList]->Music->play();
            }

        }
        // ????????????????????????????????????????????????
        else
        {
            listPlayAct->setText(tr("pause"));
            musicListChangeWid[currentSelectList]->Music->stop();
            musicListChangeWid[currentSelectList]->PlayList->setCurrentIndex(row);
            musicListChangeWid[currentSelectList]->Music->play();
        }
    }
    // ?????????????????????????????????????????????????????????
    else
    {
        qDebug()<<"??????";
        //                play_pause="??????";
        listPlayAct->setText("play");
        // ???????????????????????????
        if (currentPlayList != -1 && currentPlayList != -2)
        {
            musicListChangeWid[currentPlayList]->Music->stop();
        }
        else
        {
            myMusicListWid->Music->stop();
        }

        currentPlayList = currentSelectList;
        musicListChangeWid[currentSelectList]->PlayList->setCurrentIndex(row);
        musicListChangeWid[currentSelectList]->Music->play();


    }
//        if(musicListChangeWid[currentSelectList]->musicInfoWidget->item(musicListChangeWid[currentSelectList]->PlayList->currentIndex())->isSelected())
//        {
//            if(musicListChangeWid[currentSelectList]->Music->state() == QMediaPlayer::PlayingState)
//            {
//                qDebug()<<"??????";
//                //                play_pause="??????";
//                listPlayAct->setText("??????");
//                musicListChangeWid[currentSelectList]->Music->pause();
//            }
//            else
//            {#include "mainwid.h"
//                qDebug()<<"??????";
//                //                play_pause="??????";
//                listPlayAct->setText("??????");
//                if (currentPlayList != -1 && currentPlayList != -2) {
//                    musicListChangeWid[currentPlayList]->Music->stop();
//                }

//                currentPlayList = currentSelectList;

//                if (musicListChangeWid[currentSelectList]->Music->playlist() !=
//                        musicListChangeWid[currentSelectList]->PlayList) {
//                    musicListChangeWid[currentSelectList]->Music->setPlaylist(
//                                musicListChangeWid[currentSelectList]->PlayList);
//                }
//                musicListChangeWid[currentSelectList]->Music->play();
//            }
//        }
//        else
//        {
//            musicListChangeWid[currentSelectList]->PlayList->setCurrentIndex(musicListChangeWid[currentSelectList]->musicInfoWidget->currentIndex().row());
//            qDebug()<<"666666666666";
//            //            play_pause="??????";
//            listPlayAct->setText("??????");
//            if (currentPlayList != -1 && currentPlayList != -2) {
//                musicListChangeWid[currentPlayList]->Music->stop();
//            }

//            currentPlayList = currentSelectList;

//            if (musicListChangeWid[currentSelectList]->Music->playlist() !=
//                    musicListChangeWid[currentSelectList]->PlayList) {
//                musicListChangeWid[currentSelectList]->Music->setPlaylist(
//                            musicListChangeWid[currentSelectList]->PlayList);
//            }
//            musicListChangeWid[currentSelectList]->Music->play();

//        }
//    }
//    else
//    {
//        musicListChangeWid[currentSelectList]->Music->setPlaylist(musicListChangeWid[currentSelectList]->PlayList);
//        musicListChangeWid[currentSelectList]->PlayList->setCurrentIndex(musicListChangeWid[currentSelectList]->musicInfoWidget->currentIndex().row());
//        qDebug()<<"777777777777";
//        //        play_pause="??????";
//        listPlayAct->setText("??????");
//        if (currentPlayList != -1 && currentPlayList != -2) {
//            musicListChangeWid[currentPlayList]->Music->stop();
//        }

//        currentPlayList = currentSelectList;

//        if (musicListChangeWid[currentSelectList]->Music->playlist() !=
//                musicListChangeWid[currentSelectList]->PlayList) {
//            musicListChangeWid[currentSelectList]->Music->setPlaylist(
//                        musicListChangeWid[currentSelectList]->PlayList);
//        }
//        musicListChangeWid[currentSelectList]->Music->play();
//    }

}


void SideBar::listNextAct_slot()
{
//    for (int i = 0;i < sidemodel->rowCount();i++)
//    {
        myMusicListWid->Music->stop();

        if(musicListChangeWid[currentSelectList]->Music->playlist() == musicListChangeWid[currentSelectList]->PlayList)
        {
            int currentIndex = musicListChangeWid[currentSelectList]->PlayList->currentIndex();
            //        mpwid->setCurrentIndex(0);
            //        pushbuttonstyle();
            if(++currentIndex == musicListChangeWid[currentSelectList]->PlayList->mediaCount())
            {
                currentIndex=0;
            }
            musicListChangeWid[currentSelectList]->PlayList->setCurrentIndex(currentIndex);
        }
        musicListChangeWid[currentSelectList]->Music->play();
//    }
}

void SideBar::addMusicToPlayList(QAction *listact)
{
    int ret;
    musicDataStruct musicInfo;
    int listIndex = listact->data().toInt();

    int row = musicListChangeWid[currentSelectList]->musicInfoWidget->currentIndex().row();

    QString filePath = musicListChangeWid[currentSelectList]->localAllMusicid[row];
    ret = g_db->getSongInfoFromPlayList(musicInfo, filePath, playListName[currentSelectList]);
    if(ret != DB_OP_SUCC)
    {
        qDebug() << "????????????????????????????????????" <<__FILE__<< ","<<__FUNCTION__<<","<<__LINE__;
        return;
    }
    ret = g_db->addMusicToPlayList(filePath, listact->text());
    if(ret == DB_OP_SUCC)
    {
        QListWidgetItem *item = new QListWidgetItem(musicListChangeWid[listIndex]->musicInfoWidget);
        SongItem *songitem = new SongItem;
        musicListChangeWid[listIndex]->musicInfoWidget->setItemWidget(item, songitem);
        songitem->song_singer_albumText(musicInfo.title,musicInfo.singer,musicInfo.album); //???????????? ?????? ??????
        songitem->songTimeLabel->setText(musicInfo.time); //??????
        musicListChangeWid[listIndex]->localAllMusicid.append(musicInfo.filepath);
        musicListChangeWid[listIndex]->PlayList->addMedia(QUrl::fromLocalFile(musicInfo.filepath));
        musicListChangeWid[listIndex]->musicInfoWidget->show();
        musicListChangeWid[listIndex]->songNumberLabel->setText(
                    tr("A total of")+QString::number(musicListChangeWid[listIndex]->musicInfoWidget->count())+tr("The first"));
    }

    else
    {
        QMessageBox::about(this,"????????????","???????????????");
    }
}

void SideBar::deleteMusicFromSongList()
{
    int ret;
    int currPlay;
    int row = musicListChangeWid[currentSelectList]->musicInfoWidget->currentIndex().row();
    QString musicPath = musicListChangeWid[currentSelectList]->localAllMusicid[row];

    ret = g_db->delMusicFromPlayList(musicPath, playListName[currentSelectList]);
    if(ret == DB_OP_SUCC)
    {
        musicListChangeWid[currentSelectList]->localAllMusicid.removeOne(musicPath);
        musicListChangeWid[currentSelectList]->musicInfoWidget->removeItemWidget(musicListChangeWid[currentSelectList]->musicInfoWidget->item(row));
        delete musicListChangeWid[currentSelectList]->musicInfoWidget->item(row);

        if (currentMusicPlaylist == currentSelectList) {
            currPlay = musicListChangeWid[currentSelectList]->PlayList->currentIndex();
            if (currPlay == row) {
                musicListChangeWid[currentSelectList]->Music->stop();
                musicListChangeWid[currentSelectList]->PlayList->removeMedia(row);
                musicListChangeWid[currentSelectList]->Music->setPlaylist(musicListChangeWid[currentSelectList]->PlayList);

                if(musicListChangeWid[currentSelectList]->musicInfoWidget->count() > 0)
                {
                    if(row == musicListChangeWid[currentSelectList]->musicInfoWidget->count())
                    {
                        musicListChangeWid[currentSelectList]->PlayList->setCurrentIndex(0);
                        MainWid::mutual->playlist_currentIndexChanged(0);
                    }
                    else
                    {
                        musicListChangeWid[currentSelectList]->PlayList->setCurrentIndex(row);
                        MainWid::mutual->playlist_currentIndexChanged(row);
                    }
                }
                musicListChangeWid[currentSelectList]->Music->play();
                if (musicListChangeWid[currentSelectList]->musicInfoWidget->count() == 0)
                {
                    musicListChangeWid[currentSelectList]->Music->stop();
                    MainWid::mutual->getPlayListStop();
                    /* ???????????? */
                }
            } else if (currPlay > row) {
                int position = 0;
                if(musicListChangeWid[currentSelectList]->Music->state()==QMediaPlayer::PlayingState)
                {
                    position=musicListChangeWid[currentSelectList]->Music->position();
                }
                musicListChangeWid[currentSelectList]->Music->stop();
                musicListChangeWid[currentSelectList]->PlayList->setCurrentIndex(0);
                musicListChangeWid[currentSelectList]->PlayList->removeMedia(row, row);
                musicListChangeWid[currentSelectList]->Music->setPlaylist(musicListChangeWid[currentSelectList]->PlayList);
                musicListChangeWid[currentSelectList]->PlayList->setCurrentIndex(currPlay - 1);
                musicListChangeWid[currentSelectList]->Music->setPosition(position);
    //            hSlider->setValue(position);
                musicListChangeWid[currentSelectList]->Music->play();
            }
        } else {
            musicListChangeWid[currentSelectList]->PlayList->removeMedia(row, row);
        }

        musicListChangeWid[currentSelectList]->songNumberLabel->setText(
                    tr("A total of")+QString::number(musicListChangeWid[currentSelectList]->musicInfoWidget->count())+tr("The first"));
    }
}

void SideBar::listSongAct_slot()
{
    int ret;
    musicDataStruct fileData;
    SongInfoWidget *mySongInfoWidget = new SongInfoWidget;
    int row = musicListChangeWid[currentSelectList]->musicInfoWidget->currentIndex().row();
    QString musicPath = musicListChangeWid[currentSelectList]->localAllMusicid[row];

    mySongInfoWidget->songInfoDlg->show();
    ret = g_db->getSongInfoFromPlayList(fileData, musicPath, playListName[currentSelectList]);
    if(ret == DB_OP_SUCC)
    {
        mySongInfoWidget->titleLab ->setText(tr("The song name:"));  //????????????
        mySongInfoWidget->artistLab->setText(tr("singer:"));         //????????????
        mySongInfoWidget->albumLab ->setText(tr("album:"));          //????????????
        mySongInfoWidget->typeLab  ->setText(tr("The file type:"));  //????????????
        mySongInfoWidget->sizeLab  ->setText(tr("The file size:"));  //????????????
        mySongInfoWidget->timeLab  ->setText(tr("File length:"));    //????????????
        mySongInfoWidget->pathLab  ->setText(tr("File location:"));  //????????????


        mySongInfoWidget->musicNameLab->setText(fileData.title);
        mySongInfoWidget->singerNameLab->setText(fileData.singer);
        mySongInfoWidget->albumNameLab->setText(fileData.album);
        mySongInfoWidget->fileTypeLab->setText(fileData.filetype);
        mySongInfoWidget->fileSizeLab->setText(fileData.size);
        mySongInfoWidget->fileTimeLab->setText(fileData.time);

        QString showpathStr   = "";
        if(fileData.filepath.length() > 30)
        {
            showpathStr = fileData.filepath.mid(0,29);
            showpathStr.append("...");
            mySongInfoWidget->filePathLab->setText(" "+showpathStr);
            mySongInfoWidget->filePathLab->setToolTip(" "+fileData.filepath);
        }
        else
        {
            mySongInfoWidget->filePathLab->setText(" "+fileData.filepath);
        }
    }
    else
    {
        qDebug() << "?????????????????????????????????" <<__FILE__<< ","<<__FUNCTION__<<","<<__LINE__;
        return;
    }
}


void SideBar::addSongList()
{
    //??????????????????????????????????????????????????????????????????????????????
    newSonglistPup->enterLineEdit->clear();
    newSonglistPup->pupDialog->show();
    newSonglistPup->enterLineEdit->setFocus();
}

QString SideBar::enterLineEdit(QString text)   //??????????????????hash
{
    return text;
//    QString enterLineEditText;
//    QByteArray qByteArray;
//    QCryptographicHash hash(QCryptographicHash::Md5);

//    qByteArray.append(text);
//    hash.addData(qByteArray);
//    enterLineEditText.append(hash.result().toHex());
//    playListNew.hash = enterLineEditText;

//    return playListNew.hash;
}
void SideBar::initDefaultMusicList()
{
    myMusicListWid = new MusicListWid();    //?????????????????????????????? ?????????????????????num

    rightChangeWid->addWidget(myMusicListWid);
    connect(PlayListBtn,SIGNAL(clicked(bool)),this,SLOT(ChangePage()));
    myMusicListWid->get_localmusic_information("LocalMusic");
    myMusicListWid->songNumberLabel->setText(tr("A total of")+QString::number(myMusicListWid->musicInfoWidget->count())+tr("The first"));

}
void SideBar::createSongList()
{
    int ret;
    QString listName;

    initDefaultMusicList();

    playListName.clear();
    ret = g_db->getPlayList(playListName);
    if(ret != DB_OP_SUCC)
    {
        qDebug() << "????????????????????????" <<__FILE__<< ","<<__FUNCTION__<<","<<__LINE__;
        return;
    }
    qDebug()<<playListName<<"  ------  "<<playListName.size();
    for(int i = 0;i< playListName.size();i++)
    {
        newSongList[i] = new QListWidgetItem(songListWidget);
        listName = playListName.at(i);
        newSongListBtn[i] = new QToolButton(this);
        newSongListBtn[i]->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        newSongListBtn[i]->setIcon(QIcon(":/img/default/songlist.png"));
        newSongListBtn[i]->setIconSize(QSize(16,16));
        newSongListBtn[i]->setFixedSize(180,32);

        newSongList[i]->setSizeHint(QSize(180,38));

        if (listName != "") {
            newSongListBtn[i]->setText(listName);

        }

        if(WidgetStyle::themeColor == 1)
        {
            newSongListBtn[i]->setIcon(QIcon(":/img/default/songlist_w .png"));

            newSongListBtn[i]->setStyleSheet("QToolButton{padding-left:15px;margin-left:10px;\
                                               font-size: 14px;\
                                               \
                                              background-color:#1F2022;\
                                              color:#F9F9F9;border-radius:16px;}"
                                              "QToolButton::hover{background-color:#303032;border-radius:16px;}"
                                              "QToolButton::pressed{background-color:#303032;border-radius:16px;}");
        }
        else if(WidgetStyle::themeColor == 0)
        {
            newSongListBtn[i]->setIcon(QIcon(":/img/default/songlist.png"));

            newSongListBtn[i]->setStyleSheet("QToolButton{padding-left:15px;margin-left:10px;\
                                             font-size: 14px;\
                                             \
                                            background-color:#FAFAFA;\
                                            color:#303133;border-radius:16px;}"
                                            "QToolButton::hover{background-color:#EEEEEE;border-radius:16px;}"
                                            "QToolButton::pressed{background-color:#EEEEEE;border-radius:16px;}");
        }
        songListWidget->setItemWidget(newSongList[i],newSongListBtn[i]);
        musicListChangeWid[i] = new MusicListWid(this);
        musicListChangeWid[i]->top_addSongBtn->hide();
        musicListChangeWid[i]->songListLabel->setText(listName);
        musicListChangeWid[i]->get_localmusic_information(listName);
        musicListChangeWid[i]->songNumberLabel->setText(tr("A total of")+QString::number(musicListChangeWid[i]->musicInfoWidget->count())+tr("The first"));

        QString listNameLab = "";
        if(listName.length() > 9)
        {
            listNameLab = listName.mid(0,8);
            listNameLab.append("...");
            musicListChangeWid[i]->songListLabel->setText(listNameLab);
            musicListChangeWid[i]->songListLabel->setToolTip(listName);
        }
        else
        {
            musicListChangeWid[i]->songListLabel->setText(listName);
        }

        rightChangeWid->addWidget(musicListChangeWid[i]);

        connect(newSongListBtn[i],SIGNAL(clicked(bool)),this,SLOT(AlterPage()));
        musicListChangeWid[i]->setContextMenuPolicy(Qt::CustomContextMenu);
        connect(musicListChangeWid[i],SIGNAL(customContextMenuRequested(const QPoint&)),
            this,SLOT(on_musicListChangeWid_customContextMenuRequested(const QPoint&)));

    }
    newSonglistPup->pupDialog->hide();

}

void SideBar::addItemToSongList()
{
    int ret;
    int i, j;
    int num = songListWidget->count();   //num???songListWidget???????????????item?????????

    QString listName = newSonglistPup->enterLineEdit->text();

    if( num >= 19 )
    {
        newSonglistPup->pupDialog->hide();

//        QMessageBox::about(this,"????????????","?????????????????????????????????");
        QMessageBox::about(this,tr("Prompt information"),tr("The number of playlists has reached the limit!!"));
        return;

    }

    qDebug()<<listName;

    if(listName != "")
    {
        for(int i = 0;i< playListName.size();i++)
        {
            if(playListName.at(i) == listName)
            {
                newSonglistPup->pupDialog->hide();
        //        QMessageBox::about(this,tr("????????????"),tr("???????????????????????????"));
                QMessageBox::about(this,tr("Prompt information"),tr("Single song name already exists!!"));
                return ;
            }
        }
    }
    else
    {
        QStringList filterResult = playListName.filter("????????????");

        if (filterResult.size() == 0) {
            listName = "????????????";
        } else {

            for (i = 0; i < filterResult.size(); i++) {
                if (filterResult.at(i) == "????????????") {
                    break;
                }
            }
            if (i >= filterResult.size()) {
                listName = "????????????";
            } else {
                j = 1;
                for (i = 0; i < filterResult.size(); i++) {
                    listName = "????????????" + QString::number(j);
                    ret = filterResult.indexOf(listName, 0);
                    if (ret == -1) {
                        break;
                    }
                    j++;
                }
            }
        }
    }

    newSongList[num] = new QListWidgetItem(songListWidget);  //????????? ??????item???????????????????????????num????????????????????????????????????????????????????????????1
    newSongListBtn[num] = new QToolButton(this);
    newSongListBtn[num]->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    newSongListBtn[num]->setIconSize(QSize(16,16));
    newSongListBtn[num]->setText(listName);
    newSongListBtn[num]->setFixedSize(180,32);
    newSongList[num]->setSizeHint(QSize(180,32));
    if(WidgetStyle::themeColor == 1)
    {
        newSongListBtn[num]->setIcon(QIcon(":/img/default/songlist_w .png"));

        newSongListBtn[num]->setStyleSheet("QToolButton{padding-left:15px;margin-left:10px;\
                                           font-size: 14px;\
                                           \
                                          background-color:#1F2022;\
                                          color:#F9F9F9;border-radius:16px;}"
                                          "QToolButton::hover{background-color:#303032;border-radius:16px;}"
                                          "QToolButton::pressed{background-color:#303032;border-radius:16px;}");
    }
    else if(WidgetStyle::themeColor == 0)
    {
        newSongListBtn[num]->setIcon(QIcon(":/img/default/songlist.png"));

        newSongListBtn[num]->setStyleSheet("QToolButton{padding-left:15px;margin-left:10px;\
                                         font-size: 14px;\
                                         \
                                        background-color:#FAFAFA;\
                                        color:#303133;border-radius:16px;}"
                                        "QToolButton::hover{background-color:#EEEEEE;border-radius:16px;}"
                                        "QToolButton::pressed{background-color:#EEEEEE;border-radius:16px;}");
    }
    songListWidget->setItemWidget(newSongList[num],newSongListBtn[num]);

    qDebug() << "listName ??????" << listName <<__FILE__<< ","<<__FUNCTION__<<","<<__LINE__;
    ret = g_db->createNewPlayList(listName);
    if(ret != DB_OP_SUCC)
    {
        qDebug() << "??????????????????" <<__FILE__<< ","<<__FUNCTION__<<","<<__LINE__;
        return;
    }
    playListName.append(listName);

    musicListChangeWid[num] = new MusicListWid(this);    //?????????????????????????????? ?????????????????????num
    musicListChangeWid[num]->top_addSongBtn->hide();
    musicListChangeWid[num]->songListLabel->setText(listName);
//    musicListChangeWid[num]->tableName = listName;
    musicListChangeWid[num]->musicInfoWidget->clear();
    QString listNameLab = "";
    if(listName.length() > 9)
    {
        listNameLab = listName.mid(0,8);
        listNameLab.append("...");
        musicListChangeWid[num]->songListLabel->setText(listNameLab);
        musicListChangeWid[num]->songListLabel->setToolTip(listName);
    }
    else
    {
        musicListChangeWid[num]->songListLabel->setText(listName);
    }

    rightChangeWid->addWidget(musicListChangeWid[num]);
    connect(newSongListBtn[num],SIGNAL(clicked(bool)),this,SLOT(AlterPage()));
    musicListChangeWid[num]->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(musicListChangeWid[num],SIGNAL(customContextMenuRequested(const QPoint&)),
        this,SLOT(on_musicListChangeWid_customContextMenuRequested(const QPoint&)));

    MainWid::mutual->initAddPlayList(num);

    newSonglistPup->pupDialog->hide();
}

void SideBar::deleteSongList()      //????????????????????????
{
    int ret;
    int row = songListWidget->currentIndex().row();

    QString playlistName = playListName[row];   //????????????????????????
    if(playlistName == "?????????")
    {
        promptSongListPup->pupDialog->hide();
        QMessageBox::about(this,tr("Prompt information"),tr("????????????????????????"));
        return ;
    }
    ret = g_db->delPlayList(playlistName);
    if(ret != DB_OP_SUCC)
    {
        qDebug() << "??????????????????" <<__FILE__<< ","<<__FUNCTION__<<","<<__LINE__;
        return;
    }
    playListName.removeOne(playlistName);
    delete newSongListBtn[row];
    delete newSongList[row];
    delete musicListChangeWid[row];

    for(int i = row; i < songListWidget->count();i++)
    {
        newSongListBtn[i] = newSongListBtn[i + 1];
        newSongList[i] = newSongList[i + 1];
        musicListChangeWid[i] = musicListChangeWid[i + 1];
    }
    promptSongListPup->pupDialog->hide();
}

void SideBar::ChangePage()
{
    rightChangeWid->setCurrentIndex(0);
    currentSelectList = -1;
}

void SideBar::AlterPage()
{
    pButton = qobject_cast<QToolButton *>(sender());

    for (btnIndex = 0; btnIndex < 20; btnIndex++)
    {

        if (newSongListBtn[btnIndex] == pButton)
        {
            break;
        }
    }

    if (btnIndex < 20) {
        rightChangeWid->setCurrentIndex(btnIndex + 1);   //????????????????????????

        currentSelectList = btnIndex;
    }
    else {
//        rightChangeWid->setCurrentIndex(1);
//        currentSelectList = 1;

    }
}
