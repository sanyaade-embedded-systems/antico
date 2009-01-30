////////////////////////////////////////
//  File      : utils.h               //
//  Written by: g_cigala@virgilio.it  //
//  Copyright : GPL                   //
////////////////////////////////////////

// get application icon (from ".desktop" file)

///////////////////////////////////////////////////////////////////////////

#ifndef UTILS_H
#define UTILS_H

#include "defs.h"

///////////////////////////////////////////////////////////////////////////

class Appicon : public QObject
{
    Q_OBJECT

public:
    Appicon(QObject *parent=0);
    ~Appicon();
    QString get_app_icon(const QString &);
    QString search_in_path(const QString &, const QString &);
};

///////////////////////////////////////////////////////////////////////////
// create Category menu to add on Launcher and on Filedialog (open with ..)
///////////////////////////////////////////////////////////////////////////

class Categorymenu : public QWidget
{
    Q_OBJECT

public:
    Categorymenu(QMenu *menu, QWidget *parent=0);
    ~Categorymenu();
    void add_app(QMenu *, const QString &, const QString &, const QString &);
    void read_settings();
    void update_menu();
    void init();
    void update_style();
    void parse_desktop_file();
    void set_cmd_arguments(const QString &);

public slots:
    void run_menu(QAction *);
   
private:
    QSettings *style;
    QSettings *antico;
    QMenu *main_menu;
    QMenu *audiovideo_menu;
    QMenu *system_menu;
    QMenu *development_menu;
    QMenu *graphics_menu;
    QMenu *network_menu;
    QMenu *office_menu;
    QMenu *utility_menu;
    QString launch_pix;
    QString app_pix;
    QString quit_pix;
    QString refresh_pix;
    QString run_pix;
    QString manager_pix;
    QString utility_pix;
    QString office_pix;
    QString network_pix;
    QString graphics_pix;
    QString devel_pix;
    QString system_pix;
    QString audiovideo_pix;
    QString cmd_arguments;
    QHash<QString, QMenu *> cat_menu;
};

///////////////////////////////////////////////////////////////////////////
// get the file icon to show on Filedialog
///////////////////////////////////////////////////////////////////////////

class Fileicon : public QFileIconProvider
{
 
public:
    Fileicon();
    ~Fileicon();
    QIcon icon(const QFileInfo &) const;
    QIcon icon();
    QString type(const QFileInfo &) const; 
    void read_settings();

private:
    QSettings *style;
    QSettings *antico;
    QString utility_pix;
    QString office_pix;
    QString network_pix;
    QString graphics_pix;
    QString devel_pix;
    QString system_pix;
    QString audiovideo_pix;
    QString d_folder_pix;
    
    QStringList graphics;
    QStringList devel;
    QStringList system;
    QStringList office;
    QStringList audiovideo;
    QStringList network;
    QStringList utility;
   
};


#endif
