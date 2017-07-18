<<<<<<< HEAD
// Copyright (c) 2011-2017 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_UTILITYDIALOG_H
#define BITCOIN_QT_UTILITYDIALOG_H

#include <QDialog>
#include <QObject>
#include <QStringListModel>
#include <QStandardItemModel>

#include "walletmodel.h"


class BitcoinGUI;
class ClientModel;
class SendCoinsRecipient;

namespace Ui {
    class HelpMessageDialog;
    class CommentDialog;
    class DebugDialog;
    /* These definitions generate warnings, but they are used in utility dialog.cpp */
static const char* OPENNAME_NAME_PREORDER="a";
static const char* OPENNAME_NAME_REGISTRATION="b";
static const char* OPENNAME_NAME_UPDATE="c";
static const char* OPENNAME_NAME_TRANSFER="d";
static const char* OPENNAME_NAME_RENEWAL="e";
    
    class PaperWalletDialog;

}

/** "Help message" dialog box */
class HelpMessageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HelpMessageDialog(QWidget *parent, bool about);
    ~HelpMessageDialog();

    void printToConsole();
    void showOrPrint();

private:
    Ui::HelpMessageDialog *ui;
    QString text;

private Q_SLOTS:
    void on_okButton_accepted();
};


/** "Shutdown" window */
class ShutdownWindow : public QWidget
{
    Q_OBJECT

public:
    ShutdownWindow(QWidget *parent=0, Qt::WindowFlags f=0);
    static void showShutdownWindow(BitcoinGUI *window);

protected:
    void closeEvent(QCloseEvent *event);
};


/** "Comment" dialog box */
class CommentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CommentDialog(QWidget *parent);
    ~CommentDialog();

    void setModel(WalletModel *model);

private:
    Ui::CommentDialog *ui;
    WalletModel *model;
    void processSendCoinsReturn(const WalletModel::SendCoinsReturn &sendCoinsReturn, const QString &msgArg = QString());

private Q_SLOTS:
    void on_insertButton_clicked();
    void on_pushButton_clicked();
    
Q_SIGNALS:	
    void message(const QString &title, const QString &message, unsigned int style);
};

/** "Paper Wallet" dialog box */
class PaperWalletDialog : public QDialog
{
    Q_OBJECT
    

public:
    explicit PaperWalletDialog(QWidget *parent);
    ~PaperWalletDialog();

    void setModel(WalletModel *model);

private:
    Ui::PaperWalletDialog *ui;
    WalletModel *model;
<<<<<<< HEAD
    void processSendCoinsReturn(const WalletModel::SendCoinsReturn &sendCoinsReturn, const QString &msgArg = QString());
    
private slots:
    void on_insertButton_clicked();
    void on_pushButton_clicked();
    
signals:
    void message(const QString &title, const QString &message, unsigned int style);
=======
    static const int PAPER_WALLET_READJUST_LIMIT = 20;
    static const int PAPER_WALLET_PAGE_MARGIN = 50;

private Q_SLOTS:
    void on_getNewAddress_clicked();
    void on_printButton_clicked();
>>>>>>> origin/0.11.2-wrapper
};

/** "DebugDialog" dialog box */
class DebugDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DebugDialog(QWidget *parent);
    ~DebugDialog();

    void setModel(WalletModel *model);

private:
    Ui::DebugDialog *ui;
    WalletModel *model;
    double nowCoins;
    double getCoins;
    int inputRow;
    QStandardItemModel  *modelTable = new QStandardItemModel();

private Q_SLOTS:
    void on_exitButton_clicked();
    void on_BroadcastBtn_clicked();
    void on_AddTransBtn_clicked();
    
Q_SIGNALS:
    void message(const QString &title, const QString &message, unsigned int style);
};

#endif // BITCOIN_QT_UTILITYDIALOG_H
